void __thiscall survarium::short_jump_landing_state::initialize(survarium::short_jump_landing_state *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_user_animations_selector *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_landing_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_landing_state *>,boost::arg<1> > > v5; // [esp-8h] [ebp-30h]
  int v6; // [esp+0h] [ebp-28h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v7; // [esp+8h] [ebp-20h] BYREF

  survarium::base_player::end_jump((survarium::base_player *)this, (int)this->m_jump_logic->m_user);
  v5.l_.a1_.t_ = this;
  v5.f_.f_ = survarium::short_jump_landing_state::on_landing_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::short_jump_landing_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::short_jump_landing_state *>,boost::arg<1> > > *)&v7,
    v5,
    v6);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v3,
    (const char *)this->m_jump_logic->m_owner,
    this,
    &v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v7);
  this->m_is_jump_finished = 0;
}
