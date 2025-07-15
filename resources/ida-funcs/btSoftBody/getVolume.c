void __usercall btSoftBody::getVolume(btSoftBody *this@<ecx>, int *a2@<eax>)
{
  int v2; // edx
  _DWORD *v3; // ecx
  float *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // [esp+4h] [ebp-14h]
  float v9; // [esp+8h] [ebp-10h]
  float v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+10h] [ebp-8h]

  v8 = 0.0;
  if ( a2[180] > 0 )
  {
    v2 = a2[190];
    v9 = *(float *)(a2[182] + 16);
    v10 = *(float *)(a2[182] + 20);
    v11 = *(float *)(a2[182] + 24);
    if ( v2 > 0 )
    {
      v3 = (_DWORD *)(a2[192] + 12);
      do
      {
        v4 = (float *)v3[1];
        v5 = v4[5] - v10;
        v6 = v4[6] - v11;
        v7 = (float)((float)((float)((float)(*(float *)(*(v3 - 1) + 24) - v11)
                                   * (float)((float)(v5 * (float)(*(float *)(*v3 + 16) - v9))
                                           - (float)((float)(*(float *)(*v3 + 20) - v10) * (float)(v4[4] - v9))))
                           + (float)((float)(*(float *)(*(v3 - 1) + 20) - v10)
                                   * (float)((float)((float)(*(float *)(*v3 + 24) - v11) * (float)(v4[4] - v9))
                                           - (float)(v6 * (float)(*(float *)(*v3 + 16) - v9)))))
                   + (float)((float)(*(float *)(*(v3 - 1) + 16) - v9)
                           * (float)((float)(v6 * (float)(*(float *)(*v3 + 20) - v10))
                                   - (float)((float)(*(float *)(*v3 + 24) - v11) * v5))))
           + v8;
        v3 += 16;
        --v2;
        v8 = v7;
      }
      while ( v2 );
    }
  }
}
