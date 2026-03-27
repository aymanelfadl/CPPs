#include "PmergeMe.h"

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
T PmergeMe<T>::parser_input(int ac, char **input)
{
    T raw;

    for (int i = 1; i < ac; i++)
    {
        std::string s(input[i]);
        if (s.find_first_not_of("0123456789") != std::string::npos)
            throw "Error";

        long val = std::atol(input[i]);
        if (val > INT_MAX || val < 0)
            throw "Error";

        raw.insert(raw.end(), static_cast<int>(val));
    }

    return raw;
}

template <typename T>
PmergeMe<T>::PmergeMe(int ac, char **input)
{
    this->container = parser_input(ac, input);
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) : container(other.container) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
    if (this != &other)
        container = other.container;

    return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
T PmergeMe<T>::generateJacobsSeq(int size)
{
    T jacob;
    if (size <= 0)
        return jacob;

    jacob.push_back(1);
    jacob.push_back(3);

    while (jacob.back() < size)
        jacob.push_back(jacob[jacob.size() - 1] + (2 * jacob[jacob.size() - 2]));

    return jacob;
}

template <typename T>
T PmergeMe<T>::getInsertionIndices(int pendSize)
{
    T indices;
    if (pendSize <= 0)
        return indices;

    T jacob = generateJacobsSeq(pendSize);

    int lastPos = 1;
    for (size_t i = 0; i < jacob.size(); i++)
    {
        int startPos = std::min(jacob[i], pendSize);

        for (int j = startPos; j > lastPos; j--)
            indices.push_back(j - 1);

        lastPos = startPos;
    }

    return indices;
}

template <typename T>
T PmergeMe<T>::sort(T& input)
{
    if (input.size() <= 1)
        return input;
    
    int left_alone = -1;
    bool has_left_alone = (input.size() % 2) != 0;

    if (has_left_alone)
    {
        left_alone = input.back();
        input.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    T winners;

    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            pairs.push_back(std::make_pair(input[i], input[i + 1]));
            winners.push_back(input[i]);
        }
        else
        {
            pairs.push_back(std::make_pair(input[i + 1], input[i]));
            winners.push_back(input[i + 1]);
        }
    }

    T winnersS = this->sort(winners);

    T mainChain;
    T pend;

    for (size_t i = 0; i < winnersS.size(); ++i)
    {
        mainChain.push_back(winnersS[i]);
        for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        {
            if (it->first == winnersS[i])
            {
                pend.push_back(it->second);
                pairs.erase(it);
                break;
            }
        }
    }

    // free move
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    T indices = getInsertionIndices(pend.size());

    for (size_t i = 0; i < indices.size(); i++)
    {
        int value = pend[indices[i]];
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
        mainChain.insert(pos, value);
    }

    if (has_left_alone && left_alone != -1)
    {
        typename T::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), left_alone);
        mainChain.insert(pos, left_alone);
    }

    return mainChain;
}

template <typename T>
double PmergeMe<T>::sort()
{
    if (this->container.size() <= 1)
        return 0;

    clock_t start = clock();
    
    this->container = this->sort(this->container);
    
    clock_t end = clock();

    return ((static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6);
}


template <typename T>
const T &PmergeMe<T>::getContainer() const { return this->container; }

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;