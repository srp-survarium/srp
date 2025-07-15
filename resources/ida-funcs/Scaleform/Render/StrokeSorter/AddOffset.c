void __thiscall Scaleform::Render::StrokeSorter::AddOffset(
        Scaleform::Render::StrokeSorter *this,
        float offsetX,
        float offsetY)
{
  unsigned int v3; // esi
  double v4; // st7
  double v5; // st6
  Scaleform::Render::StrokeSorter::PathType *v6; // eax
  int v7; // edi
  unsigned int numVer; // ebp
  unsigned int start; // eax
  int v10; // ebp
  unsigned int v11; // edx
  unsigned int v12; // eax
  unsigned int v13; // ebx
  unsigned int v14; // edx
  int v15; // esi
  Scaleform::Render::StrokeSorter::VertexType *v16; // edx
  double y; // st5
  float *p_y; // edx
  int v19; // esi
  unsigned int v20; // edx
  unsigned int v21; // esi
  int v22; // edx
  unsigned int v23; // esi
  int v24; // edx
  unsigned int v25; // esi
  unsigned int v26; // ebp
  unsigned int v27; // eax
  int v28; // edx
  unsigned int v29; // [esp+4h] [ebp-4h]
  unsigned int v30; // [esp+Ch] [ebp+4h]
  int v31; // [esp+10h] [ebp+8h]

  v3 = 0;
  v29 = 0;
  if ( this->OutPaths.Size )
  {
    v4 = offsetY;
    v5 = offsetX;
    do
    {
      v6 = this->OutPaths.Pages[v3 >> 4];
      v7 = v3 & 0xF;
      numVer = v6[v7].numVer;
      start = v6[v7].start;
      v10 = numVer & 0xFFFFFFF;
      v11 = 0;
      v30 = start;
      if ( v10 >= 4 )
      {
        v12 = start + 1;
        v13 = ((unsigned int)(v10 - 4) >> 2) + 1;
        v31 = 4 * v13;
        do
        {
          v14 = (v12 - 1) >> 4;
          v15 = ((_BYTE)v12 - 1) & 0xF;
          this->OutVertices.Pages[v14][v15].x = this->OutVertices.Pages[v14][v15].x + v5;
          v16 = this->OutVertices.Pages[v14];
          y = v16[v15].y;
          p_y = &v16[v15].y;
          v19 = v12 & 0xF;
          *p_y = y + v4;
          v20 = v12 >> 4;
          this->OutVertices.Pages[v20][v19].x = this->OutVertices.Pages[v20][v19].x + v5;
          this->OutVertices.Pages[v20][v19].y = this->OutVertices.Pages[v20][v19].y + v4;
          v21 = (v12 + 1) >> 4;
          v22 = (v12 + 1) & 0xF;
          this->OutVertices.Pages[v21][v22].x = this->OutVertices.Pages[v21][v22].x + v5;
          this->OutVertices.Pages[v21][v22].y = this->OutVertices.Pages[v21][v22].y + v4;
          v23 = (v12 + 2) >> 4;
          v24 = (v12 + 2) & 0xF;
          v12 += 4;
          --v13;
          this->OutVertices.Pages[v23][v24].x = this->OutVertices.Pages[v23][v24].x + v5;
          this->OutVertices.Pages[v23][v24].y = this->OutVertices.Pages[v23][v24].y + v4;
        }
        while ( v13 );
        v11 = v31;
        start = v30;
        v3 = v29;
      }
      if ( v11 < v10 )
      {
        v25 = v11 + start;
        v26 = v10 - v11;
        do
        {
          v27 = v25 >> 4;
          v28 = v25++ & 0xF;
          --v26;
          this->OutVertices.Pages[v27][v28].x = this->OutVertices.Pages[v27][v28].x + v5;
          this->OutVertices.Pages[v27][v28].y = this->OutVertices.Pages[v27][v28].y + v4;
        }
        while ( v26 );
        v3 = v29;
      }
      v29 = ++v3;
    }
    while ( v3 < this->OutPaths.Size );
  }
}
