void __thiscall vostok::ai::perceptors::pickup_item_perceptor::pickup_item_perceptor(
        vostok::ai::perceptors::pickup_item_perceptor *this,
        vostok::ai::npc *npc,
        vostok::ai::brain_unit *brain,
        vostok::ai::working_memory *memory)
{
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v4; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v6; // [esp+10h] [ebp-64h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+3Ch] [ebp-38h] BYREF
  survarium::usable_object *(__thiscall *f)(survarium::collision_geometry_subscriber *); // [esp+4Ch] [ebp-28h]
  int f_4; // [esp+50h] [ebp-24h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> v10; // [esp+54h] [ebp-20h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_npc = npc;
  this->m_brain_unit = brain;
  this->m_working_memory = memory;
  this->__vftable = (vostok::ai::perceptors::pickup_item_perceptor_vtbl *)&vostok::ai::perceptors::pickup_item_perceptor::`vftable';
  f =  __thiscall vostok::ai::perceptors::enemy_perceptor::`vcall'{4,{flat}};
  f_4 = 0;
  v6 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int) __thiscall vostok::ai::perceptors::enemy_perceptor::`vcall'{4,{flat}},
          (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v6.l_.a1_.t_,
    &v10);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::ai::sensors::sensed_object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::perceptors::pickup_item_perceptor,vostok::ai::sensors::sensed_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::perceptors::pickup_item_perceptor *>,boost::arg<1>>>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > >)v6,
         &v10.functor) )
  {
    v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::ai::sensors::sensed_object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::perceptors::pickup_item_perceptor,vostok::ai::sensors::sensed_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::perceptors::pickup_item_perceptor *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                        + 1);
  }
  else
  {
    v10.vtable = 0;
  }
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_subscription);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v4,
    &this->m_subscription.m_subscription_callback.vtable);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&this->m_subscription,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
  this->m_subscription.m_next = 0;
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v10);
  vostok::ai::brain_unit::subscribe_on_sensors_events(this->m_brain_unit, &this->m_subscription);
}
