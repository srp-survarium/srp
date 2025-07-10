void __thiscall survarium::bullet_manager::~bullet_manager(survarium::bullet_manager *this)
{
  survarium::bullet **i; // [esp+4h] [ebp-10h]

  if ( this->m_bullets_allocator_ref.m_initialized )
    vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>>::destroy(&this->m_bullets_allocator_ref);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_bullets_memory_ptr);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_mt_stack_allocator);
  for ( i = this->m_bullets.m_begin; i != this->m_bullets.m_end; ++i )
    ;
  this->m_bullets.m_end = this->m_bullets.m_begin;
}
