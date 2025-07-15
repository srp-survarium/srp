void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>::deserialize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // ecx
  survarium::weapon_core *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v7; // [esp-8h] [ebp-38h]
  int v8; // [esp+0h] [ebp-30h]
  int v9[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::pistol_weapon_core_fire_state::deserialize(
    (survarium::pistol_weapon_core_fire_state *)this,
    reader,
    client_reader);
  survarium::weapon_sound_effect::deserialize(
    (survarium::weapon_sound_effect *)client_reader,
    (int)&this->m_sound_effect);
  v7.l_.a1_.t_ = &this->m_sound_effect;
  v7.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v9,
    v7,
    v8);
  survarium::weapon_core::set_animation_callback(
    v5,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v9);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>::deserialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // ecx
  survarium::weapon_core *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v7; // [esp-8h] [ebp-38h]
  int v8; // [esp+0h] [ebp-30h]
  int v9[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_animation_end_aware_state::deserialize(this, reader, client_reader);
  survarium::weapon_sound_effect::deserialize(
    (survarium::weapon_sound_effect *)client_reader,
    (int)&this->m_sound_effect);
  v7.l_.a1_.t_ = &this->m_sound_effect;
  v7.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v9,
    v7,
    v8);
  survarium::weapon_core::set_animation_callback(
    v5,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v9);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>::deserialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state> *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // ecx
  survarium::weapon_core *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v7; // [esp-8h] [ebp-38h]
  int v8; // [esp+0h] [ebp-30h]
  int v9[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_fire_state_base::deserialize(this, reader, client_reader);
  survarium::weapon_sound_effect::deserialize(
    (survarium::weapon_sound_effect *)client_reader,
    (int)&this->m_sound_effect);
  v7.l_.a1_.t_ = &this->m_sound_effect;
  v7.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v9,
    v7,
    v8);
  survarium::weapon_core::set_animation_callback(
    v5,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v9);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>::deserialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state> *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // ecx
  survarium::weapon_core *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v7; // [esp-8h] [ebp-38h]
  int v8; // [esp+0h] [ebp-30h]
  int v9[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_hide_state_base::deserialize(this, reader, client_reader);
  survarium::weapon_sound_effect::deserialize(
    (survarium::weapon_sound_effect *)client_reader,
    (int)&this->m_sound_effect);
  v7.l_.a1_.t_ = &this->m_sound_effect;
  v7.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v9,
    v7,
    v8);
  survarium::weapon_core::set_animation_callback(
    v5,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v9);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>::deserialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *this,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::buffer_reader *client_reader)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // ecx
  survarium::weapon_core *v5; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v7; // [esp-8h] [ebp-38h]
  int v8; // [esp+0h] [ebp-30h]
  int v9[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_animation_end_aware_state::deserialize(this, reader, client_reader);
  survarium::weapon_sound_effect::deserialize(
    (survarium::weapon_sound_effect *)client_reader,
    (int)&this->m_sound_effect);
  v7.l_.a1_.t_ = &this->m_sound_effect;
  v7.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v4,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v9,
    v7,
    v8);
  survarium::weapon_core::set_animation_callback(
    v5,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v9);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v6, v9);
}
