void __thiscall vostok::render::speedtree_cook::on_model_materials_loaded(
        vostok::render::speedtree_cook *this,
        vostok::resources::queries_result *data,
        vostok::resources::query_result_for_cook *d)
{
  vostok::resources::query_result_for_cook *v3; // ecx
  char v4; // al
  char **p_m_requery_path; // ebx
  vostok::fs_new::virtual_path_string *p_m_thread_id; // esi
  int v7; // eax
  vostok::resources::unmanaged_resource *v8; // ebp
  vostok::resources::unmanaged_resource *v9; // edi
  vostok::resources::unmanaged_resource *v10; // eax
  vostok::render::material *v11; // ecx
  vostok::resources::unmanaged_resource *m_object; // eax
  char *v13; // eax
  char *m_begin; // ecx
  char *m_end; // ecx
  bool v16; // zf
  vostok::render::speedtree_cook *v17; // [esp+0h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::render::material,vostok::resources::unmanaged_intrusive_base> *p_type; // [esp+14h] [ebp-8h]
  int v19; // [esp+18h] [ebp-4h]
  char **dataa; // [esp+20h] [ebp+4h]

  v3 = d;
  v4 = 0;
  p_m_requery_path = &data->m_queries[0].m_requery_path;
  p_m_thread_id = (vostok::fs_new::virtual_path_string *)&d->m_children_resources.m_thread_id;
  p_type = (vostok::resources::resource_ptr<vostok::render::material,vostok::resources::unmanaged_intrusive_base> *)&d->type;
  dataa = &data->m_queries[0].m_requery_path;
  v19 = 5;
  do
  {
    if ( !p_m_requery_path[1] && p_m_requery_path[2] != (char *)1 )
    {
      v7 = (int)*(p_m_requery_path - 8);
      v8 = 0;
      if ( v7 )
      {
        v8 = (vostok::resources::unmanaged_resource *)*(p_m_requery_path - 8);
        _InterlockedExchangeAdd((volatile signed __int32 *)(v7 + 208), 1u);
      }
      v9 = 0;
      if ( v8 )
      {
        v9 = v8;
        _InterlockedExchangeAdd(&v8->m_reference_count, 1u);
      }
      v10 = 0;
      if ( v9 )
      {
        v10 = v9;
        _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
      }
      v11 = (vostok::render::material *)v10;
      m_object = p_type->m_object;
      p_type->m_object = v11;
      if ( m_object )
      {
        if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(
            &m_object->vostok::resources::unmanaged_intrusive_base,
            m_object);
        p_m_requery_path = dataa;
      }
      if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
      if ( v8 && !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
      v13 = *p_m_requery_path;
      if ( !*p_m_requery_path )
        v13 = *(p_m_requery_path - 1);
      m_begin = p_m_thread_id->m_string.m_begin;
      if ( p_m_thread_id->m_string.m_begin != v13 )
      {
        p_m_thread_id->m_string.m_end = m_begin;
        *m_begin = 0;
        if ( v13 )
        {
          for ( ; *v13; ++v13 )
          {
            m_end = p_m_thread_id->m_string.m_end;
            if ( m_end >= p_m_thread_id->m_string.m_max_end )
              break;
            *m_end = *v13;
            ++p_m_thread_id->m_string.m_end;
          }
          *p_m_thread_id->m_string.m_end = 0;
        }
      }
      v3 = d;
      v4 = 1;
    }
    ++p_type;
    p_m_requery_path += 180;
    ++p_m_thread_id;
    v16 = v19-- == 1;
    dataa = p_m_requery_path;
  }
  while ( !v16 );
  if ( v4 )
    vostok::resources::query_result_for_cook::finish_query_impl(
      v3,
      (int)v3->__vftable,
      result_error,
      assert_on_fail_true,
      (vostok::resources::query_result_for_cook *)0xB);
  else
    vostok::render::speedtree_cook::finish_model_creation((vostok::resources::unmanaged_resource **)v3, v3, v17);
}
