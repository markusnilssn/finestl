#include <iostream>

#include "Array.h"
#include "Map.h"
#include "Random.h"
#include "List.h"
#include "ObservableList.h"
#include "ObservableMap.h"

#include <cassert>

#include <string>
#include <array>

using namespace simpletl;

void testarray()
{
    // Create an array
    Array<int, 5> arr;

    // Test default constructor
    assert(arr.Size() == 5);
    for (size_t i = 0; i < arr.Size(); ++i)
        assert(arr[i] == 0);

    // Test initializer list constructor
    Array<int, 3> arr2 = { 1, 2, 3 };
    assert(arr2.Size() == 3);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);

    // Test ElementAt() function
    assert(arr2.ElementAt(0) == 1);
    assert(arr2.ElementAt(1) == 2);
    assert(arr2.ElementAt(2) == 3);

    // Test Contains() function
    assert(arr2.Contains(1));
    assert(arr2.Contains(2));
    assert(arr2.Contains(3));
    assert(!arr2.Contains(4));

    // Test indexing operators
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    assert(arr[0] == 10);
    assert(arr[1] == 20);
    assert(arr[2] == 30);

    // Test const correctness
    const Array<int, 4> constArr = { 1, 2, 3, 4 };
    assert(constArr[0] == 1);
    assert(constArr[1] == 2);
    assert(constArr[2] == 3);
    assert(constArr[3] == 4);
    assert(constArr.ElementAt(0) == 1);
    assert(constArr.ElementAt(1) == 2);
    assert(constArr.ElementAt(2) == 3);
    assert(constArr.ElementAt(3) == 4);

    // Test out-of-bounds indexing (assertions are expected to fail)
    assert(arr[5] == 0);
    assert(arr2[3] == 0);
}

void testmap()
{
    // Create a map
    Map<int, std::string> map;
    assert(map.IsEmpty());
    assert(map.Size() == 0);

    // Add elements
    map.Add(1, "One");
    map.Add(2, "Two");
    map.Add(3, "Three");
    assert(map.Size() == 3);
    assert(!map.IsEmpty());

    // Access elements
    assert(map.Contains(1));
    assert(map.Contains(2));
    assert(map.Contains(3));
    assert(!map.Contains(4));
    assert(map[1] == "One");
    assert(map[2] == "Two");
    assert(map[3] == "Three");

    // Modify elements
    map[2] = "New Two";
    assert(map[2] == "New Two");

    // Remove elements
    map.Remove(1);
    assert(map.Size() == 2);
    assert(!map.Contains(1));

    // Clear the map
    map.Clear();
    assert(map.IsEmpty());
    assert(map.Size() == 0);
}

void testlist()
{
    // Test default constructor
    List<int> list;
    assert(list.Size() == 0);
    assert(list.IsEmpty());

    // Test constructor with capacity
    List<int> listWithCapacity(10);
    assert(listWithCapacity.Size() == 0);
    assert(listWithCapacity.Capacity() == 10);
    assert(listWithCapacity.IsEmpty());

    // Test initializer list constructor
    List<int> listWithInitializer = { 1, 2, 3 };
    assert(listWithInitializer.Size() == 3);
    assert(listWithInitializer.Capacity() >= 3);
    assert(!listWithInitializer.IsEmpty());
    assert(listWithInitializer[0] == 1);
    assert(listWithInitializer[1] == 2);
    assert(listWithInitializer[2] == 3);

    // Test Add method
    list.Add(5);
    assert(list.Size() == 1);
    assert(list.Capacity() >= 1);
    assert(!list.IsEmpty());
    assert(list[0] == 5);

    // Test Remove method
    list.Remove(5);
    assert(list.Size() == 0);
    assert(list.IsEmpty());

    // Test RemoveAt method
    listWithInitializer.RemoveAt(1);
    assert(listWithInitializer.Size() == 2);
    assert(listWithInitializer[0] == 1);
    assert(listWithInitializer[1] == 3);

    // Test Contains method
    listWithInitializer.Add(5);
    assert(listWithInitializer.Contains(5));
    assert(!listWithInitializer.Contains(2));

    // Test Clear method
    listWithInitializer.Clear();
    assert(listWithInitializer.Size() == 0);
    assert(listWithInitializer.IsEmpty());

    // Test operator[]
    listWithInitializer.Add(100);
    assert(listWithInitializer[0] == 100);
    const List<int>& constList = listWithInitializer;
    assert(constList[0] == 100);

    // Test Size, Capacity, and IsEmpty methods
    assert(listWithInitializer.Size() == 1);
    assert(listWithInitializer.Capacity() >= 1);
    assert(!listWithInitializer.IsEmpty());
}

int main()
{

    testlist();
    testmap();
    testarray();

   

	return EXIT_SUCCESS;
}