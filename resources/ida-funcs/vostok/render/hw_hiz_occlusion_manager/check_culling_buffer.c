void __userpurge vostok::render::hw_hiz_occlusion_manager::check_culling_buffer(
        unsigned int in_num_bounds@<eax>,
        vostok::render::hw_hiz_occlusion_manager *this)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v5; // eax
  vostok::render::resource_manager *v6; // ecx
  vostok::render::res_texture *texture2d; // eax
  vostok::render::resource_manager *v8; // ecx
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  int z_low; // edi
  vostok::render::backend *v11; // ecx
  vostok::render::res_texture *m_object; // esi
  vostok::render::resource_manager *v13; // ecx
  bool v14; // zf
  vostok::render::render_target *v15; // eax
  vostok::render::res_texture *v16; // esi
  vostok::render::resource_manager *v17; // ecx
  vostok::render::res_texture *v18; // eax
  vostok::render::resource_manager *v19; // [esp-Ch] [ebp-2Ch]
  float v20; // [esp+8h] [ebp-18h]
  unsigned int v21; // [esp+Ch] [ebp-14h]
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> object; // [esp+1Ch] [ebp-4h] BYREF
  ID3D11DeviceContext *m_context; // [esp+28h] [ebp+8h]
  char v24; // [esp+28h] [ebp+8h]

  v3 = this->m_culling_buffer_height * this->m_culling_buffer_width;
  this->m_current_num_bounds = in_num_bounds;
  if ( in_num_bounds > v3 )
  {
    this->m_culling_buffer_width = 256;
    v20 = (double)in_num_bounds * 0.00390625 + s_bm_current_air_resistance;
    v4 = vostok::math::floor(v20);
    this->m_culling_buffer_height = v4;
    v4 <<= 8;
    v19 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
    this->m_hw_hiz_point_list.m_num_points = v4;
    vostok::render::resource_manager::create_buffer(24 * v4, v19, (void *)0x18, enum_buffer_type_vertex, 0, 1, 0);
    vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      v5,
      (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&this->m_hw_hiz_point_list.m_vertex_buffer,
      0);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      0,
      (vostok::render::res_texture *)&this->m_t_culling_result_lockable);
    texture2d = vostok::render::resource_manager::create_texture2d(
                  v6,
                  (const char *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  "$user$hiz_lockable",
                  this->m_culling_buffer_width,
                  (const D3D11_SUBRESOURCE_DATA *)this->m_culling_buffer_height,
                  0,
                  DXGI_FORMAT_R8_UNORM,
                  D3D11_USAGE_STAGING,
                  1u,
                  0);
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      texture2d,
      (vostok::render::res_texture *)&this->m_t_culling_result_lockable);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &this->m_rt_culling_result,
      0);
    render_target = vostok::render::resource_manager::create_render_target(
                      v8,
                      (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                      "$user$hiz_result",
                      this->m_culling_buffer_width,
                      this->m_culling_buffer_height,
                      (char *)0x3D,
                      DXGI_FORMAT_R32G32B32A32_TYPELESS,
                      0,
                      0,
                      0,
                      v21);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &this->m_rt_culling_result,
      (vostok::render::render_target *)render_target);
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    vostok::render::backend::set_render_targets(
      (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      this->m_rt_culling_result.m_object,
      0,
      0,
      0);
    vostok::render::backend::clear_render_targets(v11, z_low, SLODWORD(s_bm_current_air_resistance), 1.0, 1.0, 1.0);
    m_context = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
      &object,
      &this->m_rt_culling_result.m_object->m_texture);
    m_object = object.m_object;
    m_context->CopyResource(
      m_context,
      this->m_t_culling_result_lockable.m_object->m_surface,
      object.m_object->m_surface);
    v14 = m_object->m_reference_count-- == 1;
    if ( v14 )
      vostok::render::resource_manager::release(
        v13,
        (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
        m_object);
    v15 = this->m_rt_culling_result.m_object;
    if ( v15
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v24 = 1;
      vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
        &object,
        &v15->m_texture);
      v16 = object.m_object;
    }
    else
    {
      v16 = 0;
      v24 = 2;
      object.m_object = 0;
    }
    vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &object,
      (vostok::render::res_texture *)&this->m_t_culling_result);
    if ( (v24 & 2) != 0 )
    {
      v24 &= ~2u;
      if ( v16 )
      {
        v14 = v16->m_reference_count-- == 1;
        if ( v14 )
          vostok::render::resource_manager::release(
            v17,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v16);
      }
    }
    if ( (v24 & 1) != 0 )
    {
      v18 = object.m_object;
      if ( object.m_object )
      {
        v14 = object.m_object->m_reference_count-- == 1;
        if ( v14 )
          vostok::render::resource_manager::release(
            v17,
            (vostok::render::res_texture *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            v18);
      }
    }
  }
}
