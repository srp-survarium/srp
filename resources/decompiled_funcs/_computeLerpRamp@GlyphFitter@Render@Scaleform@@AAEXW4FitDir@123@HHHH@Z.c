void __thiscall Scaleform::Render::GlyphFitter::computeLerpRamp(
        Scaleform::Render::GlyphFitter *this,
        Scaleform::Render::GlyphFitter::FitDir dir,
        int unitsPerPixel,
        int middle,
        int lowerCaseTop,
        Scaleform::Render::GlyphFitter::VertexType upperCaseTop)
{
  Scaleform::Render::GlyphFitter *v6; // ebx
  __int16 v7; // ax
  Scaleform::Render::ArrayPaged<unsigned int,4,16> *p_LerpPairs; // esi
  unsigned int v9; // edi
  unsigned int *v10; // edx
  int SnappedHeight; // ecx
  __int16 MinX; // ax
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ebp
  unsigned __int8 v17; // al
  unsigned int Size; // eax
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // eax
  int v23; // eax
  unsigned int v24; // ebx
  unsigned int v25; // edi
  Scaleform::Render::ArrayUnsafe<short> *p_LerpRampX; // esi
  unsigned int v27; // ebp
  unsigned __int8 *Array; // eax
  unsigned int v29; // ecx
  Scaleform::Render::GlyphFitter::VertexType *v30; // ecx
  Scaleform::Render::GlyphFitter::VertexType v31; // eax
  Scaleform::Render::GlyphFitter::VertexType v32; // esi
  unsigned int v33; // edi
  unsigned int v34; // ecx
  unsigned int v35; // ecx
  int v36; // eax
  Scaleform::Render::GlyphFitter::VertexType lerpPair; // [esp+10h] [ebp-18h] BYREF
  int prev; // [esp+14h] [ebp-14h]
  Scaleform::Render::GlyphFitter *v39; // [esp+18h] [ebp-10h]
  int top1s; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+20h] [ebp-8h]
  int minCoord; // [esp+24h] [ebp-4h]
  unsigned __int8 *dira; // [esp+2Ch] [ebp+4h]
  Scaleform::Render::GlyphFitter::FitDir dirb; // [esp+2Ch] [ebp+4h]
  int top2s; // [esp+30h] [ebp+8h]
  int top2sa; // [esp+30h] [ebp+8h]
  unsigned int topIdx; // [esp+38h] [ebp+10h]
  Scaleform::Render::GlyphFitter::VertexType v1; // [esp+3Ch] [ebp+14h]

  v6 = this;
  v7 = -4 * LOWORD(this->SnappedHeight);
  p_LerpPairs = (Scaleform::Render::ArrayPaged<unsigned int,4,16> *)&this->LerpPairs;
  this->LerpPairs.Size = 0;
  v9 = this->LerpPairs.Size >> 4;
  v39 = this;
  lerpPair.x = v7;
  lerpPair.y = v7;
  if ( v9 >= this->LerpPairs.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<unsigned int,4,16> *)&this->LerpPairs,
      v9);
  v10 = p_LerpPairs->Pages[v9];
  v10[p_LerpPairs->Size++ & 0xF] = (unsigned int)lerpPair;
  SnappedHeight = v6->SnappedHeight;
  prev = -32767;
  top1s = unitsPerPixel * ((lowerCaseTop + SnappedHeight + unitsPerPixel) / unitsPerPixel) - SnappedHeight;
  top2s = unitsPerPixel * ((*(_DWORD *)&upperCaseTop + SnappedHeight + unitsPerPixel) / unitsPerPixel) - SnappedHeight;
  if ( dir == FitX )
    MinX = v6->MinX;
  else
    MinX = v6->MinY;
  v14 = MinX;
  v15 = 0;
  minCoord = v14;
  i = 0;
  if ( v6->Events.Size )
  {
    v16 = v14;
    while ( 1 )
    {
      v17 = v6->Events.Array[v15];
      if ( v16 <= middle || dir == FitX )
      {
        if ( (v17 & 1) == 0 || v16 <= unitsPerPixel + prev + 1 )
          goto LABEL_41;
        v23 = unitsPerPixel * ((v6->SnappedHeight + unitsPerPixel / 2 + v16 + 1) / unitsPerPixel) - v6->SnappedHeight;
        if ( SHIWORD(p_LerpPairs->Pages[(p_LerpPairs->Size - 1) >> 4][(p_LerpPairs->Size - 1) & 0xF]) != v23 )
        {
          v24 = p_LerpPairs->Size >> 4;
          lerpPair.x = v16;
          lerpPair.y = v23;
          if ( v24 >= p_LerpPairs->NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(p_LerpPairs, v24);
          p_LerpPairs->Pages[v24][p_LerpPairs->Size++ & 0xF] = (unsigned int)lerpPair;
        }
        v6 = v39;
        goto LABEL_40;
      }
      if ( (v17 & 2) != 0 )
        break;
LABEL_41:
      v15 = i + 1;
      ++v16;
      i = v15;
      if ( v15 >= v6->Events.Size )
        goto LABEL_42;
    }
    if ( upperCaseTop )
    {
      if ( v16 >= *(_DWORD *)&upperCaseTop && v16 < unitsPerPixel + *(_DWORD *)&upperCaseTop + 1 )
      {
        if ( v16 <= unitsPerPixel + prev + 1
          || unitsPerPixel + SHIWORD(p_LerpPairs->Pages[(p_LerpPairs->Size - 1) >> 4][(p_LerpPairs->Size - 1) & 0xF]) >= top2s )
        {
          Size = p_LerpPairs->Size;
          if ( Size )
            p_LerpPairs->Size = Size - 1;
        }
        lerpPair.y = top2s;
        lerpPair.x = v16;
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)p_LerpPairs,
          &lerpPair);
LABEL_40:
        prev = v16;
        goto LABEL_41;
      }
      if ( v16 >= lowerCaseTop && v16 < unitsPerPixel + lowerCaseTop + 1 )
      {
        if ( v16 <= unitsPerPixel + prev + 1
          || unitsPerPixel + SHIWORD(p_LerpPairs->Pages[(p_LerpPairs->Size - 1) >> 4][(p_LerpPairs->Size - 1) & 0xF]) >= top1s )
        {
          v19 = p_LerpPairs->Size;
          if ( v19 )
            p_LerpPairs->Size = v19 - 1;
        }
        lerpPair.x = v16;
        lerpPair.y = top1s;
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *)p_LerpPairs,
          &lerpPair);
        goto LABEL_40;
      }
    }
    v20 = unitsPerPixel * ((unitsPerPixel + v6->SnappedHeight + v16) / unitsPerPixel) - v6->SnappedHeight;
    if ( v16 <= unitsPerPixel + prev + 1
      || (v6 = v39,
          unitsPerPixel + SHIWORD(p_LerpPairs->Pages[(p_LerpPairs->Size - 1) >> 4][(p_LerpPairs->Size - 1) & 0xF]) >= v20) )
    {
      v21 = p_LerpPairs->Size;
      if ( v21 )
        p_LerpPairs->Size = v21 - 1;
    }
    lerpPair.y = v20;
    v22 = p_LerpPairs->Size >> 4;
    lerpPair.x = v16;
    prev = v22;
    if ( v22 >= p_LerpPairs->NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(p_LerpPairs, v22);
      v22 = prev;
    }
    p_LerpPairs->Pages[v22][p_LerpPairs->Size++ & 0xF] = (unsigned int)lerpPair;
    goto LABEL_40;
  }
LABEL_42:
  v25 = p_LerpPairs->Size >> 4;
  lerpPair.x = 4 * LOWORD(v6->SnappedHeight);
  lerpPair.y = lerpPair.x;
  if ( v25 >= p_LerpPairs->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(p_LerpPairs, v25);
  p_LerpPairs->Pages[v25][p_LerpPairs->Size++ & 0xF] = (unsigned int)lerpPair;
  p_LerpRampX = &v6->LerpRampX;
  if ( dir != FitX )
    p_LerpRampX = &v6->LerpRampY;
  v27 = v6->Events.Size;
  top2sa = (int)p_LerpRampX;
  if ( v27 > p_LerpRampX->Size )
  {
    dira = Scaleform::Render::LinearHeap::Alloc(p_LerpRampX->pHeap, 2 * v27);
    memset((int)dira, 0, 2 * v27);
    Array = (unsigned __int8 *)p_LerpRampX->Array;
    if ( Array )
    {
      v29 = p_LerpRampX->Size;
      if ( v29 )
        memcpy(dira, Array, 2 * v29);
    }
    p_LerpRampX->Array = (__int16 *)dira;
  }
  p_LerpRampX->Size = v27;
  v30 = *v6->LerpPairs.Pages;
  v31 = *v30;
  v32 = v30[1];
  v33 = 0;
  v34 = 2;
  v1 = v31;
  topIdx = 2;
  if ( v6->Events.Size )
  {
    dirb = minCoord;
    while ( 1 )
    {
      if ( dirb >= v32.x && v34 < v6->LerpPairs.Size )
      {
        v31 = v32;
        v32 = v6->LerpPairs.Pages[v34 >> 4][v34 & 0xF];
        v1 = v31;
        topIdx = v34 + 1;
      }
      v35 = HIWORD(*(unsigned int *)&v31);
      v36 = (dirb - v31.x) * (v32.y - v31.y) / (v32.x - v31.x);
      ++dirb;
      ++v33;
      *(_WORD *)(*(_DWORD *)(top2sa + 8) + 2 * v33 - 2) = v35 + v36 - minCoord;
      if ( v33 >= v6->Events.Size )
        break;
      v34 = topIdx;
      v31 = v1;
    }
  }
}
