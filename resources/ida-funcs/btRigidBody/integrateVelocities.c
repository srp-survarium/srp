int __usercall btRigidBody::integrateVelocities@<eax>(btRigidBody *this@<ecx>, int result@<eax>, float a3@<xmm6>)
{
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm3_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm0_4

  if ( (*(_BYTE *)(result + 216) & 3) == 0 )
  {
    v3 = *(float *)(result + 352) * a3;
    v4 = *(float *)(result + 436) * v3;
    v5 = *(float *)(result + 440) * v3;
    *(float *)(result + 320) = *(float *)(result + 320) + (float)(*(float *)(result + 432) * v3);
    *(float *)(result + 324) = *(float *)(result + 324) + v4;
    *(float *)(result + 328) = *(float *)(result + 328) + v5;
    v6 = *(float *)(result + 456);
    v7 = *(float *)(result + 452);
    v8 = *(float *)(result + 448);
    v9 = (float)((float)(*(float *)(result + 276) * v7) + (float)(*(float *)(result + 280) * v6))
       + (float)(v8 * *(float *)(result + 272));
    v10 = (float)((float)(*(float *)(result + 292) * v7) + (float)(*(float *)(result + 296) * v6))
        + (float)(*(float *)(result + 288) * v8);
    v11 = (float)((float)(*(float *)(result + 308) * v7) + (float)(*(float *)(result + 312) * v6))
        + (float)(*(float *)(result + 304) * v8);
    v12 = *(float *)(result + 336);
    *(float *)(result + 340) = (float)(v10 * a3) + *(float *)(result + 340);
    *(float *)(result + 344) = (float)(v11 * a3) + *(float *)(result + 344);
    v13 = v12 + (float)(v9 * a3);
    *(float *)(result + 336) = v13;
    v14 = fsqrt(
            (float)((float)(v13 * v13) + (float)(*(float *)(result + 340) * *(float *)(result + 340)))
          + (float)(*(float *)(result + 344) * *(float *)(result + 344)));
    if ( (float)(v14 * a3) > 1.5707964 )
    {
      v15 = (float)(1.5707964 / a3) / v14;
      *(float *)(result + 336) = v15 * *(float *)(result + 336);
      v16 = (float *)(result + 340);
      result += 344;
      v17 = v15 * *v16;
      v18 = v15 * *(float *)result;
      *v16 = v17;
      *(float *)result = v18;
    }
  }
  return result;
}
