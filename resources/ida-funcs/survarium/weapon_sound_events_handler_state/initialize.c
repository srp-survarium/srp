void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::double_barreled_weapon_core_fire_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::pistol_weapon_core_fire_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_reload_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::double_barreled_weapon_core_reload_state::initialize((survarium::weapon_core_reload_state *)this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_chamber_a_round_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_fire_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_hide_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_hide_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *)&this->gap138 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::double_barreled_weapon_core_reload_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::pistol_weapon_core_fire_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *)&this->gap140 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_shotgun_reload_finish_substate::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_one_round_substate>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *)&this->m_owner_ready_for_transition);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_shotgun_reload_one_round_substate::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_one_round_substate>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *)&this->m_sound_effect);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_shotgun_reload_start_substate::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_one_round_substate>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *)&this->m_animation_ended);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state>::initialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *this)
{
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v2; // ecx
  survarium::weapon_core *v3; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > v5; // [esp-8h] [ebp-38h]
  int v6; // [esp+0h] [ebp-30h]
  int v7[8]; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_show_state::initialize(this);
  this->m_sound_effect.m_sounds_counter = -1;
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *)&this->gap138 + 1);
  v5.l_.a1_.t_ = &this->m_sound_effect;
  v5.f_.f_ = survarium::weapon_sound_effect::on_sound_event;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    v2,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_sound_effect *>,boost::arg<1> > > *)v7,
    v5,
    v6);
  survarium::weapon_core::set_animation_callback(
    v3,
    (const char *)this->m_weapon,
    "sound_events",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)&this->m_sound_effect,
    (const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)v7);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v4, v7);
}
