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
