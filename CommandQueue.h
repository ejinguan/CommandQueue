#ifndef __COMMANDQUEUE_H
  #define __COMMANDQUEUE_H

  #include "Arduino.h"
  #include "stdlib.h"

  // This is actually only 7 chars with space for a '\0'
  #define COMMANDLENGTH 8
  
  class CommandQueue {
    private:
      int _queue_length;
      int _start_idx; // inclusive - read here
      int _end_idx;   // exclusive - insert here
      int _size;      // current size of queue

      //char arr[][COMMANDLENGTH];
      //char** _char_arr;
      String* _string_arr;
  
  
    public:
      CommandQueue(int queue_length);
      ~CommandQueue();

      bool push(String newValue);
      String peek();
      String pop();

      int size();

      int start_idx();
      int end_idx();

      String peekAt(int idx);
    
  };

#endif 
/* __COMMANDQUEUE_H */
