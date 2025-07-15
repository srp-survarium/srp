void __userpurge vostok::render::grass_patch::grass_patch(
        vostok::render::grass_patch *this@<edi>,
        const vostok::math::float3 *in_origin@<eax>,
        unsigned int a3@<ebp>,
        unsigned int a4@<esi>,
        vostok::collision::space_partitioning_tree *const in_collision_tree,
        vostok::render::grass_template *templ,
        float in_size)
{
  const vostok::math::float4x4 *v7; // xmm0_4
  survarium::game_action_id *M_start; // edx
  vostok::render::render_target *render_target; // eax
  vostok::render::render_target *v10; // ecx
  const char *m_object; // eax
  bool v12; // zf
  vostok::render::res_texture *v13; // eax
  vostok::render::res_texture *v14; // ebp
  vostok::render::res_texture *v15; // eax
  vostok::render::res_texture *v16; // ecx
  vostok::render::res_texture *v17; // eax
  float v18; // xmm0_4
  __int64 v19; // xmm6_8
  float v20; // xmm3_4
  __int64 v21; // [esp+0h] [ebp-28h]
  __int64 v22; // [esp+0h] [ebp-28h]
  __int128 v23; // [esp+14h] [ebp-14h]

  *(_QWORD *)&this->m_prev_view_pos.x = 0;
  this->m_prev_view_pos.z = 0.0;
  this->m_movement_rt.m_object = 0;
  this->m_movement_texture.m_object = 0;
  *(_QWORD *)&this->m_aabb.min.x = 0xBF800000BF800000uLL;
  v7 = clear_value;
  this->m_aabb.min.z = -1.0;
  LODWORD(v21) = v7;
  HIDWORD(v21) = v7;
  *(_QWORD *)&this->m_aabb.max.x = v21;
  LODWORD(this->m_aabb.max.z) = v7;
  this->m_origin = *in_origin;
  this->m_size = 16.0;
  this->m_occlusion_info_index = -1;
  this->m_current_lod_index = 0;
  this->m_instances._M_impl._M_start = 0;
  this->m_instances._M_impl._M_finish = 0;
  this->m_instances._M_impl._M_end_of_storage._M_data = 0;
  `vector constructor iterator'(
    (char *)this->m_geometry,
    4u,
    3,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  `vector constructor iterator'(
    (char *)this->m_vb_stream_1,
    4u,
    3,
    (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>);
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  this->m_template = templ;
  this->m_collision_tree = in_collision_tree;
  this->m_collision_geometry = 0;
  this->m_collision_object = 0;
  this->m_visible = 1;
  this->m_occluded = 0;
  this->m_merged_indices[0] = 0;
  this->m_sort_info[0] = 0;
  this->m_merged_indices[1] = 0;
  this->m_sort_info[1] = 0;
  this->m_merged_indices[2] = 0;
  this->m_sort_info[2] = 0;
  if ( *((_BYTE *)M_start + 304) )
  {
    render_target = vostok::render::resource_manager::create_render_target(
                      (vostok::render::resource_manager *)in_collision_tree,
                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                      0,
                      (vostok::render::res_texture *)0x40,
                      (ID3D11Texture2D **)0x40,
                      (const char *)0x3D,
                      enum_rt_usage_render_target,
                      0,
                      0,
                      a4,
                      a3);
    v10 = 0;
    if ( render_target )
    {
      ++render_target->m_reference_count;
      v10 = render_target;
    }
    m_object = (const char *)this->m_movement_rt.m_object;
    this->m_movement_rt.m_object = v10;
    if ( m_object )
    {
      v12 = (*(_DWORD *)m_object)-- == 1;
      if ( v12 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          m_object);
    }
    v13 = this->m_movement_rt.m_object->m_texture.m_object;
    v14 = 0;
    if ( v13 )
    {
      v14 = this->m_movement_rt.m_object->m_texture.m_object;
      ++v13->m_reference_count;
    }
    v15 = 0;
    if ( v14 )
    {
      ++v14->m_reference_count;
      v15 = v14;
    }
    v16 = v15;
    v17 = this->m_movement_texture.m_object;
    this->m_movement_texture.m_object = v16;
    if ( v17 )
    {
      v12 = v17->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::res_texture::destroy_impl(v16, v17);
    }
    if ( v14 )
    {
      v12 = v14->m_reference_count-- == 1;
      if ( v12 )
        vostok::render::res_texture::destroy_impl(v16, v14);
    }
  }
  v18 = this->m_size * 0.5;
  *(float *)&v22 = this->m_origin.x - v18;
  *((float *)&v22 + 1) = this->m_origin.y - 0.1;
  v19 = v22;
  v20 = this->m_origin.z + v18;
  *(float *)&v22 = this->m_origin.x + v18;
  *((float *)&v22 + 1) = this->m_origin.y + 0.1;
  *(_QWORD *)((char *)&v23 + 4) = v22;
  *(float *)&v23 = this->m_origin.z - v18;
  *(_QWORD *)&this->m_aabb.min.x = v19;
  *((float *)&v23 + 3) = v20;
  *(_OWORD *)&this->m_aabb.min.elements[2] = v23;
}
