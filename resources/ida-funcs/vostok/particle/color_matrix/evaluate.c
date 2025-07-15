vostok::math::float4 *__userpurge vostok::particle::color_matrix::evaluate@<eax>(
        vostok::particle::color_matrix *this@<eax>,
        float a2@<xmm1>,
        vostok::math::float4 *y,
        const vostok::math::float4 *default_value,
        vostok::math::float4_pod *p_result)
{
  float v5; // xmm0_4
  float v6; // xmm2_4
  unsigned int v8; // edi
  unsigned int m_num_columns; // edx
  vostok::particle::color_matrix_point_type *pointer; // ebx
  float *p_x; // eax
  unsigned int m_num_rows; // esi
  int v14; // eax
  float *v15; // ecx
  int v16; // eax
  int v17; // ecx
  vostok::particle::color_matrix_point_type *v18; // eax
  float v19; // xmm3_4
  vostok::particle::color_matrix_point_type *v20; // ecx
  float x; // xmm1_4
  float *v22; // esi
  _QWORD *v23; // edx
  float v24; // xmm1_4
  float *v25; // esi
  vostok::math::float4 *v26; // eax
  float *v27; // esi
  vostok::math::float4_pod a0; // [esp+0h] [ebp-94h]
  vostok::math::float4_pod v29; // [esp+10h] [ebp-84h]
  vostok::math::float4_pod v30; // [esp+20h] [ebp-74h]
  vostok::math::float4_pod v31; // [esp+30h] [ebp-64h]
  vostok::math::float4_pod result; // [esp+58h] [ebp-3Ch] BYREF
  vostok::math::float4_pod v33; // [esp+6Ch] [ebp-28h]
  float v34; // [esp+7Ch] [ebp-18h]
  unsigned int v35; // [esp+80h] [ebp-14h]
  float *p_y; // [esp+84h] [ebp-10h]
  float v37; // [esp+88h] [ebp-Ch]
  unsigned int v38; // [esp+8Ch] [ebp-8h]
  float v39; // [esp+A0h] [ebp+Ch]
  float v40; // [esp+A4h] [ebp+10h]

  v5 = 0.0;
  v6 = s_bm_current_air_resistance;
  if ( a2 > 0.0 )
  {
    if ( s_bm_current_air_resistance < a2 )
      v37 = s_bm_current_air_resistance;
    else
      v37 = a2;
  }
  else
  {
    v37 = 0.0;
  }
  if ( *(float *)&default_value > 0.0 )
  {
    if ( s_bm_current_air_resistance < *(float *)&default_value )
      v5 = s_bm_current_air_resistance;
    else
      v5 = *(float *)&default_value;
  }
  v8 = 1;
  v39 = v5;
  if ( this->m_evaluate_type == random_evaluate_type )
    v39 = vostok::particle::random_float(0.0, 1.0);
  m_num_columns = this->m_num_columns;
  if ( m_num_columns > 1 )
  {
    pointer = this->m_points.pointer;
    p_x = &this->m_points.pointer[1].position.x;
    while ( v37 < *(p_x - 6) || *p_x < v37 )
    {
      ++v8;
      p_x += 6;
      if ( v8 >= m_num_columns )
        goto LABEL_29;
    }
    m_num_rows = this->m_num_rows;
    v38 = 1;
    v35 = m_num_rows;
    if ( m_num_rows > 1 )
    {
      v14 = 24 * m_num_columns;
      p_y = &pointer[m_num_columns].position.y;
      v15 = &pointer->position.y;
      while ( v39 < *v15 || *p_y < v39 )
      {
        ++v38;
        p_y = (float *)((char *)p_y + v14);
        v15 = (float *)((char *)v15 + v14);
        if ( v38 >= v35 )
          goto LABEL_29;
      }
      v16 = (v38 - 1) * m_num_columns;
      v17 = v16 + v8 - 1;
      v18 = &pointer[v8 + v16];
      v19 = v18->position.y;
      v20 = &pointer[v17];
      x = v20->position.x;
      v22 = &pointer[v8 + v38 * m_num_columns].color.x;
      *(float *)&v35 = v18->position.x - x;
      v23 = (_QWORD *)&pointer[v38 * m_num_columns - 1 + v8].color.x;
      *(float *)&v38 = x;
      v40 = *(float *)&v35;
      v24 = v22[5] - v19;
      v34 = v19;
      *(float *)&p_y = v24;
      if ( COERCE_FLOAT(v35 & 0x7FFFFFFF) <= 0.0000099999997 )
        v40 = v6;
      v35 = LODWORD(v24) & 0x7FFFFFFF;
      if ( COERCE_FLOAT(LODWORD(v24) & 0x7FFFFFFF) <= 0.0000099999997 )
        *(float *)&p_y = v6;
      v31.z = *v22;
      v25 = v22 + 1;
      v31.w = *v25;
      *(_QWORD *)&v30.elements[2] = *v23;
      *(_QWORD *)&v31.x = v23[1];
      *(_QWORD *)&v29.elements[2] = *(_QWORD *)&v18->color.x;
      *(_QWORD *)&v30.x = *(_QWORD *)&v18->color.elements[2];
      *(_QWORD *)&a0.elements[2] = *(_QWORD *)&v20->color.x;
      *(_QWORD *)&v29.x = *(_QWORD *)&v20->color.elements[2];
      a0.y = (v39 - v34) / *(float *)&p_y;
      a0.x = (v37 - *(float *)&v38) / v40;
      v33 = *vostok::particle::bilinear_interpolation<vostok::math::float4_pod>(
               &result,
               a0,
               v29,
               v30,
               v31,
               *(_QWORD *)(v25 + 1));
      result = v33;
      p_result = &result;
    }
  }
LABEL_29:
  v26 = y;
  y->x = p_result->x;
  v27 = &p_result->y;
  y->y = *v27;
  *(_QWORD *)&y->elements[2] = *(_QWORD *)(v27 + 1);
  return v26;
}
