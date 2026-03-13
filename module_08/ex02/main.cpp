#include "MutantStack.h"

int main()
{
    std::cout << "=== MutantStack<int> Basic Operations ===" << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(99);

        std::cout << "Iterating (mutable): ";

        for (std::deque<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;

        std::cout << "Iterating (const): ";

        const MutantStack<int>& cmstack = mstack;

        for (std::deque<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;
    }

    return 0;
}