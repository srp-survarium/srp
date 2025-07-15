void __thiscall vostok::ai::sensors::vision_sensor::~vision_sensor(vostok::ai::sensors::vision_sensor *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax
  survarium::game_camera *v3; // ecx
  vostok::ai::sensed_visual_object *visual_object; // [esp+30h] [ebp-4h] BYREF

  this->__vftable = (vostok::ai::sensors::vision_sensor_vtbl *)&vostok::ai::sensors::vision_sensor::`vftable';
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_world->m_destruction_subscriptions_manager,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_subscription);
  while ( 1 )
  {
    visual_object = vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::pop_front(&this->m_visible_objects);
    if ( !visual_object )
      break;
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::game_material,vostok::memory::detail::call_destructor_predicate>(
      v2,
      (survarium::game_camera **)&visual_object);
  }
  boost::function1<void,vostok::ai::game_object const &>::clear(&this->m_subscription.m_subscription_callback.boost::function1<void,vostok::ai::game_object const &>);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_subscription);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
