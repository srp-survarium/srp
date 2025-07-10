void __thiscall vostok::render::light::xform_calc(vostok::render::light *this, vostok::render::light *thisa)
{
  float z; // eax
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  long double v10; // st7
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm4_4
  unsigned int v14; // xmm2_4
  unsigned int v15; // xmm3_4
  long double v16; // st7
  float v17; // edx
  float v18; // eax
  __int64 v19; // xmm0_8
  int v20; // eax
  __int64 v21; // xmm1_8
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // ecx
  __int64 v27; // xmm2_8
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  const vostok::math::float4x4 *v31; // eax
  float range; // [esp+14h] [ebp-F8h]
  float rangea; // [esp+14h] [ebp-F8h]
  float rangeb; // [esp+14h] [ebp-F8h]
  float rangec; // [esp+14h] [ebp-F8h]
  float ranged; // [esp+14h] [ebp-F8h]
  float rangee; // [esp+14h] [ebp-F8h]
  float rangef; // [esp+14h] [ebp-F8h]
  float rangeg; // [esp+14h] [ebp-F8h]
  vostok::math::float3 position; // [esp+18h] [ebp-F4h] BYREF
  vostok::math::float3 L_right; // [esp+24h] [ebp-E8h]
  vostok::math::float3 L_up; // [esp+30h] [ebp-DCh]
  float range_X_tan_penumbra_angle_div_2; // [esp+3Ch] [ebp-D0h]
  vostok::math::float3 L_dir; // [esp+40h] [ebp-CCh]
  vostok::math::float4x4 dst; // [esp+4Ch] [ebp-C0h] BYREF
  vostok::math::float4x4 rotation; // [esp+8Ch] [ebp-80h] BYREF
  vostok::math::float4x4 result; // [esp+CCh] [ebp-40h] BYREF

  z = thisa->direction.z;
  v3 = thisa->right.z;
  v4 = thisa->right.x * thisa->right.x;
  *(_QWORD *)&L_dir.x = *(_QWORD *)&thisa->direction.x;
  v5 = (float)((float)(v3 * v3) + v4) + (float)(thisa->right.y * thisa->right.y);
  L_dir.z = z;
  if ( v5 <= 0.0000099999997 )
  {
    v11 = *(float *)&clear_value;
    v12 = 0.0;
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(L_dir.x * 0.0) + L_dir.y) + (float)(L_dir.z * 0.0)) & _mask__AbsFloat_) > 0.99000001 )
    {
      v12 = *(float *)&clear_value;
      v11 = 0.0;
    }
    L_right.y = (float)(v12 * L_dir.x) - (float)(L_dir.z * 0.0);
    L_right.z = (float)(L_dir.y * 0.0) - (float)(v11 * L_dir.x);
    rangec = 1.0
           / sqrtf(
               (float)((float)((float)((float)(v11 * L_dir.z) - (float)(v12 * L_dir.y))
                             * (float)((float)(v11 * L_dir.z) - (float)(v12 * L_dir.y)))
                     + (float)(L_right.z * L_right.z))
             + (float)(L_right.y * L_right.y));
    v13 = rangec * (float)((float)(v11 * L_dir.z) - (float)(v12 * L_dir.y));
    L_right.z = L_right.z * rangec;
    *(float *)&v14 = (float)(L_dir.y * L_right.z) - (float)(L_dir.z * (float)(L_right.y * rangec));
    L_right.y = L_right.y * rangec;
    *(float *)&v15 = (float)(L_dir.z * v13) - (float)(L_right.z * L_dir.x);
    *(_QWORD *)&position.x = __PAIR64__(v15, v14);
    position.z = (float)(L_right.y * L_dir.x) - (float)(L_dir.y * v13);
    L_right.x = v13;
    v16 = 1.0
        / sqrtf(
            (float)((float)(position.z * position.z) + (float)(*(float *)&v15 * *(float *)&v15))
          + (float)(*(float *)&v14 * *(float *)&v14));
    ranged = v16;
    L_up.x = ranged * *(float *)&v14;
    L_up.y = *(float *)&v15 * v16;
    L_up.z = v16 * position.z;
  }
  else
  {
    v6 = thisa->right.z;
    *(_QWORD *)&L_right.x = *(_QWORD *)&thisa->right.x;
    L_right.z = v6;
    range = 1.0 / sqrtf((float)((float)(L_right.x * L_right.x) + (float)(v6 * v6)) + (float)(L_right.y * L_right.y));
    v7 = (float)(L_dir.y * (float)(L_right.z * range)) - (float)(L_dir.z * (float)(L_right.y * range));
    v8 = (float)(L_dir.z * (float)(range * L_right.x)) - (float)((float)(L_right.z * range) * L_dir.x);
    v9 = (float)((float)(L_right.y * range) * L_dir.x) - (float)(L_dir.y * (float)(range * L_right.x));
    rangea = 1.0 / sqrtf((float)((float)(v7 * v7) + (float)(v9 * v9)) + (float)(v8 * v8));
    L_up.x = rangea * v7;
    L_up.y = v8 * rangea;
    L_up.z = v9 * rangea;
    position.x = (float)((float)(v8 * rangea) * L_dir.z) - (float)((float)(v9 * rangea) * L_dir.y);
    position.y = (float)((float)(v9 * rangea) * L_dir.x) - (float)(L_dir.z * (float)(rangea * v7));
    position.z = (float)(L_dir.y * (float)(rangea * v7)) - (float)((float)(v8 * rangea) * L_dir.x);
    v10 = 1.0
        / sqrtf(
            (float)((float)(position.x * position.x) + (float)(position.z * position.z))
          + (float)(position.y * position.y));
    rangeb = v10;
    L_right.x = rangeb * position.x;
    L_right.y = position.y * v10;
    L_right.z = v10 * position.z;
  }
  v17 = thisa->direction.z;
  *(_QWORD *)&rotation.lines[0].elements[2] = LODWORD(L_right.z);
  v18 = thisa->position.z;
  *(_QWORD *)&rotation.i.x = *(_QWORD *)&L_right.x;
  *(_QWORD *)&rotation.lines[3].elements[2] = __PAIR64__((unsigned int)clear_value, LODWORD(v18));
  v19 = *(_QWORD *)&thisa->position.x;
  v20 = *(_DWORD *)&thisa->flags & 0xF;
  *(_QWORD *)&rotation.lines[1].x = *(_QWORD *)&L_up.x;
  v21 = *(_QWORD *)&thisa->direction.x;
  *(_QWORD *)&rotation.lines[3].x = v19;
  *(_QWORD *)&rotation.lines[1].elements[2] = LODWORD(L_up.z);
  *(_QWORD *)&rotation.lines[2].x = v21;
  *(_QWORD *)&rotation.lines[2].elements[2] = LODWORD(v17);
  switch ( v20 )
  {
    case 0:
      rangee = thisa->range * 1.05;
      memset((int)&dst, 0, sizeof(dst));
      v22 = rangee;
      dst.i.x = rangee;
      dst.j.y = rangee;
      goto LABEL_8;
    case 1:
      rangef = thisa->range;
      range_X_tan_penumbra_angle_div_2 = tanf(thisa->spot_penumbra_angle * 0.5) * rangef;
      memset((int)&dst, 0, sizeof(dst));
      v22 = rangef;
      dst.i.x = range_X_tan_penumbra_angle_div_2;
      dst.j.y = range_X_tan_penumbra_angle_div_2;
      goto LABEL_8;
    case 2:
      v23 = thisa->range;
      position.x = v23 + thisa->scale.x;
      position.y = thisa->scale.y + v23;
      position.z = thisa->scale.z + v23;
      memset((int)&dst, 0, sizeof(dst));
      dst.j.y = position.y;
      dst.i.x = position.x;
      v22 = position.z;
      goto LABEL_8;
    case 3:
      v24 = thisa->scale.z;
      v25 = thisa->range;
      position.y = v25 + thisa->scale.x;
      memset((int)&dst, 0, sizeof(dst));
      dst.j.y = position.y;
      dst.i.x = position.y;
      v22 = v25 + v24;
      goto LABEL_8;
    case 5:
      range_X_tan_penumbra_angle_div_2 = (float)(thisa->range + thisa->scale.x) * 1.05;
      memset((int)&dst, 0, sizeof(dst));
      v22 = range_X_tan_penumbra_angle_div_2;
      dst.i.x = range_X_tan_penumbra_angle_div_2;
      dst.j.y = range_X_tan_penumbra_angle_div_2;
LABEL_8:
      dst.k.z = v22;
      LODWORD(dst.c.w) = clear_value;
      vostok::math::mul4x3(&result, &dst, &rotation);
      qmemcpy((void *)&thisa->m_xform, &result, sizeof(thisa->m_xform));
      break;
    case 6:
      rangeg = thisa->range;
      range_X_tan_penumbra_angle_div_2 = tanf(thisa->spot_penumbra_angle * 0.5) * rangeg;
      memset((int)&dst, 0, sizeof(dst));
      dst.i.x = thisa->scale.x;
      dst.j.y = thisa->scale.y;
      dst.k.z = thisa->scale.z;
      LODWORD(dst.c.w) = clear_value;
      vostok::math::mul4x3(&result, &dst, &rotation);
      position.x = thisa->scale.x + range_X_tan_penumbra_angle_div_2;
      qmemcpy((void *)&thisa->m_plane_spot_xform, &result, sizeof(thisa->m_plane_spot_xform));
      position.y = rangeg * 0.5;
      position.z = thisa->scale.z + range_X_tan_penumbra_angle_div_2;
      memset((int)&dst, 0, sizeof(dst));
      v26 = thisa->direction.z;
      dst.j.y = rangeg * 0.5;
      dst.i.x = position.x;
      dst.k.z = position.z;
      *(_QWORD *)&rotation.i.x = *(_QWORD *)&L_right.x;
      *(_QWORD *)&rotation.lines[1].x = *(_QWORD *)&L_up.x;
      v27 = *(_QWORD *)&thisa->direction.x;
      memset(&rotation.lines[3], 0, 12);
      v28 = thisa->range;
      LODWORD(dst.c.w) = clear_value;
      *(_QWORD *)&rotation.lines[0].elements[2] = LODWORD(L_right.z);
      *(_QWORD *)&rotation.lines[1].elements[2] = LODWORD(L_up.z);
      *(_QWORD *)&rotation.lines[2].x = v27;
      *(_QWORD *)&rotation.lines[2].elements[2] = LODWORD(v26);
      LODWORD(rotation.c.w) = clear_value;
      v29 = thisa->position.x - (float)((float)(v28 * L_up.x) * 0.5);
      position.y = thisa->position.y - (float)((float)(v28 * L_up.y) * 0.5);
      v30 = thisa->position.z - (float)((float)(v28 * L_up.z) * 0.5);
      position.x = v29;
      position.z = v30;
      vostok::math::mul4x3(&result, &dst, &rotation);
      v31 = vostok::math::create_translation(&rotation, &position);
      vostok::math::mul4x3(&dst, &result, v31);
      qmemcpy((void *)&thisa->m_xform, &dst, sizeof(thisa->m_xform));
      break;
    default:
      vostok::math::float4x4::identity(&thisa->m_xform);
      break;
  }
}
