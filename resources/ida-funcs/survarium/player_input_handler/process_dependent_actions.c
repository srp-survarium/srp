void __thiscall survarium::player_input_handler::process_dependent_actions(
        survarium::player_input_handler *this,
        const survarium::game_action_id action_id,
        const survarium::action_state_enum action_state,
        int a4)
{
  char **v4; // esi
  survarium::action_state_enum *p_action_state; // ebx
  survarium::game_action_id *v6; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h]

  v4 = (char **)(action_id + 680);
  if ( *(_DWORD *)(action_id + 680) != *(_DWORD *)(action_id + 684) && dependent_actions_count )
  {
    p_action_state = &survarium::dependent_actions[0].action_state;
    v7 = dependent_actions_count;
    do
    {
      if ( *((_DWORD *)p_action_state - 1) == action_state && *p_action_state == a4 )
      {
        v6 = (survarium::game_action_id *)stlp_std::find<vostok::render::render_output_window * *,vostok::render::render_output_window *>(
                                            *v4,
                                            (int *)p_action_state + 1,
                                            *(char **)(action_id + 684));
        if ( v6 != *(survarium::game_action_id **)(action_id + 684) )
          vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::erase(
            (vostok::buffer_vector<enum survarium::game_action_id> *)v4,
            &v6);
      }
      p_action_state += 3;
      --v7;
    }
    while ( v7 );
  }
}
