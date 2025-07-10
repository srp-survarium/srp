survarium::booby_trap *__thiscall survarium::booby_trap::`vector deleting destructor'(
        survarium::booby_trap *this,
        char a2)
{
  survarium::booby_trap::~booby_trap(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
