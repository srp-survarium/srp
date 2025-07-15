survarium::victory_item_core *__thiscall survarium::victory_item_core::`scalar deleting destructor'(
        survarium::victory_item_core *this,
        char a2)
{
  survarium::victory_item_core::~victory_item_core(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
