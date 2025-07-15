void __thiscall vostok::ai::working_memory::clear_resources(vostok::ai::working_memory *this)
{
  survarium::game_camera *v1; // ecx
  vostok::memory::doug_lea_allocator *v2; // eax

  vostok::ai::working_memory::forget_all(this);
  vostok::intrusive_list<survarium::player_stamina_subscriber,survarium::player_stamina_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
    (vostok::intrusive_list<vostok::ai::perceptors::sensors_subscriber,vostok::ai::perceptors::sensors_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_world->m_destruction_subscriptions_manager,
    (vostok::ai::perceptors::sensors_subscriber *)&this->m_subscription);
  survarium::weapon_user_dead_state::finalize(v1);
  ___free_helper_Vdoug_lea_allocator_memory_vostok____CBX_memory_vostok__YAXAAVdoug_lea_allocator_01_AAPBX_Z(
    v2,
    &this->m_memory);
}
