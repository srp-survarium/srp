void __thiscall vostok::render::effect_loader::on_effect_ready(
        vostok::render::effect_loader *this,
        vostok::resources::unmanaged_resource *data)
{
  vostok::resources::unmanaged_resource *v3; // edi
  vostok::resources::unmanaged_resource *v4; // ebp
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-8h] [ebp-18h]
  vostok::command_line::key_initializator predicate[4]; // [esp+Ch] [ebp-4h] BYREF

  if ( !this->query_rejected )
  {
    v3 = 0;
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
        vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
          (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)this,
          &this->effect_ptr->m_object);
      }
      else
      {
        p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources;
        data = 0;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
          (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
          (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
        v4 = data;
        *(_DWORD *)predicate = 0;
        if ( data )
        {
          v3 = data;
          *(_DWORD *)predicate = data;
          _InterlockedExchangeAdd(&data->m_reference_count, 1u);
        }
        vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
          (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)predicate,
          &this->effect_ptr->m_object);
        if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
        if ( v4 && !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
      }
    }
  }
  m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (char *)this);
}
