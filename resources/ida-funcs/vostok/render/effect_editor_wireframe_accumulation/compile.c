void __userpurge vostok::render::effect_editor_wireframe_accumulation::compile(
        vostok::render::effect_editor_wireframe_accumulation *this@<ecx>,
        vostok::render::shader_configuration *a2@<edi>,
        const vostok::configs::binary_config_value *a3@<esi>,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  unsigned int *p_id_crc; // eax
  int v7; // ecx
  float *v8; // edi
  unsigned int vertex_input_type; // ebx
  vostok::render::effect_compiler *v10; // ecx
  vostok::command_line::key *v11; // ecx
  vostok::render::effect_constant_storage *v12; // ecx
  vostok::command_line::key *v13; // ecx
  vostok::render::effect_material_base *v14; // ecx
  vostok::configs::binary_config_value *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::command_line::key *v17; // ecx
  vostok::command_line::key *v18; // ecx
  vostok::render::effect_constant_storage *v19; // ecx
  vostok::render::effect_material_base *v20; // ecx
  D3D11_COMPARISON_FUNC v22; // [esp-Ch] [ebp-E8h]
  vostok::render::shader_configuration *v23; // [esp-Ch] [ebp-E8h]
  D3D11_COMPARISON_FUNC v24; // [esp-Ch] [ebp-E8h]
  const vostok::configs::binary_config_value *v25; // [esp-8h] [ebp-E4h]
  vostok::configs::binary_config_value v26[2]; // [esp+14h] [ebp-C8h] BYREF
  float v27; // [esp+48h] [ebp-94h]
  float v28; // [esp+4Ch] [ebp-90h]
  float v29; // [esp+50h] [ebp-8Ch]
  float v30; // [esp+54h] [ebp-88h]
  float v31; // [esp+58h] [ebp-84h]
  float v32; // [esp+5Ch] [ebp-80h]
  float v33; // [esp+60h] [ebp-7Ch]
  float v34; // [esp+64h] [ebp-78h]
  float v35; // [esp+68h] [ebp-74h]
  float v36; // [esp+6Ch] [ebp-70h]
  float v37; // [esp+70h] [ebp-6Ch]
  float v38; // [esp+74h] [ebp-68h]
  float v39; // [esp+78h] [ebp-64h]
  float v40; // [esp+7Ch] [ebp-60h]
  float v41; // [esp+80h] [ebp-5Ch]
  float v42; // [esp+84h] [ebp-58h]
  float v43; // [esp+88h] [ebp-54h]
  float v44; // [esp+8Ch] [ebp-50h]
  float v45; // [esp+90h] [ebp-4Ch]
  float v46; // [esp+94h] [ebp-48h]
  float v47; // [esp+98h] [ebp-44h]
  float v48; // [esp+A8h] [ebp-34h]
  float v49; // [esp+ACh] [ebp-30h]
  float v50; // [esp+B0h] [ebp-2Ch]
  float v51; // [esp+C0h] [ebp-1Ch]
  float v52; // [esp+C4h] [ebp-18h]
  float v53; // [esp+C8h] [ebp-14h]

  v26[0].id.max_storage = 0x80000;
  v26[0].data.max_storage = 0;
  p_id_crc = &v26[0].id_crc;
  v7 = 15;
  do
  {
    *p_id_crc = 0;
    p_id_crc[1] = LODWORD(c_anim_center);
    v8 = (float *)(p_id_crc + 2);
    p_id_crc += 3;
    --v7;
    *v8 = c_anim_center;
  }
  while ( v7 );
  v27 = c_anim_center;
  v28 = FLOAT_0_1;
  v29 = FLOAT_0_75;
  v30 = c_anim_center;
  v31 = FLOAT_0_1;
  v32 = FLOAT_0_75;
  v33 = c_anim_center;
  v34 = FLOAT_0_1;
  v35 = FLOAT_0_75;
  v36 = c_anim_center;
  v37 = FLOAT_0_1;
  v38 = FLOAT_0_75;
  v45 = s_bm_current_air_resistance;
  v46 = FLOAT_0_25;
  v47 = FLOAT_0_25;
  v42 = s_bm_current_air_resistance;
  v43 = FLOAT_0_25;
  v44 = FLOAT_0_25;
  v39 = s_bm_current_air_resistance;
  v40 = FLOAT_0_25;
  v41 = FLOAT_0_25;
  v48 = FLOAT_0_1;
  v49 = FLOAT_0_75;
  vertex_input_type = parameters->vertex_input_type;
  v50 = FLOAT_0_1;
  v51 = FLOAT_0_69999999;
  v52 = c_anim_center;
  v53 = FLOAT_0_1;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v26,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "editor_wireframe_accumulation",
    compiler,
    (const char *)v26,
    config,
    a2,
    a3);
  vostok::render::effect_compiler::set_depth(v10, (int)compiler, 1, 1, v22);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v11);
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)&v26[0].id_crc + vertex_input_type,
    v12,
    compiler,
    "wireframe_color");
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v13);
  vostok::render::effect_material_base::compile_end(v14, compiler);
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v15,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "editor_wireframe_accumulation",
    compiler,
    (const char *)v26,
    config,
    v23,
    v25);
  vostok::render::effect_compiler::set_depth(v16, (int)compiler, 1, 1, v24);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
    v17);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v18);
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)&v26[0].id_crc + vertex_input_type,
    v19,
    compiler,
    "wireframe_color");
  vostok::render::effect_material_base::compile_end(v20, compiler);
}
