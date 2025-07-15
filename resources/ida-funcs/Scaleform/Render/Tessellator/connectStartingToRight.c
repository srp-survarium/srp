void __thiscall Scaleform::Render::Tessellator::connectStartingToRight(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::PendingEndType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase,
        unsigned int targetVertex)
{
  unsigned int firstChain; // eax
  Scaleform::Render::Tessellator::ScanChainType **Pages; // ebx
  unsigned int styleLeft; // edx
  Scaleform::Render::Tessellator::MonotoneType *monotone; // eax
  unsigned int v9; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v10; // edi
  unsigned int v11; // ebx
  unsigned int v12; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v13; // eax
  unsigned int v14; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v15; // ecx
  unsigned int v16; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v17; // eax
  unsigned int lastIdx; // edx
  int v19; // ebx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // ebp
  unsigned int v21; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v22; // ecx
  unsigned int v23; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v24; // ecx
  unsigned int v25; // edx
  Scaleform::Render::Tessellator::PendingEndType *v26; // edi
  Scaleform::Render::Tessellator::MonotoneType *v27; // edi
  bool v28; // zf
  unsigned int v29; // ebx
  unsigned int v30; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v31; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v33; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v34; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v35; // ebx
  unsigned int v36; // ecx
  unsigned int v37; // ebx
  unsigned int v38; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v39; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v40; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v41; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v42; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v43; // ebp
  unsigned int v44; // ecx
  unsigned int v45; // ebx
  unsigned int v46; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v47; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v48; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v49; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v50; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v51; // ebp
  unsigned int v52; // ecx
  unsigned int v53; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v54; // eax
  unsigned int aaVer; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v56; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v57; // ebp
  unsigned int v58; // ecx
  Scaleform::Render::Tessellator::PendingEndType *v59; // edi
  Scaleform::Render::Tessellator::MonotoneType *v60; // edi
  unsigned int v61; // ebx
  unsigned int v62; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v63; // eax
  unsigned int v64; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v65; // ecx
  unsigned int v66; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v67; // eax
  unsigned int v68; // edx
  int v69; // ebx
  unsigned int v70; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v71; // eax
  unsigned int v72; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v73; // ecx
  unsigned int v74; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v75; // eax
  unsigned int v76; // edx
  Scaleform::Render::Tessellator::ScanChainType **v77; // ecx
  unsigned int v78; // edi
  Scaleform::Render::Tessellator::PendingEndType *v79; // edx
  unsigned int v80; // edx
  unsigned int v81; // eax
  Scaleform::Render::Tessellator::PendingEndType *v82; // [esp+10h] [ebp-60h]
  unsigned int v83; // [esp+14h] [ebp-5Ch]
  unsigned int v84; // [esp+14h] [ebp-5Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v85; // [esp+14h] [ebp-5Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v86; // [esp+14h] [ebp-5Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v87; // [esp+14h] [ebp-5Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v88; // [esp+18h] [ebp-58h]
  unsigned int v89; // [esp+18h] [ebp-58h]
  unsigned int v90; // [esp+18h] [ebp-58h]
  unsigned int v91; // [esp+18h] [ebp-58h]
  unsigned int v92; // [esp+18h] [ebp-58h]
  unsigned int v93; // [esp+18h] [ebp-58h]
  unsigned int v94; // [esp+18h] [ebp-58h]
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+1Ch] [ebp-54h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v96; // [esp+28h] [ebp-48h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v97; // [esp+34h] [ebp-3Ch] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v98; // [esp+40h] [ebp-30h] BYREF
  unsigned int v99; // [esp+50h] [ebp-20h]
  unsigned int numChains; // [esp+54h] [ebp-1Ch]
  unsigned int vertexRight; // [esp+58h] [ebp-18h]
  Scaleform::Render::Tessellator::PendingEndType *pe; // [esp+5Ch] [ebp-14h]
  unsigned int vertexLeft; // [esp+60h] [ebp-10h]
  unsigned int vertex; // [esp+64h] [ebp-Ch]
  unsigned int v105; // [esp+68h] [ebp-8h]
  char v106; // [esp+6Ch] [ebp-4h]
  unsigned int style; // [esp+74h] [ebp+4h]

  if ( upperBase->leftAbove == -1 )
    v82 = scan;
  else
    v82 = (Scaleform::Render::Tessellator::PendingEndType *)&this->ChainsAbove.Pages[upperBase->leftAbove >> 4][upperBase->leftAbove & 0xF];
  firstChain = upperBase->firstChain;
  Pages = this->ChainsAbove.Pages;
  numChains = upperBase->numChains;
  vertexRight = upperBase->vertexRight;
  styleLeft = upperBase->styleLeft;
  vertexLeft = upperBase->vertexLeft;
  v99 = firstChain;
  vertex = Pages[firstChain >> 4][firstChain & 0xF].vertex;
  monotone = scan->monotone;
  pe = scan;
  v9 = monotone->style;
  v105 = styleLeft;
  v106 = 1;
  style = v9;
  while ( 1 )
  {
    if ( v106 )
    {
      v10 = pe->monotone;
      if ( vertexLeft == -1 )
        goto LABEL_16;
      v11 = vertexLeft | 0x80000000;
      if ( v10->start )
      {
        v88 = &this->MonoVertices.Pages[v10->d.m.lastIdx >> 4][v10->d.m.lastIdx & 0xF];
        if ( v88->srcVer == v11 )
          goto LABEL_16;
        v14 = this->MonoVertices.Size >> 4;
        v84 = v14;
        if ( v14 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v14);
          v14 = v84;
        }
        v15 = this->MonoVertices.Pages[v14];
        v16 = this->MonoVertices.Size & 0xF;
        v15[v16].srcVer = v11;
        v17 = &v15[v16];
        v17->aaVer = v11;
        v17->next = 0;
        ++this->MonoVertices.Size;
        v88->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        lastIdx = v10->d.m.lastIdx;
        v10->d.m.prevIdx2 = v10->d.m.prevIdx1;
        v10->d.m.prevIdx1 = lastIdx;
      }
      else
      {
        v12 = this->MonoVertices.Size >> 4;
        v83 = v12;
        if ( v12 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v12);
          v12 = v83;
        }
        v13 = &this->MonoVertices.Pages[v12][this->MonoVertices.Size & 0xF];
        v13->srcVer = v11;
        v13->aaVer = v11;
        v13->next = 0;
        ++this->MonoVertices.Size;
        v10->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v10->d.m.prevIdx2 = -1;
        v10->d.m.prevIdx1 = -1;
      }
      v10->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_16:
      if ( vertex != -1 )
      {
        v19 = vertex & 0x7FFFFFFF;
        if ( !v10->start )
        {
          p_MonoVertices = &this->MonoVertices;
          v21 = this->MonoVertices.Size >> 4;
          v89 = v21;
          if ( v21 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v21);
            v21 = v89;
          }
          v22 = &this->MonoVertices.Pages[v21][this->MonoVertices.Size & 0xF];
          v22->srcVer = v19;
          v22->aaVer = v19;
          v22->next = 0;
LABEL_21:
          ++p_MonoVertices->Size;
          v10->start = &p_MonoVertices->Pages[(p_MonoVertices->Size - 1) >> 4][(p_MonoVertices->Size - 1) & 0xF];
          v10->d.m.prevIdx2 = -1;
          v10->d.m.prevIdx1 = -1;
          v10->d.m.lastIdx = this->MonoVertices.Size - 1;
          goto LABEL_54;
        }
        v85 = &this->MonoVertices.Pages[v10->d.m.lastIdx >> 4][v10->d.m.lastIdx & 0xF];
        if ( v85->srcVer != v19 )
        {
          v23 = this->MonoVertices.Size >> 4;
          v90 = v23;
          if ( v23 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v23);
            v23 = v90;
          }
          v24 = &this->MonoVertices.Pages[v23][this->MonoVertices.Size & 0xF];
          v24->srcVer = v19;
          v24->aaVer = v19;
          v24->next = 0;
          ++this->MonoVertices.Size;
          v85->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v25 = v10->d.m.lastIdx;
          v10->d.m.prevIdx2 = v10->d.m.prevIdx1;
          v10->d.m.prevIdx1 = v25;
          v10->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
      }
      goto LABEL_54;
    }
    if ( vertexLeft != vertex )
    {
      v26 = pe;
      Scaleform::Render::Tessellator::replaceMonotone(this, pe, style);
      v27 = v26->monotone;
      if ( targetVertex != -1 )
      {
        v28 = v27->start == 0;
        val.next = 0;
        val.srcVer = targetVertex | 0x80000000;
        val.aaVer = targetVertex | 0x80000000;
        if ( v28 )
        {
          v29 = this->MonoVertices.Size >> 4;
          if ( v29 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v30 = this->MonoVertices.Size & 0xF;
          v31 = this->MonoVertices.Pages[v29];
          v31[v30].srcVer = val.srcVer;
          next = val.next;
          v33 = &v31[v30];
          v33->aaVer = val.aaVer;
          v33->next = next;
          ++this->MonoVertices.Size;
          v34 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v27->d.m.prevIdx2 = -1;
          v27->d.m.prevIdx1 = -1;
          v27->start = v34;
          v27->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v35 = &this->MonoVertices.Pages[v27->d.m.lastIdx >> 4][v27->d.m.lastIdx & 0xF];
          if ( v35->srcVer != (targetVertex | 0x80000000) )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &val);
            v35->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v36 = v27->d.m.lastIdx;
            v27->d.m.prevIdx2 = v27->d.m.prevIdx1;
            v27->d.m.prevIdx1 = v36;
            v27->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
        v28 = v27->start == 0;
        v96.next = 0;
        v96.srcVer = targetVertex & 0x7FFFFFFF;
        v96.aaVer = targetVertex & 0x7FFFFFFF;
        if ( v28 )
        {
          v37 = this->MonoVertices.Size >> 4;
          if ( v37 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v38 = this->MonoVertices.Size & 0xF;
          v39 = this->MonoVertices.Pages[v37];
          v39[v38].srcVer = v96.srcVer;
          v40 = v96.next;
          v41 = &v39[v38];
          v41->aaVer = v96.aaVer;
          v41->next = v40;
          ++this->MonoVertices.Size;
          v42 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v27->d.m.prevIdx2 = -1;
          v27->d.m.prevIdx1 = -1;
          v27->start = v42;
          v27->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v43 = &this->MonoVertices.Pages[v27->d.m.lastIdx >> 4][v27->d.m.lastIdx & 0xF];
          if ( v43->srcVer != (targetVertex & 0x7FFFFFFF) )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v96);
            v43->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v44 = v27->d.m.lastIdx;
            v27->d.m.prevIdx2 = v27->d.m.prevIdx1;
            v27->d.m.prevIdx1 = v44;
            v27->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
      v10 = pe->monotone;
      if ( vertexLeft != -1 )
      {
        v28 = v10->start == 0;
        v97.next = 0;
        v97.srcVer = vertexLeft | 0x80000000;
        v97.aaVer = vertexLeft | 0x80000000;
        if ( v28 )
        {
          v45 = this->MonoVertices.Size >> 4;
          if ( v45 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v46 = this->MonoVertices.Size & 0xF;
          v47 = this->MonoVertices.Pages[v45];
          v47[v46].srcVer = v97.srcVer;
          v48 = v97.next;
          v49 = &v47[v46];
          v49->aaVer = v97.aaVer;
          v49->next = v48;
          ++this->MonoVertices.Size;
          v50 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v10->d.m.prevIdx2 = -1;
          v10->d.m.prevIdx1 = -1;
          v10->start = v50;
          v10->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v51 = &this->MonoVertices.Pages[v10->d.m.lastIdx >> 4][v10->d.m.lastIdx & 0xF];
          if ( v51->srcVer != (vertexLeft | 0x80000000) )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v97);
            v51->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v52 = v10->d.m.lastIdx;
            v10->d.m.prevIdx2 = v10->d.m.prevIdx1;
            v10->d.m.prevIdx1 = v52;
            v10->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
      if ( vertex != -1 )
      {
        v28 = v10->start == 0;
        v98.next = 0;
        v98.srcVer = vertex & 0x7FFFFFFF;
        v98.aaVer = vertex & 0x7FFFFFFF;
        if ( v28 )
        {
          p_MonoVertices = &this->MonoVertices;
          v53 = this->MonoVertices.Size >> 4;
          if ( v53 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v54 = &this->MonoVertices.Pages[v53][this->MonoVertices.Size & 0xF];
          aaVer = v98.aaVer;
          v54->srcVer = v98.srcVer;
          v56 = v98.next;
          v54->aaVer = aaVer;
          v54->next = v56;
          goto LABEL_21;
        }
        v57 = &this->MonoVertices.Pages[v10->d.m.lastIdx >> 4][v10->d.m.lastIdx & 0xF];
        if ( v57->srcVer != (vertex & 0x7FFFFFFF) )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            &this->MonoVertices,
            &v98);
          v57->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v58 = v10->d.m.lastIdx;
          v10->d.m.prevIdx2 = v10->d.m.prevIdx1;
          v10->d.m.prevIdx1 = v58;
          v10->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
      }
    }
LABEL_54:
    if ( v105 == style && pe->monotone )
      goto LABEL_80;
    if ( !v105 )
    {
      pe->monotone = 0;
      goto LABEL_80;
    }
    if ( v106 )
      pe = v82;
    v59 = pe;
    Scaleform::Render::Tessellator::replaceMonotone(this, pe, v105);
    v60 = v59->monotone;
    if ( vertexLeft != -1 )
    {
      v61 = vertexLeft | 0x80000000;
      if ( !v60->start )
      {
        v62 = this->MonoVertices.Size >> 4;
        v91 = v62;
        if ( v62 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v62);
          v62 = v91;
        }
        v63 = &this->MonoVertices.Pages[v62][this->MonoVertices.Size & 0xF];
        v63->srcVer = v61;
        v63->aaVer = v61;
        v63->next = 0;
        ++this->MonoVertices.Size;
        v60->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v60->d.m.prevIdx2 = -1;
        v60->d.m.prevIdx1 = -1;
LABEL_69:
        v60->d.m.lastIdx = this->MonoVertices.Size - 1;
        goto LABEL_70;
      }
      v86 = &this->MonoVertices.Pages[v60->d.m.lastIdx >> 4][v60->d.m.lastIdx & 0xF];
      if ( v86->srcVer != v61 )
      {
        v64 = this->MonoVertices.Size >> 4;
        v92 = v64;
        if ( v64 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v64);
          v64 = v92;
        }
        v65 = this->MonoVertices.Pages[v64];
        v66 = this->MonoVertices.Size & 0xF;
        v65[v66].srcVer = v61;
        v67 = &v65[v66];
        v67->aaVer = v61;
        v67->next = 0;
        ++this->MonoVertices.Size;
        v86->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v68 = v60->d.m.lastIdx;
        v60->d.m.prevIdx2 = v60->d.m.prevIdx1;
        v60->d.m.prevIdx1 = v68;
        goto LABEL_69;
      }
    }
LABEL_70:
    if ( vertex == -1 )
      goto LABEL_80;
    v69 = vertex & 0x7FFFFFFF;
    if ( v60->start )
    {
      v87 = &this->MonoVertices.Pages[v60->d.m.lastIdx >> 4][v60->d.m.lastIdx & 0xF];
      if ( v87->srcVer == v69 )
        goto LABEL_80;
      v72 = this->MonoVertices.Size >> 4;
      v94 = v72;
      if ( v72 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v72);
        v72 = v94;
      }
      v73 = this->MonoVertices.Pages[v72];
      v74 = this->MonoVertices.Size & 0xF;
      v73[v74].srcVer = v69;
      v75 = &v73[v74];
      v75->aaVer = v69;
      v75->next = 0;
      ++this->MonoVertices.Size;
      v87->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v76 = v60->d.m.lastIdx;
      v60->d.m.prevIdx2 = v60->d.m.prevIdx1;
      v60->d.m.prevIdx1 = v76;
    }
    else
    {
      v70 = this->MonoVertices.Size >> 4;
      v93 = v70;
      if ( v70 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v70);
        v70 = v93;
      }
      v71 = &this->MonoVertices.Pages[v70][this->MonoVertices.Size & 0xF];
      v71->srcVer = v69;
      v71->aaVer = v69;
      v71->next = 0;
      ++this->MonoVertices.Size;
      v60->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v60->d.m.prevIdx2 = -1;
      v60->d.m.prevIdx1 = -1;
    }
    v60->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_80:
    v106 = 0;
    if ( !numChains )
      break;
    vertexLeft = vertex;
    v77 = this->ChainsAbove.Pages;
    v78 = v99 + 1;
    v79 = (Scaleform::Render::Tessellator::PendingEndType *)&v77[v99 >> 4][v99 & 0xF];
    --numChains;
    ++v99;
    pe = v79;
    if ( numChains )
    {
      v80 = v79->vertex;
      vertex = v77[v78 >> 4][v78 & 0xF].vertex;
      v105 = *(unsigned __int16 *)(v80 + 34);
    }
    else
    {
      v81 = *(unsigned __int16 *)(v79->vertex + 34);
      vertex = vertexRight;
      v105 = v81;
    }
  }
  upperBase->numChains = 0;
}
