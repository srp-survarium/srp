unsigned int __thiscall Scaleform::Render::Hairliner::nextScanbeam(
        Scaleform::Render::Hairliner *this,
        float yb,
        float yt,
        unsigned int startMc,
        unsigned int numMc)
{
  unsigned int v6; // ecx
  unsigned int v7; // eax
  double v8; // st7
  double v9; // st6
  Scaleform::Render::Hairliner::MonoChainType *v10; // ebx
  Scaleform::Render::Hairliner::SrcEdgeType *edge; // ecx
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // edx
  unsigned int flags; // edi
  Scaleform::Render::Hairliner::SrcEdgeType *next; // ecx
  unsigned int lower; // eax
  Scaleform::Render::Hairliner::SrcVertexType **v16; // edx
  float *p_x; // ecx
  double v18; // st7
  Scaleform::Render::Hairliner::SrcVertexType *v19; // edx
  unsigned int v20; // ebp
  unsigned int v21; // eax
  unsigned int upper; // eax
  Scaleform::Render::Hairliner::SrcVertexType *v23; // edx
  float *v24; // ecx
  double v25; // st7
  Scaleform::Render::Hairliner::SrcVertexType *v26; // edx
  unsigned int v27; // ebx
  unsigned int v28; // eax
  Scaleform::Render::Hairliner::MonoChainType *v29; // ecx
  Scaleform::Render::Hairliner::SrcVertexType *v30; // ebx
  double x; // st6
  double v32; // st7
  Scaleform::Render::Hairliner::SrcVertexType *v33; // ebx
  unsigned int v34; // ebx
  bool v35; // zf
  unsigned int Size; // ecx
  unsigned int v37; // edi
  int v38; // edx
  Scaleform::Render::Hairliner::MonoChainType ***v39; // ebx
  Scaleform::Render::Hairliner::MonoChainType *v40; // ebp
  double xt; // st5
  double xb; // st4
  unsigned int v43; // ebp
  unsigned int v44; // ebx
  int v45; // ebx
  unsigned int **v46; // edi
  Scaleform::Render::Hairliner::MonoChainType ***v47; // edx
  int v48; // ebp
  int v49; // ebx
  unsigned int v50; // eax
  Scaleform::Render::Hairliner::MonoChainType *v51; // ecx
  Scaleform::Render::Hairliner::MonoChainType *v52; // edx
  unsigned int v53; // eax
  unsigned int v54; // edi
  unsigned int MaxPages; // eax
  Scaleform::Render::LinearHeap *pHeap; // ecx
  unsigned __int8 *v57; // eax
  double v58; // st5
  double v59; // st5
  unsigned int v60; // ecx
  Scaleform::Render::Hairliner::IntersectionType *v61; // ecx
  unsigned int v62; // eax
  Scaleform::Render::Hairliner::IntersectionType *v63; // eax
  unsigned int **v64; // ecx
  Scaleform::Render::Hairliner::MonoChainType ***v65; // edx
  Scaleform::Render::Hairliner::MonoChainType **v66; // eax
  Scaleform::Render::Hairliner::MonoChainType **v67; // ecx
  Scaleform::Render::Hairliner::MonoChainType *v68; // edx
  unsigned int retFlags; // [esp+10h] [ebp-2Ch]
  unsigned int i; // [esp+14h] [ebp-28h]
  unsigned int ia; // [esp+14h] [ebp-28h]
  unsigned int ib; // [esp+14h] [ebp-28h]
  unsigned int ic; // [esp+14h] [ebp-28h]
  float v75; // [esp+18h] [ebp-24h]
  float v76; // [esp+18h] [ebp-24h]
  float v77; // [esp+18h] [ebp-24h]
  int v78; // [esp+18h] [ebp-24h]
  unsigned __int8 *v79; // [esp+18h] [ebp-24h]
  unsigned int k; // [esp+1Ch] [ebp-20h]
  unsigned int ka; // [esp+1Ch] [ebp-20h]
  unsigned int kb; // [esp+1Ch] [ebp-20h]
  Scaleform::Render::Hairliner::MonoChainType **den; // [esp+20h] [ebp-1Ch]
  float denb; // [esp+20h] [ebp-1Ch]
  float denc; // [esp+20h] [ebp-1Ch]
  unsigned int dena; // [esp+20h] [ebp-1Ch]
  float height; // [esp+24h] [ebp-18h]
  int v88; // [esp+28h] [ebp-14h]
  int v89; // [esp+2Ch] [ebp-10h]
  Scaleform::Render::Hairliner::MonoChainType *in; // [esp+30h] [ebp-Ch]
  Scaleform::Render::Hairliner::MonoChainType *in_4; // [esp+34h] [ebp-8h]
  float in_8; // [esp+38h] [ebp-4h]
  Scaleform::Render::Hairliner::MonoChainType *startMca; // [esp+48h] [ebp+Ch]
  unsigned int startMcb; // [esp+48h] [ebp+Ch]
  unsigned int numMca; // [esp+4Ch] [ebp+10h]

  v6 = numMc;
  v7 = 0;
  retFlags = numMc != 0;
  v8 = yt;
  this->ValidChains.Size = 0;
  v9 = yb;
  i = 0;
  if ( this->ActiveChains.Size )
  {
    do
    {
      v10 = this->ActiveChains.Pages[v7 >> 4][v7 & 0xF];
      v10->flags &= ~2u;
      edge = v10->edge;
      Pages = this->SrcVertices.Pages;
      flags = v10->flags;
      if ( v9 == Pages[v10->edge->upper >> 4][v10->edge->upper & 0xF].y )
      {
        next = edge->next;
        if ( next )
        {
          v10->edge = next;
          lower = next->lower;
          v16 = this->SrcVertices.Pages;
          p_x = &v16[next->upper >> 4][next->upper & 0xF].x;
          v10->xb = v16[lower >> 4][lower & 0xF].x;
          if ( v8 == p_x[1] )
          {
            v18 = *p_x;
          }
          else
          {
            v19 = this->SrcVertices.Pages[v10->edge->lower >> 4];
            v18 = (v8 - v19[v10->edge->lower & 0xF].y) * v10->edge->slope + v19[v10->edge->lower & 0xF].x;
          }
          v75 = v18;
          v10->xt = v75;
          v20 = this->ValidChains.Size >> 4;
          if ( v20 >= this->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
              &this->ValidChains,
              this->ValidChains.Size >> 4);
          v8 = yt;
          v9 = yb;
          v21 = i;
          this->ValidChains.Pages[v20][this->ValidChains.Size++ & 0xF] = i;
          v10->flags |= 2u;
        }
        else
        {
          retFlags |= 2u;
          v21 = i;
          v10->xb = v10->xt;
          v10->flags = flags | 1;
          v10->flags |= 2u;
        }
      }
      else
      {
        upper = edge->upper;
        v23 = Pages[upper >> 4];
        v10->xb = v10->xt;
        v24 = &v23[upper & 0xF].x;
        if ( v8 == v24[1] )
        {
          v25 = *v24;
        }
        else
        {
          v26 = this->SrcVertices.Pages[v10->edge->lower >> 4];
          v25 = (v8 - v26[v10->edge->lower & 0xF].y) * v10->edge->slope + v26[v10->edge->lower & 0xF].x;
        }
        v76 = v25;
        v10->xt = v76;
        v27 = this->ValidChains.Size >> 4;
        if ( v27 >= this->ValidChains.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
            &this->ValidChains,
            this->ValidChains.Size >> 4);
        v8 = yt;
        v9 = yb;
        v21 = i;
        this->ValidChains.Pages[v27][this->ValidChains.Size++ & 0xF] = i;
      }
      v7 = v21 + 1;
      i = v7;
    }
    while ( v7 < this->ActiveChains.Size );
    v6 = numMc;
  }
  if ( v6 )
  {
    v28 = startMc;
    ia = startMc;
    k = v6;
    do
    {
      v29 = this->MonoChainsSorted.Pages[v28 >> 4][v28 & 0xF];
      v30 = &this->SrcVertices.Pages[v29->edge->lower >> 4][v29->edge->lower & 0xF];
      x = v30->x;
      v29->flags = 2;
      v29->xb = x;
      if ( v8 == v30->y )
      {
        v32 = v30->x;
      }
      else
      {
        v33 = this->SrcVertices.Pages[v29->edge->lower >> 4];
        v32 = (v8 - v33[v29->edge->lower & 0xF].y) * v29->edge->slope + v33[v29->edge->lower & 0xF].x;
      }
      v77 = v32;
      v29->xt = v77;
      v34 = this->ActiveChains.Size >> 4;
      if ( v34 >= this->ActiveChains.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType *,4,8> *)&this->ActiveChains,
          this->ActiveChains.Size >> 4);
      v8 = yt;
      this->ActiveChains.Pages[v34][this->ActiveChains.Size++ & 0xF] = 0;
      v28 = ia + 1;
      v35 = k-- == 1;
      ++ia;
    }
    while ( !v35 );
    v9 = yb;
    Size = this->ActiveChains.Size;
    v37 = Size - numMc;
    v38 = numMc + startMc;
    ka = Size - numMc;
    v78 = numMc + startMc;
    ib = Size - numMc - 1;
    while ( 1 )
    {
      if ( v37
        && ((v39 = this->ActiveChains.Pages,
             startMca = this->MonoChainsSorted.Pages[(unsigned int)(v38 - 1) >> 4][((_BYTE)v38 - 1) & 0xF],
             v40 = v39[ib >> 4][ib & 0xF],
             startMca->xb == v40->xb)
          ? (xt = v40->xt, xb = startMca->xt)
          : (xt = v40->xb, xb = startMca->xb),
            xb <= xt) )
      {
        --ib;
        --Size;
        ka = v37 - 1;
        v39[Size >> 4][Size & 0xF] = v39[(v37 - 1) >> 4][(v37 - 1) & 0xF];
      }
      else
      {
        --numMc;
        --Size;
        v78 = v38 - 1;
        this->ActiveChains.Pages[Size >> 4][Size & 0xF] = this->MonoChainsSorted.Pages[(unsigned int)(v38 - 1) >> 4][(v38 - 1) & 0xF];
      }
      if ( !numMc )
        break;
      v38 = v78;
      v37 = ka;
    }
  }
  v43 = 0;
  this->Intersections.Size = 0;
  if ( (retFlags & 1) != 0 )
  {
    this->ValidChains.Size = 0;
    if ( this->ActiveChains.Size )
    {
      do
      {
        if ( (this->ActiveChains.Pages[v43 >> 4][v43 & 0xF]->flags & 1) == 0 )
        {
          v44 = this->ValidChains.Size >> 4;
          if ( v44 >= this->ValidChains.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
              &this->ValidChains,
              this->ValidChains.Size >> 4);
          v8 = yt;
          v9 = yb;
          this->ValidChains.Pages[v44][this->ValidChains.Size++ & 0xF] = v43;
        }
        ++v43;
      }
      while ( v43 < this->ActiveChains.Size );
    }
  }
  height = v8 - v9;
  if ( this->ValidChains.Size > 1 )
  {
    v45 = 0;
    ic = 0;
    do
    {
      numMca = v45;
      if ( v45 >= 0 )
      {
        startMcb = v45 + 1;
        while ( 1 )
        {
          v46 = this->ValidChains.Pages;
          v47 = this->ActiveChains.Pages;
          v48 = (unsigned int)v45 >> 4;
          v49 = v45 & 0xF;
          in = v47[v46[v48][v49] >> 4][v46[v48][v49] & 0xF];
          v88 = startMcb >> 4;
          v50 = v46[v88][startMcb & 0xF];
          v89 = startMcb & 0xF;
          v51 = v47[v50 >> 4][v50 & 0xF];
          v52 = in;
          in_4 = v51;
          if ( v51->xt >= (double)in->xt )
            break;
          v53 = 0;
          if ( !this->Intersections.Size )
          {
            this->ChainsAtBottom.Size = 0;
            kb = 0;
            if ( this->ActiveChains.Size )
            {
              do
              {
                v54 = this->ChainsAtBottom.Size >> 4;
                den = &this->ActiveChains.Pages[v53 >> 4][v53 & 0xF];
                if ( v54 >= this->ChainsAtBottom.NumPages )
                {
                  MaxPages = this->ChainsAtBottom.MaxPages;
                  if ( v54 >= MaxPages )
                  {
                    pHeap = this->ChainsAtBottom.pHeap;
                    if ( this->ChainsAtBottom.Pages )
                    {
                      v79 = Scaleform::Render::LinearHeap::Alloc(pHeap, 8 * MaxPages);
                      memcpy(v79, (unsigned __int8 *)this->ChainsAtBottom.Pages, 4 * this->ChainsAtBottom.NumPages);
                      v57 = v79;
                      this->ChainsAtBottom.MaxPages *= 2;
                    }
                    else
                    {
                      this->ChainsAtBottom.MaxPages = 8;
                      v57 = Scaleform::Render::LinearHeap::Alloc(pHeap, 0x20u);
                    }
                    this->ChainsAtBottom.Pages = (Scaleform::Render::Hairliner::MonoChainType ***)v57;
                  }
                  this->ChainsAtBottom.Pages[v54] = (Scaleform::Render::Hairliner::MonoChainType **)Scaleform::Render::LinearHeap::Alloc(this->ChainsAtBottom.pHeap, 0x40u);
                  ++this->ChainsAtBottom.NumPages;
                  v53 = kb;
                }
                this->ChainsAtBottom.Pages[v54][this->ChainsAtBottom.Size++ & 0xF] = *den;
                kb = ++v53;
              }
              while ( v53 < this->ActiveChains.Size );
              v8 = yt;
              v52 = in;
              v9 = yb;
              v51 = in_4;
            }
          }
          denb = v51->xt - v51->xb - v52->xt + v52->xb;
          v58 = denb;
          if ( denb == 0.0 )
          {
            v59 = v9;
          }
          else
          {
            denc = v52->xb - v51->xb;
            v59 = denc * height / v58 + v9;
          }
          in_8 = v59;
          if ( in_8 < v9 )
            in_8 = v9;
          if ( in_8 > v8 )
            in_8 = v8;
          v60 = this->Intersections.Size >> 4;
          dena = v60;
          if ( v60 >= this->Intersections.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::IntersectionType,4,4>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::IntersectionType,4,4> *)&this->Intersections,
              v60);
            v60 = dena;
          }
          v8 = yt;
          v9 = yb;
          v61 = this->Intersections.Pages[v60];
          v62 = this->Intersections.Size & 0xF;
          v61[v62].mc1 = in;
          v63 = &v61[v62];
          v63->mc2 = in_4;
          v63->y = in_8;
          ++this->Intersections.Size;
          v64 = this->ValidChains.Pages;
          v65 = this->ActiveChains.Pages;
          --startMcb;
          v66 = &v65[v64[v88][v89] >> 4][v64[v88][v89] & 0xF];
          v67 = &v65[v64[v48][v49] >> 4][v64[v48][v49] & 0xF];
          v68 = *v67;
          *v67 = *v66;
          *v66 = v68;
          if ( (--numMca & 0x80000000) != 0 )
            break;
          v45 = numMca;
        }
        v45 = ic;
      }
      ic = ++v45;
    }
    while ( v45 + 1 < this->ValidChains.Size );
  }
  return retFlags;
}
