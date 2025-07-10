void __thiscall survarium::artefact_lifebone_core::artefact_lifebone_core(survarium::artefact_lifebone_core *this)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v2; // [esp+4h] [ebp-F0h]
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *p_reduce_damage_functor; // [esp+14h] [ebp-E0h]
  boost::function4<float,char const *,char const *,float,float> v4; // [esp+38h] [ebp-BCh] BYREF
  boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2> > > v5; // [esp+58h] [ebp-9Ch]
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *other; // [esp+68h] [ebp-8Ch]
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> v7; // [esp+8Ch] [ebp-68h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v8; // [esp+BCh] [ebp-38h] BYREF
  int (__thiscall *v9)(void *); // [esp+CCh] [ebp-28h]
  int v10; // [esp+D0h] [ebp-24h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+D4h] [ebp-20h] BYREF
  bool (__thiscall *f)(survarium::artefact_lifebone_core *, const char *, survarium::hit_affects_type_enum); // [esp+E8h] [ebp-Ch]
  int f_4; // [esp+ECh] [ebp-8h]
  unsigned int i; // [esp+F0h] [ebp-4h]

  survarium::inventory_item::inventory_item(this, use_silent);
  this->survarium::artefact_base::survarium::inventory_item::survarium::interactive_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact_lifebone_core_vtbl *)&survarium::artefact_base::`vftable';
  survarium::damage_protector::damage_protector(&this->survarium::damage_protector);
  this->survarium::artefact_base::survarium::inventory_item::survarium::interactive_object::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::artefact_lifebone_core_vtbl *)&survarium::artefact_lifebone_core::`vftable'{for `survarium::artefact_base'};
  this->survarium::damage_protector::__vftable = (survarium::damage_protector_vtbl *)&survarium::artefact_lifebone_core::`vftable'{for `survarium::damage_protector'};
  `vector constructor iterator'(
    (char *)this->m_damage_protectors,
    0x50u,
    4,
    (void *(__thiscall *)(void *))survarium::damage_protector::damage_protector);
  this->m_unlimited = 1;
  this->m_passive_mode = 0;
  this->m_cooldown_ms = 0;
  this->m_last_used_time_ms = 0;
  for ( i = 0; i < 4; ++i )
  {
    f = survarium::artefact_lifebone_core::protect_affect;
    f_4 = 0;
    v5 = *(boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)survarium::artefact_lifebone_core::protect_affect, (survarium::weapon_core_animation_end_aware_state *)this);
    other = &this->m_damage_protectors[i].protect_affect_functor;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
      &v7);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
      &v7,
      v5);
    boost::function1<unsigned int,char const *>::swap(&v7, other);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v7);
    v9 =  __thiscall survarium::artefact_lifebone_core::`vcall'{120,{flat}};
    v10 = 0;
    v2 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
            (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v8,
            (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int) __thiscall survarium::artefact_lifebone_core::`vcall'{120,{flat}},
            (survarium::weapon_core_animation_end_aware_state *)this);
    p_reduce_damage_functor = (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&this->m_damage_protectors[i].reduce_damage_functor;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
      &v4);
    boost::function4<float,char const *,char const *,float,float>::assign_to<boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::artefact_lifebone_core,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4>>>>(
      &v4,
      (boost::_bi::bind_t<float,boost::_mfi::mf4<float,survarium::artefact_lifebone_core,char const *,char const *,float,float>,boost::_bi::list5<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>,boost::arg<3>,boost::arg<4> > >)v2);
    boost::function1<unsigned int,char const *>::swap(
      (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v4,
      p_reduce_damage_functor);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear(&v4);
  }
}
