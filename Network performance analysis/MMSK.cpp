#include <iostream>
#include <cmath>
#include <queue>
#include <random>
#include <algorithm>
#include <vector>
#include <fstream>

class MathQueueingSystem
{
private:
    int S, K;
    double mu, lambda, rho;
    std::vector<double> stateProbabilities;

    double calculateP0()
    {
        double sum = 0.0;
        for (int n = 0; n < S; ++n)
        {
            sum += std::pow(lambda / mu, n) / factorial(n);
        }
        /*
                //不考慮容量 k= limit
                double lastTerm = std::pow(lambda / mu, S) / (factorial(S) * (1 - rho));

                sum += lastTerm;
        */
        // 考慮容量 k= K
        double lastTerm = (std::pow(lambda / mu, S) / factorial(S)) *
                          (1 - std::pow(lambda / (S * mu), K - S + 1)) / (1 - lambda / (S * mu));
        sum += lastTerm;

        if (sum == 0)
        {
            throw std::runtime_error("Division by zero in calculateP0");
        }
        return 1.0 / sum;
    }

    double factorial(int n)
    {
        double result = 1.0;
        for (int i = 1; i <= n; ++i)
        {
            result *= i;
        }

        return result;
        // result = 1-result;
    }

    void calculateStateProbabilities()
    {
        double P0 = calculateP0();
        stateProbabilities.resize(K + 1);
        stateProbabilities[0] = P0;

        for (int n = 1; n <= K; ++n)
        {
            if (n < S)
            {
                stateProbabilities[n] = std::pow(lambda / mu, n) / factorial(n) * P0;
            }
            else
            {
                stateProbabilities[n] = std::pow(lambda / mu, n) / (factorial(S) * std::pow(S, n - S)) * P0;
            }
        }
    }

public:
    MathQueueingSystem(int s, int k, double mu, double lambda) : S(s), K(k), mu(mu), lambda(lambda)
    {
        rho = lambda / (S * mu);
        if (rho >= 1)
        {
            throw std::runtime_error("BadValue: rho >= 1");
        }
        calculateStateProbabilities();
    }

    double L()
    {
        double sum = 0.0;
        double sum2 = 0.0;
        for (int n = 0; n < S; n++)
        {
            double temp = stateProbabilities[n];
            sum += n * temp;
            sum2 += temp;
        }
        sum2 = S * (1 - sum2);
        return Lq() + sum + sum2;
    }

    double Lq()
    {
        double Lq = 0.0;
        for (int n = S; n <= K; n++)
        {
            Lq += (n - S) * stateProbabilities[n];
        }
        return Lq;
    }

    double lambdaEff()
    {
        return lambda * (1 - stateProbabilities[K]);
    }

    double W()
    {
        return L() / lambdaEff();
    }

    double Wq()
    {
        return Lq() / lambdaEff();
    }

    // debug
    void printAllValue()
    {
        std::cout << "P0: " << calculateP0() << std::endl;
        std::cout << "rho: " << rho << std::endl;
        std::cout << "stateProbabilities: " << std::endl;
        for (int i = 0; i < stateProbabilities.size(); i++)
        {
            std::cout << stateProbabilities[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

class SimulationQueueingSystem
{
private:
    int S, K;          // 服務台數量和系統容量
    double mu, lambda; // 服務率和到達率 HR^-1
    std::default_random_engine generator;
    std::exponential_distribution<double> arrivalDistribution; 
    std::exponential_distribution<double> serviceDistribution;

    double totalWaitTime;      // 所有顧客的總等待時間
    double totalQueueWaitTime; // 所有顧客在隊列中的總等待時間
    int totalCustomers;        // 總顧客數
    int totalServedCustomers;  // 總服務的顧客數

    struct Customer
    {
        double arrivalTime;   // 到達時間
        double serviceTime;   // 服務所需時間
        double startTime;     // 開始服務時間
        double departureTime; // 結束服務時間
    };

    std::queue<Customer> allCustomerQueue;    // 所有顧客 test
    std::queue<Customer> queue;               // 排隊的顧客
    std::vector<Customer> inService;          // 處理中的顧客
    std::vector<Customer> processedCustomers; // 處裡完的顧客 (不用管了)
    double currentTime;

//GCC????
    Customer generateCustomer(double inTime)
    {
        totalCustomers++;
        return {inTime + arrivalDistribution(generator) * 60, serviceDistribution(generator) * 60, 0.0, 0.0};
    }

    // server離開的
    void processDepartures()
    {
        for (auto &customer : inService)
        {

            if (customer.departureTime <= currentTime)
            {
                //totalWaitTime += (currentTime - customer.arrivalTime);
                // totalWaitTime += (customer.departureTime - customer.arrivalTime); // 不知道為甚麼是負數 patch!
                totalWaitTime += (customer.departureTime - customer.arrivalTime);

                totalQueueWaitTime += (customer.startTime-customer.arrivalTime ); 
                totalServedCustomers++;
                processedCustomers.push_back(customer);
            }
        }
        // 去除顧客
        inService.erase(std::remove_if(inService.begin(), inService.end(), [this](const Customer &c)
                                       { return c.departureTime <= currentTime; }),
                        inService.end());
    }
    // 處裡排隊的列
    void processQueue()
    {
        // 可以服務 開始服務
        while (!queue.empty() && inService.size() < S)
        {
            Customer &customer = queue.front();
            customer.startTime = currentTime;
            customer.departureTime = customer.startTime + customer.serviceTime;
            // if startTime < arrivalTime throw error
            if (customer.startTime < customer.arrivalTime)
            {
                printAllValue();
                // print startTime , arrivalTime
                std::cout << "startTime: " << customer.startTime << std::endl;
                std::cout << "arrivalTime: " << customer.arrivalTime << std::endl;
                throw std::runtime_error("BadValue: startTime < arrivalTime");
            }

            inService.push_back(customer);
            queue.pop();
        }
    }
    // 到達的
    bool  processArrival(Customer &customer)
    {
        if (inService.size() < S)
        {
            // 有空閒的服務台 直接處裡掉
            customer.startTime = currentTime;
            customer.departureTime = currentTime + customer.serviceTime;
            inService.push_back(customer);
            //totalServedCustomers++; 不能在這邊加 = =
            return true;
        }
        else if (queue.size() < K) // k-s?
        {                          // 有空間在隊列中等待
            queue.push(customer);
        }
        // 如果沒有空間則客戶被丟棄
        // totalCustomers--;
        return false;
    }

public:
    //  init服務台數量、系統容量、服務率和到達率
    SimulationQueueingSystem(int s, int k, double mu, double lambda)
        : S(s), K(k), mu(mu), lambda(lambda), currentTime(0.0),
          arrivalDistribution(lambda), serviceDistribution(mu),
          totalWaitTime(0.0), totalQueueWaitTime(0.0),
          totalCustomers(0), totalServedCustomers(0) {}

    void run(double simulationTime)
    {

        // test
        for (double time = 0; time < simulationTime;)
        {
            Customer newCustomer = generateCustomer(time);
            allCustomerQueue.push(newCustomer);
            time = newCustomer.arrivalTime;
        }

        // 歸0
        currentTime = 0;
        bool newCustomerIsIn = false;
        Customer newCustomerTmp;
        while (currentTime < simulationTime)
        {
            // 把server客人排出->處裡排隊->處裡到達

            // 處理server離開顧客
            processDepartures();
            // 將顧客從隊列移動到sever
            processQueue();
            // 處理到達server顧客
            if(!newCustomerIsIn){
                if (allCustomerQueue.empty())
                {
                    break;
                }
                newCustomerTmp = allCustomerQueue.front();
                allCustomerQueue.pop();
                newCustomerIsIn = true;
            }
            else{
                currentTime += 0.1;
                //if newCustomerTmp can in
                if(newCustomerTmp.arrivalTime <= currentTime){
                    processArrival(newCustomerTmp);
                    newCustomerIsIn = false;
                }
            }

            /*
            Customer newCustomer = allCustomerQueue.front();
            allCustomerQueue.pop();
            processArrival(newCustomer);
            currentTime = newCustomer.arrivalTime;
            */
        }
    }
    // pointer value
    double L()
    {
        return totalWaitTime / currentTime;
    }

    double Lq()
    {

        return (totalQueueWaitTime / currentTime);
    }

    double W()
    {
        // DE
        if (totalServedCustomers > 0)
        {
            return (totalWaitTime / totalServedCustomers) / 60;
        }
        return 0.0;
    }

    double Wq()
    {
        // DE
        if (totalServedCustomers > 0)
        {
            return (totalQueueWaitTime / totalServedCustomers) / 60;
        }
        return 0.0;
    }

    // debug
    void printAllValue()
    {
        std::cout << "totalWaitTime: " << totalWaitTime << std::endl;
        std::cout << "totalQueueWaitTime: " << totalQueueWaitTime << std::endl;
        std::cout << "totalCustomers: " << totalCustomers << std::endl;
        std::cout << "totalServedCustomers: " << totalServedCustomers << std::endl;
    }
};

int main()
{
    int s = 3, k = 8;
    double mu = 30;                  // 服務率 (Hr^-1)
    double simulationTime = 100000.0; // 模擬時間 (s)

    std::ofstream outputFile("queueing_system_results.csv");
    outputFile << "Lambda,L,Lq,W,Wq,SimulatedL,SimulatedLq,SimulatedW,SimulatedWq\n";

    for (double lambda = 15; lambda <= 25; ++lambda)
    {
        MathQueueingSystem queueSystem(s, k, mu, lambda);
        SimulationQueueingSystem simQueueSystem(s, k, mu, lambda);

        simQueueSystem.run(simulationTime); // 運行模擬

        // 從理論模型中計算
        double L = queueSystem.L();
        double Lq = queueSystem.Lq();
        double W = queueSystem.W();
        double Wq = queueSystem.Wq();
        queueSystem.printAllValue();
        // simulate
        double simulatedL = simQueueSystem.L();
        double simulatedLq = simQueueSystem.Lq();
        double simulatedW = simQueueSystem.W();
        double simulatedWq = simQueueSystem.Wq();
        simQueueSystem.printAllValue();
        // result
        std::cout << lambda << "," << L << "," << Lq << "," << W << "," << Wq << ","
                  << simulatedL << "," << simulatedLq << "," << simulatedW << "," << simulatedWq << std::endl;

        outputFile << lambda << "," << L << "," << Lq << "," << W << "," << Wq << ","
                   << simulatedL << "," << simulatedLq << "," << simulatedW << "," << simulatedWq << std::endl;
    }

    outputFile.close();
    std::cout << "saved to queueing_system_results.csv" << std::endl;

    return 0;
}
