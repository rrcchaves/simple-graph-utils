PROJ_DIR = /home/ricardo/Projetos/simple-graph-utils
CATCH_SINGLE_INCLUDE = $(PROJ_DIR)/test/include
SRC_DIR = $(PROJ_DIR)/src
SRC_BASE_DIR = $(SRC_DIR)/base

test:
	g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -I$(SRC_DIR) -o testbase $(SRC_BASE_DIR)/simplevertex.cpp $(SRC_BASE_DIR)/simpleedge.cpp testsimplevertex.cpp testsimpleedge.cpp
