void __userpurge vostok::render::grass_patch::render(
        vostok::render::grass_patch *this@<edi>,
        const vostok::math::float3 *viewer_position@<eax>,
        unsigned int a3@<esi>,
        vostok::render::grass_world *in_grass_world,
        vostok::render::renderer_context *context,
        vostok::render::enum_render_stage_type stage_type,
        vostok::render::res_effect *tech_index,
        float draw_distance,
        vostok::render::res_effect *debug_effect,
        unsigned int cascade_index)
{
  float v10; // xmm3_4
  float v11; // xmm0_4
  float z; // xmm1_4
  unsigned int m_current_lod_index; // eax
  float v14; // xmm1_4
  vostok::render::grass_render_model *m_object; // ecx
  vostok::render::grass_render_surface *v16; // eax
  vostok::render::material_effects_instance *v17; // ecx
  vostok::render::material_effects *v18; // ecx
  vostok::render::material_effects_instance *v19; // ecx
  vostok::render::material_effects *p_m_material_effects; // ecx
  vostok::render::material_effects *material_effects; // eax
  const vostok::math::float4x4 *v22; // eax
  const char *m_conflicted_key_name; // ebx
  float *v24; // eax
  double v25; // st7
  vostok::render::grass_world *v26; // ecx
  vostok::render::grass_render_model *strength; // [esp+0h] [ebp-5Ch]
  float strengtha; // [esp+0h] [ebp-5Ch]
  vostok::math::float2 dir; // [esp+14h] [ebp-48h] BYREF
  vostok::math::float4x4 v30; // [esp+1Ch] [ebp-40h] BYREF

  v10 = viewer_position->x - (float)((float)(this->m_aabb.max.x + this->m_aabb.min.x) * 0.5);
  v11 = viewer_position->y - (float)((float)(this->m_aabb.max.y + this->m_aabb.min.y) * 0.5);
  z = viewer_position->z;
  m_current_lod_index = this->m_current_lod_index;
  v14 = z - (float)((float)(this->m_aabb.max.z + this->m_aabb.min.z) * 0.5);
  strength = 0;
  m_object = this->m_template->m_render_model.m_object;
  if ( m_object )
  {
    strength = this->m_template->m_render_model.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v16 = vostok::render::surface_by_lod(
          m_current_lod_index,
          (vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base>)strength);
  if ( v16 )
  {
    if ( stage_type != sun_shadows_accumulate_render_stage && stage_type != shadow_render_stage
      || ((v17 = v16->m_materail_effects_instance.m_object) == 0 || s_use_one_material_value
        ? (v18 = s_nomaterial_material_effects[v16->m_vertex_input_type])
        : (v18 = &v17->m_material_effects),
          v18->is_cast_shadow) )
    {
      v19 = v16->m_materail_effects_instance.m_object;
      if ( !v19 || s_use_one_material_value )
        p_m_material_effects = s_nomaterial_material_effects[v16->m_vertex_input_type];
      else
        p_m_material_effects = &v19->m_material_effects;
      if ( p_m_material_effects->m_effects[stage_type].m_object
        && (float)((float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v14 * v14)) <= (float)(draw_distance * draw_distance) )
      {
        material_effects = vostok::render::render_surface::get_material_effects(v16);
        vostok::render::res_effect::apply(tech_index, &material_effects->m_effects[stage_type].m_object->__vftable);
        v22 = vostok::math::float4x4::identity(&v30);
        vostok::render::renderer_context::set_w(context, v22);
        vostok::render::res_geometry::apply(this->m_geometry[this->m_current_lod_index].m_object);
        m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
        vostok::render::backend::set_vb_stream_1(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          this->m_vb_stream_1[this->m_current_lod_index].m_object,
          0x10u);
        if ( *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
             + 304) )
        {
          *((_BYTE *)m_conflicted_key_name + 151) = vostok::render::textures_handler<0>::set_overwrite(
                                                      (vostok::render::textures_handler<0> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
                                                      (char *)m_conflicted_key_name + 208,
                                                      (vostok::render::res_texture *)&stru_966A14,
                                                      this->m_movement_texture.m_object);
          vostok::render::grass_world::set_patch_parameters(in_grass_world, this);
        }
        v24 = (float *)context->m_scene_view.m_object;
        v25 = v24[164];
        dir.x = v24[161];
        strengtha = v25;
        dir.y = v24[163];
        vostok::render::grass_world::set_wind_parameters(in_grass_world, &dir, strengtha);
        if ( stage_type == sun_shadows_accumulate_render_stage )
          vostok::render::grass_world::set_shadow_parameters(v26, a3);
        vostok::render::backend::render_indexed(
          (vostok::render::backend *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          this->m_num_merged_indices[this->m_current_lod_index],
          D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
          0,
          0);
        ++vostok::quasi_singleton<vostok::render::statistics>::pinst->grass_stat_group.num_rendered_patches.value;
      }
    }
  }
}
