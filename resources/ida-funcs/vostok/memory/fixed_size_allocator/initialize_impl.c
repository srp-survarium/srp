void __thiscall vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        void *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *p_m_allocator; // edi
  vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex>::node *v6; // eax
  char v7; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> const &)> on_out_of_memory; // [esp+10h] [ebp-20h] BYREF

  v7 = 0;
  p_m_allocator = (vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex> *)&this->m_allocator;
  this->m_arena_id = arena_id;
  if ( this != (vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *)-24 )
  {
    on_out_of_memory.vtable = 0;
    v7 = 1;
    v6 = (vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex>::node *)vostok::math::align_up<unsigned long>(8u);
    vostok::memory::single_size_buffer_allocator<292,vostok::threading::mutex>::single_size_buffer_allocator<292,vostok::threading::mutex>(
      &on_out_of_memory,
      p_m_allocator,
      v6,
      size);
  }
  _InterlockedExchange(&this->m_allocator.m_initialized, 1);
  if ( (v7 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&on_out_of_memory);
}


void __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        unsigned int arena,
        unsigned __int64 size,
        const char *arena_id)
{
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *p_m_allocator; // edi
  vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *v6; // eax
  char v7; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> const &)> on_out_of_memory; // [esp+10h] [ebp-20h] BYREF

  v7 = 0;
  p_m_allocator = (vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex> *)&this->m_allocator;
  this->m_arena_id = arena_id;
  if ( this != (vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *)-24 )
  {
    on_out_of_memory.vtable = 0;
    v7 = 1;
    v6 = (vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::node *)vostok::math::align_up<unsigned long>(8u);
    vostok::memory::single_size_buffer_allocator<12,vostok::threading::mutex>::single_size_buffer_allocator<12,vostok::threading::mutex>(
      &on_out_of_memory,
      p_m_allocator,
      v6,
      size);
  }
  _InterlockedExchange(&this->m_allocator.m_initialized, 1);
  if ( (v7 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&on_out_of_memory);
}


void __thiscall vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware>::initialize_impl(
        vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *this,
        void *arena,
        unsigned __int64 size,
        const char *arena_id)
{
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> *p_m_allocator; // edi
  vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *v6; // eax
  char v7; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> const &)> on_out_of_memory; // [esp+10h] [ebp-20h] BYREF

  v7 = 0;
  p_m_allocator = (vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware> *)&this->m_allocator;
  this->m_arena_id = arena_id;
  if ( this != (vostok::memory::fixed_size_allocator<vostok::tasks::task_type,vostok::threading::mutex_tasks_unaware> *)-24 )
  {
    on_out_of_memory.vtable = 0;
    v7 = 1;
    v6 = (vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::node *)vostok::math::align_up<unsigned long>(8u);
    vostok::memory::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>::single_size_buffer_allocator<120,vostok::threading::mutex_tasks_unaware>(
      &on_out_of_memory,
      p_m_allocator,
      v6,
      size);
  }
  _InterlockedExchange(&this->m_allocator.m_initialized, 1);
  if ( (v7 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
      (int *)&on_out_of_memory);
}
