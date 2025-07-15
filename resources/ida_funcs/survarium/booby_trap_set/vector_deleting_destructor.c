survarium::booby_trap_set *__thiscall survarium::booby_trap_set::`vector deleting destructor'(
        survarium::booby_trap_set *this,
        char a2)
{
  survarium::booby_trap_set::~booby_trap_set(this, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
