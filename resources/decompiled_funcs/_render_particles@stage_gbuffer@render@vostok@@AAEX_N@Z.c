void __thiscall vostok::render::stage_gbuffer::render_particles(
        vostok::render::stage_gbuffer *this,
        vostok::particle::render_particle_emitter_instance *const *z_only,
        bool z_onlya)
{
  int v4; // eax
  int v5; // ecx
  void **M_start; // eax
  void **v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  vostok::render::render_particle_emitter_instance *v11; // ebx
  int v12; // edx
  vostok::particle::enum_particle_render_mode v13; // esi
  vostok::render::res_effect *m_object; // eax
  unsigned int v15; // ecx
  int v16; // esi
  float v17; // xmm2_4
  vostok::render::particle_shader_constants *v18; // ecx
  vostok::math::float3 v19; // [esp-24h] [ebp-74h]
  vostok::math::float3 v20; // [esp-18h] [ebp-68h]
  vostok::math::float3 v21; // [esp-Ch] [ebp-5Ch]
  unsigned int v22; // [esp+Ch] [ebp-44h]
  float v23; // [esp+20h] [ebp-30h]
  float v24; // [esp+20h] [ebp-30h]
  float v25; // [esp+24h] [ebp-2Ch]
  __int64 v26; // [esp+24h] [ebp-2Ch]
  float v27; // [esp+28h] [ebp-28h]
  float v28; // [esp+2Ch] [ebp-24h]
  float v29; // [esp+30h] [ebp-20h]
  __int64 v30; // [esp+30h] [ebp-20h]
  float v31; // [esp+34h] [ebp-1Ch]
  float v32; // [esp+38h] [ebp-18h]
  vostok::vectora<vostok::particle::render_particle_emitter_instance *> emitters; // [esp+3Ch] [ebp-14h] BYREF
  void **it; // [esp+54h] [ebp+4h]

  v4 = *((_DWORD *)z_only + 1);
  v5 = *(_DWORD *)(*(_DWORD *)(v4 + 12388) + 948);
  if ( v5 )
  {
    emitters._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
    emitters._M_impl._M_start = 0;
    emitters._M_impl._M_finish = 0;
    emitters._M_impl._M_end_of_storage._M_data = 0;
    (*(void (__thiscall **)(int, int, vostok::vectora<vostok::particle::render_particle_emitter_instance *> *))(*(_DWORD *)v5 + 36))(
      v5,
      v4 + 16260,
      &emitters);
    M_start = emitters._M_impl._M_start;
    v7 = emitters._M_impl._M_start;
    it = emitters._M_impl._M_start;
    if ( emitters._M_impl._M_start != emitters._M_impl._M_finish )
    {
      do
      {
        v8 = (int)*v7;
        v9 = *((_DWORD *)*v7 + 275);
        v10 = *(_DWORD *)(v9 + 36);
        v11 = 0;
        if ( v10 )
        {
          do
          {
            v10 = *(_DWORD *)(v10 + 128);
            v11 = (vostok::render::render_particle_emitter_instance *)((char *)v11 + 1);
          }
          while ( v10 );
          if ( v11 )
          {
            v12 = *((_DWORD *)z_only + 1);
            v13 = *(_DWORD *)(*(_DWORD *)(v12 + 12392) + 1208);
            if ( v13
              || !vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v8)->stage_enable[0] )
            {
              vostok::render::render_particle_emitter_instance::draw_debug(
                (vostok::render::render_particle_emitter_instance *)v9,
                v8,
                (const vostok::math::float4x4 *)(v12 + 15620),
                v13);
            }
            else
            {
              m_object = vostok::render::render_particle_emitter_instance::get_material_effects((vostok::render::render_particle_emitter_instance *)v9)->m_effects[0].m_object;
              v15 = z_onlya ? 8 : 0;
              if ( v15 < m_object->m_techniques._M_impl._M_finish - m_object->m_techniques._M_impl._M_start )
              {
                m_object->m_cur_technique = v15;
                vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v15, v22);
              }
              v16 = *((_DWORD *)z_only + 1);
              v17 = (float)((float)(*(float *)(v16 + 15788) + *(float *)(v16 + 15772)) * 0.0)
                  + (float)(*(float *)(v16 + 15756) * 1000.0);
              v25 = (float)((float)(*(float *)(v16 + 15780) + *(float *)(v16 + 15764)) * 0.0)
                  + (float)(*(float *)(v16 + 15748) * 1000.0);
              v27 = (float)((float)(*(float *)(v16 + 15784) + *(float *)(v16 + 15768)) * 0.0)
                  + (float)(*(float *)(v16 + 15752) * 1000.0);
              v23 = 1.0 / sqrtf((float)((float)(v25 * v25) + (float)(v17 * v17)) + (float)(v27 * v27));
              *(float *)&v26 = v23 * v25;
              *((float *)&v26 + 1) = v27 * v23;
              v28 = v17 * v23;
              v29 = (float)((float)(*(float *)(v16 + 15780) + *(float *)(v16 + 15748)) * 0.0)
                  + (float)(*(float *)(v16 + 15764) * 1000.0);
              v31 = (float)((float)(*(float *)(v16 + 15784) + *(float *)(v16 + 15752)) * 0.0)
                  + (float)(*(float *)(v16 + 15768) * 1000.0);
              v32 = (float)((float)(*(float *)(v16 + 15788) + *(float *)(v16 + 15756)) * 0.0)
                  + (float)(*(float *)(v16 + 15772) * 1000.0);
              v24 = 1.0 / sqrtf((float)((float)(v29 * v29) + (float)(v32 * v32)) + (float)(v31 * v31));
              *(float *)&v30 = v24 * v29;
              *((float *)&v30 + 1) = v31 * v24;
              *(_QWORD *)&v21.elements[1] = *(_QWORD *)(v16 + 15796);
              *(_QWORD *)&v20.elements[1] = v26;
              v21.x = v28;
              *(_QWORD *)&v19.elements[1] = v30;
              v19.x = *(float *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_is_active;
              v20.x = v32 * v24;
              vostok::render::particle_shader_constants::set(
                (vostok::render::particle_shader_constants *)LODWORD(v28),
                v19,
                v20,
                v21,
                *(vostok::particle::enum_particle_locked_axis *)(v16 + 15804),
                *(vostok::particle::enum_particle_screen_alignment *)(v8 + 1124));
              vostok::render::particle_shader_constants::set_time(v18, *(float *)(*((_DWORD *)z_only + 1) + 11244));
              vostok::render::renderer_context::set_w(
                *((vostok::render::renderer_context **)z_only + 1),
                (const vostok::math::float4x4 *)(v8 + 944));
              vostok::render::render_particle_emitter_instance::render(
                v11,
                (const vostok::math::float3 *)(*((_DWORD *)z_only + 1) + 15796),
                (vostok::render::render_particle_emitter_instance *)v8);
            }
          }
        }
        v7 = it + 1;
        it = v7;
      }
      while ( v7 != emitters._M_impl._M_finish );
      M_start = emitters._M_impl._M_start;
    }
    if ( M_start )
      emitters._M_impl._M_end_of_storage.m_allocator->call_free(emitters._M_impl._M_end_of_storage.m_allocator, M_start);
  }
}
