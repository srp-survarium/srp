void __userpurge Wm4::Mapper2<float>::Mapper2<float>(
        Wm4::Mapper2<float> *this@<ecx>,
        int a2@<esi>,
        int iVQuantity,
        const Wm4::Vector2<float> *akVertex,
        float fEpsilon)
{
  double v6; // st7
  int v7; // edx
  float *v8; // eax
  float v9; // xmm0_4
  char *v10; // edi
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // eax
  int v14; // eax
  const Wm4::Vector2<float> *v15; // eax
  int v16; // eax
  const Wm4::Vector2<float> *v17; // eax
  float v18; // xmm1_4
  int v19; // xmm2_4
  int v20; // eax
  float v21; // xmm4_4
  float i; // xmm5_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  int v26; // eax
  int v27; // [esp+8h] [ebp-1Ch] BYREF
  int v28; // [esp+Ch] [ebp-18h]
  int v29; // [esp+10h] [ebp-14h] BYREF
  int v30; // [esp+14h] [ebp-10h]
  char *v31; // [esp+18h] [ebp-Ch]
  char *v32; // [esp+1Ch] [ebp-8h]
  int v33; // [esp+30h] [ebp+Ch]

  *(_BYTE *)(a2 + 36) = 0;
  *(float *)a2 = akVertex->m_afTuple[0];
  v6 = akVertex->m_afTuple[1];
  v27 = 0;
  v28 = 0;
  *(float *)(a2 + 4) = v6;
  *(float *)(a2 + 8) = *(float *)a2;
  *(float *)(a2 + 12) = *(float *)(a2 + 4);
  v29 = 0;
  v7 = 1;
  v30 = 0;
  if ( iVQuantity > 1 )
  {
    v32 = (char *)&v29 - a2;
    v31 = (char *)&v27 - a2;
    this = (Wm4::Mapper2<float> *)&CONTAINING_RECORD(akVertex, Wm4::Mapper2<float>, m_kMin)->m_kMax;
    do
    {
      v8 = (float *)a2;
      v33 = 2;
      do
      {
        v9 = this->m_kMin.m_afTuple[0];
        if ( *v8 <= this->m_kMin.m_afTuple[0] )
        {
          if ( v9 <= v8[2] )
            goto LABEL_9;
          v10 = v31;
          v8[2] = v9;
        }
        else
        {
          v10 = v32;
          *v8 = v9;
        }
        *(_DWORD *)((char *)v8 + (_DWORD)v10) = v7;
LABEL_9:
        ++v8;
        this = (Wm4::Mapper2<float> *)((char *)this + 4);
        --v33;
      }
      while ( v33 );
      ++v7;
    }
    while ( v7 < iVQuantity );
  }
  v11 = *(float *)(a2 + 8) - *(float *)a2;
  v12 = *(float *)(a2 + 12) - *(float *)(a2 + 4);
  *(_DWORD *)(a2 + 24) = v29;
  v13 = v27;
  *(float *)(a2 + 16) = v11;
  *(_DWORD *)(a2 + 28) = v13;
  if ( v12 > v11 )
  {
    *(_DWORD *)(a2 + 24) = v30;
    v14 = v28;
    *(float *)(a2 + 16) = v12;
    *(_DWORD *)(a2 + 28) = v14;
  }
  v15 = &akVertex[*(_DWORD *)(a2 + 24)];
  *(float *)(a2 + 40) = v15->m_afTuple[0];
  *(float *)(a2 + 44) = v15->m_afTuple[1];
  if ( fEpsilon <= *(float *)(a2 + 16) )
  {
    v17 = &akVertex[*(_DWORD *)(a2 + 28)];
    v18 = v17->m_afTuple[1] - *(float *)(a2 + 44);
    *(float *)(a2 + 48) = v17->m_afTuple[0] - *(float *)(a2 + 40);
    *(float *)(a2 + 52) = v18;
    Wm4::Vector2<float>::Normalize(&this->m_kMin, (float *)(a2 + 48));
    v19 = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(a2 + 60) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(a2 + 56) = v19 ^ _mask__NegFloat_;
    *(_DWORD *)(a2 + 32) = *(_DWORD *)(a2 + 24);
    v20 = 0;
    v21 = 0.0;
    for ( i = 0.0; v20 < iVQuantity; ++v20 )
    {
      v23 = (float)(*(float *)(a2 + 56) * (float)(akVertex[v20].m_afTuple[0] - *(float *)(a2 + 40)))
          + (float)((float)(akVertex[v20].m_afTuple[1] - *(float *)(a2 + 44)) * *(float *)(a2 + 60));
      if ( v23 <= 0.0 )
      {
        if ( v23 >= 0.0 )
          v24 = 0.0;
        else
          v24 = FLOAT_N1_0;
      }
      else
      {
        v24 = s_bm_current_air_resistance;
      }
      LODWORD(v25) = LODWORD(v23) & _mask__AbsFloat_;
      if ( v25 > v21 )
      {
        v21 = v25;
        i = v24;
        *(_DWORD *)(a2 + 32) = v20;
      }
    }
    if ( (float)(fEpsilon * *(float *)(a2 + 16)) <= v21 )
    {
      *(_DWORD *)(a2 + 20) = 2;
      *(_BYTE *)(a2 + 36) = i > 0.0;
    }
    else
    {
      v26 = *(_DWORD *)(a2 + 28);
      *(_DWORD *)(a2 + 20) = 1;
      *(_DWORD *)(a2 + 32) = v26;
    }
  }
  else
  {
    *(_DWORD *)(a2 + 20) = 0;
    v16 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(a2 + 28) = v16;
    *(_DWORD *)(a2 + 32) = v16;
    *(Wm4::Vector2<float> *)(a2 + 48) = Wm4::Vector2<float>::ZERO;
    *(Wm4::Vector2<float> *)(a2 + 56) = Wm4::Vector2<float>::ZERO;
  }
}
