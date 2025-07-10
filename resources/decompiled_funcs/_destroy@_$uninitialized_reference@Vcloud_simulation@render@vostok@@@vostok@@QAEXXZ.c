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
