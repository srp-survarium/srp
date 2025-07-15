void __userpurge btMatrix3x3::setRotation(const btQuaternion *q@<eax>, btMatrix3x3 *this)
{
  float v2; // xmm0_4
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm7_4
  int v14; // [esp+0h] [ebp-24h] BYREF
  float v15; // [esp+4h] [ebp-20h] BYREF
  float v16; // [esp+8h] [ebp-1Ch] BYREF
  float v17; // [esp+Ch] [ebp-18h] BYREF
  float v18; // [esp+10h] [ebp-14h] BYREF
  float v19; // [esp+14h] [ebp-10h] BYREF
  float v20; // [esp+18h] [ebp-Ch] BYREF
  float v21; // [esp+1Ch] [ebp-8h] BYREF
  float v22; // [esp+20h] [ebp-4h] BYREF

  v2 = q->m_floats[0];
  v3 = q->m_floats[1];
  v4 = q->m_floats[2];
  v5 = q->m_floats[3];
  v6 = 2.0 / (float)((float)((float)((float)(v2 * v2) + (float)(v3 * v3)) + (float)(v4 * v4)) + (float)(v5 * v5));
  v7 = v3 * v6;
  v8 = q->m_floats[0] * v6;
  v9 = v4 * v6;
  v22 = v5 * v8;
  v10 = v4 * (float)(v4 * v6);
  v21 = v2 * v8;
  v11 = v3;
  v12 = v3 * v9;
  v13 = v11 * v7;
  v17 = v12 + v22;
  v22 = v12 - v22;
  v16 = (float)(v2 * v9) - (float)(v5 * v7);
  v18 = s_bm_current_air_resistance - (float)(v13 + v21);
  v21 = s_bm_current_air_resistance - (float)(v10 + v21);
  v15 = (float)(v2 * v7) + (float)(v5 * v9);
  v20 = (float)(v2 * v9) + (float)(v5 * v7);
  v19 = (float)(v2 * v7) - (float)(v5 * v9);
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v14,
    (int)this,
    &v19,
    &v20,
    &v15,
    &v21,
    &v22,
    &v16,
    &v17,
    &v18,
    COERCE_CONST_FLOAT_(s_bm_current_air_resistance - (float)(v10 + v13)));
}
