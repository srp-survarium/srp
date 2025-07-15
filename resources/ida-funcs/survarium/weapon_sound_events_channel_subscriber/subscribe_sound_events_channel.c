void __usercall survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
        survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *this@<ecx>,
        void *a2@<edi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,enum vostok::animation::callback_return_type_enum (__cdecl*)(vostok::animation::animation_callback_params &),boost::_bi::list1<boost::arg<1> > > v3; // [esp-8h] [ebp-38h]
  int v4; // [esp+0h] [ebp-30h]
  const void *v5; // [esp+0h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+8h] [ebp-28h] BYREF
  int v7; // [esp+Ch] [ebp-24h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> callback; // [esp+10h] [ebp-20h] BYREF

  animation.m_object = 0;
  *(_DWORD *)&v3.l_.boost::_bi::storage1<boost::arg<1> > = v7;
  v3.f_ = (vostok::animation::callback_return_type_enum (__cdecl *)(vostok::animation::animation_callback_params *))survarium::player_respawn_rule::priority;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,enum vostok::animation::callback_return_type_enum (__cdecl*)(vostok::animation::animation_callback_params &),boost::_bi::list1<boost::arg<1> > > *)&callback,
    v3,
    v4);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&callback,
    "sound_events",
    &callback,
    a2,
    &animation,
    0,
    v5);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&callback);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
}


void __usercall survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::subscribe_sound_events_channel(
        survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *this@<ecx>,
        void *a2@<edi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,enum vostok::animation::callback_return_type_enum (__cdecl*)(vostok::animation::animation_callback_params &),boost::_bi::list1<boost::arg<1> > > v3; // [esp-8h] [ebp-38h]
  int v4; // [esp+0h] [ebp-30h]
  const void *v5; // [esp+0h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+8h] [ebp-28h] BYREF
  int v7; // [esp+Ch] [ebp-24h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> callback; // [esp+10h] [ebp-20h] BYREF

  animation.m_object = 0;
  *(_DWORD *)&v3.l_.boost::_bi::storage1<boost::arg<1> > = v7;
  v3.f_ = (vostok::animation::callback_return_type_enum (__cdecl *)(vostok::animation::animation_callback_params *))survarium::player_respawn_rule::priority;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,enum vostok::animation::callback_return_type_enum (__cdecl*)(vostok::animation::animation_callback_params &),boost::_bi::list1<boost::arg<1> > > *)&callback,
    v3,
    v4);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&callback,
    "sound_events",
    &callback,
    a2,
    &animation,
    0,
    v5);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&callback);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
}


void __usercall survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate>::subscribe_sound_events_channel(
        survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *this@<ecx>,
        void *a2@<edi>)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,enum vostok::animation::callback_return_type_enum (__cdecl*)(vostok::animation::animation_callback_params &),boost::_bi::list1<boost::arg<1> > > v3; // [esp-8h] [ebp-38h]
  int v4; // [esp+0h] [ebp-30h]
  const void *v5; // [esp+0h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> animation; // [esp+8h] [ebp-28h] BYREF
  int v7; // [esp+Ch] [ebp-24h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> callback; // [esp+10h] [ebp-20h] BYREF

  animation.m_object = 0;
  *(_DWORD *)&v3.l_.boost::_bi::storage1<boost::arg<1> > = v7;
  v3.f_ = (vostok::animation::callback_return_type_enum (__cdecl *)(vostok::animation::animation_callback_params *))survarium::player_respawn_rule::priority;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,enum vostok::animation::callback_return_type_enum (__cdecl*)(vostok::animation::animation_callback_params &),boost::_bi::list1<boost::arg<1> > > *)&callback,
    v3,
    v4);
  survarium::base_player::subscribe_animation_player(
    (survarium::base_player *)&callback,
    "sound_events",
    &callback,
    a2,
    &animation,
    0,
    v5);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&callback);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&animation);
}
