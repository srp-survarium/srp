vostok::math::float3 *__thiscall vostok::particle::particle_domain_complex::generate(
        vostok::particle::particle_domain_complex *this,
        vostok::particle::particle_domain_complex *result,
        float *a3)
{
  vostok::math::float4x4 *transform; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float m_line_width; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  vostok::math::float3 *v22; // eax
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  vostok::particle::particle_domain_complex *v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm4_4
  float x; // xmm7_4
  float v36; // xmm7_4
  float y; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  vostok::math::float4x4 *v40; // eax
  vostok::math::float4x4 *v41; // eax
  double v42; // st7
  double v43; // st6
  double v44; // st7
  double v45; // st6
  double v46; // st5
  float v47; // xmm0_4
  float v48; // xmm1_4
  float m_cylinder_height; // xmm0_4
  double v50; // st7
  float v51; // xmm0_4
  float v52; // xmm0_4
  double v53; // st7
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  float v58; // xmm2_4
  float v59; // xmm0_4
  vostok::math::float4_pod *p_c; // eax
  float v62; // [esp+4h] [ebp-274h]
  vostok::math::float4x4 v63; // [esp+14h] [ebp-264h] BYREF
  vostok::math::float4x4 v64; // [esp+54h] [ebp-224h] BYREF
  vostok::math::float4x4 v65; // [esp+94h] [ebp-1E4h] BYREF
  vostok::math::float4x4 v66; // [esp+D4h] [ebp-1A4h] BYREF
  vostok::math::float4x4 v67; // [esp+114h] [ebp-164h] BYREF
  vostok::math::float4x4 resulta; // [esp+154h] [ebp-124h] BYREF
  vostok::math::float4x4 v69; // [esp+194h] [ebp-E4h] BYREF
  vostok::math::float4x4 v70; // [esp+1D4h] [ebp-A4h] BYREF
  vostok::math::float4x4 v71; // [esp+214h] [ebp-64h] BYREF
  vostok::math::float3 v72; // [esp+254h] [ebp-24h] BYREF
  vostok::math::float3 v73; // [esp+260h] [ebp-18h] BYREF
  $D38C34BC714B112AEE2977F5CA171B83 v74; // [esp+26Ch] [ebp-Ch] BYREF
  float v75; // [esp+280h] [ebp+8h]
  float v76; // [esp+280h] [ebp+8h]
  float m_outer_radius; // [esp+280h] [ebp+8h]
  float v78; // [esp+280h] [ebp+8h]
  float v79; // [esp+280h] [ebp+8h]
  float v80; // [esp+280h] [ebp+8h]
  float v81; // [esp+280h] [ebp+8h]
  float v82; // [esp+284h] [ebp+Ch]

  switch ( result->m_domain_type )
  {
    case 0u:
      v74 = result->164;
      transform = vostok::particle::particle_domain_complex::get_transform(result, &resulta);
      v6 = (float)(transform->k.x * v74.m_point_position.z) + (float)(transform->j.x * v74.m_point_position.y);
      v7 = transform->i.x * v74.m_point_position.x;
      goto LABEL_3;
    case 1u:
      m_line_width = result->m_line_width;
      v75 = vostok::particle::random_float(0.0, 1.0);
      v74.m_point_position.x = (float)((float)(s_bm_current_air_resistance - v75) * (float)(m_line_width * -0.5))
                             + (float)((float)(m_line_width * 0.5) * v75);
      v74.m_point_position.y = (float)((float)(s_bm_current_air_resistance - v75) * 0.0) + (float)(v75 * 0.0);
      v74.m_point_position.z = v74.m_point_position.y;
      transform = vostok::particle::particle_domain_complex::get_transform(result, &v63);
      v15 = (float)(transform->k.x * v74.m_point_position.z) + (float)(transform->j.x * v74.m_point_position.y);
      v16 = transform->i.x * v74.m_point_position.x;
      goto LABEL_6;
    case 2u:
      v21 = s_bm_current_air_resistance;
      v74.m_point_position.x = s_bm_current_air_resistance;
      v74.m_point_position.y = s_bm_current_air_resistance;
      v74.m_point_position.z = s_bm_current_air_resistance;
      memset(&v73, 0, sizeof(v73));
      v22 = vostok::particle::random_float3((const vostok::math::float3 *)&v74, &v72, &v73);
      v23 = v21 / fsqrt((float)((float)(v22->z * v22->z) + (float)(v22->y * v22->y)) + (float)(v22->x * v22->x));
      v24 = v23 * v22->x;
      v22->y = v23 * v22->y;
      v22->z = v22->z * v23;
      v22->x = v24;
      v73 = *v22;
      v25 = (float)(v73.z + v73.y) + v73.x;
      if ( v25 <= 0.001 )
        v25 = epsilon_3_4;
      v26 = result;
      v27 = v21 / v25;
      v28 = v27 * v73.x;
      v29 = v27;
      v30 = v27 * v73.z;
      v31 = v29 * v73.y;
      v32 = result->m_triangle_c.y * v30;
      v33 = result->m_triangle_c.z * v30;
      v34 = result->m_triangle_c.x * v30;
      x = result->m_triangle_b.x;
      v73.y = result->m_triangle_b.y * v31;
      v73.z = result->m_triangle_b.z * v31;
      v36 = x * v31;
      y = result->m_point_position.y;
      v38 = (float)((float)(result->m_point_position.z * v28) + v73.z) + v33;
      v74.m_point_position.x = (float)((float)(result->m_point_position.x * v28) + v36) + v34;
      v39 = (float)((float)(y * v28) + v73.y) + v32;
      v74.m_point_position.z = v38;
      v40 = &v70;
      goto LABEL_10;
    case 4u:
      v74.m_point_position.x = vostok::particle::random_float(result->m_box_width * -0.5, result->m_box_width * 0.5);
      v74.m_point_position.y = vostok::particle::random_float(result->m_box_height * -0.5, result->m_box_height * 0.5);
      v74.m_point_position.z = vostok::particle::random_float(result->m_box_depth * -0.5, result->m_box_depth * 0.5);
      v41 = vostok::particle::particle_domain_complex::get_transform(result, &v64);
      *a3 = v41->k.x * v74.m_point_position.z
          + v41->j.x * v74.m_point_position.y
          + v74.m_point_position.x * v41->i.x
          + v41->c.x;
      a3[1] = v41->k.y * v74.m_point_position.z
            + v41->i.y * v74.m_point_position.x
            + v41->j.y * v74.m_point_position.y
            + v41->c.y;
      v42 = v41->k.z * v74.m_point_position.z + v41->i.z * v74.m_point_position.x;
      v43 = v41->j.z * v74.m_point_position.y;
      goto LABEL_12;
    case 5u:
      v74.m_point_position.x = vostok::particle::random_float(-1.0, 1.0);
      v74.m_point_position.y = vostok::particle::random_float(-1.0, 1.0);
      v74.m_point_position.z = vostok::particle::random_float(-1.0, 1.0);
      v76 = result->m_outer_radius
          - vostok::particle::random_float(0.0, result->m_outer_radius - result->m_inner_radius);
      v47 = s_bm_current_air_resistance
          / fsqrt(
              (float)((float)(v74.m_point_position.x * v74.m_point_position.x)
                    + (float)(v74.m_point_position.z * v74.m_point_position.z))
            + (float)(v74.m_point_position.y * v74.m_point_position.y));
      v74.m_point_position.x = (float)(v47 * v74.m_point_position.x) * v76;
      v74.m_point_position.y = (float)(v47 * v74.m_point_position.y) * v76;
      v74.m_point_position.z = (float)(v47 * v74.m_point_position.z) * v76;
      transform = vostok::particle::particle_domain_complex::get_transform(result, &v69);
      v15 = (float)(transform->k.x * v74.m_point_position.z) + (float)(transform->j.x * v74.m_point_position.y);
      v16 = v74.m_point_position.x * transform->i.x;
LABEL_6:
      v17 = (float)(v15 + v16) + transform->c.x;
      v18 = transform->j.y * v74.m_point_position.y;
      *a3 = v17;
      v19 = (float)((float)((float)(transform->k.y * v74.m_point_position.z) + v18)
                  + (float)(transform->i.y * v74.m_point_position.x))
          + transform->c.y;
      v20 = transform->j.z * v74.m_point_position.y;
      a3[1] = v19;
      v12 = (float)(transform->k.z * v74.m_point_position.z) + v20;
      v13 = transform->i.z * v74.m_point_position.x;
      goto LABEL_4;
    case 6u:
      v74.m_point_position.y = vostok::particle::random_float(-1.0, 1.0);
      v74.m_point_position.z = vostok::particle::random_float(-1.0, 1.0);
      v48 = s_bm_current_air_resistance
          / fsqrt(
              (float)(v74.m_point_position.z * v74.m_point_position.z)
            + (float)(v74.m_point_position.y * v74.m_point_position.y));
      v74.m_point_position.z = v48 * v74.m_point_position.z;
      m_cylinder_height = result->m_cylinder_height;
      v74.m_point_position.y = v48 * v74.m_point_position.y;
      v82 = vostok::particle::random_float(m_cylinder_height * -0.5, m_cylinder_height * 0.5);
      m_outer_radius = result->m_outer_radius;
      v50 = vostok::particle::random_float(0.0, result->m_outer_radius - result->m_inner_radius);
      v51 = m_outer_radius - result->m_inner_radius;
      v73.x = (m_outer_radius - v50) * v74.m_point_position.y;
      v73.z = (result->m_outer_radius - vostok::particle::random_float(0.0, v51)) * v74.m_point_position.z;
      v41 = vostok::particle::particle_domain_complex::get_transform(result, &v67);
      *a3 = v41->j.x * v82 + v41->k.x * v73.z + v41->i.x * v73.x + v41->c.x;
      a3[1] = v41->j.y * v82 + v41->k.y * v73.z + v41->i.y * v73.x + v41->c.y;
      v42 = v41->j.z * v82 + v41->k.z * v73.z;
      v43 = v41->i.z * v73.x;
      goto LABEL_12;
    case 7u:
      v74.m_point_position.y = vostok::particle::random_float(-1.0, 1.0);
      v74.m_point_position.z = vostok::particle::random_float(-1.0, 1.0);
      v80 = vostok::particle::random_float(0.0, 1.0);
      v55 = s_bm_current_air_resistance
          / fsqrt(
              (float)(v74.m_point_position.y * v74.m_point_position.y)
            + (float)(v74.m_point_position.z * v74.m_point_position.z));
      v56 = (float)(v55 * v74.m_point_position.z) * v80;
      v57 = (float)(v55 * v74.m_point_position.y) * v80;
      v58 = v56;
      v81 = vostok::particle::random_float(-1.0, 0.0);
      v59 = result->m_outer_radius;
      v74.m_point_position.x = (float)(v57 * v59) * v81;
      v39 = result->m_cylinder_height * v81;
      v74.m_point_position.z = (float)(v59 * v81) * v58;
      v40 = &v71;
      v26 = result;
LABEL_10:
      v74.m_point_position.y = v39;
      transform = vostok::particle::particle_domain_complex::get_transform(v26, v40);
      v6 = (float)(transform->k.x * v74.m_point_position.z) + (float)(transform->j.x * v74.m_point_position.y);
      v7 = v74.m_point_position.x * transform->i.x;
LABEL_3:
      v8 = (float)(v6 + v7) + transform->c.x;
      v9 = transform->k.y * v74.m_point_position.z;
      *a3 = v8;
      v10 = (float)((float)((float)(transform->i.y * v74.m_point_position.x) + v9)
                  + (float)(transform->j.y * v74.m_point_position.y))
          + transform->c.y;
      v11 = transform->k.z * v74.m_point_position.z;
      a3[1] = v10;
      v12 = (float)(transform->i.z * v74.m_point_position.x) + v11;
      v13 = transform->j.z * v74.m_point_position.y;
LABEL_4:
      a3[2] = (float)(v12 + v13) + transform->c.z;
      return (vostok::math::float3 *)a3;
    case 9u:
      v74.m_point_position.y = vostok::particle::random_float(-1.0, 1.0);
      v74.m_point_position.z = vostok::particle::random_float(-1.0, 1.0);
      v52 = s_bm_current_air_resistance
          / fsqrt(
              (float)(v74.m_point_position.y * v74.m_point_position.y)
            + (float)(v74.m_point_position.z * v74.m_point_position.z));
      v74.m_point_position.z = v52 * v74.m_point_position.z;
      v78 = result->m_outer_radius;
      v62 = v78 - result->m_inner_radius;
      v74.m_point_position.y = v52 * v74.m_point_position.y;
      v53 = v78 - vostok::particle::random_float(0.0, v62);
      v79 = result->m_outer_radius;
      v54 = v79 - result->m_inner_radius;
      v73.x = v53 * v74.m_point_position.y;
      v73.z = (v79 - vostok::particle::random_float(0.0, v54)) * v74.m_point_position.z;
      v41 = vostok::particle::particle_domain_complex::get_transform(result, &v65);
      v44 = 0.0;
      *a3 = v41->j.x * 0.0 + v41->k.x * v73.z + v73.x * v41->i.x + v41->c.x;
      a3[1] = v41->k.y * v73.z + v41->i.y * v73.x + v41->j.y * 0.0 + v41->c.y;
      v45 = v41->k.z * v73.z;
      v46 = v41->i.z * v73.x;
      goto LABEL_14;
    case 0xAu:
      v74.m_point_position.x = vostok::particle::random_float(result->m_box_width * -0.5, result->m_box_width * 0.5);
      v74.m_point_position.z = vostok::particle::random_float(result->m_box_height * -0.5, result->m_box_height * 0.5);
      v41 = vostok::particle::particle_domain_complex::get_transform(result, &v66);
      v44 = 0.0;
      *a3 = v41->j.x * 0.0 + v41->k.x * v74.m_point_position.z + v41->i.x * v74.m_point_position.x + v41->c.x;
      a3[1] = v41->k.y * v74.m_point_position.z + v41->i.y * v74.m_point_position.x + v41->j.y * 0.0 + v41->c.y;
      v45 = v41->k.z * v74.m_point_position.z;
      v46 = v41->i.z * v74.m_point_position.x;
LABEL_14:
      v43 = v45 + v46;
      v42 = v44 * v41->j.z;
LABEL_12:
      a3[2] = v42 + v43 + v41->c.z;
      break;
    default:
      p_c = &vostok::particle::particle_domain_complex::get_transform(result, &v71)->c;
      *a3 = p_c->x;
      a3[1] = p_c->y;
      a3[2] = p_c->z;
      break;
  }
  return (vostok::math::float3 *)a3;
}
