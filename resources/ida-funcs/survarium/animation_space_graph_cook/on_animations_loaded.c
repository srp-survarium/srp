void __thiscall survarium::animation_space_graph_cook::on_animations_loaded(
        survarium::animation_space_graph_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config)
{
  volatile int m_result; // eax
  vostok::resources::query_result_for_cook *m_parent_query; // edi
  vostok::configs::binary_config_value *v5; // eax
  const char *v6; // eax
  float v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // ebx
  vostok::memory::doug_lea_allocator *v10; // eax
  int *v11; // eax
  survarium::animation_space_graph *v12; // eax
  survarium::animation_space_graph *v13; // ebx
  const vostok::configs::binary_config_value *v14; // eax
  char **p_m_requery_path; // esi
  survarium::animation_space_vertex *v16; // edi
  const char *v17; // eax
  int v18; // ecx
  vostok::configs::binary_config_value *v19; // edi
  const vostok::configs::binary_config_value *v20; // eax
  const vostok::configs::binary_config_value *v21; // ebx
  const char **v22; // esi
  survarium::animation_space_graph *animation_by_path; // eax
  survarium::animation_space_graph_vtbl *v24; // edx
  const vostok::configs::binary_config_value *v25; // eax
  vostok::configs::binary_config_value *v26; // esi
  const char *v27; // edi
  const char *v28; // edx
  survarium::animation_space_graph *v29; // eax
  stlp_std::pair<survarium::animation_space_vertex const *,survarium::animation_space_vertex const *> *v30; // ecx
  vostok::resources::unmanaged_resource *v31; // esi
  vostok::resources::query_result_for_cook *v32; // edi
  vostok::resources::unmanaged_intrusive_base *v33; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v34; // [esp-Ch] [ebp-54h]
  unsigned int v35; // [esp+0h] [ebp-48h]
  survarium::animation_space_graph *graph; // [esp+Ch] [ebp-3Ch]
  unsigned int it_groups; // [esp+10h] [ebp-38h]
  const vostok::configs::binary_config_value *it_groupsa; // [esp+10h] [ebp-38h]
  const vostok::configs::binary_config_value *it_end_groups; // [esp+14h] [ebp-34h] BYREF
  stlp_std::pair<survarium::animation_space_vertex const *,survarium::animation_space_vertex const *> *it_edges; // [esp+18h] [ebp-30h]
  const vostok::configs::binary_config_value *it_end_mix; // [esp+1Ch] [ebp-2Ch] BYREF
  unsigned int mixes_count; // [esp+20h] [ebp-28h]
  const survarium::animation_space_vertex *first_mixable; // [esp+24h] [ebp-24h]
  const char *second_path; // [esp+28h] [ebp-20h]
  int v45; // [esp+2Ch] [ebp-1Ch]
  vostok::resources::query_result_for_cook *parent; // [esp+34h] [ebp-14h]
  const void *pointer; // [esp+38h] [ebp-10h]
  int v48; // [esp+3Ch] [ebp-Ch]
  survarium::animation_space_graph_vtbl *v49; // [esp+40h] [ebp-8h]
  int v50; // [esp+44h] [ebp-4h]

  m_result = data->m_result;
  m_parent_query = data->m_parent_query;
  it_edges = (stlp_std::pair<survarium::animation_space_vertex const *,survarium::animation_space_vertex const *> *)this;
  it_groups = 0;
  parent = m_parent_query;
  if ( m_result == 1 )
  {
    v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                   config.m_object->m_root,
                                                   "animation_space_graph");
    v6 = (const char *)vostok::configs::binary_config_value::operator[](v5, "groups");
    v7 = *(float *)&data->m_size;
    second_path = v6;
    survarium::get_animation_mixes_count((const vostok::configs::binary_config_value *)v6, &it_end_mix);
    v8 = mixes_count;
    first_mixable = (const survarium::animation_space_vertex *)(292 * LODWORD(v7));
    v9 = 292 * LODWORD(v7) + 8 * ((_DWORD)it_end_mix + 4 * mixes_count + mixes_count) + 288;
    v10 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
    v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, v9);
    if ( v11 )
    {
      survarium::animation_space_graph::animation_space_graph(
        (survarium::animation_space_graph *)it_edges[4].first,
        (int)v11,
        (vostok::ai::navigation::world *)it_edges[4].first,
        v7,
        (unsigned int)it_end_mix,
        v8,
        v35);
      v13 = v12;
      graph = v12;
    }
    else
    {
      graph = 0;
      v13 = 0;
    }
    v14 = (const vostok::configs::binary_config_value *)&v13[1];
    if ( v7 != 0.0 )
    {
      p_m_requery_path = &data->m_queries[0].m_requery_path;
      it_edges = (stlp_std::pair<survarium::animation_space_vertex const *,survarium::animation_space_vertex const *> *)LODWORD(v7);
      while ( 1 )
      {
        v16 = (survarium::animation_space_vertex *)v14;
        it_end_mix = (const vostok::configs::binary_config_value *)((char *)v14 + 292);
        if ( v14 )
        {
          v17 = *p_m_requery_path;
          it_groups |= 1u;
          if ( !*p_m_requery_path )
            v17 = *(p_m_requery_path - 1);
          v18 = (int)*(p_m_requery_path - 9);
          it_end_groups = 0;
          if ( v18 )
          {
            it_end_groups = (const vostok::configs::binary_config_value *)v18;
            _InterlockedExchangeAdd((volatile signed __int32 *)(v18 + 220), 1u);
          }
          survarium::animation_space_vertex::animation_space_vertex(
            v16,
            (vostok::resources::managed_resource *)&it_end_groups,
            v17);
          v13 = graph;
        }
        if ( (it_groups & 1) != 0 )
        {
          it_groups &= ~1u;
          vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&it_end_groups);
        }
        p_m_requery_path += 180;
        it_edges = (stlp_std::pair<survarium::animation_space_vertex const *,survarium::animation_space_vertex const *> *)((char *)it_edges - 1);
        if ( !it_edges )
          break;
        v14 = it_end_mix;
      }
    }
    v19 = *(vostok::configs::binary_config_value **)second_path;
    v20 = (const vostok::configs::binary_config_value *)(*(_DWORD *)second_path
                                                       + 24 * *((unsigned __int16 *)second_path + 11));
    it_edges = (stlp_std::pair<survarium::animation_space_vertex const *,survarium::animation_space_vertex const *> *)((char *)&v13[1] + (_DWORD)first_mixable);
    it_groupsa = v19;
    it_end_groups = v20;
    if ( v19 != v20 )
    {
      do
      {
        pointer = vostok::configs::binary_config_value::operator[](v19, "group_id")->data.pointer;
        v48 = 0;
        v49 = (survarium::animation_space_graph_vtbl *)vostok::configs::binary_config_value::operator[](
                                                         v19,
                                                         "intervals_count")->data.pointer;
        v50 = 0;
        v21 = vostok::configs::binary_config_value::operator[](v19, "vertices");
        v22 = (const char **)v21->data.pointer;
        second_path = (char *)v21->data.pointer + 24 * v21->count;
        if ( v22 != (const char **)second_path )
        {
          do
          {
            animation_by_path = survarium::animation_space_graph::get_animation_by_path(graph, *v22);
            v24 = v49;
            v22 += 6;
            animation_by_path->m_edges_count = (const unsigned int)pointer;
            animation_by_path[1].__vftable = v24;
          }
          while ( v22 != (const char **)second_path );
          v19 = (vostok::configs::binary_config_value *)it_groupsa;
        }
        if ( vostok::configs::binary_config_value::value_exists(v19, "mixable") )
        {
          v25 = vostok::configs::binary_config_value::operator[](v19, "mixable");
          v26 = (vostok::configs::binary_config_value *)v25->data.pointer;
          for ( it_end_mix = (const vostok::configs::binary_config_value *)((char *)v25->data.pointer + 24 * v25->count);
                v26 != it_end_mix;
                ++v26 )
          {
            v27 = (const char *)*((_DWORD *)v21->data.pointer
                                + 6 * (int)vostok::configs::binary_config_value::operator[](v26, "first")->data.pointer);
            v45 = 0;
            v28 = (const char *)*((_DWORD *)v21->data.pointer
                                + 6 * (int)vostok::configs::binary_config_value::operator[](v26, "second")->data.pointer);
            v45 = 0;
            second_path = v28;
            first_mixable = (const survarium::animation_space_vertex *)survarium::animation_space_graph::get_animation_by_path(
                                                                         graph,
                                                                         v27);
            v29 = survarium::animation_space_graph::get_animation_by_path(graph, second_path);
            v30 = it_edges++;
            if ( v30 )
            {
              v30->first = first_mixable;
              v30->second = (const survarium::animation_space_vertex *)v29;
            }
          }
          v19 = (vostok::configs::binary_config_value *)it_groupsa;
        }
        it_groupsa = ++v19;
      }
      while ( v19 != it_end_groups );
      v13 = graph;
    }
    survarium::animation_space_graph_cook::generate_graph_edges((survarium::animation_space_graph_cook *)v13);
    v31 = 0;
    if ( v13 )
    {
      v31 = v13;
      _InterlockedExchangeAdd(&v13->m_reference_count, 1u);
    }
    v34.m_object = 0;
    if ( v31 )
    {
      v34.m_object = v31;
      _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
    }
    v32 = parent;
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      v34,
      &vostok::resources::nocache_memory,
      0x120u);
    if ( v31 )
    {
      v33 = &v31->vostok::resources::unmanaged_intrusive_base;
      if ( !_InterlockedExchangeAdd(&v31->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(v33, v31);
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)v33,
      (int)v32,
      result_success,
      assert_on_fail_true,
      0);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      (vostok::resources::query_result_for_cook *)this,
      (int)m_parent_query,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  }
  if ( config.m_object )
  {
    if ( !_InterlockedExchangeAdd(&config.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &config.m_object->vostok::resources::unmanaged_intrusive_base,
        config.m_object);
  }
}
