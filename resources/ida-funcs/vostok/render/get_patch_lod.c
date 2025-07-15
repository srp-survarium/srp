int __cdecl vostok::render::get_patch_lod(
        vostok::math::aabb *instance_transform,
        const vostok::math::float4x4 *mat_vp,
        const vostok::math::float3 *view_pos,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> original)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  bool v5; // zf
  int v6; // esi
  float *v8; // eax
  float v9; // xmm0_4
  float *p_z; // eax
  int v11; // ecx
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm5_4
  bool v19; // cc
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm4_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  int v29; // [esp-10h] [ebp-F4h]
  vostok::math::aabb v30[4]; // [esp+4h] [ebp-E0h] BYREF
  _DWORD v31[6]; // [esp+64h] [ebp-80h] BYREF
  float v32; // [esp+7Ch] [ebp-68h]
  float v33; // [esp+80h] [ebp-64h]
  float x; // [esp+84h] [ebp-60h]
  float v35; // [esp+88h] [ebp-5Ch]
  float v36; // [esp+8Ch] [ebp-58h]
  float v37; // [esp+90h] [ebp-54h]
  float w; // [esp+94h] [ebp-50h]
  float v39; // [esp+98h] [ebp-4Ch]
  float v40; // [esp+9Ch] [ebp-48h]
  float y; // [esp+A0h] [ebp-44h]
  float v42; // [esp+A4h] [ebp-40h]
  float v43; // [esp+A8h] [ebp-3Ch]
  float v44; // [esp+ACh] [ebp-38h]
  float z; // [esp+B0h] [ebp-34h]
  float v46; // [esp+B4h] [ebp-30h]
  vostok::math::aabb v47; // [esp+B8h] [ebp-2Ch] BYREF
  float v48; // [esp+D0h] [ebp-14h]
  float v49; // [esp+D4h] [ebp-10h]
  float v50; // [esp+D8h] [ebp-Ch]
  float *v51; // [esp+DCh] [ebp-8h]
  float v52; // [esp+E0h] [ebp-4h]

  m_object = original.m_object->m_lods[1].m_template.m_object;
  v5 = LOBYTE(m_object->__vftable) == 0;
  *(float *)v31 = FLOAT_20_0;
  *(float *)&v31[1] = FLOAT_40_0;
  *(float *)&v31[2] = FLOAT_240_0;
  *(float *)&v31[3] = FLOAT_0_40000001;
  *(float *)&v31[4] = FLOAT_0_2;
  *(float *)&v31[5] = epsilon_3_4;
  v52 = *(float *)&m_object;
  if ( v5 )
  {
    v6 = 170;
LABEL_3:
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&original);
    return v6;
  }
  if ( !BYTE1(m_object->__vftable) )
  {
    v6 = 0;
    goto LABEL_3;
  }
  if ( LOBYTE(m_object->m_uid) )
    v8 = (float *)&v31[3 * LOBYTE(m_object->m_reconstruction_info_actuality_tick)];
  else
    v8 = (float *)&m_object->m_reconstruction_info_actuality_tick + 1;
  qmemcpy(&v47, original.m_object->m_lods, sizeof(v47));
  v51 = v8;
  vostok::math::aabb::modify(instance_transform, &v47);
  v6 = 0;
  if ( *(_BYTE *)(LODWORD(v52) + 16) )
  {
    if ( *(_BYTE *)(LODWORD(v52) + 16) != 1 )
      goto LABEL_3;
    vostok::math::aabb::vertices(v30, (int)&v47);
    v47.max.x = FLOAT_N1_0;
    v47.max.y = FLOAT_N1_0;
    v47.max.z = FLOAT_N1_0;
    x = mat_vp->c.x;
    v39 = mat_vp->k.x;
    v52 = mat_vp->j.x;
    v36 = mat_vp->i.x;
    y = mat_vp->c.y;
    v43 = mat_vp->k.y;
    v37 = mat_vp->j.y;
    v33 = mat_vp->i.y;
    z = mat_vp->c.z;
    v46 = mat_vp->k.z;
    v35 = mat_vp->j.z;
    v32 = mat_vp->i.z;
    w = mat_vp->c.w;
    v42 = mat_vp->k.w;
    v44 = mat_vp->j.w;
    v9 = mat_vp->i.w;
    v48 = s_bm_current_air_resistance;
    v49 = s_bm_current_air_resistance;
    v50 = s_bm_current_air_resistance;
    v40 = v9;
    p_z = &v30[0].min.z;
    v11 = 8;
    do
    {
      v12 = *(p_z - 1);
      v13 = *(p_z - 2);
      v14 = (float)((float)((float)(v52 * v12) + (float)(v39 * *p_z)) + (float)(v36 * v13)) + x;
      v15 = (float)((float)((float)(v37 * v12) + (float)(v43 * *p_z)) + (float)(v33 * v13)) + y;
      v16 = (float)((float)((float)(v35 * v12) + (float)(v46 * *p_z)) + (float)(v32 * v13)) + z;
      v17 = s_bm_current_air_resistance
          / (float)((float)((float)((float)(v44 * v12) + (float)(v42 * *p_z)) + (float)(v40 * v13)) + w);
      v18 = v17 * v14;
      v19 = (float)(v17 * v14) <= v48;
      v20 = v17 * v15;
      v21 = v17 * v16;
      if ( v19 )
        v48 = v18;
      if ( v20 <= v49 )
        v49 = v20;
      if ( v21 <= v50 )
        v50 = v21;
      v22 = v47.max.x;
      if ( v47.max.x <= v18 )
      {
        v22 = v18;
        v47.max.x = v18;
      }
      v23 = v47.max.y;
      if ( v47.max.y <= v20 )
      {
        v23 = v20;
        v47.max.y = v20;
      }
      if ( v47.max.z <= v21 )
        v47.max.z = v21;
      p_z += 3;
      --v11;
    }
    while ( v11 );
    v24 = v22 - v48;
    v25 = v23 - v49;
    if ( v24 <= v25 )
      v24 = v25;
    v26 = v24 * 0.5;
    if ( v51[2] > v26 )
    {
      v29 = 3;
LABEL_37:
      v6 = v29;
      goto LABEL_3;
    }
    if ( v51[1] <= v26 )
    {
      if ( *v51 <= v26 )
        goto LABEL_3;
      goto LABEL_34;
    }
    goto LABEL_36;
  }
  v27 = view_pos->z - (float)((float)(v47.max.z + v47.min.z) * 0.5);
  v28 = fsqrt(
          (float)((float)((float)(view_pos->x - (float)((float)(v47.max.x + v47.min.x) * 0.5))
                        * (float)(view_pos->x - (float)((float)(v47.max.x + v47.min.x) * 0.5)))
                + (float)(v27 * v27))
        + (float)((float)(view_pos->y - (float)((float)(v47.max.y + v47.min.y) * 0.5))
                * (float)(view_pos->y - (float)((float)(v47.max.y + v47.min.y) * 0.5))));
  if ( *v51 > v28 )
    goto LABEL_3;
  if ( v51[1] > v28 )
  {
LABEL_34:
    v6 = 1;
    goto LABEL_3;
  }
  if ( v51[2] > v28 )
  {
LABEL_36:
    v29 = 2;
    goto LABEL_37;
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&original);
  return 3;
}
