void __userpurge btRigidBody::integrateVelocities(btRigidBody *this@<ecx>, int a2@<esi>, float step)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm4_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  long double v12; // st7
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // [esp+10h] [ebp-4h]

  if ( (*(_BYTE *)(a2 + 216) & 3) == 0 )
  {
    v3 = *(float *)(a2 + 352) * step;
    v4 = *(float *)(a2 + 436) * v3;
    v5 = *(float *)(a2 + 440) * v3;
    *(float *)(a2 + 320) = *(float *)(a2 + 320) + (float)(*(float *)(a2 + 432) * v3);
    *(float *)(a2 + 324) = *(float *)(a2 + 324) + v4;
    *(float *)(a2 + 328) = *(float *)(a2 + 328) + v5;
    v6 = *(float *)(a2 + 456);
    v7 = *(float *)(a2 + 452);
    v8 = *(float *)(a2 + 448);
    v9 = (float)((float)((float)((float)(*(float *)(a2 + 292) * v7) + (float)(*(float *)(a2 + 296) * v6))
                       + (float)(*(float *)(a2 + 288) * v8))
               * step)
       + *(float *)(a2 + 340);
    v10 = (float)((float)((float)((float)(*(float *)(a2 + 308) * v7) + (float)(*(float *)(a2 + 312) * v6))
                        + (float)(*(float *)(a2 + 304) * v8))
                * step)
        + *(float *)(a2 + 344);
    v11 = *(float *)(a2 + 336)
        + (float)((float)((float)((float)(*(float *)(a2 + 276) * v7) + (float)(*(float *)(a2 + 280) * v6))
                        + (float)(v8 * *(float *)(a2 + 272)))
                * step);
    *(float *)(a2 + 344) = v10;
    *(float *)(a2 + 336) = v11;
    *(float *)(a2 + 340) = v9;
    v12 = sqrtf((float)((float)(v11 * v11) + (float)(v9 * v9)) + (float)(v10 * v10));
    if ( v12 * step > 1.5707964 )
    {
      v16 = v12;
      v13 = (float)(1.5707964 / step) / v16;
      *(float *)(a2 + 336) = *(float *)(a2 + 336) * v13;
      v14 = v13 * *(float *)(a2 + 340);
      v15 = v13 * *(float *)(a2 + 344);
      *(float *)(a2 + 340) = v14;
      *(float *)(a2 + 344) = v15;
    }
  }
}
