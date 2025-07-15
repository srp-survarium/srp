void __thiscall vostok::particle::particle_beam_emitter_instance::particle_beam_emitter_instance(
        vostok::particle::particle_beam_emitter_instance *this,
        vostok::memory::base_allocator *allocator,
        vostok::particle::particle_emitter *emitter,
        int is_child_emitter_instance,
        bool need_query_material)
{
  int v5; // eax
  void **v6; // esi
  void **v7; // esi
  int v8; // eax
  vostok::math::float3 *v9; // eax
  double v10; // st7
  vostok::math::float3 *v11; // eax
  vostok::particle::particle_beam_emitter_instance *m_arena_start; // ecx
  vostok::math::float3 *v13; // esi
  _DWORD *m_arena_end; // eax
  char *v15; // eax
  vostok::particle::particle_beam_emitter_instance *v16; // ecx
  vostok::particle::particle_beam_emitter_instance *v17; // ecx
  const char *m_arena_id; // eax
  unsigned int v19; // [esp+8h] [ebp-70h]
  unsigned int v20; // [esp+8h] [ebp-70h]
  vostok::math::float4x4 result; // [esp+14h] [ebp-64h] BYREF
  vostok::math::float3 v22; // [esp+54h] [ebp-24h] BYREF
  vostok::math::float3_pod v23; // [esp+60h] [ebp-18h] BYREF
  vostok::math::float3 v24; // [esp+6Ch] [ebp-Ch] BYREF
  float v25; // [esp+88h] [ebp+10h]

  vostok::particle::particle_emitter_instance::particle_emitter_instance(
    this,
    allocator,
    emitter,
    is_child_emitter_instance,
    need_query_material);
  allocator->__vftable = (vostok::memory::base_allocator_vtbl *)&vostok::particle::particle_beam_emitter_instance::`vftable';
  *(_DWORD *)&allocator[30].m_use_memory_monitor = 0;
  allocator[31].__vftable = 0;
  allocator[31].m_arena_start = 0;
  allocator[31].m_arena_end = 0;
  allocator[31].m_arena_id = 0;
  *(_DWORD *)&allocator[31].m_use_memory_monitor = 0;
  allocator[32].__vftable = 0;
  allocator[32].m_arena_start = 0;
  LOBYTE(allocator[32].m_arena_end) = 0;
  v5 = *(_DWORD *)(is_child_emitter_instance + 272);
  if ( v5 )
  {
    vostok::particle::particle_domain_complex::get_transform(
      (vostok::particle::particle_domain_complex *)(v5 + 24),
      &result);
    v6 = (void **)&result.c.0;
  }
  else
  {
    memset(&v24, 0, sizeof(v24));
    v6 = (void **)&v24;
  }
  allocator[28].m_arena_end = *v6;
  v7 = v6 + 1;
  allocator[28].m_arena_id = (const char *)*v7;
  *(_DWORD *)&allocator[28].m_use_memory_monitor = v7[1];
  v8 = *(_DWORD *)(is_child_emitter_instance + 280);
  if ( v8 )
  {
    v9 = vostok::particle::particle_domain_complex::generate(
           (vostok::particle::particle_domain_complex *)&v23,
           (vostok::particle::particle_domain_complex *)(v8 + 24),
           &v23.x);
  }
  else
  {
    v24.x = FLOAT_50_0;
    v24.y = FLOAT_50_0;
    v24.z = FLOAT_50_0;
    v9 = &v24;
  }
  allocator[29].__vftable = (vostok::memory::base_allocator_vtbl *)LODWORD(v9->x);
  allocator[29].m_arena_start = (void *)LODWORD(v9->y);
  allocator[29].m_arena_end = (void *)LODWORD(v9->z);
  allocator[30].m_arena_start = (void *)LODWORD(v9->x);
  allocator[30].m_arena_end = (void *)LODWORD(v9->y);
  allocator[30].m_arena_id = (const char *)LODWORD(v9->z);
  v25 = vostok::particle::random_float(0.0, 1.0);
  v10 = vostok::particle::random_float(0.0, 1.0);
  v24.x = v25;
  v24.y = v10;
  v24.z = vostok::particle::random_float(0.0, 1.0);
  v23.x = *(float *)&allocator[29].__vftable - *(float *)&allocator[28].m_arena_end;
  v23.y = *(float *)&allocator[29].m_arena_start - *(float *)&allocator[28].m_arena_id;
  v23.z = *(float *)&allocator[29].m_arena_end - *(float *)&allocator[28].m_use_memory_monitor;
  v11 = vostok::math::normalize_safe(&v23, &v24, &v22);
  m_arena_start = (vostok::particle::particle_beam_emitter_instance *)allocator[24].m_arena_start;
  v13 = v11;
  m_arena_end = allocator[24].m_arena_end;
  allocator[29].m_arena_id = (const char *)LODWORD(v13->x);
  v13 = (vostok::math::float3 *)((char *)v13 + 4);
  *(float *)&allocator[29].m_use_memory_monitor = v13->x;
  allocator[30].__vftable = (vostok::memory::base_allocator_vtbl *)LODWORD(v13->y);
  v15 = (char *)(*(_DWORD *)&m_arena_start->m_use_second_transform * m_arena_end[90]);
  allocator[27].m_arena_id = v15;
  allocator[26].m_arena_end = v15;
  vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data(m_arena_start, (int)allocator, 1u, v19);
  if ( (void *)*((_DWORD *)allocator[24].m_arena_start + 2) != allocator[31].m_arena_end )
  {
    vostok::particle::particle_beam_emitter_instance::free_dynamic_data(v16, (int)allocator);
    vostok::particle::particle_beam_emitter_instance::alloc_dynamic_data(
      v17,
      (int)allocator,
      *((_DWORD *)allocator[24].m_arena_start + 2),
      v20);
  }
  m_arena_id = allocator[23].m_arena_id;
  if ( m_arena_id )
    *(_DWORD *)&allocator[30].m_use_memory_monitor = m_arena_id;
  vostok::particle::particle_beam_emitter_instance::generate_offsets(v16, (int)allocator);
}
