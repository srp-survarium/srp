void __thiscall Scaleform::Render::Tessellator::connectPendingToLeft(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        unsigned int targetVertex)
{
  Scaleform::Render::Tessellator::MonotoneType *monotone; // eax
  unsigned int style; // edi
  Scaleform::Render::Tessellator::BaseLineType *v6; // ecx
  unsigned int vertexLeft; // ebx
  unsigned int styleLeft; // eax
  char v9; // dl
  Scaleform::Render::Tessellator::MonotoneType *v10; // edi
  unsigned int v11; // ebx
  unsigned int v12; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v14; // edx
  unsigned int v15; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v16; // eax
  unsigned int v17; // edx
  Scaleform::Render::Tessellator::MonotoneType *v18; // edi
  bool v19; // zf
  unsigned int v20; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v21; // ecx
  unsigned int v22; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v24; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v25; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v26; // ebp
  unsigned int lastIdx; // ecx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // ebp
  unsigned int v29; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v30; // eax
  unsigned int aaVer; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v32; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v33; // ebp
  Scaleform::Render::Tessellator::MonoVertexType *v34; // eax
  unsigned int v35; // ebp
  Scaleform::Render::Tessellator::MonotoneType *v36; // eax
  Scaleform::Render::Tessellator::MonotoneType *v37; // edi
  unsigned int v38; // ebx
  unsigned int v39; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v40; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v41; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v42; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v43; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v44; // ebp
  unsigned int v45; // ecx
  unsigned int v46; // ebx
  unsigned int v47; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v48; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v49; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v50; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v51; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v52; // ebp
  unsigned int v53; // ecx
  unsigned int v54; // ebx
  unsigned int v55; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v56; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v57; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v58; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v59; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v60; // ebx
  unsigned int v61; // ecx
  unsigned int v62; // ebx
  unsigned int v63; // ebx
  unsigned int v64; // ecx
  char v65; // al
  unsigned int v66; // edi
  Scaleform::Render::Tessellator::PendingEndType **Pages; // ecx
  int v68; // eax
  unsigned int vertex; // ecx
  int v70; // eax
  unsigned int firstChain; // eax
  unsigned int Size; // eax
  unsigned int it_4; // [esp+14h] [ebp-88h]
  unsigned int it_8; // [esp+18h] [ebp-84h]
  unsigned int it_12; // [esp+1Ch] [ebp-80h]
  Scaleform::Render::Tessellator::PendingEndType *it_16; // [esp+20h] [ebp-7Ch]
  unsigned int it_24; // [esp+28h] [ebp-74h]
  unsigned int styleAbove; // [esp+34h] [ebp-68h]
  Scaleform::Render::Tessellator::MonoVertexType v79; // [esp+38h] [ebp-64h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v80; // [esp+44h] [ebp-58h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+50h] [ebp-4Ch] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v82; // [esp+5Ch] [ebp-40h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v83; // [esp+68h] [ebp-34h] BYREF
  unsigned int v84; // [esp+74h] [ebp-28h] BYREF
  unsigned int v85; // [esp+78h] [ebp-24h]
  Scaleform::Render::Tessellator::MonoVertexType *v86; // [esp+7Ch] [ebp-20h]
  unsigned int v87; // [esp+80h] [ebp-1Ch] BYREF
  unsigned int v88; // [esp+84h] [ebp-18h]
  Scaleform::Render::Tessellator::MonoVertexType *v89; // [esp+88h] [ebp-14h]
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // [esp+8Ch] [ebp-10h]
  Scaleform::Render::Tessellator::MonoVertexType *v91; // [esp+90h] [ebp-Ch]
  Scaleform::Render::Tessellator::PendingEndType scanLeft; // [esp+94h] [ebp-8h] BYREF

  monotone = scan->monotone;
  style = monotone->style;
  v6 = monotone->lowerBase;
  monotone->lowerBase = 0;
  vertexLeft = v6->vertexLeft;
  it_8 = v6->numChains;
  it_12 = v6->vertexRight;
  scanLeft.monotone = scan->monotone;
  it_16 = &scanLeft;
  styleAbove = style;
  it_4 = v6->firstChain;
  it_24 = this->PendingEnds.Pages[it_4 >> 4][it_4 & 0xF].vertex;
  styleLeft = v6->styleLeft;
  lowerBase = v6;
  scanLeft.vertex = vertexLeft;
  v9 = 1;
  while ( 1 )
  {
    if ( vertexLeft == it_24 )
      goto LABEL_66;
    if ( v9 )
    {
      v10 = scan->monotone;
      if ( v10->start )
      {
        v14 = &this->MonoVertices.Pages[v10->d.m.lastIdx >> 4][v10->d.m.lastIdx & 0xF];
        v91 = v14;
        if ( v14->srcVer == it_24 )
        {
LABEL_13:
          v18 = scan->monotone;
          if ( targetVertex == -1 )
            goto LABEL_66;
          v19 = v18->start == 0;
          val.next = 0;
          val.srcVer = targetVertex | 0x80000000;
          val.aaVer = targetVertex | 0x80000000;
          if ( v19 )
          {
            v20 = this->MonoVertices.Size >> 4;
            if ( v20 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v21 = this->MonoVertices.Pages[v20];
            v22 = this->MonoVertices.Size & 0xF;
            v21[v22].srcVer = val.srcVer;
            next = val.next;
            v24 = &v21[v22];
            v24->aaVer = val.aaVer;
            v24->next = next;
            ++this->MonoVertices.Size;
            v25 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
            v18->d.m.prevIdx2 = -1;
            v18->d.m.prevIdx1 = -1;
            v18->start = v25;
            v18->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
          else
          {
            v26 = &this->MonoVertices.Pages[v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
            if ( v26->srcVer != (targetVertex | 0x80000000) )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                &this->MonoVertices,
                &val);
              v26->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                      & 0xF];
              lastIdx = v18->d.m.lastIdx;
              v18->d.m.prevIdx2 = v18->d.m.prevIdx1;
              v18->d.m.prevIdx1 = lastIdx;
              v18->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
          }
          v19 = v18->start == 0;
          v79.next = 0;
          v79.srcVer = targetVertex & 0x7FFFFFFF;
          v79.aaVer = targetVertex & 0x7FFFFFFF;
          if ( v19 )
          {
            p_MonoVertices = &this->MonoVertices;
            v29 = this->MonoVertices.Size >> 4;
            if ( v29 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v30 = &this->MonoVertices.Pages[v29][this->MonoVertices.Size & 0xF];
            aaVer = v79.aaVer;
            v30->srcVer = v79.srcVer;
            v32 = v79.next;
LABEL_62:
            v30->aaVer = aaVer;
            v30->next = v32;
            ++p_MonoVertices->Size;
            v18->start = &p_MonoVertices->Pages[(p_MonoVertices->Size - 1) >> 4][(p_MonoVertices->Size - 1) & 0xF];
            v18->d.m.prevIdx2 = -1;
            v18->d.m.prevIdx1 = -1;
            v18->d.m.lastIdx = this->MonoVertices.Size - 1;
            goto LABEL_66;
          }
          v33 = &this->MonoVertices.Pages[v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
          if ( v33->srcVer == (targetVertex & 0x7FFFFFFF) )
            goto LABEL_66;
          v34 = &v79;
          goto LABEL_65;
        }
        v15 = this->MonoVertices.Size >> 4;
        if ( v15 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            this->MonoVertices.Size >> 4);
          v14 = v91;
        }
        v16 = &this->MonoVertices.Pages[v15][this->MonoVertices.Size & 0xF];
        v16->srcVer = it_24;
        v16->aaVer = it_24;
        v16->next = 0;
        ++this->MonoVertices.Size;
        v14->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v17 = v10->d.m.lastIdx;
        v10->d.m.prevIdx2 = v10->d.m.prevIdx1;
        v10->d.m.prevIdx1 = v17;
      }
      else
      {
        v11 = this->MonoVertices.Size >> 4;
        if ( v11 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v12 = this->MonoVertices.Size & 0xF;
        v13 = this->MonoVertices.Pages[v11];
        v13[v12].srcVer = it_24;
        v13[v12].aaVer = it_24;
        v13[v12].next = 0;
        ++this->MonoVertices.Size;
        v10->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v10->d.m.prevIdx2 = -1;
        v10->d.m.prevIdx1 = -1;
      }
      v10->d.m.lastIdx = this->MonoVertices.Size - 1;
      goto LABEL_13;
    }
    if ( styleLeft != styleAbove || !it_16->monotone )
    {
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
      it_16->monotone = v37;
      if ( vertexLeft != -1 )
      {
        v19 = v37->start == 0;
        v82.next = 0;
        v82.srcVer = vertexLeft | 0x80000000;
        v82.aaVer = vertexLeft | 0x80000000;
        if ( v19 )
        {
          v38 = this->MonoVertices.Size >> 4;
          if ( v38 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v39 = this->MonoVertices.Size & 0xF;
          v40 = this->MonoVertices.Pages[v38];
          v40[v39].srcVer = v82.srcVer;
          v41 = v82.next;
          v42 = &v40[v39];
          v42->aaVer = v82.aaVer;
          v42->next = v41;
          ++this->MonoVertices.Size;
          v43 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v37->d.m.prevIdx2 = -1;
          v37->d.m.prevIdx1 = -1;
          v37->start = v43;
          v37->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v44 = &this->MonoVertices.Pages[v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
          if ( v44->srcVer != (vertexLeft | 0x80000000) )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v82);
            v44->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v45 = v37->d.m.lastIdx;
            v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
            v37->d.m.prevIdx1 = v45;
            v37->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
      if ( it_24 != -1 )
      {
        v19 = v37->start == 0;
        v80.next = 0;
        v80.srcVer = it_24 & 0x7FFFFFFF;
        v80.aaVer = it_24 & 0x7FFFFFFF;
        if ( v19 )
        {
          v46 = this->MonoVertices.Size >> 4;
          if ( v46 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v47 = this->MonoVertices.Size & 0xF;
          v48 = this->MonoVertices.Pages[v46];
          v48[v47].srcVer = v80.srcVer;
          v49 = v80.next;
          v50 = &v48[v47];
          v50->aaVer = v80.aaVer;
          v50->next = v49;
          ++this->MonoVertices.Size;
          v51 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v37->d.m.prevIdx2 = -1;
          v37->d.m.prevIdx1 = -1;
          v37->start = v51;
          v37->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v52 = &this->MonoVertices.Pages[v37->d.m.lastIdx >> 4][v37->d.m.lastIdx & 0xF];
          if ( v52->srcVer != (it_24 & 0x7FFFFFFF) )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v80);
            v52->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v53 = v37->d.m.lastIdx;
            v37->d.m.prevIdx2 = v37->d.m.prevIdx1;
            v37->d.m.prevIdx1 = v53;
            v37->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
    }
    v18 = it_16->monotone;
    if ( it_8 )
    {
      if ( targetVertex == -1 )
        goto LABEL_66;
      v83.next = 0;
      v83.srcVer = targetVertex | 0x80000000;
      v83.aaVer = targetVertex | 0x80000000;
      if ( v18->start )
      {
        v60 = &this->MonoVertices.Pages[v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
        if ( v60->srcVer != (targetVertex | 0x80000000) )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            &this->MonoVertices,
            &v83);
          v60->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v61 = v18->d.m.lastIdx;
          v18->d.m.prevIdx2 = v18->d.m.prevIdx1;
          v18->d.m.prevIdx1 = v61;
          v18->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
      }
      else
      {
        v54 = this->MonoVertices.Size >> 4;
        if ( v54 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v55 = this->MonoVertices.Size & 0xF;
        v56 = this->MonoVertices.Pages[v54];
        v56[v55].srcVer = v83.srcVer;
        v57 = v83.next;
        v58 = &v56[v55];
        v58->aaVer = v83.aaVer;
        v58->next = v57;
        ++this->MonoVertices.Size;
        v59 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v18->d.m.prevIdx2 = -1;
        v18->d.m.prevIdx1 = -1;
        v18->start = v59;
        v18->d.m.lastIdx = this->MonoVertices.Size - 1;
      }
      v19 = v18->start == 0;
      v89 = 0;
      v87 = targetVertex & 0x7FFFFFFF;
      v88 = targetVertex & 0x7FFFFFFF;
      if ( v19 )
      {
        p_MonoVertices = &this->MonoVertices;
        v62 = this->MonoVertices.Size >> 4;
        if ( v62 >= this->MonoVertices.NumPages )
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            this->MonoVertices.Size >> 4);
        v30 = &this->MonoVertices.Pages[v62][this->MonoVertices.Size & 0xF];
        aaVer = v88;
        v30->srcVer = v87;
        v32 = v89;
        goto LABEL_62;
      }
      v33 = &this->MonoVertices.Pages[v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
      if ( v33->srcVer == (targetVertex & 0x7FFFFFFF) )
        goto LABEL_66;
      v34 = (Scaleform::Render::Tessellator::MonoVertexType *)&v87;
      goto LABEL_65;
    }
    scan->monotone = v18;
    v86 = 0;
    v84 = targetVertex | 0x80000000;
    v85 = targetVertex | 0x80000000;
    if ( !v18->start )
    {
      p_MonoVertices = &this->MonoVertices;
      v63 = this->MonoVertices.Size >> 4;
      if ( v63 >= this->MonoVertices.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          this->MonoVertices.Size >> 4);
      v30 = &this->MonoVertices.Pages[v63][this->MonoVertices.Size & 0xF];
      aaVer = v85;
      v30->srcVer = v84;
      v32 = v86;
      goto LABEL_62;
    }
    v33 = &this->MonoVertices.Pages[v18->d.m.lastIdx >> 4][v18->d.m.lastIdx & 0xF];
    if ( v33->srcVer != (targetVertex | 0x80000000) )
    {
      v34 = (Scaleform::Render::Tessellator::MonoVertexType *)&v84;
LABEL_65:
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        &this->MonoVertices,
        v34);
      v33->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v64 = v18->d.m.lastIdx;
      v18->d.m.prevIdx2 = v18->d.m.prevIdx1;
      v18->d.m.prevIdx1 = v64;
      v18->d.m.lastIdx = this->MonoVertices.Size - 1;
    }
LABEL_66:
    v9 = 0;
    if ( !it_8 )
      break;
    --it_8;
    vertexLeft = it_24;
    v65 = it_4;
    v66 = it_4++;
    Pages = this->PendingEnds.Pages;
    v68 = (int)&Pages[v66 >> 4][v65 & 0xF];
    it_16 = (Scaleform::Render::Tessellator::PendingEndType *)v68;
    if ( it_8 )
      vertex = Pages[it_4 >> 4][it_4 & 0xF].vertex;
    else
      vertex = it_12;
    v70 = *(_DWORD *)(v68 + 4);
    it_24 = vertex;
    if ( v70 )
      styleLeft = *(_DWORD *)(v70 + 16);
    else
      styleLeft = 0;
  }
  if ( lowerBase == &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(this->BaseLines.Size - 1) & 0xF] )
  {
    firstChain = lowerBase->firstChain;
    if ( firstChain < this->PendingEnds.Size )
      this->PendingEnds.Size = firstChain;
    Size = this->BaseLines.Size;
    if ( Size )
      this->BaseLines.Size = Size - 1;
  }
}
