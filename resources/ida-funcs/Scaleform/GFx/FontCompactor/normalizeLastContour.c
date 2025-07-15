void __thiscall Scaleform::GFx::FontCompactor::normalizeLastContour(Scaleform::GFx::FontCompactor *this)
{
  Scaleform::GFx::FontCompactor *ebx1; // ebx
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
  int y; // eax
  Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261> > *p_TmpContour; // esi
  unsigned int v14; // eax
  unsigned int DataSize; // ecx
  unsigned int v16; // edi
  Scaleform::GFx::FontCompactor::VertexType **v17; // ebx
  Scaleform::GFx::FontCompactor::VertexType v18; // ebx
  unsigned int v19; // edi
  unsigned int v20; // edi
  unsigned int v21; // edi
  unsigned int j; // ebp
  unsigned int v23; // esi
  __int16 v1; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::FontCompactor::VertexType v1a; // [esp+Ch] [ebp-18h]
  Scaleform::GFx::FontCompactor::VertexType v1b; // [esp+Ch] [ebp-18h]
  unsigned int i; // [esp+10h] [ebp-14h]
  unsigned int ia; // [esp+10h] [ebp-14h]
  Scaleform::GFx::FontCompactor::ContourType *c; // [esp+14h] [ebp-10h]
  int minY; // [esp+18h] [ebp-Ch]
  int minX; // [esp+1Ch] [ebp-8h]
  int minXa; // [esp+1Ch] [ebp-8h]
  Scaleform::GFx::FontCompactor::VertexType *v34; // [esp+20h] [ebp-4h]

  ebx1 = this;
  v2 = &this->TmpContours.Pages[(this->TmpContours.Size - 1) >> 6][(this->TmpContours.Size - 1) & 0x3F];
  v3 = this->TmpVertices.Pages[(this->TmpVertices.Size - 1) >> 6][(this->TmpVertices.Size - 1) & 0x3F];
  c = v2;
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
  minX = Pages[v2->DataStart >> 6][v2->DataStart & 0x3F].x >> 1;
  minY = Pages[v2->DataStart >> 6][v2->DataStart & 0x3F].y;
  v8 = 1;
  v9 = 0;
  if ( v2->DataSize <= 1 )
    return;
  v10 = v2->DataStart + 1;
  i = v10;
  do
  {
    v11 = Pages[v10 >> 6][v10 & 0x3F];
    v1 = v11.x;
    if ( (v11.x & 1) != 0 )
    {
      ++v8;
      ++i;
      goto LABEL_20;
    }
    y = v11.y;
    if ( y < minY )
    {
      minY = y;
LABEL_19:
      v9 = v8;
      goto LABEL_20;
    }
    if ( y == minY && v1 >> 1 < minX )
    {
      minX = v1;
      goto LABEL_19;
    }
LABEL_20:
    ++v8;
    v10 = ++i;
  }
  while ( v8 < v2->DataSize );
  if ( !v9 )
    return;
  ebx1->TmpContour.Size = 0;
  v1a = Pages[(v9 + v2->DataStart) >> 6][(v9 + v2->DataStart) & 0x3F];
  v1a.x &= ~1u;
  p_TmpContour = &ebx1->TmpContour;
  v14 = ebx1->TmpContour.Size >> 6;
  minXa = v14;
  if ( v14 >= ebx1->TmpContour.NumPages )
  {
    Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
      &ebx1->TmpContour,
      v14);
    v14 = minXa;
  }
  ebx1->TmpContour.Pages[v14][ebx1->TmpContour.Size++ & 0x3F] = v1a;
  ia = 1;
  if ( v2->DataSize > 1 )
  {
    while ( 2 )
    {
      DataSize = v2->DataSize;
      ++v9;
      v16 = v2->DataStart;
      v17 = ebx1->TmpVertices.Pages;
      v1b = v17[(v16 + v9 % DataSize) >> 6][(v16 + v9 % DataSize) & 0x3F];
      if ( (v1b.x & 1) != 0 )
      {
        ++v9;
        ++ia;
        v18 = v17[(v16 + v9 % DataSize) >> 6][(v16 + v9 % DataSize) & 0x3F];
        v19 = p_TmpContour->Size >> 6;
        if ( v19 >= p_TmpContour->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
            p_TmpContour,
            p_TmpContour->Size >> 6);
        p_TmpContour->Pages[v19][p_TmpContour->Size++ & 0x3F] = v1b;
        v20 = p_TmpContour->Size >> 6;
        if ( v20 >= p_TmpContour->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
            p_TmpContour,
            p_TmpContour->Size >> 6);
        p_TmpContour->Pages[v20][p_TmpContour->Size & 0x3F] = v18;
        goto LABEL_36;
      }
      if ( ((v1b.x ^ p_TmpContour->Pages[(p_TmpContour->Size - 1) >> 6][(p_TmpContour->Size - 1) & 0x3F].x) & 0xFFFE) != 0
        || v1b.y != p_TmpContour->Pages[(p_TmpContour->Size - 1) >> 6][(p_TmpContour->Size - 1) & 0x3F].y )
      {
        v21 = p_TmpContour->Size >> 6;
        if ( v21 >= p_TmpContour->NumPages )
          Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
            p_TmpContour,
            p_TmpContour->Size >> 6);
        p_TmpContour->Pages[v21][p_TmpContour->Size & 0x3F] = v1b;
LABEL_36:
        ++p_TmpContour->Size;
      }
      ebx1 = this;
      ++ia;
      v2 = c;
      if ( ia >= c->DataSize )
        break;
      continue;
    }
  }
  if ( v2->DataStart < ebx1->TmpVertices.Size )
    ebx1->TmpVertices.Size = v2->DataStart;
  for ( j = 0; j < ebx1->TmpContour.Size; ++j )
  {
    v23 = ebx1->TmpVertices.Size >> 6;
    v34 = &ebx1->TmpContour.Pages[j >> 6][j & 0x3F];
    if ( v23 >= ebx1->TmpVertices.NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::VertexType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::VertexType,261>>::allocatePage(
        &ebx1->TmpVertices,
        v23);
    ebx1->TmpVertices.Pages[v23][ebx1->TmpVertices.Size++ & 0x3F] = *v34;
  }
  c->DataSize = ebx1->TmpContour.Size;
}
