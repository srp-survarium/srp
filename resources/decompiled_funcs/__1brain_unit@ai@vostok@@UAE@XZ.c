void __thiscall vostok::ai::brain_unit::~brain_unit(vostok::ai::brain_unit *this)
{
  vostok::threading::mutex *v1; // ecx
  vostok::threading::mutex *v2; // ecx
  vostok::threading::mutex *v3; // ecx
  vostok::threading::mutex *v4; // ecx
  vostok::threading::mutex *v5; // ecx

  this->__vftable = (vostok::ai::brain_unit_vtbl *)&vostok::ai::brain_unit::`vftable';
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_behaviour);
  vostok::threading::mutex::~mutex(v1, (_RTL_CRITICAL_SECTION *)&this->m_target_selectors.vostok::threading::mutex);
  vostok::threading::mutex::~mutex(v2, (_RTL_CRITICAL_SECTION *)&this->m_perceptors.vostok::threading::mutex);
  vostok::threading::mutex::~mutex(v3, (_RTL_CRITICAL_SECTION *)&this->m_passive_sensors.vostok::threading::mutex);
  vostok::threading::mutex::~mutex(v4, (_RTL_CRITICAL_SECTION *)&this->m_active_sensors.vostok::threading::mutex);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_player);
  vostok::threading::mutex::~mutex(
    v5,
    (_RTL_CRITICAL_SECTION *)&this->m_perceptors_subscriptions_manager.m_subscribers.vostok::threading::mutex);
  vostok::ai::blackboard::~blackboard(&this->m_blackboard);
  vostok::ai::working_memory::~working_memory(&this->m_working_memory);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_next_for_tick);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
