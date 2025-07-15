int __usercall vostok::render::calculate_streaming_texture_factor@<xmm0>(
        const unsigned int num_indices@<eax>,
        const vostok::math::float3 *positions,
        const vostok::math::float2 *uvs,
        const unsigned int __formal,
        const unsigned int vertex_stride)
{
  float *v5; // ecx
  void *v6; // esp
  int result; // xmm0_4
  float *v8; // edi
  float v9; // xmm4_4
  unsigned __int16 *v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ecx
  float *v13; // ebx
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float *v17; // eax
  float v18; // xmm5_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm5_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  int v26; // ebx
  _DWORD v27[3]; // [esp+0h] [ebp-2Ch] BYREF
  float *__first; // [esp+Ch] [ebp-20h] BYREF
  float *__last; // [esp+10h] [ebp-1Ch]
  _DWORD *v30; // [esp+14h] [ebp-18h]
  int v31; // [esp+18h] [ebp-14h]
  float v32; // [esp+1Ch] [ebp-10h]
  float v33; // [esp+20h] [ebp-Ch]
  unsigned int v34; // [esp+24h] [ebp-8h]
  float v35; // [esp+28h] [ebp-4h] BYREF

  LOBYTE(v5) = 3;
  v6 = alloca(4 * (num_indices / 3));
  result = 0;
  v8 = (float *)v27;
  __first = (float *)v27;
  __last = (float *)v27;
  v30 = &v27[num_indices / 3];
  v31 = 0;
  if ( num_indices / 3 )
  {
    v9 = epsilon_5_392;
    v10 = (unsigned __int16 *)(vertex_stride + 2);
    v34 = num_indices / 3;
    do
    {
      v11 = __formal * *(v10 - 1);
      v12 = __formal * *v10;
      v13 = (float *)((char *)&uvs->x + v11);
      v14 = *(float *)((char *)&positions->y + v11) - *(float *)((char *)&positions->y + v12);
      v15 = *(float *)((char *)&positions->z + v11) - *(float *)((char *)&positions->z + v12);
      v16 = *(float *)((char *)&positions->x + v11) - *(float *)((char *)&positions->x + v12);
      v5 = (float *)((char *)&uvs->x + v12);
      v17 = (float *)((char *)&uvs->x + __formal * v10[1]);
      v18 = (float)(v15 * v15) + (float)(v14 * v14);
      v19 = *v13;
      v20 = fsqrt(v18 + (float)(v16 * v16));
      v21 = v13[1];
      v22 = fsqrt((float)((float)(v21 - v5[1]) * (float)(v21 - v5[1])) + (float)((float)(*v13 - *v5)
                                                                               * (float)(*v13 - *v5)));
      v33 = *(float *)&v5;
      if ( v22 <= v9 )
        v22 = v9;
      v23 = fsqrt(
              (float)((float)(v21 - v17[1]) * (float)(v21 - v17[1]))
            + (float)((float)(v19 - *v17) * (float)(v19 - *v17)));
      if ( v23 <= v9 )
        v23 = v9;
      v32 = v23 * v22;
      v33 = fabs(v23 * v22);
      if ( v33 > v9 )
      {
        v24 = v20 / v22;
        v25 = v20 / v23;
        if ( v24 <= v25 )
          v35 = v25;
        else
          v35 = v24;
        vostok::buffer_vector<float>::push_back((vostok::buffer_vector<float> *)v5, (int)&__first, &v35);
        v9 = epsilon_5_392;
        result = v31;
      }
      v10 += 3;
      --v34;
    }
    while ( v34 );
    v8 = __first;
  }
  v26 = __last - v8;
  if ( v26 )
  {
    stlp_std::sort<float *>(v8, __last, (stlp_std::less<float>)v5);
    v31 = v26;
    return LODWORD(v8[-(unsigned __int64)((double)(unsigned int)v26 * -0.5)]);
  }
  return result;
}
