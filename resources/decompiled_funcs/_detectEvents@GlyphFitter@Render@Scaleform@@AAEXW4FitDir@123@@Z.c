void __thiscall Scaleform::Render::GlyphFitter::detectEvents(
        Scaleform::Render::GlyphFitter *this,
        Scaleform::Render::GlyphFitter::FitDir dir)
{
  __int16 MinX; // ax
  int v4; // esi
  unsigned int v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *Array; // eax
  unsigned int v8; // eax
  Scaleform::Render::GlyphFitter::ContourType *v9; // edx
  int v10; // esi
  const Scaleform::Render::GlyphFitter::ContourType *v11; // edx
  unsigned int v12; // ebp
  unsigned int StartVertex; // ecx
  Scaleform::Render::GlyphFitter::VertexType **Pages; // esi
  unsigned int NumVertices; // edi
  unsigned int v16; // ebp
  Scaleform::Render::GlyphFitter::VertexType v17; // edx
  __int16 y; // si
  __int16 x; // ax
  int v20; // edx
  __int16 v21; // di
  char v22; // cl
  int v23; // esi
  unsigned __int8 *v24; // eax
  int v25; // eax
  bool v26; // cc
  Scaleform::Render::GlyphFitter::VertexType v1; // [esp+Ch] [ebp-1Ch]
  Scaleform::Render::GlyphFitter::VertexType v3; // [esp+10h] [ebp-18h]
  unsigned int j; // [esp+14h] [ebp-14h]
  Scaleform::Render::GlyphFitter::VertexType v2; // [esp+18h] [ebp-10h]
  int minCoord; // [esp+1Ch] [ebp-Ch]
  const Scaleform::Render::GlyphFitter::ContourType *c; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  if ( dir == FitX )
    MinX = this->MinX;
  else
    MinX = this->MinY;
  minCoord = MinX;
  if ( dir == FitX )
    v4 = this->MaxX - this->MinX;
  else
    v4 = this->MaxY - this->MinY;
  v5 = v4 + 1;
  if ( v5 > this->Events.Size )
  {
    v6 = Scaleform::Render::LinearHeap::Alloc(this->Events.pHeap, v5);
    memset((int)v6, 0, v5);
    Array = this->Events.Array;
    if ( Array && this->Events.Size )
      memcpy(v6, Array, this->Events.Size);
    this->Events.Array = v6;
  }
  this->Events.Size = v5;
  memset((int)this->Events.Array, 0, v5);
  v8 = 0;
  i = 0;
  if ( this->Contours.Size )
  {
    while ( 1 )
    {
      v9 = this->Contours.Pages[v8 >> 2];
      v10 = v8 & 3;
      v26 = v9[v10].NumVertices <= 2;
      v11 = &v9[v10];
      c = v11;
      if ( !v26 )
      {
        v12 = 0;
        *this->Events.Array = 3;
        j = 0;
        if ( v11->NumVertices )
          break;
      }
LABEL_40:
      i = ++v8;
      if ( v8 >= this->Contours.Size )
        return;
    }
    while ( 1 )
    {
      StartVertex = v11->StartVertex;
      Pages = this->Vertices.Pages;
      NumVertices = v11->NumVertices;
      v1 = Pages[(v11->StartVertex + v12) >> 4][(v11->StartVertex + v12) & 0xF];
      v16 = v12 + 2;
      v2 = Pages[(StartVertex + (v16 - 1) % NumVertices) >> 4][(StartVertex + (v16 - 1) % NumVertices) & 0xF];
      v17 = Pages[(StartVertex + v16 % NumVertices) >> 4][(StartVertex + v16 % NumVertices) & 0xF];
      v3 = v17;
      if ( dir == FitX )
      {
        y = (__int16)Pages[(StartVertex + v16 % NumVertices) >> 4][(StartVertex + v16 % NumVertices) & 0xF];
        v1.y = v1.x;
        x = v2.x;
        v20 = -HIWORD(*(unsigned int *)&v17);
      }
      else
      {
        LOWORD(v20) = v1.x;
        x = v2.y;
        y = v3.y;
      }
      v21 = v1.y;
      v22 = 0;
      if ( v1.y < x )
        goto LABEL_23;
      if ( y < x )
        break;
LABEL_24:
      v23 = x - minCoord;
      if ( (__int16)v20 > v2.x )
        goto LABEL_28;
      if ( v2.x <= v3.x )
      {
        this->Events.Array[v23] |= (this->Direction == DirCW) + 1;
        v22 = 1;
      }
      if ( (__int16)v20 >= v2.x )
      {
LABEL_28:
        if ( v2.x >= v3.x )
        {
          v24 = &this->Events.Array[v23];
LABEL_37:
          *v24 |= (this->Direction != DirCW) + 1;
          goto LABEL_38;
        }
      }
      if ( v22 )
        goto LABEL_38;
      v21 = v1.y;
LABEL_32:
      if ( v21 == x )
      {
        v25 = x - minCoord;
        v26 = (__int16)v20 <= v2.x;
        if ( (__int16)v20 < v2.x )
        {
          this->Events.Array[v25] |= (this->Direction == DirCW) + 1;
          v26 = (__int16)v20 <= v2.x;
        }
        if ( !v26 )
        {
          v24 = &this->Events.Array[v25];
          goto LABEL_37;
        }
      }
LABEL_38:
      if ( ++j >= c->NumVertices )
      {
        v8 = i;
        goto LABEL_40;
      }
      v12 = j;
      v11 = c;
    }
    if ( v1.y > x )
      goto LABEL_38;
LABEL_23:
    if ( y > x )
      goto LABEL_32;
    goto LABEL_24;
  }
}
