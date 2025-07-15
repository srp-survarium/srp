void __userpurge survarium::game_world_ui::disactivate_quick_slot(
        survarium::game_world_ui *this@<ecx>,
        int a2@<edi>,
        survarium::profile_slot_enum slot)
{
  _DWORD *v3; // edx
  _DWORD *v4; // ebx
  _DWORD *v5; // esi
  _DWORD *v6; // ecx
  int v7; // ecx
  _DWORD *i; // eax

  v3 = *(_DWORD **)(a2 + 52);
  v4 = *(_DWORD **)(a2 + 56);
  if ( v3 != v4 )
  {
    v5 = v3 + 1;
    do
    {
      if ( *v3 == slot )
      {
        v6 = *(_DWORD **)(a2 + 56);
        if ( v5 != v6 )
        {
          v7 = v6 - v5;
          for ( i = v3; v7 > 0; ++i )
          {
            *i = i[1];
            --v7;
          }
        }
        *(_DWORD *)(a2 + 56) -= 4;
      }
      ++v3;
      ++v5;
    }
    while ( v3 != v4 );
  }
}
