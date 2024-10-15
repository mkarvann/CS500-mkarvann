CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp event.cpp event_factory.cpp event_manager.cpp user.cpp notification_system.cpp search_strategy.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = event_management_system

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)