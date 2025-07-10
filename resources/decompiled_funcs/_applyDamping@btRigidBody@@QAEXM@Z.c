void __userpurge btRigidBody::applyDamping(btRigidBody *this@<ecx>, int a2@<esi>, float timeStep)
{
  long double v3; // st7
  const vostok::math::float4x4 *v4; // xmm0_4
  long double v5; // st7
  long double v6; // st7
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  long double v11; // st7
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // [esp+10h] [ebp-8h]
  float v16; // [esp+10h] [ebp-8h]
  float v17; // [esp+10h] [ebp-8h]
  float angSpeed; // [esp+14h] [ebp-4h]
  float angSpeeda; // [esp+14h] [ebp-4h]
  float angSpeedb; // [esp+14h] [ebp-4h]

  v3 = powf(*(float *)&clear_value - *(float *)(a2 + 464), timeStep);
  v4 = clear_value;
  *(float *)(a2 + 320) = *(float *)(a2 + 320) * v3;
  *(float *)(a2 + 324) = *(float *)(a2 + 324) * v3;
  *(float *)(a2 + 328) = v3 * *(float *)(a2 + 328);
  v5 = powf(*(float *)&v4 - *(float *)(a2 + 468), timeStep);
  *(float *)(a2 + 336) = *(float *)(a2 + 336) * v5;
  *(float *)(a2 + 340) = *(float *)(a2 + 340) * v5;
  *(float *)(a2 + 344) = v5 * *(float *)(a2 + 344);
  if ( *(_BYTE *)(a2 + 472) )
  {
    if ( *(float *)(a2 + 484) > (float)((float)((float)(*(float *)(a2 + 336) * *(float *)(a2 + 336))
                                              + (float)(*(float *)(a2 + 340) * *(float *)(a2 + 340)))
                                      + (float)(*(float *)(a2 + 344) * *(float *)(a2 + 344)))
      && *(float *)(a2 + 480) > (float)((float)((float)(*(float *)(a2 + 320) * *(float *)(a2 + 320))
                                              + (float)(*(float *)(a2 + 324) * *(float *)(a2 + 324)))
                                      + (float)(*(float *)(a2 + 328) * *(float *)(a2 + 328))) )
    {
      *(float *)(a2 + 336) = *(float *)(a2 + 476) * *(float *)(a2 + 336);
      *(float *)(a2 + 340) = *(float *)(a2 + 476) * *(float *)(a2 + 340);
      *(float *)(a2 + 344) = *(float *)(a2 + 476) * *(float *)(a2 + 344);
      *(float *)(a2 + 320) = *(float *)(a2 + 476) * *(float *)(a2 + 320);
      *(float *)(a2 + 324) = *(float *)(a2 + 324) * *(float *)(a2 + 476);
      *(float *)(a2 + 328) = *(float *)(a2 + 328) * *(float *)(a2 + 476);
    }
    v6 = sqrtf(
           (float)((float)(*(float *)(a2 + 320) * *(float *)(a2 + 320))
                 + (float)(*(float *)(a2 + 324) * *(float *)(a2 + 324)))
         + (float)(*(float *)(a2 + 328) * *(float *)(a2 + 328)));
    v7 = 0.0;
    if ( *(float *)(a2 + 464) > v6 )
    {
      v15 = v6;
      if ( v15 <= 0.0049999999 )
      {
        *(_DWORD *)(a2 + 320) = 0;
        *(_DWORD *)(a2 + 324) = 0;
        *(_DWORD *)(a2 + 332) = 0;
      }
      else
      {
        angSpeed = *(float *)(a2 + 320);
        v16 = 1.0
            / sqrtf(
                (float)((float)(angSpeed * angSpeed) + (float)(*(float *)(a2 + 324) * *(float *)(a2 + 324)))
              + (float)(*(float *)(a2 + 328) * *(float *)(a2 + 328)));
        v8 = (float)(*(float *)(a2 + 328) * v16) * 0.0049999999;
        v9 = *(float *)(a2 + 324) - (float)((float)(*(float *)(a2 + 324) * v16) * 0.0049999999);
        v10 = *(float *)(a2 + 328);
        *(float *)(a2 + 320) = *(float *)(a2 + 320) - (float)((float)(angSpeed * v16) * 0.0049999999);
        *(float *)(a2 + 324) = v9;
        v7 = v10 - v8;
      }
      *(float *)(a2 + 328) = v7;
    }
    v11 = sqrtf(
            (float)((float)(*(float *)(a2 + 336) * *(float *)(a2 + 336))
                  + (float)(*(float *)(a2 + 340) * *(float *)(a2 + 340)))
          + (float)(*(float *)(a2 + 344) * *(float *)(a2 + 344)));
    if ( *(float *)(a2 + 468) > v11 )
    {
      angSpeeda = v11;
      if ( angSpeeda <= 0.0049999999 )
      {
        *(_DWORD *)(a2 + 336) = 0;
        *(_DWORD *)(a2 + 340) = 0;
        *(_QWORD *)(a2 + 344) = 0;
      }
      else
      {
        v17 = *(float *)(a2 + 336);
        angSpeedb = 1.0
                  / sqrtf(
                      (float)((float)(v17 * v17) + (float)(*(float *)(a2 + 340) * *(float *)(a2 + 340)))
                    + (float)(*(float *)(a2 + 344) * *(float *)(a2 + 344)));
        v12 = (float)(angSpeedb * *(float *)(a2 + 344)) * 0.0049999999;
        v13 = *(float *)(a2 + 340) - (float)((float)(angSpeedb * *(float *)(a2 + 340)) * 0.0049999999);
        v14 = *(float *)(a2 + 344);
        *(float *)(a2 + 336) = *(float *)(a2 + 336) - (float)((float)(v17 * angSpeedb) * 0.0049999999);
        *(float *)(a2 + 340) = v13;
        *(float *)(a2 + 344) = v14 - v12;
      }
    }
  }
}
