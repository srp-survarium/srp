void __thiscall vostok::render::effect_fstage_default_materials::compile(
        vostok::render::effect_fstage_default_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  char data; // al
  vostok::render::custom_config_value *v6; // ecx
  const vostok::render::custom_config_value *v7; // eax
  const vostok::render::custom_config_value *v8; // eax
  vostok::render::custom_config_value *v9; // ecx
  vostok::render::custom_config_value *v10; // ecx
  const vostok::render::custom_config_value *v11; // eax
  vostok::render::custom_config_value *v12; // ecx
  vostok::render::custom_config_value *v13; // ecx
  const vostok::render::custom_config_value *v14; // eax
  vostok::render::custom_config_value *v15; // ecx
  const vostok::render::custom_config_value *v16; // eax
  vostok::render::custom_config_value *v17; // ecx
  vostok::strings::shared::profile *v18; // eax
  vostok::render::effect_constant_storage *v19; // ecx
  vostok::strings::shared::manager *v20; // ecx
  vostok::strings::shared::profile *v21; // eax
  vostok::render::custom_config_value *v22; // ecx
  const vostok::render::custom_config_value *v23; // eax
  vostok::render::custom_config_value *v24; // ecx
  vostok::render::custom_config_value *v25; // ecx
  const vostok::render::custom_config_value *v26; // eax
  vostok::render::custom_config_value *v27; // ecx
  vostok::strings::shared::profile *v28; // eax
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::shared_string v31; // [esp+50h] [ebp-34h]
  vostok::shared_string v32; // [esp+50h] [ebp-34h]
  vostok::shared_string v33; // [esp+50h] [ebp-34h]
  const char *v34; // [esp+54h] [ebp-30h]
  bool v35; // [esp+54h] [ebp-30h]
  bool v36; // [esp+54h] [ebp-30h]
  bool v37; // [esp+54h] [ebp-30h]
  vostok::render::shader_configuration *v38; // [esp+58h] [ebp-2Ch]
  vostok::render::data_indexer *source; // [esp+60h] [ebp-24h] BYREF
  vostok::render::effect_constant_storage geometry_shader_name; // [esp+64h] [ebp-20h] BYREF
  vostok::math::float4 si128; // [esp+74h] [ebp-10h] BYREF

  geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data = (vostok::render::data_indexer *)4;
  geometry_shader_name.m_indexers._M_impl._M_start = 0;
  geometry_shader_name.m_indexers._M_impl._M_finish = 0;
  geometry_shader_name.m_constant_buffer = 0;
  LOBYTE(geometry_shader_name.m_indexers._M_impl._M_finish) = 4
                                                            * (((LOBYTE(vostok::render::custom_config_value::operator[](
                                                                          (vostok::render::custom_config_value *)this,
                                                                          (int)config,
                                                                          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4)->data) != 0)
                                                              + 1)
                                                             & 3);
  BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) = (16
                                                           * LOBYTE(vostok::render::custom_config_value::operator[](
                                                                      v3,
                                                                      (int)config,
                                                                      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4.destroyer)->data))
                                                          & 0x10;
  if ( vostok::render::custom_config_value::value_exists(&stru_967E08, (int)config) )
    data = (char)vostok::render::custom_config_value::operator[](
                   v4,
                   (int)config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E08)->data;
  else
    data = 0;
  HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data) ^= (HIBYTE(geometry_shader_name.m_indexers._M_impl._M_end_of_storage._M_data)
                                                                              ^ (4 * data))
                                                                             & 4;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_967E08.destroyer,
    (const char *)&geometry_shader_name,
    v34,
    v38);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v35);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    v36);
  if ( ((int)geometry_shader_name.m_indexers._M_impl._M_finish & 0xC) == 8 )
  {
    v7 = vostok::render::custom_config_value::operator[](
           v6,
           (int)config,
           (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_emissive");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v7->data,
      0,
      v37);
  }
  v8 = vostok::render::custom_config_value::operator[](
         v6,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966774);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v9, &si128, (int)v8);
  v11 = vostok::render::custom_config_value::operator[](
          v10,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966754);
  *(float *)&source = vostok::render::custom_config_value::operator<float> float(v12, (int)v11);
  si128.x = si128.x * *(float *)&source;
  si128.y = si128.y * *(float *)&source;
  si128.z = si128.z * *(float *)&source;
  LODWORD(si128.w) = clear_value;
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  if ( (BYTE1(geometry_shader_name.m_indexers._M_impl._M_start) & 0x10) != 0 )
  {
    v14 = vostok::render::custom_config_value::operator[](
            v13,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_transparency", (char *)v14->data, 0, v37);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E64, (int)config) )
  {
    v16 = vostok::render::custom_config_value::operator[](
            v15,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E64);
    *(float *)&source = vostok::render::custom_config_value::operator<float> float(v17, (int)v16);
  }
  else
  {
    source = (vostok::render::data_indexer *)clear_value;
  }
  v18 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v15,
          s_manager.m_variable,
          (const char *)&stru_967E7C);
  v31.m_pointer.m_object = 0;
  if ( v18 )
  {
    v31.m_pointer.m_object = v18;
    v19 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v18->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>((const float *)&source, v19, compiler, v31);
  v21 = vostok::strings::shared::manager::string(v20, s_manager.m_variable, (const char *)&stru_961604);
  v32.m_pointer.m_object = 0;
  if ( v21 )
  {
    v32.m_pointer.m_object = v21;
    _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v32);
  if ( vostok::render::custom_config_value::value_exists(&stru_967E90, (int)config)
    && vostok::render::custom_config_value::value_exists(
         (vostok::render::custom_config_value *)&stru_967E90.destroyer,
         (int)config) )
  {
    v23 = vostok::render::custom_config_value::operator[](
            v22,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E90.destroyer);
    *(float *)&source = vostok::render::custom_config_value::operator<float> float(v24, (int)v23);
    v26 = vostok::render::custom_config_value::operator[](
            v25,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E90);
    *(float *)&geometry_shader_name.m_indexers._M_impl._M_start = vostok::render::custom_config_value::operator<float> float(
                                                                    v27,
                                                                    (int)v26);
    geometry_shader_name.m_indexers._M_impl._M_finish = source;
  }
  else
  {
    geometry_shader_name.m_indexers._M_impl._M_start = (vostok::render::data_indexer *)clear_value;
    geometry_shader_name.m_indexers._M_impl._M_finish = (vostok::render::data_indexer *)clear_value;
  }
  v28 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v22,
          s_manager.m_variable,
          "constant_tile_uv");
  v33.m_pointer.m_object = 0;
  if ( v28 )
  {
    v33.m_pointer.m_object = v28;
    _InterlockedExchangeAdd(&v28->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float2>(&geometry_shader_name, compiler, v33);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v29,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v30, (int)compiler);
}
