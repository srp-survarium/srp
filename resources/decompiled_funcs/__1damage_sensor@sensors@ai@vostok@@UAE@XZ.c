void __thiscall vostok::ai::sensors::damage_sensor::~damage_sensor(vostok::ai::sensors::damage_sensor *this)
{
  this->__vftable = (vostok::ai::sensors::damage_sensor_vtbl *)&vostok::ai::sensors::damage_sensor::`vftable';
  vostok::ai::npc_subscriptions_manager<vostok::ai::sensors::sound_subscriber,vostok::ai::sensed_sound_object>::unsubscribe(
    &this->m_world->m_damage_subscriptions_manager,
    this->m_npc,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_subscription);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->m_subscription);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_subscription);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next);
}
