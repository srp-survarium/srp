void __thiscall Scaleform::Render::Tessellator::connectPendingToRight(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        unsigned int targetVertex)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // eax
  unsigned int style; // esi
  Scaleform::Render::Tessellator::BaseLineType *v6; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v7; // esi
  unsigned int numChains; // edx
  unsigned int firstChain; // eax
  unsigned int vertexRight; // ecx
  Scaleform::Render::Tessellator::PendingEndType *v11; // edx
  unsigned int vertex; // ecx
  unsigned int v13; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v14; // ecx
  unsigned int v15; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v16; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v17; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v18; // ebp
  unsigned int lastIdx; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v20; // esi
  bool v21; // zf
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // ebx
  unsigned int v23; // ebp
  Scaleform::Render::Tessellator::MonoVertexType *v24; // eax
  unsigned int aaVer; // edx
  Scaleform::Render::Tessellator::MonoVertexType *next; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v27; // ebp
  unsigned int v28; // ecx
  Scaleform::Render::Tessellator::PendingEndType **Pages; // edx
  unsigned int v30; // ebp
  unsigned int v31; // ecx
  Scaleform::Render::Tessellator::PendingEndType *v32; // esi
  Scaleform::Render::Tessellator::MonotoneType *v33; // eax
  unsigned int v34; // eax
  unsigned int v35; // ebx
  Scaleform::Render::Tessellator::MonotoneType *v36; // eax
  Scaleform::Render::Tessellator::MonotoneType *v37; // esi
  unsigned int v38; // ebp
  unsigned int v39; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v40; // eax
  unsigned int v41; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v42; // ecx
  unsigned int v43; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v44; // eax
  unsigned int v45; // edx
  unsigned int v46; // ebp
  unsigned int v47; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v48; // eax
  unsigned int v49; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v50; // ecx
  unsigned int v51; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v52; // eax
  unsigned int v53; // edx
  unsigned int v54; // ebp
  unsigned int v55; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v56; // eax
  unsigned int v57; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v58; // ecx
  unsigned int v59; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v60; // eax
  unsigned int v61; // edx
  unsigned int v62; // ebp
  unsigned int v63; // ecx
  unsigned int v64; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v65; // ecx
  unsigned int v66; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v67; // eax
  unsigned int v68; // edx
  unsigned int v69; // eax
  unsigned int Size; // eax
  unsigned int styleAbove; // [esp+10h] [ebp-44h]
  unsigned int v72; // [esp+14h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v73; // [esp+14h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v74; // [esp+14h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v75; // [esp+14h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v76; // [esp+14h] [ebp-40h]
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // [esp+18h] [ebp-3Ch]
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+24h] [ebp-30h] BYREF
  Scaleform::Render::TessBaseLineIterator<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4> > it; // [esp+30h] [ebp-24h]
  Scaleform::Render::Tessellator::ScanChainType *scana; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scanb; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scanc; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scand; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scane; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scanf; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scang; // [esp+58h] [ebp+4h]
  Scaleform::Render::Tessellator::ScanChainType *scanh; // [esp+58h] [ebp+4h]

  monotone = scan->monotone;
  style = monotone->style;
  v6 = monotone->lowerBase;
  monotone->lowerBase = 0;
  styleAbove = style;
  v7 = scan->monotone;
  numChains = v6->numChains;
  lowerBase = v6;
  firstChain = v6->firstChain;
  vertexRight = v6->vertexRight;
  it.Num = numChains;
  it.VertexRightmost = vertexRight;
  v11 = this->PendingEnds.Pages[firstChain >> 4];
  it.Index = firstChain;
  vertex = v11[firstChain & 0xF].vertex;
  it.VertexRight = vertex;
  val.next = 0;
  val.srcVer = vertex;
  val.aaVer = vertex;
  if ( v7->start )
  {
    v18 = &this->MonoVertices.Pages[v7->d.m.lastIdx >> 4][v7->d.m.lastIdx & 0xF];
    if ( v18->srcVer != vertex )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        &this->MonoVertices,
        &val);
      v18->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      lastIdx = v7->d.m.lastIdx;
      v7->d.m.prevIdx2 = v7->d.m.prevIdx1;
      v7->d.m.prevIdx1 = lastIdx;
      v7->d.m.lastIdx = this->MonoVertices.Size - 1;
    }
  }
  else
  {
    v13 = this->MonoVertices.Size >> 4;
    v72 = v13;
    if ( v13 >= this->MonoVertices.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(&this->MonoVertices, v13);
      v13 = v72;
    }
    v14 = this->MonoVertices.Pages[v13];
    v15 = this->MonoVertices.Size & 0xF;
    v14[v15].srcVer = val.srcVer;
    v16 = &v14[v15];
    v16->aaVer = val.aaVer;
    v16->next = 0;
    ++this->MonoVertices.Size;
    v17 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
    v7->d.m.prevIdx2 = -1;
    v7->d.m.prevIdx1 = -1;
    v7->start = v17;
    v7->d.m.lastIdx = this->MonoVertices.Size - 1;
  }
  v20 = scan->monotone;
  v21 = v20->start == 0;
  val.next = 0;
  val.srcVer = targetVertex;
  val.aaVer = targetVertex;
  if ( v21 )
  {
    p_MonoVertices = &this->MonoVertices;
    v23 = this->MonoVertices.Size >> 4;
    if ( v23 >= this->MonoVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        &this->MonoVertices,
        this->MonoVertices.Size >> 4);
    v24 = &this->MonoVertices.Pages[v23][this->MonoVertices.Size & 0xF];
    aaVer = val.aaVer;
    v24->srcVer = val.srcVer;
    next = val.next;
    v24->aaVer = aaVer;
    goto LABEL_59;
  }
  v27 = &this->MonoVertices.Pages[v20->d.m.lastIdx >> 4][v20->d.m.lastIdx & 0xF];
  if ( v27->srcVer != targetVertex )
  {
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(&this->MonoVertices, &val);
    v27->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
    v28 = v20->d.m.lastIdx;
    v20->d.m.prevIdx2 = v20->d.m.prevIdx1;
    v20->d.m.prevIdx1 = v28;
    v20->d.m.lastIdx = this->MonoVertices.Size - 1;
  }
  while ( it.Num )
  {
    Pages = this->PendingEnds.Pages;
    --it.Num;
    v30 = it.VertexRight;
    v31 = it.Index + 1;
    v32 = &Pages[it.Index++ >> 4][it.Index & 0xF];
    it.Chain = v32;
    if ( it.Num )
      it.VertexRight = Pages[v31 >> 4][v31 & 0xF].vertex;
    else
      it.VertexRight = it.VertexRightmost;
    v33 = v32->monotone;
    if ( v33 )
      v34 = v33->style;
    else
      v34 = 0;
    if ( v30 != it.VertexRight )
    {
      if ( v34 == styleAbove && v32->monotone )
        goto LABEL_45;
      v35 = this->Monotones.Size >> 4;
      if ( v35 >= this->Monotones.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonotoneType,4,16>::allocPage(
          &this->Monotones,
          this->Monotones.Size >> 4);
      v36 = &this->Monotones.Pages[v35][this->Monotones.Size & 0xF];
      v36->start = 0;
      v36->d.m.lastIdx = -1;
      v36->d.m.prevIdx1 = -1;
      v36->d.m.prevIdx2 = -1;
      v36->style = styleAbove;
      v36->lowerBase = 0;
      ++this->Monotones.Size;
      v37 = &this->Monotones.Pages[(this->Monotones.Size - 1) >> 4][(this->Monotones.Size - 1) & 0xF];
      it.Chain->monotone = v37;
      if ( v30 != -1 )
      {
        v38 = v30 | 0x80000000;
        if ( v37->start )
        {
          v73 = &this->MonoVertices.Pages[v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
          if ( v73->srcVer == v38 )
            goto LABEL_35;
          v41 = this->MonoVertices.Size >> 4;
          scanb = (Scaleform::Render::Tessellator::ScanChainType *)v41;
          if ( v41 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v41);
            v41 = (unsigned int)scanb;
          }
          v42 = this->MonoVertices.Pages[v41];
          v43 = this->MonoVertices.Size & 0xF;
          v42[v43].srcVer = v38;
          v44 = &v42[v43];
          v44->aaVer = v38;
          v44->next = 0;
          ++this->MonoVertices.Size;
          v73->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v45 = v37->d.m.lastIdx;
          v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
          v37->d.m.prevIdx1 = v45;
        }
        else
        {
          v39 = this->MonoVertices.Size >> 4;
          scana = (Scaleform::Render::Tessellator::ScanChainType *)v39;
          if ( v39 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v39);
            v39 = (unsigned int)scana;
          }
          v40 = &this->MonoVertices.Pages[v39][this->MonoVertices.Size & 0xF];
          v40->srcVer = v38;
          v40->aaVer = v38;
          v40->next = 0;
          ++this->MonoVertices.Size;
          v37->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v37->d.m.prevIdx2 = -1;
          v37->d.m.prevIdx1 = -1;
        }
        v37->d.m.lastIdx = this->MonoVertices.Size - 1;
      }
LABEL_35:
      if ( it.VertexRight != -1 )
      {
        v46 = it.VertexRight & 0x7FFFFFFF;
        if ( !v37->start )
        {
          v47 = this->MonoVertices.Size >> 4;
          scanc = (Scaleform::Render::Tessellator::ScanChainType *)v47;
          if ( v47 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v47);
            v47 = (unsigned int)scanc;
          }
          v48 = &this->MonoVertices.Pages[v47][this->MonoVertices.Size & 0xF];
          v48->srcVer = v46;
          v48->aaVer = v46;
          v48->next = 0;
          ++this->MonoVertices.Size;
          v37->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v37->d.m.prevIdx2 = -1;
          v37->d.m.prevIdx1 = -1;
LABEL_44:
          v37->d.m.lastIdx = this->MonoVertices.Size - 1;
          goto LABEL_45;
        }
        v74 = &this->MonoVertices.Pages[v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
        if ( v74->srcVer != v46 )
        {
          v49 = this->MonoVertices.Size >> 4;
          scand = (Scaleform::Render::Tessellator::ScanChainType *)v49;
          if ( v49 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v49);
            v49 = (unsigned int)scand;
          }
          v50 = this->MonoVertices.Pages[v49];
          v51 = this->MonoVertices.Size & 0xF;
          v50[v51].srcVer = v46;
          v52 = &v50[v51];
          v52->aaVer = v46;
          v52->next = 0;
          ++this->MonoVertices.Size;
          v74->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v53 = v37->d.m.lastIdx;
          v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
          v37->d.m.prevIdx1 = v53;
          goto LABEL_44;
        }
      }
LABEL_45:
      v20 = it.Chain->monotone;
      if ( targetVertex != -1 )
      {
        v54 = targetVertex | 0x80000000;
        if ( v20->start )
        {
          v75 = &this->MonoVertices.Pages[v20->d.m.lastIdx >> 4][v20->d.m.lastIdx & 0xF];
          if ( v75->srcVer == v54 )
            goto LABEL_55;
          v57 = this->MonoVertices.Size >> 4;
          scanf = (Scaleform::Render::Tessellator::ScanChainType *)v57;
          if ( v57 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v57);
            v57 = (unsigned int)scanf;
          }
          v58 = this->MonoVertices.Pages[v57];
          v59 = this->MonoVertices.Size & 0xF;
          v58[v59].srcVer = v54;
          v60 = &v58[v59];
          v60->aaVer = v54;
          v60->next = 0;
          ++this->MonoVertices.Size;
          v75->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v61 = v20->d.m.lastIdx;
          v20->d.m.prevIdx2 = v20->d.m.prevIdx1;
          v20->d.m.prevIdx1 = v61;
        }
        else
        {
          v55 = this->MonoVertices.Size >> 4;
          scane = (Scaleform::Render::Tessellator::ScanChainType *)v55;
          if ( v55 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v55);
            v55 = (unsigned int)scane;
          }
          v56 = &this->MonoVertices.Pages[v55][this->MonoVertices.Size & 0xF];
          v56->srcVer = v54;
          v56->aaVer = v54;
          v56->next = 0;
          ++this->MonoVertices.Size;
          v20->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v20->d.m.prevIdx2 = -1;
          v20->d.m.prevIdx1 = -1;
        }
        v20->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_55:
        v62 = targetVertex & 0x7FFFFFFF;
        if ( !v20->start )
        {
          p_MonoVertices = &this->MonoVertices;
          v63 = this->MonoVertices.Size >> 4;
          scang = (Scaleform::Render::Tessellator::ScanChainType *)v63;
          if ( v63 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v63);
            v63 = (unsigned int)scang;
          }
          v24 = &this->MonoVertices.Pages[v63][this->MonoVertices.Size & 0xF];
          v24->srcVer = v62;
          v24->aaVer = v62;
          next = 0;
LABEL_59:
          v24->next = next;
          ++p_MonoVertices->Size;
          v20->start = &p_MonoVertices->Pages[(p_MonoVertices->Size - 1) >> 4][(p_MonoVertices->Size - 1) & 0xF];
          v20->d.m.prevIdx2 = -1;
          v20->d.m.prevIdx1 = -1;
          v20->d.m.lastIdx = this->MonoVertices.Size - 1;
          continue;
        }
        v76 = &this->MonoVertices.Pages[v20->d.m.lastIdx >> 4][v20->d.m.lastIdx & 0xF];
        if ( v76->srcVer != v62 )
        {
          v64 = this->MonoVertices.Size >> 4;
          scanh = (Scaleform::Render::Tessellator::ScanChainType *)v64;
          if ( v64 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v64);
            v64 = (unsigned int)scanh;
          }
          v65 = this->MonoVertices.Pages[v64];
          v66 = this->MonoVertices.Size & 0xF;
          v65[v66].srcVer = v62;
          v67 = &v65[v66];
          v67->aaVer = v62;
          v67->next = 0;
          ++this->MonoVertices.Size;
          v76->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v68 = v20->d.m.lastIdx;
          v20->d.m.prevIdx2 = v20->d.m.prevIdx1;
          v20->d.m.prevIdx1 = v68;
          v20->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
      }
    }
  }
  if ( lowerBase == &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(this->BaseLines.Size - 1) & 0xF] )
  {
    v69 = lowerBase->firstChain;
    if ( v69 < this->PendingEnds.Size )
      this->PendingEnds.Size = v69;
    Size = this->BaseLines.Size;
    if ( Size )
      this->BaseLines.Size = Size - 1;
  }
}
