// bad sp value at call has been detected, the output may be wrong!
void __thiscall vostok::render::stage_particles::render_pre_distortion_particles(
        vostok::render::stage_particles *this,
        vostok::render::render_target *rt)
{
  vostok::render::render_target *v2; // ebx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v3; // eax
  int z_low; // esi
  vostok::render::render_target *v5; // eax
  int v6; // edi
  bool v7; // zf
  const stlp_std::random_access_iterator_tag *v8; // ecx
  vostok::render::render_target *m_begin; // eax
  vostok::particle::render_particle_emitter_instance **m_end; // ecx
  int m_reference_count; // esi
  unsigned int v12; // eax
  vostok::strings::shared::profile *m_object; // edi
  vostok::render::res_effect *v14; // eax
  vostok::render::res_effect *v15; // ecx
  vostok::strings::shared::profile *v16; // eax
  float x; // esi
  vostok::strings::shared::profile *v18; // eax
  vostok::render::particle_shader_constants *v19; // ecx
  vostok::render::ambient_light **v20; // esi
  vostok::render::render_particle_emitter_instance *v21; // ecx
  vostok::math::float4x4 *v22; // eax
  vostok::render::backend *v23; // ecx
  int v24; // ecx
  vostok::math::float3 v25; // [esp-2Ch] [ebp-10A4h]
  vostok::math::float3 v26; // [esp-20h] [ebp-1098h] BYREF
  vostok::math::float3 v27; // [esp-14h] [ebp-108Ch]
  vostok::strings::shared::profile *next_in_hashset; // [esp-8h] [ebp-1080h]
  vostok::particle::enum_particle_screen_alignment v29; // [esp-4h] [ebp-107Ch]
  vostok::math::float3 v30; // [esp+0h] [ebp-1078h]
  vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> v31; // [esp+14h] [ebp-1064h] BYREF
  vostok::math::float4x4 v32; // [esp+1024h] [ebp-54h] BYREF
  unsigned int v33; // [esp+1064h] [ebp-14h]
  vostok::particle::render_particle_emitter_instance **v34; // [esp+1068h] [ebp-10h]
  vostok::particle::enum_particle_render_mode debug_mode; // [esp+106Ch] [ebp-Ch]
  vostok::render::ambient_light **end; // [esp+1070h] [ebp-8h] BYREF

  v2 = rt;
  v3 = vostok::render::renderer_context::get_rt(
         (vostok::render::renderer_context *)rt->m_name.m_pointer.m_object,
         rt_generic_0,
         (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&rt);
  z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  vostok::render::backend::set_render_targets(
    (vostok::render::backend *)LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    v3->m_object,
    0,
    0,
    0);
  v5 = rt;
  if ( rt )
  {
    --rt->m_reference_count;
    if ( !v5->m_reference_count )
    {
      vostok::render::resource_manager::release(rt, vostok::quasi_singleton<vostok::render::resource_manager>::pinst);
      z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
    }
  }
  v6 = *(_DWORD *)(z_low + 7440);
  v7 = *(_DWORD *)(z_low + 7384) == v6;
  *(_DWORD *)(z_low + 7384) = v6;
  *(_BYTE *)(z_low + 117) |= !v7;
  vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024>(
    &v31,
    (const vostok::fixed_vector<vostok::particle::render_particle_emitter_instance *,1024> *)(v2->m_name.m_pointer.m_object[1016].m_checksum
                                                                                            + 56568));
  LOBYTE(rt) = v2->m_memory_usage == 0;
  LOBYTE(v8) = (_BYTE)rt;
  end = (vostok::render::ambient_light **)v31.m_end;
  rt = (vostok::render::render_target *)stlp_std::remove_if<vostok::particle::render_particle_emitter_instance * *,vostok::render::remove_particle_emitter_predicate>(
                                          v31.m_begin,
                                          v8,
                                          v31.m_end,
                                          (vostok::render::remove_particle_emitter_predicate)rt);
  vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
    (vostok::buffer_vector<vostok::render::ambient_light *> *)&v31,
    (vostok::render::ambient_light ***)&rt,
    &end);
  m_begin = (vostok::render::render_target *)v31.m_begin;
  m_end = v31.m_end;
  rt = (vostok::render::render_target *)v31.m_begin;
  v34 = v31.m_end;
  if ( v31.m_begin != v31.m_end )
  {
    do
    {
      m_reference_count = m_begin->m_reference_count;
      v12 = **(_DWORD **)(m_begin->m_reference_count + 340);
      end = (vostok::render::ambient_light **)m_reference_count;
      v33 = v12;
      if ( v12 )
      {
        m_object = v2->m_name.m_pointer.m_object;
        debug_mode = *(_DWORD *)(m_object[1016].m_checksum + 1128);
        if ( debug_mode == normal_particle_render_mode
          && vostok::render::render_particle_emitter_instance::get_material_effects(
               (vostok::render::render_particle_emitter_instance *)m_end,
               m_reference_count)->m_effects[16].m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          v14 = vostok::render::render_particle_emitter_instance::get_material_effects(
                  (vostok::render::render_particle_emitter_instance *)m_end,
                  m_reference_count)->m_effects[16].m_object;
          v14->m_cur_technique = 0;
          vostok::render::res_effect::apply_pass(v15, (int)v14);
          v30.x = *(float *)(m_reference_count + 372);
          v16 = v2->m_name.m_pointer.m_object;
          v29 = *(_DWORD *)(m_reference_count + 368);
          *(_QWORD *)&v27.elements[1] = *(_QWORD *)&v16[1320].m_checksum;
          next_in_hashset = v16[1321].next_in_hashset;
          *(_QWORD *)&v26.elements[1] = *(_QWORD *)&v16[1015].m_checksum;
          LODWORD(v27.x) = v16[1016].next_in_hashset;
          *(_QWORD *)&v25.elements[1] = *(_QWORD *)&v16[1015].m_reference_count;
          LODWORD(v26.x) = v16[1015].m_length;
          x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          v25.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          vostok::render::particle_shader_constants::set(
            (vostok::render::particle_shader_constants *)v16,
            v25,
            v26,
            v27,
            (vostok::particle::enum_particle_locked_axis)next_in_hashset,
            v29,
            SLODWORD(v30.x));
          v18 = v2->m_name.m_pointer.m_object;
          LODWORD(v30.x) = v19;
          v30.x = *(float *)&v18[732].next_in_hashset;
          vostok::render::particle_shader_constants::set_time(v19, x, v30);
          v20 = end;
          vostok::render::renderer_context::set_w(
            (const vostok::math::float4x4 *)(end + 46),
            (vostok::render::renderer_context *)v2->m_name.m_pointer.m_object);
          vostok::render::render_particle_emitter_instance::render(
            v21,
            (int)v2,
            (int)&v26.y,
            (int)v20,
            (vostok::math::float3 *)v20,
            (const unsigned int)v2->m_name.m_pointer.m_object,
            v33);
        }
        else
        {
          vostok::render::render_particle_emitter_instance::draw_debug(
            (vostok::render::render_particle_emitter_instance *)m_end,
            m_reference_count,
            COERCE_FLOAT((vostok::strings::shared::profile *)((char *)m_object + 19508)),
            (const vostok::math::float4x4 *)debug_mode);
        }
      }
      m_begin = (vostok::render::render_target *)&rt->m_name;
      rt = m_begin;
    }
    while ( m_begin != (vostok::render::render_target *)v34 );
    z_low = LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z);
  }
  v22 = vostok::math::float4x4::identity((vostok::math::float4x4 *)m_end, &v32);
  vostok::render::renderer_context::set_w(v22, (vostok::render::renderer_context *)v2->m_name.m_pointer.m_object);
  vostok::render::backend::reset_render_targets(v23, z_low);
  v24 = *(_DWORD *)(z_low + 7440);
  *(_BYTE *)(z_low + 117) |= *(_DWORD *)(z_low + 7384) != v24;
  *(_DWORD *)(z_low + 7384) = v24;
}
