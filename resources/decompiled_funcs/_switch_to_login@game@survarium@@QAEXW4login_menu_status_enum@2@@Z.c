void __userpurge survarium::game::switch_to_login(
        survarium::game *this@<ecx>,
        int a2@<esi>,
        survarium::login_menu_status_enum status)
{
  void (__thiscall ***v3)(_DWORD); // edi
  void (__thiscall ***v4)(_DWORD); // ecx

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 952) + 20))(*(_DWORD *)(a2 + 952)) )
  {
    survarium::login_menu::set_status(*(survarium::login_menu **)(a2 + 888), status);
    v3 = *(void (__thiscall ****)(_DWORD))(a2 + 888);
    v4 = *(void (__thiscall ****)(_DWORD))(a2 + 940);
    if ( v4 != v3 )
    {
      if ( v4 )
        (*v4)[1](v4);
      *(_DWORD *)(a2 + 940) = v3;
      (**v3)(v3);
    }
  }
}
