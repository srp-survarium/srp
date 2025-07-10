vostok::resources::managed_resource *__thiscall vostok::resources::resources_manager::allocate_managed_resource(
        vostok::resources::resources_manager *this,
        vostok::memory::managed_allocator_base *size,
        vostok::resources::class_id_enum class_id)
{
  unsigned int v3; // edx
  unsigned int p_m_know_largest_free_block; // ecx
  vostok::memory::managed_node *v5; // edi
  unsigned int v7; // ecx
  int *v8; // esi
  int v9; // eax
  int v10; // esi
  vostok::memory::managed_node_owner *v11; // eax
  volatile __int32 *p_m_is_unmovable; // ebx
  vostok::threading::mutex *v13; // edi
  vostok::memory::managed_node *v14; // [esp+0h] [ebp-Ch]

  v3 = (unsigned int)&size[1].m_know_largest_free_block % vostok::memory::g_resources_managed_allocator.m_granularity;
  if ( v3 )
    p_m_know_largest_free_block = (unsigned int)(&size[1].m_know_largest_free_block
                                               + vostok::memory::g_resources_managed_allocator.m_granularity
                                               - v3);
  else
    p_m_know_largest_free_block = (unsigned int)&size[1].m_know_largest_free_block;
  if ( p_m_know_largest_free_block > vostok::memory::g_resources_managed_allocator.m_free_size
                                   - vostok::memory::g_resources_managed_allocator.m_reserved_size )
    return 0;
  v5 = vostok::memory::managed_allocator_base::allocate(
         size,
         &vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base,
         v14);
  if ( !v5 )
    return 0;
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(&vostok::memory::g_resources_helper_allocator, 0xF0u);
  if ( !v8 )
  {
    v10 = 0;
    goto LABEL_11;
  }
  vostok::resources::managed_resource::managed_resource(
    (vostok::resources::managed_resource *)v8,
    class_id,
    v7,
    (unsigned int)size);
  v10 = v9;
  if ( !v9 )
  {
LABEL_11:
    v11 = 0;
    goto LABEL_12;
  }
  v11 = (vostok::memory::managed_node_owner *)(v9 + 208);
LABEL_12:
  v5->m_owner = v11;
  p_m_is_unmovable = &v5->m_is_unmovable;
  *(_DWORD *)(v10 + 212) = v5;
  if ( !v5->m_is_unmovable )
  {
    v13 = (vostok::threading::mutex *)(*(_DWORD *)(v10 + 216) + 8368);
    vostok::threading::mutex::lock(v13);
    _InterlockedExchange(p_m_is_unmovable, 1);
    LeaveCriticalSection((LPCRITICAL_SECTION)v13);
  }
  return (vostok::resources::managed_resource *)v10;
}
