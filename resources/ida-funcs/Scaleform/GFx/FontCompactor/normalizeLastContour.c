void __thiscall Scaleform::GFx::FontCompactor::normalizeLastContour(Scaleform::GFx::FontCompactor *this)
{
  Scaleform::GFx::FontCompactor *v1; // ebx
  Scaleform::GFx::FontCompactor::ContourType *v2; // edi
  Scaleform::GFx::FontCompactor::VertexType v3; // eax
  unsigned int Size; // eax
  unsigned int DataStart; // edi
  unsigned int v6; // eax
  Scaleform::GFx::FontCompactor::VertexType **Pages; // edx
  unsigned int v8; // ecx
  unsigned int v9; // ebp
  unsigned int v10; // eax
  Scaleform::GFx::FontCompactor::VertexType v11; // eax
  int v12; // eax
  Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261> > *p_TmpContour; // esi
  unsigned int v14; // eax
  unsigned int DataSize; // ecx
  unsigned int v16; // edi
  Scaleform::GFx::FontCompactor::VertexType **v17; // ebx
  Scaleform::GFx::FontCompactor::VertexType v18; // ebx
  unsigned int v19; // edi
  unsigned int v20; // edi
  unsigned int v21; // edi
  unsigned int i; // ebp
  unsigned int v23; // esi
  __int16 x; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::FontCompactor::VertexType v25; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::FontCompactor::VertexType v26; // [esp+Ch] [ebp-18h]
  unsigned int v27; // [esp+10h] [ebp-14h]
  unsigned int v28; // [esp+10h] [ebp-14h]
  Scaleform::GFx::FontCompactor::ContourType *v29; // [esp+14h] [ebp-10h]
  int y; // [esp+18h] [ebp-Ch]
  int v31; // [esp+1Ch] [ebp-8h]
  unsigned int v32; // [esp+1Ch] [ebp-8h]
  Scaleform::GFx::FontCompactor::VertexType *v34; // [esp+20h] [ebp-4h]

  v1 = this;
  v2 = &this->TmpContours.Pages[(this->TmpContours.Size - 1) >> 6][(this->TmpContours.Size - 1) & 0x3F];
  v3 = this->TmpVertices.Pages[(this->TmpVertices.Size - 1) >> 6][(this->TmpVertices.Size - 1) & 0x3F];
  v29 = v2;
  if ( (v3.x & 1) == 0 && *(_DWORD *)&this->TmpVertices.Pages[v2->DataStart >> 6][v2->DataStart & 0x3F] == v3 )
  {
    --v2->DataSize;
    Size = this->TmpVertices.Size;
    if ( Size )
      this->TmpVertices.Size = Size - 1;
  }
  if ( v2->DataSize < 3 )
  {
    DataStart = v2->DataStart;
    if ( DataStart < this->TmpVertices.Size )
      this->TmpVertices.Size = DataStart;
    v6 = this->TmpContours.Size;
    if ( v6 )
      this->TmpContours.Size = v6 - 1;
    return;
  }
  Pages = this->TmpVertices.Pages;
  v31 = Pages[v2->DataStart >> 6][v2->DataStart & 0x3F].x >> 1;
  y = Pages[v2->DataStart >> 6][v2->DataStart & 0x3F].y;
  v8 = 1;
  v9 = 0;
  if ( v2->DataSize <= 1 )
    return;
  v10 = v2->DataStart + 1;
  v27 = v10;
  do
  {
    v11 = Pages[v10 >> 6][v10 & 0x3F];
    x = v11.x;
    if ( (v11.x & 1) != 0 )
    {
      ++v8;
      ++v27;
      goto LABEL_20;
    }
    v12 = v11.y;
    if ( v12 < y )
    {
      y = v12;
LABEL_19:
      v9 = v8;
      goto LABEL_20;
    }
    if ( v12 == y && x >> 1 < v31 )
    {
      v31 = x;
      goto LABEL_19;
    }
LABEL_20:
    ++v8;
    v10 = ++v27;
  }
  while ( v8 < v2->DataSize );
  if ( !v9 )
    return;
  v1->TmpContour.Size = 0;
  v25 = Pages[(v9 + v2->DataStart) >> 6][(v9 + v2->DataStart) & 0x3F];
  v25.x &= ~1u;
  p_TmpContour = &v1->TmpContour;
  v14 = v1->TmpContour.Size >> 6;
  v32 = v14;
  if ( v14 >= v1->TmpContour.NumPages )
  {
    Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
      &v1->TmpContour,
      v14);
    v14 = v32;
  }
  v1->TmpContour.Pages[v14][v1->TmpContour.Size++ & 0x3F] = v25;
  v28 = 1;
  if ( v2->DataSize > 1 )
  {
    while ( 2 )
    {
      DataSize = v2->DataSize;
      ++v9;
      v16 = v2->DataStart;
      v17 = v1->TmpVertices.Pages;
      v26 = v17[(v16 + v9 % DataSize) >> 6][(v16 + v9 % DataSize) & 0x3F];
      if ( (v26.x & 1) != 0 )
      {
        ++v9;
        ++v28;
        v18 = v17[(v16 + v9 % DataSize) >> 6][(v16 + v9 % DataSize) & 0x3F];
        v19 = p_TmpContour->Size >> 6;
        if ( v19 >= p_TmpContour->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
            p_TmpContour,
            p_TmpContour->Size >> 6);
        p_TmpContour->Pages[v19][p_TmpContour->Size++ & 0x3F] = v26;
        v20 = p_TmpContour->Size >> 6;
        if ( v20 >= p_TmpContour->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
            p_TmpContour,
            p_TmpContour->Size >> 6);
        p_TmpContour->Pages[v20][p_TmpContour->Size & 0x3F] = v18;
        goto LABEL_36;
      }
      if ( ((v26.x ^ p_TmpContour->Pages[(p_TmpContour->Size - 1) >> 6][(p_TmpContour->Size - 1) & 0x3F].x) & 0xFFFE) != 0
        || v26.y != p_TmpContour->Pages[(p_TmpContour->Size - 1) >> 6][(p_TmpContour->Size - 1) & 0x3F].y )
      {
        v21 = p_TmpContour->Size >> 6;
        if ( v21 >= p_TmpContour->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
            p_TmpContour,
            p_TmpContour->Size >> 6);
        p_TmpContour->Pages[v21][p_TmpContour->Size & 0x3F] = v26;
LABEL_36:
        ++p_TmpContour->Size;
      }
      v1 = this;
      ++v28;
      v2 = v29;
      if ( v28 >= v29->DataSize )
        break;
      continue;
    }
  }
  if ( v2->DataStart < v1->TmpVertices.Size )
    v1->TmpVertices.Size = v2->DataStart;
  for ( i = 0; i < v1->TmpContour.Size; ++i )
  {
    v23 = v1->TmpVertices.Size >> 6;
    v34 = &v1->TmpContour.Pages[i >> 6][i & 0x3F];
    if ( v23 >= v1->TmpVertices.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
        &v1->TmpVertices,
        v23);
    v1->TmpVertices.Pages[v23][v1->TmpVertices.Size++ & 0x3F] = *v34;
  }
  v29->DataSize = v1->TmpContour.Size;
}
