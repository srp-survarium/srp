void __userpurge vostok::render::effect_editor_show_overdraw::compile(
        vostok::render::effect_editor_show_overdraw *this@<ecx>,
        D3D11_STENCIL_OP a2@<edi>,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *__formal)
{
  unsigned int v4; // ecx
  vostok::math::float4 *v5; // edx
  double v6; // st4
  float v7; // xmm0_4
  unsigned __int64 v8; // xmm0_8
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_finish; // eax
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // ecx
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v11; // eax
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v12; // edi
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v13; // ecx
  vostok::render::res_pass **p_m_object; // esi
  vostok::render::res_pass *v15; // eax
  vostok::strings::shared::manager *v16; // ecx
  vostok::strings::shared::profile *v17; // eax
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::shared_string v20; // [esp-14h] [ebp-E4h]
  D3D11_STENCIL_OP v21; // [esp-10h] [ebp-E0h]
  float layer_index; // [esp+0h] [ebp-D0h]
  unsigned int layer_indexa; // [esp+0h] [ebp-D0h]
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v24; // [esp+4h] [ebp-CCh]
  unsigned int v25; // [esp+4h] [ebp-CCh]
  vostok::render::shader_configuration include_getter; // [esp+10h] [ebp-C0h] BYREF
  __int64 v27; // [esp+20h] [ebp-B0h]
  unsigned __int64 v28; // [esp+28h] [ebp-A8h]
  vostok::math::float4 overdraw_colors[10]; // [esp+30h] [ebp-A0h] BYREF

  v21 = a2;
  v4 = 0;
  v5 = overdraw_colors;
  do
  {
    v6 = ((double)v4 + 1.0) * 0.1;
    layer_index = v6;
    v7 = *(float *)&clear_value - layer_index;
    if ( v6 > 0.5 )
    {
      *((float *)include_getter.configuration + 1) = (float)(v7 * 0.0) + layer_index;
      *(float *)&include_getter.0 = v7 + layer_index;
      *(float *)&include_getter.configuration[1] = *((float *)include_getter.configuration + 1);
      *((float *)&include_getter.configuration[1] + 1) = v7 + layer_index;
      *(_QWORD *)&v5->x = include_getter.configuration[0];
      v8 = include_getter.configuration[1];
    }
    else
    {
      *((float *)&v28 + 1) = v7 + layer_index;
      *(float *)&v27 = (float)(v7 * 0.0) + layer_index;
      *((float *)&v27 + 1) = (float)(v7 * 0.25) + (float)(layer_index * 0.0);
      *(float *)&v28 = (float)(v7 * 0.0) + (float)(layer_index * 0.0);
      *(_QWORD *)&v5->x = v27;
      v8 = v28;
    }
    *(_QWORD *)&v5->elements[2] = v8;
    ++v4;
    ++v5;
  }
  while ( v4 < 0xA );
  layer_indexa = 0;
  include_getter.configuration[0] = 0;
  do
  {
    if ( !compiler->m_shaders_cache_mode )
    {
      M_finish = compiler->m_sh_technique.m_passes._M_impl._M_finish;
      M_start = compiler->m_sh_technique.m_passes._M_impl._M_start;
      if ( M_start != M_finish )
      {
        v11 = stlp_std::priv::__copy<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
                M_finish,
                M_start,
                compiler->m_sh_technique.m_passes._M_impl._M_finish);
        v12 = compiler->m_sh_technique.m_passes._M_impl._M_finish;
        v13 = v11;
        v24 = v11;
        p_m_object = &v11->m_object;
        if ( v11 != v12 )
        {
          do
          {
            v15 = *p_m_object;
            if ( *p_m_object )
            {
              if ( !--v15->m_reference_count )
              {
                vostok::render::effect_manager::delete_pass(
                  (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
                  *p_m_object);
                v13 = v24;
              }
            }
            ++p_m_object;
          }
          while ( p_m_object != (vostok::render::res_pass **)v12 );
        }
        compiler->m_sh_technique.m_passes._M_impl._M_finish = v13;
      }
      compiler->m_pass_idx = 0;
    }
    include_getter.configuration[1] = 4;
    vostok::render::effect_compiler::begin_pass(
      (vostok::render::effect_compiler *)&include_getter,
      compiler,
      (char *)&gs_name,
      0,
      (vostok::render::shader_configuration *)&stru_967C04.m_name.m_string.m_buffer[220],
      &include_getter);
    if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 0;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
        compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
      }
      if ( !compiler->m_shaders_cache_mode )
      {
        if ( s_no_effect_result.m_type == type_unset )
        {
          s_no_effect_result.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        }
        if ( s_no_effect_result.m_type == type_recursive )
          vostok::render::state_descriptor::set_alpha_blend(
            D3D11_BLEND_ZERO,
            D3D11_BLEND_OP_ADD,
            D3D11_BLEND_ZERO,
            D3D11_BLEND_OP_ADD,
            &compiler->m_state_descriptor,
            0,
            D3D11_BLEND_ONE,
            (D3D11_BLEND)v21);
      }
    }
    v25 = layer_indexa + 1;
    if ( layer_indexa == 9 )
      vostok::render::effect_compiler::set_stencil(
        compiler,
        D3D11_STENCIL_OP_KEEP,
        1,
        0xAu,
        0xFFu,
        0xFFu,
        D3D11_COMPARISON_LESS_EQUAL,
        D3D11_STENCIL_OP_KEEP,
        v21);
    else
      vostok::render::effect_compiler::set_stencil(
        compiler,
        D3D11_STENCIL_OP_KEEP,
        1,
        layer_indexa + 1,
        0xFFu,
        0xFFu,
        D3D11_COMPARISON_EQUAL,
        D3D11_STENCIL_OP_KEEP,
        v21);
    v17 = vostok::strings::shared::manager::string(
            v16,
            s_manager.m_variable,
            &stru_967C04.m_name.m_string.m_buffer[244]);
    v20.m_pointer.m_object = 0;
    if ( v17 )
    {
      v20.m_pointer.m_object = v17;
      _InterlockedExchangeAdd(&v17->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&overdraw_colors[layer_indexa],
      compiler,
      v20);
    vostok::render::effect_compiler::end_pass(
      v18,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    vostok::render::effect_compiler::end_technique(v19, (int)compiler);
    ++layer_indexa;
  }
  while ( v25 < 0xA );
}
