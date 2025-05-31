#include "CppUnitTest.h"
#include "LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{
    TEST_CLASS(LinkedListTests)
    {
    public:

        // Тесты конструкторов
        TEST_METHOD(DefaultConstructor_CreatesEmptyList)
        {
            LinkedList list;
            Assert::IsTrue(list.empty());
            Assert::AreEqual(static_cast<size_t>(0), list.length());
        }

        TEST_METHOD(InitializerListConstructor_CreatesListWithElements)
        {
            LinkedList list = { 1, 2, 3, 4 };
            Assert::IsFalse(list.empty());
            Assert::AreEqual(static_cast<size_t>(4), list.length());
            Assert::AreEqual(std::string("1 -> 2 -> 3 -> 4"), list.to_string());
        }

        TEST_METHOD(CopyConstructor_CreatesExactCopy)
        {
            LinkedList original = { 5, 6, 7 };
            LinkedList copy(original);

            Assert::AreEqual(original.length(), copy.length());
            Assert::AreEqual(original.to_string(), copy.to_string());
        }

        TEST_METHOD(MoveConstructor_MovesContentAndLeavesOriginalEmpty)
        {
            LinkedList original = { 8, 9, 10 };
            LinkedList moved(std::move(original));

            Assert::AreEqual(static_cast<size_t>(3), moved.length());
            Assert::AreEqual(std::string("8 -> 9 -> 10"), moved.to_string());
            Assert::IsTrue(original.empty());
        }

        // Тесты операторов присваивания
        TEST_METHOD(CopyAssignment_CreatesExactCopy)
        {
            LinkedList original = { 11, 12, 13 };
            LinkedList copy;
            copy = original;

            Assert::AreEqual(original.length(), copy.length());
            Assert::AreEqual(original.to_string(), copy.to_string());
        }

        TEST_METHOD(MoveAssignment_MovesContentAndLeavesOriginalEmpty)
        {
            LinkedList original = { 14, 15, 16 };
            LinkedList moved;
            moved = std::move(original);

            Assert::AreEqual(static_cast<size_t>(3), moved.length());
            Assert::AreEqual(std::string("14 -> 15 -> 16"), moved.to_string());
            Assert::IsTrue(original.empty());
        }

        // Тесты методов вставки и удаления
        TEST_METHOD(Insert_AddsElementsToEnd)
        {
            LinkedList list;
            list.insert(1);
            list.insert(2);
            list.insert(3);

            Assert::AreEqual(static_cast<size_t>(3), list.length());
            Assert::AreEqual(std::string("1 -> 2 -> 3"), list.to_string());
        }

        TEST_METHOD(Remove_DeletesFirstOccurrenceAndReturnsTrue)
        {
            LinkedList list = { 1, 2, 3, 2, 4 };

            Assert::IsTrue(list.remove(2));
            Assert::AreEqual(static_cast<size_t>(4), list.length());
            Assert::AreEqual(std::string("1 -> 3 -> 2 -> 4"), list.to_string());

            Assert::IsTrue(list.remove(4));
            Assert::AreEqual(static_cast<size_t>(3), list.length());
            Assert::AreEqual(std::string("1 -> 3 -> 2"), list.to_string());

            Assert::IsFalse(list.remove(5));
            Assert::AreEqual(static_cast<size_t>(3), list.length());
        }

        // Тесты проверки содержимого
        TEST_METHOD(Contains_ReturnsTrueForExistingElements)
        {
            LinkedList list = { 5, 10, 15 };

            Assert::IsTrue(list.contains(5));
            Assert::IsTrue(list.contains(10));
            Assert::IsTrue(list.contains(15));
            Assert::IsFalse(list.contains(20));
        }

        TEST_METHOD(Empty_ReturnsTrueForEmptyList)
        {
            LinkedList list;
            Assert::IsTrue(list.empty());

            list.insert(1);
            Assert::IsFalse(list.empty());

            list.remove(1);
            Assert::IsTrue(list.empty());
        }

        // Тесты операторов доступа
        TEST_METHOD(SubscriptOperator_ReturnsCorrectElement)
        {
            LinkedList list = { 10, 20, 30 };

            Assert::AreEqual(10, list[0]);
            Assert::AreEqual(20, list[1]);
            Assert::AreEqual(30, list[2]);

            list[1] = 25;
            Assert::AreEqual(25, list[1]);
        }

        TEST_METHOD(SubscriptOperator_ThrowsOutOfRangeForInvalidIndex)
        {
            LinkedList list = { 1, 2, 3 };

            auto func = [&list]() { return list[3]; };
            Assert::ExpectException<std::out_of_range>(func);

            auto func2 = [&list]() { return list[10]; };
            Assert::ExpectException<std::out_of_range>(func2);
        }

        // Тесты операторов сдвига
        TEST_METHOD(LeftShiftOperator_InsertsElement)
        {
            LinkedList list;
            list << 1 << 2 << 3;

            Assert::AreEqual(static_cast<size_t>(3), list.length());
            Assert::AreEqual(std::string("1 -> 2 -> 3"), list.to_string());
        }

        TEST_METHOD(RightShiftOperator_RemovesLastElement)
        {
            LinkedList list = { 4, 5, 6 };
            int value;

            list >> value;
            Assert::AreEqual(6, value);
            Assert::AreEqual(static_cast<size_t>(2), list.length());

            list >> value;
            Assert::AreEqual(5, value);
            Assert::AreEqual(static_cast<size_t>(1), list.length());
        }

        TEST_METHOD(RightShiftOperator_ThrowsOutOfRangeForEmptyList)
        {
            LinkedList list;
            int value;

            auto func = [&list, &value]() { list >> value; };
            Assert::ExpectException<std::out_of_range>(func);
        }

        // Тесты строкового представления
        TEST_METHOD(ToString_ReturnsCorrectStringRepresentation)
        {
            LinkedList emptyList;
            Assert::AreEqual(std::string(""), emptyList.to_string());

            LinkedList singleItem = { 42 };
            Assert::AreEqual(std::string("42"), singleItem.to_string());

            LinkedList multipleItems = { 1, 2, 3 };
            Assert::AreEqual(std::string("1 -> 2 -> 3"), multipleItems.to_string());
        }
    };
}