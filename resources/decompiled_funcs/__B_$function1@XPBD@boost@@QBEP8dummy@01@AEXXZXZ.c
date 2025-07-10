void (__thiscall *__usercall boost::function1<void,char const *>::operator void (__thiscall boost::function1<void,char const *>::dummy::*)(void)@<eax>(
        boost::function1<void,char const *> *this@<ecx>,
        _DWORD *a2@<eax>))(boost::function1<void,char const *>::dummy *this)
{
  return *a2 != 0
       ? (void (__thiscall *)(boost::function1<void,char const *>::dummy *))survarium::weapon_user_dead_state::finalize
       : 0;
}
