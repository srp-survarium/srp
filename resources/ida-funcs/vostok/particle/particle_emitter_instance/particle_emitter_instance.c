void __thiscall vostok::particle::particle_emitter_instance::particle_emitter_instance(
        vostok::particle::particle_emitter_instance *this,
        vostok::memory::base_allocator *allocator,
        vostok::particle::particle_emitter *emitter,
        int is_child_emitter_instance,
        bool need_query_material)
{
  vostok::memory::base_allocator_vtbl *v5; // xmm0_4
  vostok::threading::mutex_tasks_unaware *v6; // ecx
  float v7; // xmm0_4
  _DWORD *i; // edi
  int v9; // eax
  const char *m_arena_id; // ecx
  const char *v11; // ecx
  const char *v12; // ecx
  _BYTE *m_arena_end; // eax
  const char *v14; // ecx
  vostok::math::float4x4 v15; // [esp+18h] [ebp-140h] BYREF
  vostok::math::float4x4 v16; // [esp+58h] [ebp-100h] BYREF
  vostok::math::float4x4 v17; // [esp+98h] [ebp-C0h] BYREF
  vostok::math::float4x4 v18; // [esp+D8h] [ebp-80h] BYREF
  vostok::math::float4x4 v19; // [esp+118h] [ebp-40h] BYREF

  allocator->__vftable = (vostok::memory::base_allocator_vtbl *)&vostok::particle::particle_emitter_instance::`vftable';
  qmemcpy(&allocator->m_arena_id, vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v18), 0x40u);
  qmemcpy(&allocator[3].m_use_memory_monitor, vostok::math::float4x4::identity(0, &v16), 0x40u);
  qmemcpy(&allocator[7], vostok::math::float4x4::identity(0, &v19), 0x40u);
  qmemcpy(&allocator[10].m_arena_start, vostok::math::float4x4::identity(0, &v17), 0x40u);
  qmemcpy(&allocator[13].m_arena_end, vostok::math::float4x4::identity(0, &v15), 0x40u);
  vostok::math::create_zero_aabb((vostok::math::aabb *)&allocator[16].m_arena_id);
  v5 = (vostok::memory::base_allocator_vtbl *)LODWORD(s_bm_current_air_resistance);
  *(float *)&allocator[17].m_use_memory_monitor = s_bm_current_air_resistance;
  allocator[18].__vftable = v5;
  allocator[18].m_arena_start = v5;
  allocator[18].m_arena_end = v5;
  allocator[18].m_arena_id = (const char *)emitter;
  *(_DWORD *)&allocator[18].m_use_memory_monitor = 0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(v6, (_RTL_CRITICAL_SECTION *)&allocator[19].m_arena_start);
  v7 = s_bm_current_air_resistance;
  allocator[20].m_arena_id = 0;
  *(_DWORD *)&allocator[20].m_use_memory_monitor = 0;
  allocator[21].m_arena_start = 0;
  allocator[21].m_arena_end = 0;
  allocator[21].m_arena_id = 0;
  *(_DWORD *)&allocator[21].m_use_memory_monitor = 0;
  allocator[22].__vftable = 0;
  allocator[22].m_arena_id = 0;
  *(float *)&allocator[22].m_arena_start = v7;
  *(float *)&allocator[22].m_arena_end = v7;
  *(_DWORD *)&allocator[22].m_use_memory_monitor = 0;
  allocator[23].__vftable = 0;
  allocator[23].m_arena_end = 0;
  allocator[23].m_arena_id = 0;
  *(_DWORD *)&allocator[23].m_use_memory_monitor = 0;
  allocator[24].__vftable = 0;
  allocator[24].m_arena_start = 0;
  allocator[24].m_arena_end = (void *)is_child_emitter_instance;
  allocator[24].m_arena_id = 0;
  *(_DWORD *)&allocator[24].m_use_memory_monitor = 0;
  allocator[25].__vftable = 0;
  allocator[25].m_arena_start = 0;
  allocator[25].m_arena_end = 0;
  *(_DWORD *)&allocator[25].m_use_memory_monitor = 0;
  allocator[26].__vftable = 0;
  allocator[26].m_arena_start = 0;
  allocator[26].m_arena_end = *(void **)(is_child_emitter_instance + 360);
  allocator[26].m_arena_id = 0;
  *(_DWORD *)&allocator[26].m_use_memory_monitor = 0;
  allocator[27].__vftable = 0;
  *(float *)&allocator[27].m_arena_start = vostok::particle::calc_duration(
                                             *(float *)(is_child_emitter_instance + 352),
                                             *(float *)(is_child_emitter_instance + 356));
  allocator[27].m_arena_end = 0;
  allocator[27].m_arena_id = *(const char **)(is_child_emitter_instance + 360);
  allocator[27].m_use_memory_monitor = need_query_material;
  *(&allocator[27].m_use_memory_monitor + 1) = 0;
  *(&allocator[27].m_use_memory_monitor + 2) = 0;
  *(&allocator[27].m_use_memory_monitor + 3) = 1;
  LOBYTE(allocator[28].__vftable) = 0;
  allocator[28].m_arena_start = 0;
  for ( i = *(_DWORD **)(is_child_emitter_instance + 296); i; i = (_DWORD *)i[2] )
  {
    v9 = (*(int (__thiscall **)(_DWORD *))(*i + 52))(i);
    if ( v9 && *(_BYTE *)(v9 + 16) )
    {
      allocator[23].m_arena_id = (const char *)v9;
      break;
    }
  }
  m_arena_id = allocator[23].m_arena_id;
  if ( m_arena_id && !(*(int (__thiscall **)(const char *))(*(_DWORD *)m_arena_id + 60))(m_arena_id) )
    allocator[24].__vftable = (vostok::memory::base_allocator_vtbl *)(allocator[23].m_arena_id + 96);
  v11 = allocator[23].m_arena_id;
  if ( v11 && (*(int (__thiscall **)(const char *))(*(_DWORD *)v11 + 60))(v11) == 2
    || (v12 = allocator[23].m_arena_id) != 0 && (*(int (__thiscall **)(const char *))(*(_DWORD *)v12 + 60))(v12) == 3 )
  {
    allocator[24].m_arena_start = (void *)(allocator[23].m_arena_id + 24);
  }
  m_arena_end = allocator[24].m_arena_end;
  BYTE1(allocator[28].__vftable) = m_arena_end[369];
  v14 = allocator[23].m_arena_id;
  LOBYTE(allocator->m_arena_end) = m_arena_end[368];
  if ( v14 )
  {
    if ( (*(int (__thiscall **)(const char *))(*(_DWORD *)v14 + 60))(v14) != 1 )
      (*(void (__thiscall **)(const char *))(*(_DWORD *)allocator[23].m_arena_id + 60))(allocator[23].m_arena_id);
  }
}
