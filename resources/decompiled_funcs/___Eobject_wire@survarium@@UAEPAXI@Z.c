survarium::object_wire *__thiscall survarium::object_wire::`vector deleting destructor'(
        survarium::object_wire *this,
        char a2)
{
  survarium::object_wire::~object_wire(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
