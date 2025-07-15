void __thiscall Scaleform::Render::StrokeSorter::Snap(
        Scaleform::Render::StrokeSorter *this,
        float offsetX,
        float offsetY)
{
  Scaleform::Render::StrokeSorter *v3; // esi
  unsigned int v4; // eax
  double v5; // st7
  Scaleform::Render::StrokeSorter::VertexType **Pages; // edi
  Scaleform::Render::StrokeSorter::PathType *v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  float *p_x; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // esi
  float *v15; // edx
  float *v16; // ecx
  float *v17; // edx
  unsigned int v18; // esi
  unsigned int v19; // ebx
  float *v20; // edx
  unsigned int v21; // esi
  Scaleform::Render::StrokeSorter::VertexType *v22; // edi
  double x; // st6
  double v24; // st7
  unsigned int v25; // esi
  float *p_y; // edi
  double v27; // st6
  double v28; // st7
  bool snapX; // [esp+2Eh] [ebp-1Ah]
  bool snapY; // [esp+2Fh] [ebp-19h]
  unsigned int start; // [esp+30h] [ebp-18h]
  unsigned int i; // [esp+38h] [ebp-10h]
  unsigned int v34; // [esp+3Ch] [ebp-Ch]
  unsigned int numVer; // [esp+40h] [ebp-8h]
  unsigned int y; // [esp+44h] [ebp-4h]
  float ya; // [esp+44h] [ebp-4h]
  float yb; // [esp+44h] [ebp-4h]
  float yc; // [esp+44h] [ebp-4h]
  float yd; // [esp+44h] [ebp-4h]

  v3 = this;
  v4 = 0;
  i = 0;
  if ( this->OutPaths.Size )
  {
    v5 = 0.5;
    while ( 1 )
    {
      Pages = v3->OutVertices.Pages;
      v7 = v3->OutPaths.Pages[v4 >> 4];
      v8 = v4 & 0xF;
      v9 = v7[v8].numVer;
      start = v7[v8].start;
      p_x = &Pages[start >> 4][start & 0xF].x;
      v11 = v9 & 0xFFFFFFF;
      numVer = v9 & 0xFFFFFFF;
      snapX = 0;
      snapY = 0;
      v12 = 1;
      if ( (v9 & 0x20000000) != 0 )
      {
        v12 = 0;
        p_x = &Pages[(v11 + start - 1) >> 4][(v11 + start - 1) & 0xF].x;
      }
      v13 = v12;
      if ( v12 < v11 )
      {
        if ( (int)(v11 - v12) >= 4 )
        {
          v14 = v12 + start + 1;
          v34 = ((v11 - v12 - 4) >> 2) + 1;
          y = v12 + 4 * v34;
          do
          {
            v15 = &Pages[(v14 - 1) >> 4][((_BYTE)v14 - 1) & 0xF].x;
            if ( *v15 == *p_x && v15[1] != p_x[1] )
              snapX = 1;
            if ( v15[1] == p_x[1] && *v15 != *p_x )
              snapY = 1;
            v16 = &Pages[v14 >> 4][v14 & 0xF].x;
            if ( *v16 == *v15 && v16[1] != v15[1] )
              snapX = 1;
            if ( v16[1] == v15[1] && *v16 != *v15 )
              snapY = 1;
            v17 = &Pages[(v14 + 1) >> 4][(v14 + 1) & 0xF].x;
            if ( *v17 == *v16 && v17[1] != v16[1] )
              snapX = 1;
            if ( v17[1] == v16[1] && *v17 != *v16 )
              snapY = 1;
            p_x = &Pages[(v14 + 2) >> 4][(v14 + 2) & 0xF].x;
            if ( *p_x == *v17 && p_x[1] != v17[1] )
              snapX = 1;
            if ( p_x[1] == v17[1] && *p_x != *v17 )
              snapY = 1;
            v14 += 4;
            --v34;
          }
          while ( v34 );
          v13 = y;
        }
        if ( v13 < v11 )
        {
          v18 = v13 + start;
          v19 = v11 - v13;
          do
          {
            v20 = &Pages[v18 >> 4][v18 & 0xF].x;
            if ( *v20 == *p_x && v20[1] != p_x[1] )
              snapX = 1;
            if ( v20[1] == p_x[1] && *v20 != *p_x )
              snapY = 1;
            ++v18;
            --v19;
            p_x = v20;
          }
          while ( v19 );
          v11 = numVer;
        }
        if ( snapX && v11 )
        {
          v21 = start;
          do
          {
            v22 = &this->OutVertices.Pages[v21 >> 4][v21 & 0xF];
            x = v22->x;
            if ( x >= 0.0 )
              v24 = v5 + x;
            else
              v24 = x - v5;
            ya = v24;
            yb = floor(ya);
            ++v21;
            --v11;
            v22->x = yb + offsetX;
            v5 = 0.5;
          }
          while ( v11 );
          v11 = numVer;
        }
        if ( snapY && v11 )
        {
          v25 = start;
          do
          {
            p_y = &this->OutVertices.Pages[v25 >> 4][v25 & 0xF].y;
            v27 = *p_y;
            if ( v27 >= 0.0 )
              v28 = v5 + v27;
            else
              v28 = v27 - v5;
            yc = v28;
            yd = floor(yc);
            ++v25;
            --v11;
            *p_y = yd + offsetY;
            v5 = 0.5;
          }
          while ( v11 );
        }
      }
      if ( ++i >= this->OutPaths.Size )
        break;
      v4 = i;
      v3 = this;
    }
  }
}
