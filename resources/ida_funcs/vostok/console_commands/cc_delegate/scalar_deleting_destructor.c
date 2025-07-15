vostok::console_commands::cc_delegate *__thiscall vostok::console_commands::cc_delegate::`scalar deleting destructor'(
        vostok::console_commands::cc_delegate *this,
        char a2)
{
  vostok::console_commands::cc_delegate::~cc_delegate(this, (survarium::keyboard_key_descr ***)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
