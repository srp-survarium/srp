void __thiscall vostok::particle::particle_action_turbulence::update(
        vostok::particle::particle_action_turbulence *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  __m128 v5; // xmm0
  vostok::math::float4x4 *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  vostok::math::float4x4 *transform; // eax
  float v10; // xmm0_4
  __int128 m_box_width_low; // xmm1
  float v12; // xmm2_4
  __int128 v13; // xmm3
  unsigned int v14; // eax
  float v15; // xmm5_4
  __int128 v16; // xmm4
  unsigned int v17; // eax
  __int128 v18; // xmm4
  __int128 v19; // xmm3
  __int128 v20; // xmm3
  __int128 m_box_height_low; // xmm3
  unsigned int v22; // eax
  float v23; // xmm1_4
  __int128 v24; // xmm6
  vostok::particle::base_particle *v25; // ecx
  float v26; // xmm1_4
  __m128i v27; // xmm0
  float v28; // xmm5_4
  __m128 v29; // xmm0
  __m128i v30; // xmm0
  float v31; // xmm5_4
  float v32; // xmm4_4
  __m128 v33; // xmm0
  __m128i v34; // xmm0
  float v35; // xmm4_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm1_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float x; // [esp+20h] [ebp-B0h]
  float v45; // [esp+20h] [ebp-B0h]
  float m_ratio_y; // [esp+24h] [ebp-ACh]
  float m_ratio_x; // [esp+28h] [ebp-A8h]
  float v48; // [esp+2Ch] [ebp-A4h]
  float v49; // [esp+30h] [ebp-A0h]
  float m_ratio_z; // [esp+30h] [ebp-A0h]
  float v51; // [esp+34h] [ebp-9Ch]
  float v52; // [esp+38h] [ebp-98h]
  float v53; // [esp+3Ch] [ebp-94h]
  float v54; // [esp+40h] [ebp-90h]
  vostok::math::float4x4 result; // [esp+50h] [ebp-80h] BYREF
  vostok::math::float4x4 v56; // [esp+90h] [ebp-40h] BYREF

  if ( this->m_domain.m_domain_type == 4 )
  {
    if ( COERCE_FLOAT(LODWORD(this->m_domain.m_box_width) & _mask__AbsFloat_) < 0.0000001
      || COERCE_FLOAT(LODWORD(this->m_domain.m_box_height) & _mask__AbsFloat_) < 0.0000001
      || COERCE_FLOAT(LODWORD(this->m_domain.m_box_depth) & _mask__AbsFloat_) < 0.0000001 )
    {
      v5.m128_f32[0] = s_bm_current_air_resistance;
    }
    else
    {
      if ( !vostok::particle::particle_domain_complex::inside(&P->position, &this->m_domain) )
        return;
      transform = vostok::particle::particle_domain_complex::get_transform(&this->m_domain, &v56);
      v10 = P->position.y - transform->c.y;
      m_box_width_low = LODWORD(this->m_domain.m_box_width);
      v12 = fsqrt(
              (float)((float)((float)(P->position.x - transform->c.x) * (float)(P->position.x - transform->c.x))
                    + (float)((float)(P->position.z - transform->c.z) * (float)(P->position.z - transform->c.z)))
            + (float)(v10 * v10));
      v13 = m_box_width_low;
      v14 = 2;
      v15 = s_bm_current_air_resistance;
      while ( 1 )
      {
        if ( (v14 & 1) != 0 )
          v15 = v15 * *(float *)&v13;
        v14 >>= 1;
        if ( !v14 )
          break;
        v16 = v13;
        *(float *)&v16 = *(float *)&v13 * *(float *)&v13;
        v13 = v16;
      }
      v17 = 2;
      v18 = LODWORD(s_bm_current_air_resistance);
      while ( 1 )
      {
        if ( (v17 & 1) != 0 )
        {
          v19 = v18;
          *(float *)&v19 = *(float *)&v18 * *(float *)&m_box_width_low;
          v18 = v19;
        }
        v17 >>= 1;
        if ( !v17 )
          break;
        v20 = m_box_width_low;
        *(float *)&v20 = *(float *)&m_box_width_low * *(float *)&m_box_width_low;
        m_box_width_low = v20;
      }
      m_box_height_low = LODWORD(this->m_domain.m_box_height);
      v22 = 2;
      v23 = s_bm_current_air_resistance;
      while ( 1 )
      {
        if ( (v22 & 1) != 0 )
          v23 = v23 * *(float *)&m_box_height_low;
        v22 >>= 1;
        if ( !v22 )
          break;
        v24 = m_box_height_low;
        *(float *)&v24 = *(float *)&m_box_height_low * *(float *)&m_box_height_low;
        m_box_height_low = v24;
      }
      v5.m128_f32[0] = s_bm_current_air_resistance - (float)(v12 / fsqrt((float)(v23 + *(float *)&v18) + v15));
    }
LABEL_29:
    v48 = v5.m128_f32[0];
    if ( v5.m128_f32[0] < 0.0000001 )
      return;
    goto LABEL_30;
  }
  if ( this->m_domain.m_domain_type != 5 )
    return;
  if ( COERCE_FLOAT(LODWORD(this->m_domain.m_outer_radius) & _mask__AbsFloat_) >= 0.0000001 )
  {
    if ( vostok::particle::particle_domain_complex::inside(&P->position, &this->m_domain) )
    {
      v6 = vostok::particle::particle_domain_complex::get_transform(&this->m_domain, &result);
      v7 = P->position.y - v6->c.y;
      v8 = P->position.z - v6->c.z;
      v5.m128_f32[0] = s_bm_current_air_resistance
                     - (float)(fsqrt(
                                 (float)((float)(v7 * v7)
                                       + (float)((float)(P->position.x - v6->c.x) * (float)(P->position.x - v6->c.x)))
                               + (float)(v8 * v8))
                             / this->m_domain.m_outer_radius);
    }
    else
    {
      v5.m128_i32[0] = 0;
    }
    goto LABEL_29;
  }
  v5.m128_f32[0] = s_bm_current_air_resistance;
  v48 = s_bm_current_air_resistance;
LABEL_30:
  x = P->lifetime;
  vostok::particle::fractalsum1(x, this->m_frequency, this->m_octaves, P->m_seed);
  vostok::particle::fractalsum1(x, this->m_frequency, this->m_octaves, P->m_seed + 3);
  v49 = v5.m128_f32[0];
  vostok::particle::fractalsum1(x, this->m_frequency, this->m_octaves, P->m_seed + 5);
  v54 = v5.m128_f32[0];
  m_ratio_x = this->m_ratio_x;
  if ( COERCE_FLOAT(LODWORD(m_ratio_x) & _mask__AbsFloat_) >= 0.0000001 )
  {
    v5 = (__m128)v5.m128_u32[0];
    v5.m128_f32[0] = v5.m128_f32[0] * 6.2800002;
    v27 = (__m128i)_mm_cvtps_pd(v5);
    __libm_sse2_sin(v27);
    v26 = 0.0;
    *(float *)v27.m128i_i32 = *(double *)v27.m128i_i64;
    v45 = *(float *)v27.m128i_i32 * m_ratio_x;
  }
  else
  {
    v26 = 0.0;
    v45 = 0.0;
  }
  m_ratio_y = this->m_ratio_y;
  if ( COERCE_FLOAT(LODWORD(m_ratio_y) & _mask__AbsFloat_) >= 0.0000001 )
  {
    v29 = (__m128)LODWORD(v49);
    v29.m128_f32[0] = v49 * 6.2800002;
    v30 = (__m128i)_mm_cvtps_pd(v29);
    __libm_sse2_sin(v30);
    v26 = 0.0;
    v31 = *(double *)v30.m128i_i64;
    v28 = v31 * m_ratio_y;
  }
  else
  {
    v28 = 0.0;
  }
  m_ratio_z = this->m_ratio_z;
  if ( COERCE_FLOAT(LODWORD(m_ratio_z) & _mask__AbsFloat_) >= 0.0000001 )
  {
    v33 = (__m128)LODWORD(v54);
    v33.m128_f32[0] = v54 * 6.2800002;
    v34 = (__m128i)_mm_cvtps_pd(v33);
    __libm_sse2_sin(v34);
    v26 = 0.0;
    v35 = *(double *)v34.m128i_i64;
    v32 = v35 * m_ratio_z;
  }
  else
  {
    v32 = 0.0;
  }
  LODWORD(v36) = LODWORD(P->duration) & _mask__AbsFloat_;
  if ( v36 >= 0.0000001 )
  {
    vostok::particle::base_particle::get_linear_lifetime_impl(v25, (int)P, P->lifetime);
    v39 = v36 * this->m_attenuation;
    v37 = s_bm_current_air_resistance;
    v38 = s_bm_current_air_resistance - v39;
    v26 = 0.0;
  }
  else
  {
    v37 = s_bm_current_air_resistance;
    v38 = s_bm_current_air_resistance;
  }
  v40 = fsqrt((float)((float)(v32 * v32) + (float)(v28 * v28)) + (float)(v45 * v45));
  if ( v40 <= 0.0 )
  {
    v51 = 0.0;
    v53 = 0.0;
  }
  else
  {
    v41 = v37 / v40;
    v42 = (float)((float)((float)(this->m_magnitude - this->m_min_magnitude) * v48) + this->m_min_magnitude) * v38;
    v51 = (float)(v41 * v45) * v42;
    v26 = (float)(v41 * v28) * v42;
    v53 = (float)(v41 * v32) * v42;
  }
  v52 = P->position.y + (float)(v26 * time);
  v43 = P->position.z + (float)(v53 * time);
  P->position.x = P->position.x + (float)(v51 * time);
  P->position.y = v52;
  P->position.z = v43;
}
