void __usercall survarium::game::switch_to_main_menu(survarium::game *this@<ecx>, int a2@<edi>)
{
  void (__thiscall ***v2)(_DWORD); // ecx
  void (__thiscall ***v3)(_DWORD); // esi

  v2 = *(void (__thiscall ****)(_DWORD))(a2 + 940);
  v3 = *(void (__thiscall ****)(_DWORD))(a2 + 880);
  if ( v2 != v3 )
  {
    if ( v2 )
      (*v2)[1](v2);
    *(_DWORD *)(a2 + 940) = v3;
    (**v3)(v3);
  }
}
