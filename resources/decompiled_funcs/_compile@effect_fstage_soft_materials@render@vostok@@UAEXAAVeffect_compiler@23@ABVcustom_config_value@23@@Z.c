void __thiscall vostok::render::effect_fstage_soft_materials::compile(
        vostok::render::effect_fstage_soft_materials *this,
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
  vostok::strings::shared::manager *v16; // ecx
  vostok::strings::shared::profile *v17; // eax
  vostok::render::effect_constant_storage *v18; // ecx
  vostok::strings::shared::manager *v19; // ecx
  vostok::strings::shared::profile *v20; // eax
  vostok::render::custom_config_value *v21; // ecx
  const vostok::render::custom_config_value *v22; // eax
  vostok::render::custom_config_value *v23; // ecx
  vostok::strings::shared::manager *v24; // ecx
  vostok::strings::shared::profile *v25; // eax
  vostok::render::effect_constant_storage *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::shared_string v29; // [esp+70h] [ebp-44h]
  vostok::shared_string v30; // [esp+70h] [ebp-44h]
  vostok::shared_string v31; // [esp+70h] [ebp-44h]
  const char *v32; // [esp+74h] [ebp-40h]
  bool v33; // [esp+74h] [ebp-40h]
  vostok::render::shader_configuration *v34; // [esp+78h] [ebp-3Ch]
  float source; // [esp+80h] [ebp-34h] BYREF
  char geometry_shader_name[4]; // [esp+84h] [ebp-30h] BYREF
  int v37; // [esp+88h] [ebp-2Ch]
  int v38; // [esp+8Ch] [ebp-28h]
  int v39; // [esp+90h] [ebp-24h]
  __m128i v40; // [esp+94h] [ebp-20h] BYREF
  vostok::math::float4 v41; // [esp+A4h] [ebp-10h] BYREF

  v38 = 4;
  *(_DWORD *)geometry_shader_name = 0;
  v37 = 0;
  v39 = 0;
  LOBYTE(v37) = 4
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
    (vostok::render::shader_configuration *)&stru_9662C0.m_effects._M_impl._M_end_of_storage,
    geometry_shader_name,
    v32,
    v34);
  if ( (v37 & 0xC) == 8 )
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
      v33);
  }
  v6 = vostok::render::custom_config_value::operator[](
         v4,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966774);
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v7, &v41, (int)v6);
  v9 = vostok::render::custom_config_value::operator[](
         v8,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966754);
  *(float *)&v40.m128i_i32[3] = vostok::render::custom_config_value::operator<float> float(v10, (int)v9);
  v40.m128i_i64[0] = *(_QWORD *)&v41.x;
  v40.m128i_i32[2] = LODWORD(v41.z);
  v41 = (vostok::math::float4)_mm_load_si128(&v40);
  if ( (geometry_shader_name[1] & 0x10) != 0 )
  {
    v12 = vostok::render::custom_config_value::operator[](
            v11,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_transparency", (char *)v12->data, 0, v33);
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
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v33);
  v17 = vostok::strings::shared::manager::string(v16, s_manager.m_variable, (const char *)&stru_967E7C);
  v29.m_pointer.m_object = 0;
  if ( v17 )
  {
    v29.m_pointer.m_object = v17;
    v18 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v17->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&source, v18, compiler, v29);
  v20 = vostok::strings::shared::manager::string(v19, s_manager.m_variable, (const char *)&stru_961604);
  v30.m_pointer.m_object = 0;
  if ( v20 )
  {
    v30.m_pointer.m_object = v20;
    _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&v41,
    compiler,
    v30);
  if ( vostok::render::custom_config_value::value_exists(&stru_968620, (int)config) )
  {
    v22 = vostok::render::custom_config_value::operator[](
            v21,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_968620);
    source = vostok::render::custom_config_value::operator<float> float(v23, (int)v22);
    v25 = vostok::strings::shared::manager::string(v24, s_manager.m_variable, "soft_distance");
    v31.m_pointer.m_object = 0;
    if ( v25 )
    {
      v31.m_pointer.m_object = v25;
      v26 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v25->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<float>(&source, v26, compiler, v31);
  }
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  vostok::render::effect_compiler::end_pass(
    v27,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v28, (int)compiler);
}
