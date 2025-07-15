void __thiscall survarium::weapon_core_shotgun_reload_start_substate::initialize(
        survarium::weapon_core_shotgun_reload_start_substate *this)
{
  survarium::weapon_core *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  survarium::weapon_core *m_weapon; // ecx
  survarium::weapon_core_vtbl *v5; // eax
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_shotgun_reload_start_substate,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_shotgun_reload_start_substate *>,boost::arg<1> > > v6; // [esp-14h] [ebp-44h]
  bool *p_m_animation_ended; // [esp+Ch] [ebp-24h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  p_m_animation_ended = &this->m_animation_ended;
  this->m_animation_ended = 0;
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *)survarium::weapon_core_shotgun_reload_start_substate::on_animation_end;
  (&f.vtable)[1] = 0;
  HIDWORD(v6.f_.f_) = survarium::weapon_core_shotgun_reload_start_substate::on_animation_end;
  *(_QWORD *)&v6.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v6.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v6,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::weapon_core::set_animation_callback(
    v2,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon,
    (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)this,
    &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  m_weapon = this->m_weapon;
  if ( m_weapon->m_chamber_a_round_on_reload && m_weapon->m_is_round_chambered )
  {
    v5 = m_weapon->survarium::interactive_object::__vftable;
    ++m_weapon->m_ammo_in_magazine;
    m_weapon->m_is_round_chambered = 0;
    ((void (*)(void))v5->on_unload_chambered_round)();
  }
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate>::subscribe_sound_events_channel(
    (survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *)m_weapon,
    p_m_animation_ended);
}
