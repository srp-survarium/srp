void __thiscall Scaleform::Render::Hairliner::decomposePath(
        Scaleform::Render::Hairliner *this,
        const Scaleform::Render::Hairliner::PathType *path)
{
  Scaleform::Render::Hairliner *v2; // ebp
  signed int start; // esi
  signed int end; // eax
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
  int v20; // edi
  int v21; // ecx
  unsigned int i; // edx
  signed int v23; // ebx
  signed int v24; // ecx
  unsigned int v25; // edi
  unsigned int j; // edx
  unsigned int v27; // [esp+10h] [ebp-28h]
  float numEdges; // [esp+14h] [ebp-24h]
  unsigned int numEdgesa; // [esp+14h] [ebp-24h]
  unsigned int numEdgesb; // [esp+14h] [ebp-24h]
  unsigned int numEdgesc; // [esp+14h] [ebp-24h]
  signed int v32; // [esp+18h] [ebp-20h]
  float v33; // [esp+1Ch] [ebp-1Ch]
  float v35; // [esp+24h] [ebp-14h]
  float v36; // [esp+28h] [ebp-10h]
  float v37; // [esp+2Ch] [ebp-Ch]
  int v38; // [esp+3Ch] [ebp+4h]

  v2 = this;
  start = path->start;
  end = path->end;
  p_Scanbeams = &this->Scanbeams;
  v6 = this->Scanbeams.Size >> 4;
  numEdges = this->SrcVertices.Pages[path->start >> 4][path->start & 0xF].y;
  v27 = path->start;
  v38 = end;
  if ( v6 >= this->Scanbeams.NumPages )
  {
    Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(&this->Scanbeams, v6);
    end = v38;
  }
  v2->Scanbeams.Pages[v6][v2->Scanbeams.Size++ & 0xF] = start;
  v7 = start + 1;
  if ( start + 1 <= (unsigned int)end )
  {
    v8 = start;
    v32 = start;
    do
    {
      Pages = v2->SrcVertices.Pages;
      p_x = &Pages[v8 >> 4][v8 & 0xF].x;
      v11 = Pages[v7 >> 4];
      v12 = v7 & 0xF;
      y = v11[v12].y;
      v14 = &v11[v12].x;
      if ( numEdges == y )
      {
        if ( *v14 != *p_x )
        {
          v35 = *p_x;
          v36 = *v14;
          v37 = v14[1];
          if ( v36 < (double)v35 )
          {
            v33 = v35;
            v35 = v36;
            v36 = v33;
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
          v19->x1 = v35;
          v19->x2 = v36;
          v19->y = v37;
          v19->lv = -1;
          v19->rv = -1;
          ++p_HorizontalEdges->Size;
        }
      }
      else
      {
        v15 = p_Scanbeams->Size >> 4;
        numEdgesa = v15;
        if ( v15 >= p_Scanbeams->NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(p_Scanbeams, v15);
          v15 = numEdgesa;
        }
        p_Scanbeams->Pages[v15][p_Scanbeams->Size++ & 0xF] = v7;
        numEdges = v14[1];
      }
      ++v7;
      v8 = ++v32;
    }
    while ( v7 <= v38 );
    start = v27;
    end = v38;
  }
  v20 = start;
  if ( start < end )
  {
    do
    {
      if ( (unsigned __int8)Scaleform::Render::Hairliner::forwardMin(v2, v20, start) )
      {
        v21 = v20 + 1;
        numEdgesb = 1;
        for ( i = v20 + 2; v21 < v38; ++i )
        {
          start = v27;
          if ( v2->SrcVertices.Pages[(unsigned int)v21 >> 4][v21 & 0xF].y >= (double)v2->SrcVertices.Pages[i >> 4][i & 0xF].y )
            break;
          ++numEdgesb;
          ++v21;
        }
        Scaleform::Render::Hairliner::buildEdgeList(v2, v20, numEdgesb, 1);
        v20 = v20 + numEdgesb - 1;
      }
      ++v20;
    }
    while ( v20 < v38 );
    end = v38;
  }
  v23 = end;
  numEdgesc = end;
  if ( end > start )
  {
    while ( 1 )
    {
      if ( (unsigned __int8)Scaleform::Render::Hairliner::reverseMin(v2, v23, end) )
      {
        v24 = v23 - 1;
        v25 = 1;
        for ( j = v23 - 2; v24 > start; --j )
        {
          start = v27;
          v23 = numEdgesc;
          if ( v2->SrcVertices.Pages[(unsigned int)v24 >> 4][v24 & 0xF].y >= (double)v2->SrcVertices.Pages[j >> 4][j & 0xF].y )
            break;
          ++v25;
          --v24;
        }
        Scaleform::Render::Hairliner::buildEdgeList(v2, v23, v25, -1);
        v23 += 1 - v25;
      }
      numEdgesc = --v23;
      if ( v23 <= start )
        break;
      end = v38;
    }
  }
}
