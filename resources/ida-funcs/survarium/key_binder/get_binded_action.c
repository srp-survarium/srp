survarium::game_action_id __userpurge survarium::key_binder::get_binded_action@<eax>(
        survarium::key_binder *this@<eax>,
        int _dik@<esi>,
        survarium::toggle_action_enum *actions_mask_type@<edx>,
        int key_group_mask)
{
  int v4; // edi
  survarium::keyboard_key_descr **i; // eax
  int v6; // ecx
  int v7; // ecx
  survarium::game_action_id result; // eax
  int v9; // eax
  survarium::toggle_action_enum v10; // ecx

  v4 = 0;
  for ( i = &this->m_key_bindings[0].m_keyboard[1]; ; i += 3 )
  {
    v6 = (int)*(i - 2);
    if ( v6 && (key_group_mask & *(_DWORD *)(v6 + 8)) != 0 )
    {
      v7 = (int)*(i - 1);
      if ( v7 )
      {
        if ( *(_DWORD *)(v7 + 4) == _dik )
          break;
      }
      if ( *i && (*i)->dik == _dik )
        break;
    }
    if ( ++v4 >= 72 )
      return 73;
  }
  v9 = (int)*(i - 2);
  v10 = *(_DWORD *)(v9 + 12);
  result = *(_DWORD *)(v9 + 4);
  *actions_mask_type = v10;
  return result;
}
