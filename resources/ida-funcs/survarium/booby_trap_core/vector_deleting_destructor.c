survarium::booby_trap_core *__thiscall survarium::booby_trap_core::`vector deleting destructor'(
        survarium::booby_trap_core *this,
        char a2)
{
  survarium::booby_trap_core::~booby_trap_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::booby_trap_core *__thiscall survarium::booby_trap_core::`vector deleting destructor'(char *this, char a2)
{
  return survarium::booby_trap_core::`vector deleting destructor'((survarium::booby_trap_core *)(this - 16), a2);
}


survarium::booby_trap_core *__thiscall survarium::booby_trap_core::`vector deleting destructor'(char *this, char a2)
{
  return survarium::booby_trap_core::`vector deleting destructor'((survarium::booby_trap_core *)(this - 52), a2);
}


survarium::booby_trap_core *__thiscall survarium::booby_trap_core::`vector deleting destructor'(char *this, char a2)
{
  return survarium::booby_trap_core::`vector deleting destructor'((survarium::booby_trap_core *)(this - 144), a2);
}
