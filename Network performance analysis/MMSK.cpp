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
                不考慮容量 k= limit
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
            throw std::runtime_error("System BadValue: rho >= 1");
        }
        calculateStateProbabilities();
    }

    double L()
    {
        double L = 0.0;
        for (int n = 0; n <= K; ++n)
        {
            L += n * stateProbabilities[n];
        }
        return L;
    }

    double Lq()
    {
        double Lq = 0.0;
        for (int n = S; n <= K; ++n)
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
};

class SimulationQueueingSystem
{
private:
    int S, K;          // 服務台數量和系統容量
    double mu, lambda; // 服務率和到達率
    std::default_random_engine generator;
    std::exponential_distribution<double> arrivalDistribution;
    std::exponential_distribution<double> serviceDistribution;

    double totalWaitTime;      // 所有顧客的總等待時間
    double totalQueueWaitTime; // 所有顧客在隊列中的總等待時間
    int totalCustomers;        // 總顧客數
    int totalServedCustomers;  // 總服務的顧客數

    struct Customer
    {
        double arrivalTime;
        double serviceTime;
        double startTime;
        double departureTime;
    };

    std::queue<Customer> queue; //排隊的顧客
    std::vector<Customer> inService;    // 處理中的顧客
    std::vector<Customer> processedCustomers;   // 處裡玩的顧客
    double currentTime;

    Customer generateCustomer()
    {
        totalCustomers++;
        return {currentTime + arrivalDistribution(generator), serviceDistribution(generator), 0.0, 0.0};
    }

    void processArrival(Customer &customer)
    {
        if (inService.size() < S)
        { // 有空閒的服務台
            customer.startTime = currentTime;
            customer.departureTime = currentTime + customer.serviceTime;
            inService.push_back(customer);
        }
        else if (queue.size() < K - S)
        { // 有空間在隊列中等待
            queue.push(customer);
        }
        // 如果沒有空間則客戶被丟棄
    }

    void processDepartures()
    {
        for (auto &customer : inService)
        {
            
            if (customer.departureTime <= currentTime)
            {
                totalWaitTime += (currentTime - customer.arrivalTime);
                totalQueueWaitTime += (customer.arrivalTime - customer.startTime);
                totalServedCustomers++;
                processedCustomers.push_back(customer);
            }
        }
        inService.erase(std::remove_if(inService.begin(), inService.end(), [this](const Customer &c)
                                       { return c.departureTime <= currentTime; }),
                        inService.end());
    }

    void processQueue()
    {
        while (!queue.empty() && inService.size() < S)
        {
            Customer &customer = queue.front();
            customer.startTime = currentTime;
            customer.departureTime = currentTime + customer.serviceTime;
            inService.push_back(customer);
            queue.pop();
        }
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
        while (currentTime < simulationTime)
        {
            // 處理離開顧客
            processDepartures();

            // 處理到達顧客
            Customer newCustomer = generateCustomer();
            processArrival(newCustomer);
            currentTime = newCustomer.arrivalTime;

            // 將顧客從隊列移動到服務台
            processQueue();
        }
    }
    // pointer value
    double L()
    {
        return totalWaitTime / currentTime;
    }

    double Lq()
    {

        return totalQueueWaitTime / currentTime;
    }

    double W()
    {
        if (totalServedCustomers > 0)
        {
            return totalWaitTime / totalServedCustomers;
        }
        return 0.0;
    }

    double Wq()
    {
        if (totalServedCustomers > 0)
        {
            return totalQueueWaitTime / totalServedCustomers;
        }
        return 0.0;
    }

    //debug
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
    double mu = 35;
    double simulationTime = 1000.0; // 設定模擬時間，這可以根據需要進行調整

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
    std::cout << "Results saved to queueing_system_results.csv" << std::endl;

    return 0;
}