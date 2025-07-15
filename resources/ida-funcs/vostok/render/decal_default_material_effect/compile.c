void __thiscall vostok::render::decal_default_material_effect::compile(
        vostok::render::decal_default_material_effect *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ecx
  char v7; // al
  bool v8; // zf
  vostok::configs::binary_config_value *v9; // eax
  vostok::configs::binary_config_value *v10; // eax
  vostok::configs::binary_config_value *v11; // ecx
  vostok::configs::binary_config_value *v12; // eax
  vostok::configs::binary_config_value *v13; // ecx
  vostok::configs::binary_config_value *v14; // eax
  vostok::configs::binary_config_value *v15; // ecx
  vostok::configs::binary_config_value *v16; // eax
  BOOL v17; // ecx
  vostok::configs::binary_config_value *v18; // eax
  BOOL v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::command_line::key *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::configs::binary_config_value *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::configs::binary_config_value *v26; // eax
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::configs::binary_config_value *v29; // eax
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_constant_storage *v31; // ecx
  vostok::configs::binary_config_value *v32; // eax
  const vostok::configs::binary_config_value *v33; // eax
  vostok::render::effect_constant_storage *v34; // ecx
  float v35; // xmm0_4
  vostok::configs::binary_config_value *v36; // ecx
  vostok::render::effect_compiler *v37; // ecx
  vostok::configs::binary_config_value *v38; // eax
  vostok::render::effect_compiler *v39; // ecx
  vostok::render::effect_constant_storage *v40; // ecx
  vostok::configs::binary_config_value *v41; // eax
  const vostok::configs::binary_config_value *v42; // eax
  vostok::render::effect_constant_storage *v43; // ecx
  float v44; // xmm0_4
  vostok::configs::binary_config_value *v45; // ecx
  vostok::render::effect_compiler *v46; // ecx
  vostok::configs::binary_config_value *v47; // eax
  vostok::render::effect_compiler *v48; // ecx
  vostok::render::effect_constant_storage *v49; // ecx
  vostok::configs::binary_config_value *v50; // eax
  const vostok::configs::binary_config_value *v51; // eax
  vostok::render::effect_constant_storage *v52; // ecx
  float v53; // xmm0_4
  vostok::render::effect_compiler *v54; // ecx
  vostok::configs::binary_config_value *v55; // eax
  char **v56; // eax
  vostok::render::effect_compiler *v57; // ecx
  vostok::configs::binary_config_value *v58; // ecx
  vostok::configs::binary_config_value *v59; // eax
  const vostok::configs::binary_config_value *v60; // eax
  float *v61; // edi
  double v62; // xmm0_8
  double v63; // xmm0_8
  double v64; // xmm0_8
  vostok::render::effect_constant_storage *v65; // ecx
  vostok::configs::binary_config_value *v66; // ecx
  vostok::configs::binary_config_value *v67; // eax
  float **v68; // eax
  float *v69; // esi
  vostok::render::effect_constant_storage *v70; // ecx
  vostok::render::effect_compiler *v71; // ecx
  vostok::configs::binary_config_value *v72; // eax
  const vostok::configs::binary_config_value *v73; // eax
  vostok::render::effect_constant_storage *v74; // ecx
  float v75; // xmm0_4
  vostok::configs::binary_config_value *v76; // eax
  char **v77; // eax
  vostok::render::effect_compiler *v78; // ecx
  vostok::render::effect_compiler *v79; // ecx
  vostok::render::effect_compiler *v80; // ecx
  vostok::configs::binary_config_value *v81; // ecx
  vostok::configs::binary_config_value *v82; // ecx
  vostok::render::effect_constant_storage *v83; // ecx
  vostok::configs::binary_config_value *v84; // eax
  float v85; // xmm0_4
  vostok::configs::binary_config_value *v86; // eax
  char **v87; // eax
  vostok::render::effect_compiler *v88; // ecx
  char *pointer; // [esp-10h] [ebp-7Ch]
  char *v90; // [esp-10h] [ebp-7Ch]
  char *v91; // [esp-10h] [ebp-7Ch]
  char *v92; // [esp-10h] [ebp-7Ch]
  long double v93; // [esp+4h] [ebp-68h]
  long double v94; // [esp+4h] [ebp-68h]
  long double v95; // [esp+4h] [ebp-68h]
  long double v96; // [esp+Ch] [ebp-60h]
  long double v97; // [esp+Ch] [ebp-60h]
  long double v98; // [esp+Ch] [ebp-60h]
  char v99; // [esp+17h] [ebp-55h]
  unsigned int i; // [esp+18h] [ebp-54h]
  float v102; // [esp+20h] [ebp-4Ch] BYREF
  float v103; // [esp+24h] [ebp-48h] BYREF
  int v104; // [esp+28h] [ebp-44h] BYREF
  float v105; // [esp+2Ch] [ebp-40h] BYREF
  int v106; // [esp+30h] [ebp-3Ch] BYREF
  float v107; // [esp+34h] [ebp-38h] BYREF
  int v108; // [esp+38h] [ebp-34h] BYREF
  float v109; // [esp+3Ch] [ebp-30h] BYREF
  vostok::math::float3 v110; // [esp+40h] [ebp-2Ch] BYREF
  int v111; // [esp+4Ch] [ebp-20h] BYREF
  int v112; // [esp+50h] [ebp-1Ch]
  int v113; // [esp+54h] [ebp-18h]
  int v114; // [esp+58h] [ebp-14h]
  vostok::math::float4 v115; // [esp+5Ch] [ebp-10h] BYREF

  v113 = 0x80000;
  v111 = 0;
  v112 = 0;
  v114 = 0;
  v4 = vostok::configs::binary_config_value::operator[](config, "use_tdiffuse");
  v5 = vostok::configs::binary_config_value::operator[](v4, "value");
  v6 = (vostok::configs::binary_config_value *)this;
  v7 = 8 * (v5->data.pointer != 0);
  v8 = !this->m_is_forward;
  BYTE2(v111) = v7;
  if ( v8 )
  {
    v9 = vostok::configs::binary_config_value::operator[](config, "use_nmap");
    v8 = vostok::configs::binary_config_value::operator[](v9, "value")->data.pointer == 0;
    v7 = BYTE2(v111);
    LOBYTE(v6) = !v8;
  }
  else
  {
    LOBYTE(v6) = 0;
  }
  LOBYTE(v6) = v7 & 0x7F | ((_BYTE)v6 << 7);
  BYTE2(v111) = (_BYTE)v6;
  if ( vostok::configs::binary_config_value::value_exists(v6, (int)config, (unsigned int)"use_reflection") )
  {
    v10 = vostok::configs::binary_config_value::operator[](config, "use_reflection");
    v11 = (vostok::configs::binary_config_value *)(vostok::configs::binary_config_value::operator[](v10, "value")->data.pointer != 0);
  }
  else
  {
    v11 = 0;
  }
  v8 = !this->m_is_forward;
  BYTE2(v112) = BYTE2(v112) & 0x3F | ((_BYTE)v11 << 6);
  LOBYTE(v11) = HIBYTE(v112) & 0x1F;
  HIBYTE(v112) = HIBYTE(v112) & 0x1F | (!v8 << 6) | 0x20;
  if ( vostok::configs::binary_config_value::value_exists(v11, (int)config, (unsigned int)"use_tfresnel") )
  {
    v12 = vostok::configs::binary_config_value::operator[](config, "use_tfresnel");
    v13 = (vostok::configs::binary_config_value *)(vostok::configs::binary_config_value::operator[](v12, "value")->data.pointer != 0);
  }
  else
  {
    v13 = 0;
  }
  LOBYTE(v13) = (HIBYTE(v111) ^ (16 * (_BYTE)v13)) & 0x10;
  HIBYTE(v111) ^= (unsigned __int8)v13;
  if ( vostok::configs::binary_config_value::value_exists(v13, (int)config, (unsigned int)"use_tsmoothness") )
  {
    v14 = vostok::configs::binary_config_value::operator[](config, "use_tsmoothness");
    v15 = (vostok::configs::binary_config_value *)(vostok::configs::binary_config_value::operator[](v14, "value")->data.pointer != 0);
  }
  else
  {
    v15 = 0;
  }
  LOBYTE(v15) = (HIBYTE(v111) ^ (32 * (_BYTE)v15)) & 0x20;
  HIBYTE(v111) ^= (unsigned __int8)v15;
  if ( vostok::configs::binary_config_value::value_exists(v15, (int)config, (unsigned int)"use_tspecular_mask") )
  {
    v16 = vostok::configs::binary_config_value::operator[](config, "use_tspecular_mask");
    v17 = vostok::configs::binary_config_value::operator[](v16, "value")->data.pointer != 0;
  }
  else
  {
    v17 = 0;
  }
  LOBYTE(v17) = (v112 ^ v17) & 1;
  LOBYTE(v112) = v17 ^ v112;
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v17,
         (int)config,
         (unsigned int)"use_normal_mask_texture") )
  {
    v18 = vostok::configs::binary_config_value::operator[](config, "use_normal_mask_texture");
    v19 = vostok::configs::binary_config_value::operator[](v18, "value")->data.pointer != 0;
  }
  else
  {
    v19 = 0;
  }
  LOBYTE(v19) = (HIBYTE(v111) ^ v19) & 1;
  HIBYTE(v111) ^= v19;
  v99 = v112 & 1;
  for ( i = 0; i < 2; ++i )
  {
    vostok::render::effect_material_base::compile_begin(
      parameters,
      (vostok::configs::binary_config_value *)v19,
      (vostok::render::effect_material_base *)&stru_80E8FC,
      "decal_base",
      compiler,
      (const char *)&v111,
      config,
      (vostok::render::shader_configuration *)LODWORD(v93),
      (const vostok::configs::binary_config_value *)HIDWORD(v93));
    vostok::render::effect_compiler::set_depth(v20, (int)compiler, 0, 0, SLODWORD(v93));
    vostok::render::effect_compiler::set_stencil(
      v21,
      (int)compiler,
      0,
      0,
      0,
      0,
      D3D11_COMPARISON_ALWAYS,
      D3D11_STENCIL_OP_KEEP,
      D3D11_STENCIL_OP_KEEP,
      SLODWORD(v93));
    if ( i )
      vostok::render::effect_compiler::set_cull_mode(
        compiler,
        (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)2,
        v22);
    else
      vostok::render::effect_compiler::set_cull_mode(
        compiler,
        (vostok::render::map<vostok::render::binary_shader_key_type,vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base>,stlp_std::less<vostok::render::binary_shader_key_type> > *)3,
        v22);
    vostok::render::effect_compiler::set_stencil(
      v23,
      (int)compiler,
      1,
      0,
      0xFFu,
      0,
      D3D11_COMPARISON_NOT_EQUAL,
      D3D11_STENCIL_OP_KEEP,
      D3D11_STENCIL_OP_KEEP,
      SLODWORD(v93));
    if ( (v111 & 0x1000000) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v24, (int)config, (unsigned int)"texture_normal_mask") )
      {
        v26 = vostok::configs::binary_config_value::operator[](config, "texture_normal_mask");
        pointer = (char *)vostok::configs::binary_config_value::operator[](v26, "value")->data.pointer;
        vostok::render::effect_compiler::set_texture(
          v27,
          (const char *)compiler,
          "t_normal_mask",
          pointer,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      else
      {
        vostok::render::effect_compiler::set_texture(
          v25,
          (const char *)compiler,
          "t_normal_mask",
          (char *)uri,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
    }
    if ( (v111 & 0x20000000) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v24, (int)config, (unsigned int)"texture_smoothness") )
      {
        v29 = vostok::configs::binary_config_value::operator[](config, "texture_smoothness");
        v90 = (char *)vostok::configs::binary_config_value::operator[](v29, "value")->data.pointer;
        vostok::render::effect_compiler::set_texture(
          v30,
          (const char *)compiler,
          "t_smoothness",
          v90,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      else
      {
        vostok::render::effect_compiler::set_texture(
          v28,
          (const char *)compiler,
          "t_smoothness",
          (char *)uri,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v24, (int)config, (unsigned int)"constant_smoothness") )
    {
      v32 = vostok::configs::binary_config_value::operator[](config, "constant_smoothness");
      v33 = vostok::configs::binary_config_value::operator[](v32, "value");
      if ( v33->type == 2 )
        v35 = *(float *)&v33->data.pointer;
      else
        v35 = (float)(int)v33->data.pointer;
      v103 = v35;
      vostok::render::effect_compiler::set_constant<float>(v34, &v103, compiler, "constant_smoothness");
    }
    else
    {
      v104 = 0;
      vostok::render::effect_compiler::set_constant<float>(v31, (float *)&v104, compiler, "constant_smoothness");
    }
    if ( (v111 & 0x10000000) != 0 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v36, (int)config, (unsigned int)"texture_fresnel") )
      {
        v38 = vostok::configs::binary_config_value::operator[](config, "texture_fresnel");
        v91 = (char *)vostok::configs::binary_config_value::operator[](v38, "value")->data.pointer;
        vostok::render::effect_compiler::set_texture(
          v39,
          (const char *)compiler,
          "t_fresnel",
          v91,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      else
      {
        vostok::render::effect_compiler::set_texture(
          v37,
          (const char *)compiler,
          "t_fresnel",
          (char *)uri,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v36, (int)config, (unsigned int)"constant_fresnel") )
    {
      v41 = vostok::configs::binary_config_value::operator[](config, "constant_fresnel");
      v42 = vostok::configs::binary_config_value::operator[](v41, "value");
      if ( v42->type == 2 )
        v44 = *(float *)&v42->data.pointer;
      else
        v44 = (float)(int)v42->data.pointer;
      v105 = v44;
      vostok::render::effect_compiler::set_constant<float>(v43, &v105, compiler, "constant_fresnel");
    }
    else
    {
      v106 = 0;
      vostok::render::effect_compiler::set_constant<float>(v40, (float *)&v106, compiler, "constant_fresnel");
    }
    if ( v99 )
    {
      if ( vostok::configs::binary_config_value::value_exists(v45, (int)config, (unsigned int)"texture_specular_mask") )
      {
        v47 = vostok::configs::binary_config_value::operator[](config, "texture_specular_mask");
        v92 = (char *)vostok::configs::binary_config_value::operator[](v47, "value")->data.pointer;
        vostok::render::effect_compiler::set_texture(
          v48,
          (const char *)compiler,
          "t_specular_mask",
          v92,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
      else
      {
        vostok::render::effect_compiler::set_texture(
          v46,
          (const char *)compiler,
          "t_specular_mask",
          (char *)uri,
          0,
          0xFFFFFFFF,
          0,
          1.0);
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v45, (int)config, (unsigned int)"constant_specular_mask") )
    {
      v50 = vostok::configs::binary_config_value::operator[](config, "constant_specular_mask");
      v51 = vostok::configs::binary_config_value::operator[](v50, "value");
      if ( v51->type == 2 )
        v53 = *(float *)&v51->data.pointer;
      else
        v53 = (float)(int)v51->data.pointer;
      v107 = v53;
      vostok::render::effect_compiler::set_constant<float>(v52, &v107, compiler, "constant_specular_mask");
    }
    else
    {
      v108 = 0;
      vostok::render::effect_compiler::set_constant<float>(v49, (float *)&v108, compiler, "constant_specular_mask");
    }
    if ( !this->m_is_forward )
      vostok::render::effect_compiler::set_alpha_blend(
        v54,
        (int)compiler,
        1,
        D3D11_BLEND_SRC_ALPHA,
        D3D11_BLEND_INV_SRC_ALPHA,
        D3D11_BLEND_OP_ADD,
        D3D11_BLEND_ONE,
        D3D11_BLEND_ONE,
        SLODWORD(v93));
    if ( (v111 & 0x80000) != 0 )
    {
      v55 = vostok::configs::binary_config_value::operator[](config, "texture_diffuse");
      v56 = (char **)vostok::configs::binary_config_value::operator[](v55, "value");
      vostok::render::effect_compiler::set_texture(v57, (const char *)compiler, "t_base", *v56, 1, 5u, 1u, 1.0);
    }
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)v54,
           (int)config,
           (unsigned int)"constant_diffuse") )
    {
      v59 = vostok::configs::binary_config_value::operator[](config, "constant_diffuse");
      v60 = vostok::configs::binary_config_value::operator[](v59, "value");
      v61 = (float *)v60->data.pointer;
      v62 = *(float *)v60->data.pointer;
      __libm_sse2_pow(v93, v96);
      *(float *)&v62 = v62;
      v115.x = *(float *)&v62;
      v63 = v61[1];
      __libm_sse2_pow(v94, v97);
      *(float *)&v63 = v63;
      v115.y = *(float *)&v63;
      v64 = v61[2];
      __libm_sse2_pow(v95, v98);
      *(float *)&v64 = v64;
      v115.z = *(float *)&v64;
      v115.w = v61[3];
      vostok::render::effect_compiler::set_constant<vostok::math::float4>(&v115, v65, compiler, "constant_diffuse");
    }
    if ( vostok::configs::binary_config_value::value_exists(v58, (int)config, (unsigned int)"normal_multiplier") )
    {
      v67 = vostok::configs::binary_config_value::operator[](config, "normal_multiplier");
      v68 = (float **)vostok::configs::binary_config_value::operator[](v67, "value");
      v69 = *v68;
      v110.x = **v68;
      *(_QWORD *)&v110.elements[1] = *(_QWORD *)(v69 + 1);
      vostok::render::effect_compiler::set_constant<vostok::math::float3>(
        &v110,
        v70,
        compiler,
        "constant_normal_multiplier");
    }
    if ( vostok::configs::binary_config_value::value_exists(v66, (int)config, (unsigned int)"diffuse_alpha") )
    {
      v72 = vostok::configs::binary_config_value::operator[](config, "diffuse_alpha");
      v73 = vostok::configs::binary_config_value::operator[](v72, "value");
      if ( v73->type == 2 )
        v75 = *(float *)&v73->data.pointer;
      else
        v75 = (float)(int)v73->data.pointer;
      v109 = v75;
      vostok::render::effect_compiler::set_constant<float>(v74, &v109, compiler, "diffuse_alpha");
    }
    if ( (v111 & 0x800000) != 0 )
    {
      v76 = vostok::configs::binary_config_value::operator[](config, "texture_normal");
      v77 = (char **)vostok::configs::binary_config_value::operator[](v76, "value");
      vostok::render::effect_compiler::set_texture(v78, (const char *)compiler, "t_normal_map", *v77, 1, 5u, 0, 1.0);
    }
    vostok::render::effect_compiler::set_texture(
      v71,
      (const char *)compiler,
      "t_position",
      "$user$position",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v79,
      (const char *)compiler,
      "t_normal",
      "$user$normal",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    vostok::render::effect_compiler::set_texture(
      v80,
      (const char *)compiler,
      "t_parameters",
      "$user$surface_parameters",
      0,
      0xFFFFFFFF,
      0,
      1.0);
    if ( vostok::configs::binary_config_value::value_exists(
           v81,
           (int)config,
           (unsigned int)"blend_with_geometry_normals") )
    {
      if ( vostok::configs::binary_config_value::value_exists(
             v82,
             (int)config,
             (unsigned int)"blend_with_geometry_normals")
        && (v84 = vostok::configs::binary_config_value::operator[](config, "blend_with_geometry_normals"),
            vostok::configs::binary_config_value::operator[](v84, "value")->data.pointer) )
      {
        v85 = s_bm_current_air_resistance;
      }
      else
      {
        v85 = FLOAT_N1_0;
      }
      v102 = v85;
      vostok::render::effect_compiler::set_constant<float>(v83, &v102, compiler, "blend_with_geometry_normals");
    }
    if ( (v112 & 0xC00000) != 0 )
    {
      v86 = vostok::configs::binary_config_value::operator[](config, "texture_cubemap");
      v87 = (char **)vostok::configs::binary_config_value::operator[](v86, "value");
      vostok::render::effect_compiler::set_texture(
        v88,
        (const char *)compiler,
        "t_cubemap",
        *v87,
        0,
        0xFFFFFFFF,
        0,
        1.0);
    }
    vostok::render::effect_material_base::compile_end((vostok::render::effect_material_base *)v82, compiler);
  }
}
