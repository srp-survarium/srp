void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        void *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex> *v6; // [esp+34h] [ebp-8h]
  unsigned __int8 *aligned_arena; // [esp+38h] [ebp-4h]

  this->m_arena_id = arena_id;
  aligned_arena = (unsigned __int8 *)vostok::math::align_up<unsigned int>((unsigned int)arena, 8u);
  survarium::weapon_user_dead_state::finalize(v4);
  v6 = (vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex> *)operator new(
                                                                                       0x10u,
                                                                                       &this->m_allocator);
  if ( v6 )
    vostok::memory::single_size_buffer_allocator<208,vostok::threading::mutex>::single_size_buffer_allocator<208,vostok::threading::mutex>(
      v6,
      aligned_arena,
      size);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_allocator);
  vostok::threading::interlocked_exchange_pointer(&this->m_allocator.m_initialized, 1);
}


void __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        char *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  char *v5; // eax

  this->m_arena_id = arena_id;
  v5 = arena;
  if ( ((unsigned __int8)arena & 7) != 0 )
    v5 = &arena[-((unsigned __int8)arena & 7) + 8];
  if ( this != (vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *)-24 )
    vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>(
      (vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *)&this->m_allocator,
      v5,
      size);
  _InterlockedExchange(&this->m_allocator.m_initialized, 1);
}


void __thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this,
        char *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  char *v5; // eax

  this->m_arena_id = arena_id;
  v5 = arena;
  if ( ((unsigned __int8)arena & 7) != 0 )
    v5 = &arena[-((unsigned __int8)arena & 7) + 8];
  if ( this != (vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *)-24 )
    vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>(
      (vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> *)&this->m_allocator,
      v5,
      size);
  _InterlockedExchange(&this->m_allocator.m_initialized, 1);
}
