bool __userpurge vostok::particle::particle_domain_complex::inside@<al>(
        const vostok::math::float3 *point@<eax>,
        vostok::particle::particle_domain_complex *this)
{
  bool result; // al
  float v3; // xmm0_4
  bool v4; // cc
  float v5; // xmm2_4
  float v6; // xmm1_4
  float m_box_depth; // xmm0_4
  bool v8; // cf
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // [esp+10h] [ebp-Ch] BYREF
  float v14; // [esp+14h] [ebp-8h]
  float v15; // [esp+18h] [ebp-4h]

  switch ( this->m_domain_type )
  {
    case 0u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      result = 0;
      if ( fsqrt((float)((float)(v15 * v15) + (float)(v14 * v14)) + (float)(v13 * v13)) < 0.0099999998 )
        return 1;
      return result;
    case 1u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      v3 = this->m_line_width * -0.5;
      if ( v13 < v3 || v3 < v13 || COERCE_FLOAT(LODWORD(v14) & 0x7FFFFFFF) >= 0.001 )
        return 0;
      v4 = COERCE_FLOAT(LODWORD(v15) & 0x7FFFFFFF) >= 0.001;
      goto LABEL_8;
    case 2u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      if ( COERCE_FLOAT(LODWORD(v14) & 0x7FFFFFFF) < 0.1
        && v13 > 0.0
        && s_bm_current_air_resistance > v13
        && v15 > 0.0
        && s_bm_current_air_resistance > v15 )
      {
        v4 = (float)(s_bm_current_air_resistance - v13) <= v15;
LABEL_8:
        if ( !v4 )
          return 1;
      }
      return 0;
    case 4u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      v5 = FLOAT_N0_5;
      if ( v13 < (float)(this->m_box_width * -0.5) )
        return 0;
      v6 = c_anim_center;
      if ( (float)(this->m_box_width * 0.5) < v13
        || v14 < (float)(this->m_box_height * -0.5)
        || (float)(this->m_box_height * 0.5) < v14 )
      {
        return 0;
      }
      m_box_depth = this->m_box_depth;
      goto LABEL_22;
    case 5u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      v9 = (float)(v14 * v14) + (float)(v15 * v15);
      v10 = v13 * v13;
      goto LABEL_30;
    case 6u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      v12 = fsqrt((float)(v13 * v13) + (float)(v15 * v15));
      if ( v12 < this->m_inner_radius || this->m_outer_radius < v12 || v14 < (float)(this->m_cylinder_height * -0.5) )
        return 0;
      v8 = (float)(this->m_cylinder_height * 0.5) < v14;
      return !v8;
    case 9u:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      v9 = v13 * v13;
      v10 = v15 * v15;
LABEL_30:
      v11 = fsqrt(v9 + v10);
      if ( v11 < this->m_inner_radius )
        return 0;
      v8 = this->m_outer_radius < v11;
      return !v8;
    case 0xAu:
      vostok::particle::particle_domain_complex::to_local_space(this, point, &v13);
      v5 = FLOAT_N0_5;
      if ( v13 < (float)(this->m_box_width * -0.5) )
        return 0;
      v6 = c_anim_center;
      if ( (float)(this->m_box_width * 0.5) < v13 )
        return 0;
      m_box_depth = this->m_box_height;
LABEL_22:
      if ( v15 < (float)(m_box_depth * v5) )
        return 0;
      v8 = (float)(m_box_depth * v6) < v15;
      return !v8;
    default:
      return 0;
  }
}
