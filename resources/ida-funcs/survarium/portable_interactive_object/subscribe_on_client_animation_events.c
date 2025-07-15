void __thiscall survarium::portable_interactive_object::subscribe_on_client_animation_events(
        survarium::portable_interactive_object *this)
{
  survarium::base_player *m_user; // ebx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *v4; // eax
  survarium::base_player *v5; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::player_equipment_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::player_equipment_sound_effect *>,boost::arg<1> > > v6; // [esp-8h] [ebp-38h]
  const void *v7; // [esp+0h] [ebp-30h]
  const void *v8; // [esp+0h] [ebp-30h]
  int __formal; // [esp+Ch] [ebp-24h] BYREF
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> v10; // [esp+10h] [ebp-20h] BYREF

  m_user = this->m_user;
  __formal = 0;
  if ( *((_BYTE *)&loc_1143B + (_DWORD)m_user) )
  {
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
      &v10);
    survarium::base_player::subscribe_animation_player(
      v5,
      "player_sound_events",
      v4,
      this,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&__formal,
      0,
      v7);
  }
  else
  {
    v6.l_.a1_.t_ = &this->m_player_equipment_sound_effect;
    v6.f_.f_ = (vostok::animation::callback_return_type_enum (__thiscall *)(survarium::player_equipment_sound_effect *, vostok::animation::animation_callback_params *))survarium::player_equipment_sound_effect::on_player_sound_event;
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)survarium::player_equipment_sound_effect::on_player_sound_event,
      (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::player_equipment_sound_effect,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::player_equipment_sound_effect *>,boost::arg<1> > > *)&v10,
      v6,
      (int)v7);
    survarium::base_player::subscribe_animation_player(
      (survarium::base_player *)&v10,
      "player_sound_events",
      &v10,
      this,
      (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&__formal,
      (unsigned __int8)this->m_user,
      v8);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v10);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&__formal);
}
