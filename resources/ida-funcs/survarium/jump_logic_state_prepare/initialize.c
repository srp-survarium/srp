void __usercall survarium::jump_logic_state_prepare::initialize(
        survarium::jump_logic_state_prepare *this@<ecx>,
        float a2@<xmm0>)
{
  survarium::weapon_user_animations_selector *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  survarium::jump_logic *m_jump_logic; // edi
  survarium::jump_logic *v6; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_prepare,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_prepare *>,boost::arg<1> > > v7; // [esp-8h] [ebp-38h]
  int v8; // [esp+0h] [ebp-30h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v9; // [esp+10h] [ebp-20h] BYREF

  v7.l_.a1_.t_ = this;
  v7.f_.f_ = survarium::jump_logic_state_prepare::on_interval_end;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_prepare,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_prepare *>,boost::arg<1> > > *)&v9,
    v7,
    v8);
  survarium::weapon_user_animations_selector::set_animation_callback(
    v3,
    (vostok::animation::reserved_channel_ids_enum)this->m_jump_logic->m_owner,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)2,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&v9);
  m_jump_logic = this->m_jump_logic;
  this->m_prepare_interval_ended = 0;
  survarium::jump_logic::get_preface_animation_timescale(v6, (int)m_jump_logic);
  this->m_time_scale = a2;
}
