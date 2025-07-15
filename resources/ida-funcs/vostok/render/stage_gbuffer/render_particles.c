// bad sp value at call has been detected, the output may be wrong!
void __thiscall vostok::render::stage_gbuffer::render_particles(vostok::render::stage_gbuffer *this, int z_only)
{
  int v2; // eax
  int **v3; // edi
  int *v4; // eax
  int v5; // esi
  vostok::render::render_particle_emitter_instance *v6; // ecx
  vostok::render::res_effect *v7; // edi
  vostok::render::material_effects *material_effects; // eax
  int v9; // eax
  float x; // esi
  int v11; // eax
  vostok::render::particle_shader_constants *v12; // ecx
  vostok::math::float3 *v13; // esi
  vostok::render::render_particle_emitter_instance *v14; // ecx
  vostok::math::float3 v15; // [esp-2Ch] [ebp-50h]
  vostok::math::float3 v16; // [esp-20h] [ebp-44h] BYREF
  vostok::math::float3 v17; // [esp-14h] [ebp-38h]
  vostok::particle::enum_particle_locked_axis v18; // [esp-8h] [ebp-2Ch]
  vostok::particle::enum_particle_screen_alignment v19; // [esp-4h] [ebp-28h]
  vostok::math::float3 v20; // [esp+0h] [ebp-24h]
  int *v21; // [esp+10h] [ebp-14h]
  int v22; // [esp+14h] [ebp-10h]
  vostok::render::render_particle_emitter_instance *v23; // [esp+18h] [ebp-Ch]
  int **v24; // [esp+1Ch] [ebp-8h]
  const vostok::math::float4x4 *v25; // [esp+20h] [ebp-4h]

  v2 = *(_DWORD *)(z_only + 4);
  if ( *(int *)((char *)&dword_8B9664 + *(_DWORD *)(v2 + 16264)) )
  {
    v3 = (int **)(*(_DWORD *)(v2 + 16268) + 56568);
    v4 = *v3;
    v24 = v3;
    while ( 1 )
    {
      v21 = v4;
      if ( v4 == v3[1] )
        break;
      v5 = *v4;
      v6 = **(vostok::render::render_particle_emitter_instance ***)(*v4 + 340);
      v22 = *v4;
      v23 = v6;
      if ( v6 )
      {
        v25 = *(const vostok::math::float4x4 **)(*(_DWORD *)(*(_DWORD *)(z_only + 4) + 16268) + 1128);
        if ( !v25
          && vostok::render::render_particle_emitter_instance::get_material_effects(v6, v5)->m_effects[1].m_object
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          if ( s_sort_deferred_particles )
            vostok::render::render_particle_emitter_instance::sort_particles(
              (vostok::render::render_particle_emitter_instance *)(*(_DWORD *)(z_only + 4) + 21132),
              (const vostok::math::float3 *)v5,
              (vostok::render::render_particle_emitter_instance::sort_particles::__l2::particle_entry *)1);
          v7 = *(vostok::render::res_effect **)(z_only + 100);
          material_effects = vostok::render::render_particle_emitter_instance::get_material_effects(v6, v5);
          vostok::render::res_effect::apply(v7, (int)material_effects->m_effects[1].m_object);
          v20.x = *(float *)(v5 + 372);
          v9 = *(_DWORD *)(z_only + 4);
          v19 = *(_DWORD *)(v5 + 368);
          *(_QWORD *)&v17.elements[1] = *(_QWORD *)(v9 + 21132);
          v18 = *(_DWORD *)(v9 + 21140);
          *(_QWORD *)&v16.elements[1] = *(_QWORD *)(v9 + 16252);
          v17.x = *(float *)(v9 + 16260);
          *(_QWORD *)&v15.elements[1] = *(_QWORD *)(v9 + 16240);
          v16.x = *(float *)(v9 + 16248);
          x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          v15.x = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x;
          vostok::render::particle_shader_constants::set(
            (vostok::render::particle_shader_constants *)v9,
            v15,
            v16,
            v17,
            v18,
            v19,
            SLODWORD(v20.x));
          v11 = *(_DWORD *)(z_only + 4);
          LODWORD(v20.x) = v12;
          v20.x = *(float *)(v11 + 11716);
          vostok::render::particle_shader_constants::set_time(v12, x, v20);
          v13 = (vostok::math::float3 *)v22;
          vostok::render::renderer_context::set_w(
            (const vostok::math::float4x4 *)(v22 + 184),
            *(vostok::render::renderer_context **)(z_only + 4));
          vostok::render::render_particle_emitter_instance::render(
            v14,
            z_only,
            (int)&v16.y,
            (int)v13,
            v13,
            *(_DWORD *)(z_only + 4),
            (unsigned int)v23);
          v3 = v24;
        }
        else
        {
          vostok::render::render_particle_emitter_instance::draw_debug(
            v6,
            v5,
            COERCE_FLOAT(*(_DWORD *)(z_only + 4) + 19508),
            v25);
        }
        v4 = v21;
      }
      ++v4;
    }
  }
}
