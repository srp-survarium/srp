void __userpurge survarium::weapon::set_ui_ammo(survarium::weapon *this@<ecx>, int a2@<eax>, bool update_total_count)
{
  survarium::game_world_ui *v4; // edx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  vostok::resources::unmanaged_resource *v9; // edi
  unsigned int v10; // ecx
  unsigned int v11; // eax

  v4 = *(survarium::game_world_ui **)(a2 + 4024);
  if ( v4 )
  {
    if ( *(_DWORD *)(a2 + 268) )
    {
      survarium::game_world_ui::set_ammo_in_magazine(
        v4,
        (unsigned __int16)(*(_WORD *)(a2 + 1146) + (*(_BYTE *)(a2 + 1166) != 0)));
      if ( update_total_count )
      {
        v5 = *(_DWORD *)(a2 + 268);
        v6 = *(_DWORD *)(v5 + 4 * survarium::weapon_core::get_ammo_slot((survarium::weapon_core *)a2, first_ammo) + 264);
        v7 = 0;
        if ( v6 )
        {
          v7 = v6;
          _InterlockedExchangeAdd((volatile signed __int32 *)(v6 + 208), 1u);
        }
        v8 = *(_DWORD *)(v5 + 4 * survarium::weapon_core::get_ammo_slot((survarium::weapon_core *)a2, second_ammo) + 264);
        v9 = 0;
        if ( v8 )
        {
          v9 = (vostok::resources::unmanaged_resource *)v8;
          _InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 208), 1u);
          v10 = *(unsigned __int16 *)(v8 + 276);
        }
        else
        {
          v10 = 0;
        }
        if ( v7 )
          v11 = *(unsigned __int16 *)(v7 + 276);
        else
          v11 = 0;
        survarium::game_world_ui::set_ammo_total_count(*(survarium::game_world_ui **)(a2 + 4024), v11, v10);
        if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
        if ( v7 )
        {
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              (vostok::resources::unmanaged_intrusive_base *)(v7 + 208),
              (vostok::resources::unmanaged_resource *)v7);
        }
      }
    }
  }
}
