survarium::booby_trap_core *__thiscall survarium::booby_trap_core::`vector deleting destructor'(
        survarium::booby_trap_core *this,
        char a2)
{
  survarium::booby_trap_core::~booby_trap_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
