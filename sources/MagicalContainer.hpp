#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP

#include <vector>
#include <set>
#include <stdexcept>

namespace ariel
{

    class MagicalContainer
    {
    private:
        std::set<int> elements;
        std::vector<const int *> elementsAsc;
        std::vector<const int *> elementsSide;
        std::vector<const int *> elementsP;

        static bool isPrime(int num);

    public:
        void addElement(int element);
        void removeElement(int element);
        size_t size() const;

        class AscendingIterator
        {
        public:
            AscendingIterator(MagicalContainer &container, size_t index);
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
			AscendingIterator(AscendingIterator &&other) noexcept;
			~AscendingIterator() ;
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(const AscendingIterator &other);
            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            int operator*() const;
            AscendingIterator &operator++();

            AscendingIterator begin()
            {
                return AscendingIterator(container, 0);
            }
            AscendingIterator end()
            {
                return AscendingIterator(container, container.elementsAsc.size());
            }

        private:
            MagicalContainer &container;
            size_t index;
        };

        class SideCrossIterator
        {
        public:
            SideCrossIterator(MagicalContainer &container, size_t index);
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
			SideCrossIterator(SideCrossIterator &&other) noexcept;
            ~SideCrossIterator();
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept;
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            int operator*() const;
            SideCrossIterator &operator++();

            SideCrossIterator begin()
            {
                return SideCrossIterator(container, 0);
            }
            SideCrossIterator end()
            {
                return SideCrossIterator(container, container.elementsSide.size());
            }

        private:
            MagicalContainer &container;
            size_t index;
        };

        class PrimeIterator
        {
        public:
            PrimeIterator(MagicalContainer &container, size_t index);
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator();
			PrimeIterator(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(PrimeIterator &&other) noexcept;
            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            int operator*() const;
            PrimeIterator &operator++();

            PrimeIterator begin()
            {
                return PrimeIterator(container, 0);
            }
            PrimeIterator end()
            {
                return PrimeIterator(container, container.elementsP.size());
            }

        private:
            MagicalContainer &container;
            size_t index;
        };
    };

} 

#endif 
