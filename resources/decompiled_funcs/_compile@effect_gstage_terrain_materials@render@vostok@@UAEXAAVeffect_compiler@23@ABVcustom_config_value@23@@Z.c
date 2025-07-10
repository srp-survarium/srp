void __thiscall vostok::render::effect_gstage_terrain_materials::compile(
        vostok::render::effect_gstage_terrain_materials *this,
        vostok::render::effect_compiler *compiler,
        const vostok::render::custom_config_value *custom_config)
{
  vostok::render::custom_config_value *v3; // ecx
  bool v4; // al
  vostok::render::custom_config_value *v5; // ecx
  bool v6; // al
  vostok::render::custom_config_value *v7; // ecx
  char v8; // al
  vostok::render::custom_config_value *v9; // ecx
  const void *data; // eax
  vostok::render::custom_config_value *v11; // ecx
  bool v12; // zf
  vostok::render::custom_config_value *v13; // ecx
  vostok::render::custom_config_value *v14; // ecx
  vostok::render::custom_config_value *v15; // ecx
  bool v16; // dl
  bool v17; // al
  vostok::render::custom_config_value *v18; // ecx
  unsigned int v19; // eax
  vostok::render::custom_config_value *v20; // ecx
  const vostok::render::custom_config_value *v21; // eax
  vostok::render::custom_config_value *v22; // ecx
  const vostok::render::custom_config_value *v23; // eax
  vostok::render::custom_config_value *v24; // ecx
  vostok::render::custom_config_value *v25; // ecx
  const vostok::render::custom_config_value *v26; // eax
  vostok::render::custom_config_value *v27; // ecx
  vostok::render::custom_config_value *v28; // ecx
  const vostok::render::custom_config_value *v29; // eax
  vostok::render::custom_config_value *v30; // ecx
  vostok::render::custom_config_value *v31; // ecx
  const vostok::render::custom_config_value *v32; // eax
  vostok::render::custom_config_value *v33; // ecx
  vostok::render::custom_config_value *v34; // ecx
  double v35; // st7
  const vostok::render::custom_config_value *v36; // eax
  vostok::render::custom_config_value *v37; // ecx
  const vostok::render::custom_config_value *v38; // eax
  vostok::render::custom_config_value *v39; // ecx
  const vostok::render::custom_config_value *v40; // eax
  vostok::render::custom_config_value *v41; // ecx
  const vostok::render::custom_config_value *v42; // eax
  vostok::strings::shared::manager *v43; // ecx
  vostok::strings::shared::profile *v44; // eax
  const vostok::render::custom_config_value *v45; // eax
  vostok::render::custom_config_value *v46; // ecx
  const vostok::render::custom_config_value *v47; // eax
  vostok::render::custom_config_value *v48; // ecx
  const vostok::render::custom_config_value *v49; // eax
  vostok::render::custom_config_value *v50; // ecx
  const vostok::render::custom_config_value *v51; // eax
  vostok::render::custom_config_value *v52; // ecx
  const vostok::render::custom_config_value *v53; // eax
  vostok::strings::shared::manager *v54; // ecx
  vostok::strings::shared::profile *v55; // eax
  const vostok::render::custom_config_value *v56; // eax
  vostok::render::custom_config_value *v57; // ecx
  const vostok::render::custom_config_value *v58; // eax
  vostok::render::custom_config_value *v59; // ecx
  const vostok::render::custom_config_value *v60; // eax
  vostok::render::custom_config_value *v61; // ecx
  const vostok::render::custom_config_value *v62; // eax
  vostok::strings::shared::manager *v63; // ecx
  vostok::strings::shared::profile *v64; // eax
  vostok::render::custom_config_value *v65; // ecx
  const vostok::render::custom_config_value *v66; // eax
  vostok::render::custom_config_value *v67; // ecx
  const vostok::render::custom_config_value *v68; // eax
  vostok::render::custom_config_value *v69; // ecx
  const vostok::render::custom_config_value *v70; // eax
  vostok::render::custom_config_value *v71; // ecx
  vostok::render::custom_config_value *v72; // ecx
  const vostok::render::custom_config_value *v73; // eax
  vostok::render::custom_config_value *v74; // ecx
  vostok::strings::shared::manager *v75; // ecx
  vostok::strings::shared::profile *v76; // eax
  vostok::render::effect_compiler *v77; // ecx
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::custom_config_value *v80; // ecx
  bool v81; // al
  vostok::render::custom_config_value *v82; // ecx
  const vostok::render::custom_config_value *v83; // eax
  vostok::strings::shared::profile *v84; // eax
  float v85; // ecx
  vostok::render::effect_compiler *v86; // ecx
  vostok::render::effect_compiler *v87; // ecx
  vostok::render::custom_config_value *v88; // ecx
  bool v89; // al
  const vostok::render::custom_config_value *v90; // eax
  vostok::strings::shared::profile *v91; // eax
  float v92; // ecx
  vostok::render::effect_compiler *v93; // ecx
  vostok::render::effect_compiler *v94; // ecx
  vostok::render::custom_config_value *v95; // ecx
  const vostok::render::custom_config_value *v96; // eax
  vostok::render::custom_config_value *v97; // ecx
  vostok::render::custom_config_value *v98; // ecx
  const vostok::render::custom_config_value *v99; // eax
  vostok::render::custom_config_value *v100; // ecx
  __m128i si128; // xmm0
  vostok::strings::shared::profile *v102; // ecx
  vostok::strings::shared::profile *v103; // eax
  vostok::render::custom_config_value *v104; // ecx
  const vostok::render::custom_config_value *v105; // eax
  vostok::render::effect_compiler *v106; // esi
  vostok::render::effect_compiler *v107; // ecx
  vostok::render::custom_config_value *v108; // ecx
  char v109; // al
  vostok::render::custom_config_value *v110; // ecx
  char v111; // al
  vostok::render::custom_config_value *v112; // ecx
  const vostok::render::custom_config_value *v113; // eax
  const vostok::render::custom_config_value *v114; // eax
  vostok::render::custom_config_value *v115; // ecx
  vostok::strings::shared::profile *v116; // eax
  vostok::render::effect_constant_storage *v117; // ecx
  vostok::render::effect_compiler *v118; // ecx
  vostok::render::effect_compiler *v119; // ecx
  vostok::render::custom_config_value *v120; // ecx
  char v121; // al
  vostok::render::custom_config_value *v122; // ecx
  char v123; // al
  vostok::render::custom_config_value *v124; // ecx
  const vostok::render::custom_config_value *v125; // eax
  const vostok::render::custom_config_value *v126; // eax
  vostok::render::custom_config_value *v127; // ecx
  vostok::strings::shared::profile *v128; // eax
  vostok::render::effect_constant_storage *v129; // ecx
  vostok::render::effect_compiler *v130; // ecx
  vostok::render::effect_compiler *v131; // ecx
  int v132; // ecx
  unsigned __int8 *p_RenderTargetWriteMask; // eax
  vostok::render::effect_compiler *v134; // ecx
  vostok::shared_string v135; // [esp+30Ch] [ebp-64h] BYREF
  const char *v136; // [esp+310h] [ebp-60h]
  vostok::render::shader_configuration *v137; // [esp+314h] [ebp-5Ch]
  char v138; // [esp+329h] [ebp-47h]
  char v139; // [esp+32Ah] [ebp-46h]
  char v140; // [esp+32Bh] [ebp-45h]
  float v141; // [esp+32Ch] [ebp-44h] BYREF
  vostok::command_line::key_initializator predicate[4]; // [esp+330h] [ebp-40h]
  float v143; // [esp+334h] [ebp-3Ch]
  float v144; // [esp+338h] [ebp-38h]
  vostok::command_line::key_initializator v145[4]; // [esp+33Ch] [ebp-34h]
  vostok::math::float3 geometry_shader_name; // [esp+340h] [ebp-30h] BYREF
  int v147; // [esp+34Ch] [ebp-24h]
  vostok::math::float4 source; // [esp+350h] [ebp-20h] BYREF
  vostok::math::float4 v149; // [esp+360h] [ebp-10h] BYREF

  LODWORD(v141) = 2;
  do
  {
    geometry_shader_name.x = 0.0;
    *(_QWORD *)&geometry_shader_name.elements[1] = 0x400000000LL;
    v147 = 0;
    v4 = vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)&stru_969540.configuration[1],
           (int)custom_config)
      && LOBYTE(vostok::render::custom_config_value::operator[](
                  v3,
                  (int)custom_config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_969540.configuration[1])->data);
    LOBYTE(geometry_shader_name.x) = (32 * v4) | 1;
    v6 = vostok::render::custom_config_value::value_exists(&stru_967F04, (int)custom_config)
      && LOBYTE(vostok::render::custom_config_value::operator[](
                  v5,
                  (int)custom_config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_967F04)->data);
    LOBYTE(geometry_shader_name.x) ^= (LOBYTE(geometry_shader_name.x) ^ (8 * v6)) & 8;
    v8 = vostok::render::custom_config_value::value_exists(
           (vostok::render::custom_config_value *)"use_specular_intensity_map",
           (int)custom_config)
      && LOBYTE(vostok::render::custom_config_value::operator[](
                  v7,
                  (int)custom_config,
                  (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"use_specular_intensity_map")->data);
    LOBYTE(geometry_shader_name.x) = LOBYTE(geometry_shader_name.x) & 0x7F | (v8 << 7);
    if ( vostok::render::custom_config_value::value_exists(&stru_969570, (int)custom_config) )
      data = vostok::render::custom_config_value::operator[](
               v9,
               (int)custom_config,
               (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_969570)->data;
    else
      LOBYTE(data) = 0;
    HIBYTE(geometry_shader_name.elements[2]) ^= (HIBYTE(geometry_shader_name.elements[2]) ^ (unsigned __int8)data) & 3;
    if ( !vostok::render::custom_config_value::value_exists(&stru_969584, (int)custom_config)
      || (v12 = LOBYTE(vostok::render::custom_config_value::operator[](
                         v11,
                         (int)custom_config,
                         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_969584)->data) == 0,
          v140 = 1,
          v12) )
    {
      v140 = 0;
    }
    if ( !vostok::render::custom_config_value::value_exists(&stru_969598, (int)custom_config)
      || (v12 = LOBYTE(vostok::render::custom_config_value::operator[](
                         v13,
                         (int)custom_config,
                         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_969598)->data) == 0,
          v138 = 1,
          v12) )
    {
      v138 = 0;
    }
    if ( !vostok::render::custom_config_value::value_exists(&stru_9695AC, (int)custom_config)
      || (v12 = LOBYTE(vostok::render::custom_config_value::operator[](
                         v14,
                         (int)custom_config,
                         (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9695AC)->data) == 0,
          v139 = 1,
          v12) )
    {
      v139 = 0;
    }
    v16 = vostok::render::custom_config_value::value_exists(&stru_9695C0, (int)custom_config)
       && LOBYTE(vostok::render::custom_config_value::operator[](
                   v15,
                   (int)custom_config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9695C0)->data);
    v17 = v140 || v138 || v139 || v16;
    LOBYTE(geometry_shader_name.x) ^= (LOBYTE(geometry_shader_name.x) ^ (4 * v17)) & 4;
    if ( v138 )
      LOBYTE(geometry_shader_name.elements[2]) = 36;
    if ( v139 )
      LOBYTE(geometry_shader_name.elements[2]) |= 0x10u;
    if ( v16 )
      LOBYTE(geometry_shader_name.elements[2]) |= 8u;
    if ( vostok::render::custom_config_value::value_exists(&stru_9695D4, (int)custom_config) )
    {
      v19 = (unsigned int)vostok::render::custom_config_value::operator[](
                            v18,
                            (int)custom_config,
                            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9695D4)->data;
      if ( v19 > 1 )
      {
        if ( v19 > 4 )
          LOBYTE(v19) = 4;
      }
      else
      {
        LOBYTE(v19) = 1;
      }
      LOBYTE(geometry_shader_name.elements[2]) ^= (LOBYTE(geometry_shader_name.elements[2]) ^ v19) & 7;
    }
    vostok::render::effect_material_base::compile_begin(
      compiler,
      custom_config,
      (vostok::render::effect_material_base *)&stru_966284,
      (vostok::render::shader_configuration *)"terrain_gbuffer_pass",
      (const char *)&geometry_shader_name,
      v136,
      v137);
    vostok::render::effect_compiler::set_stencil(
      compiler,
      D3D11_STENCIL_OP_KEEP,
      1,
      0x82u,
      0xFFu,
      0xFFu,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_REPLACE,
      (D3D11_STENCIL_OP)v136);
    v20 = (vostok::render::custom_config_value *)compiler;
    if ( !compiler->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        predicate[0] = 0;
        v135.m_pointer.m_object = *(vostok::strings::shared::profile **)predicate;
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
        compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
      }
    }
    v21 = vostok::render::custom_config_value::operator[](
            v20,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_mask");
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "texture_mask", (char *)v21->data, 0, (bool)v136);
    v23 = vostok::render::custom_config_value::operator[](
            v22,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_tile_0");
    v143 = vostok::render::custom_config_value::operator<float> float(v24, (int)v23);
    v26 = vostok::render::custom_config_value::operator[](
            v25,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_tile_1");
    v144 = vostok::render::custom_config_value::operator<float> float(v27, (int)v26);
    v29 = vostok::render::custom_config_value::operator[](
            v28,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_tile_2");
    *(float *)v145 = vostok::render::custom_config_value::operator<float> float(v30, (int)v29);
    v32 = vostok::render::custom_config_value::operator[](
            v31,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_tile_3");
    v35 = vostok::render::custom_config_value::operator<float> float(v33, (int)v32);
    source.x = v143;
    source.y = v144;
    source.z = *(float *)v145;
    source.w = v35;
    if ( (LOBYTE(geometry_shader_name.x) & 8) != 0 )
    {
      v36 = vostok::render::custom_config_value::operator[](
              v34,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_normal_0");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_normal_0",
        (char *)v36->data,
        0,
        (bool)v136);
      v38 = vostok::render::custom_config_value::operator[](
              v37,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_normal_1");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_normal_1",
        (char *)v38->data,
        0,
        (bool)v136);
      v40 = vostok::render::custom_config_value::operator[](
              v39,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_normal_2");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_normal_2",
        (char *)v40->data,
        0,
        (bool)v136);
      v42 = vostok::render::custom_config_value::operator[](
              v41,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_normal_3");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_normal_3",
        (char *)v42->data,
        0,
        (bool)v136);
      v44 = vostok::strings::shared::manager::string(v43, s_manager.m_variable, "constant_tiles");
      v135.m_pointer.m_object = 0;
      if ( v44 )
      {
        v135.m_pointer.m_object = v44;
        _InterlockedExchangeAdd(&v44->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&source,
        compiler,
        v135);
    }
    v45 = vostok::render::custom_config_value::operator[](
            v34,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_specular_intensity");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "texture_specular_intensity",
      (char *)v45->data,
      0,
      (bool)v136);
    if ( (LOBYTE(geometry_shader_name.x) & 4) != 0 )
    {
      v47 = vostok::render::custom_config_value::operator[](
              v46,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_height_0");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_height_0",
        (char *)v47->data,
        0,
        (bool)v136);
      v49 = vostok::render::custom_config_value::operator[](
              v48,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_height_1");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_height_1",
        (char *)v49->data,
        0,
        (bool)v136);
      v51 = vostok::render::custom_config_value::operator[](
              v50,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_height_2");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_height_2",
        (char *)v51->data,
        0,
        (bool)v136);
      v53 = vostok::render::custom_config_value::operator[](
              v52,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_height_3");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_height_3",
        (char *)v53->data,
        0,
        (bool)v136);
      v55 = vostok::strings::shared::manager::string(v54, s_manager.m_variable, "constant_tiles");
      v135.m_pointer.m_object = 0;
      if ( v55 )
      {
        v135.m_pointer.m_object = v55;
        _InterlockedExchangeAdd(&v55->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&source,
        compiler,
        v135);
    }
    v56 = vostok::render::custom_config_value::operator[](
            v46,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse_0");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "texture_diffuse_0",
      (char *)v56->data,
      0,
      (bool)v136);
    v58 = vostok::render::custom_config_value::operator[](
            v57,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse_1");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "texture_diffuse_1",
      (char *)v58->data,
      0,
      (bool)v136);
    v60 = vostok::render::custom_config_value::operator[](
            v59,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse_2");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "texture_diffuse_2",
      (char *)v60->data,
      0,
      (bool)v136);
    v62 = vostok::render::custom_config_value::operator[](
            v61,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse_3");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "texture_diffuse_3",
      (char *)v62->data,
      0,
      (bool)v136);
    v64 = vostok::strings::shared::manager::string(v63, s_manager.m_variable, "constant_tiles");
    v135.m_pointer.m_object = 0;
    if ( v64 )
    {
      v135.m_pointer.m_object = v64;
      _InterlockedExchangeAdd(&v64->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&source,
      compiler,
      v135);
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_normal", "$user$normal", 0, (bool)v136);
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      "t_decals_normal",
      "$user$decals_normal",
      0,
      (bool)v136);
    if ( (LOBYTE(geometry_shader_name.x) & 0x20) != 0 )
    {
      v66 = vostok::render::custom_config_value::operator[](
              v65,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_detail_0");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_detail_0",
        (char *)v66->data,
        0,
        (bool)v136);
      v68 = vostok::render::custom_config_value::operator[](
              v67,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_detail_1");
      vostok::render::effect_compiler::set_texture(
        0xFFFFFFFF,
        compiler,
        "texture_detail_1",
        (char *)v68->data,
        0,
        (bool)v136);
      v70 = vostok::render::custom_config_value::operator[](
              v69,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_detail_tile_1");
      *(float *)v145 = vostok::render::custom_config_value::operator<float> float(v71, (int)v70);
      v73 = vostok::render::custom_config_value::operator[](
              v72,
              (int)custom_config,
              (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"constant_detail_tile_0");
      v149.x = vostok::render::custom_config_value::operator<float> float(v74, (int)v73);
      v149.y = *(float *)v145;
      *(_QWORD *)&v149.elements[2] = 0;
      v76 = vostok::strings::shared::manager::string(v75, s_manager.m_variable, "constant_detail_tiles");
      v135.m_pointer.m_object = 0;
      if ( v76 )
      {
        v135.m_pointer.m_object = v76;
        _InterlockedExchangeAdd(&v76->m_reference_count, 1u);
      }
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(
        (vostok::render::effect_constant_storage *)&v149,
        compiler,
        v135);
    }
    vostok::render::effect_compiler::end_pass(
      (vostok::render::effect_compiler *)v65,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    vostok::render::effect_compiler::end_technique(v77, (int)compiler);
    --LODWORD(v141);
  }
  while ( v141 != 0.0 );
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = 0x400000000LL;
  source.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966A14.m_name.m_string.m_buffer[92],
    (vostok::render::shader_configuration *)"fill_reflective_shadow_map_backed",
    (const char *)&source,
    v136,
    v137);
  vostok::render::effect_compiler::end_pass(
    v78,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v79, (int)compiler);
  geometry_shader_name.x = 0.0;
  *(_QWORD *)&geometry_shader_name.elements[1] = 0x400000000LL;
  v147 = 0;
  v81 = vostok::render::custom_config_value::value_exists(
          (vostok::render::custom_config_value *)&stru_969540.configuration[1],
          (int)custom_config)
     && LOBYTE(vostok::render::custom_config_value::operator[](
                 v80,
                 (int)custom_config,
                 (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_969540.configuration[1])->data);
  LOBYTE(geometry_shader_name.x) = 32 * v81;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_9666F4,
    (vostok::render::shader_configuration *)&stru_9666F4,
    (const char *)&geometry_shader_name,
    v136,
    v137);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
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
    (D3D11_STENCIL_OP)v136);
  if ( (LOBYTE(geometry_shader_name.x) & 0x20) != 0 )
  {
    v83 = vostok::render::custom_config_value::operator[](
            v82,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_detail_0");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v83->data,
      0,
      (bool)v136);
  }
  v135.m_pointer.m_object = (vostok::strings::shared::profile *)v82;
  v141 = COERCE_FLOAT(&v135);
  LODWORD(geometry_shader_name.x) = clear_value;
  LODWORD(geometry_shader_name.y) = clear_value;
  LODWORD(geometry_shader_name.z) = clear_value;
  v84 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v82,
          s_manager.m_variable,
          "diffuse_color_parameter");
  v85 = v141;
  *(_DWORD *)LODWORD(v141) = 0;
  if ( v84 )
  {
    *(_DWORD *)LODWORD(v85) = v84;
    _InterlockedExchangeAdd(&v84->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&geometry_shader_name, compiler, v135);
  vostok::render::effect_compiler::end_pass(
    v86,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v87, (int)compiler);
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = 0x400000000LL;
  source.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"fill_reflective_shadow_map",
    (const char *)&source,
    v136,
    v137);
  v89 = vostok::render::custom_config_value::value_exists(
          (vostok::render::custom_config_value *)&stru_969540.configuration[1],
          (int)custom_config)
     && LOBYTE(vostok::render::custom_config_value::operator[](
                 v88,
                 (int)custom_config,
                 (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_969540.configuration[1])->data);
  LOBYTE(v88) = (LOBYTE(source.x) ^ (32 * v89)) & 0x20 ^ LOBYTE(source.x);
  if ( ((unsigned __int8)v88 & 0x20) != 0 )
  {
    v90 = vostok::render::custom_config_value::operator[](
            v88,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_detail_0");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v90->data,
      0,
      (bool)v136);
  }
  v135.m_pointer.m_object = (vostok::strings::shared::profile *)v88;
  v141 = COERCE_FLOAT(&v135);
  LODWORD(geometry_shader_name.x) = clear_value;
  LODWORD(geometry_shader_name.y) = clear_value;
  LODWORD(geometry_shader_name.z) = clear_value;
  v91 = vostok::strings::shared::manager::string(
          (vostok::strings::shared::manager *)v88,
          s_manager.m_variable,
          "diffuse_color_parameter");
  v92 = v141;
  *(_DWORD *)LODWORD(v141) = 0;
  if ( v91 )
  {
    *(_DWORD *)LODWORD(v92) = v91;
    _InterlockedExchangeAdd(&v91->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<vostok::math::float3>(&geometry_shader_name, compiler, v135);
  vostok::render::effect_compiler::end_pass(
    v93,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v94, (int)compiler);
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = 0x400000000LL;
  source.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"gbuffer_emissive_pass",
    (const char *)&source,
    v136,
    v137);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
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
    (D3D11_STENCIL_OP)v136);
  v140 = (LOBYTE(source.elements[1]) >> 2) & 3;
  if ( v140 )
  {
    v96 = vostok::render::custom_config_value::operator[](
            v95,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966754);
    *(float *)v145 = vostok::render::custom_config_value::operator<float> float(v97, (int)v96);
    v99 = vostok::render::custom_config_value::operator[](
            v98,
            (int)custom_config,
            (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_966774);
    vostok::render::custom_config_value::operator<vostok::math::float4> vostok::math::float4(v100, &v149, (int)v99);
    si128 = _mm_load_si128((const __m128i *)&v149);
    LODWORD(source.w) = si128.m128i_i32[3];
    v135.m_pointer.m_object = v102;
    source.x = v149.x * *(float *)v145;
    source.y = *(float *)&si128.m128i_i32[1] * *(float *)v145;
    source.z = *(float *)v145 * *(float *)&si128.m128i_i32[2];
    v103 = vostok::strings::shared::manager::string(s_manager.m_variable, s_manager.m_variable, "solid_emission_color");
    v135.m_pointer.m_object = 0;
    if ( v103 )
    {
      v135.m_pointer.m_object = v103;
      _InterlockedExchangeAdd(&v103->m_reference_count, 1u);
    }
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (vostok::render::effect_constant_storage *)&source,
      compiler,
      v135);
  }
  v104 = (vostok::render::custom_config_value *)compiler;
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
      vostok::render::state_descriptor::set_alpha_blend(
        D3D11_BLEND_ONE,
        D3D11_BLEND_OP_ADD,
        D3D11_BLEND_ZERO,
        D3D11_BLEND_OP_ADD,
        &compiler->m_state_descriptor,
        1,
        D3D11_BLEND_ONE,
        (D3D11_BLEND)v136);
  }
  if ( v140 == 2 )
  {
    v105 = vostok::render::custom_config_value::operator[](
             v104,
             (int)custom_config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_emissive");
    vostok::render::effect_compiler::set_texture(0xFFFFFFFF, compiler, "t_emission", (char *)v105->data, 0, (bool)v136);
  }
  v106 = compiler;
  vostok::render::effect_compiler::end_pass(
    (vostok::render::effect_compiler *)v104,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v107, (int)compiler);
  geometry_shader_name.x = 0.0;
  *(_QWORD *)&geometry_shader_name.elements[1] = 0x400000000LL;
  v147 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, (int)custom_config) )
    v109 = (char)vostok::render::custom_config_value::operator[](
                   v108,
                   (int)custom_config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44)->data;
  else
    v109 = 0;
  LOBYTE(geometry_shader_name.x) = 2 * (v109 & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, (int)custom_config) )
    v111 = (char)vostok::render::custom_config_value::operator[](
                   v110,
                   (int)custom_config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data;
  else
    v111 = 0;
  LOBYTE(geometry_shader_name.x) ^= (v111 ^ LOBYTE(geometry_shader_name.x)) & 1;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)&stru_9667A8.destroyer,
    (const char *)&geometry_shader_name,
    v136,
    v137);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v141 = 0.25;
  if ( (LOBYTE(geometry_shader_name.x) & 1) != 0 )
  {
    v113 = vostok::render::custom_config_value::operator[](
             v112,
             (int)custom_config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v113->data,
      0,
      (bool)v136);
  }
  if ( (LOBYTE(geometry_shader_name.x) & 2) != 0
    && vostok::render::custom_config_value::value_exists(&stru_9667FC, (int)custom_config) )
  {
    v114 = vostok::render::custom_config_value::operator[](
             v112,
             (int)custom_config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667FC);
    v141 = vostok::render::custom_config_value::operator<float> float(v115, (int)v114);
  }
  v135.m_pointer.m_object = (vostok::strings::shared::profile *)v112;
  v116 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v112,
           s_manager.m_variable,
           (const char *)&stru_9667FC.type);
  v135.m_pointer.m_object = 0;
  if ( v116 )
  {
    v135.m_pointer.m_object = v116;
    v117 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v116->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&v141, v117, compiler, v135);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v12 = compiler->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
      compiler->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
      LOBYTE(v118) = !v12;
      compiler->m_state_descriptor.m_rasterizer_desc_updated |= !v12;
    }
  }
  vostok::render::effect_compiler::end_pass(
    v118,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v119, (int)compiler);
  geometry_shader_name.x = 0.0;
  *(_QWORD *)&geometry_shader_name.elements[1] = 0x400000000LL;
  v147 = 0;
  if ( vostok::render::custom_config_value::value_exists(&stru_960A44, (int)custom_config) )
    v121 = (char)vostok::render::custom_config_value::operator[](
                   v120,
                   (int)custom_config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_960A44)->data;
  else
    v121 = 0;
  LOBYTE(geometry_shader_name.x) = 2 * (v121 & 1);
  if ( vostok::render::custom_config_value::value_exists(&stru_9667A8, (int)custom_config) )
    v123 = (char)vostok::render::custom_config_value::operator[](
                   v122,
                   (int)custom_config,
                   (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667A8)->data;
  else
    v123 = 0;
  LOBYTE(geometry_shader_name.x) ^= (v123 ^ LOBYTE(geometry_shader_name.x)) & 1;
  vostok::render::effect_material_base::compile_begin(
    compiler,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"subsurface_scattering",
    (const char *)&geometry_shader_name,
    v136,
    v137);
  if ( !compiler->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
      compiler->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      compiler->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
  }
  v141 = 0.25;
  if ( (LOBYTE(geometry_shader_name.x) & 1) != 0 )
  {
    v125 = vostok::render::custom_config_value::operator[](
             v124,
             (int)custom_config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)"texture_diffuse");
    vostok::render::effect_compiler::set_texture(
      0xFFFFFFFF,
      compiler,
      &stru_963F84.m_name.m_string.m_buffer[116],
      (char *)v125->data,
      0,
      (bool)v136);
  }
  if ( (LOBYTE(geometry_shader_name.x) & 2) != 0
    && vostok::render::custom_config_value::value_exists(&stru_9667FC, (int)custom_config) )
  {
    v126 = vostok::render::custom_config_value::operator[](
             v124,
             (int)custom_config,
             (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>)&stru_9667FC);
    v141 = vostok::render::custom_config_value::operator<float> float(v127, (int)v126);
    v106 = compiler;
  }
  v135.m_pointer.m_object = (vostok::strings::shared::profile *)v124;
  v128 = vostok::strings::shared::manager::string(
           (vostok::strings::shared::manager *)v124,
           s_manager.m_variable,
           (const char *)&stru_9667FC.type);
  v135.m_pointer.m_object = 0;
  if ( v128 )
  {
    v135.m_pointer.m_object = v128;
    v129 = (vostok::render::effect_constant_storage *)_InterlockedExchangeAdd(&v128->m_reference_count, 1u);
  }
  vostok::render::effect_compiler::set_constant<float>(&v141, v129, v106, v135);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    v106,
    "t_diffuse_lighting",
    "$user$accum_diffuse",
    0,
    (bool)v136);
  vostok::render::effect_compiler::set_texture(
    0xFFFFFFFF,
    v106,
    "t_specular_lighting",
    "$user$accum_specular",
    0,
    (bool)v136);
  if ( !v106->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v12 = v106->m_state_descriptor.m_rasterizer_desc.CullMode == D3D11_CULL_NONE;
      v106->m_state_descriptor.m_rasterizer_desc.CullMode = D3D11_CULL_NONE;
      v106->m_state_descriptor.m_rasterizer_desc_updated |= !v12;
    }
  }
  vostok::render::effect_compiler::end_pass(
    v130,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v106);
  vostok::render::effect_compiler::end_technique(v131, (int)v106);
  source.x = 0.0;
  *(_QWORD *)&source.elements[1] = 0x400000000LL;
  source.w = 0.0;
  vostok::render::effect_material_base::compile_begin(
    v106,
    custom_config,
    (vostok::render::effect_material_base *)&stru_966284,
    (vostok::render::shader_configuration *)"z_only",
    (const char *)&source,
    v136,
    v137);
  if ( !v106->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      v145[0] = 0;
      v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v106->m_state_descriptor.m_depth_stencil_desc.DepthEnable = 1;
      v106->m_state_descriptor.m_depth_stencil_desc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
      v106->m_state_descriptor.m_depth_stencil_desc.DepthFunc = D3D11_COMPARISON_LESS_EQUAL;
      v106->m_state_descriptor.m_depth_stencil_desc_updated = 1;
    }
    if ( !v106->m_shaders_cache_mode )
    {
      if ( s_no_effect_result.m_type == type_unset )
      {
        v145[0] = 0;
        v135.m_pointer.m_object = *(vostok::strings::shared::profile **)v145;
        s_no_effect_result.m_type = type_recursive;
        vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
      }
      if ( s_no_effect_result.m_type == type_recursive )
      {
        p_RenderTargetWriteMask = &v106->m_state_descriptor.m_effect_desc.RenderTarget[0].RenderTargetWriteMask;
        v106->m_state_descriptor.m_effect_desc_updated |= v106->m_state_descriptor.m_effect_desc.RenderTarget[0].RenderTargetWriteMask != 0;
        v132 = 8;
        do
        {
          *p_RenderTargetWriteMask = 0;
          p_RenderTargetWriteMask += 32;
          --v132;
        }
        while ( v132 );
      }
    }
  }
  vostok::render::effect_compiler::end_pass(
    (vostok::render::effect_compiler *)v132,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)v106);
  vostok::render::effect_compiler::end_technique(v134, (int)v106);
}
