void __usercall survarium::booby_trap::on_trap_fired_message(survarium::booby_trap *this@<ecx>, int a2@<esi>)
{
  survarium::booby_trap *v2; // ecx

  (*(void (__thiscall **)(int, int))(*(_DWORD *)a2 + 60))(a2, 2);
  survarium::booby_trap::play_fired_effects(v2, a2);
}
