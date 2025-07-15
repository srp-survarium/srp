char __thiscall survarium::game_world::on_keyboard_action(
        survarium::game_world *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  const vostok::input::keyboard *v5; // eax
  survarium::game *v6; // ecx
  int m_current_satisfaction_update_tick_high; // edi
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  survarium::game_world_ui *btab; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::Value pargs; // [esp+14h] [ebp-18h] BYREF

  v5 = input_world->get_keyboard(input_world);
  LOBYTE(btab) = v5->is_key_down(v5, key_tab);
  survarium::game_world_ui::show_players_list(btab, (int)&this->m_render_scene, (char)btab);
  if ( action == kb_key_down )
  {
    btab = (survarium::game_world_ui *)survarium::key_binder::get_binded_action(
                                         (survarium::key_binder *)LODWORD(this[-1].m_next_delay_delete->m_last_fail_of_increasing_quality),
                                         key,
                                         1,
                                         (survarium::toggle_action_enum *)&btab);
    if ( btab == (survarium::game_world_ui *)55 || key == key_return || key == key_numpadenter )
    {
      m_current_satisfaction_update_tick_high = HIDWORD(this[-1].m_next_delay_delete[3].m_current_satisfaction_update_tick);
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)(m_current_satisfaction_update_tick_high
                                                                               + 24)
                                                                   + 952)
                                                     + 20))(*(_DWORD *)(*(_DWORD *)(m_current_satisfaction_update_tick_high
                                                                                  + 24)
                                                                      + 952)) )
      {
        if ( *(_BYTE *)(m_current_satisfaction_update_tick_high + 20) != 1 )
        {
          if ( *(_BYTE *)(m_current_satisfaction_update_tick_high + 22) )
          {
            v8 = *(_DWORD *)(m_current_satisfaction_update_tick_high + 28);
            pargs.pObjectInterface = 0;
            pargs.Type = VT_Boolean;
            pargs.mValue.BValue = 1;
            Scaleform::GFx::Movie::Invoke(
              *(Scaleform::GFx::Movie **)(*(_DWORD *)(v8 + 264) + 4),
              "root.focus_chat",
              0,
              &pargs,
              1u);
            if ( (pargs.Type & 0x40) != 0 )
              pargs.pObjectInterface->ObjectRelease(pargs.pObjectInterface, &pargs, (void *)pargs.mValue.IValue);
          }
          v9 = *(_DWORD *)(m_current_satisfaction_update_tick_high + 24);
          *(_BYTE *)(m_current_satisfaction_update_tick_high + 20) = 1;
          v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 40))(v9);
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 16))(v10, m_current_satisfaction_update_tick_high);
        }
      }
    }
    switch ( key )
    {
      case key_k:
        (*(void (__thiscall **)(vostok::vfs::vfs_hashset *))(*(_DWORD *)this[-1].m_next_delay_delete[3].m_fat_it.m_hashset
                                                           + 40))(this[-1].m_next_delay_delete[3].m_fat_it.m_hashset);
        return 1;
      case key_l:
        (*(void (__thiscall **)(vostok::vfs::vfs_hashset *))(*(_DWORD *)this[-1].m_next_delay_delete[3].m_fat_it.m_hashset
                                                           + 44))(this[-1].m_next_delay_delete[3].m_fat_it.m_hashset);
        return 1;
      case key_escape:
        survarium::game::activate_main_menu(v6, (int)this[-1].m_next_delay_delete);
        return 1;
    }
    if ( btab == (survarium::game_world_ui *)16 )
      survarium::game_world::switch_to_player_camera(
        (survarium::game_world *)v6,
        (int)&this[-1].m_parent_resources.vostok::threading::simple_lock,
        1);
  }
  return 0;
}
