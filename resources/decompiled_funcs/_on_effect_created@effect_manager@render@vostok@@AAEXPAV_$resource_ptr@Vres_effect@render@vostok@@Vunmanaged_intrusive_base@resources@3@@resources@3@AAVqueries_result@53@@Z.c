void __thiscall vostok::render::effect_manager::on_effect_created(
        vostok::render::effect_manager *this,
        vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *out_effect_ptr,
        vostok::resources::unmanaged_resource *data)
{
  vostok::resources::unmanaged_resource *v3; // ebp
  vostok::resources::unmanaged_resource *v4; // edi
  vostok::render::res_effect *m_object; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-4h] [ebp-18h]
  vostok::command_line::key_initializator predicate[4]; // [esp+10h] [ebp-4h] BYREF

  if ( s_no_effects_initialize.m_type == type_unset )
  {
    predicate[0] = 0;
    s_no_effects_initialize.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_no_effects_initialize.m_type == type_recursive )
  {
    if ( *(_DWORD *)&data[1].m_parent_resources.gapC
      || data[1].m_parent_resources.m_first == (vostok::resources::resource_link *)1 )
    {
      m_object = out_effect_ptr->m_object;
      out_effect_ptr->m_object = 0;
      if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          &m_object->vostok::resources::unmanaged_intrusive_base,
          m_object);
    }
    else
    {
      p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources;
      data = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
        (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
      v3 = data;
      v4 = 0;
      *(_DWORD *)predicate = 0;
      if ( data )
      {
        v4 = data;
        *(_DWORD *)predicate = data;
        _InterlockedExchangeAdd(&data->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
        (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)predicate,
        &out_effect_ptr->m_object);
      if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
      if ( v3 )
      {
        if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
      }
    }
  }
}
