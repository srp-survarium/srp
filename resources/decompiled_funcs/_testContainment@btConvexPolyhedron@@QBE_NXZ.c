char __usercall btConvexPolyhedron::testContainment@<al>(btConvexPolyhedron *this@<ecx>, int a2@<eax>)
{
  int v2; // edi
  int v3; // esi
  float v4; // xmm4_4
  float v5; // xmm5_4
  unsigned int v6; // xmm2_4
  __m128i v7; // xmm2
  float v8; // xmm2_4
  float v9; // xmm5_4
  unsigned int v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm4_4
  int v13; // xmm4_4
  unsigned int v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm5_4
  unsigned int v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  unsigned int v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  unsigned int v25; // xmm2_4
  int v26; // edx
  float *v27; // ecx
  btVector3 LocalPt; // [esp+0h] [ebp-90h]
  __m128i v30; // [esp+10h] [ebp-80h] BYREF
  __m128i v31; // [esp+20h] [ebp-70h] BYREF
  __m128i v32; // [esp+30h] [ebp-60h] BYREF
  __m128i v33; // [esp+40h] [ebp-50h] BYREF
  __m128i v34; // [esp+50h] [ebp-40h] BYREF
  __m128i v35; // [esp+60h] [ebp-30h] BYREF
  __m128i v36; // [esp+70h] [ebp-20h] BYREF
  __m128i v37; // [esp+80h] [ebp-10h] BYREF

  v2 = *(_DWORD *)(a2 + 40);
  v3 = 0;
  while ( 1 )
  {
    if ( v3 )
    {
      switch ( v3 )
      {
        case 1:
          v8 = *(float *)(a2 + 104);
          v9 = *(float *)(a2 + 80) + *(float *)(a2 + 96);
          *(float *)&v32.m128i_i32[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
          *(float *)&v10 = *(float *)(a2 + 88) - v8;
          *(float *)v32.m128i_i32 = v9;
          v32.m128i_i64[1] = v10;
          v7 = _mm_load_si128(&v32);
          break;
        case 2:
          v11 = *(float *)(a2 + 100);
          v12 = *(float *)(a2 + 104);
          *(float *)v36.m128i_i32 = *(float *)(a2 + 96) + *(float *)(a2 + 80);
          *(float *)&v36.m128i_i32[1] = *(float *)(a2 + 84) - v11;
          *(float *)&v36.m128i_i32[2] = *(float *)(a2 + 88) + v12;
          v36.m128i_i32[3] = 0;
          v7 = _mm_load_si128(&v36);
          break;
        case 3:
          *(float *)&v13 = *(float *)(a2 + 84) - *(float *)(a2 + 100);
          *(float *)&v14 = *(float *)(a2 + 88) - *(float *)(a2 + 104);
          *(float *)v30.m128i_i32 = *(float *)(a2 + 80) + *(float *)(a2 + 96);
          v30.m128i_i32[1] = v13;
          v30.m128i_i64[1] = v14;
          v7 = _mm_load_si128(&v30);
          break;
        case 4:
          v15 = *(float *)(a2 + 104);
          v16 = *(float *)(a2 + 80) - *(float *)(a2 + 96);
          *(float *)&v31.m128i_i32[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
          *(float *)&v17 = *(float *)(a2 + 88) + v15;
          *(float *)v31.m128i_i32 = v16;
          v31.m128i_i64[1] = v17;
          v7 = _mm_load_si128(&v31);
          break;
        case 5:
          v18 = *(float *)(a2 + 104);
          v19 = *(float *)(a2 + 80) - *(float *)(a2 + 96);
          *(float *)&v33.m128i_i32[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
          *(float *)&v20 = *(float *)(a2 + 88) - v18;
          *(float *)v33.m128i_i32 = v19;
          v33.m128i_i64[1] = v20;
          v7 = _mm_load_si128(&v33);
          break;
        case 6:
          v21 = *(float *)(a2 + 100);
          v22 = *(float *)(a2 + 104);
          *(float *)v35.m128i_i32 = *(float *)(a2 + 80) - *(float *)(a2 + 96);
          *(float *)&v35.m128i_i32[1] = *(float *)(a2 + 84) - v21;
          *(float *)&v35.m128i_i32[2] = *(float *)(a2 + 88) + v22;
          v35.m128i_i32[3] = 0;
          v7 = _mm_load_si128(&v35);
          break;
        case 7:
          v23 = *(float *)(a2 + 104);
          v24 = *(float *)(a2 + 80) - *(float *)(a2 + 96);
          *(float *)&v37.m128i_i32[1] = *(float *)(a2 + 84) - *(float *)(a2 + 100);
          *(float *)&v25 = *(float *)(a2 + 88) - v23;
          *(float *)v37.m128i_i32 = v24;
          v37.m128i_i64[1] = v25;
          v7 = _mm_load_si128(&v37);
          break;
        default:
          goto LABEL_19;
      }
    }
    else
    {
      v4 = *(float *)(a2 + 104);
      v5 = *(float *)(a2 + 80) + *(float *)(a2 + 96);
      *(float *)&v34.m128i_i32[1] = *(float *)(a2 + 84) + *(float *)(a2 + 100);
      *(float *)&v6 = *(float *)(a2 + 88) + v4;
      *(float *)v34.m128i_i32 = v5;
      v34.m128i_i64[1] = v6;
      v7 = _mm_load_si128(&v34);
    }
    LocalPt.mVec128 = (__m128)v7;
LABEL_19:
    v26 = 0;
    if ( v2 > 0 )
      break;
LABEL_23:
    if ( ++v3 >= 8 )
      return 1;
  }
  v27 = (float *)(*(_DWORD *)(a2 + 48) + 24);
  while ( (float)((float)((float)((float)(LocalPt.mVec128.m128_f32[2] * v27[1])
                                + (float)(LocalPt.mVec128.m128_f32[1] * *v27))
                        + (float)(LocalPt.mVec128.m128_f32[0] * *(v27 - 1)))
                + v27[2]) <= 0.0 )
  {
    ++v26;
    v27 += 9;
    if ( v26 >= v2 )
      goto LABEL_23;
  }
  return 0;
}
