vostok::math::float3 *__thiscall vostok::particle::particle_domain_complex::generate(
        vostok::particle::particle_domain_complex *this,
        vostok::math::float3 *result)
{
  vostok::math::float4x4 *transform; // eax
  vostok::math::float3 *v3; // eax
  vostok::math::float3 *v4; // eax
  vostok::math::float3 *v5; // eax
  const vostok::math::float3 *v6; // esi
  vostok::math::float4x4 *v7; // eax
  const vostok::math::float3 *v8; // eax
  const vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // eax
  float v11; // xmm0_4
  vostok::math::float3 *v12; // esi
  vostok::math::float3 *v13; // edi
  vostok::math::float3 *v14; // eax
  vostok::math::float3 *v15; // eax
  vostok::math::float3 *v16; // esi
  vostok::math::float4x4 *v17; // eax
  const vostok::math::float3 *v18; // eax
  const vostok::math::float3 *v19; // esi
  vostok::math::float4x4 *v20; // eax
  const vostok::math::float3 *v21; // eax
  const vostok::math::float3 *v22; // esi
  vostok::math::float4x4 *v23; // eax
  vostok::math::float3 *v24; // eax
  vostok::math::float3 *v25; // esi
  vostok::math::float4x4 *v26; // eax
  vostok::math::float2 *v27; // ecx
  vostok::math::float2_pod *v28; // ecx
  float y; // edx
  double v30; // st7
  double v31; // st7
  vostok::math::float4x4 *v32; // eax
  vostok::math::float2 *v33; // ecx
  vostok::math::float2_pod *v34; // ecx
  float v35; // edx
  double v36; // st7
  double v37; // st7
  vostok::math::float4x4 *v38; // eax
  vostok::math::float2 *v39; // ecx
  vostok::math::float2_pod *v40; // ecx
  vostok::math::float2 *v41; // eax
  vostok::math::float3 *v42; // eax
  vostok::math::float3 *v43; // eax
  vostok::math::float4x4 *v44; // eax
  survarium::game_camera *v45; // ecx
  vostok::math::float3 *v46; // eax
  vostok::math::float3 other_x; // [esp+Ch] [ebp-430h]
  vostok::math::float3 other_xa; // [esp+Ch] [ebp-430h]
  unsigned int other_y; // [esp+10h] [ebp-42Ch]
  unsigned int other_ya; // [esp+10h] [ebp-42Ch]
  unsigned int other_yb; // [esp+10h] [ebp-42Ch]
  unsigned int other_yc; // [esp+10h] [ebp-42Ch]
  unsigned int min_value; // [esp+14h] [ebp-428h]
  unsigned int min_valuea; // [esp+14h] [ebp-428h]
  float max_value; // [esp+18h] [ebp-424h]
  const vostok::math::float3 *max_valuea; // [esp+18h] [ebp-424h]
  float max_valueb; // [esp+18h] [ebp-424h]
  float max_valuec; // [esp+18h] [ebp-424h]
  float max_valued; // [esp+18h] [ebp-424h]
  float max_valuee; // [esp+18h] [ebp-424h]
  float max_valuef; // [esp+18h] [ebp-424h]
  float max_valueg; // [esp+18h] [ebp-424h]
  float max_valueh; // [esp+18h] [ebp-424h]
  float max_valuei; // [esp+18h] [ebp-424h]
  float max_valuej; // [esp+18h] [ebp-424h]
  float max_valuek; // [esp+18h] [ebp-424h]
  float max_valuel; // [esp+18h] [ebp-424h]
  float v68; // [esp+1Ch] [ebp-420h]
  int v69; // [esp+24h] [ebp-418h]
  int v70; // [esp+28h] [ebp-414h]
  int v71; // [esp+2Ch] [ebp-410h]
  vostok::math::float2_pod *v73; // [esp+38h] [ebp-404h]
  vostok::math::float2 *v74; // [esp+3Ch] [ebp-400h]
  vostok::math::float2 *v75; // [esp+40h] [ebp-3FCh]
  vostok::math::float4x4 v76; // [esp+8Ch] [ebp-3B0h] BYREF
  vostok::math::float4x4 v77; // [esp+CCh] [ebp-370h] BYREF
  vostok::math::float3 v78; // [esp+10Ch] [ebp-330h] BYREF
  vostok::math::float3 v79; // [esp+118h] [ebp-324h] BYREF
  _BYTE v80[8]; // [esp+124h] [ebp-318h] BYREF
  vostok::math::float4x4 v81; // [esp+12Ch] [ebp-310h] BYREF
  vostok::math::float4x4 v82; // [esp+16Ch] [ebp-2D0h] BYREF
  vostok::math::float3 v83; // [esp+1ACh] [ebp-290h] BYREF
  float value; // [esp+1B8h] [ebp-284h] BYREF
  vostok::math::float4x4 v85; // [esp+1BCh] [ebp-280h] BYREF
  vostok::math::float3 v86; // [esp+1FCh] [ebp-240h] BYREF
  vostok::math::float4x4 v87; // [esp+208h] [ebp-234h] BYREF
  vostok::math::float3 v88; // [esp+248h] [ebp-1F4h] BYREF
  vostok::math::float4x4 v89; // [esp+254h] [ebp-1E8h] BYREF
  vostok::math::float3 v90; // [esp+294h] [ebp-1A8h] BYREF
  vostok::math::float3 v91; // [esp+2A0h] [ebp-19Ch] BYREF
  vostok::math::float3 v92; // [esp+2ACh] [ebp-190h] BYREF
  vostok::math::float3 v93; // [esp+2B8h] [ebp-184h] BYREF
  vostok::math::float3 v94; // [esp+2C4h] [ebp-178h] BYREF
  vostok::math::float4x4 v95; // [esp+2D0h] [ebp-16Ch] BYREF
  vostok::math::float3 v96; // [esp+310h] [ebp-12Ch] BYREF
  vostok::math::float3 v97; // [esp+31Ch] [ebp-120h] BYREF
  vostok::math::float3 v98; // [esp+328h] [ebp-114h] BYREF
  vostok::math::float3 v99; // [esp+334h] [ebp-108h] BYREF
  vostok::math::float3 v100; // [esp+340h] [ebp-FCh] BYREF
  vostok::math::float3 v101; // [esp+34Ch] [ebp-F0h] BYREF
  vostok::math::float4x4 v102; // [esp+358h] [ebp-E4h] BYREF
  vostok::math::float3 vector; // [esp+398h] [ebp-A4h] BYREF
  vostok::math::float4x4 v104; // [esp+3A4h] [ebp-98h] BYREF
  vostok::math::float2 xz_offset; // [esp+3E4h] [ebp-58h] BYREF
  vostok::math::float3 v106; // [esp+3ECh] [ebp-50h] BYREF
  vostok::math::float2 direction; // [esp+3F8h] [ebp-44h] BYREF
  vostok::math::float3 position; // [esp+400h] [ebp-3Ch] BYREF
  vostok::math::float3 pos; // [esp+40Ch] [ebp-30h] BYREF
  float height; // [esp+418h] [ebp-24h]
  vostok::math::float2 dir2d; // [esp+41Ch] [ebp-20h] BYREF
  vostok::math::float3 dir; // [esp+424h] [ebp-18h] BYREF
  vostok::math::float3 weights; // [esp+430h] [ebp-Ch] BYREF

  switch ( this->m_domain_type )
  {
    case 0u:
      vostok::math::float3::float3((vostok::math::float3 *)&this->164, &vector);
      transform = vostok::particle::particle_domain_complex::get_transform(this, &v104);
      vostok::math::float4x4::transform_position(&vector, result, transform);
      v3 = result;
      break;
    case 1u:
      max_value = vostok::particle::random_float(0.0, 1.0);
      vostok::math::float3::float3(&v101, COERCE_UNSIGNED_INT(this->m_line_width / 2.0), COERCE_UNSIGNED_INT(0.0), 0.0);
      other_x = *v4;
      vostok::math::float3::float3(
        &v100,
        COERCE_UNSIGNED_INT((float)-this->m_line_width / 2.0),
        COERCE_UNSIGNED_INT(0.0),
        0.0);
      v6 = vostok::particle::linear_interpolation<vostok::math::float3>(&v99, *v5, other_x, max_value);
      v7 = vostok::particle::particle_domain_complex::get_transform(this, &v102);
      vostok::math::float4x4::transform_position(v6, result, v7);
      v3 = result;
      break;
    case 2u:
      vostok::math::float3::float3(&v98, COERCE_UNSIGNED_INT(1.0), COERCE_UNSIGNED_INT(1.0), 1.0);
      max_valuea = v8;
      vostok::math::float3::float3(&v97, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
      v10 = vostok::particle::random_float3(&v96, v9, max_valuea);
      weights = *vostok::math::float3_pod::normalize(v10);
      v11 = (float)(weights.x + weights.y) + weights.z;
      vostok::math::max();
      vostok::math::float3_pod::operator/=(&weights, v11);
      v12 = vostok::math::operator*(&this->m_triangle_c, &v94, &weights.z);
      v13 = vostok::math::operator*(&this->m_triangle_b, &v93, &weights.y);
      v14 = vostok::math::operator*(&this->m_point_position, &v92, &weights.x);
      v15 = vostok::math::operator+(v13, v14, &v91);
      v16 = vostok::math::operator+(v12, v15, &v90);
      v17 = vostok::particle::particle_domain_complex::get_transform(this, &v95);
      vostok::math::float4x4::transform_position(v16, result, v17);
      v3 = result;
      break;
    case 4u:
      max_valueb = vostok::particle::random_float(-0.5 * this->m_box_depth, 0.5 * this->m_box_depth);
      *(float *)&min_value = vostok::particle::random_float(-0.5 * this->m_box_height, 0.5 * this->m_box_height);
      *(float *)&other_y = vostok::particle::random_float(-0.5 * this->m_box_width, 0.5 * this->m_box_width);
      vostok::math::float3::float3(&v88, other_y, min_value, max_valueb);
      v19 = v18;
      v20 = vostok::particle::particle_domain_complex::get_transform(this, &v89);
      vostok::math::float4x4::transform_position(v19, result, v20);
      v3 = result;
      break;
    case 5u:
      max_valued = vostok::particle::random_float(-1.0, 1.0);
      *(float *)&min_valuea = vostok::particle::random_float(-1.0, 1.0);
      *(float *)&other_yb = vostok::particle::random_float(-1.0, 1.0);
      vostok::math::float3::float3(&dir, other_yb, min_valuea, max_valued);
      value = this->m_outer_radius - vostok::particle::random_float(0.0, this->m_outer_radius - this->m_inner_radius);
      v24 = vostok::math::float3_pod::normalize(&dir);
      v25 = vostok::math::operator*(v24, &v83, &value);
      v26 = vostok::particle::particle_domain_complex::get_transform(this, &v85);
      vostok::math::float4x4::transform_position(v25, result, v26);
      v3 = result;
      break;
    case 6u:
      max_valuee = vostok::particle::random_float(-1.0, 1.0);
      *(float *)&v71 = vostok::particle::random_float(-1.0, 1.0);
      vostok::math::float2::float2(v27, (int)&dir2d, v71, max_valuee, v68);
      max_valuef = vostok::math::float2_pod::length(v28, &dir2d.x);
      v75 = vostok::math::float2_pod::operator/=(&dir2d, max_valuef);
      y = v75->y;
      dir2d.x = v75->x;
      dir2d.y = y;
      height = vostok::particle::random_float(-0.5 * this->m_cylinder_height, 0.5 * this->m_cylinder_height);
      survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pos);
      v30 = vostok::particle::random_float(0.0, this->m_outer_radius - this->m_inner_radius);
      pos.x = (this->m_outer_radius - v30) * dir2d.x;
      v31 = vostok::particle::random_float(0.0, this->m_outer_radius - this->m_inner_radius);
      pos.z = (this->m_outer_radius - v31) * dir2d.y;
      pos.y = height;
      v32 = vostok::particle::particle_domain_complex::get_transform(this, &v82);
      vostok::math::float4x4::transform_position(&pos, result, v32);
      v3 = result;
      break;
    case 7u:
      max_valuej = vostok::particle::random_float(-1.0, 1.0) * this->m_outer_radius;
      *(float *)&v69 = vostok::particle::random_float(-1.0, 1.0) * this->m_outer_radius;
      v73 = (vostok::math::float2_pod *)vostok::math::float2::float2(v39, (int)v80, v69, max_valuej, v68);
      max_valuek = vostok::math::float2_pod::length(v40, &v73->x);
      v41 = vostok::math::float2_pod::operator/=(v73, max_valuek);
      Wm4::Vector2<float>::operator=(v41, &xz_offset);
      max_valuel = vostok::particle::random_float(0.0, 1.0);
      vostok::math::float3::float3(&v79, LODWORD(xz_offset.x), COERCE_UNSIGNED_INT(-1.0), xz_offset.y);
      other_xa = *v42;
      vostok::math::float3::float3(&v78, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
      vostok::particle::linear_interpolation<vostok::math::float3>(&v106, *v43, other_xa, max_valuel);
      v44 = vostok::particle::particle_domain_complex::get_transform(this, &v77);
      vostok::math::float4x4::transform_position(&v106, result, v44);
      v3 = result;
      break;
    case 9u:
      max_valueg = vostok::particle::random_float(-1.0, 1.0);
      *(float *)&v70 = vostok::particle::random_float(-1.0, 1.0);
      vostok::math::float2::float2(v33, (int)&direction, v70, max_valueg, v68);
      max_valueh = vostok::math::float2_pod::length(v34, &direction.x);
      v74 = vostok::math::float2_pod::operator/=(&direction, max_valueh);
      v35 = v74->y;
      direction.x = v74->x;
      direction.y = v35;
      v36 = vostok::particle::random_float(0.0, this->m_outer_radius - this->m_inner_radius);
      max_valuei = (this->m_outer_radius - v36) * direction.y;
      v37 = vostok::particle::random_float(0.0, this->m_outer_radius - this->m_inner_radius);
      *(float *)&other_yc = (this->m_outer_radius - v37) * direction.x;
      vostok::math::float3::float3(&position, other_yc, COERCE_UNSIGNED_INT(0.0), max_valuei);
      v38 = vostok::particle::particle_domain_complex::get_transform(this, &v81);
      vostok::math::float4x4::transform_position(&position, result, v38);
      v3 = result;
      break;
    case 0xAu:
      max_valuec = vostok::particle::random_float(-0.5 * this->m_box_height, 0.5 * this->m_box_height);
      *(float *)&other_ya = vostok::particle::random_float(-0.5 * this->m_box_width, 0.5 * this->m_box_width);
      vostok::math::float3::float3(&v86, other_ya, COERCE_UNSIGNED_INT(0.0), max_valuec);
      v22 = v21;
      v23 = vostok::particle::particle_domain_complex::get_transform(this, &v87);
      vostok::math::float4x4::transform_position(v22, result, v23);
      v3 = result;
      break;
    default:
      vostok::particle::particle_domain_complex::get_transform(this, &v76);
      survarium::weapon_user_dead_state::finalize(v45);
      *result = *v46;
      v3 = result;
      break;
  }
  return v3;
}
