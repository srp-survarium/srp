void __usercall survarium::game::switch_to_lobby(survarium::game *this@<ecx>, int a2@<edi>)
{
  void (__thiscall ***v2)(_DWORD); // ecx
  void (__thiscall ***v3)(_DWORD); // esi

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 952) + 20))(*(_DWORD *)(a2 + 952)) )
  {
    v2 = *(void (__thiscall ****)(_DWORD))(a2 + 940);
    v3 = *(void (__thiscall ****)(_DWORD))(a2 + 884);
    if ( v2 != v3 )
    {
      if ( v2 )
        (*v2)[1](v2);
      *(_DWORD *)(a2 + 940) = v3;
      (**v3)(v3);
    }
  }
}
