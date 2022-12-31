
#include "Arduino.h"
#include "CommandQueue.h"


CommandQueue::CommandQueue(int queue_length)
{
  //_char_arr = (char**) new char[queue_length][COMMANDLENGTH];
  _string_arr = new String[queue_length];

  //for (int i=0; i<queue_length; i++) {
  //  _string_arr[i] = String("");
  //}

  _queue_length = queue_length;
   
  _start_idx = 0;
  _end_idx = 0;
  _size = 0;
}

CommandQueue::~CommandQueue()
{
  //delete[] _char_arr;
  delete[] _string_arr;
}

bool CommandQueue::push(String newValue) {
  if (_size == _queue_length) return false; // If queue is full
  
  _string_arr[_end_idx] = newValue;         // Assign at the end index
  _end_idx++;                               // Increment and wrap around
  _end_idx = _end_idx % _queue_length;
  _size++;                                  // Update size
}

String CommandQueue::peek() {
  if (_size == 0) return String("");        // Exit without updating the array
  
  return _string_arr[_start_idx];           // Read the right index
}

String CommandQueue::pop() {
  if (_size == 0) return String("");        // Exit without updating the array
  
  String tmp = _string_arr[_start_idx];     // Read the right index
  _string_arr[_start_idx] = String("");

  _start_idx++;                             // Increment and wrap around
  _start_idx = _start_idx % _queue_length;
  _size--;                                  // Update size
  
  return tmp;
}

int CommandQueue::size() {
  return _size;
}
int CommandQueue::start_idx() {
  return _start_idx;
}
int CommandQueue::end_idx() {
  return _end_idx;
}

String CommandQueue::peekAt(int idx) {
  return _string_arr[idx];
}