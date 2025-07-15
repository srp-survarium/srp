void __thiscall vostok::ai::sensors::damage_sensor::damage_sensor(
        vostok::ai::sensors::damage_sensor *this,
        vostok::ai::npc *npc,
        vostok::ai::ai_world *world,
        vostok::ai::brain_unit *brain)
{
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *v4; // eax
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v7; // [esp+A4h] [ebp-58h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+C4h] [ebp-38h] BYREF
  void (__thiscall *f)(vostok::ai::sensors::damage_sensor *, const vostok::ai::sensed_hit_object *); // [esp+D4h] [ebp-28h]
  int f_4; // [esp+D8h] [ebp-24h]
  boost::function1<void,enum vostok::handshaking_error_types_enum> v11; // [esp+DCh] [ebp-20h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_npc = npc;
  this->m_world = world;
  this->m_brain_unit = brain;
  this->m_enabled = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)world) != 0
                  ? -51
                  : -3;
  this->__vftable = (vostok::ai::sensors::damage_sensor_vtbl *)&vostok::ai::sensors::damage_sensor::`vftable';
  f = vostok::ai::sensors::damage_sensor::on_perceive_hit;
  f_4 = 0;
  v4 = boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
         (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::sensors::damage_sensor::on_perceive_hit,
         (survarium::weapon_core_animation_end_aware_state *)this);
  v7 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)v4;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)HIDWORD(v4->f_.f_),
    &v11);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::ai::sensed_hit_object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::ai::sensors::damage_sensor,vostok::ai::sensed_hit_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::sensors::damage_sensor *>,boost::arg<1>>>>'::`2'::stored_vtable,
         v7,
         &v11.functor) )
  {
    v11.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::ai::sensed_hit_object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::cmf1<void,vostok::ai::sensors::damage_sensor,vostok::ai::sensed_hit_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::sensors::damage_sensor *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                        + 1);
  }
  else
  {
    v11.vtable = 0;
  }
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_subscription);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v5,
    &this->m_subscription.m_subscription_callback.vtable);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&this->m_subscription,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
  this->m_subscription.m_next = 0;
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v11);
  vostok::ai::damage_sensor_parameters::damage_sensor_parameters(&this->m_parameters);
  vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object>::subscribe(
    &this->m_world->m_damage_subscriptions_manager,
    this->m_npc,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_subscription);
}
