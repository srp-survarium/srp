void __thiscall vostok::render::effect_fstage_volume_cone_base_materials::compile(
        vostok::render::effect_fstage_volume_cone_base_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *config)
{
  vostok::render::custom_config_value *v3; // ecx
  vostok::render::custom_config_value *v4; // ecx
  const vostok::render::custom_config_value *v5; // eax
  vostok::render::custom_config_value *v6; // ecx
  vostok::render::custom_config_value *v7; // ecx
  const vostok::render::custom_config_value *v8; // eax
  vostok::render::custom_config_value *v9; // ecx
  vostok::render::custom_config_value *v10; // ecx
  const vostok::render::custom_config_value *v11; // eax
  vostok::render::custom_config_value *v12; // ecx
  vostok::render::custom_config_value *v13; // ecx
  const vostok::render::custom_config_value *v14; // eax
  vostok::render::custom_config_value *v15; // ecx
  vostok::strings::shared::profile *v16; // eax
  vostok::strings::shared::manager *v17; // ecx
  vostok::strings::shared::profile *v18; // eax
  vostok::render::custom_config_value *v19; // ecx
  const vostok::render::custom_config_value *v20; // eax
  vostok::render::custom_config_value *v21; // ecx
  const vostok::render::custom_config_value *v22; // eax
  vostok::render::custom_config_value *v23; // ecx
  const vostok::render::custom_config_value *v24; // eax
  vostok::render::custom_config_value *v25; // ecx
  const vostok::render::custom_config_value *v26; // eax
  vostok::render::custom_config_value *v27; // ecx
  vostok::strings::shared::manager *v28; // ecx
  vostok::strings::shared::profile *v29; // eax
  vostok::render::effect_constant_storage *v30; // ecx
  vostok::strings::shared::manager *v31; // ecx
  vostok::strings::shared::profile *v32; // eax
  vostok::render::effect_constant_storage *v33; // ecx
  vostok::render::effect_compiler *v34; // ecx
  vostok::render::effect_compiler *v35; // ecx
  vostok::shared_string v36; // [esp-4h] [ebp-54h]
  vostok::shared_string v37; // [esp-4h] [ebp-54h]
  vostok::shared_string v38; // [esp-4h] [ebp-54h]
  vostok::shared_string v39; // [esp-4h] [ebp-54h]
  const char *v40; // [esp+0h] [ebp-50h]
  bool v41; // [esp+0h] [ebp-50h]
  bool v42; // [esp+0h] [ebp-50h]
  bool v43; // [esp+0h] [ebp-50h]
  bool v44; // [esp+0h] [ebp-50h]
  vostok::render::shader_configuration *v45; // [esp+4h] [ebp-4Ch]
  float solid_transparency; // [esp+Ch] [ebp-44h] BYREF
  float v47; // [esp+10h] [ebp-40h] BYREF
  vostok::math::float3 v48; // [esp+14h] [ebp-3Ch] BYREF
  vostok::render::shader_configuration configuration; // [esp+20h] [ebp-30h] BYREF
  vostok::math::float4 source; // [esp+30h] [ebp-20h] BYREF
  vostok::math::float4 v51; // [esp+40h] [ebp-10h] BYREF

  *(_DWORD *)&configuration.0 = 0;
  *(unsigned __int64 *)((char *)configuration.configuration + 4) = 0x400000000LL;
  HIDWORD(configuration.configuration[1]) = 0;
  *(_BYTE *)&configuration.0 = (int)vostok::render::custom_config_value::operator[](
                                      (vostok::render::custom_config_value *)this,
                                      (int)config,
                                      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data
                             & 1;
  *((_BYTE *)&configuration.0 + 1) = (16
                                    * LOBYTE(vostok::render::custom_config_value::operator[](
                                               v3,
                                               (int)config,
                                               (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967DE4.destroyer)->data))
                                   & 0x10;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_966378.m_passes._M_t._M_header._M_data._M_parent,
    (const char *)&configuration,
    v40,
    v45);
  vostok::render::effect_compiler::set_cull_mode(compiler, D3D11_CULL_NONE);
  v5 = vostok::render::custom_config_value::operator[](
         v4,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_volume_color");
  vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v6, &v51, (int)v5);
  v8 = vostok::render::custom_config_value::operator[](
         v7,
         (int)config,
         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_volume_color_multiplier");
  solid_transparency = vostok::render::custom_config_value::operator<float> float(v9, (int)v8);
  v11 = vostok::render::custom_config_value::operator[](
          v10,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"move_direction");
  vostok::render::custom_config_value::operator<vostok::math::float3> vostok::math::float3(v12, &v48, (int)v11);
  v14 = vostok::render::custom_config_value::operator[](
          v13,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"uv_tile");
  source.w = vostok::render::custom_config_value::operator<float> float(v15, (int)v14);
  *(_QWORD *)&source.x = *(_QWORD *)&v48.x;
  source.z = v48.z;
  v16 = vostok::strings::shared::manager::string(
          s_manager.m_variable,
          s_manager.m_variable,
          "mode_direction_and_uv_tile");
  v36.m_pointer.m_object = 0;
  if ( v16 )
  {
    v36.m_pointer.m_object = v16;
    _InterlockedExchangeAdd(&v16->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&source,
    compiler,
    v36);
  source.x = v51.x * solid_transparency;
  source.y = v51.y * solid_transparency;
  source.z = v51.z * solid_transparency;
  source.w = v51.w;
  v18 = vostok::strings::shared::manager::string(v17, s_manager.m_variable, "volume_color");
  v37.m_pointer.m_object = 0;
  if ( v18 )
  {
    v37.m_pointer.m_object = v18;
    _InterlockedExchangeAdd(&v18->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float4>(
    (vostok::render::effect_constant_storage *)&source,
    compiler,
    v37);
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_position", "$user$position", 0, v41);
  if ( (*(_BYTE *)&configuration.0 & 1) != 0 )
  {
    v20 = vostok::render::custom_config_value::operator[](
            v19,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      (const char *)&stru_9642F8.m_desc.ArraySize,
      (char *)v20->data,
      0,
      v42);
  }
  vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_spot_falloff", "fx/spot_falloff", 0, v42);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    compiler,
    "t_sphere_falloff",
    (char *)&stru_9656C8.m_desc_valid,
    0,
    v43);
  if ( (*((_BYTE *)&configuration.0 + 1) & 0x10) != 0 )
  {
    v22 = vostok::render::custom_config_value::operator[](
            v21,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E3C);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_transparency", (char *)v22->data, 0, v44);
  }
  if ( vostok::render::custom_config_value::value_exists(&stru_967E64, (int)config) )
  {
    v24 = vostok::render::custom_config_value::operator[](
            v23,
            (int)config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967E64);
    solid_transparency = vostok::render::custom_config_value::operator<float> float(v25, (int)v24);
  }
  else
  {
    solid_transparency = *(float *)&clear_value;
  }
  v26 = vostok::render::custom_config_value::operator[](
          v23,
          (int)config,
          (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"attenuation_scale");
  v47 = vostok::render::custom_config_value::operator<float> float(v27, (int)v26);
  v29 = vostok::strings::shared::manager::string(v28, s_manager.m_variable, "attenuation_scale");
  v38.m_pointer.m_object = 0;
  if ( v29 )
  {
    v38.m_pointer.m_object = v29;
    v30 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v29->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&v47, v30, compiler, v38);
  v32 = vostok::strings::shared::manager::string(v31, s_manager.m_variable, (const char *)&stru_967E7C);
  v39.m_pointer.m_object = 0;
  if ( v32 )
  {
    v39.m_pointer.m_object = v32;
    v33 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v32->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&solid_transparency, v33, compiler, v39);
  vostok::render::effect_compiler::end_pass(
    v34,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v35, (int)compiler);
}
