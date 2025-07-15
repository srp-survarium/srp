vostok::math::float3 *__userpurge vostok::render::skeleton_render_model_instance::get_bone_direction@<eax>(
        vostok::render::skeleton_render_model_instance *this@<ecx>,
        vostok::render::skeleton_render_model_instance *a2@<edi>,
        float *a3@<esi>,
        vostok::math::float3 *result,
        vostok::math::float3 point,
        const unsigned __int16 skeleton_bone_idx,
        bool world_space)
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  vostok::math::float4x4 v11; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 v12; // [esp+50h] [ebp-40h] BYREF

  vostok::render::skeleton_render_model_instance::get_bone_matrix(
    a2,
    LOWORD(point.elements[2]),
    &v12,
    &a2->m_bones_matrices.m_begin,
    0);
  vostok::render::skeleton_render_model_instance::get_bone_matrix(
    a2,
    LOWORD(point.elements[2]),
    &v11,
    &a2->m_prev_bones_matrices.m_begin,
    0);
  v7 = s_bm_current_air_resistance
     / (float)((float)((float)((float)(v12.i.w * *(float *)&result) + (float)(v12.j.w * point.x))
                     + (float)(v12.k.w * point.y))
             + v12.c.w);
  v8 = (float)(v7
             * (float)((float)((float)((float)(v12.i.y * *(float *)&result) + (float)(v12.j.y * point.x))
                             + (float)(v12.k.y * point.y))
                     + v12.c.y))
     - (float)((float)(s_bm_current_air_resistance
                     / (float)((float)((float)((float)(v11.i.w * *(float *)&result) + (float)(v11.j.w * point.x))
                                     + (float)(v11.k.w * point.y))
                             + v11.c.w))
             * (float)((float)((float)((float)(v11.i.y * *(float *)&result) + (float)(v11.j.y * point.x))
                             + (float)(v11.k.y * point.y))
                     + v11.c.y));
  v9 = (float)(v7
             * (float)((float)((float)((float)(v12.i.z * *(float *)&result) + (float)(v12.j.z * point.x))
                             + (float)(v12.k.z * point.y))
                     + v12.c.z))
     - (float)((float)(s_bm_current_air_resistance
                     / (float)((float)((float)((float)(v11.i.w * *(float *)&result) + (float)(v11.j.w * point.x))
                                     + (float)(v11.k.w * point.y))
                             + v11.c.w))
             * (float)((float)((float)((float)(v11.i.z * *(float *)&result) + (float)(v11.j.z * point.x))
                             + (float)(v11.k.z * point.y))
                     + v11.c.z));
  *a3 = (float)(v7
              * (float)((float)((float)((float)(v12.j.x * point.x) + (float)(v12.k.x * point.y))
                              + (float)(v12.i.x * *(float *)&result))
                      + v12.c.x))
      - (float)((float)(s_bm_current_air_resistance
                      / (float)((float)((float)((float)(v11.i.w * *(float *)&result) + (float)(v11.j.w * point.x))
                                      + (float)(v11.k.w * point.y))
                              + v11.c.w))
              * (float)((float)((float)((float)(v11.j.x * point.x) + (float)(v11.k.x * point.y))
                              + (float)(v11.i.x * *(float *)&result))
                      + v11.c.x));
  a3[1] = v8;
  a3[2] = v9;
  return (vostok::math::float3 *)a3;
}
