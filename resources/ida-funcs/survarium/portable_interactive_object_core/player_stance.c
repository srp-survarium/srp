int __usercall survarium::portable_interactive_object_core::player_stance@<eax>(
        survarium::portable_interactive_object_core *this@<ecx>,
        int a2@<esi>)
{
  bool is_moving; // al

  is_moving = survarium::player_input::is_moving((survarium::player_input *)(*(_DWORD *)(a2 + 68) + 744));
  if ( *(_DWORD *)(*(_DWORD *)(a2 + 24) + 32) == 1 )
    return 2 * is_moving + 4;
  else
    return is_moving ? 2 : 0;
}
