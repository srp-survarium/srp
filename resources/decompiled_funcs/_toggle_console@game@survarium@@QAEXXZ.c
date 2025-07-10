void __usercall survarium::game::toggle_console(survarium::game *this@<ecx>, int a2@<esi>)
{
  bool v2; // zf
  int v3; // eax

  v2 = (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 112) + 32))(*(_DWORD *)(a2 + 112)) == 0;
  v3 = **(_DWORD **)(a2 + 112);
  if ( v2 )
    (*(void (**)(void))(v3 + 36))();
  else
    (*(void (**)(void))(v3 + 40))();
}
