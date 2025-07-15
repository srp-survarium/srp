void __thiscall Scaleform::Render::Tessellator::connectStartingToLeft(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase,
        unsigned int targetVertex)
{
  unsigned int firstChain; // eax
  Scaleform::Render::Tessellator::ScanChainType **Pages; // ebp
  unsigned int vertexLeft; // ebx
  unsigned int styleLeft; // ecx
  Scaleform::Render::Tessellator::MonotoneType *monotone; // edx
  unsigned int style; // eax
  Scaleform::Render::Tessellator::MonotoneType *started; // ebp
  Scaleform::Render::Tessellator::MonotoneType *v13; // eax
  Scaleform::Render::Tessellator::ScanChainType *Chain; // edi
  Scaleform::Render::Tessellator::MonotoneType *v15; // edi
  bool v16; // zf
  unsigned int v17; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v18; // ecx
  unsigned int v19; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v21; // eax
  unsigned int v22; // edx
  unsigned int v23; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v24; // ecx
  unsigned int v25; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v26; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v27; // eax
  unsigned int lastIdx; // edx
  Scaleform::Render::Tessellator::MonotoneType *v29; // edi
  unsigned int v30; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v31; // ecx
  unsigned int v32; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v33; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v34; // eax
  unsigned int v35; // edx
  unsigned int v36; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v37; // ecx
  unsigned int v38; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v39; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v40; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v41; // edx
  unsigned int v42; // edx
  unsigned int v43; // ebx
  unsigned int v44; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v45; // eax
  unsigned int v46; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v47; // ecx
  unsigned int v48; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v49; // eax
  unsigned int v50; // edx
  unsigned int v51; // ebx
  unsigned int v52; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v53; // ecx
  unsigned int v54; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v55; // ecx
  unsigned int v56; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v57; // eax
  unsigned int v58; // edx
  Scaleform::Render::Tessellator::ScanChainType *v59; // edi
  Scaleform::Render::Tessellator::MonotoneType *v60; // edi
  unsigned int v61; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v62; // eax
  unsigned int v63; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v64; // eax
  unsigned int v65; // edx
  unsigned int v66; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v67; // eax
  unsigned int v68; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v69; // eax
  unsigned int v70; // edx
  Scaleform::Render::Tessellator::ScanChainType **v71; // ecx
  unsigned int v72; // edx
  Scaleform::Render::Tessellator::ScanChainType *v73; // edi
  Scaleform::Render::Tessellator::MonoChainType *v74; // eax
  unsigned int rightAbove; // ecx
  Scaleform::Render::Tessellator::ScanChainType *leftAbove; // [esp+10h] [ebp-64h]
  unsigned int v77; // [esp+14h] [ebp-60h]
  Scaleform::Render::Tessellator::MonoVertexType *v78; // [esp+14h] [ebp-60h]
  unsigned int v79; // [esp+14h] [ebp-60h]
  Scaleform::Render::Tessellator::MonoVertexType *v80; // [esp+14h] [ebp-60h]
  unsigned int v81; // [esp+14h] [ebp-60h]
  Scaleform::Render::Tessellator::MonoVertexType *v82; // [esp+14h] [ebp-60h]
  unsigned int v83; // [esp+14h] [ebp-60h]
  Scaleform::Render::Tessellator::MonoVertexType *v84; // [esp+14h] [ebp-60h]
  unsigned int v85; // [esp+14h] [ebp-60h]
  unsigned int v86; // [esp+14h] [ebp-60h]
  Scaleform::Render::Tessellator::MonoVertexType *v87; // [esp+14h] [ebp-60h]
  unsigned int v88; // [esp+14h] [ebp-60h]
  unsigned int v89; // [esp+14h] [ebp-60h]
  Scaleform::Render::Tessellator::MonoVertexType *v90; // [esp+18h] [ebp-5Ch]
  unsigned int v91; // [esp+18h] [ebp-5Ch]
  unsigned int v92; // [esp+18h] [ebp-5Ch]
  unsigned int v93; // [esp+18h] [ebp-5Ch]
  unsigned int v94; // [esp+18h] [ebp-5Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v95; // [esp+18h] [ebp-5Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v96; // [esp+1Ch] [ebp-58h]
  unsigned int v97; // [esp+1Ch] [ebp-58h]
  unsigned int v98; // [esp+1Ch] [ebp-58h]
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+20h] [ebp-54h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v100; // [esp+2Ch] [ebp-48h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v101; // [esp+38h] [ebp-3Ch] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v102; // [esp+44h] [ebp-30h] BYREF
  Scaleform::Render::TessBaseLineIterator<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8> > it; // [esp+50h] [ebp-24h]
  unsigned int styleBelow; // [esp+78h] [ebp+4h]

  if ( upperBase->leftAbove == -1 )
    leftAbove = scan;
  else
    leftAbove = &this->ChainsAbove.Pages[upperBase->leftAbove >> 4][upperBase->leftAbove & 0xF];
  firstChain = upperBase->firstChain;
  Pages = this->ChainsAbove.Pages;
  vertexLeft = upperBase->vertexLeft;
  it.Num = upperBase->numChains;
  styleLeft = upperBase->styleLeft;
  it.VertexRightmost = upperBase->vertexRight;
  it.Index = firstChain;
  monotone = scan->monotone;
  it.VertexRight = Pages[firstChain >> 4][firstChain & 0xF].vertex;
  style = monotone->style;
  it.Style = styleLeft;
  it.Chain = scan;
  it.VertexLeft = vertexLeft;
  it.FlagFirst = 1;
  styleBelow = style;
  started = Scaleform::Render::Tessellator::startMonotone(this, 0);
  *started = *scan->monotone;
  v13 = scan->monotone;
  v13->d.m.lastIdx = -1;
  v13->d.m.prevIdx1 = -1;
  v13->d.m.prevIdx2 = -1;
  v13->start = 0;
  v13->style = styleBelow;
  v13->lowerBase = 0;
  while ( 1 )
  {
    if ( it.Num )
    {
      if ( vertexLeft == it.VertexRight )
        goto LABEL_57;
      Chain = it.Chain;
      Scaleform::Render::Tessellator::replaceMonotone(
        this,
        (Scaleform::Render::Tessellator::PendingEndType *)it.Chain,
        styleBelow);
      v15 = Chain->monotone;
      if ( targetVertex == -1 )
        goto LABEL_22;
      v16 = v15->start == 0;
      val.next = 0;
      val.srcVer = targetVertex | 0x80000000;
      val.aaVer = targetVertex | 0x80000000;
      if ( v16 )
      {
        v17 = this->MonoVertices.Size >> 4;
        v77 = v17;
        if ( v17 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v17);
          v17 = v77;
        }
        v18 = this->MonoVertices.Pages[v17];
        v19 = this->MonoVertices.Size & 0xF;
        v18[v19].srcVer = val.srcVer;
        next = val.next;
        v21 = &v18[v19];
        v21->aaVer = val.aaVer;
        v21->next = next;
        ++this->MonoVertices.Size;
        v15->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v15->d.m.prevIdx2 = -1;
        v15->d.m.prevIdx1 = -1;
      }
      else
      {
        v78 = &this->MonoVertices.Pages[v15->d.m.lastIdx >> 4][v15->d.m.lastIdx & 0xF];
        if ( v78->srcVer == (targetVertex | 0x80000000) )
        {
LABEL_15:
          v16 = v15->start == 0;
          v100.next = 0;
          v100.srcVer = targetVertex & 0x7FFFFFFF;
          v100.aaVer = targetVertex & 0x7FFFFFFF;
          if ( v16 )
          {
            v23 = this->MonoVertices.Size >> 4;
            v79 = v23;
            if ( v23 >= this->MonoVertices.NumPages )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                v23);
              v23 = v79;
            }
            v24 = this->MonoVertices.Pages[v23];
            v25 = this->MonoVertices.Size & 0xF;
            v24[v25].srcVer = v100.srcVer;
            v26 = v100.next;
            v27 = &v24[v25];
            v27->aaVer = v100.aaVer;
            v27->next = v26;
            ++this->MonoVertices.Size;
            v15->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                     & 0xF];
            v15->d.m.prevIdx2 = -1;
            v15->d.m.prevIdx1 = -1;
          }
          else
          {
            v80 = &this->MonoVertices.Pages[v15->d.m.lastIdx >> 4][v15->d.m.lastIdx & 0xF];
            if ( v80->srcVer == (targetVertex & 0x7FFFFFFF) )
              goto LABEL_22;
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v100);
            v80->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            lastIdx = v15->d.m.lastIdx;
            v15->d.m.prevIdx2 = v15->d.m.prevIdx1;
            v15->d.m.prevIdx1 = lastIdx;
          }
          v15->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_22:
          v29 = it.Chain->monotone;
          if ( it.VertexLeft == -1 )
            goto LABEL_30;
          v16 = v29->start == 0;
          v101.next = 0;
          v101.srcVer = it.VertexLeft | 0x80000000;
          v101.aaVer = it.VertexLeft | 0x80000000;
          if ( v16 )
          {
            v30 = this->MonoVertices.Size >> 4;
            v81 = v30;
            if ( v30 >= this->MonoVertices.NumPages )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                v30);
              v30 = v81;
            }
            v31 = this->MonoVertices.Pages[v30];
            v32 = this->MonoVertices.Size & 0xF;
            v31[v32].srcVer = v101.srcVer;
            v33 = v101.next;
            v34 = &v31[v32];
            v34->aaVer = v101.aaVer;
            v34->next = v33;
            ++this->MonoVertices.Size;
            v29->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                     & 0xF];
            v29->d.m.prevIdx2 = -1;
            v29->d.m.prevIdx1 = -1;
          }
          else
          {
            v82 = &this->MonoVertices.Pages[v29->d.m.lastIdx >> 4][v29->d.m.lastIdx & 0xF];
            if ( v82->srcVer == (it.VertexLeft | 0x80000000) )
              goto LABEL_30;
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v101);
            v82->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v35 = v29->d.m.lastIdx;
            v29->d.m.prevIdx2 = v29->d.m.prevIdx1;
            v29->d.m.prevIdx1 = v35;
          }
          v29->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_30:
          if ( it.VertexRight != -1 )
          {
            v16 = v29->start == 0;
            v102.next = 0;
            v102.srcVer = it.VertexRight & 0x7FFFFFFF;
            v102.aaVer = it.VertexRight & 0x7FFFFFFF;
            if ( v16 )
            {
              v36 = this->MonoVertices.Size >> 4;
              v83 = v36;
              if ( v36 >= this->MonoVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  v36);
                v36 = v83;
              }
              v37 = this->MonoVertices.Pages[v36];
              v38 = this->MonoVertices.Size & 0xF;
              v37[v38].srcVer = v102.srcVer;
              v39 = v102.next;
              v40 = &v37[v38];
              v40->aaVer = v102.aaVer;
              v40->next = v39;
              ++this->MonoVertices.Size;
              v41 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
              v29->d.m.prevIdx2 = -1;
              v29->d.m.prevIdx1 = -1;
              v29->start = v41;
              v29->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
            else
            {
              v84 = &this->MonoVertices.Pages[v29->d.m.lastIdx >> 4][v29->d.m.lastIdx & 0xF];
              if ( v84->srcVer != (it.VertexRight & 0x7FFFFFFF) )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                  &this->MonoVertices,
                  &v102);
                v84->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                        & 0xF];
                v42 = v29->d.m.lastIdx;
                v29->d.m.prevIdx2 = v29->d.m.prevIdx1;
                v29->d.m.prevIdx1 = v42;
                v29->d.m.lastIdx = this->MonoVertices.Size - 1;
              }
            }
          }
          goto LABEL_57;
        }
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
          &this->MonoVertices,
          &val);
        v78->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v22 = v15->d.m.lastIdx;
        v15->d.m.prevIdx2 = v15->d.m.prevIdx1;
        v15->d.m.prevIdx1 = v22;
      }
      v15->d.m.lastIdx = this->MonoVertices.Size - 1;
      goto LABEL_15;
    }
    it.Chain->monotone = started;
    if ( vertexLeft != -1 )
    {
      v43 = vertexLeft | 0x80000000;
      if ( started->start )
      {
        v90 = &this->MonoVertices.Pages[started->d.m.lastIdx >> 4][started->d.m.lastIdx & 0xF];
        if ( v90->srcVer == v43 )
          goto LABEL_47;
        v46 = this->MonoVertices.Size >> 4;
        v86 = v46;
        if ( v46 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v46);
          v46 = v86;
        }
        v47 = this->MonoVertices.Pages[v46];
        v48 = this->MonoVertices.Size & 0xF;
        v47[v48].srcVer = v43;
        v49 = &v47[v48];
        v49->aaVer = v43;
        v49->next = 0;
        ++this->MonoVertices.Size;
        v90->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v50 = started->d.m.lastIdx;
        started->d.m.prevIdx2 = started->d.m.prevIdx1;
        started->d.m.prevIdx1 = v50;
      }
      else
      {
        v44 = this->MonoVertices.Size >> 4;
        v85 = v44;
        if ( v44 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v44);
          v44 = v85;
        }
        v45 = &this->MonoVertices.Pages[v44][this->MonoVertices.Size & 0xF];
        v45->srcVer = v43;
        v45->aaVer = v43;
        v45->next = 0;
        ++this->MonoVertices.Size;
        started->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                     & 0xF];
        started->d.m.prevIdx2 = -1;
        started->d.m.prevIdx1 = -1;
      }
      started->d.m.lastIdx = this->MonoVertices.Size - 1;
    }
LABEL_47:
    if ( it.VertexRight != -1 )
    {
      v51 = it.VertexRight & 0x7FFFFFFF;
      if ( started->start )
      {
        v87 = &this->MonoVertices.Pages[started->d.m.lastIdx >> 4][started->d.m.lastIdx & 0xF];
        if ( v87->srcVer == v51 )
          goto LABEL_57;
        v54 = this->MonoVertices.Size >> 4;
        v92 = v54;
        if ( v54 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v54);
          v54 = v92;
        }
        v55 = this->MonoVertices.Pages[v54];
        v56 = this->MonoVertices.Size & 0xF;
        v55[v56].srcVer = v51;
        v57 = &v55[v56];
        v57->aaVer = v51;
        v57->next = 0;
        ++this->MonoVertices.Size;
        v87->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v58 = started->d.m.lastIdx;
        started->d.m.prevIdx2 = started->d.m.prevIdx1;
        started->d.m.prevIdx1 = v58;
      }
      else
      {
        v52 = this->MonoVertices.Size >> 4;
        v91 = v52;
        if ( v52 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v52);
          v52 = v91;
        }
        v53 = &this->MonoVertices.Pages[v52][this->MonoVertices.Size & 0xF];
        v53->srcVer = v51;
        v53->aaVer = v51;
        v53->next = 0;
        ++this->MonoVertices.Size;
        started->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                     & 0xF];
        started->d.m.prevIdx2 = -1;
        started->d.m.prevIdx1 = -1;
      }
      started->d.m.lastIdx = this->MonoVertices.Size - 1;
    }
LABEL_57:
    if ( it.Style == styleBelow && it.Chain->monotone )
      goto LABEL_83;
    if ( !it.Style )
    {
      it.Chain->monotone = 0;
      goto LABEL_83;
    }
    if ( it.FlagFirst )
      it.Chain = leftAbove;
    v59 = it.Chain;
    Scaleform::Render::Tessellator::replaceMonotone(
      this,
      (Scaleform::Render::Tessellator::PendingEndType *)it.Chain,
      it.Style);
    v60 = v59->monotone;
    if ( it.VertexLeft != -1 )
    {
      v88 = it.VertexLeft | 0x80000000;
      if ( !v60->start )
      {
        v61 = this->MonoVertices.Size >> 4;
        v93 = v61;
        if ( v61 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v61);
          v61 = v93;
        }
        v62 = &this->MonoVertices.Pages[v61][this->MonoVertices.Size & 0xF];
        v62->srcVer = v88;
        v62->aaVer = v88;
        v62->next = 0;
        ++this->MonoVertices.Size;
        v60->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v60->d.m.prevIdx2 = -1;
        v60->d.m.prevIdx1 = -1;
LABEL_72:
        v60->d.m.lastIdx = this->MonoVertices.Size - 1;
        goto LABEL_73;
      }
      v96 = &this->MonoVertices.Pages[v60->d.m.lastIdx >> 4][v60->d.m.lastIdx & 0xF];
      if ( v96->srcVer != (it.VertexLeft | 0x80000000) )
      {
        v63 = this->MonoVertices.Size >> 4;
        v94 = v63;
        if ( v63 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v63);
          v63 = v94;
        }
        v64 = &this->MonoVertices.Pages[v63][this->MonoVertices.Size & 0xF];
        v64->srcVer = v88;
        v64->aaVer = v88;
        v64->next = 0;
        ++this->MonoVertices.Size;
        v96->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v65 = v60->d.m.lastIdx;
        v60->d.m.prevIdx2 = v60->d.m.prevIdx1;
        v60->d.m.prevIdx1 = v65;
        goto LABEL_72;
      }
    }
LABEL_73:
    if ( it.VertexRight == -1 )
      goto LABEL_83;
    v89 = it.VertexRight & 0x7FFFFFFF;
    if ( v60->start )
    {
      v95 = &this->MonoVertices.Pages[v60->d.m.lastIdx >> 4][v60->d.m.lastIdx & 0xF];
      if ( v95->srcVer == (it.VertexRight & 0x7FFFFFFF) )
        goto LABEL_83;
      v68 = this->MonoVertices.Size >> 4;
      v98 = v68;
      if ( v68 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v68);
        v68 = v98;
      }
      v69 = &this->MonoVertices.Pages[v68][this->MonoVertices.Size & 0xF];
      v69->srcVer = v89;
      v69->aaVer = v89;
      v69->next = 0;
      ++this->MonoVertices.Size;
      v95->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v70 = v60->d.m.lastIdx;
      v60->d.m.prevIdx2 = v60->d.m.prevIdx1;
      v60->d.m.prevIdx1 = v70;
    }
    else
    {
      v66 = this->MonoVertices.Size >> 4;
      v97 = v66;
      if ( v66 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v66);
        v66 = v97;
      }
      v67 = &this->MonoVertices.Pages[v66][this->MonoVertices.Size & 0xF];
      v67->srcVer = v89;
      v67->aaVer = v89;
      v67->next = 0;
      ++this->MonoVertices.Size;
      v60->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v60->d.m.prevIdx2 = -1;
      v60->d.m.prevIdx1 = -1;
    }
    v60->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_83:
    it.FlagFirst = 0;
    if ( !it.Num )
      break;
    --it.Num;
    it.VertexLeft = it.VertexRight;
    v71 = this->ChainsAbove.Pages;
    v72 = it.Index + 1;
    v73 = &v71[it.Index++ >> 4][it.Index & 0xF];
    it.Chain = v73;
    if ( it.Num )
    {
      v74 = v73->chain;
      vertexLeft = it.VertexLeft;
      it.VertexRight = v71[v72 >> 4][v72 & 0xF].vertex;
      it.Style = v74->rightAbove;
    }
    else
    {
      rightAbove = v73->chain->rightAbove;
      vertexLeft = it.VertexLeft;
      it.VertexRight = it.VertexRightmost;
      it.Style = rightAbove;
    }
  }
  upperBase->numChains = 0;
}
