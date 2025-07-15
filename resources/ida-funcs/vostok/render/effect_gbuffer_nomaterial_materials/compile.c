void __thiscall vostok::render::effect_gbuffer_nomaterial_materials::compile(
        vostok::render::effect_gbuffer_nomaterial_materials *this,
        vostok::render::effect_compiler *compiler,
        vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_material_base *v7; // ecx
  vostok::render::effect_material_base *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::render::effect_constant_storage *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_material_base *v12; // ecx
  vostok::configs::binary_config_value *v13; // ecx
  vostok::render::effect_constant_storage *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_material_base *v16; // ecx
  vostok::configs::binary_config_value *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::configs::binary_config_value *v21; // eax
  const vostok::configs::binary_config_value *v22; // eax
  float pointer; // xmm0_4
  vostok::configs::binary_config_value *v24; // eax
  const vostok::configs::binary_config_value *v25; // eax
  float *v26; // esi
  double v27; // xmm0_8
  double v28; // xmm0_8
  double v29; // xmm0_8
  vostok::render::effect_constant_storage *v30; // ecx
  vostok::render::effect_material_base *v31; // ecx
  vostok::configs::binary_config_value *v32; // eax
  char **v33; // eax
  vostok::render::effect_compiler *v34; // ecx
  vostok::configs::binary_config_value *v35; // ecx
  vostok::configs::binary_config_value *v36; // ecx
  vostok::configs::binary_config_value *v37; // eax
  bool v38; // al
  vostok::configs::binary_config_value *v39; // ecx
  vostok::configs::binary_config_value *v40; // eax
  bool v41; // al
  vostok::render::effect_compiler *v42; // ecx
  vostok::render::effect_material_base *v43; // ecx
  vostok::configs::binary_config_value *v44; // ecx
  vostok::configs::binary_config_value *v45; // ecx
  vostok::configs::binary_config_value *v46; // eax
  bool v47; // al
  vostok::configs::binary_config_value *v48; // ecx
  vostok::configs::binary_config_value *v49; // eax
  bool v50; // al
  vostok::render::effect_compiler *v51; // ecx
  vostok::configs::binary_config_value *v52; // ecx
  vostok::configs::binary_config_value *v53; // eax
  char **v54; // eax
  vostok::render::effect_compiler *v55; // ecx
  vostok::configs::binary_config_value *v56; // eax
  vostok::render::effect_compiler *v57; // ecx
  vostok::render::effect_compiler *v58; // ecx
  vostok::render::effect_material_base *v59; // ecx
  vostok::configs::binary_config_value *v60; // ecx
  vostok::render::effect_compiler *v61; // ecx
  vostok::render::effect_compiler *v62; // ecx
  vostok::render::effect_material_base *v63; // ecx
  vostok::configs::binary_config_value *v64; // ecx
  vostok::configs::binary_config_value *v65; // ecx
  vostok::configs::binary_config_value *v66; // eax
  bool v67; // al
  vostok::render::effect_compiler *v68; // ecx
  vostok::command_line::key *v69; // ecx
  vostok::render::effect_compiler *v70; // ecx
  vostok::render::effect_material_base *v71; // ecx
  vostok::configs::binary_config_value *v72; // ecx
  vostok::render::effect_compiler *v73; // ecx
  vostok::command_line::key *v74; // ecx
  vostok::render::effect_compiler *v75; // ecx
  vostok::render::effect_material_base *v76; // ecx
  vostok::configs::binary_config_value *v77; // ecx
  vostok::configs::binary_config_value *v78; // ecx
  vostok::configs::binary_config_value *v79; // eax
  bool v80; // al
  vostok::configs::binary_config_value *v81; // ecx
  vostok::configs::binary_config_value *v82; // eax
  char v83; // al
  vostok::configs::binary_config_value *v84; // ecx
  vostok::configs::binary_config_value *v85; // eax
  bool v86; // al
  vostok::configs::binary_config_value *v87; // ecx
  vostok::configs::binary_config_value *v88; // eax
  bool v89; // al
  vostok::render::effect_compiler *v90; // ecx
  vostok::command_line::key *v91; // ecx
  vostok::command_line::key *v92; // ecx
  vostok::render::effect_material_base *v93; // ecx
  vostok::render::shader_configuration *v94; // [esp+4h] [ebp-38h]
  D3D11_STENCIL_OP v95; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v96; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v97; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v98; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v99; // [esp+4h] [ebp-38h]
  long double v100; // [esp+4h] [ebp-38h]
  long double v101; // [esp+4h] [ebp-38h]
  long double v102; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v103; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v104; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v105; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v106; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v107; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v108; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v109; // [esp+4h] [ebp-38h]
  D3D11_BLEND_OP v110; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v111; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v112; // [esp+4h] [ebp-38h]
  vostok::render::shader_configuration *v113; // [esp+4h] [ebp-38h]
  D3D11_COMPARISON_FUNC v114; // [esp+4h] [ebp-38h]
  const vostok::configs::binary_config_value *v115; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v116; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v117; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v118; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v119; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v120; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v121; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v122; // [esp+8h] [ebp-34h]
  const vostok::configs::binary_config_value *v123; // [esp+8h] [ebp-34h]
  long double v124; // [esp+Ch] [ebp-30h]
  long double v125; // [esp+Ch] [ebp-30h]
  long double v126; // [esp+Ch] [ebp-30h]
  char v127; // [esp+17h] [ebp-25h]
  unsigned int source; // [esp+18h] [ebp-24h]
  float sourcea; // [esp+18h] [ebp-24h]
  vostok::math::float4 pixel_shader_name; // [esp+1Ch] [ebp-20h] BYREF
  char v131[4]; // [esp+2Ch] [ebp-10h] BYREF
  float v132; // [esp+30h] [ebp-Ch]
  int v133; // [esp+34h] [ebp-8h]
  float v134; // [esp+38h] [ebp-4h]

  for ( source = 0; source < 3; ++source )
  {
    LOWORD(pixel_shader_name.elements[2]) = 0;
    *(_QWORD *)&pixel_shader_name.x = 0x80000;
    HIBYTE(pixel_shader_name.elements[2]) = (16 * (source == 1)) & 0x10;
    pixel_shader_name.w = 0.0;
    BYTE2(pixel_shader_name.elements[2]) = 8;
    vostok::render::effect_material_base::compile_begin(
      parameters,
      (vostok::configs::binary_config_value *)this,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "gbuffer_nomaterial_pass",
      (char *)compiler,
      (const char *)&pixel_shader_name,
      config,
      v94,
      v115);
    vostok::render::effect_compiler::set_stencil(
      v4,
      (int)compiler,
      1,
      0x81u,
      0xFFu,
      255,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_REPLACE,
      D3D11_STENCIL_OP_KEEP,
      v95);
    vostok::render::effect_compiler::set_depth(v5, (int)compiler, 1, 1, v96);
    vostok::render::effect_compiler::set_texture(
      v6,
      (const char *)compiler,
      "t_default_texture",
      "no_texture",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_material_base::compile_end(v7, compiler);
  }
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    (vostok::configs::binary_config_value *)this,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "fill_reflective_shadow_map_backed",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v94,
    v115);
  vostok::render::effect_material_base::compile_end(v8, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v9,
    (vostok::render::effect_material_base *)&stru_812848,
    (const char *)&stru_812848,
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v97,
    v116);
  pixel_shader_name.x = s_bm_current_air_resistance;
  pixel_shader_name.y = s_bm_current_air_resistance;
  pixel_shader_name.z = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)&pixel_shader_name,
    v10,
    compiler,
    "diffuse_color_parameter");
  vostok::render::effect_compiler::set_texture(
    v11,
    (const char *)compiler,
    "t_base",
    "no_texture",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v12, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v13,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "fill_reflective_shadow_map",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v98,
    v117);
  pixel_shader_name.x = s_bm_current_air_resistance;
  pixel_shader_name.y = s_bm_current_air_resistance;
  pixel_shader_name.z = s_bm_current_air_resistance;
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(
    (const vostok::math::float3 *)&pixel_shader_name,
    v14,
    compiler,
    "diffuse_color_parameter");
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_base",
    "no_texture",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v16, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v17,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "gbuffer_emissive_pass",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v99,
    v118);
  vostok::render::effect_compiler::set_depth(v18, (int)compiler, 1, 0, SLODWORD(v100));
  vostok::render::effect_compiler::set_stencil(
    v19,
    (int)compiler,
    0,
    0,
    0,
    0,
    D3D11_COMPARISON_ALWAYS,
    D3D11_STENCIL_OP_KEEP,
    D3D11_STENCIL_OP_KEEP,
    SLODWORD(v100));
  v127 = HIBYTE(pixel_shader_name.elements[1]) & 3;
  if ( (HIBYTE(pixel_shader_name.elements[1]) & 3) != 0 )
  {
    v21 = vostok::configs::binary_config_value::operator[](config, "constant_emissive_multiplier");
    v22 = vostok::configs::binary_config_value::operator[](v21, "value");
    if ( v22->type == 2 )
      pointer = *(float *)&v22->data.pointer;
    else
      pointer = (float)(int)v22->data.pointer;
    sourcea = pointer;
    v24 = vostok::configs::binary_config_value::operator[](config, "constant_emissive");
    v25 = vostok::configs::binary_config_value::operator[](v24, "value");
    v26 = (float *)v25->data.pointer;
    v27 = *(float *)v25->data.pointer;
    __libm_sse2_pow(v100, v124);
    *(float *)&v27 = v27;
    *(float *)v131 = *(float *)&v27;
    v28 = v26[1];
    __libm_sse2_pow(v101, v125);
    *(float *)&v28 = v28;
    v132 = *(float *)&v28;
    v29 = v26[2];
    __libm_sse2_pow(v102, v126);
    *(float *)&v29 = v29;
    v133 = LODWORD(v29);
    v134 = v26[3];
    pixel_shader_name.w = v134;
    pixel_shader_name.x = *(float *)v131 * sourcea;
    pixel_shader_name.y = v132 * sourcea;
    pixel_shader_name.z = *(float *)&v29 * sourcea;
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      &pixel_shader_name,
      v30,
      compiler,
      "solid_emission_color");
  }
  vostok::render::effect_compiler::set_alpha_blend(
    v20,
    (int)compiler,
    1,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    SLODWORD(v100));
  if ( v127 == 2 )
  {
    v32 = vostok::configs::binary_config_value::operator[](config, "texture_emissive");
    v33 = (char **)vostok::configs::binary_config_value::operator[](v32, "value");
    vostok::render::effect_compiler::set_texture(v34, (const char *)compiler, "t_emission", *v33, 0, 0xFFFFFFFF, 0, 1.0);
  }
  vostok::render::effect_material_base::compile_end(v31, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v35, (int)config, (unsigned int)"use_alpha_test") )
  {
    v37 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v38 = vostok::configs::binary_config_value::operator[](v37, "value")->data.pointer != 0;
  }
  else
  {
    v38 = 0;
  }
  BYTE2(pixel_shader_name.elements[0]) = 16 * v38;
  if ( vostok::configs::binary_config_value::value_exists(v36, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v40 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v41 = vostok::configs::binary_config_value::operator[](v40, "value")->data.pointer != 0;
  }
  else
  {
    v41 = 0;
  }
  BYTE2(pixel_shader_name.elements[0]) ^= (BYTE2(pixel_shader_name.elements[0]) ^ (8 * v41)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v39,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "motion_vectors_accumulation",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    (vostok::render::shader_configuration *)LODWORD(v100),
    (const vostok::configs::binary_config_value *)HIDWORD(v100));
  vostok::render::effect_compiler::set_depth(v42, (int)compiler, 1, 0, v103);
  vostok::render::effect_material_base::compile_end(v43, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v44, (int)config, (unsigned int)"use_alpha_test") )
  {
    v46 = vostok::configs::binary_config_value::operator[](config, "use_alpha_test");
    v47 = vostok::configs::binary_config_value::operator[](v46, "value")->data.pointer != 0;
  }
  else
  {
    v47 = 0;
  }
  BYTE2(pixel_shader_name.elements[0]) = 16 * v47;
  if ( vostok::configs::binary_config_value::value_exists(v45, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v49 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v50 = vostok::configs::binary_config_value::operator[](v49, "value")->data.pointer != 0;
  }
  else
  {
    v50 = 0;
  }
  BYTE2(pixel_shader_name.elements[0]) ^= (BYTE2(pixel_shader_name.elements[0]) ^ (8 * v50)) & 8;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v48,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "subsurface_scattering",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v104,
    v119);
  vostok::render::effect_compiler::set_depth(v51, (int)compiler, 1, 0, v105);
  if ( (BYTE2(pixel_shader_name.elements[0]) & 8) != 0 )
  {
    v53 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
    v54 = (char **)vostok::configs::binary_config_value::operator[](v53, "value");
    vostok::render::effect_compiler::set_texture(v55, (const char *)compiler, "t_base", *v54, 0, 0, 0xFFFFFFFF, 1.0);
  }
  if ( (BYTE2(pixel_shader_name.elements[0]) & 0x10) != 0
    && vostok::configs::binary_config_value::value_exists(v52, (int)config, (unsigned int)"alpha_ref") )
  {
    v56 = vostok::configs::binary_config_value::operator[](config, "alpha_ref");
    vostok::configs::binary_config_value::operator[](v56, "value");
  }
  vostok::render::effect_compiler::set_constant<float>(
    (vostok::render::effect_constant_storage *)v52,
    compiler,
    "alpha_ref_parameter");
  vostok::render::effect_compiler::set_texture(
    v57,
    (const char *)compiler,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v58,
    (const char *)compiler,
    "t_specular_lighting",
    "$user$accum_specular",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_material_base::compile_end(v59, compiler);
  v133 = 0x80000;
  *(float *)v131 = 0.0;
  v132 = 0.0;
  v134 = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v60,
    (vostok::render::effect_material_base *)&stru_80E8FC,
    "z_only",
    (char *)compiler,
    v131,
    config,
    v106,
    v120);
  vostok::render::effect_compiler::set_depth(v61, (int)compiler, 1, 1, v107);
  vostok::render::effect_compiler::color_write_enable(v62, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_material_base::compile_end(v63, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v64, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v66 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v67 = vostok::configs::binary_config_value::operator[](v66, "value")->data.pointer != 0;
  }
  else
  {
    v67 = 0;
  }
  BYTE2(pixel_shader_name.elements[0]) = 8 * v67;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v65,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "bake_decal_accumulate",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v108,
    v121);
  vostok::render::effect_compiler::set_depth(v68, (int)compiler, 0, 0, v109);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v69);
  vostok::render::effect_compiler::set_alpha_blend(
    v70,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ONE,
    v110);
  vostok::render::effect_material_base::compile_end(v71, compiler);
  v133 = 0x80000;
  *(float *)v131 = 0.0;
  v132 = 0.0;
  v134 = 0.0;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v72,
    (vostok::render::effect_material_base *)&stru_8129E4,
    "bake_decal_occlusion",
    (char *)compiler,
    v131,
    config,
    v111,
    v122);
  vostok::render::effect_compiler::set_depth(v73, (int)compiler, 1, 1, v112);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v74);
  vostok::render::effect_compiler::color_write_enable(v75, (int)compiler, (D3D11_COLOR_WRITE_ENABLE)0);
  vostok::render::effect_material_base::compile_end(v76, compiler);
  pixel_shader_name.x = 0.0;
  *(_QWORD *)&pixel_shader_name.elements[1] = 0x8000000000000LL;
  pixel_shader_name.w = 0.0;
  if ( vostok::configs::binary_config_value::value_exists(v77, (int)config, (unsigned int)"use_tdiffuse") )
  {
    v79 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
    v80 = vostok::configs::binary_config_value::operator[](v79, "value")->data.pointer != 0;
  }
  else
  {
    v80 = 0;
  }
  BYTE2(pixel_shader_name.elements[0]) = 8 * v80;
  if ( vostok::configs::binary_config_value::value_exists(v78, (int)config, (unsigned int)"use_nmap") )
  {
    v82 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
    v83 = vostok::configs::binary_config_value::operator[](v82, "value")->data.pointer != 0;
  }
  else
  {
    v83 = 0;
  }
  LOBYTE(v81) = BYTE2(pixel_shader_name.elements[0]) & 0x7F;
  BYTE2(pixel_shader_name.elements[0]) = BYTE2(pixel_shader_name.elements[0]) & 0x7F | (v83 << 7);
  if ( vostok::configs::binary_config_value::value_exists(v81, (int)config, (unsigned int)"use_tfresnel") )
  {
    v85 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v86 = vostok::configs::binary_config_value::operator[](v85, "value")->data.pointer != 0;
  }
  else
  {
    v86 = 0;
  }
  HIBYTE(pixel_shader_name.elements[0]) ^= (HIBYTE(pixel_shader_name.elements[0]) ^ (16 * v86)) & 0x10;
  if ( vostok::configs::binary_config_value::value_exists(v84, (int)config, (unsigned int)"use_troughness") )
  {
    v88 = vostok::configs::binary_config_value::operator[](config, "use_troughness");
    v89 = vostok::configs::binary_config_value::operator[](v88, "value")->data.pointer != 0;
  }
  else
  {
    v89 = 0;
  }
  HIBYTE(pixel_shader_name.elements[0]) ^= (HIBYTE(pixel_shader_name.elements[0]) ^ (32 * v89)) & 0x20;
  vostok::render::effect_material_base::compile_begin(
    parameters,
    v87,
    (vostok::render::effect_material_base *)&stru_8129B8,
    "bake_decal_composition",
    (char *)compiler,
    (const char *)&pixel_shader_name,
    config,
    v113,
    v123);
  vostok::render::effect_compiler::set_depth(v90, (int)compiler, 0, 0, v114);
  vostok::render::effect_compiler::set_fill_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
    v91);
  vostok::render::effect_compiler::set_cull_mode(
    compiler,
    (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)1,
    v92);
  vostok::render::effect_material_base::compile_end(v93, compiler);
}
