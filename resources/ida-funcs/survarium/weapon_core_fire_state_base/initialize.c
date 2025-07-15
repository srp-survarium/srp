void __thiscall survarium::weapon_core_fire_state_base::initialize(survarium::weapon_core_fire_state_base *this)
{
  survarium::weapon_core *v2; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  survarium::weapon_core *m_weapon; // eax
  unsigned __int16 m_bullets_in_queue; // cx
  bool v6; // al
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_fire_state_base,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_fire_state_base *>,boost::arg<1> > > v7; // [esp-14h] [ebp-44h]
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> f; // [esp+10h] [ebp-20h] BYREF

  survarium::weapon_core_animation_end_aware_state::initialize(this);
  f.functor.obj_ptr = this;
  f.vtable = (boost::detail::function::vtable_base *) __thiscall survarium::weapon_core_fire_state_base::`vcall'{40,{flat}};
  (&f.vtable)[1] = 0;
  HIDWORD(v7.f_.f_) =  __thiscall survarium::weapon_core_fire_state_base::`vcall'{40,{flat}};
  *(_QWORD *)&v7.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v7.f_.f_) = &f;
  boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
    0,
    v7,
    (int)f.functor.vostok_pointer_size_alignment[1]);
  survarium::weapon_core::set_animation_callback(
    v2,
    (const char *)this->m_weapon,
    "shoot",
    (boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *)this,
    &f);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v3, (int *)&f);
  m_weapon = this->m_weapon;
  v6 = 0;
  if ( m_weapon->m_weapon_fire_queue_types[m_weapon->m_fire_queue_type] != 0xFF )
  {
    m_bullets_in_queue = m_weapon->m_bullets_in_queue;
    if ( m_bullets_in_queue )
    {
      if ( m_bullets_in_queue < m_weapon->m_weapon_fire_queue_types[m_weapon->m_fire_queue_type] )
        v6 = 1;
    }
  }
  this->m_keep_shooting = v6;
}
