void __thiscall vostok::render::effect_manager::on_effects_recompiled(
        vostok::render::effect_manager *this,
        vostok::vectora<vostok::render::effect_manager::effect_to_recompile_struct> *effects_to_recompile,
        vostok::resources::queries_result *data)
{
  vostok::render::effect_manager::effect_to_recompile_struct *M_start; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // ebp
  vostok::resources::unmanaged_intrusive_base *m_object; // ecx
  vostok::resources::unmanaged_resource *v6; // eax
  vostok::resources::unmanaged_resource *v7; // edi
  vostok::render::effect_manager *v8; // [esp+10h] [ebp-4h]

  M_start = effects_to_recompile->_M_impl._M_start;
  v8 = this;
  if ( effects_to_recompile->_M_impl._M_start != effects_to_recompile->_M_impl._M_finish )
  {
    p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
    do
    {
      if ( !p_m_unmanaged_resource[9].m_object
        && p_m_unmanaged_resource[10].m_object != (vostok::resources::unmanaged_resource *)1 )
      {
        m_object = (vostok::resources::unmanaged_intrusive_base *)p_m_unmanaged_resource->m_object;
        v6 = 0;
        if ( p_m_unmanaged_resource->m_object )
        {
          v6 = p_m_unmanaged_resource->m_object;
          m_object += 26;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        v7 = 0;
        if ( v6 )
        {
          m_object = &v6->vostok::resources::unmanaged_intrusive_base;
          v7 = v6;
          _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
          if ( !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
            vostok::resources::unmanaged_intrusive_base::destroy(m_object, v6);
        }
        stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::operator=(
          (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)m_object,
          &M_start->effect.m_object->m_techniques._M_impl,
          (const stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)&v7[1].vostok::resources::resource_reconstruction_info);
        M_start->effect.m_object->m_cur_technique = *((_DWORD *)&v7[1].vostok::resources::resource_flags + 3);
        if ( !_InterlockedExchangeAdd(&v7->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v7->vostok::resources::unmanaged_intrusive_base, v7);
      }
      ++M_start;
      p_m_unmanaged_resource += 180;
    }
    while ( M_start != effects_to_recompile->_M_impl._M_finish );
    this = v8;
  }
  this->m_is_effects_query_processing = 0;
}
