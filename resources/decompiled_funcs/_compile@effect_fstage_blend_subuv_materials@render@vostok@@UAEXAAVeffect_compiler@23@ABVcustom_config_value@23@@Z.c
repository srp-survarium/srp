void __thiscall vostok::render::effect_fstage_blend_subuv_materials::compile(
        vostok::render::effect_fstage_blend_subuv_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  const vostok::render::custom_config_value *v5; // eax
  const vostok::render::custom_config_value *v6; // eax
  vostok::render::custom_config_value *v7; // ecx
  vostok::render::custom_config_value *v8; // ecx
  const vostok::render::custom_config_value *v9; // eax
  vostok::render::custom_config_value *v10; // ecx
  vostok::render::custom_config_value *v11; // ecx
  const vostok::render::custom_config_value *v12; // eax
  vostok::render::custom_config_value *v13; // ecx
  const vostok::render::custom_config_value *v14; // eax
  vostok::render::custom_config_value *v15; // ecx
  vostok::strings::shared::profile *v16; // eax
  vostok::render::effect_constant_storage *v17; // ecx
  vostok::strings::shared::manager *v18; // ecx
  vostok::strings::shared::profile *v19; // eax
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::shared_string v22; // [esp+50h] [ebp-34h]
  vostok::shared_string v23; // [esp+50h] [ebp-34h]
  const char *v24; // [esp+54h] [ebp-30h]
  bool v25; // [esp+54h] [ebp-30h]
  bool v26; // [esp+54h] [ebp-30h]
  bool v27; // [esp+54h] [ebp-30h]
  vostok::render::shader_configuration *v28; // [esp+58h] [ebp-2Ch]
  float source; // [esp+60h] [ebp-24h] BYREF
  char geometry_shader_name[4]; // [esp+64h] [ebp-20h] BYREF
  int v31; // [esp+68h] [ebp-1Ch]
  int v32; // [esp+6Ch] [ebp-18h]
  int v33; // [esp+70h] [ebp-14h]
  vostok::math::float4 si128; // [esp+74h] [ebp-10h] BYREF

  v32 = 4;
  *(_DWORD *)geometry_shader_name = 0;
  v31 = 0;
  v33 = 0;
  LOBYTE(v31) = 4
              * (((LOBYTE(vostok::render::custom_config_value::operator[](
                            (vostok::render::custom_config_value *)this,
                            (int)config,
                            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4)->data) != 0)
                + 1)
               & 3);
  geometry_shader_name[1] = (16
                           * LOBYTE(vostok::render::custom_config_value::operator[](
                                      v3,
                                      (int)config,
                                      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4.destroyer)->data))
                          & 0x10;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"forward_base_subuv",
    geometry_shader_name,
    v24,
    v28);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v25);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_particle_lighting",
    "$user$particle_lighting",
    0,
    v26);
  if ( (v31 & 0xC) == 8 )
  {
    v5 = vostok::render::custom_config_value::operator[](
           v4,
           (int)config,
           (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_emissive");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v5->data,
      0,
      v27);
  }
  v6 = vostok::render::custom_config_value::operator[](
         v4,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966774);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v7, &si128, (int)v6);
  v9 = vostok::render::custom_config_value::operator[](
         v8,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966754);
  source = vostok::render::custom_config_value::operator<float> float(v10, (int)v9);
  si128.x = si128.x * source;
  si128.y = si128.y * source;
  si128.z = si128.z * source;
  LODWORD(si128.w) = clear_value;
  si128 = (vostok::math::float4)_mm_load_si128((const __m128i *)&si128);
  if ( (geometry_shader_name[1] & 0x10) != 0 )
  {
    v12 = vostok::render::custom_config_value::operator[](
            v11,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_transparency", (char *)v12->data, 0, v27);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E64, (int)config) )
  {
    v14 = vostok::render::custom_config_value::operator[](
            v13,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E64);
    source = vostok::render::custom_config_value::operator<float> float(v15, (int)v14);
  }
  else
  {
    source = *(float *)&clear_value;
  }
  v16 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v13,
          s_manager.m_variable,
          (const char *)&stru_967E7C);
  v22.m_pointer.m_object = 0;
  if ( v16 )
  {
    v22.m_pointer.m_object = v16;
    v17 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&source, v17, compiler, v22);
  v19 = vostok::strings::shared::manager::string(v18, s_manager.m_variable, (const char *)&stru_961604);
  v23.m_pointer.m_object = 0;
  if ( v19 )
  {
    v23.m_pointer.m_object = v19;
    _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&si128,
    compiler,
    v23);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v20,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v21, (int)compiler);
}
