survarium::victory_items_container_core *__thiscall survarium::victory_items_container_core::`vector deleting destructor'(
        survarium::victory_items_container_core *this,
        char a2)
{
  survarium::victory_items_container_core::~victory_items_container_core(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
