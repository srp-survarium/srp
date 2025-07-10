void __thiscall Scaleform::Render::Hairliner::decomposePath(Scaleform::Render::Hairliner *this, int path)
{
  Scaleform::Render::Hairliner *v2; // ebp
  signed int v3; // esi
  signed int v4; // eax
  Scaleform::Render::ArrayPaged<unsigned int,4,16> *p_Scanbeams; // edi
  unsigned int v6; // ebx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // eax
  float *p_x; // ecx
  Scaleform::Render::Hairliner::SrcVertexType *v11; // eax
  int v12; // esi
  double y; // st7
  float *v14; // esi
  unsigned int v15; // eax
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4> *p_HorizontalEdges; // esi
  unsigned int v17; // ebp
  Scaleform::Render::Hairliner::HorizontalEdgeType *v18; // eax
  Scaleform::Render::Hairliner::HorizontalEdgeType *v19; // eax
  signed int v20; // edi
  int v21; // ecx
  unsigned int i; // edx
  signed int v23; // ebx
  signed int v24; // ecx
  unsigned int v25; // edi
  unsigned int j; // edx
  unsigned int start; // [esp+10h] [ebp-28h]
  int min; // [esp+14h] [ebp-24h]
  int mina; // [esp+14h] [ebp-24h]
  unsigned int minb; // [esp+14h] [ebp-24h]
  int minc; // [esp+14h] [ebp-24h]
  signed int v32; // [esp+18h] [ebp-20h]
  float v33; // [esp+1Ch] [ebp-1Ch]
  float he; // [esp+24h] [ebp-14h]
  float he_4; // [esp+28h] [ebp-10h]
  float he_8; // [esp+2Ch] [ebp-Ch]
  int end; // [esp+3Ch] [ebp+4h]

  v2 = this;
  v3 = *(_DWORD *)path;
  v4 = *(_DWORD *)(path + 4);
  p_Scanbeams = &this->Scanbeams;
  v6 = this->Scanbeams.Size >> 4;
  min = SLODWORD(this->SrcVertices.Pages[*(_DWORD *)path >> 4][*(_DWORD *)path & 0xF].y);
  start = *(_DWORD *)path;
  end = v4;
  if ( v6 >= this->Scanbeams.NumPages )
  {
    Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(&this->Scanbeams, v6);
    v4 = end;
  }
  v2->Scanbeams.Pages[v6][v2->Scanbeams.Size++ & 0xF] = v3;
  v7 = v3 + 1;
  if ( v3 + 1 <= (unsigned int)v4 )
  {
    v8 = v3;
    v32 = v3;
    do
    {
      Pages = v2->SrcVertices.Pages;
      p_x = &Pages[v8 >> 4][v8 & 0xF].x;
      v11 = Pages[v7 >> 4];
      v12 = v7 & 0xF;
      y = v11[v12].y;
      v14 = &v11[v12].x;
      if ( *(float *)&min == y )
      {
        if ( *v14 != *p_x )
        {
          he = *p_x;
          he_4 = *v14;
          he_8 = v14[1];
          if ( he_4 < (double)he )
          {
            v33 = he;
            he = he_4;
            he_4 = v33;
          }
          p_HorizontalEdges = &v2->HorizontalEdges;
          v17 = v2->HorizontalEdges.Size >> 2;
          if ( v17 >= p_HorizontalEdges->NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::HorizontalEdgeType,2,4>::allocPage(
              p_HorizontalEdges,
              v17);
          v18 = p_HorizontalEdges->Pages[v17];
          v2 = this;
          v19 = &v18[p_HorizontalEdges->Size & 3];
          v19->x1 = he;
          v19->x2 = he_4;
          v19->y = he_8;
          v19->lv = -1;
          v19->rv = -1;
          ++p_HorizontalEdges->Size;
        }
      }
      else
      {
        v15 = p_Scanbeams->Size >> 4;
        mina = v15;
        if ( v15 >= p_Scanbeams->NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(p_Scanbeams, v15);
          v15 = mina;
        }
        p_Scanbeams->Pages[v15][p_Scanbeams->Size++ & 0xF] = v7;
        min = *((int *)v14 + 1);
      }
      ++v7;
      v8 = ++v32;
    }
    while ( v7 <= end );
    v3 = start;
    v4 = end;
  }
  v20 = v3;
  if ( v3 < v4 )
  {
    do
    {
      if ( (unsigned __int8)Scaleform::Render::Hairliner::forwardMin(v2, v20, v3) )
      {
        v21 = v20 + 1;
        minb = 1;
        for ( i = v20 + 2; v21 < end; ++i )
        {
          v3 = start;
          if ( v2->SrcVertices.Pages[(unsigned int)v21 >> 4][v21 & 0xF].y >= (double)v2->SrcVertices.Pages[i >> 4][i & 0xF].y )
            break;
          ++minb;
          ++v21;
        }
        Scaleform::Render::Hairliner::buildEdgeList(v2, v20, minb, 1);
        v20 = v20 + minb - 1;
      }
      ++v20;
    }
    while ( v20 < end );
    v4 = end;
  }
  v23 = v4;
  minc = v4;
  if ( v4 > v3 )
  {
    while ( 1 )
    {
      if ( (unsigned __int8)Scaleform::Render::Hairliner::reverseMin(v2, v23, v4) )
      {
        v24 = v23 - 1;
        v25 = 1;
        for ( j = v23 - 2; v24 > v3; --j )
        {
          v3 = start;
          v23 = minc;
          if ( v2->SrcVertices.Pages[(unsigned int)v24 >> 4][v24 & 0xF].y >= (double)v2->SrcVertices.Pages[j >> 4][j & 0xF].y )
            break;
          ++v25;
          --v24;
        }
        Scaleform::Render::Hairliner::buildEdgeList(v2, v23, v25, -1);
        v23 += 1 - v25;
      }
      minc = --v23;
      if ( v23 <= v3 )
        break;
      v4 = end;
    }
  }
}
