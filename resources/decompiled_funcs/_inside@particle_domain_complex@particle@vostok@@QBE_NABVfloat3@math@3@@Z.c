bool __thiscall vostok::particle::particle_domain_complex::inside(
        vostok::particle::particle_domain_complex *this,
        const vostok::math::float3 *point)
{
  vostok::math::float3_pod *v2; // ecx
  bool v3; // al
  vostok::math::float3_pod *v4; // ecx
  vostok::math::float2 *v5; // ecx
  float *v6; // eax
  vostok::math::float2_pod *v7; // ecx
  vostok::math::float2 *v8; // ecx
  float *v9; // eax
  vostok::math::float2_pod *v10; // ecx
  float v11; // [esp+4h] [ebp-D0h]
  bool v12; // [esp+4h] [ebp-D0h]
  bool v13; // [esp+8h] [ebp-CCh]
  bool v14; // [esp+Ch] [ebp-C8h]
  bool v15; // [esp+10h] [ebp-C4h]
  bool v16; // [esp+14h] [ebp-C0h]
  bool v17; // [esp+18h] [ebp-BCh]
  bool v18; // [esp+1Ch] [ebp-B8h]
  _BYTE v20[8]; // [esp+4Ch] [ebp-88h] BYREF
  _BYTE v21[8]; // [esp+54h] [ebp-80h] BYREF
  float v22; // [esp+5Ch] [ebp-78h] BYREF
  float v23; // [esp+60h] [ebp-74h] BYREF
  float right; // [esp+64h] [ebp-70h] BYREF
  vostok::math::float3 v25; // [esp+68h] [ebp-6Ch] BYREF
  float v26; // [esp+74h] [ebp-60h]
  vostok::math::float3 v27; // [esp+78h] [ebp-5Ch] BYREF
  float from_center; // [esp+84h] [ebp-50h]
  vostok::math::float3 v29; // [esp+88h] [ebp-4Ch] BYREF
  float dist; // [esp+94h] [ebp-40h]
  vostok::math::float3 v31; // [esp+98h] [ebp-3Ch] BYREF
  vostok::math::float3 v32; // [esp+A4h] [ebp-30h] BYREF
  vostok::math::float3 v33; // [esp+B0h] [ebp-24h] BYREF
  vostok::math::float3 result; // [esp+BCh] [ebp-18h] BYREF
  vostok::math::float3 local_space_pos; // [esp+C8h] [ebp-Ch] BYREF

  switch ( this->m_domain_type )
  {
    case 0u:
      vostok::particle::particle_domain_complex::to_local_space(this, &local_space_pos, point);
      v3 = vostok::math::float3_pod::length(v2, &local_space_pos.x) < 0.0099999998;
      break;
    case 1u:
      vostok::particle::particle_domain_complex::to_local_space(this, &result, point);
      v18 = 0;
      if ( result.x >= (float)((float)-this->m_line_width / 2.0)
        && (float)((float)-this->m_line_width / 2.0) >= result.x )
      {
        right = *(float *)&FLOAT_0_0;
        if ( vostok::math::is_similar<float>(&result.y, &right, 0.001) )
        {
          v23 = *(float *)&FLOAT_0_0;
          if ( vostok::math::is_similar<float>(&result.z, &v23, 0.001) )
            v18 = 1;
        }
      }
      v3 = v18;
      break;
    case 2u:
      vostok::particle::particle_domain_complex::to_local_space(this, &v33, point);
      v22 = *(float *)&FLOAT_0_0;
      v17 = vostok::math::is_similar<float>(&v33.y, &v22, 0.1)
         && v33.x > 0.0
         && *(float *)&clear_value > v33.x
         && v33.z > 0.0
         && *(float *)&clear_value > v33.z
         && (float)(*(float *)&clear_value - v33.x) > v33.z;
      v3 = v17;
      break;
    case 4u:
      vostok::particle::particle_domain_complex::to_local_space(this, &v32, point);
      v16 = v32.x >= (float)((float)-this->m_box_width * 0.5)
         && (float)(this->m_box_width * 0.5) >= v32.x
         && v32.y >= (float)((float)-this->m_box_height * 0.5)
         && (float)(this->m_box_height * 0.5) >= v32.y
         && v32.z >= (float)((float)-this->m_box_depth * 0.5)
         && (float)(this->m_box_depth * 0.5) >= v32.z;
      v3 = v16;
      break;
    case 5u:
      vostok::particle::particle_domain_complex::to_local_space(this, &v29, point);
      dist = vostok::math::float3_pod::length(v4, &v29.x);
      v14 = dist >= this->m_inner_radius && this->m_outer_radius >= dist;
      v3 = v14;
      break;
    case 6u:
      vostok::particle::particle_domain_complex::to_local_space(this, &v27, point);
      v6 = (float *)vostok::math::float2::float2(v5, (int)v21, SLODWORD(v27.x), v27.z, v11);
      from_center = vostok::math::float2_pod::length(v7, v6);
      v13 = from_center >= this->m_inner_radius
         && this->m_outer_radius >= from_center
         && v27.y >= (float)-this->m_cylinder_height * 0.5
         && this->m_cylinder_height * 0.5 >= v27.y;
      v3 = v13;
      break;
    case 7u:
      v3 = 0;
      break;
    case 9u:
      vostok::particle::particle_domain_complex::to_local_space(this, &v25, point);
      v9 = (float *)vostok::math::float2::float2(v8, (int)v20, SLODWORD(v25.x), v25.z, v11);
      v26 = vostok::math::float2_pod::length(v10, v9);
      v12 = v26 >= this->m_inner_radius && this->m_outer_radius >= v26;
      v3 = v12;
      break;
    case 0xAu:
      vostok::particle::particle_domain_complex::to_local_space(this, &v31, point);
      v15 = v31.x >= (float)((float)-this->m_box_width * 0.5)
         && (float)(this->m_box_width * 0.5) >= v31.x
         && v31.z >= (float)-this->m_box_height * 0.5
         && this->m_box_height * 0.5 >= v31.z;
      v3 = v15;
      break;
    default:
      v3 = 0;
      break;
  }
  return v3;
}
