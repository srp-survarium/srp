void __thiscall vostok::render::decal_default_material_effect::compile(
        vostok::render::decal_default_material_effect *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  const vostok::render::custom_config_value *v3; // esi
  vostok::render::custom_config_value *v5; // ecx
  char v6; // bl
  char data; // al
  vostok::render::custom_config_value *v8; // ecx
  bool v9; // al
  bool v10; // zf
  D3D11_CULL_MODE v11; // eax
  vostok::render::custom_config_value *v12; // ecx
  const vostok::render::custom_config_value *v13; // eax
  vostok::render::custom_config_value *v14; // ecx
  const vostok::render::custom_config_value *v15; // eax
  vostok::render::custom_config_value *v16; // ecx
  vostok::strings::shared::manager *v17; // ecx
  vostok::strings::shared::profile *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  const vostok::render::custom_config_value *v20; // eax
  vostok::strings::shared::manager *v21; // ecx
  __int64 v22; // xmm0_8
  float v23; // eax
  vostok::strings::shared::profile *v24; // eax
  vostok::render::custom_config_value *v25; // ecx
  const vostok::render::custom_config_value *v26; // eax
  vostok::render::custom_config_value *v27; // ecx
  vostok::strings::shared::manager *v28; // ecx
  vostok::strings::shared::profile *v29; // eax
  vostok::render::effect_constant_storage *v30; // ecx
  const float *v31; // eax
  vostok::strings::shared::profile *v32; // eax
  vostok::render::custom_config_value *v33; // ecx
  const vostok::render::custom_config_value *v34; // eax
  vostok::render::custom_config_value *v35; // ecx
  vostok::strings::shared::manager *v36; // ecx
  vostok::strings::shared::profile *v37; // eax
  vostok::render::effect_constant_storage *v38; // ecx
  vostok::render::custom_config_value *v39; // ecx
  const vostok::render::custom_config_value *v40; // eax
  vostok::render::custom_config_value *v41; // ecx
  vostok::strings::shared::manager *v42; // ecx
  vostok::strings::shared::profile *v43; // eax
  vostok::render::effect_constant_storage *v44; // ecx
  const vostok::render::custom_config_value *v45; // eax
  vostok::render::custom_config_value *v46; // ecx
  vostok::render::custom_config_value *v47; // ecx
  float v48; // xmm0_4
  vostok::strings::shared::profile *v49; // eax
  vostok::render::effect_constant_storage *v50; // ecx
  const vostok::render::custom_config_value *v51; // eax
  vostok::render::effect_compiler *v52; // ecx
  vostok::shared_string v53; // [esp+88h] [ebp-74h]
  vostok::shared_string v54; // [esp+88h] [ebp-74h]
  vostok::shared_string v55; // [esp+88h] [ebp-74h]
  vostok::shared_string v56; // [esp+88h] [ebp-74h]
  vostok::shared_string v57; // [esp+88h] [ebp-74h]
  vostok::shared_string v58; // [esp+88h] [ebp-74h]
  const char *v59; // [esp+8Ch] [ebp-70h]
  D3D11_STENCIL_OP v60; // [esp+8Ch] [ebp-70h]
  D3D11_STENCIL_OP v61; // [esp+8Ch] [ebp-70h]
  D3D11_BLEND v62; // [esp+8Ch] [ebp-70h]
  bool v63; // [esp+8Ch] [ebp-70h]
  vostok::render::shader_configuration *v64; // [esp+90h] [ebp-6Ch]
  float v65; // [esp+9Ch] [ebp-60h] BYREF
  int v66; // [esp+A0h] [ebp-5Ch]
  vostok::command_line::key_initializator predicate[4]; // [esp+A4h] [ebp-58h]
  vostok::command_line::key_initializator v68[4]; // [esp+A8h] [ebp-54h]
  vostok::command_line::key_initializator v69[4]; // [esp+ACh] [ebp-50h]
  vostok::render::decal_default_material_effect *v70; // [esp+B0h] [ebp-4Ch]
  vostok::command_line::key_initializator v71[4]; // [esp+B4h] [ebp-48h]
  float v72; // [esp+B8h] [ebp-44h] BYREF
  float v73; // [esp+BCh] [ebp-40h] BYREF
  vostok::math::float3 v74; // [esp+C0h] [ebp-3Ch] BYREF
  char geometry_shader_name[4]; // [esp+CCh] [ebp-30h] BYREF
  int v76; // [esp+D0h] [ebp-2Ch]
  int v77; // [esp+D4h] [ebp-28h]
  int v78; // [esp+D8h] [ebp-24h]
  vostok::math::float4 v79; // [esp+DCh] [ebp-20h] BYREF
  vostok::math::float4 source; // [esp+ECh] [ebp-10h] BYREF

  v3 = config;
  v77 = 4;
  *(_DWORD *)geometry_shader_name = 0;
  v76 = 0;
  v78 = 0;
  v70 = this;
  v6 = (int)vostok::render::custom_config_value::operator[](
              (vostok::render::custom_config_value *)this,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data
     & 1;
  if ( this->m_is_forward )
    data = 0;
  else
    data = (char)vostok::render::custom_config_value::operator[](
                   v5,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967F04)->data;
  geometry_shader_name[0] = (v6 ^ (8 * data)) & 8 ^ v6;
  v9 = vostok::render::custom_config_value::value_exists(&stru_9687D4, (int)config)
    && LOBYTE(vostok::render::custom_config_value::operator[](
                v8,
                (int)config,
                (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9687D4)->data) != 0;
  v10 = !this->m_is_forward;
  LOBYTE(v76) = v76 & 0xFC | v9 & 3 | 0x80;
  BYTE1(v76) ^= (BYTE1(v76) ^ !v10) & 3;
  v66 = 0;
  while ( 1 )
  {
    vostok::render::effect_material_base::compile_begin(
      compiler,
      v3,
      (vostok::render::effect_material_base *)&stru_966284,
      (vostok::render::shader_configuration *)"decal_base",
      geometry_shader_name,
      v59,
      v64);
    if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        predicate[0] = 0;
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
    }
    vostok::render::effect_compiler::set_stencil(
      compiler,
      D3D11_STENCIL_OP_KEEP,
      0,
      0,
      0,
      0,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_KEEP,
      v60);
    if ( v66 )
    {
      if ( !compiler->m_shaders_cache_mode )
      {
        if ( s_no_effect_result.m_type == type_unset )
        {
          v69[0] = 0;
          s_no_effect_result.m_type = type_recursive;
          vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
        }
        if ( s_no_effect_result.m_type == type_recursive )
        {
          v11 = D3D11_CULL_FRONT;
          goto LABEL_25;
        }
      }
    }
    else if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        v68[0] = 0;
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        v11 = D3D11_CULL_BACK;
LABEL_25:
        v10 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == v11;
        compiler->m_state_descriptor.m_rasterizer_desc.CullMode = v11;
        compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v10;
      }
    }
    vostok::render::effect_compiler::set_stencil(
      compiler,
      D3D11_STENCIL_OP_KEEP,
      1,
      0,
      0xFFu,
      0,
      D3D11_COMPARISON_NOT_EQUAL,
      D3D11_STENCIL_OP_KEEP,
      v61);
    if ( !v70->m_is_forward && !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        v71[0] = 0;
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
        vostok::render::state_descriptor::set_alpha_blend(
          D3D11_BLEND_INV_SRC_ALPHA,
          D3D11_BLEND_OP_ADD,
          D3D11_BLEND_ONE,
          D3D11_BLEND_OP_ADD,
          &compiler->m_state_descriptor,
          1,
          D3D11_BLEND_SRC_ALPHA,
          v62);
    }
    if ( (geometry_shader_name[0] & 1) != 0 )
    {
      v13 = vostok::render::custom_config_value::operator[](
              v12,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        &stru_963F84.m_name.m_string.m_buffer[116],
        (char *)v13->data,
        0,
        v62);
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_967F74, (int)config) )
    {
      v15 = vostok::render::custom_config_value::operator[](
              v14,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967F74);
      vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v16, &v79, (int)v15);
      source = (vostok::math::float4)_mm_load_si128((const __m128i *)&v79);
      v18 = vostok::strings::shared::manager::string(v17, s_manager.m_variable, (const char *)&stru_967F74);
      v53.m_pointer.m_object = 0;
      if ( v18 )
      {
        v53.m_pointer.m_object = v18;
        _InterlockedExchangeAdd(&v18->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&source,
        compiler,
        v53);
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_9693AC, (int)config) )
    {
      v20 = vostok::render::custom_config_value::operator[](
              v19,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9693AC);
      if ( (`vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' & 1) == 0 )
      {
        `vostok::render::static_type::get_type_id<char const *>'::`2'::`local static guard' |= 1u;
        LOWORD(v21) = vostok::render::static_type::type_id_counter + 1;
        vostok::render::static_type::type_id_counter = (unsigned __int16)v21;
        LOWORD(`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id) = (_WORD)v21;
      }
      if ( v20->type == (_WORD)`vostok::render::static_type::get_type_id<char const *>'::`2'::current_id )
      {
        v22 = *(_QWORD *)&v20->data;
        v23 = *(float *)&v20->type;
      }
      else
      {
        v22 = *(_QWORD *)v20->data;
        v23 = *((float *)v20->data + 2);
      }
      v74.z = v23;
      *(_QWORD *)&v74.x = v22;
      v24 = vostok::strings::shared::manager::string(v21, s_manager.m_variable, "constant_normal_multiplier");
      v54.m_pointer.m_object = 0;
      if ( v24 )
      {
        v54.m_pointer.m_object = v24;
        _InterlockedExchangeAdd(&v24->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(&v74, compiler, v54);
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_9693DC, (int)config) )
    {
      v26 = vostok::render::custom_config_value::operator[](
              v25,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9693DC);
      v72 = vostok::render::custom_config_value::operator<float> float(v27, (int)v26);
      v29 = vostok::strings::shared::manager::string(v28, s_manager.m_variable, (const char *)&stru_9693DC);
      v55.m_pointer.m_object = 0;
      if ( v29 )
      {
        v55.m_pointer.m_object = v29;
        v30 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v29->m_reference_count, 1u);
      }
      v31 = &v72;
    }
    else
    {
      v73 = 0.0;
      v32 = vostok::strings::shared::manager::string(
              (vostok::strings::shared::manager *)v25,
              s_manager.m_variable,
              (const char *)&stru_9693DC);
      v55.m_pointer.m_object = 0;
      if ( v32 )
      {
        v55.m_pointer.m_object = v32;
        v30 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v32->m_reference_count, 1u);
      }
      v31 = &v73;
    }
    vostok::render::effect_compiler::set_constant<float>(v31, v30, compiler, v55);
    if ( vostok::render::custom_config_value::value_exists(&stru_9693F8, (int)config) )
    {
      v34 = vostok::render::custom_config_value::operator[](
              v33,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9693F8);
      v72 = vostok::render::custom_config_value::operator<float> float(v35, (int)v34);
      v37 = vostok::strings::shared::manager::string(v36, s_manager.m_variable, (const char *)&stru_9693F8);
      v56.m_pointer.m_object = 0;
      if ( v37 )
      {
        v56.m_pointer.m_object = v37;
        v38 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v37->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<float>(&v72, v38, compiler, v56);
    }
    if ( vostok::render::custom_config_value::value_exists(&stru_96940C, (int)config) )
    {
      v40 = vostok::render::custom_config_value::operator[](
              v39,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_96940C);
      v72 = vostok::render::custom_config_value::operator<float> float(v41, (int)v40);
      v43 = vostok::strings::shared::manager::string(v42, s_manager.m_variable, (const char *)&stru_96940C);
      v57.m_pointer.m_object = 0;
      if ( v43 )
      {
        v57.m_pointer.m_object = v43;
        v44 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v43->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<float>(&v72, v44, compiler, v57);
    }
    if ( (geometry_shader_name[0] & 8) != 0 )
    {
      v45 = vostok::render::custom_config_value::operator[](
              v39,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_normal");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        (const char *)&stru_96940C.destroyer,
        (char *)v45->data,
        0,
        v62);
    }
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v62);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, v63);
    if ( vostok::render::custom_config_value::value_exists(&stru_96942C, (int)config) )
    {
      if ( vostok::render::custom_config_value::value_exists(&stru_96942C, (int)config)
        && LOBYTE(vostok::render::custom_config_value::operator[](
                    v47,
                    (int)config,
                    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_96942C)->data) )
      {
        v48 = *(float *)&clear_value;
      }
      else
      {
        v48 = -1.0;
      }
      v65 = v48;
      v49 = vostok::strings::shared::manager::string(
              (vostok::strings::shared::manager *)v47,
              s_manager.m_variable,
              (const char *)&stru_96942C);
      v58.m_pointer.m_object = 0;
      if ( v49 )
      {
        v58.m_pointer.m_object = v49;
        v50 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v49->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<float>(&v65, v50, compiler, v58);
    }
    if ( (v76 & 3) != 0 )
    {
      v51 = vostok::render::custom_config_value::operator[](
              v46,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_cubemap");
      vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_cubemap", (char *)v51->data, 0, (bool)v59);
    }
    vostok::render::effect_compiler::end_pass(
      (vostok::render::effect_compiler *)v46,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    vostok::render::effect_compiler::end_technique(v52, (int)compiler);
    if ( (unsigned int)++v66 >= 2 )
      break;
    v3 = config;
  }
}
