cmake_minimum_required(VERSION 3.27)
project(Big_Homework)

set(CMAKE_CXX_STANDARD 20)

add_executable(A A_Matrix/matrix_test.cpp)
add_executable(B B_Array/array_test.cpp)
add_executable(C C_Vector/vector_public_test.cpp)
add_executable(D D_Vector_plus/vector_public_test.cpp)
add_executable(E E_SharedPtr/shared_ptr_public_test.cpp)
add_executable(F F_ItertoolsRange/range_public_test.cpp)
add_executable(G G_UnorderedSet/unordered_set_public_test.cpp)
add_executable(H H.cpp)
add_executable(I I.cpp)
add_executable(J J.cpp)
add_executable(K K.cpp)
add_executable(L L_BigInteger/big_integer_test.cpp)