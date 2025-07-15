void __userpurge vostok::render::system_renderer::draw_3D_point(
        vostok::render::system_renderer *this@<ecx>,
        vostok::render::system_renderer *position,
        int width,
        const vostok::math::color *color,
        bool use_depth)
{
  float *v5; // ebx
  vostok::render::backend *v6; // ecx
  vostok::render::renderer_context *m_renderer_context; // eax
  vostok::buffer_vector<vostok::render::vertex_colored> *v8; // ecx
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm3_4
  float v22; // xmm5_4
  float v23; // xmm4_4
  float v24; // xmm6_4
  vostok::math::float4_pod *p_j; // ebx
  unsigned int m_value; // eax
  vostok::buffer_vector<unsigned short> *v27; // ecx
  vostok::buffer_vector<unsigned short> *v28; // ecx
  vostok::buffer_vector<unsigned short> *v29; // ecx
  vostok::buffer_vector<unsigned short> *v30; // ecx
  vostok::buffer_vector<unsigned short> *v31; // ecx
  vostok::render::system_renderer *v32; // ecx
  vostok::math::float4x4 v33; // [esp+10h] [ebp-154h] BYREF
  vostok::render::vertex_colored value; // [esp+50h] [ebp-114h] BYREF
  char v35; // [esp+9Ch] [ebp-C8h] BYREF
  vostok::math::float4x4 v36; // [esp+A0h] [ebp-C4h] BYREF
  vostok::math::float4x4 v37; // [esp+E0h] [ebp-84h] BYREF
  float v38; // [esp+120h] [ebp-44h]
  float v39; // [esp+124h] [ebp-40h]
  float v40; // [esp+128h] [ebp-3Ch]
  float v41; // [esp+12Ch] [ebp-38h]
  float x; // [esp+130h] [ebp-34h] BYREF
  float y; // [esp+134h] [ebp-30h]
  float z; // [esp+138h] [ebp-2Ch]
  float v45; // [esp+13Ch] [ebp-28h]
  float v46; // [esp+140h] [ebp-24h]
  float v47; // [esp+144h] [ebp-20h]
  unsigned __int16 *indices_begin; // [esp+148h] [ebp-1Ch] BYREF
  unsigned __int16 *indices_end; // [esp+14Ch] [ebp-18h]
  char *v50; // [esp+150h] [ebp-14h]
  float v51; // [esp+154h] [ebp-10h] BYREF
  float v52; // [esp+158h] [ebp-Ch]
  float v53; // [esp+15Ch] [ebp-8h]
  char v54; // [esp+160h] [ebp-4h] BYREF

  v5 = (float *)width;
  if ( vostok::render::system_renderer::is_effects_ready(this, position) )
  {
    v46 = COERCE_FLOAT(
            vostok::render::backend::target_width(
              v6,
              SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z)));
    m_renderer_context = position->m_renderer_context;
    width = (int)&m_renderer_context->m_v;
    qmemcpy(&v33, &m_renderer_context->m_v, sizeof(v33));
    qmemcpy(&v36, &m_renderer_context->m_p, sizeof(v36));
    vostok::math::mul4x4(&v36, &v33, &v37);
    vostok::math::float4x4::try_invert(&v37, &v37);
    qmemcpy(&v36, (const void *)width, sizeof(v36));
    vostok::math::float4x4::try_invert(&v36, &v36);
    v9 = *v5;
    *(float *)&width = fsqrt(
                         (float)((float)((float)(v36.c.z - v5[2]) * (float)(v36.c.z - v5[2]))
                               + (float)((float)(v36.c.y - v5[1]) * (float)(v36.c.y - v5[1])))
                       + (float)((float)(v36.c.x - v9) * (float)(v36.c.x - v9)));
    v46 = (float)LODWORD(v46);
    v39 = v46;
    v40 = v37.k.x * 0.0;
    v10 = (float)((float)(v37.j.x * 0.0) + (float)(v37.i.x * 1000.0)) + (float)(v37.k.x * 0.0);
    v38 = v37.k.y * 0.0;
    v11 = (float)((float)(v37.j.y * 0.0) + (float)(v37.i.y * 1000.0)) + (float)(v37.k.y * 0.0);
    v47 = v37.k.z * 0.0;
    v12 = (float)((float)(v37.j.z * 0.0) + (float)(v37.i.z * 1000.0)) + (float)(v37.k.z * 0.0);
    v13 = fsqrt((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v10 * v10));
    v41 = s_bm_current_air_resistance / v13;
    v45 = v12 * (float)(s_bm_current_air_resistance / v13);
    v45 = (float)(v45 * (float)(s_bm_current_air_resistance / v46)) * 3.0;
    y = (float)((float)((float)((float)(s_bm_current_air_resistance / v46)
                              * (float)((float)(s_bm_current_air_resistance / v13) * v10))
                      * 3.0)
              * 0.5)
      * *(float *)&width;
    v52 = (float)((float)((float)(v11 * (float)(s_bm_current_air_resistance / v13))
                        * (float)(s_bm_current_air_resistance / v46))
                * 3.0)
        * 0.5;
    z = v52 * *(float *)&width;
    v14 = v45 * 0.5;
    v45 = (float)(v45 * 0.5) * *(float *)&width;
    v53 = v14;
    v51 = (float)((float)(v37.i.x * 0.0) - (float)(v37.j.x * 1000.0)) + (float)(v37.k.x * 0.0);
    v15 = (float)((float)(v37.i.y * 0.0) - (float)(v37.j.y * 1000.0)) + (float)(v37.k.y * 0.0);
    v16 = (float)((float)(v37.i.z * 0.0) - (float)(v37.j.z * 1000.0)) + (float)(v37.k.z * 0.0);
    v17 = fsqrt((float)((float)(v51 * v51) + (float)(v16 * v16)) + (float)(v15 * v15));
    v18 = v5[1];
    v52 = (float)((float)((float)((float)(v15 * (float)(s_bm_current_air_resistance / v17))
                                * (float)(s_bm_current_air_resistance / v46))
                        * 3.0)
                * 0.5)
        * *(float *)&width;
    v19 = v5[2];
    v53 = (float)((float)((float)((float)(v16 * (float)(s_bm_current_air_resistance / v17))
                                * (float)(s_bm_current_air_resistance / v46))
                        * 3.0)
                * 0.5)
        * *(float *)&width;
    v20 = (float)((float)((float)((float)(s_bm_current_air_resistance / v46)
                                * (float)((float)(s_bm_current_air_resistance / v17) * v51))
                        * 3.0)
                * 0.5)
        * *(float *)&width;
    v21 = v9 - y;
    v22 = v9 + y;
    *(float *)&width = v18;
    v23 = v18 - z;
    v47 = v19;
    v24 = v19 - v45;
    v37.j.x = v21 - v20;
    v37.j.y = v23 - v52;
    v37.j.z = v24 - v53;
    v37.j.w = v21 + v20;
    v37.k.x = v23 + v52;
    v37.k.y = v24 + v53;
    LODWORD(value.position.x) = &value.color;
    LODWORD(value.position.y) = &value.color;
    LODWORD(value.position.z) = &v35;
    v37.k.z = v22 + v20;
    v37.k.w = (float)(z + *(float *)&width) + v52;
    v37.c.x = (float)(v45 + v47) + v53;
    indices_begin = (unsigned __int16 *)&v51;
    indices_end = (unsigned __int16 *)&v51;
    v37.c.y = v22 - v20;
    v37.c.z = (float)(z + *(float *)&width) - v52;
    v37.c.w = (float)(v45 + v47) - v53;
    v50 = &v54;
    p_j = &v37.j;
    width = 4;
    do
    {
      m_value = color->m_value;
      x = p_j->x;
      y = p_j->y;
      z = p_j->z;
      v45 = *(float *)&m_value;
      vostok::buffer_vector<vostok::render::vertex_colored>::push_back(v8, &value, &x);
      p_j = (vostok::math::float4_pod *)((char *)p_j + 12);
      --width;
    }
    while ( *(float *)&width != 0.0 );
    width = 2;
    vostok::buffer_vector<unsigned short>::push_back(
      (vostok::buffer_vector<unsigned short> *)v8,
      (int)&indices_begin,
      (const unsigned __int16 *)&width);
    width = 1;
    vostok::buffer_vector<unsigned short>::push_back(v27, (int)&indices_begin, (const unsigned __int16 *)&width);
    *(float *)&width = 0.0;
    vostok::buffer_vector<unsigned short>::push_back(v28, (int)&indices_begin, (const unsigned __int16 *)&width);
    width = 3;
    vostok::buffer_vector<unsigned short>::push_back(v29, (int)&indices_begin, (const unsigned __int16 *)&width);
    width = 2;
    vostok::buffer_vector<unsigned short>::push_back(v30, (int)&indices_begin, (const unsigned __int16 *)&width);
    *(float *)&width = 0.0;
    vostok::buffer_vector<unsigned short>::push_back(v31, (int)&indices_begin, (const unsigned __int16 *)&width);
    vostok::render::system_renderer::draw_triangles(
      (const vostok::render::vertex_colored *const)LODWORD(value.position.y),
      v32,
      position,
      SLODWORD(value.position.x),
      (unsigned __int8 *)indices_begin,
      (char *)indices_end,
      0);
  }
}
