void __userpurge vostok::render::render_particle_emitter_instance::render(
        vostok::render::render_particle_emitter_instance *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::math::float3 *context,
        const unsigned int num_particles,
        unsigned int num_particlesa)
{
  float x; // eax
  float y; // eax
  int v10; // eax
  int v11; // eax
  vostok::math::float3 view_location; // [esp+0h] [ebp-18h] BYREF
  vostok::math::float3 v14; // [esp+Ch] [ebp-Ch] BYREF
  float v15; // [esp+20h] [ebp+8h]

  LODWORD(v14.x) = *(_DWORD *)(num_particles + 21148) ^ _mask__NegFloat_;
  LODWORD(v14.y) = *(_DWORD *)(num_particles + 21152) ^ _mask__NegFloat_;
  x = context->x;
  LODWORD(v14.z) = *(_DWORD *)(num_particles + 21156) ^ _mask__NegFloat_;
  v15 = (float)(unsigned int)(*(int (__thiscall **)(vostok::math::float3 *, int, int, int))(LODWORD(x) + 20))(
                               context,
                               a3,
                               a4,
                               a2);
  view_location.x = (float)(v14.x * v15) * 0.1;
  view_location.y = (float)(v14.y * v15) * 0.1;
  view_location.z = (float)(v14.z * v15) * 0.1;
  v14 = view_location;
  view_location = *(vostok::math::float3 *)(num_particles + 21132);
  vostok::quasi_singleton<vostok::render::statistics>::pinst->visibility_stat_group.num_particles.value += num_particlesa;
  y = context[30].y;
  if ( y == 0.0 )
  {
    vostok::render::render_particle_emitter_instance::render_sprites(
      (vostok::render::render_particle_emitter_instance *)num_particlesa,
      context,
      &v14.x);
  }
  else
  {
    v10 = LODWORD(y) - 1;
    if ( v10 )
    {
      v11 = v10 - 1;
      if ( v11 )
      {
        if ( v11 == 1 )
          vostok::render::render_particle_emitter_instance::render_beams(
            (vostok::render::render_particle_emitter_instance *)num_particlesa,
            (int)context,
            (vostok::particle::base_particle *)&view_location,
            num_particlesa);
      }
      else
      {
        vostok::render::render_particle_emitter_instance::render_trails(
          (vostok::render::render_particle_emitter_instance *)num_particlesa,
          context,
          (vostok::particle::base_particle *)&view_location,
          *(_DWORD *)(LODWORD(context[28].y) + 36),
          num_particlesa);
      }
    }
    else
    {
      vostok::render::render_particle_emitter_instance::render_subuv_sprites(
        (vostok::render::render_particle_emitter_instance *)num_particlesa,
        context,
        &v14.x);
    }
  }
}
