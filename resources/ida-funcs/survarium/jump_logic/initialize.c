void __thiscall survarium::jump_logic::initialize(survarium::jump_logic *this, survarium::jump_logic *a2)
{
  const survarium::player_input *m_user; // esi
  int move_direction; // eax
  survarium::base_player *v4; // ecx
  survarium::player_input *v5; // ecx
  survarium::base_player *v6; // esi
  survarium::base_player *v7; // ecx
  survarium::jump_type_enum v8; // eax
  survarium::player_input *v9; // ecx
  survarium::base_player *v10; // esi
  survarium::base_player *v11; // ecx
  survarium::player_input *v12; // ecx
  survarium::base_player *v13; // esi
  survarium::base_player *v14; // ecx
  int m_jump_type; // eax
  boost::detail::function::vtable_base *m_owner; // eax
  void *v17; // eax
  bool v18; // al

  m_user = (const survarium::player_input *)a2->m_user;
  move_direction = survarium::get_move_direction(m_user + 62);
  a2->m_is_jump_from_right_leg = 1;
  switch ( move_direction )
  {
    case 0:
      a2->m_jump_type = jump_type_on_site;
      break;
    case 1:
      if ( survarium::base_player::is_enough_accelerated_for_long_jump(v4, (int)m_user) )
      {
        v6 = a2->m_user;
        if ( !survarium::player_input::is_sprinting(v5, (int)&v6->m_input)
          || !survarium::base_player::can_sprint(v7, (int)v6) )
        {
          v8 = !s_long_jump_only_in_sprint_value ? jump_type_fwd : jump_type_from_site_fwd;
          goto LABEL_7;
        }
        a2->m_jump_type = jump_type_sprint_fwd;
      }
      else
      {
        a2->m_jump_type = jump_type_from_site_fwd;
      }
      break;
    case 2:
      if ( survarium::base_player::is_enough_accelerated_for_long_jump(v4, (int)m_user) )
      {
        v10 = a2->m_user;
        if ( !survarium::player_input::is_sprinting(v9, (int)&v10->m_input)
          || !survarium::base_player::can_sprint(v11, (int)v10) )
        {
          v8 = !s_long_jump_only_in_sprint_value ? jump_type_fwd_right : jump_type_from_site_fwd_right;
          goto LABEL_7;
        }
        a2->m_jump_type = jump_type_sprint_fwd_right;
      }
      else
      {
        a2->m_jump_type = jump_type_from_site_fwd_right;
      }
      break;
    case 3:
      a2->m_jump_type = jump_type_from_site_right;
      break;
    case 4:
      a2->m_jump_type = jump_type_from_site_back_right;
      break;
    case 5:
      a2->m_jump_type = jump_type_from_site_back;
      break;
    case 6:
      a2->m_jump_type = jump_type_from_site_back_left;
      break;
    case 7:
      a2->m_jump_type = jump_type_from_site_left;
      break;
    case 8:
      if ( survarium::base_player::is_enough_accelerated_for_long_jump(v4, (int)m_user) )
      {
        v13 = a2->m_user;
        if ( survarium::player_input::is_sprinting(v12, (int)&v13->m_input)
          && survarium::base_player::can_sprint(v14, (int)v13) )
        {
          a2->m_jump_type = jump_type_sprint_fwd_left;
        }
        else
        {
          v8 = !s_long_jump_only_in_sprint_value ? jump_type_fwd_left : jump_type_from_site_fwd_left;
LABEL_7:
          a2->m_jump_type = v8;
        }
      }
      else
      {
        a2->m_jump_type = jump_type_from_site_fwd_left;
      }
      break;
  }
  m_jump_type = a2->m_jump_type;
  if ( m_jump_type == 1 || m_jump_type >= 8 )
  {
    vostok::ai::fsm::set_initial_state(&a2->m_logic, &a2->m_short_jump_start, ignore_current_state);
    survarium::jump_logic::initialize_weight_for_on_site_move_animation(a2);
  }
  else
  {
    vostok::ai::fsm::set_initial_state(&a2->m_logic, &a2->m_long_jump_prepare, ignore_current_state);
    m_owner = (boost::detail::function::vtable_base *)a2->m_owner;
    a2->m_move_animation_weight = 0.0;
    a2->m_is_jump_from_right_leg = LOBYTE(m_owner[18].manager) == 0;
  }
  v17 = (void *)a2->m_jump_type;
  v18 = v17 == (void *)5 || v17 == (void *)6 || v17 == (void *)7;
  a2->m_owner_state->m_is_sprinting = v18;
}
