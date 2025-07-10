// local variable allocation has failed, the output may be wrong!
unsigned __int8 __userpurge vostok::render::static_render_model_instance::select_lod@<al>(
        vostok::render::static_render_model_instance *this@<edx>,
        const vostok::math::float4x4 *mat_vp@<esi>,
        const vostok::math::float3 *view_pos)
{
  vostok::render::static_render_model *m_object; // eax
  vostok::render::model_lods_descriptor *m_lods_descriptor; // edi
  unsigned __int8 result; // al
  float *m_lod_custom_params; // ebx
  float v7; // xmm0_4
  float *p_z; // eax
  int v9; // ecx
  float v10; // xmm5_4
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  long double v20; // st7
  const vostok::math::float4x4 *v21; // [esp+4h] [ebp-D0h]
  float params_mult; // [esp+Ch] [ebp-C8h]
  float distance; // [esp+10h] [ebp-C4h]
  float distancea; // [esp+10h] [ebp-C4h]
  __int128 pt_min; // [esp+14h] [ebp-C0h] OVERLAPPED BYREF
  __int64 v26; // [esp+24h] [ebp-B0h]
  vostok::math::float3 pt_max; // [esp+2Ch] [ebp-A8h]
  float v28; // [esp+38h] [ebp-9Ch]
  float z; // [esp+3Ch] [ebp-98h]
  float v30; // [esp+40h] [ebp-94h]
  float v31; // [esp+44h] [ebp-90h]
  float v32; // [esp+48h] [ebp-8Ch]
  float w; // [esp+4Ch] [ebp-88h]
  float v34; // [esp+50h] [ebp-84h]
  float v35; // [esp+54h] [ebp-80h]
  float v36; // [esp+58h] [ebp-7Ch]
  float v37; // [esp+5Ch] [ebp-78h]
  float y; // [esp+60h] [ebp-74h]
  float v39; // [esp+64h] [ebp-70h]
  float v40; // [esp+68h] [ebp-6Ch]
  float x; // [esp+6Ch] [ebp-68h]
  float v42; // [esp+70h] [ebp-64h]
  vostok::math::float3 vertices[8]; // [esp+74h] [ebp-60h] BYREF

  m_object = this->m_original.m_object;
  m_lods_descriptor = m_object->m_lods_descriptor;
  if ( !m_lods_descriptor->m_lod_surfaces_count[0] )
    return -86;
  if ( !m_lods_descriptor->m_lod_surfaces_count[1] )
    return 0;
  if ( m_lods_descriptor->m_lod_params_default )
    m_lod_custom_params = &vostok::render::lod_def_params[3 * m_lods_descriptor->m_lod_calc_type];
  else
    m_lod_custom_params = m_lods_descriptor->m_lod_custom_params;
  params_mult = *(float *)&clear_value;
  if ( !*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
        + 48) )
    params_mult = 0.75;
  pt_min = *(_OWORD *)&m_object->m_aabbox.min.x;
  v26 = *(_QWORD *)&m_object->m_aabbox.max.elements[1];
  vostok::math::aabb::modify((vostok::math::aabb *)&this->m_transform, v21);
  if ( m_lods_descriptor->m_lod_calc_type )
  {
    if ( m_lods_descriptor->m_lod_calc_type != 1 )
      return 0;
    vostok::math::aabb::vertices((vostok::math::aabb *)vertices, (__int64 *)&pt_min);
    *(_QWORD *)&pt_max.x = 0xBF800000BF800000uLL;
    pt_max.z = -1.0;
    x = mat_vp->c.x;
    v37 = mat_vp->k.x;
    v34 = mat_vp->j.x;
    v39 = mat_vp->i.x;
    y = mat_vp->c.y;
    v40 = mat_vp->k.y;
    v30 = mat_vp->j.y;
    v32 = mat_vp->i.y;
    z = mat_vp->c.z;
    v42 = mat_vp->k.z;
    v28 = mat_vp->j.z;
    v36 = mat_vp->i.z;
    distance = mat_vp->c.w;
    w = mat_vp->k.w;
    v31 = mat_vp->j.w;
    v7 = mat_vp->i.w;
    LODWORD(pt_min) = clear_value;
    DWORD1(pt_min) = clear_value;
    DWORD2(pt_min) = clear_value;
    v35 = v7;
    p_z = &vertices[0].z;
    v9 = 8;
    do
    {
      v10 = *(p_z - 1);
      v11 = *(p_z - 2);
      v12 = (float)((float)((float)(v31 * v10) + (float)(w * *p_z)) + (float)(v35 * v11)) + distance;
      v13 = (float)((float)((float)((float)(v34 * v10) + (float)(v37 * *p_z)) + (float)(v39 * v11)) + x)
          * (float)(*(float *)&clear_value / v12);
      v14 = (float)((float)((float)((float)(v30 * v10) + (float)(v40 * *p_z)) + (float)(v32 * v11)) + y)
          * (float)(*(float *)&clear_value / v12);
      v15 = (float)((float)((float)((float)(v28 * v10) + (float)(v42 * *p_z)) + (float)(v36 * v11)) + z)
          * (float)(*(float *)&clear_value / v12);
      if ( v13 <= *(float *)&pt_min )
        *(float *)&pt_min = (float)((float)((float)((float)(v34 * v10) + (float)(v37 * *p_z)) + (float)(v39 * v11)) + x)
                          * (float)(*(float *)&clear_value / v12);
      if ( v14 <= *((float *)&pt_min + 1) )
        *((float *)&pt_min + 1) = v14;
      if ( v15 <= *((float *)&pt_min + 2) )
        *((float *)&pt_min + 2) = v15;
      if ( pt_max.x <= v13 )
        pt_max.x = v13;
      if ( pt_max.y <= v14 )
        pt_max.y = v14;
      if ( pt_max.z <= v15 )
        pt_max.z = v15;
      p_z += 3;
      --v9;
    }
    while ( v9 );
    v16 = pt_max.x - *(float *)&pt_min;
    if ( (float)(pt_max.x - *(float *)&pt_min) <= (float)(pt_max.y - *((float *)&pt_min + 1)) )
      v16 = pt_max.y - *((float *)&pt_min + 1);
    v17 = v16 * 0.5;
    if ( (float)(m_lod_custom_params[2] * params_mult) <= v17 )
    {
      if ( (float)(m_lod_custom_params[1] * params_mult) > v17 )
        return 2;
      return (float)(*m_lod_custom_params * params_mult) > v17;
    }
    return 3;
  }
  v18 = view_pos->y - (float)((float)(*(float *)&v26 + *((float *)&pt_min + 1)) * 0.5);
  v19 = view_pos->z - (float)((float)(*((float *)&v26 + 1) + *((float *)&pt_min + 2)) * 0.5);
  v20 = sqrtf(
          (float)((float)(v19 * v19) + (float)(v18 * v18))
        + (float)((float)(view_pos->x - (float)((float)(*((float *)&pt_min + 3) + *(float *)&pt_min) * 0.5))
                * (float)(view_pos->x - (float)((float)(*((float *)&pt_min + 3) + *(float *)&pt_min) * 0.5))));
  if ( *m_lod_custom_params * params_mult > v20 )
    return 0;
  distancea = v20;
  if ( (float)(m_lod_custom_params[1] * params_mult) > distancea )
    return 1;
  result = 2;
  if ( (float)(m_lod_custom_params[2] * params_mult) <= distancea )
    return 3;
  return result;
}
