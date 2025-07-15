void __thiscall vostok::sound::sound_world::~sound_world(vostok::sound::sound_world *this)
{
  vostok::sound::sound_order *order; // [esp+4Ch] [ebp-4h] BYREF

  this->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::sound_world::`vftable';
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::voice_factory>(
    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
    &this->m_voice_factory);
  vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::sound::sound_buffer_factory>(
    (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
    &this->m_sound_buffer_factory);
  if ( this->m_master_voice )
    this->m_master_voice->DestroyVoice(this->m_master_voice);
  this->m_xaudio->Release(this->m_xaudio);
  order = vostok::intrusive_spsc_queue<vostok::sound::sound_response,vostok::sound::sound_response,4>::pop_null_node(&this->m_xaudio_callback_orders);
  vostok::memory::detail::delete_helper_impl<vostok::memory::pthreads3_allocator,vostok::particle::particle_system_instance,vostok::memory::detail::call_destructor_predicate>(
    &vostok::memory::g_mt_allocator,
    &order);
  vostok::threading::mutex_tasks_unaware::~mutex_tasks_unaware(&this->m_voices_to_delete.m_mutex);
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_panning_lut);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_unmanaged_resources_ptr);
  this->__vftable = (vostok::sound::sound_world_vtbl *)&vostok::sound::world::`vftable';
}
