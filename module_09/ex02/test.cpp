#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/time.h>

long long get_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

struct Pair
{
    int winner;
    int loser;
};

void print(const std::vector<Pair> &p)
{
    for (std::vector<Pair>::const_iterator it = p.begin(); it != p.end(); ++it)
        std::cout << "(winner: " << it->winner << " loser: " << it->loser << ")" << std::endl;
}

bool comparePairs(const Pair &a, const Pair &b)
{
    return a.winner < b.winner;
}

std::vector<int> generateJacobsSeq(int size)
{
    std::vector<int> jacob;

    if (size == 0)
        return jacob;

    jacob.push_back(1); // J(1)
    jacob.push_back(3); // J(2)

    while (jacob.back() < size)
    {
        int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        jacob.push_back(next);
    }
    return jacob;
}

std::vector<int> getInsertionIndices(int pendSize)
{
    std::vector<int> indices;
    if (pendSize <= 0)
        return indices;

    std::vector<int> jacob = generateJacobsSeq(pendSize);

    int lastPos = 1;
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        int currentJacob = jacob[i];

        // Don't go past the end of the pend list
        int startPos = std::min(currentJacob, pendSize);

        // Backtrack: From current boundary down to the end of the last boundary
        for (int j = startPos; j > lastPos; --j)
        {
            // We use j - 1 because pend is 0-indexed
            // (Note: Index 0 is skipped because it's the "Free Move")
            indices.push_back(j - 1);
        }
        lastPos = startPos;
    }
    return indices;
}

void printFinalChain(const std::vector<int>& main_chain) {
    std::cout << "After:  ";
    for (std::vector<int>::const_iterator it = main_chain.begin(); it != main_chain.end(); ++it) {
        std::cout << *it << (it + 1 == main_chain.end() ? "" : " ");
    }
    std::cout << std::endl;
}

int main()
{
    long long start = get_time();
    int elemnts[] = {9, 2, 3, 190, 1, 5, 100};

    std::vector<int> input(elemnts, elemnts + (sizeof(elemnts) / sizeof(int)));

    int left_alone = -1;
    if ((input.size() % 2) != 0)
    {
        left_alone = input.back();
        input.pop_back();
    }

    std::vector<Pair> pairs;

    for (size_t i = 0; i < input.size() - 1; i += 2)
    {
        Pair n;
        if (input[i] > input[i + 1])
        {
            n.winner = input[i];
            n.loser = input[i + 1];
        }
        else
        {
            n.winner = input[i + 1];
            n.loser = input[i];
        }
        pairs.push_back(n);
    }

    std::cout << "first pairs:" << std::endl;
    print(pairs);

    std::sort(pairs.begin(), pairs.end(), comparePairs);
    std::cout << "pairs after sorting:" << std::endl;
    print(pairs);

    std::vector<int> main_chain;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main_chain.push_back(pairs[i].winner);
        pend.push_back(pairs[i].loser);
    }

    // The "Free" Move
    main_chain.insert(main_chain.begin(), pend[0]);
    pend.erase(pend.begin());
    std::cout << pend.size() << std::endl;
    std::vector<int> insertionOrder = getInsertionIndices(pend.size());

    // 3. Loop through the indices
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int pendIndex = insertionOrder[i];
        int itemToInsert = pend[pendIndex];

        // Perform Binary Search to find the position in main_chain
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), itemToInsert);

        // Insert it
        main_chain.insert(pos, itemToInsert);
    }
    if (left_alone != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), left_alone);
        main_chain.insert(pos, left_alone);
    }
    
    printFinalChain(main_chain);
    std::cout << "W7dani: " << left_alone << std::endl;
    long long end = get_time();
    std::cout << "Time: " << (end - start) << " us" << std::endl;
}