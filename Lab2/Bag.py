class Bag:

    # creates a new, empty Bag
    def __init__(self):
        # theta(1)
        self.__elements = []
        self.__occurrence = []

    # adds a new element to the Bag
    def add(self, e):
        # O(n)
        if e not in self.__elements:
            self.__elements.append(e)
            self.__occurrence.append(1)
            return
        self.__occurrence[self.__elements.index(e)] += 1

    # removes one occurrence of an element from a Bag
    # returns True if an element was actually removed (the Bag contained the element e), or False if nothing was removed
    def remove(self, e):
        # O(n)
        if e in self.__elements:
            i = self.__elements.index(e)
            if self.__occurrence[i] > 1:
                self.__occurrence[i] -= 1
            else:
                del self.__elements[i]
                del self.__occurrence[i]
            return True
        return False

    # searches for an element e in the Bag
    # returns True if the Bag contains the element, False otherwise
    def search(self, e):
        # O(n)
        if e in self.__elements:
            return True
        return False

    # counts and returns the number of times the element e appears in the bag
    def nrOccurrences(self, e):
        # O(n)
        if e in self.__elements:
            return self.__occurrence[self.__elements.index(e)]
        return 0

    # returns the size of the Bag (the number of elements)
    def size(self):
        # theta(n)
        size = 0
        for i in self.__occurrence:
            size += i
        return size

    # returns True if the Bag is empty, False otherwise
    def isEmpty(self):
        # theta(1)
        return len(self.__elements) == 0

    # returns a BagIterator for the Bag
    def iterator(self):
        # theta(1)
        return BagIterator(self)


class BagIterator:

    # creates an iterator for the Bag b, set to the first element of the bag, or invalid if the Bag is empty
    def __init__(self, b):
        # theta(1)
        self.__bag = b
        self.__current = 0
        self.__occurrence = 0

    # returns True if the iterator is valid
    def valid(self):
        # theta(1)
        if self.__current < len(self.__bag._Bag__elements):
            return True
        return False

    # returns the current element from the iterator.
    # throws ValueError if the iterator is not valid
    def getCurrent(self):
        # theta(1)
        if self.valid():
            return self.__bag._Bag__elements[self.__current]
        else:
            raise ValueError()

    # moves the iterator to the next element
    # throws ValueError if the iterator is not valid
    def next(self):
        # theta(1)
        if self.valid():
            if self.__occurrence == self.__bag._Bag__occurrence[self.__current] - 1:
                self.__occurrence = -1
                self.__current += 1
            self.__occurrence += 1
        else:
            raise ValueError()

    # sets the iterator to the first element from the Bag
    def first(self):
        # theta(1)
        self.__current = 0
        self.__occurrence = 0
