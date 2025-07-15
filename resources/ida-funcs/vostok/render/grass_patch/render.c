void __thiscall vostok::render::grass_patch::render(
        vostok::render::grass_patch *this,
        vostok::particle::particle_system_instance_impl *in_grass_world,
        vostok::render::renderer_context *context,
        vostok::render::renderer_context *viewer_position,
        const vostok::math::float3 *stage_type,
        const unsigned int tech_index,
        vostok::render::res_effect *draw_distance,
        vostok::render::res_effect *debug_effect,
        int __formal)
{
  vostok::particle::particle_system_instance_impl *v9; // ecx
  float v10; // xmm3_4
  float v11; // xmm0_4
  vostok::resources::resource_link *m_first; // eax
  float v13; // xmm1_4
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_next_link; // edi
  float v15; // xmm6_4
  float v16; // xmm1_4
  float v17; // xmm7_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  unsigned int v23; // xmm2_4
  unsigned int v24; // xmm3_4
  vostok::math::float4x4 *v25; // eax
  vostok::particle::particle_system_instance_impl *v26; // ecx
  vostok::render::grass_render_surface *v27; // eax
  int v28; // edi
  vostok::render::render_surface *m_object; // ecx
  unsigned int v30; // esi
  vostok::render::render_surface *v31; // ecx
  int v32; // eax
  vostok::math::float4x4 *v33; // ecx
  vostok::math::float4x4 *v34; // eax
  vostok::render::base_scene_view *v35; // eax
  unsigned int v36; // xmm1_4
  int z_low; // esi
  volatile int m_reference_count; // xmm0_4
  const vostok::render::shader_constant_host *v39; // eax
  vostok::render::res_geometry *v40; // ecx
  vostok::render::backend *v41; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v42[5]; // [esp-4h] [ebp-6Ch] BYREF
  float v43; // [esp+10h] [ebp-58h]
  float v44; // [esp+14h] [ebp-54h]
  float v45; // [esp+18h] [ebp-50h]
  vostok::math::float3 arg; // [esp+1Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 v47; // [esp+28h] [ebp-40h] BYREF

  if ( !vostok::render::grass_patch::is_occluded(this, (int)in_grass_world) )
  {
    v10 = stage_type->x
        - (float)((float)(*(float *)&in_grass_world->m_memory_usage_self.size
                        + *(float *)&in_grass_world->m_next_in_increase_quality_queue)
                * 0.5);
    v11 = stage_type->y
        - (float)((float)(*(float *)&in_grass_world->m_quality_levels_count
                        + *(float *)&in_grass_world->m_current_satisfaction_update_tick)
                * 0.5);
    m_first = in_grass_world->m_parent_resources.m_first;
    v13 = stage_type->z
        - (float)((float)(in_grass_world->m_current_satisfaction
                        + *((float *)&in_grass_world->m_current_satisfaction_update_tick + 1))
                * 0.5);
    v42[0].m_object = v9;
    p_next_link = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_first[1].next_link;
    v45 = (float)((float)(v10 * v10) + (float)(v11 * v11)) + (float)(v13 * v13);
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v42,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_first[1].next_link);
    v15 = (float)(*(float *)&in_grass_world->m_next_in_increase_quality_queue
                - *(float *)&in_grass_world->m_memory_usage_self.size)
        * 0.5;
    v16 = *(float *)&in_grass_world->m_next_in_increase_quality_queue
        + *(float *)&in_grass_world->m_memory_usage_self.size;
    v17 = (float)(*(float *)&in_grass_world->m_quality_levels_count
                - *(float *)&in_grass_world->m_current_satisfaction_update_tick)
        * 0.5;
    v18 = *(float *)&in_grass_world->m_quality_levels_count
        + *(float *)&in_grass_world->m_current_satisfaction_update_tick;
    v44 = (float)(in_grass_world->m_current_satisfaction
                - *((float *)&in_grass_world->m_current_satisfaction_update_tick + 1))
        * 0.5;
    v19 = stage_type->x - (float)(v16 * 0.5);
    v20 = stage_type->y - (float)(v18 * 0.5);
    v43 = (float)(in_grass_world->m_current_satisfaction
                + *((float *)&in_grass_world->m_current_satisfaction_update_tick + 1))
        * 0.5;
    v21 = stage_type->z - v43;
    v22 = fsqrt((float)((float)(v19 * v19) + (float)(v20 * v20)) + (float)(v21 * v21));
    *(float *)&v23 = (float)((float)(*(float *)&in_grass_world->m_quality_levels_count
                                   + *(float *)&in_grass_world->m_current_satisfaction_update_tick)
                           * 0.5)
                   + (float)((float)(v20 * (float)(s_bm_current_air_resistance / v22)) * v17);
    *(float *)&v24 = (float)((float)(in_grass_world->m_current_satisfaction
                                   + *((float *)&in_grass_world->m_current_satisfaction_update_tick + 1))
                           * 0.5)
                   + (float)((float)(v21 * (float)(s_bm_current_air_resistance / v22)) * v44);
    arg.x = (float)((float)(*(float *)&in_grass_world->m_memory_usage_self.size
                          + *(float *)&in_grass_world->m_next_in_increase_quality_queue)
                  * 0.5)
          + (float)((float)(v19 * (float)(s_bm_current_air_resistance / v22)) * v15);
    *(_QWORD *)&arg.elements[1] = __PAIR64__(v24, v23);
    v25 = vostok::math::create_translation(&arg, &v47);
    v43 = COERCE_FLOAT(vostok::render::get_patch_lod((vostok::math::aabb *)v25, &viewer_position->m_vp, stage_type, v42[0]));
    if ( tech_index == 27 )
      ++LODWORD(v43);
    v42[0].m_object = v26;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      v42,
      p_next_link);
    v27 = vostok::render::surface_by_lod(LODWORD(v43), v42[0]);
    v28 = (int)v27;
    m_object = (vostok::render::render_surface *)v42[0].m_object;
    v44 = *(float *)&v27;
    if ( v27
      && (tech_index && tech_index != 27
       || vostok::render::render_surface::get_material_effects(
            (vostok::render::render_surface *)v42[0].m_object,
            (int)v27)->is_cast_shadow) )
    {
      v30 = 4 * tech_index + 40;
      if ( *(_DWORD *)(&vostok::render::render_surface::get_material_effects(m_object, v28)->is_emissive + v30)
        && v45 <= (float)(*(float *)&debug_effect * *(float *)&debug_effect) )
      {
        v32 = __formal;
        if ( !__formal )
          v32 = *(_DWORD *)(&vostok::render::render_surface::get_material_effects(v31, v28)->is_emissive + v30);
        vostok::render::res_effect::apply(draw_distance, v32);
        v34 = vostok::math::float4x4::identity(v33, &v47);
        vostok::render::renderer_context::set_w(v34, viewer_position);
        v35 = viewer_position->m_scene_view.m_object;
        v36 = *((_DWORD *)&v35[2].m_memory_type_data + 1);
        z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
        LODWORD(arg.x) = v35[2].m_construct_thread_id;
        m_reference_count = v35[2].m_reference_count;
        v42[0].m_object = (vostok::particle::particle_system_instance_impl *)&arg;
        v39 = *(const vostok::render::shader_constant_host **)&context->m_family[2].name.m_buffer[44];
        *(_QWORD *)&arg.elements[1] = __PAIR64__(m_reference_count, v36);
        vostok::render::backend::set_vs_constant<vostok::math::float4x4>(
          (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          v39,
          (const unsigned int *)&arg);
        vostok::render::res_geometry::apply(v40, *(_DWORD *)(v28 + 4));
        vostok::render::backend::set_declaration(
          (vostok::render::backend *)z_low,
          *(vostok::render::res_declaration **)&context->m_family[1].name.m_buffer[12]);
        vostok::render::backend::set_vb_instance_data(
          (vostok::render::backend *)in_grass_world->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
          z_low);
        vostok::render::backend::render_indexed_instanced(
          (vostok::render::backend *)z_low,
          3 * *(_DWORD *)(LODWORD(v44) + 24),
          v41,
          *((_DWORD *)&in_grass_world->vostok::resources::resource_flags + 3),
          (unsigned int)v42[1].m_object,
          (unsigned int)v42[2].m_object,
          (unsigned int)v42[3].m_object,
          (unsigned int)v42[4].m_object);
        ++vostok::quasi_singleton<vostok::render::statistics>::pinst->grass_stat_group.num_rendered_patches.value;
      }
    }
  }
}
