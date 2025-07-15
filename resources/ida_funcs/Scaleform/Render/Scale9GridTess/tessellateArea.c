void __thiscall Scaleform::Render::Scale9GridTess::tessellateArea(
        Scaleform::Render::Scale9GridTess *this,
        Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2> *ver,
        float i1,
        unsigned int i2)
{
  unsigned int v4; // ebx
  unsigned int v6; // ecx
  unsigned int v8; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType *v9; // eax
  unsigned int *p_VerIdx; // edi
  unsigned int *v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edx
  double y; // st7
  float *p_x; // edx
  double v16; // st7
  float *v17; // edx
  double v18; // st7
  float *v19; // edx
  unsigned int *v20; // edx
  unsigned int v21; // edi
  unsigned int v22; // eax
  int v23; // eax
  Scaleform::Render::Scale9GridTess::TmpVertexType *Data; // edi
  unsigned int v25; // eax
  int v26; // edi
  Scaleform::ArrayStaticBuffPOD<unsigned short,72,2> *p_Indices; // ebx
  int v28; // edi
  unsigned int v29; // esi
  float v30; // [esp+20h] [ebp-8h]
  float v31; // [esp+20h] [ebp-8h]
  float v32; // [esp+20h] [ebp-8h]
  float v33; // [esp+20h] [ebp-8h]
  float x1; // [esp+20h] [ebp-8h]
  unsigned int v35; // [esp+24h] [ebp-4h]
  unsigned int i; // [esp+2Ch] [ebp+4h]
  float ib; // [esp+2Ch] [ebp+4h]
  unsigned int ia; // [esp+2Ch] [ebp+4h]

  v4 = LODWORD(i1);
  v6 = i2;
  if ( LODWORD(i1) + 3 <= i2 )
  {
    v30 = 0.0;
    i1 = 0.0;
    v8 = v4;
    if ( v4 < i2 )
    {
      if ( (int)(i2 - v4) >= 4 )
      {
        v9 = &ver->Data[v4];
        p_VerIdx = &v9->VerIdx;
        v11 = &v9[2].VerIdx;
        v12 = ((i2 - v4 - 4) >> 2) + 1;
        i = v4 + 4 * v12;
        do
        {
          v13 = *p_VerIdx;
          p_VerIdx += 12;
          v11 += 12;
          v31 = this->Vertices[v13].x + v30;
          y = this->Vertices[v13].y;
          p_x = &this->Vertices[*(v11 - 15)].x;
          i1 = y + i1;
          v32 = *p_x + v31;
          v16 = p_x[1];
          v17 = &this->Vertices[*(v11 - 12)].x;
          i1 = v16 + i1;
          v33 = *v17 + v32;
          v18 = v17[1];
          v19 = &this->Vertices[*(v11 - 9)].x;
          --v12;
          i1 = v18 + i1;
          v30 = v33 + *v19;
          i1 = v19[1] + i1;
        }
        while ( v12 );
        v6 = i2;
        v8 = i;
      }
      if ( v8 < v6 )
      {
        v20 = &ver->Data[v8].VerIdx;
        v21 = v6 - v8;
        do
        {
          v22 = *v20;
          v20 += 3;
          --v21;
          v30 = this->Vertices[v22].x + v30;
          i1 = this->Vertices[v22].y + i1;
        }
        while ( v21 );
      }
    }
    ib = (float)(v6 - v4);
    x1 = v30 / ib;
    i1 = i1 / ib;
    if ( v4 < v6 )
    {
      v23 = 12 * v4;
      ia = 12 * v4;
      v35 = v6 - v4;
      while ( 1 )
      {
        Data = ver->Data;
        ia += 12;
        *(float *)((char *)&Data->Slope + v23) = Scaleform::Render::Math2D::SlopeRatio(
                                                   x1,
                                                   i1,
                                                   this->Vertices[*(unsigned int *)((char *)&Data->VerIdx + v23)].x,
                                                   this->Vertices[*(unsigned int *)((char *)&Data->VerIdx + v23)].y);
        if ( !--v35 )
          break;
        v23 = ia;
      }
      v6 = i2;
    }
    Scaleform::Alg::QuickSortSliced<Scaleform::ArrayStaticBuffPOD<Scaleform::Render::Scale9GridTess::TmpVertexType,72,2>,bool (__cdecl *)(Scaleform::Render::Scale9GridTess::TmpVertexType const &,Scaleform::Render::Scale9GridTess::TmpVertexType const &)>(
      ver,
      v4,
      v6,
      (bool (__cdecl *)(const Scaleform::Render::Scale9GridTess::TmpVertexType *, const Scaleform::Render::Scale9GridTess::TmpVertexType *))Scaleform::Render::Scale9GridTess::cmpSlopes);
    v25 = v4 + 2;
    if ( v4 + 2 < i2 )
    {
      v26 = 3 * v4;
      p_Indices = &this->Indices;
      v28 = 4 * v26;
      v29 = v25;
      i2 -= v25;
      do
      {
        LODWORD(i1) = *(unsigned __int16 *)((char *)&ver->Data->VerIdx + v28);
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, (const unsigned __int16 *)&i1);
        LODWORD(i1) = LOWORD(ver->Data[v29 - 1].VerIdx);
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, (const unsigned __int16 *)&i1);
        LODWORD(i1) = LOWORD(ver->Data[v29].VerIdx);
        Scaleform::ArrayStaticBuffPOD<unsigned short,72,2>::PushBack(p_Indices, (const unsigned __int16 *)&i1);
        ++v29;
        --i2;
      }
      while ( i2 );
    }
  }
}
