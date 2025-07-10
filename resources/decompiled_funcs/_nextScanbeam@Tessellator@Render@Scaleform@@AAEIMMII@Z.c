unsigned int __thiscall Scaleform::Render::Tessellator::nextScanbeam(
        Scaleform::Render::Tessellator *this,
        float yb,
        float yt,
        unsigned int startMc,
        unsigned int numMc)
{
  unsigned int v5; // ebx
  unsigned int v6; // eax
  double v8; // st7
  double v9; // st6
  Scaleform::Render::Tessellator::MonoChainType *v10; // ebp
  unsigned int edge; // edx
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // edi
  unsigned int v13; // ecx
  char v14; // al
  Scaleform::Render::Tessellator::EdgeType *v15; // ecx
  Scaleform::Render::Tessellator::SrcVertexType **v16; // edx
  Scaleform::Render::Tessellator::EdgeType *v17; // edi
  float *p_x; // ecx
  double v19; // st5
  Scaleform::Render::Tessellator::SrcVertexType *v20; // ecx
  unsigned int v21; // ebx
  unsigned int v22; // eax
  Scaleform::Render::Tessellator::SrcVertexType *v23; // edx
  int v24; // ecx
  double v25; // st5
  float *v26; // ecx
  double v27; // st5
  Scaleform::Render::Tessellator::SrcVertexType *v28; // edx
  unsigned int v29; // ebx
  Scaleform::Render::Tessellator::MonoChainType *v30; // edx
  Scaleform::Render::Tessellator::SrcVertexType **v31; // ebx
  unsigned int lower; // ecx
  float *v33; // ebp
  double v34; // st5
  Scaleform::Render::Tessellator::SrcVertexType *v35; // ebx
  unsigned int v36; // ebx
  unsigned int v37; // ebx
  unsigned int Size; // ecx
  int v39; // edx
  unsigned int v40; // eax
  unsigned int v41; // ebp
  Scaleform::Render::Tessellator::MonoChainType ***v42; // edi
  Scaleform::Render::Tessellator::MonoChainType *v43; // ebp
  double xt; // st5
  double v45; // st4
  unsigned int v46; // ebp
  unsigned int v47; // ebx
  int v48; // eax
  unsigned int **v49; // edx
  Scaleform::Render::Tessellator::MonoChainType ***v50; // edi
  int v51; // ebp
  int v52; // ebx
  unsigned int v53; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v54; // edi
  Scaleform::Render::Tessellator::MonoChainType *v55; // ecx
  double v56; // st5
  double v57; // st5
  unsigned int v58; // ecx
  Scaleform::Render::Tessellator::IntersectionType *v59; // ecx
  unsigned int v60; // eax
  Scaleform::Render::Tessellator::IntersectionType *v61; // eax
  unsigned int **v62; // ecx
  Scaleform::Render::Tessellator::MonoChainType ***v63; // edx
  Scaleform::Render::Tessellator::MonoChainType **v64; // eax
  Scaleform::Render::Tessellator::MonoChainType **v65; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v66; // edx
  unsigned int k; // edi
  unsigned int v68; // ecx
  int v69; // edx
  float *p_y; // ebx
  double v71; // st6
  double v72; // st7
  unsigned int retFlags; // [esp+Ch] [ebp-24h]
  unsigned int i; // [esp+10h] [ebp-20h]
  unsigned int ia; // [esp+10h] [ebp-20h]
  unsigned int ib; // [esp+10h] [ebp-20h]
  unsigned int ic; // [esp+10h] [ebp-20h]
  Scaleform::Render::Tessellator::EdgeType *height; // [esp+14h] [ebp-1Ch]
  Scaleform::Render::Tessellator::EdgeType *heighta; // [esp+14h] [ebp-1Ch]
  unsigned int heightb; // [esp+14h] [ebp-1Ch]
  float heightc; // [esp+14h] [ebp-1Ch]
  float v83; // [esp+18h] [ebp-18h]
  float v84; // [esp+18h] [ebp-18h]
  float v85; // [esp+18h] [ebp-18h]
  unsigned int v86; // [esp+18h] [ebp-18h]
  int v87; // [esp+18h] [ebp-18h]
  unsigned __int16 den; // [esp+1Ch] [ebp-14h]
  unsigned int dena; // [esp+1Ch] [ebp-14h]
  Scaleform::Render::Tessellator::MonoChainType *denb; // [esp+1Ch] [ebp-14h]
  float dend; // [esp+1Ch] [ebp-14h]
  float dene; // [esp+1Ch] [ebp-14h]
  unsigned int denc; // [esp+1Ch] [ebp-14h]
  int v94; // [esp+20h] [ebp-10h]
  unsigned int intr; // [esp+24h] [ebp-Ch]
  unsigned int intr_4; // [esp+28h] [ebp-8h]
  float intr_8; // [esp+2Ch] [ebp-4h]
  float y; // [esp+34h] [ebp+4h]
  unsigned int j; // [esp+3Ch] [ebp+Ch]
  unsigned int ja; // [esp+3Ch] [ebp+Ch]
  unsigned int numMca; // [esp+40h] [ebp+10h]

  v5 = numMc;
  v6 = 0;
  retFlags = numMc != 0;
  v8 = yt;
  v9 = yb;
  this->ValidChains.Size = 0;
  i = 0;
  if ( this->ActiveChains.Size )
  {
    do
    {
      v10 = this->ActiveChains.Pages[v6 >> 4][v6 & 0xF];
      v10->flags &= ~8u;
      edge = v10->edge;
      den = v10->flags;
      Pages = this->SrcVertices.Pages;
      height = &this->Edges.Pages[v10->edge >> 4][v10->edge & 0xF];
      v13 = height->lower + v10->dir;
      if ( v9 == Pages[v13 >> 4][v13 & 0xF].y )
      {
        if ( edge >= v10->end )
        {
          retFlags |= 2u;
          v10->xb = v10->xt;
          v10->flags = den | 2;
          v22 = i;
          v10->flags |= 8u;
        }
        else
        {
          v14 = edge + 1;
          v10->edge = edge + 1;
          v15 = this->Edges.Pages[(edge + 1) >> 4];
          v16 = this->SrcVertices.Pages;
          v17 = &v15[v14 & 0xF];
          p_x = &v16[(v17->lower + v10->dir) >> 4][(v17->lower + v10->dir) & 0xF].x;
          v10->xb = v16[v17->lower >> 4][v17->lower & 0xF].x;
          if ( v8 == p_x[1] )
          {
            v19 = *p_x;
          }
          else
          {
            v20 = this->SrcVertices.Pages[v17->lower >> 4];
            v19 = (v8 - v20[v17->lower & 0xF].y) * v17->slope + v20[v17->lower & 0xF].x;
          }
          v83 = v19;
          v10->xt = v83;
          v21 = this->ValidChains.Size >> 4;
          if ( v21 >= this->ValidChains.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
              &this->ValidChains,
              this->ValidChains.Size >> 4);
            v8 = yt;
            v9 = yb;
          }
          v22 = i;
          this->ValidChains.Pages[v21][this->ValidChains.Size++ & 0xF] = i;
          v10->flags |= 8u;
        }
      }
      else
      {
        v23 = Pages[v13 >> 4];
        v10->xb = v10->xt;
        v24 = v13 & 0xF;
        v25 = v23[v24].y;
        v26 = &v23[v24].x;
        if ( v8 == v25 )
        {
          v27 = *v26;
        }
        else
        {
          v28 = this->SrcVertices.Pages[height->lower >> 4];
          v27 = (v8 - v28[height->lower & 0xF].y) * height->slope + v28[height->lower & 0xF].x;
        }
        v84 = v27;
        v10->xt = v84;
        v29 = this->ValidChains.Size >> 4;
        if ( v29 >= this->ValidChains.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
            &this->ValidChains,
            this->ValidChains.Size >> 4);
          v8 = yt;
          v9 = yb;
        }
        v22 = i;
        this->ValidChains.Pages[v29][this->ValidChains.Size++ & 0xF] = i;
      }
      v6 = v22 + 1;
      i = v6;
    }
    while ( v6 < this->ActiveChains.Size );
    v5 = numMc;
  }
  if ( v5 )
  {
    ia = startMc;
    dena = v5;
    do
    {
      v30 = this->MonoChainsSorted.Array[ia];
      v31 = this->SrcVertices.Pages;
      lower = this->Edges.Pages[v30->edge >> 4][v30->edge & 0xF].lower;
      heighta = &this->Edges.Pages[v30->edge >> 4][v30->edge & 0xF];
      v33 = &v31[(lower + v30->dir) >> 4][(lower + v30->dir) & 0xF].x;
      v30->xb = v31[lower >> 4][lower & 0xF].x;
      v30->flags = 8;
      if ( v8 == v33[1] )
      {
        v34 = *v33;
      }
      else
      {
        v35 = this->SrcVertices.Pages[heighta->lower >> 4];
        v34 = (v8 - v35[heighta->lower & 0xF].y) * heighta->slope + v35[heighta->lower & 0xF].x;
      }
      v85 = v34;
      v30->xt = v85;
      v36 = this->ActiveChains.Size >> 4;
      if ( v36 >= this->ActiveChains.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->ActiveChains,
          this->ActiveChains.Size >> 4);
        v8 = yt;
        v9 = yb;
      }
      ++ia;
      this->ActiveChains.Pages[v36][this->ActiveChains.Size++ & 0xF] = 0;
      --dena;
    }
    while ( dena );
    v37 = numMc;
    Size = this->ActiveChains.Size;
    v39 = Size - numMc;
    v40 = 4 * (numMc + startMc);
    v41 = Size - numMc - 1;
    v86 = v40;
    heightb = v41;
    ib = v40;
    while ( 1 )
    {
      if ( v39
        && ((v42 = this->ActiveChains.Pages,
             j = *(unsigned int *)((char *)this->MonoChainsSorted.Array + v40 - 4),
             v43 = v42[v41 >> 4][v41 & 0xF],
             *(float *)(j + 12) == v43->xb)
          ? (xt = v43->xt, v45 = *(float *)(j + 16))
          : (xt = v43->xb, v45 = *(float *)(j + 12)),
            v45 <= xt) )
      {
        --heightb;
        --Size;
        v42[Size >> 4][Size & 0xF] = v42[(unsigned int)(v39 - 1) >> 4][(v39 - 1) & 0xF];
        --v39;
      }
      else
      {
        --Size;
        numMc = v37 - 1;
        ib -= 4;
        v86 = ib;
        this->ActiveChains.Pages[Size >> 4][Size & 0xF] = *(Scaleform::Render::Tessellator::MonoChainType **)((char *)this->MonoChainsSorted.Array + ib);
      }
      v37 = numMc;
      v40 = v86;
      if ( !numMc )
        break;
      v41 = heightb;
    }
  }
  v46 = 0;
  this->Intersections.Size = 0;
  if ( (retFlags & 1) != 0 )
  {
    this->ValidChains.Size = 0;
    if ( this->ActiveChains.Size )
    {
      do
      {
        if ( (this->ActiveChains.Pages[v46 >> 4][v46 & 0xF]->flags & 2) == 0 )
        {
          v47 = this->ValidChains.Size >> 4;
          if ( v47 >= this->ValidChains.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
              &this->ValidChains,
              this->ValidChains.Size >> 4);
            v8 = yt;
            v9 = yb;
          }
          this->ValidChains.Pages[v47][this->ValidChains.Size++ & 0xF] = v46;
        }
        ++v46;
      }
      while ( v46 < this->ActiveChains.Size );
    }
  }
  heightc = v8 - v9;
  if ( this->ValidChains.Size > 1 )
  {
    v48 = 0;
    v87 = 0;
    do
    {
      numMca = v48;
      if ( v48 >= 0 )
      {
        ja = v48 + 1;
        while ( 1 )
        {
          v49 = this->ValidChains.Pages;
          v50 = this->ActiveChains.Pages;
          v51 = (unsigned int)v48 >> 4;
          v52 = v48 & 0xF;
          denb = v50[v49[v51][v52] >> 4][v49[v51][v52] & 0xF];
          v94 = ja & 0xF;
          v53 = v49[ja >> 4][v94];
          ic = ja >> 4;
          v54 = v50[v53 >> 4][v53 & 0xF];
          v55 = denb;
          if ( v54->xt >= (double)denb->xt )
            break;
          if ( !this->Intersections.Size )
          {
            Scaleform::Render::Tessellator::setupIntersections(this);
            v55 = denb;
            v9 = yb;
            v8 = yt;
          }
          intr = v55->posIntr;
          intr_4 = v54->posIntr;
          dend = v54->xt - v54->xb - v55->xt + v55->xb;
          v56 = dend;
          if ( dend == 0.0 )
          {
            v57 = v9;
          }
          else
          {
            dene = v55->xb - v54->xb;
            v57 = dene * heightc / v56 + v9;
          }
          intr_8 = v57;
          if ( intr_8 < v9 )
            intr_8 = v9;
          if ( intr_8 > v8 )
            intr_8 = v8;
          v58 = this->Intersections.Size >> 4;
          denc = v58;
          if ( v58 >= this->Intersections.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::IntersectionType,4,4>::allocPage(
              &this->Intersections,
              v58);
            v58 = denc;
            v9 = yb;
            v8 = yt;
          }
          v59 = this->Intersections.Pages[v58];
          v60 = this->Intersections.Size & 0xF;
          v59[v60].pos1 = intr;
          v61 = &v59[v60];
          v61->pos2 = intr_4;
          v61->y = intr_8;
          ++this->Intersections.Size;
          v62 = this->ValidChains.Pages;
          v63 = this->ActiveChains.Pages;
          --ja;
          v64 = &v63[v62[ic][v94] >> 4][v62[ic][v94] & 0xF];
          v65 = &v63[v62[v51][v52] >> 4][v62[v51][v52] & 0xF];
          v66 = *v65;
          *v65 = *v64;
          *v64 = v66;
          if ( (--numMca & 0x80000000) != 0 )
            break;
          v48 = numMca;
        }
        v48 = v87;
      }
      v87 = ++v48;
    }
    while ( v48 + 1 < this->ValidChains.Size );
  }
  if ( this->Intersections.Size > 1 )
  {
    Scaleform::Alg::InsertionSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4>,bool (__cdecl *)(Scaleform::Render::Tessellator::IntersectionType const &,Scaleform::Render::Tessellator::IntersectionType const &)>(
      &this->Intersections,
      0,
      this->Intersections.Size,
      (bool (__cdecl *)(const Scaleform::Render::Tessellator::IntersectionType *, const Scaleform::Render::Tessellator::IntersectionType *))Scaleform::Render::Scale9GridTess::cmpSlopes);
    if ( this->HasEpsilon )
    {
      for ( k = 0; k < this->Intersections.Size; yb = this->Intersections.Pages[v68][v69].y )
      {
        v68 = k >> 4;
        v69 = k & 0xF;
        p_y = &this->Intersections.Pages[v68][v69].y;
        v71 = yb;
        v72 = *p_y - yb;
        y = fabs(yb);
        if ( y * this->Epsilon > v72 )
          *p_y = v71;
        ++k;
      }
    }
  }
  return retFlags;
}
