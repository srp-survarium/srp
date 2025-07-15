char __thiscall survarium::game_world::on_keyboard_action(
        survarium::game_world *this,
        vostok::input::world *input_world,
        int key,
        vostok::input::enum_keyboard_action action)
{
  vostok::input::keyboard *v5; // eax
  survarium::flash_value *v6; // ecx
  char v7; // bl
  int v9; // edi
  survarium::chat_handler *v10; // ecx
  bool value[4]; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-18h] BYREF

  v5 = input_world->get_keyboard(input_world);
  v7 = v5->is_key_down(v5, key_tab);
  value[0] = v7;
  if ( BYTE2(this->m_scheduler.m_inactive_objects._M_impl._M_end_of_storage.m_allocator) != v7 )
  {
    pargs.pObjectInterface = 0;
    pargs.Type = VT_Undefined;
    survarium::flash_value::SetBoolean(v6, (int)&pargs, value[0]);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(LODWORD(this->m_inverted_view_matrix.i.x) + 264) + 4),
      "root.show_player_list",
      0,
      &pargs,
      1u);
    BYTE2(this->m_scheduler.m_inactive_objects._M_impl._M_end_of_storage.m_allocator) = v7;
    Scaleform::GFx::Value::~Value(&pargs);
  }
  if ( v7 || action != kb_key_down )
    return 0;
  v9 = *(_DWORD *)&this[-1].m_third_person_game_effect_presenters[10908];
  if ( survarium::key_binder::get_binded_action(
         *(survarium::key_binder **)(v9 + 144),
         key,
         (survarium::toggle_action_enum *)value,
         1) == kCHAT
    || key == 28
    || key == 156 )
  {
    survarium::chat_handler::focus(v10, *(_DWORD *)(v9 + 13848), 1);
    return 1;
  }
  if ( key != 38 )
  {
    if ( key == 1 )
    {
      survarium::game::activate_main_menu((survarium::game *)v10, v9);
      return 1;
    }
    return 0;
  }
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v9 + 13912) + 44))(*(_DWORD *)(v9 + 13912));
  return 1;
}
