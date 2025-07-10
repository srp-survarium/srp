survarium::animation_space_vertex_id *__userpurge survarium::animation_space_graph_wrapper::vertex_id@<eax>(
        const survarium::animation_space_vertex_id *vertex_id@<ecx>,
        const unsigned int iterator@<eax>,
        int a3@<esi>,
        survarium::animation_space_graph_wrapper *this)
{
  int v5; // ecx
  __int64 v6; // xmm0_8
  survarium::animation_space_graph *m_object; // eax
  unsigned int v8; // edi
  int v9; // edx
  char *v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  float *v13; // eax
  float v14; // edx
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm5_4
  __int64 position; // [esp+4h] [ebp-50h] BYREF
  __int64 position_8; // [esp+Ch] [ebp-48h]
  vostok::math::float4x4 temp; // [esp+14h] [ebp-40h]

  position = 0;
  LODWORD(position_8) = 0;
  vostok::math::create_matrix(&vertex_id->rotation, (const vostok::math::float3 *)&position);
  v6 = *(_QWORD *)(v5 + 16);
  temp.c.z = *(float *)(v5 + 24);
  m_object = this->m_graph->m_object;
  v8 = 5 * iterator + m_object->m_mixes_count;
  v9 = 292 * m_object->m_animations_count;
  *(_QWORD *)&temp.lines[3].x = v6;
  v10 = (char *)m_object + v9;
  LODWORD(v6) = *(_DWORD *)&v10[8 * v8 + 304];
  v11 = *(float *)&v10[8 * v8 + 312];
  v12 = *(float *)&v10[8 * v8 + 308];
  v13 = (float *)&v10[8 * v8 + 288];
  *(float *)&position = (float)((float)((float)(v11 * temp.k.x) + (float)(*(float *)&v6 * temp.i.x))
                              + (float)(v12 * temp.j.x))
                      + temp.c.x;
  *(float *)&position_8 = (float)((float)((float)(*(float *)&v6 * temp.i.z) + (float)(v12 * temp.j.z))
                                + (float)(v11 * temp.k.z))
                        + temp.c.z;
  v14 = *(float *)&position_8;
  *((float *)&position + 1) = (float)((float)((float)(*(float *)&v6 * temp.i.y) + (float)(v12 * temp.j.y))
                                    + (float)(v11 * temp.k.y))
                            + temp.c.y;
  *(_QWORD *)(a3 + 16) = position;
  *(float *)(a3 + 24) = v14;
  v15 = v13[3];
  v16 = v13[1];
  LODWORD(v6) = *(_DWORD *)(v5 + 4);
  v17 = *(float *)(v5 + 8);
  v18 = v13[2];
  *((float *)&position_8 + 1) = (float)((float)((float)(*(float *)(v5 + 12) * v15) - (float)(*v13 * *(float *)v5))
                                      - (float)(*(float *)&v6 * v16))
                              - (float)(v17 * v18);
  v19 = *v13;
  *(float *)&position = (float)((float)((float)(v17 * v16) + (float)(*v13 * *(float *)(v5 + 12)))
                              + (float)(*(float *)v5 * v15))
                      - (float)(v18 * *(float *)&v6);
  v20 = v17 * v19;
  v21 = *(float *)(v5 + 12);
  *((float *)&position + 1) = (float)((float)((float)(*(float *)&v6 * v15) - v20) + (float)(v18 * *(float *)v5))
                            + (float)(v16 * v21);
  *(float *)&position_8 = (float)((float)((float)(*(float *)&v6 * *v13) + (float)(v17 * v15))
                                - (float)(v16 * *(float *)v5))
                        + (float)(v18 * v21);
  *(_QWORD *)a3 = position;
  *(_QWORD *)(a3 + 8) = position_8;
  return (survarium::animation_space_vertex_id *)a3;
}
