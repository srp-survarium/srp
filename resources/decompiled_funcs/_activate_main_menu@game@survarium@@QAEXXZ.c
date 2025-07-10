void __usercall survarium::game::activate_main_menu(survarium::game *this@<ecx>, int a2@<eax>)
{
  survarium::game_options *v3; // ecx

  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 940) + 20))(*(_DWORD *)(a2 + 940), 0);
  survarium::game_options::activate(v3, *(survarium::base_game_scene **)(a2 + 940));
}
