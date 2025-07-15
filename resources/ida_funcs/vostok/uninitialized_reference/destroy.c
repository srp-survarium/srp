void __thiscall vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface>::destroy(
        vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *this,
        vostok::uninitialized_reference<vostok::fs_new::asynchronous_device_interface> *thisa)
{
  vostok::fs_new::asynchronous_device_interface *m_variable; // esi

  m_variable = thisa->m_variable;
  CloseHandle(*(HANDLE *)m_variable->m_wakeup_event.m_event.m_event);
  TlsFree(m_variable->m_high_priority_queries.m_backward_queue_tls_key);
  TlsFree(m_variable->m_high_priority_queries.m_backward_queue_allocator_tls_key);
  TlsFree(m_variable->m_queries.m_backward_queue_tls_key);
  TlsFree(m_variable->m_queries.m_backward_queue_allocator_tls_key);
  thisa->m_initialized = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::render::cloud_simulation>::destroy(
        vostok::uninitialized_reference<vostok::render::cloud_simulation> *this,
        vostok::uninitialized_reference<vostok::render::cloud_simulation> *thisa)
{
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::cloud_simulation *m_variable; // edi
  void *v4; // esi
  vostok::render::cloud_simulation::voxel *v5; // [esp+14h] [ebp-8h]
  float *v6; // [esp+18h] [ebp-4h]

  m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  m_variable = thisa->m_variable;
  v5 = m_variable->m_voxels - 2;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
  v4 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v6 = m_variable->m_densities - 2;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v4, v6);
  thisa->m_initialized = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::resources::hdd_manager>::destroy(
        vostok::uninitialized_reference<vostok::resources::hdd_manager> *this)
{
  vostok::resources::hdd_manager *m_variable; // edi
  stlp_std::pair<unsigned int,unsigned int> *M_start; // eax

  m_variable = vostok::resources::s_hdd_device.m_variable;
  DeleteCriticalSection((LPCRITICAL_SECTION)&vostok::resources::s_hdd_device.m_variable->m_queries.vostok::threading::mutex);
  M_start = m_variable->m_thread_id_to_num_queries._M_impl._M_start;
  if ( M_start )
  {
    vostok::memory::g_resources_helper_allocator.m_out_of_memory = 0;
    vostok_mspace_free(vostok::memory::g_resources_helper_allocator.m_arena, M_start);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&m_variable->m_pre_allocated_mutex);
  vostok::resources::s_hdd_device.m_initialized = 0;
}


void __usercall vostok::uninitialized_reference<vostok::render::index_buffer>::destroy(
        vostok::uninitialized_reference<vostok::render::index_buffer> *this@<ecx>,
        int a2@<esi>)
{
  const vostok::render::untyped_buffer **v2; // eax
  const vostok::render::untyped_buffer *v3; // ecx

  v2 = *(const vostok::render::untyped_buffer ***)(a2 + 20);
  v3 = *v2;
  if ( *v2 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *v2);
  }
  *(_DWORD *)(a2 + 24) = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::network::network_world>::destroy(
        vostok::uninitialized_reference<vostok::network::network_world> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ((void (__thiscall *)(vostok::network::network_world *, _DWORD))this->m_variable->~vostok::network::network_world)(
    this->m_variable,
    0);
  this->m_initialized = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::particle::particle_world_cooker>::destroy(
        vostok::uninitialized_reference<vostok::particle::particle_world_cooker> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  ((void (__thiscall *)(vostok::particle::particle_world_cooker *, _DWORD))this->m_variable->~vostok::particle::particle_world_cooker)(
    this->m_variable,
    0);
  this->m_initialized = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::sound::sound_world>::destroy(
        vostok::uninitialized_reference<vostok::sound::sound_world> *this)
{
  ((void (__thiscall *)(vostok::sound::sound_world *, _DWORD))this->m_variable->~vostok::sound::world)(
    this->m_variable,
    0);
  this->m_initialized = 0;
}


void __usercall vostok::uninitialized_reference<vostok::render::vertex_buffer>::destroy(
        vostok::uninitialized_reference<vostok::render::vertex_buffer> *this@<ecx>,
        int a2@<esi>)
{
  const vostok::render::untyped_buffer **v2; // eax
  const vostok::render::untyped_buffer *v3; // ecx

  v2 = *(const vostok::render::untyped_buffer ***)(a2 + 24);
  v3 = *v2;
  if ( *v2 )
  {
    if ( v3->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        *v2);
  }
  *(_DWORD *)(a2 + 28) = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::fixed_vector<int,4096>>::destroy(
        vostok::uninitialized_reference<vostok::fixed_vector<int,4096> > *this)
{
  this->m_variable->m_end = this->m_variable->m_begin;
  this->m_initialized = 0;
}


void __thiscall vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock>>::destroy(
        vostok::uninitialized_reference<vostok::memory::single_size_buffer_allocator<128,vostok::threading::simple_lock> > *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this->m_variable);
  this->m_initialized = 0;
}
