void __thiscall vostok::render::grass_cook::on_layers_loaded(
        vostok::render::grass_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::grass_cook_data *cook_data)
{
  unsigned int m_size; // eax
  vostok::render::grass_cook_data *v4; // ebp
  int v5; // edi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_managed_resource; // ebx
  unsigned int v7; // esi
  vostok::resources::queries_result *m_object; // ecx
  vostok::resources::queries_result *v9; // eax
  vostok::resources::queries_result *v10; // ecx
  vostok::render::grass_world *result; // eax
  vostok::resources::query_result_for_cook *v12; // ecx
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  char *v14; // eax
  malloc_state *v15; // esi
  char *v16; // eax
  malloc_state *v17; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v18; // [esp-Ch] [ebp-24h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v19; // [esp+10h] [ebp-8h] BYREF
  vostok::render::grass_layer_desc *layer_desc; // [esp+14h] [ebp-4h]

  m_size = data->m_size;
  v4 = cook_data;
  v5 = 0;
  layer_desc = 0;
  if ( (_BYTE)m_size )
  {
    p_m_managed_resource = &data->m_queries[0].m_managed_resource;
    cook_data = (vostok::render::grass_cook_data *)(unsigned __int8)m_size;
    do
    {
      v7 = (unsigned int)v4->data[v5];
      m_object = (vostok::resources::queries_result *)p_m_managed_resource->m_object;
      v9 = 0;
      layer_desc = v4->desc[v5];
      data = 0;
      if ( m_object )
      {
        v9 = m_object;
        data = m_object;
        _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].grm_satisfaction_tree_hook.left_, 1u);
      }
      v10 = 0;
      if ( v9 )
      {
        v10 = v9;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v9->m_queries[0].grm_satisfaction_tree_hook.left_, 1u);
      }
      v19.m_object = *(vostok::resources::managed_resource **)(v7 + 36);
      *(_DWORD *)(v7 + 36) = v10;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v19);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&data);
      vostok::render::grass_world::update_grass_layer(v7, v4->result, layer_desc, 1, 1, 1);
      ++v5;
      p_m_managed_resource += 180;
      cook_data = (vostok::render::grass_cook_data *)((char *)cook_data - 1);
    }
    while ( cook_data );
  }
  vostok::render::grass_world::populate((vostok::render::grass_world *)this, v4->result);
  result = v4->result;
  v18.m_object = 0;
  if ( result )
  {
    v18.m_object = v4->result;
    _InterlockedExchangeAdd(&result->m_reference_count, 1u);
  }
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v4->parent_query,
    v18,
    &vostok::resources::nocache_memory,
    0x168u);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v12,
    (int)v4->parent_query,
    result_success,
    assert_on_fail_true,
    0);
  m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v14 = (char *)(v4->desc - 2);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v14);
  v15 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v16 = (char *)(v4->data - 2);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v15, v16);
  v17 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v17, (char *)v4);
}
