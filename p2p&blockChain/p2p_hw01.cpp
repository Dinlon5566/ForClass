// C++14
// code by Dinlon5566(408261292)

#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;

const int n = 10000;

class Node
{
public:
    uint32_t id;
    Node *predecessor = NULL;
    Node *successor = NULL;
    vector<Node *> fingerTable;

    // initialize node id
    Node() : id(getNewID()){};
    Node(int id) : id(id){};
    Node(vector<uint32_t> &exists)
    {
        id = getUniqueID(exists);
    }

    // reload operator
    bool operator<(const Node &tNode) const
    {
        return id < tNode.id;
    }
    bool operator>(const Node &tNode) const
    {
        return id > tNode.id;
    }
    bool operator==(const Node &tNode) const
    {
        return id == tNode.id;
    }

    static uint32_t getUniqueID(vector<uint32_t> &exists)
    {
        uint32_t tid;
        do
        {
            tid = getNewID();
        } while (find(exists.begin(), exists.end(), tid) != exists.end());
        exists.push_back(tid);
        return tid;
    }

    // return 32-bit random number
    static uint32_t getNewID()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static bool isRand = false;

        if (!isRand)
        {
            gen.seed(time(NULL));
            isRand = true;
        }
        return gen();
    }
};

void createTopology(vector<Node> &nodeList, vector<uint32_t> &idList)
{
    // create nodes
    for (int i = 0; i < n; i++)
    {
        Node tid(idList);
        nodeList.push_back(tid);
    }

    sort(idList.begin(), idList.end());
    sort(nodeList.begin(), nodeList.end());

    // set successor and predecessor
    for (int i = 0; i < n; i++)
    {
        nodeList[i].successor = &nodeList[(i + 1) % n];
        nodeList[i].predecessor = &nodeList[(i - 1 + n) % n];
    }

    // set finger table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            uint64_t tid = ((uint64_t)nodeList[i].id + (uint64_t)(1 << (uint64_t)j)) % ((uint64_t)1 << 32);

            int index = lower_bound(idList.begin(), idList.end(), tid) - idList.begin();

            if (DEBUG)
            {
                if (i == n - 20)
                {
                    // tid should <= id
                    cout << endl
                         << "tid   " << tid << endl;
                    cout << "index " << index << endl;
                    cout << "id    " << nodeList[index].id << endl;
                }
            }

            if (index == n)
            {
                index = 0;
            }
            nodeList[i].fingerTable.push_back(&nodeList[index]);
        }
    }
}

void mapKeysToPeers(vector<Node> &nodeList, vector<uint32_t> &idList)
{
    int count[n];
    if (DEBUG && false)
        for (uint32_t i : idList)
            cout << i << " ";
    // i : 10, 20, 30, ..., 100 (numK)
    for (int i = 10; i <= 100; i = i + 10)
    {
        memset(count, 0, sizeof(count));
        for (int j = 0; j < i * n; j++)
        {
            int k = Node::getNewID();
            int index = lower_bound(idList.begin(), idList.end(), k) - idList.begin();
            if (index == n)
            {
                index = 0;
            }
            count[index]++;

            if (DEBUG && false)
            {
                if (count[index] > 1000)
                {
                    cout << "100:" << index << "/" << nodeList[index].id << endl;
                }
            }
        }

        if (DEBUG && false)
        {
            for (int p = 0; p < n; p++)
            {
                if (count[p] == 0)
                {
                    Node *tn = &nodeList[p];
                    cout << tn->predecessor->id << " <- " << tn->id << " -> " << tn->successor->id << endl;
                }
            }
        }

        sort(count, count + n);
        // count max&min
        unsigned int maxCount = count[n - 1], minCount = count[0], midCount = count[n / 2];

        cout << "LC [" << i * n << "]:";
        cout << minCount << " " << midCount << " " << maxCount << endl;
    }
}
void computeSearchHops(vector<Node> &nodeList, vector<uint32_t> &idList)
{
    int hops[32];
    int err = 0;
    int doNothing = 0;
    memset(hops, 0, sizeof(hops));
    for (int i = 0; i < n; i++)
    {
        // Each node is the initiator of 100 searches
        for (int j = 0; j < 100; j++)
        {
            uint32_t target = Node::getNewID();
            int hop = 0;
            int targetNodeIndex = lower_bound(idList.begin(), idList.end(), target) - idList.begin();
            if (targetNodeIndex == n)
            {
                targetNodeIndex = 0;
            }

            Node *targetNode = &nodeList[targetNodeIndex];
            Node *currentNode = &nodeList[i];
            while (currentNode->id != targetNode->id)
            {
                hop++;

                if (hop >= 32)
                {
                    doNothing++;
                    err++;
                    break;
                }

                // find by finger table
                uint32_t dif = targetNode->id - currentNode->id;
                int index = 31 - __builtin_clz(dif);
                currentNode = currentNode->fingerTable[index];
            }
            hops[hop]++;
        }
    }
    cout << "hops: " << endl;
    for (int i = 0; i < 32; i++)
    {
        cout << hops[i] << " ";
    }
    cout << endl
         << "ErrorTime: " << err << endl;
    cout << "doNothing: " << doNothing << endl;
}

int main()
{
    // malloc for nodeList
    vector<Node> nodeList;
    vector<uint32_t> idList;

    createTopology(nodeList, idList);
    mapKeysToPeers(nodeList, idList);
    computeSearchHops(nodeList, idList);

    if (DEBUG)
    {
        // show nodeList[0]'s finger table
        Node *tn = &nodeList[n / 2];
        cout << tn->predecessor->id << " <- " << tn->id << " -> " << tn->successor->id << endl;
        for (int i = 0; i < 32; i++)
        {
            cout << i << " " << tn->id + (1 << i) << ":" << tn->fingerTable[i]->id << endl;
        }
    }
    return 0;
}
