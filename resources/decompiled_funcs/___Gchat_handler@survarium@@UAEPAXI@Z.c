survarium::chat_handler *__thiscall survarium::chat_handler::`scalar deleting destructor'(
        survarium::chat_handler *this,
        char a2)
{
  survarium::chat_handler::~chat_handler(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
