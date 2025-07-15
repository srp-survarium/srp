// bad sp value at call has been detected, the output may be wrong!
void __userpurge vostok::render::stage_particles::render_particle_entries(
        const vostok::fixed_vector<vostok::render::stage_particles::particle_emitter_instance_entry,1024> *entries@<eax>,
        vostok::render::stage_particles *this)
{
  vostok::render::renderer_context **m_begin; // ecx
  vostok::render::stage_particles::particle_emitter_instance_entry *m_end; // esi
  int v4; // eax
  bool i; // zf
  int v7; // esi
  unsigned int v8; // eax
  vostok::render::renderer_context *m_context; // edi
  vostok::render::res_effect *m_object; // eax
  vostok::render::res_effect *v11; // ecx
  vostok::render::renderer_context *v12; // eax
  float x; // esi
  vostok::render::renderer_context *v14; // eax
  vostok::render::particle_shader_constants *v15; // ecx
  vostok::math::float3 *v16; // esi
  vostok::render::render_particle_emitter_instance *v17; // ecx
  vostok::math::float3 v18; // [esp-2Ch] [ebp-4Ch]
  vostok::math::float3 v19; // [esp-20h] [ebp-40h] BYREF
  vostok::math::float3 v20; // [esp-14h] [ebp-34h]
  float z; // [esp-8h] [ebp-28h]
  vostok::particle::enum_particle_screen_alignment v22; // [esp-4h] [ebp-24h]
  vostok::math::float3 v23; // [esp+0h] [ebp-20h]
  vostok::render::stage_particles::particle_emitter_instance_entry *v24; // [esp+10h] [ebp-10h]
  vostok::particle::enum_particle_render_mode debug_mode; // [esp+14h] [ebp-Ch]
  unsigned int v26; // [esp+18h] [ebp-8h]
  vostok::render::renderer_context *context; // [esp+1Ch] [ebp-4h]
  vostok::render::renderer_context **v28; // [esp+28h] [ebp+8h]

  m_begin = (vostok::render::renderer_context **)entries->m_begin;
  m_end = entries->m_end;
  v4 = m_end - entries->m_begin;
  v24 = m_end;
  if ( v4 )
  {
    for ( i = m_begin == (vostok::render::renderer_context **)m_end;
          ;
          i = v28 + 3 == (vostok::render::renderer_context **)v24 )
    {
      v28 = m_begin;
      if ( i )
        break;
      v7 = (int)*m_begin;
      v8 = **(_DWORD **)&(*m_begin)->m_family[2].orig_name.m_buffer[4];
      context = *m_begin;
      v26 = v8;
      if ( v8 )
      {
        m_context = this->m_context;
        debug_mode = m_context->m_scene_view.m_object[4].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
        if ( debug_mode == normal_particle_render_mode
          && vostok::render::render_particle_emitter_instance::get_material_effects(
               (vostok::render::render_particle_emitter_instance *)m_begin,
               v7)->m_effects[16].m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          m_object = vostok::render::render_particle_emitter_instance::get_material_effects(
                       (vostok::render::render_particle_emitter_instance *)m_begin,
                       v7)->m_effects[16].m_object;
          m_object->m_cur_technique = 0;
          vostok::render::res_effect::apply_pass(v11, (int)m_object);
          v23.x = *(float *)(v7 + 372);
          v12 = this->m_context;
          v22 = *(_DWORD *)(v7 + 368);
          *(_QWORD *)&v20.elements[1] = *(_QWORD *)&v12->m_view_pos.x;
          z = v12->m_view_pos.z;
          *(_QWORD *)&v19.elements[1] = *(_QWORD *)&v12->m_camera_right_vector.x;
          v20.x = v12->m_camera_right_vector.z;
          *(_QWORD *)&v18.elements[1] = *(_QWORD *)&v12->m_camera_up_vector.x;
          v19.x = v12->m_camera_up_vector.z;
          x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          v18.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          vostok::render::particle_shader_constants::set(
            (vostok::render::particle_shader_constants *)v12,
            v18,
            v19,
            v20,
            SLODWORD(z),
            v22,
            SLODWORD(v23.x));
          v14 = this->m_context;
          LODWORD(v23.x) = v15;
          v23.x = v14->m_current_time;
          vostok::render::particle_shader_constants::set_time(v15, x, v23);
          v16 = (vostok::math::float3 *)context;
          vostok::render::renderer_context::set_w(
            (const vostok::math::float4x4 *)&context->m_family[1].orig_name.m_buffer[8],
            this->m_context);
          vostok::render::render_particle_emitter_instance::render(
            v17,
            (int)this,
            (int)&v19.y,
            (int)v16,
            v16,
            (const unsigned int)this->m_context,
            v26);
        }
        else
        {
          vostok::render::render_particle_emitter_instance::draw_debug(
            (vostok::render::render_particle_emitter_instance *)m_begin,
            v7,
            COERCE_FLOAT((vostok::render::renderer_context *)&m_context->m_v),
            (const vostok::math::float4x4 *)debug_mode);
        }
      }
      m_begin = v28 + 3;
    }
  }
}
