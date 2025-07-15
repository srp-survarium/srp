bool __thiscall survarium::free_fly_camera::on_keyboard_action(
        survarium::free_fly_camera *this,
        vostok::input::world *input_world,
        int key,
        vostok::input::enum_keyboard_action action)
{
  survarium::game *v4; // edi
  survarium::game_action_id binded_action; // eax
  survarium::game *v6; // ecx
  __int32 v7; // eax
  __int32 v8; // eax
  int v9; // eax
  const int *v11; // [esp+0h] [ebp-10h]
  survarium::toggle_action_enum actions_mask_type; // [esp+Ch] [ebp-4h] BYREF

  v4 = (survarium::game *)this[-1].m_mouse_events._M_impl._M_end_of_storage._M_data[40];
  binded_action = survarium::key_binder::get_binded_action(v4->m_key_binder, key, &actions_mask_type, 1);
  if ( action == kb_key_down )
  {
    v7 = binded_action - 51;
    if ( v7 )
    {
      v8 = v7 - 3;
      if ( v8 )
      {
        if ( v8 == 1 )
          vostok::console_commands::execute("deserialize_player_state", execution_filter_all, 1u);
      }
      else
      {
        vostok::console_commands::execute("serialize_player_state", execution_filter_all, 1u);
      }
    }
    else
    {
      survarium::game::toggle_pause(v6, v4);
    }
    if ( actions_mask_type == toggle_action )
    {
      v9 = key;
LABEL_14:
      actions_mask_type = v9;
      stlp_std::vector<int,survarium::std_allocator<int>>::push_back(
        (stlp_std::vector<int,survarium::std_allocator<int> > *)&actions_mask_type,
        v11);
    }
  }
  else if ( action == kb_key_hold && actions_mask_type == hold_action )
  {
    v9 = key;
    goto LABEL_14;
  }
  return 0;
}
