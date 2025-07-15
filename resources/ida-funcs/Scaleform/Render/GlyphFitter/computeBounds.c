void __thiscall Scaleform::Render::GlyphFitter::computeBounds(Scaleform::Render::GlyphFitter *this)
{
  __int16 v1; // bp
  unsigned int v2; // esi
  Scaleform::Render::GlyphFitter::ContourType *v3; // eax
  int v4; // edi
  unsigned int NumVertices; // edx
  Scaleform::Render::GlyphFitter::ContourType *v6; // eax
  unsigned int StartVertex; // ebx
  Scaleform::Render::GlyphFitter::VertexType v8; // eax
  Scaleform::Render::GlyphFitter::VertexType *v9; // edi
  __int16 x; // dx
  __int16 y; // si
  int v12; // ebp
  int v13; // edx
  __int16 v14; // [esp+8h] [ebp-1Ch]
  __int16 v15; // [esp+Ch] [ebp-18h]
  __int16 v16; // [esp+10h] [ebp-14h]
  __int16 v17; // [esp+14h] [ebp-10h]
  int v18; // [esp+18h] [ebp-Ch]
  unsigned int i; // [esp+1Ch] [ebp-8h]
  unsigned int v20; // [esp+20h] [ebp-4h]

  v1 = 0x7FFF;
  v2 = 0;
  this->MinX = 0x7FFF;
  this->MinY = 0x7FFF;
  v17 = 0x7FFF;
  v14 = 0x7FFF;
  v15 = -32767;
  v16 = -32767;
  this->MaxX = -32767;
  this->MaxY = -32767;
  for ( i = 0; v2 < this->Contours.Size; i = v2 )
  {
    v3 = this->Contours.Pages[v2 >> 2];
    v4 = v2 & 3;
    NumVertices = v3[v4].NumVertices;
    v6 = &v3[v4];
    if ( NumVertices > 2 )
    {
      StartVertex = v6->StartVertex;
      v8 = this->Vertices.Pages[(v6->StartVertex + NumVertices - 1) >> 4][(v6->StartVertex + NumVertices - 1) & 0xF];
      v18 = 0;
      v20 = NumVertices;
      do
      {
        v9 = &this->Vertices.Pages[StartVertex >> 4][StartVertex & 0xF];
        x = v9->x;
        if ( v9->x < v1 )
          v17 = v9->x;
        y = v9->y;
        if ( y < v14 )
          v14 = v9->y;
        if ( x > v15 )
          v15 = v9->x;
        if ( y > v16 )
          v16 = v9->y;
        v12 = x * v8.y;
        v13 = v8.x * y;
        v8 = *v9;
        v18 += v13 - v12;
        v1 = v17;
        ++StartVertex;
        --v20;
      }
      while ( v20 );
      v2 = i;
      if ( v17 < this->MinX || v14 < this->MinY || v15 > this->MaxX || v16 > this->MaxY )
      {
        this->MaxX = v15;
        this->MinY = v14;
        this->MinX = v17;
        this->MaxY = v16;
        this->Direction = (v18 > 0) + 1;
      }
    }
    ++v2;
  }
}
