void __userpurge vostok::particle::particle_emitter_instance::append_particles(
        vostok::particle::particle_emitter_instance *this@<ecx>,
        float a2@<xmm0>,
        char *time_delta,
        int a4)
{
  vostok::particle::base_particle *particle; // edi
  unsigned int v6; // eax
  vostok::particle::particle_emitter_instance *v7; // ecx
  int j; // esi
  float *p_x; // edi
  vostok::math::float4x4 *transform; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float y; // xmm4_4
  vostok::math::float4x4 v14; // [esp+20h] [ebp-50h] BYREF
  float v15; // [esp+60h] [ebp-10h]
  float v16; // [esp+64h] [ebp-Ch]
  float v17; // [esp+68h] [ebp-8h]
  int v18; // [esp+6Ch] [ebp-4h] BYREF
  unsigned int i; // [esp+78h] [ebp+8h]

  for ( i = 0; i < *((_DWORD *)time_delta + 131); ++i )
  {
    if ( (unsigned int)(*((_DWORD *)time_delta + 124) + 1) > *((_DWORD *)time_delta + 138) )
      break;
    particle = vostok::particle::particle_world::allocate_particle(
                 (vostok::particle::particle_world *)this,
                 *((_DWORD **)time_delta + 114));
    v18 = (int)particle;
    if ( particle )
    {
      vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::particle::base_particle,vostok::particle::base_particle *,208,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(time_delta + 376),
        particle,
        (vostok::threading::mutex *)this);
      v6 = (unsigned int)particle + vostok::timing::get_QPC().LowPart;
      particle->m_seed = v6;
      vostok::math::curve_line_ranged_base::evaluate(
        (vostok::math::curve_line_ranged_base *)(*((_DWORD *)time_delta + 122) + 128),
        v6,
        *((float *)time_delta + 127),
        1.0,
        *(vostok::math::enum_evaluate_type *)(*((_DWORD *)time_delta + 122) + 192),
        range_time_type);
      particle->duration = a2;
      if ( *(_BYTE *)(*((_DWORD *)time_delta + 122) + 371) )
      {
        a2 = 0.0;
        particle->duration = 0.0;
        particle->lifetime_cycle = *(float *)(*((_DWORD *)time_delta + 122) + 376);
      }
      else if ( a2 < 0.001 )
      {
        a2 = 0.0;
        particle->duration = 0.0;
        particle->lifetime_cycle = 0.0;
      }
      for ( j = *(_DWORD *)(*((_DWORD *)time_delta + 122) + 296); j; j = *(_DWORD *)(j + 8) )
      {
        if ( *(_BYTE *)(j + 16) )
          (*(void (__thiscall **)(int, char *, vostok::particle::base_particle *, int))(*(_DWORD *)j + 12))(
            j,
            time_delta,
            particle,
            a4);
      }
      if ( *(_BYTE *)(*((_DWORD *)time_delta + 122) + 369) )
      {
        p_x = &particle->position.x;
        transform = vostok::particle::particle_emitter_instance::get_transform(v7, time_delta, &v14);
        v11 = p_x[1];
        a2 = p_x[2];
        v12 = *p_x;
        y = transform->j.y;
        v15 = (float)((float)((float)(transform->j.x * v11) + (float)(transform->k.x * a2))
                    + (float)(transform->i.x * *p_x))
            + transform->c.x;
        v16 = (float)((float)((float)(transform->i.y * v12) + (float)(y * v11)) + (float)(transform->k.y * a2))
            + transform->c.y;
        v17 = (float)((float)((float)(transform->i.z * v12) + (float)(transform->j.z * v11))
                    + (float)(transform->k.z * a2))
            + transform->c.z;
        *p_x++ = v15;
        *p_x = v16;
        p_x[1] = v17;
        particle = (vostok::particle::base_particle *)v18;
      }
      v18 = 3;
      vostok::particle::particle_emitter_instance::process_event(
        v7,
        (vostok::particle::particle_event *)time_delta,
        (vostok::math::float4x4 *)&v18,
        &particle->position);
      ++*((_DWORD *)time_delta + 124);
      ++*((_DWORD *)time_delta + 125);
    }
  }
}
