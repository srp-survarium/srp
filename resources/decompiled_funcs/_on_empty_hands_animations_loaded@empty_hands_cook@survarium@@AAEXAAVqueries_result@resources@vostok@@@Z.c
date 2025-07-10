void __thiscall survarium::empty_hands_cook::on_empty_hands_animations_loaded(
        survarium::empty_hands_cook *this,
        vostok::resources::queries_result *data)
{
  unsigned int m_size; // ebx
  int *v3; // esi
  vostok::resources::managed_resource **v4; // ebx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // edi
  vostok::resources::managed_resource *m_object; // ecx
  vostok::resources::managed_resource *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ecx
  vostok::resources::query_result_for_cook *m_parent_query; // ecx
  vostok::resources::unmanaged_resource *v10; // ebx
  vostok::resources::unmanaged_intrusive_base *v11; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v12; // [esp-Ch] [ebp-2Ch]
  unsigned int v13; // [esp-4h] [ebp-24h]
  unsigned int v14; // [esp+0h] [ebp-20h]
  int v15; // [esp+Ch] [ebp-14h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v16; // [esp+10h] [ebp-10h] BYREF
  unsigned int v17; // [esp+14h] [ebp-Ch]
  unsigned int animations_count; // [esp+18h] [ebp-8h]
  unsigned int buffer_size; // [esp+1Ch] [ebp-4h]

  m_size = data->m_size;
  v15 = 0;
  animations_count = m_size;
  buffer_size = 4 * m_size + 344;
  v3 = vostok::memory::doug_lea_allocator::malloc_impl(
         (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
         buffer_size);
  if ( m_size )
  {
    v4 = (vostok::resources::managed_resource **)(v3 + 86);
    p_m_managed_resource = &data->m_queries[0].m_managed_resource;
    v17 = animations_count;
    do
    {
      if ( v4 )
      {
        m_object = p_m_managed_resource->m_object;
        v15 |= 1u;
        v7 = 0;
        v16.m_object = 0;
        if ( m_object )
        {
          v7 = m_object;
          v16.m_object = m_object;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        *v4 = 0;
        if ( v7 )
        {
          *v4 = v7;
          _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
        }
      }
      if ( (v15 & 1) != 0 )
      {
        v15 &= ~1u;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v16);
      }
      ++v4;
      p_m_managed_resource += 180;
      --v17;
    }
    while ( v17 );
    m_size = animations_count;
  }
  if ( v3 )
  {
    vostok::resources::resource_base::resource_base(
      (vostok::resources::resource_base *)4,
      (int)v3,
      unknown_data_class,
      1u,
      v14);
    v3[52] = 0;
    animations_count = 0;
    v3[53] = 0;
    *v3 = (int)&vostok::resources::unmanaged_resource::`vftable';
    v3[54] = 0;
    v3[55] = 0;
    v3[57] = 0;
    v3[64] = 0;
    vostok::resources::unmanaged_resource::constructor_impl(v8, (int)v3);
    *v3 = (int)&survarium::empty_hands::`vftable';
    v3[82] = 0;
    v3[83] = (int)(v3 + 86);
    v3[84] = m_size;
    v3[85] = 0;
    vostok::math::float4x4::identity((vostok::math::float4x4 *)(v3 + 66));
  }
  else
  {
    v3 = 0;
  }
  m_parent_query = data->m_parent_query;
  v10 = 0;
  animations_count = (unsigned int)m_parent_query;
  if ( v3 )
  {
    v10 = (vostok::resources::unmanaged_resource *)v3;
    _InterlockedExchangeAdd(v3 + 52, 1u);
  }
  v13 = buffer_size;
  v12.m_object = 0;
  if ( v10 )
  {
    v12.m_object = v10;
    _InterlockedExchangeAdd(&v10->m_reference_count, 1u);
  }
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    m_parent_query,
    v12,
    &vostok::resources::nocache_memory,
    v13);
  if ( v10 )
  {
    v11 = &v10->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v11, v10);
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)v11,
    animations_count,
    result_success,
    assert_on_fail_true,
    0);
}
