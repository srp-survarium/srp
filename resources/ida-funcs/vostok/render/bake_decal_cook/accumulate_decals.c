vostok::render::result_struct *__userpurge vostok::render::bake_decal_cook::accumulate_decals@<eax>(
        vostok::render::bake_decal_cook *this@<ecx>,
        vostok::math::float4x4 *result,
        vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *surface,
        vostok::render::render_surface_instance *parameters,
        unsigned int width,
        unsigned int height,
        unsigned __int32 occlusion_size,
        DXGI_FORMAT format,
        DXGI_FORMAT occlusion_buffer_format)
{
  bool has_texture_type; // al
  bool v10; // al
  bool v11; // al
  bool v12; // al
  vostok::render::result_struct *v13; // ecx
  vostok::render::render_target *v14; // edx
  vostok::render::render_target *v15; // ecx
  vostok::render::render_target *v16; // eax
  int z_low; // esi
  bool v18; // zf
  vostok::render::backend *v19; // ecx
  vostok::render::backend *v20; // ecx
  const vostok::render::render_target *v21; // eax
  vostok::math::float4x4 *v22; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v23; // eax
  vostok::render::resource_manager *v24; // ecx
  vostok::render::resource_intrusive_base *v25; // eax
  vostok::render::render_target *v26; // edx
  vostok::render::render_target *v27; // ecx
  vostok::render::render_target *v28; // eax
  float z; // esi
  vostok::render::backend *v30; // ecx
  vostok::render::res_texture *v31; // ecx
  vostok::render::bake_decal_cook *v32; // ecx
  vostok::render::resource_manager *v33; // ecx
  vostok::render::res_texture *v34; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v36; // [esp+0h] [ebp-B4h] BYREF
  unsigned int v37; // [esp+4h] [ebp-B0h]
  DXGI_FORMAT v38; // [esp+8h] [ebp-ACh]
  DXGI_FORMAT v39; // [esp+Ch] [ebp-A8h]
  vostok::math::float4x4 v40; // [esp+1Ch] [ebp-98h] BYREF
  vostok::math::float4x4 surfacea; // [esp+5Ch] [ebp-58h] BYREF
  const vostok::render::render_target *v42; // [esp+A0h] [ebp-14h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v43; // [esp+A4h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v44; // [esp+A8h] [ebp-Ch] BYREF
  DXGI_FORMAT v45; // [esp+ACh] [ebp-8h]
  const vostok::render::render_target *m_object; // [esp+B0h] [ebp-4h]

  has_texture_type = vostok::render::bake_decal_parameters::has_texture_type(
                       (vostok::render::bake_decal_parameters *)3,
                       width,
                       enum_dtt_diffuse,
                       v39);
  v10 = vostok::render::bake_decal_parameters::has_texture_type(
          (vostok::render::bake_decal_parameters *)2,
          width,
          enum_dtt_diffuse,
          has_texture_type);
  v11 = vostok::render::bake_decal_parameters::has_texture_type(
          (vostok::render::bake_decal_parameters *)1,
          width,
          enum_dtt_diffuse,
          v10);
  v12 = vostok::render::bake_decal_parameters::has_texture_type(0, width, enum_dtt_diffuse, v11);
  vostok::render::result_struct::result_struct(
    v13,
    surface,
    height,
    (DXGI_FORMAT)occlusion_size,
    (DXGI_FORMAT)v12,
    (const bool)v36.m_object,
    v37,
    v38,
    v39);
  if ( !surface[3].m_object
    || (m_object = surface[3].m_object,
        !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
  {
    m_object = 0;
  }
  if ( surface[2].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v14 = surface[2].m_object;
  }
  else
  {
    v14 = 0;
  }
  if ( surface[1].m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v15 = surface[1].m_object;
  }
  else
  {
    v15 = 0;
  }
  v16 = surface->m_object;
  if ( !surface->m_object
    || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v16 = 0;
  }
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v16,
    v15,
    v14,
    m_object);
  v18 = *(_DWORD *)(z_low + 7384) == 0;
  *(_DWORD *)(z_low + 7384) = 0;
  LOBYTE(v19) = !v18;
  *(_BYTE *)(z_low + 117) |= !v18;
  vostok::render::backend::clear_render_targets(v19, z_low, 0, 0.0, 0.0, 0.0);
  vostok::render::set_view_port(height, v20, occlusion_size);
  v45 = DXGI_FORMAT_UNKNOWN;
  m_object = (const vostok::render::render_target *)(width + 64);
  do
  {
    v21 = m_object;
    v22 = 0;
    while ( !v21->m_reference_count )
    {
      v22 = (vostok::math::float4x4 *)((char *)v22 + 1);
      v21 = (const vostok::render::render_target *)((char *)v21 + 4);
      if ( (unsigned int)v22 >= 4 )
        goto LABEL_39;
    }
    qmemcpy(&surfacea, vostok::math::float4x4::identity(v22, &v40), sizeof(surfacea));
    v44.m_object = 0;
    v23 = vostok::render::bake_decal_cook::occlusion(
            0,
            (vostok::render::render_target *)result,
            &v43,
            &surfacea,
            parameters,
            width,
            v45,
            v39);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v23,
      (vostok::render::res_texture *)&v44);
    if ( v43.m_object )
    {
      v25 = &v43.m_object->vostok::render::resource_intrusive_base;
      --v43.m_object->m_reference_count;
      if ( !v25->m_reference_count )
        vostok::render::resource_manager::release(
          v24,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v43.m_object);
    }
    if ( !surface[3].m_object
      || (v42 = surface[3].m_object,
          !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr) )
    {
      v42 = 0;
    }
    if ( surface[2].m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v26 = surface[2].m_object;
    }
    else
    {
      v26 = 0;
    }
    v27 = surface[1].m_object;
    if ( !v27
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v27 = 0;
    }
    v28 = surface->m_object;
    if ( !surface->m_object
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v28 = 0;
    }
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      v28,
      v27,
      v26,
      v42);
    v38 = occlusion_size;
    v18 = *(_DWORD *)(LODWORD(z) + 7384) == 0;
    *(_DWORD *)(LODWORD(z) + 7384) = 0;
    LOBYTE(v30) = !v18;
    *(_BYTE *)(LODWORD(z) + 117) |= !v18;
    vostok::render::set_view_port(height, v30, v38);
    v31 = (vostok::render::res_texture *)v38;
    v38 = v45;
    v37 = width;
    v36.m_object = v31;
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &v36,
      &v44);
    vostok::render::bake_decal_cook::accumulate_decal(
      v32,
      (vostok::render::bake_decal_cook *)result,
      &surfacea,
      (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)parameters,
      v36.m_object,
      v37,
      v38);
    v34 = v44.m_object;
    if ( v44.m_object )
    {
      --v44.m_object->m_reference_count;
      if ( !v34->m_reference_count )
        vostok::render::resource_manager::release(
          v33,
          (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          v34);
    }
LABEL_39:
    ++v45;
    m_object = (const vostok::render::render_target *)((char *)m_object + 80);
  }
  while ( (unsigned int)v45 < DXGI_FORMAT_R16G16B16A16_FLOAT );
  return (vostok::render::result_struct *)surface;
}
