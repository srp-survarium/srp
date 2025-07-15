void __thiscall vostok::render::render_model_cook::on_materials_loaded(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::cook_intermediate_data *cook_data)
{
  vostok::render::cook_intermediate_data *v4; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // edi
  vostok::resources::unmanaged_resource *m_object; // esi
  vostok::resources::unmanaged_resource **p_m_object; // ecx
  vostok::resources::unmanaged_resource *v8; // eax
  vostok::resources::unmanaged_resource *v9; // edx
  vostok::resources::unmanaged_resource *v10; // eax
  bool v11; // zf
  int v12; // [esp+Ch] [ebp-Ch]
  unsigned int i; // [esp+10h] [ebp-8h]
  vostok::render::render_model_cook *v14; // [esp+14h] [ebp-4h]

  v4 = cook_data;
  v14 = this;
  if ( cook_data->status_failed )
    goto LABEL_20;
  i = 0;
  if ( data->m_size )
  {
    v12 = 0;
    p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
    do
    {
      if ( !p_m_unmanaged_resource[9].m_object
        && p_m_unmanaged_resource[10].m_object != (vostok::resources::unmanaged_resource *)1 )
      {
        m_object = 0;
        if ( p_m_unmanaged_resource->m_object )
        {
          m_object = p_m_unmanaged_resource->m_object;
          _InterlockedExchangeAdd(&p_m_unmanaged_resource->m_object->m_reference_count, 1u);
        }
        p_m_object = &v4->assets[v12].material.m_object;
        v8 = 0;
        if ( m_object )
        {
          v8 = m_object;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        v9 = v8;
        v10 = *p_m_object;
        *p_m_object = v9;
        if ( v10 && !_InterlockedExchangeAdd(&v10->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v10->vostok::resources::unmanaged_intrusive_base, v10);
        if ( m_object )
        {
          if ( !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(
              &m_object->vostok::resources::unmanaged_intrusive_base,
              m_object);
        }
        v4 = cook_data;
      }
      ++v12;
      p_m_unmanaged_resource += 180;
      ++i;
    }
    while ( i < data->m_size );
    this = v14;
  }
  v11 = !v4->render_model_data_ready;
  v4->material_data_ready = 1;
  if ( !v11 )
LABEL_20:
    vostok::render::render_model_cook::query_materail_effects(
      (vostok::render::render_model_cook *)v4,
      (vostok::render::cook_intermediate_data *)this,
      v4);
}
