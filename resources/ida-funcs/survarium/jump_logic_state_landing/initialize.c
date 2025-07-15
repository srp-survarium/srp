void __thiscall survarium::jump_logic_state_landing::initialize(survarium::jump_logic_state_landing *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_user_animations_selector *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  survarium::jump_logic *m_jump_logic; // edi
  int move_direction; // eax
  int m_jump_type; // ecx
  char v8; // al
  bool v9; // zf
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > v10; // [esp-8h] [ebp-30h]
  int v11; // [esp+0h] [ebp-28h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v12; // [esp+8h] [ebp-20h] BYREF

  survarium::base_player::end_jump((survarium::base_player *)this, (int)this->m_jump_logic->m_user);
  v10.l_.a1_.t_ = this;
  v10.f_.f_ = survarium::jump_logic_state_landing::on_interval_end;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > *)&v12,
    v10,
    v11);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v3,
    (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)2,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v12);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v12);
  this->m_is_jump_finished = 0;
  m_jump_logic = this->m_jump_logic;
  move_direction = survarium::get_move_direction(&m_jump_logic->m_user->m_input);
  m_jump_type = m_jump_logic->m_jump_type;
  if ( m_jump_type == 1 )
    goto LABEL_6;
  if ( m_jump_type == 2 )
  {
LABEL_14:
    if ( move_direction != 1 && move_direction != 8 )
    {
      v9 = move_direction == 2;
LABEL_17:
      if ( !v9 )
        goto LABEL_6;
      goto LABEL_18;
    }
    goto LABEL_18;
  }
  if ( m_jump_type != 3 )
  {
    if ( m_jump_type == 4 )
    {
      if ( move_direction != 8 && move_direction != 7 )
      {
        v9 = move_direction == 1;
        goto LABEL_17;
      }
      goto LABEL_18;
    }
    if ( m_jump_type > 7 )
      goto LABEL_6;
    goto LABEL_14;
  }
  if ( move_direction != 2 && move_direction != 1 )
  {
    v9 = move_direction == 3;
    goto LABEL_17;
  }
LABEL_18:
  if ( m_jump_type == 5 || m_jump_type == 7 || m_jump_type == 6 )
  {
    v8 = 1;
    goto LABEL_7;
  }
LABEL_6:
  v8 = 0;
LABEL_7:
  m_jump_logic->m_owner_state->m_is_sprinting = v8;
}
