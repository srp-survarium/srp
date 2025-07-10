void __userpurge vostok::render::material_cook::on_material_binary_config_loaded(
        vostok::resources::query_result_for_cook *parent@<eax>,
        vostok::render::material_cook *this,
        vostok::configs::binary_config *cfg)
{
  int *v4; // esi
  vostok::render::material *v5; // ecx
  int v6; // eax
  int v7; // esi
  char *m_requery_path; // edx
  char *v9; // eax
  vostok::resources::query_result_for_cook *v10; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v12; // [esp-8h] [ebp-18h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13[5]; // [esp-4h] [ebp-14h] BYREF

  v13[4].m_object = 0;
  v4 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
         0x198u);
  if ( v4 )
  {
    v13[0].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      v13,
      (vostok::configs::binary_config *)this);
    vostok::render::material::material(
      v5,
      (int)v4,
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>)v13[0].m_object);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  m_requery_path = parent->m_requery_path;
  if ( !m_requery_path )
    m_requery_path = parent->m_request_path;
  v9 = *(char **)(v7 + 264);
  if ( v9 != m_requery_path )
  {
    *(_DWORD *)(v7 + 268) = v9;
    v13[0].m_object = (vostok::configs::binary_config *)m_requery_path;
    *v9 = 0;
    vostok::buffer_string::operator+=((vostok::buffer_string *)(v7 + 264), (const char *)v13[0].m_object);
  }
  v13[0].m_object = (vostok::configs::binary_config *)408;
  v12 = &vostok::resources::nocache_memory;
  v11.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v11,
    (vostok::configs::binary_config *)v7);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v11.m_object,
    v12,
    (unsigned int)v13[0].m_object);
  vostok::resources::query_result_for_cook::finish_query_impl(v10, (int)parent, result_success, assert_on_fail_true, 0);
}
