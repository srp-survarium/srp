survarium::booby_trap_set_core *__thiscall survarium::booby_trap_set_core::`vector deleting destructor'(
        survarium::booby_trap_set_core *this,
        char a2)
{
  survarium::booby_trap_set_core::~booby_trap_set_core(this);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
