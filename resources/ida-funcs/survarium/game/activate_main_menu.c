void __usercall survarium::game::activate_main_menu(survarium::game *this@<ecx>, int a2@<edi>)
{
  survarium::game_options *v2; // ecx

  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 13900) + 32))(*(_DWORD *)(a2 + 13900), 0);
  survarium::game_options::activate(v2, a2 + 15072, *(survarium::base_game_scene **)(a2 + 13900));
}
