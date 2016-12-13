cmake_minimum_required(VERSION 3.6)
project(warehouse-work)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES src/main.cpp src/WarehouseWorkException.h src/NotNumberException.h src/Client.cpp src/Client.h src/Contract.cpp src/Contract.h src/Invoice.cpp src/Invoice.h src/Product.cpp src/Product.h src/Request.cpp src/Request.h src/Supplier.cpp src/Supplier.h src/Warehouse.cpp src/Warehouse.h)
add_executable(warehouse-work ${SOURCE_FILES})