void __thiscall vostok::render::grass_patch::init_collision(
        vostok::render::grass_patch *this,
        vostok::render::grass_patch *thisa)
{
  void **M_start; // ecx
  void **M_finish; // edx
  int v4; // eax
  float v5; // xmm2_4
  unsigned int v6; // ecx
  float v7; // xmm1_4
  float x; // xmm4_4
  const vostok::math::float4x4 *v9; // eax
  int v10; // eax
  vostok::collision::geometry_instance *v11; // edx
  vostok::collision::geometry_instance *v12; // esi
  int v13; // eax
  vostok::collision::space_partitioning_tree *m_collision_tree; // ecx
  __int64 v15; // [esp+14h] [ebp-E4h]
  __int64 v16; // [esp+14h] [ebp-E4h]
  float v17; // [esp+1Ch] [ebp-DCh]
  float v18; // [esp+1Ch] [ebp-DCh]
  float v19; // [esp+20h] [ebp-D8h]
  float v20; // [esp+24h] [ebp-D4h]
  __int64 v21; // [esp+28h] [ebp-D0h]
  float z; // [esp+30h] [ebp-C8h]
  vostok::math::float4x4 transform; // [esp+38h] [ebp-C0h] BYREF
  vostok::math::float4x4 dst; // [esp+78h] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+B8h] [ebp-40h] BYREF

  if ( (_S6_5 & 1) == 0 )
  {
    _S6_5 |= 1u;
    s_randomizer_0.m_seed = (unsigned int)&loc_186A0;
  }
  M_start = thisa->m_instances._M_impl._M_start;
  M_finish = thisa->m_instances._M_impl._M_finish;
  thisa->m_aabb.min.y = float_max_12;
  for ( thisa->m_aabb.max.y = float_min_9; M_start != M_finish; thisa->m_aabb.max.z = v17 )
  {
    v4 = (int)*M_start + 56;
    if ( *(float *)v4 <= thisa->m_aabb.min.x )
      LODWORD(v21) = *((_DWORD *)*M_start + 14);
    else
      *(float *)&v21 = thisa->m_aabb.min.x;
    if ( *((float *)*M_start + 15) <= thisa->m_aabb.min.y )
      HIDWORD(v21) = *((_DWORD *)*M_start + 15);
    else
      HIDWORD(v21) = LODWORD(thisa->m_aabb.min.y);
    if ( *((float *)*M_start + 16) <= thisa->m_aabb.min.z )
      z = *((float *)*M_start + 16);
    else
      z = thisa->m_aabb.min.z;
    *(_QWORD *)&thisa->m_aabb.min.x = v21;
    thisa->m_aabb.min.z = z;
    if ( thisa->m_aabb.max.x <= *(float *)v4 )
      LODWORD(v15) = *(_DWORD *)v4;
    else
      *(float *)&v15 = thisa->m_aabb.max.x;
    if ( thisa->m_aabb.max.y <= *(float *)(v4 + 4) )
      HIDWORD(v15) = *(_DWORD *)(v4 + 4);
    else
      HIDWORD(v15) = LODWORD(thisa->m_aabb.max.y);
    if ( thisa->m_aabb.max.z <= *(float *)(v4 + 8) )
      v17 = *(float *)(v4 + 8);
    else
      v17 = thisa->m_aabb.max.z;
    ++M_start;
    *(_QWORD *)&thisa->m_aabb.max.x = v15;
  }
  thisa->m_aabb.min.y = thisa->m_aabb.min.y - 0.2;
  thisa->m_aabb.max.y = thisa->m_aabb.max.y + 3.0;
  v5 = (float)(thisa->m_aabb.max.z + thisa->m_aabb.min.z) * 0.5;
  *(float *)&v16 = (float)(thisa->m_aabb.min.x + thisa->m_aabb.max.x) * 0.5;
  *((float *)&v16 + 1) = (float)(thisa->m_aabb.max.y + thisa->m_aabb.min.y) * 0.5;
  *(_QWORD *)&thisa->m_origin.x = v16;
  thisa->m_origin.z = v5;
  v19 = (double)((((unsigned int)&loc_FFFFF + 1) * (unsigned __int64)(134775813 * s_randomizer_0.m_seed + 1)) >> 32)
      * 0.00000095367432
      * 0.1;
  v6 = 134775813 * (134775813 * s_randomizer_0.m_seed + 1) + 1;
  v20 = (double)((((unsigned int)&loc_FFFFF + 1) * (unsigned __int64)v6) >> 32) * 0.00000095367432 * 0.1;
  s_randomizer_0.m_seed = 134775813 * v6 + 1;
  v7 = (float)(v19 - 0.25) + thisa->m_origin.z;
  *(float *)&v16 = 0.1
                 * (0.00000095367432
                  * (double)((((unsigned int)&loc_FFFFF + 1) * (unsigned __int64)s_randomizer_0.m_seed) >> 32));
  x = thisa->m_origin.x;
  thisa->m_origin.y = (float)(v20 - 0.25) + thisa->m_origin.y;
  thisa->m_origin.z = v7;
  thisa->m_origin.x = x + (float)(*(float *)&v16 - 0.25);
  *(float *)&v16 = (float)(thisa->m_aabb.max.x - thisa->m_aabb.min.x) * 0.5;
  *((float *)&v16 + 1) = (float)(thisa->m_aabb.max.y - thisa->m_aabb.min.y) * 0.5;
  v18 = (float)(thisa->m_aabb.max.z - thisa->m_aabb.min.z) * 0.5;
  memset((int)&dst, 0, sizeof(dst));
  dst.j.y = *((float *)&v16 + 1);
  LODWORD(dst.i.x) = v16;
  dst.k.z = v18;
  LODWORD(dst.c.w) = clear_value;
  v9 = vostok::math::create_translation(&result, &thisa->m_origin);
  vostok::math::mul4x3(&transform, &dst, v9);
  v10 = ((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
          vostok::render::g_allocator.m_object,
          136);
  if ( v10 )
  {
    *(_BYTE *)(v10 + 4) = 1;
    *(_DWORD *)v10 = &vostok::collision::box_geometry_instance::`vftable';
    qmemcpy((void *)(v10 + 8), &transform, 0x40u);
    invert_impl(
      &transform,
      (float)((float)((float)((float)(transform.k.z * transform.j.y) - (float)(transform.j.z * transform.k.y))
                    * transform.i.x)
            - (float)((float)((float)(transform.k.z * transform.j.x) - (float)(transform.j.z * transform.k.x))
                    * transform.i.y))
    + (float)((float)((float)(transform.j.x * transform.k.y) - (float)(transform.j.y * transform.k.x)) * transform.i.z));
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  thisa->m_collision_geometry = v12;
  v13 = ((int (__thiscall *)(vostok::render::grass_render_model *, int))vostok::render::g_allocator.m_object->decrease_quality)(
          vostok::render::g_allocator.m_object,
          52);
  if ( v13 )
  {
    *(_QWORD *)(v13 + 4) = 0;
    *(_DWORD *)(v13 + 12) = 0;
    *(_QWORD *)(v13 + 16) = 0;
    *(_DWORD *)(v13 + 24) = 0;
    *(_DWORD *)(v13 + 28) = 0;
    *(_DWORD *)(v13 + 32) = 0;
    *(_BYTE *)(v13 + 44) = 1;
    *(_DWORD *)v13 = &vostok::collision::collision_object::`vftable';
    *(_DWORD *)(v13 + 48) = v12;
    *(_DWORD *)(v13 + 36) = thisa;
    *(_DWORD *)(v13 + 40) = 1;
  }
  else
  {
    v13 = 0;
  }
  m_collision_tree = thisa->m_collision_tree;
  thisa->m_collision_object = (vostok::collision::object *)v13;
  m_collision_tree->insert(m_collision_tree, (vostok::collision::object *)v13, &transform);
}
