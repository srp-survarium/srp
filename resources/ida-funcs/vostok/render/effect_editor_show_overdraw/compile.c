void __userpurge vostok::render::effect_editor_show_overdraw::compile(
        vostok::render::effect_editor_show_overdraw *this@<ecx>,
        D3D11_COMPARISON_FUNC a2@<edi>,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *__formal,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v5; // ecx
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // esi
  _DWORD *v9; // edi
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_constant_storage *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::shader_configuration v17; // [esp-20h] [ebp-27Ch]
  D3D11_COMPARISON_FUNC v18; // [esp-Ch] [ebp-268h]
  D3D11_BLEND_OP v19; // [esp-Ch] [ebp-268h]
  D3D11_STENCIL_OP v20; // [esp-Ch] [ebp-268h]
  int v21; // [esp+4h] [ebp-258h]
  unsigned int v22; // [esp+8h] [ebp-254h]
  _DWORD v23[4]; // [esp+1Ch] [ebp-240h] BYREF
  _DWORD v24[4]; // [esp+2Ch] [ebp-230h] BYREF
  _DWORD v25[4]; // [esp+3Ch] [ebp-220h] BYREF
  _DWORD v26[4]; // [esp+4Ch] [ebp-210h] BYREF
  _OWORD v27[32]; // [esp+5Ch] [ebp-200h] BYREF

  *(float *)v24 = FLOAT_0_80000001;
  *(float *)&v24[1] = FLOAT_0_80000001;
  *(float *)&v23[1] = c_anim_center;
  *(float *)&v25[1] = FLOAT_0_40000001;
  v18 = a2;
  v23[0] = 0;
  v23[2] = 0;
  *(float *)&v23[3] = s_bm_current_air_resistance;
  v24[2] = 0;
  *(float *)&v24[3] = s_bm_current_air_resistance;
  *(float *)v25 = s_bm_current_air_resistance;
  *(float *)&v25[2] = FLOAT_0_1;
  *(float *)&v25[3] = s_bm_current_air_resistance;
  *(float *)v26 = s_bm_current_air_resistance;
  v26[1] = 0;
  v26[2] = 0;
  *(float *)&v26[3] = s_bm_current_air_resistance;
  v5 = 0;
  v6 = v27;
  do
  {
    if ( (unsigned int)v5 >= 2 )
    {
      if ( (unsigned int)v5 >= 4 )
      {
        v7 = v25;
        if ( (unsigned int)v5 >= 6 )
          v7 = v26;
      }
      else
      {
        v7 = v24;
      }
    }
    else
    {
      v7 = v23;
    }
    *v6 = *v7;
    v8 = v7 + 1;
    v6[1] = *v8++;
    v6[2] = *v8;
    v9 = v6 + 3;
    v5 = (vostok::render::effect_compiler *)((char *)v5 + 1);
    v6 += 4;
    *v9 = v8[1];
  }
  while ( (unsigned int)v5 < 0x20 );
  v21 = 0;
  do
  {
    vostok::render::effect_compiler::begin_technique(v5, (int)compiler);
    *(_DWORD *)&v17.0 = "editor_show_overdraw";
    *(unsigned __int64 *)((char *)v17.configuration + 4) = 0;
    HIDWORD(v17.configuration[1]) = 0x80000;
    vostok::render::effect_compiler::begin_pass(v10, (int)compiler, "eye_adaptation", 0, v17, 0);
    vostok::render::effect_compiler::set_depth(v11, (int)compiler, 0, 0, v18);
    vostok::render::effect_compiler::set_alpha_blend(
      v12,
      (int)compiler,
      0,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      D3D11_BLEND_OP_ADD,
      D3D11_BLEND_ONE,
      D3D11_BLEND_ZERO,
      v19);
    v22 = v21 + 1;
    if ( v21 == 31 )
      vostok::render::effect_compiler::set_stencil(
        v13,
        (int)compiler,
        1,
        0x20u,
        0xFFu,
        255,
        D3D11_COMPARISON_LESS_EQUAL,
        D3D11_STENCIL_OP_KEEP,
        D3D11_STENCIL_OP_KEEP,
        v20);
    else
      vostok::render::effect_compiler::set_stencil(
        v13,
        (int)compiler,
        1,
        v21 + 1,
        0xFFu,
        255,
        D3D11_COMPARISON_EQUAL,
        D3D11_STENCIL_OP_KEEP,
        D3D11_STENCIL_OP_KEEP,
        v20);
    vostok::render::effect_compiler::set_constant<vostok::math::float4>(
      (const vostok::math::float4 *)&v27[v21],
      v14,
      compiler,
      "show_overdraw_color");
    vostok::render::effect_compiler::end_pass(v15, (int)compiler);
    vostok::render::effect_compiler::end_technique(
      v16,
      (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
    ++v21;
  }
  while ( v22 < 0x20 );
}
