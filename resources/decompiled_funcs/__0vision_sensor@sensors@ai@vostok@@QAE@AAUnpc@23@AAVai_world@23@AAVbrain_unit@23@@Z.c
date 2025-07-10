void __thiscall vostok::ai::sensors::vision_sensor::vision_sensor(
        vostok::ai::sensors::vision_sensor *this,
        vostok::ai::npc *npc,
        vostok::ai::ai_world *world,
        vostok::ai::brain_unit *brain)
{
  survarium::game_camera *v4; // ecx
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *v5; // ecx
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > v7; // [esp+2Ch] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+40h] [ebp-38h] BYREF
  void (__thiscall *f)(vostok::ai::sensors::vision_sensor *, const vostok::ai::game_object *); // [esp+50h] [ebp-28h]
  int f_4; // [esp+54h] [ebp-24h]
  boost::function1<void,vostok::ai::game_object const &> v11; // [esp+58h] [ebp-20h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_next);
  this->m_next = 0;
  this->m_npc = npc;
  this->m_world = world;
  this->m_brain_unit = brain;
  this->__vftable = (vostok::ai::sensors::vision_sensor_vtbl *)&vostok::ai::sensors::vision_sensor::`vftable';
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->m_visible_objects.m_size);
  survarium::weapon_user_dead_state::finalize(v4);
  this->m_visible_objects.m_first = 0;
  this->m_visible_objects.m_last = 0;
  f = vostok::ai::sensors::vision_sensor::on_object_destruction;
  f_4 = 0;
  v7 = *boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>(
          (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::ai::sensors::vision_sensor::on_object_destruction,
          (survarium::weapon_core_animation_end_aware_state *)this);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v7.l_.a1_.t_,
    &v11);
  boost::function1<void,vostok::ai::game_object const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::sensors::vision_sensor,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::sensors::vision_sensor *>,boost::arg<1>>>>(
    &v11,
    (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::sensors::vision_sensor,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::sensors::vision_sensor *>,boost::arg<1> > >)v7);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_subscription);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    v5,
    &this->m_subscription.m_subscription_callback.vtable);
  boost::function0<bool>::assign_to_own(
    (boost::function0<bool> *)&this->m_subscription,
    (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11);
  this->m_subscription.m_next = 0;
  boost::function1<void,vostok::ai::game_object const &>::clear(&v11);
  vostok::ai::vision_sensor_parameters::vision_sensor_parameters(&this->m_parameters);
  this->m_last_tick = vostok::ai::ai_world::get_current_time_in_ms(world);
  vostok::intrusive_list<vostok::ai::game_object_subscriber,vostok::ai::game_object_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back_unique(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_world->m_destruction_subscriptions_manager,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_subscription,
    0);
}
