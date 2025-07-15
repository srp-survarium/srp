void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_particles(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        vostok::math::float4 **out_counter,
        vostok::particle::render_particle_emitter_instance **end)
{
  float z; // eax
  vostok::particle::render_particle_emitter_instance **v6; // edi
  vostok::particle::render_particle_emitter_instance *v7; // esi
  vostok::particle::render_particle_emitter_instance_vtbl *v8; // eax
  bool v9; // al
  vostok::particle::render_particle_emitter_instance *v10; // eax
  vostok::math::aabb *v11; // eax
  vostok::math::float4 *v12; // eax
  const vostok::math::float4x4 *v13; // [esp+4h] [ebp-78h]
  __int64 v14; // [esp+14h] [ebp-68h]
  __int64 v15; // [esp+1Ch] [ebp-60h]
  __int64 v16; // [esp+24h] [ebp-58h]
  __int64 v17; // [esp+2Ch] [ebp-50h]
  __int64 v18; // [esp+34h] [ebp-48h]
  vostok::math::float4x4 v19; // [esp+3Ch] [ebp-40h] BYREF
  vostok::particle::render_particle_emitter_instance **enda; // [esp+88h] [ebp+Ch]

  z = out_bounds[1][774].z;
  v6 = *(vostok::particle::render_particle_emitter_instance ***)(LODWORD(z) + 1388);
  for ( enda = *(vostok::particle::render_particle_emitter_instance ***)(LODWORD(z) + 1392);
        v6 != enda;
        *out_counter = v12 + 1 )
  {
    v7 = *v6;
    v8 = (*v6)[286].__vftable;
    v9 = v8 != (vostok::particle::render_particle_emitter_instance_vtbl *)-1
      && *((_BYTE *)&out_bounds[7]->x + (_DWORD)v8) == 0;
    LOBYTE(v7[287].__vftable) = v9;
    v10 = *end;
    v7[286].__vftable = (vostok::particle::render_particle_emitter_instance_vtbl *)*end;
    *end = (vostok::particle::render_particle_emitter_instance *)((char *)&v10->__vftable + 1);
    v11 = (vostok::math::aabb *)vostok::math::float4x4::identity(&v19);
    v16 = *(_QWORD *)&v7[230].__vftable;
    v17 = *(_QWORD *)&v7[232].__vftable;
    v18 = *(_QWORD *)&v7[234].__vftable;
    vostok::math::aabb::modify(v11, v13);
    *(float *)&v14 = (float)(*((float *)&v17 + 1) + *(float *)&v16) * 0.5;
    *((float *)&v14 + 1) = (float)(*(float *)&v18 + *((float *)&v16 + 1)) * 0.5;
    *(float *)&v15 = (float)(*((float *)&v18 + 1) + *(float *)&v17) * 0.5;
    *((float *)&v15 + 1) = sqrtf(
                             (float)((float)((float)((float)(*((float *)&v18 + 1) - *(float *)&v17) * 0.5)
                                           * (float)((float)(*((float *)&v18 + 1) - *(float *)&v17) * 0.5))
                                   + (float)((float)((float)(*((float *)&v17 + 1) - *(float *)&v16) * 0.5)
                                           * (float)((float)(*((float *)&v17 + 1) - *(float *)&v16) * 0.5)))
                           + (float)((float)((float)(*(float *)&v18 - *((float *)&v16 + 1)) * 0.5)
                                   * (float)((float)(*(float *)&v18 - *((float *)&v16 + 1)) * 0.5)));
    v12 = *out_counter;
    *(_QWORD *)&v12->x = v14;
    *(_QWORD *)&v12->elements[2] = v15;
    ++v6;
  }
}
