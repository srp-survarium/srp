vostok::render::result_struct *__thiscall vostok::render::bake_decal_cook::composition(
        vostok::render::bake_decal_cook *this,
        vostok::render::bake_decal_cook *result,
        const vostok::render::result_struct *decals_result,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> surface,
        vostok::render::render_surface_instance *parameters,
        vostok::render::render_target *width,
        __int64 height)
{
  vostok::render::render_target *v7; // ebx
  vostok::render::render_target *v8; // esi
  bool has_texture_type; // al
  bool v10; // al
  bool v11; // al
  bool v12; // al
  vostok::render::result_struct *v13; // ecx
  vostok::render::render_target *m_object; // eax
  vostok::render::render_target *v15; // ecx
  const vostok::render::render_target *v16; // eax
  int z_low; // esi
  vostok::render::backend *v18; // ecx
  vostok::render::backend *v19; // ecx
  vostok::render::material_effects *material_effects; // eax
  vostok::particle::particle_system_instance_impl *v21; // eax
  vostok::render::res_effect *v22; // ecx
  vostok::render::resource_manager *v23; // ecx
  vostok::render::res_texture_vtbl *v24; // eax
  vostok::render::res_texture *v25; // eax
  vostok::render::res_texture *v26; // edi
  vostok::render::backend *v27; // ecx
  vostok::render::resource_manager *v28; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *default_texture; // eax
  vostok::render::backend *v30; // ecx
  vostok::render::resource_intrusive_base *v31; // eax
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *m_reference_count; // eax
  vostok::render::res_texture *v33; // eax
  vostok::render::res_texture *v34; // edi
  vostok::render::backend *v35; // ecx
  vostok::render::resource_manager *v36; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v37; // eax
  vostok::render::backend *v38; // ecx
  vostok::render::resource_intrusive_base *v39; // eax
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v40; // eax
  vostok::render::res_texture *v41; // eax
  vostok::render::res_texture *v42; // edi
  vostok::render::backend *v43; // ecx
  vostok::render::resource_manager *v44; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v45; // eax
  vostok::render::backend *v46; // ecx
  vostok::render::resource_intrusive_base *v47; // eax
  const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *num_mips; // eax
  vostok::render::res_texture *v49; // eax
  vostok::render::res_texture *v50; // edi
  vostok::render::backend *v51; // ecx
  vostok::render::resource_manager *v52; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v53; // eax
  vostok::render::backend *v54; // ecx
  vostok::render::resource_manager *v55; // ecx
  vostok::render::resource_intrusive_base *v56; // eax
  double v57; // st7
  vostok::render::resource_manager *v58; // ecx
  vostok::render::resource_manager *v59; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v60; // eax
  vostok::render::backend *v61; // ecx
  _DWORD *v62; // eax
  vostok::render::resource_manager *v63; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v64; // eax
  vostok::render::backend *v65; // ecx
  _DWORD *v66; // eax
  vostok::render::resource_manager *v67; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v68; // eax
  vostok::render::backend *v69; // ecx
  _DWORD *v70; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v71; // eax
  vostok::render::backend *v72; // ecx
  vostok::render::resource_manager *v73; // ecx
  _DWORD *v74; // eax
  bool v75; // al
  float z; // esi
  vostok::render::backend *v77; // ecx
  bool v78; // zf
  D3D11_USAGE m_memory_usage_type; // ecx
  ID3D11Texture2D *m_surface; // eax
  BOOL v81; // ecx
  float v82; // xmm0_4
  vostok::render::backend *v83; // ecx
  vostok::render::shader_constant_host *m_use_compression_parameter; // eax
  bool v86; // [esp+0h] [ebp-50h]
  bool v87; // [esp+4h] [ebp-4Ch]
  const vostok::render::render_target *v88; // [esp+4h] [ebp-4Ch]
  vostok::render::shader_constant_host *m_decal_texture_use_flags_parameter; // [esp+4h] [ebp-4Ch]
  vostok::render::shader_constant_host *m_camouflage_texture_use_flags_parameter; // [esp+4h] [ebp-4Ch]
  vostok::render::shader_constant_host *m_camouflage_scale_parameter; // [esp+4h] [ebp-4Ch]
  bool v92; // [esp+8h] [ebp-48h]
  vostok::render::render_surface *v93; // [esp+8h] [ebp-48h]
  bool v94; // [esp+Ch] [ebp-44h]
  bool v95; // [esp+Ch] [ebp-44h]
  bool v96; // [esp+Ch] [ebp-44h]
  bool v97; // [esp+Ch] [ebp-44h]
  bool v98; // [esp+Ch] [ebp-44h]
  bool v99; // [esp+Ch] [ebp-44h]
  vostok::math::float3 v100; // [esp+1Ch] [ebp-34h] BYREF
  float v101; // [esp+28h] [ebp-28h]
  __int64 v102; // [esp+2Ch] [ebp-24h] BYREF
  __int64 v103; // [esp+34h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v104; // [esp+3Ch] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v105; // [esp+40h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> resulta; // [esp+44h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v107; // [esp+48h] [ebp-8h] BYREF

  v7 = width;
  v8 = 0;
  v107.m_object = 0;
  has_texture_type = vostok::render::bake_decal_parameters::has_texture_type(
                       (vostok::render::bake_decal_parameters *)3,
                       (int)width,
                       enum_dtt_diffuse,
                       v94);
  v10 = vostok::render::bake_decal_parameters::has_texture_type(
          (vostok::render::bake_decal_parameters *)2,
          (int)v7,
          enum_dtt_diffuse,
          has_texture_type);
  v11 = vostok::render::bake_decal_parameters::has_texture_type(
          (vostok::render::bake_decal_parameters *)1,
          (int)v7,
          enum_dtt_diffuse,
          v10);
  v12 = vostok::render::bake_decal_parameters::has_texture_type(0, (int)v7, enum_dtt_diffuse, v11);
  vostok::render::result_struct::result_struct(
    v13,
    &decals_result->diffuse,
    height,
    SHIDWORD(height),
    (DXGI_FORMAT)v12,
    v86,
    v87,
    v92,
    v95);
  if ( !decals_result->smoothness.m_object
    || (width = decals_result->smoothness.m_object,
        !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    width = 0;
  }
  if ( decals_result->fresnel.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    m_object = decals_result->fresnel.m_object;
  }
  else
  {
    m_object = 0;
  }
  v15 = decals_result->normal.m_object;
  if ( !v15
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v15 = 0;
  }
  if ( decals_result->diffuse.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v8 = decals_result->diffuse.m_object;
  }
  v88 = m_object;
  v16 = v8;
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v16,
    v15,
    v88,
    width);
  LOBYTE(v18) = *(_DWORD *)(z_low + 7384) != 0;
  *(_DWORD *)(z_low + 7384) = 0;
  *(_BYTE *)(z_low + 117) |= (unsigned __int8)v18;
  vostok::render::backend::clear_render_targets(v18, z_low, 0, 0.0, 0.0, 0.0);
  vostok::render::set_view_port(height, v19, HIDWORD(height));
  material_effects = vostok::render::render_surface::get_material_effects(v93, (int)parameters->m_render_surface);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v104,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&material_effects->m_effects[1]);
  v21 = v104.m_object;
  LODWORD(v104.m_object[28].m_current_satisfaction_update_tick) = 12;
  vostok::render::res_effect::apply_pass(v22, (int)v21);
  v24 = surface.m_object->__vftable;
  if ( !surface.m_object->__vftable
    || (v23 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) == 0 )
  {
    v25 = (vostok::render::res_texture *)width;
LABEL_20:
    HIBYTE(width) = 0;
    goto LABEL_21;
  }
  v107.m_object = (vostok::particle::particle_system_instance_impl *)1;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&v24[7]);
  v25 = (vostok::render::res_texture *)width;
  if ( !width )
    goto LABEL_20;
  v23 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_20;
  HIBYTE(width) = 1;
LABEL_21:
  if ( ((int)v107.m_object & 1) != 0 )
  {
    v107.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v107.m_object & 0xFFFFFFFE);
    if ( v25 )
    {
      if ( !--v25->m_reference_count )
        vostok::render::resource_manager::release(
          v23,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v25);
    }
  }
  if ( HIBYTE(width) )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&surface.m_object->__vftable[7]);
    v26 = (vostok::render::res_texture *)width;
    vostok::render::backend::set_ps_texture(
      v27,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_diffuse",
      (vostok::render::res_texture *)width);
    if ( v26 )
    {
      if ( !--v26->m_reference_count )
        vostok::render::resource_manager::release(
          v28,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v26);
    }
  }
  else
  {
    default_texture = vostok::render::resource_manager::get_default_texture(
                        v23,
                        (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                        &resulta);
    vostok::render::backend::set_ps_texture(
      v30,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_diffuse",
      default_texture->m_object);
    if ( resulta.m_object )
    {
      v31 = &resulta.m_object->vostok::render::resource_intrusive_base;
      --resulta.m_object->m_reference_count;
      if ( !v31->m_reference_count )
        vostok::render::resource_manager::release(
          v28,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          resulta.m_object);
    }
  }
  m_reference_count = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)surface.m_object->m_reference_count;
  if ( !m_reference_count
    || (v28 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) == 0 )
  {
    v33 = (vostok::render::res_texture *)width;
LABEL_38:
    HIBYTE(width) = 0;
    goto LABEL_39;
  }
  v107.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v107.m_object | 2);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
    m_reference_count + 7);
  v33 = (vostok::render::res_texture *)width;
  if ( !width )
    goto LABEL_38;
  v28 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_38;
  HIBYTE(width) = 1;
LABEL_39:
  if ( ((int)v107.m_object & 2) != 0 )
  {
    v107.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v107.m_object & 0xFFFFFFFD);
    if ( v33 )
    {
      if ( !--v33->m_reference_count )
        vostok::render::resource_manager::release(
          v28,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v33);
    }
  }
  if ( HIBYTE(width) )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(surface.m_object->m_reference_count + 28));
    v34 = (vostok::render::res_texture *)width;
    vostok::render::backend::set_ps_texture(
      v35,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_normal",
      (vostok::render::res_texture *)width);
    if ( v34 )
    {
      if ( !--v34->m_reference_count )
        vostok::render::resource_manager::release(
          v36,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v34);
    }
  }
  else
  {
    v37 = vostok::render::resource_manager::get_default_texture(
            v28,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            &v105);
    vostok::render::backend::set_ps_texture(
      v38,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_normal",
      v37->m_object);
    if ( v105.m_object )
    {
      v39 = &v105.m_object->vostok::render::resource_intrusive_base;
      --v105.m_object->m_reference_count;
      if ( !v39->m_reference_count )
        vostok::render::resource_manager::release(
          v36,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v105.m_object);
    }
  }
  v40 = *(const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&surface.m_object->m_loaded;
  if ( !v40
    || (v36 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) == 0 )
  {
    v41 = (vostok::render::res_texture *)width;
LABEL_56:
    HIBYTE(width) = 0;
    goto LABEL_57;
  }
  v107.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v107.m_object | 4);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
    v40 + 7);
  v41 = (vostok::render::res_texture *)width;
  if ( !width )
    goto LABEL_56;
  v36 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_56;
  HIBYTE(width) = 1;
LABEL_57:
  if ( ((int)v107.m_object & 4) != 0 )
  {
    v107.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v107.m_object & 0xFFFFFFFB);
    if ( v41 )
    {
      if ( !--v41->m_reference_count )
        vostok::render::resource_manager::release(
          v36,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v41);
    }
  }
  if ( HIBYTE(width) )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(*(_DWORD *)&surface.m_object->m_loaded + 28));
    v42 = (vostok::render::res_texture *)width;
    vostok::render::backend::set_ps_texture(
      v43,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_fresnel",
      (vostok::render::res_texture *)width);
    if ( v42 )
    {
      if ( !--v42->m_reference_count )
        vostok::render::resource_manager::release(
          v44,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v42);
    }
  }
  else
  {
    v45 = vostok::render::resource_manager::get_default_texture(
            v36,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            &resulta);
    vostok::render::backend::set_ps_texture(
      v46,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_fresnel",
      v45->m_object);
    if ( resulta.m_object )
    {
      v47 = &resulta.m_object->vostok::render::resource_intrusive_base;
      --resulta.m_object->m_reference_count;
      if ( !v47->m_reference_count )
        vostok::render::resource_manager::release(
          v44,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          resulta.m_object);
    }
  }
  num_mips = (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)surface.m_object->num_mips;
  if ( !num_mips
    || (v44 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) == 0 )
  {
    v49 = (vostok::render::res_texture *)width;
LABEL_74:
    HIBYTE(width) = 0;
    goto LABEL_75;
  }
  v107.m_object = (vostok::particle::particle_system_instance_impl *)((unsigned int)v107.m_object | 8);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&width,
    num_mips + 7);
  v49 = (vostok::render::res_texture *)width;
  if ( !width )
    goto LABEL_74;
  v44 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
  if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    goto LABEL_74;
  HIBYTE(width) = 1;
LABEL_75:
  if ( ((int)v107.m_object & 8) != 0 )
  {
    if ( v49 )
    {
      if ( !--v49->m_reference_count )
        vostok::render::resource_manager::release(
          v44,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v49);
    }
  }
  if ( HIBYTE(width) )
  {
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &surface,
      (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(surface.m_object->num_mips + 28));
    v50 = surface.m_object;
    vostok::render::backend::set_ps_texture(
      v51,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_smoothness",
      surface.m_object);
    if ( v50 )
    {
      if ( !--v50->m_reference_count )
        vostok::render::resource_manager::release(
          v52,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v50);
    }
  }
  else
  {
    v53 = vostok::render::resource_manager::get_default_texture(
            v44,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            &surface);
    vostok::render::backend::set_ps_texture(
      v54,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_decal_smoothness",
      v53->m_object);
    if ( surface.m_object )
    {
      v56 = &surface.m_object->vostok::render::resource_intrusive_base;
      --surface.m_object->m_reference_count;
      if ( !v56->m_reference_count )
        vostok::render::resource_manager::release(
          v55,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          surface.m_object);
    }
  }
  HIBYTE(surface.m_object) = 0;
  if ( (unsigned int)height <= HIDWORD(height) )
  {
    *((float *)&v103 + 1) = s_bm_current_air_resistance;
    *(float *)&v103 = (double)HIDWORD(height) / (double)(unsigned int)height;
  }
  else
  {
    v57 = (double)(unsigned int)height;
    *(float *)&v103 = s_bm_current_air_resistance;
    LODWORD(height) = HIDWORD(height);
    *((float *)&v103 + 1) = v57 / (double)HIDWORD(height);
  }
  v102 = v103;
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v7[12],
    &v107);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v7[12].m_name,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resulta);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v7[12].m_surface,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v105);
  vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>,vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    (const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&v7[13].m_memory_usage_type,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&width);
  if ( v107.m_object
    && (v58 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
  {
    vostok::render::backend::set_ps_texture(
      (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_camouflage_diffuse",
      (vostok::render::res_texture *)v107.m_object->m_lods[0].m_template.m_object);
  }
  else
  {
    v60 = vostok::render::resource_manager::get_default_texture(
            v58,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&height);
    vostok::render::backend::set_ps_texture(
      v61,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_camouflage_normal",
      v60->m_object);
    if ( (_DWORD)height )
    {
      v62 = (_DWORD *)(height + 4);
      --*(_DWORD *)(height + 4);
      if ( !*v62 )
        vostok::render::resource_manager::release(
          v59,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)height);
    }
  }
  if ( resulta.m_object
    && (v59 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
  {
    vostok::render::backend::set_ps_texture(
      (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_camouflage_normal",
      *(vostok::render::res_texture **)&resulta.m_object->m_name.m_string.m_buffer[88]);
  }
  else
  {
    v64 = vostok::render::resource_manager::get_default_texture(
            v59,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&height
          + 1);
    vostok::render::backend::set_ps_texture(
      v65,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_camouflage_normal",
      v64->m_object);
    if ( HIDWORD(height) )
    {
      v66 = (_DWORD *)(HIDWORD(height) + 4);
      --*(_DWORD *)(HIDWORD(height) + 4);
      if ( !*v66 )
        vostok::render::resource_manager::release(
          v63,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)HIDWORD(height));
    }
  }
  if ( v105.m_object
    && (v63 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
  {
    vostok::render::backend::set_ps_texture(
      (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_camouflage_smoothness",
      *(vostok::render::res_texture **)&v105.m_object->m_name.m_string.m_buffer[88]);
  }
  else
  {
    v68 = vostok::render::resource_manager::get_default_texture(
            v63,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&height);
    vostok::render::backend::set_ps_texture(
      v69,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_camouflage_smoothness",
      v68->m_object);
    if ( (_DWORD)height )
    {
      v70 = (_DWORD *)(height + 4);
      --*(_DWORD *)(height + 4);
      if ( !*v70 )
        vostok::render::resource_manager::release(
          v67,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)height);
    }
  }
  if ( width
    && (v67 = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) != 0 )
  {
    vostok::render::backend::set_ps_texture(
      (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_aoac",
      (vostok::render::res_texture *)width[3].m_memory_usage);
    HIBYTE(surface.m_object) = 1;
  }
  else
  {
    v71 = vostok::render::resource_manager::get_default_texture(
            v67,
            (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&height
          + 1);
    vostok::render::backend::set_ps_texture(
      v72,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      "t_aoac",
      v71->m_object);
    if ( HIDWORD(height) )
    {
      v74 = (_DWORD *)(HIDWORD(height) + 4);
      --*(_DWORD *)(HIDWORD(height) + 4);
      if ( !*v74 )
        vostok::render::resource_manager::release(
          v73,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          (vostok::render::res_texture *)HIDWORD(height));
    }
  }
  *(float *)&height = (float)vostok::render::bake_decal_parameters::has_texture_type(0, (int)v7, enum_dtt_normal, v96);
  *((float *)&height + 1) = (float)vostok::render::bake_decal_parameters::has_texture_type(
                                     (vostok::render::bake_decal_parameters *)1,
                                     (int)v7,
                                     enum_dtt_normal,
                                     v97);
  *((float *)&v103 + 1) = (float)vostok::render::bake_decal_parameters::has_texture_type(
                                   (vostok::render::bake_decal_parameters *)2,
                                   (int)v7,
                                   enum_dtt_normal,
                                   v98);
  v75 = vostok::render::bake_decal_parameters::has_texture_type(
          (vostok::render::bake_decal_parameters *)3,
          (int)v7,
          enum_dtt_normal,
          v99);
  z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
  *(_QWORD *)&v100.x = height;
  m_decal_texture_use_flags_parameter = result->m_decal_texture_use_flags_parameter;
  v100.z = *((float *)&v103 + 1);
  v101 = (float)v75;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v77,
    (vostok::render::constants_handler<1> *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    m_decal_texture_use_flags_parameter,
    &v100);
  v78 = v7[12].m_reference_count == 0;
  m_memory_usage_type = v7[12].m_memory_usage_type;
  m_surface = v7[12].m_surface;
  LODWORD(height) = v7[12].m_name.m_pointer.m_object;
  v100.x = (float)!v78;
  v81 = m_memory_usage_type != D3D11_USAGE_DEFAULT;
  v100.y = (float)((_DWORD)height != 0);
  v100.z = (float)v81;
  m_camouflage_texture_use_flags_parameter = result->m_camouflage_texture_use_flags_parameter;
  v101 = (float)(m_surface != 0);
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    (vostok::render::backend *)v81,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    m_camouflage_texture_use_flags_parameter,
    &v100);
  surface.m_object = (vostok::render::res_texture *)HIBYTE(surface.m_object);
  vostok::render::backend::set_ps_constant<unsigned int>(
    (vostok::render::backend *)LODWORD(z),
    result->m_use_ao_texture_parameter,
    (const int *)&surface);
  v82 = *(float *)&v7[13].m_surface * *((float *)&v102 + 1);
  m_camouflage_scale_parameter = result->m_camouflage_scale_parameter;
  *(float *)&v102 = *(float *)&v7[13].m_surface * *(float *)&v102;
  *((float *)&v102 + 1) = v82;
  vostok::render::backend::set_ps_constant<vostok::math::float4x4>(
    v83,
    (vostok::render::constants_handler<1> *)LODWORD(z),
    m_camouflage_scale_parameter,
    (const vostok::math::float3 *)&v102);
  m_use_compression_parameter = result->m_use_compression_parameter;
  surface.m_object = (vostok::render::res_texture *)1;
  vostok::render::backend::set_ps_constant<unsigned int>(
    (vostok::render::backend *)LODWORD(z),
    m_use_compression_parameter,
    (const int *)&surface);
  vostok::render::bake_decal_cook::render_unwrapped_surface(
    result,
    parameters,
    (const vostok::math::float4x4 *)&v7[12].m_surface_3d);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&width);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v105);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&resulta);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v107);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v104);
  return (vostok::render::result_struct *)decals_result;
}
