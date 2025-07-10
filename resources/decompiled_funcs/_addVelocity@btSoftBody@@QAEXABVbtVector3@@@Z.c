void __thiscall btSoftBody::addVelocity(btSoftBody *this, const btVector3 *velocity)
{
  int v3; // ebp
  int v4; // eax
  int v5; // edx
  unsigned int v6; // edi
  int v7; // eax
  float v8; // xmm1_4
  float *v9; // eax
  int v10; // eax
  float v11; // xmm1_4
  float *v12; // eax
  int v13; // eax
  int v14; // esi
  float v15; // xmm1_4
  float *v16; // eax
  int v17; // eax
  float v18; // xmm1_4
  float *v19; // eax
  int v20; // edx
  int v21; // esi
  int v22; // eax
  float v23; // xmm1_4
  float *v24; // eax
  int i; // [esp+4h] [ebp+4h]

  v3 = velocity[45].mVec128.m128_i32[0];
  v4 = 0;
  if ( v3 >= 4 )
  {
    v5 = 0;
    v6 = ((unsigned int)(v3 - 4) >> 2) + 1;
    i = 4 * v6;
    do
    {
      v7 = velocity[45].mVec128.m128_i32[2];
      v8 = *(float *)(v7 + v5 + 96);
      v9 = (float *)(v5 + v7);
      if ( v8 > 0.0 )
      {
        v9[12] = v9[12] + *(float *)&this->__vftable;
        v9[13] = *((float *)&this->__vftable + 1) + v9[13];
        v9[14] = *((float *)&this->__vftable + 2) + v9[14];
      }
      v10 = velocity[45].mVec128.m128_i32[2];
      v11 = *(float *)(v5 + v10 + 208);
      v12 = (float *)(v5 + v10 + 112);
      if ( v11 > 0.0 )
      {
        v12[12] = v12[12] + *(float *)&this->__vftable;
        v12[13] = *((float *)&this->__vftable + 1) + v12[13];
        v12[14] = *((float *)&this->__vftable + 2) + v12[14];
      }
      v13 = velocity[45].mVec128.m128_i32[2];
      v14 = v5 + 336;
      v15 = *(float *)(v5 + 336 + v13 - 16);
      v16 = (float *)(v5 + 336 + v13 - 112);
      if ( v15 > 0.0 )
      {
        v16[12] = v16[12] + *(float *)&this->__vftable;
        v16[13] = *((float *)&this->__vftable + 1) + v16[13];
        v16[14] = *((float *)&this->__vftable + 2) + v16[14];
      }
      v17 = velocity[45].mVec128.m128_i32[2];
      v18 = *(float *)(v17 + v14 + 96);
      v19 = (float *)(v14 + v17);
      if ( v18 > 0.0 )
      {
        v19[12] = v19[12] + *(float *)&this->__vftable;
        v19[13] = *((float *)&this->__vftable + 1) + v19[13];
        v19[14] = *((float *)&this->__vftable + 2) + v19[14];
      }
      v5 += 448;
      --v6;
    }
    while ( v6 );
    v4 = i;
  }
  if ( v4 < v3 )
  {
    v20 = 112 * v4;
    v21 = v3 - v4;
    do
    {
      v22 = velocity[45].mVec128.m128_i32[2];
      v23 = *(float *)(v22 + v20 + 96);
      v24 = (float *)(v20 + v22);
      if ( v23 > 0.0 )
      {
        v24[12] = v24[12] + *(float *)&this->__vftable;
        v24[13] = *((float *)&this->__vftable + 1) + v24[13];
        v24[14] = *((float *)&this->__vftable + 2) + v24[14];
      }
      v20 += 112;
      --v21;
    }
    while ( v21 );
  }
}
