#include "PmergeMe.h"

template <typename T>
PmergeMe<T>::PmergeMe() : time(0) {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) : container(other.container), time(other.time) {}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        container = other.container;
        time = other.time;
    }
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
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

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
    for (size_t i = 0; i < jacob.size(); ++i)
    {
        int startPos = std::min(jacob[i], pendSize);

        for (int j = startPos; j > lastPos; --j)
            indices.push_back(j - 1);

        lastPos = startPos;
    }

    return indices;
}

template <typename T>
void PmergeMe<T>::sort(T &input)
{
    clock_t start = clock();

    if (input.size() <= 1)
    {
        container = input;
        time = 0;
        return;
    }

    int left_alone = 0;
    bool has_left_alone = (input.size() % 2 != 0);

    if (has_left_alone)
    {
        left_alone = input.back();
        input.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];

        if (a > b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }

    std::sort(pairs.begin(), pairs.end());

    T main_chain;
    T pend;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main_chain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // free move
    main_chain.insert(main_chain.begin(), pend[0]);

    T indices = getInsertionIndices(pend.size());

    for (size_t i = 0; i < indices.size(); ++i)
    {
        int value = pend[indices[i]];
        typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), value);
        main_chain.insert(pos, value);
    }

    if (has_left_alone)
    {
        typename T::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), left_alone);
        main_chain.insert(pos, left_alone);
    }

    container = main_chain;

    clock_t end = clock();

    this->time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
}

template <typename T>
double PmergeMe<T>::getTime() const { return this->time; }

template <typename T>
const T &PmergeMe<T>::getContainer() const { return this->container; }

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;