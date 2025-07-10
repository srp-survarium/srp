void __userpurge btMatrix3x3::getRotation(btMatrix3x3 *this@<ecx>, float *a2@<esi>, btQuaternion *q)
{
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4
  long double v7; // st7
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  int v13; // edi
  int v14; // ebx
  int v15; // ebp
  long double v16; // st7
  float v17; // xmm1_4
  float v18; // xmm0_4
  float s; // [esp+10h] [ebp-14h]
  float sa; // [esp+10h] [ebp-14h]
  float temp[4]; // [esp+14h] [ebp-10h]

  v3 = *a2;
  v4 = a2[5];
  v5 = a2[10];
  v6 = (float)(*a2 + v4) + v5;
  if ( v6 <= 0.0 )
  {
    if ( v4 <= v3 )
    {
      if ( v5 <= v3 )
      {
        v13 = 0;
        goto LABEL_9;
      }
    }
    else if ( v5 <= v4 )
    {
      v13 = 1;
LABEL_9:
      v14 = (v13 + 1) % 3;
      v15 = (v13 + 2) % 3;
      v16 = sqrtf((float)((float)(a2[5 * v13] - a2[5 * v14]) - a2[5 * v15]) + *(float *)&clear_value);
      sa = v16;
      v17 = a2[4 * v15 + v14];
      temp[v13] = v16 * 0.5;
      temp[3] = (float)(v17 - a2[4 * v14 + v15]) * (float)(0.5 / sa);
      temp[v14] = (float)(a2[4 * v14 + v13] + a2[4 * v13 + v14]) * (float)(0.5 / sa);
      temp[v15] = (float)(a2[4 * v15 + v13] + a2[4 * v13 + v15]) * (float)(0.5 / sa);
      v12 = temp[2];
      v11 = temp[1];
      v10 = temp[0];
      goto LABEL_10;
    }
    v13 = 2;
    goto LABEL_9;
  }
  v7 = sqrtf(v6 + *(float *)&clear_value);
  s = v7;
  v8 = a2[9];
  v9 = a2[2];
  temp[3] = v7 * 0.5;
  v10 = (float)(v8 - a2[6]) * (float)(0.5 / s);
  v11 = (float)(v9 - a2[8]) * (float)(0.5 / s);
  v12 = (float)(a2[4] - a2[1]) * (float)(0.5 / s);
LABEL_10:
  v18 = temp[3];
  q->m_floats[0] = v10;
  q->m_floats[1] = v11;
  q->m_floats[2] = v12;
  q->m_floats[3] = v18;
}
