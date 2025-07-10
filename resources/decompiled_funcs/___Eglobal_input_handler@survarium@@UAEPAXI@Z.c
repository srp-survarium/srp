survarium::global_input_handler *__thiscall survarium::global_input_handler::`vector deleting destructor'(
        survarium::global_input_handler *this,
        char a2)
{
  this->__vftable = (survarium::global_input_handler_vtbl *)&survarium::global_input_handler::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
