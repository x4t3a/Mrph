export CXX := clang++
export CXXFLAGS := --std=c++14

static_polymorphism_test: static_polymorphism_test.cpp static_polymorphism.hpp
	${CXX} ${CXXFLAGS} static_polymorphism_test.cpp -o $@
