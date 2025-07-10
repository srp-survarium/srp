// local variable allocation has failed, the output may be wrong!
vostok::render::effect_compiler *__thiscall vostok::render::effect_compiler::begin_pass(
        vostok::render::effect_compiler *this,
        vostok::render::effect_compiler *vs_name,
        char *gs_name,
        char *ps_name,
        vostok::render::shader_configuration *shader_config,
        const vostok::render::shader_configuration *include_getter)
{
  vostok::render::shader_constant_binding *v6; // eax
  vostok::render::shader_constant_binding *M_start; // ecx
  vostok::render::shader_constant_binding *v8; // esi
  vostok::render::res_xs_hw<vostok::render::vs_data> *v9; // eax
  vostok::render::resource_manager *v10; // ecx
  const vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // eax
  bool v12; // zf
  vostok::render::res_xs_hw<vostok::render::gs_data> *v13; // eax
  vostok::render::res_xs_hw<vostok::render::gs_data> *v14; // ecx
  vostok::render::res_xs_hw<vostok::render::gs_data> *v15; // eax
  stlp_std::priv::_Rb_tree_node_base *v16; // eax
  vostok::render::resource_manager *v17; // ecx
  vostok::render::res_xs_hw<vostok::render::ps_data> *v18; // eax
  vostok::render::res_xs_hw<vostok::render::vs_data> *v19; // edi
  const vostok::render::res_xs_hw<vostok::render::vs_data> *v20; // eax
  vostok::render::res_xs_hw<vostok::render::gs_data> *v21; // eax
  vostok::render::res_xs_hw<vostok::render::gs_data> *v22; // eax
  vostok::render::res_xs_hw<vostok::render::ps_data> *v23; // eax
  vostok::render::res_xs_hw<vostok::render::ps_data> *v24; // eax
  char *v26; // eax
  char *m_end; // ecx
  char *v28; // eax
  char *v29; // ecx
  char *m_begin; // ecx
  vostok::render::shader_configuration *v31; // eax
  vostok::render::effect_compiler::shader_cache_info *M_finish; // esi
  associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type> > *m_shader_sources; // [esp-14h] [ebp-37Ch]
  associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type> > *v34; // [esp-14h] [ebp-37Ch]
  vostok::render::shader_configuration v35; // [esp-14h] [ebp-37Ch]
  unsigned __int64 v36; // [esp-10h] [ebp-378h] OVERLAPPED
  unsigned __int64 v37; // [esp-10h] [ebp-378h] OVERLAPPED
  unsigned __int64 v38; // [esp-8h] [ebp-370h] OVERLAPPED
  unsigned __int64 v39; // [esp-8h] [ebp-370h] OVERLAPPED
  associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type> > *v40; // [esp+0h] [ebp-368h]
  associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type> > *v41; // [esp+0h] [ebp-368h]
  associative_vector<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,vostok::render::vector,stlp_std::less<vostok::render::binary_shader_key_type> > *v42; // [esp+0h] [ebp-368h]
  D3D11_BLEND_OP v43; // [esp+0h] [ebp-368h]
  bool v44; // [esp+4h] [ebp-364h]
  vostok::render::effect_compiler::shader_cache_info info; // [esp+18h] [ebp-350h] BYREF

  if ( vs_name->m_shaders_cache_mode )
    goto LABEL_55;
  if ( s_no_effect_result.m_type == type_unset )
  {
    s_no_effect_result.m_type = type_recursive;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
  }
  if ( s_no_effect_result.m_type != type_recursive )
  {
LABEL_55:
    vostok::render::effect_compiler::shader_cache_info::shader_cache_info(
      (vostok::render::effect_compiler::shader_cache_info *)this,
      (int)&info);
    if ( info.vertex_shader_name.m_string.m_begin != gs_name )
    {
      info.vertex_shader_name.m_string.m_end = info.vertex_shader_name.m_string.m_begin;
      *info.vertex_shader_name.m_string.m_begin = 0;
      v26 = gs_name;
      if ( gs_name )
      {
        m_end = info.vertex_shader_name.m_string.m_end;
        if ( *gs_name )
        {
          do
          {
            if ( m_end >= info.vertex_shader_name.m_string.m_max_end )
              break;
            *m_end = *v26;
            m_end = info.vertex_shader_name.m_string.m_end + 1;
            v12 = *++v26 == 0;
            ++info.vertex_shader_name.m_string.m_end;
          }
          while ( !v12 );
        }
        *m_end = 0;
      }
    }
    v28 = ps_name;
    if ( info.geometry_shader_name.m_string.m_begin != ps_name )
    {
      info.geometry_shader_name.m_string.m_end = info.geometry_shader_name.m_string.m_begin;
      *info.geometry_shader_name.m_string.m_begin = 0;
      if ( ps_name )
      {
        v29 = info.geometry_shader_name.m_string.m_end;
        if ( *ps_name )
        {
          do
          {
            if ( v29 >= info.geometry_shader_name.m_string.m_max_end )
              break;
            *v29 = *v28;
            v29 = info.geometry_shader_name.m_string.m_end + 1;
            v12 = *++v28 == 0;
            ++info.geometry_shader_name.m_string.m_end;
          }
          while ( !v12 );
        }
        *v29 = 0;
      }
    }
    m_begin = info.pixel_shader_name.m_string.m_begin;
    v31 = shader_config;
    if ( (vostok::render::shader_configuration *)info.pixel_shader_name.m_string.m_begin != shader_config )
    {
      info.pixel_shader_name.m_string.m_end = info.pixel_shader_name.m_string.m_begin;
      *info.pixel_shader_name.m_string.m_begin = 0;
      if ( shader_config )
      {
        m_begin = info.pixel_shader_name.m_string.m_end;
        if ( *(_BYTE *)&shader_config->0 )
        {
          do
          {
            if ( m_begin >= info.pixel_shader_name.m_string.m_max_end )
              break;
            *m_begin = (char)v31->0;
            m_begin = info.pixel_shader_name.m_string.m_end + 1;
            v31 = (vostok::render::shader_configuration *)((char *)v31 + 1);
            v12 = *(_BYTE *)&v31->0 == 0;
            ++info.pixel_shader_name.m_string.m_end;
          }
          while ( !v12 );
        }
        *m_begin = 0;
      }
    }
    M_finish = vs_name->m_shader_cache_info._M_impl._M_finish;
    info.configuration.configuration[0] = include_getter->configuration[0];
    info.configuration.configuration[1] = include_getter->configuration[1];
    if ( M_finish == vs_name->m_shader_cache_info._M_impl._M_end_of_storage._M_data )
    {
      stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info>>::_M_insert_overflow_aux(
        (stlp_std::priv::_Impl_vector<vostok::render::effect_compiler::shader_cache_info,vostok::vectora_allocator<vostok::render::effect_compiler::shader_cache_info> > *)m_begin,
        (int)&vs_name->m_shader_cache_info,
        M_finish,
        &info,
        (unsigned int)v40,
        v44);
      return vs_name;
    }
    else
    {
      if ( M_finish )
        vostok::render::effect_compiler::shader_cache_info::shader_cache_info(M_finish, &info);
      ++vs_name->m_shader_cache_info._M_impl._M_finish;
      return vs_name;
    }
  }
  else
  {
    vostok::render::state_descriptor::reset((vostok::render::state_descriptor *)this, (int)&vs_name->m_state_descriptor);
    v6 = vs_name->m_bindings.m_bindings._M_impl._M_finish;
    M_start = vs_name->m_bindings.m_bindings._M_impl._M_start;
    if ( M_start != v6 )
    {
      v8 = stlp_std::priv::__copy<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding *,int>(
             v6,
             M_start,
             vs_name->m_bindings.m_bindings._M_impl._M_finish);
      stlp_std::__destroy_range_aux<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
        v8,
        vs_name->m_bindings.m_bindings._M_impl._M_finish);
      vs_name->m_bindings.m_bindings._M_impl._M_finish = v8;
    }
    v36 = include_getter->configuration[0];
    m_shader_sources = vs_name->m_shader_sources;
    v38 = include_getter->configuration[1];
    v9 = vostok::render::resource_manager::create_xs_hw_impl<vostok::render::vs_data>(
           (vostok::render::resource_manager *)vs_name->m_shader_sources,
           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           gs_name,
           *(vostok::render::shader_configuration *)((char *)&v36 - 4),
           (vostok::render::shader_include_getter *)HIDWORD(include_getter->configuration[1]),
           v40);
    v10 = 0;
    if ( v9 )
    {
      ++v9->m_reference_count;
      v10 = (vostok::render::resource_manager *)v9;
    }
    m_object = vs_name->m_vs_hw.m_object;
    vs_name->m_vs_hw.m_object = (vostok::render::res_xs_hw<vostok::render::vs_data> *)v10;
    if ( m_object )
    {
      v12 = m_object->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
          v10,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          m_object);
    }
    v37 = include_getter->configuration[0];
    v34 = vs_name->m_shader_sources;
    v39 = include_getter->configuration[1];
    v13 = vostok::render::resource_manager::create_xs_hw_impl<vostok::render::gs_data>(
            (vostok::render::resource_manager *)ps_name,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            ps_name,
            *(vostok::render::shader_configuration *)((char *)&v37 - 4),
            (vostok::render::shader_include_getter *)HIDWORD(include_getter->configuration[1]),
            v41);
    v14 = 0;
    if ( v13 )
    {
      ++v13->m_reference_count;
      v14 = v13;
    }
    v15 = vs_name->m_gs_hw.m_object;
    vs_name->m_gs_hw.m_object = v14;
    if ( v15 )
    {
      v12 = v15->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v15);
    }
    *(unsigned __int64 *)((char *)v35.configuration + 4) = include_getter->configuration[0];
    *(_DWORD *)&v35.0 = vs_name->m_shader_sources;
    HIDWORD(v35.configuration[1]) = include_getter->configuration[1];
    v16 = vostok::render::resource_manager::create_xs_hw_impl<vostok::render::ps_data>(
            (vostok::render::resource_manager *)vs_name->m_shader_sources,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            (char *)shader_config,
            v35,
            (vostok::render::shader_include_getter *)HIDWORD(include_getter->configuration[1]),
            v42);
    v17 = 0;
    if ( v16 )
    {
      ++*(_DWORD *)&v16->_M_color;
      v17 = (vostok::render::resource_manager *)v16;
    }
    v18 = vs_name->m_ps_hw.m_object;
    vs_name->m_ps_hw.m_object = (vostok::render::res_xs_hw<vostok::render::ps_data> *)v17;
    if ( v18 )
    {
      v12 = v18->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v18);
    }
    v19 = vs_name->m_vs_hw.m_object;
    if ( v19
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::xs_descriptor<vostok::render::vs_data>::reset(&vs_name->m_vs_descriptor, v19);
    }
    else
    {
      v20 = vs_name->m_vs_descriptor.m_hardware_shader.m_object;
      vs_name->m_vs_descriptor.m_hardware_shader.m_object = 0;
      if ( v20 )
      {
        v12 = v20->m_reference_count-- == 1;
        if ( v12 )
          vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
            v17,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v20);
        if ( vs_name->m_vs_descriptor.m_hardware_shader.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::vs_data::operator=(
            (const vostok::render::vs_data *)4,
            &vs_name->m_vs_descriptor.m_shader_data);
        }
      }
    }
    v21 = vs_name->m_gs_hw.m_object;
    if ( v21
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::xs_descriptor<vostok::render::gs_data>::reset(&vs_name->m_gs_descriptor, v21);
    }
    else
    {
      v22 = vs_name->m_gs_descriptor.m_hardware_shader.m_object;
      vs_name->m_gs_descriptor.m_hardware_shader.m_object = 0;
      if ( v22 )
      {
        v12 = v22->m_reference_count-- == 1;
        if ( v12 )
          vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v22);
        if ( vs_name->m_gs_descriptor.m_hardware_shader.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::gs_data::operator=(
            (const vostok::render::gs_data *)4,
            &vs_name->m_gs_descriptor.m_shader_data);
        }
      }
    }
    v23 = vs_name->m_ps_hw.m_object;
    if ( v23
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::xs_descriptor<vostok::render::ps_data>::reset(&vs_name->m_ps_descriptor, v23);
    }
    else
    {
      v24 = vs_name->m_ps_descriptor.m_hardware_shader.m_object;
      vs_name->m_ps_descriptor.m_hardware_shader.m_object = 0;
      if ( v24 )
      {
        v12 = v24->m_reference_count-- == 1;
        if ( v12 )
          vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v24);
        if ( vs_name->m_ps_descriptor.m_hardware_shader.m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          vostok::render::gs_data::operator=(
            (const vostok::render::gs_data *)4,
            (vostok::render::gs_data *)&vs_name->m_ps_descriptor.m_shader_data);
        }
      }
    }
    if ( !vs_name->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        vs_name->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
        vs_name->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        vs_name->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
        vs_name->m_state_descriptor.m_depth_stencil_desc_updated = 1;
      }
    }
    vostok::render::effect_compiler::set_alpha_blend(
      D3D11_BLEND_ZERO,
      vs_name,
      0,
      D3D11_BLEND_ONE,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ZERO,
      D3D11_BLEND_OP_ADD,
      v43);
    return vs_name;
  }
}
