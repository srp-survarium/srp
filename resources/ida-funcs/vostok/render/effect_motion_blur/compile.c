void __thiscall vostok::render::effect_motion_blur::compile(
        vostok::render::effect_motion_blur *this,
        vostok::render::effect_compiler *compiler,
        const vostok::configs::binary_config_value *config,
        const vostok::render::surface_effect_parameters *parameters)
{
  vostok::render::effect_compiler *v4; // ecx
  vostok::render::effect_compiler *v5; // ecx
  vostok::render::effect_compiler *v6; // ecx
  vostok::render::effect_compiler *v7; // ecx
  vostok::render::effect_compiler *v8; // ecx
  vostok::render::effect_compiler *v9; // ecx
  vostok::render::effect_compiler *v10; // ecx
  vostok::render::effect_compiler *v11; // ecx
  vostok::render::effect_compiler *v12; // ecx
  vostok::render::effect_compiler *v13; // ecx
  vostok::render::effect_compiler *v14; // ecx
  vostok::render::effect_compiler *v15; // ecx
  vostok::render::effect_compiler *v16; // ecx
  vostok::render::effect_compiler *v17; // ecx
  vostok::render::effect_compiler *v18; // ecx
  vostok::render::effect_compiler *v19; // ecx
  vostok::render::effect_compiler *v20; // ecx
  vostok::render::effect_compiler *v21; // ecx
  vostok::render::effect_compiler *v22; // ecx
  vostok::render::effect_compiler *v23; // ecx
  vostok::render::effect_compiler *v24; // ecx
  vostok::render::effect_compiler *v25; // ecx
  vostok::render::effect_compiler *v26; // ecx
  vostok::render::effect_compiler *v27; // ecx
  vostok::render::effect_compiler *v28; // ecx
  vostok::render::effect_compiler *v29; // ecx
  vostok::render::effect_compiler *v30; // ecx
  vostok::render::effect_compiler *v31; // ecx
  vostok::render::effect_compiler *v32; // ecx
  vostok::render::shader_configuration v33; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v34; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v35; // [esp-10h] [ebp-34h]
  vostok::render::shader_configuration v36; // [esp-10h] [ebp-34h]
  D3D11_COMPARISON_FUNC v37; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v38; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v39; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v40; // [esp+4h] [ebp-20h]
  D3D11_COMPARISON_FUNC v41; // [esp+4h] [ebp-20h]
  D3D11_BLEND_OP v42; // [esp+4h] [ebp-20h]
  __int64 v43; // [esp+1Ch] [ebp-8h]

  vostok::render::effect_compiler::begin_technique((vostok::render::effect_compiler *)this, (int)compiler);
  *(_DWORD *)&v33.0 = "motion_blur";
  *(unsigned __int64 *)((char *)v33.configuration + 4) = 0;
  HIDWORD(v33.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v4, (int)compiler, "motion_blur", 0, v33, 0);
  vostok::render::effect_compiler::set_depth(v5, (int)compiler, 0, 0, v37);
  vostok::render::effect_compiler::set_texture(
    v6,
    (const char *)compiler,
    "t_frame_color",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v7,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v8,
    (const char *)compiler,
    "t_object_motion_vectors",
    "$user$object_motion_vectors",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v9, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v10,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v11, (int)compiler);
  *(_DWORD *)&v34.0 = "motion_blur";
  *(unsigned __int64 *)((char *)v34.configuration + 4) = 0;
  HIDWORD(v34.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v12, (int)compiler, "motion_blur", 0, v34, 0);
  vostok::render::effect_compiler::set_depth(v13, (int)compiler, 0, 0, v38);
  vostok::render::effect_compiler::set_texture(
    v14,
    (const char *)compiler,
    "t_frame_color",
    "$user$motion_blur_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v15,
    (const char *)compiler,
    "t_position",
    "$user$position",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_texture(
    v16,
    (const char *)compiler,
    "t_object_motion_vectors",
    "$user$object_motion_vectors",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::end_pass(v17, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v18,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v19, (int)compiler);
  *(_DWORD *)&v35.0 = "motion_blur_apply";
  *(unsigned __int64 *)((char *)v35.configuration + 4) = 0;
  HIDWORD(v35.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v20, (int)compiler, "motion_blur", 0, v35, 0);
  vostok::render::effect_compiler::set_depth(v21, (int)compiler, 0, 0, v39);
  vostok::render::effect_compiler::set_texture(
    v22,
    (const char *)compiler,
    "t_motion_blur_result",
    "$user$motion_blur_result",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v23,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v40);
  vostok::render::effect_compiler::end_pass(v24, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v25,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::begin_technique(v26, (int)compiler);
  v43 = 0x80000;
  *(_DWORD *)&v36.0 = "motion_blur_apply";
  *(unsigned __int64 *)((char *)v36.configuration + 4) = 0;
  HIDWORD(v36.configuration[1]) = 0x80000;
  vostok::render::effect_compiler::begin_pass(v27, (int)compiler, "motion_blur", 0, v36, 0);
  vostok::render::effect_compiler::set_depth(v28, (int)compiler, 0, 0, v41);
  vostok::render::effect_compiler::set_texture(
    v29,
    (const char *)compiler,
    "t_motion_blur_result",
    "$user$present_downsampled",
    0,
    0xFFFFFFFF,
    0,
    1.0);
  vostok::render::effect_compiler::set_alpha_blend(
    v30,
    (int)compiler,
    1,
    D3D11_BLEND_SRC_ALPHA,
    D3D11_BLEND_INV_SRC_ALPHA,
    D3D11_BLEND_OP_ADD,
    D3D11_BLEND_ONE,
    D3D11_BLEND_ZERO,
    v42);
  vostok::render::effect_compiler::end_pass(v31, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v32,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
