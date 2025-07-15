vostok::resources::managed_resource *__thiscall vostok::resources::resources_manager::allocate_managed_resource(
        vostok::resources::resources_manager *this,
        vostok::memory::managed_allocator_base *size,
        vostok::resources::class_id_enum class_id)
{
  vostok::memory::managed_node *v3; // edi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  vostok::resources::managed_resource *v8; // ecx
  int v9; // eax
  int v10; // esi
  vostok::memory::managed_node_owner *v11; // eax
  const char *v12; // [esp+0h] [ebp-Ch]
  const char *v13; // [esp+4h] [ebp-8h]
  unsigned int v14; // [esp+8h] [ebp-4h]

  if ( vostok::math::align_up<unsigned long>(vostok::memory::g_resources_managed_allocator.m_granularity) > vostok::memory::g_resources_managed_allocator.m_free_size - vostok::memory::g_resources_managed_allocator.m_reserved_size )
    return 0;
  v3 = vostok::memory::managed_allocator_base::allocate(
         size,
         &vostok::memory::g_resources_managed_allocator.vostok::memory::managed_allocator_base);
  if ( !v3 )
    return 0;
  v5 = type_info::raw_name(&vostok::resources::managed_resource `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(
         v6,
         (int)&vostok::memory::g_resources_helper_allocator,
         0xF0u,
         v5,
         v12,
         v13,
         v14);
  if ( v7 )
  {
    vostok::resources::managed_resource::managed_resource(v8, v7, (unsigned int)size, class_id);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  if ( v10 )
    v11 = (vostok::memory::managed_node_owner *)(v10 + 208);
  else
    v11 = 0;
  v3->m_owner = v11;
  *(_DWORD *)(v10 + 212) = v3;
  vostok::memory::managed_node_owner::set_is_unmovable((vostok::memory::managed_node_owner *)v8, v10 + 208, 1);
  return (vostok::resources::managed_resource *)v10;
}
