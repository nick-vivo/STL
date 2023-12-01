#ifndef __SORTS_HH__
#define __SORTS_HH__

/**
 *  Работает со своей библиотекой STL пока в доступе есть:
 *
 *      1. List с собственными итераторами
 */

namespace mstd
{

    // #Полезные функции

    template <typename T>
    inline void swapNative(T &first, T &second)
    {
        T tmp(first);

        first = second;

        second = tmp;
    }

    // #1

    /**
     *  @brief  Select Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void bubbleSort(Iterator begin, Iterator end)
    {
        bool update;

        while (begin != end)
        {
            update = false;

            for (Iterator it = begin; it != end; ++it)
            {
                if (*it > *(it + 1))
                {
                    swapNative(*it, *(it + 1));

                    update = true;
                }
            }

            if (!update)
                break;
        }
    }

    /**
     *  @brief  Select Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void insertSort(Iterator begin, Iterator end)
    {
        if (begin == end)
        {
            return;
        }

        for (Iterator it = begin + 1; it != end + 1; ++it)
        {
            for (Iterator it2 = begin; it2 != it; ++it2)
            {
                if (*it2 > *(it))
                {
                    swapNative(*it2, *(it));
                }
            }
        }
    }

    /**
     *  @brief  Select Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void selectSort(Iterator begin, Iterator end)
    {
        Iterator it_min;

        for (Iterator it = begin; it != end; ++it)
        {

            it_min = it;

            for (Iterator it2 = it + 1; it2 != end + 1; ++it2)
            {
                if (*it_min > *it2)
                {
                    it_min = it2;
                }
            }

            swapNative(*it_min, *it);
        }
    }

    // #2

    using size_t = long int;

    template <class Iterator>
    inline size_t distance(Iterator begin, Iterator end)
    {
        size_t count = 0;

        while (begin != end)
        {
            ++begin;
            ++count;
        }
        return count;
    }

    /**
     *  @brief  Shell Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void shellSort(Iterator begin, Iterator end)
    {
        int Length = mstd::distance(begin, end) + 1;
        if (Length == 0 || Length == 1)
        {
            return;
        }
        int j;
        int step = Length / 2;

        while (step > 0)
        {
            for (int i = 0; i < (Length - step); i++)
            {
                j = i;
                while ((j >= 0) && (*(begin + j) > *(begin + j + step)))
                {
                    swapNative(*(begin + j), *(begin + j + step));
                    j = j - step;
                }
            }
            step = step / 2;
        }
    }

    /**
     *  @brief  Cocktail/Sheker Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void cocktailSort(Iterator begin, Iterator end)
    {
        int Length = mstd::distance(begin, end) + 1;
        if (Length == 0 || Length == 1)
        {
            return;
        }
        int b = 0;
        int left = 0;
        int right = Length - 1;
        while (left < right)
        {
            for (int i = left; i < right; i++)
            {
                if (*(begin + i) > *(begin + i + 1))
                {
                    swapNative(*(begin + i), *(begin + i + 1));
                    b = i;
                }
            }
            right = b;
            if (left >= right)
                break;
            for (int i = right; i > left; i--)
            {
                if (*(begin + i - 1) > *(begin + i))
                {
                    swapNative(*(begin + i - 1), *(begin + i));
                    b = i;
                }
            }
            left = b;
        }
    }

    /**
     *  @brief  Quick Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void quickSort(Iterator begin, Iterator end)
    {
        int first = 0;
        int last = mstd::distance(begin, end);
        if (first < last)
        {
            int left = first, right = last, middle = *(begin + (left + right) / 2);
            do
            {
                while (*(begin + left) < middle)
                    left++;
                while (*(begin + right) > middle)
                    right--;
                if (left <= right)
                {
                    swapNative(*(begin + left), *(begin + right));
                    left++;
                    right--;
                }
            } while (left <= right);
            quickSort(begin + first, begin + right);
            quickSort(begin + left, begin + last);
        }
    }

    // #3

    /**
     *  @brief  Comb Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void combSort(Iterator begin, Iterator end)
    {
        int gap = mstd::distance(begin, end) + 1;

        int Length = gap;
        if (Length == 0 || Length == 1)
        {
            return;
        }

        bool swaps = true;
        while (gap > 1 || swaps)
        {
            gap /= 1.247330950103979;
            swaps = false;

            for (int i = 0; i < Length - gap; ++i)
            {
                if (*(begin + i) > *(begin + i + gap))
                {
                    swapNative(*(begin + i), *(begin + i + gap));
                    swaps = true;
                }
            }
        }
    }

    template <class Iterator>
    void heapify(Iterator begin, int N, int i)
    {

        int largest = i;

        int l = 2 * i + 1;

        int r = 2 * i + 2;

        if (l<N &&*(begin + l)> * (begin + largest))
            largest = l;

        if (r<N &&*(begin + r)> * (begin + largest))
            largest = r;

        if (largest != i)
        {
            swapNative(*(begin + i), *(begin + largest));

            heapify(begin, N, largest);
        }
    }

    /**
     *  @brief  Comb Sort for two iterators.
     *  @param  begin  First parametr for this function. This parametr = begin iterator. Doesn't use bad Iterator!
     *
     *  @param  end  First parametr for this function. This parametr = end iterator. Doesn't use bad Iterator!
     */
    template <class Iterator>
    void heapSort(Iterator begin, Iterator end)
    {
        int N = mstd::distance(begin, end) + 1;

        if (N == 0 || N == 1)
        {
            return;
        }

        for (int i = N / 2 - 1; i >= 0; i--)
            heapify(begin, N, i);

        for (int i = N - 1; i > 0; i--)
        {

            swapNative(*begin, *(begin + i));

            heapify(begin, i, 0);
        }
    }

}

#endif