survarium::game_action_id __userpurge survarium::key_binder::get_binded_action@<eax>(
        survarium::key_binder *this@<eax>,
        int _dik@<esi>,
        int key_group_mask@<edi>,
        survarium::toggle_action_enum *actions_mask_type)
{
  int v4; // edx
  survarium::keyboard_key_descr **i; // eax
  int v6; // ecx
  int v7; // ecx
  survarium::game_action_id result; // eax
  int v9; // eax
  survarium::toggle_action_enum v10; // ecx
  int v11; // eax
  survarium::toggle_action_enum v12; // edx

  v4 = 0;
  for ( i = &this->m_key_bindings[0].m_keyboard[1]; ; i += 3 )
  {
    v6 = (int)*(i - 2);
    if ( v6 && (key_group_mask & *(_DWORD *)(v6 + 8)) != 0 )
    {
      v7 = (int)*(i - 1);
      if ( v7 && *(_DWORD *)(v7 + 4) == _dik )
      {
        v9 = (int)*(i - 2);
        v10 = *(_DWORD *)(v9 + 12);
        result = *(_DWORD *)(v9 + 4);
        *actions_mask_type = v10;
        return result;
      }
      if ( *i && (*i)->dik == _dik )
        break;
    }
    if ( ++v4 >= 64 )
      return 65;
  }
  v11 = (int)*(i - 2);
  v12 = *(_DWORD *)(v11 + 12);
  result = *(_DWORD *)(v11 + 4);
  *actions_mask_type = v12;
  return result;
}
