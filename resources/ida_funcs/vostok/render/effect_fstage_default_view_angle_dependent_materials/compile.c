void __thiscall vostok::render::effect_fstage_default_view_angle_dependent_materials::compile(
        vostok::render::effect_fstage_default_view_angle_dependent_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  char v4; // al
  vostok::render::custom_config_value *v5; // ecx
  char data; // al
  vostok::render::custom_config_value *v7; // ecx
  char v8; // al
  vostok::render::effect_compiler *v9; // ebx
  vostok::render::custom_config_value *v10; // ecx
  const vostok::render::custom_config_value *v11; // eax
  vostok::render::custom_config_value *v12; // ecx
  const vostok::render::custom_config_value *v13; // eax
  vostok::render::custom_config_value *v14; // ecx
  vostok::render::custom_config_value *v15; // ecx
  const vostok::render::custom_config_value *v16; // eax
  vostok::render::custom_config_value *v17; // ecx
  float v18; // xmm3_4
  vostok::render::custom_config_value *v19; // ecx
  const vostok::render::custom_config_value *v20; // eax
  vostok::render::custom_config_value *v21; // ecx
  vostok::strings::shared::manager *v22; // ecx
  vostok::strings::shared::profile *v23; // eax
  vostok::render::effect_constant_storage *v24; // ecx
  const vostok::render::custom_config_value *v25; // eax
  vostok::render::custom_config_value *v26; // ecx
  const vostok::render::custom_config_value *v27; // eax
  vostok::render::custom_config_value *v28; // ecx
  vostok::strings::shared::manager *v29; // ecx
  vostok::strings::shared::profile *v30; // eax
  vostok::render::effect_constant_storage *v31; // ecx
  vostok::strings::shared::manager *v32; // ecx
  vostok::strings::shared::profile *v33; // eax
  vostok::render::custom_config_value *v34; // ecx
  const vostok::render::custom_config_value *v35; // eax
  vostok::render::custom_config_value *v36; // ecx
  vostok::render::custom_config_value *v37; // ecx
  const vostok::render::custom_config_value *v38; // eax
  vostok::render::custom_config_value *v39; // ecx
  vostok::math::float2 *p_source; // edi
  vostok::strings::shared::manager *v41; // ecx
  vostok::strings::shared::profile *v42; // eax
  vostok::render::effect_compiler *v43; // ecx
  vostok::render::effect_compiler *v44; // ecx
  vostok::shared_string v45; // [esp+94h] [ebp-64h]
  vostok::shared_string v46; // [esp+94h] [ebp-64h]
  vostok::shared_string v47; // [esp+94h] [ebp-64h]
  vostok::shared_string v48; // [esp+94h] [ebp-64h]
  const char *v49; // [esp+98h] [ebp-60h]
  bool v50; // [esp+98h] [ebp-60h]
  vostok::render::shader_configuration *v51; // [esp+9Ch] [ebp-5Ch]
  vostok::math::float2 v52; // [esp+B0h] [ebp-48h] BYREF
  __m128i source; // [esp+B8h] [ebp-40h] BYREF
  char geometry_shader_name[4]; // [esp+C8h] [ebp-30h] BYREF
  int v55; // [esp+CCh] [ebp-2Ch]
  int v56; // [esp+D0h] [ebp-28h]
  int v57; // [esp+D4h] [ebp-24h]
  vostok::math::float4 v58; // [esp+D8h] [ebp-20h] BYREF
  vostok::math::float4 v59; // [esp+E8h] [ebp-10h] BYREF

  v56 = 4;
  *(_DWORD *)geometry_shader_name = 0;
  v55 = 0;
  v57 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_967DE4, (int)config) )
    v4 = (LOBYTE(vostok::render::custom_config_value::operator[](
                   v3,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4)->data) != 0)
       + 1;
  else
    v4 = 0;
  LOBYTE(v55) = 4 * (v4 & 3);
  if ( vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967DE4.destroyer,
         (int)config) )
  {
    data = (char)vostok::render::custom_config_value::operator[](
                   v5,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4.destroyer)->data;
  }
  else
  {
    data = 0;
  }
  geometry_shader_name[1] ^= (geometry_shader_name[1] ^ (16 * data)) & 0x10;
  if ( vostok::render::custom_config_value::value_exists(&stru_967E08, (int)config) )
    v8 = (char)vostok::render::custom_config_value::operator[](
                 v7,
                 (int)config,
                 (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E08)->data;
  else
    v8 = 0;
  v9 = compiler;
  HIBYTE(v56) ^= (HIBYTE(v56) ^ (4 * v8)) & 4;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"forward_view_angle_dependent",
    geometry_shader_name,
    v49,
    v51);
  v10 = (vostok::render::custom_config_value *)(unsigned __int8)v55;
  memset(&v58, 0, sizeof(v58));
  LODWORD(v52.x) = clear_value;
  if ( (v55 & 0xC) == 8 )
  {
    LOBYTE(v10) = v55 & 0xC;
    v11 = vostok::render::custom_config_value::operator[](
            v10,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_emissive");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v11->data,
      0,
      v50);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_966774, (int)config)
    && vostok::render::custom_config_value::value_exists(&stru_966754, (int)config) )
  {
    v13 = vostok::render::custom_config_value::operator[](
            v12,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966774);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v14, &v59, (int)v13);
    v16 = vostok::render::custom_config_value::operator[](
            v15,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966754);
    *(float *)source.m128i_i32 = vostok::render::custom_config_value::operator<float> float(v17, (int)v16);
    v18 = *(float *)source.m128i_i32;
    *(float *)source.m128i_i32 = v59.x * *(float *)source.m128i_i32;
    *(float *)&source.m128i_i32[1] = v59.y * v18;
    *(float *)&source.m128i_i32[2] = v59.z * v18;
    source.m128i_i32[3] = (int)clear_value;
    v58 = (vostok::math::float4)_mm_load_si128(&source);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_955728, (int)config) )
  {
    v20 = vostok::render::custom_config_value::operator[](
            v19,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_955728);
    *(float *)source.m128i_i32 = vostok::render::custom_config_value::operator<float> float(v21, (int)v20);
    v23 = vostok::strings::shared::manager::string(v22, s_manager.m_variable, (const char *)&stru_955728);
    v45.m_pointer.m_object = 0;
    if ( v23 )
    {
      v45.m_pointer.m_object = v23;
      v24 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v23->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>((const float *)source.m128i_i32, v24, compiler, v45);
    v9 = compiler;
  }
  if ( (geometry_shader_name[1] & 0x10) != 0 )
  {
    v25 = vostok::render::custom_config_value::operator[](
            v19,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, v9, "t_transparency", (char *)v25->data, 0, v50);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E64, (int)config) )
  {
    if ( vostok::render::custom_config_value::value_exists(&stru_967E64, (int)config) )
    {
      v27 = vostok::render::custom_config_value::operator[](
              v26,
              (int)config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E64);
      v52.x = vostok::render::custom_config_value::operator<float> float(v28, (int)v27);
    }
    else
    {
      LODWORD(v52.x) = clear_value;
    }
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E7C, (int)config) )
  {
    v30 = vostok::strings::shared::manager::string(v29, s_manager.m_variable, (const char *)&stru_967E7C);
    v46.m_pointer.m_object = 0;
    if ( v30 )
    {
      v46.m_pointer.m_object = v30;
      v31 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v30->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>(&v52.x, v31, compiler, v46);
    v9 = compiler;
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_961604, (int)config) )
  {
    v33 = vostok::strings::shared::manager::string(v32, s_manager.m_variable, (const char *)&stru_961604);
    v47.m_pointer.m_object = 0;
    if ( v33 )
    {
      v47.m_pointer.m_object = v33;
      _InterlockedExchangeAdd(&v33->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&v58,
      compiler,
      v47);
    v9 = compiler;
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E90, (int)config)
    && vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967E90.destroyer,
         (int)config) )
  {
    v35 = vostok::render::custom_config_value::operator[](
            v34,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E90.destroyer);
    *(float *)source.m128i_i32 = vostok::render::custom_config_value::operator<float> float(v36, (int)v35);
    v38 = vostok::render::custom_config_value::operator[](
            v37,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E90);
    v52.x = vostok::render::custom_config_value::operator<float> float(v39, (int)v38);
    v52.y = *(float *)source.m128i_i32;
    p_source = &v52;
    v42 = vostok::strings::shared::manager::string(v41, s_manager.m_variable, "constant_tile_uv");
  }
  else
  {
    source.m128i_i32[0] = (int)clear_value;
    source.m128i_i32[1] = (int)clear_value;
    p_source = (vostok::math::float2 *)&source;
    v42 = vostok::strings::shared::manager::string(
            (vostok::strings::shared::manager *)v34,
            s_manager.m_variable,
            "constant_tile_uv");
  }
  v48.m_pointer.m_object = 0;
  if ( v42 )
  {
    v48.m_pointer.m_object = v42;
    _InterlockedExchangeAdd(&v42->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float2>(
    (vostok::render::effect_constant_storage *)p_source,
    v9,
    v48);
  if ( (v56 & 0x4000000) != 0 )
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, v9, "t_position", "$user$position", 0, v50);
  vostok::render::effect_compiler::set_cull_mode(v9, D3D11_CULL_BACK);
  vostok::render::effect_compiler::end_pass(
    v43,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v9);
  vostok::render::effect_compiler::end_technique(v44, (int)v9);
}
