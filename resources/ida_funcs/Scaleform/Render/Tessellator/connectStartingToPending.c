void __thiscall Scaleform::Render::Tessellator::connectStartingToPending(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::Tessellator::ScanChainType *scan,
        Scaleform::Render::Tessellator::BaseLineType *upperBase)
{
  Scaleform::Render::Tessellator::MonotoneType *v3; // eax
  unsigned int style; // edi
  Scaleform::Render::Tessellator::BaseLineType *v6; // ecx
  unsigned int firstChain; // eax
  unsigned int vertexLeft; // ebx
  unsigned int vertex; // eax
  unsigned int styleLeft; // ecx
  unsigned int v11; // eax
  unsigned int numChains; // ebx
  unsigned int vertexRight; // ebp
  unsigned int v14; // edx
  unsigned int rightAbove; // ecx
  unsigned int v16; // ebx
  unsigned int v17; // ebp
  Scaleform::Render::Tessellator::PendingEndType *Chain; // edi
  Scaleform::Render::Tessellator::MonotoneType *v19; // edi
  unsigned int v20; // eax
  bool v21; // zf
  unsigned int v22; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v23; // ecx
  unsigned int v24; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v26; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v27; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v28; // ebx
  unsigned int lastIdx; // ecx
  unsigned int v30; // ebx
  unsigned int v31; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v32; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v33; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v34; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v35; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v36; // ebx
  unsigned int v37; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v38; // edi
  unsigned int v39; // ebx
  unsigned int v40; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v41; // eax
  unsigned int v42; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v43; // ecx
  unsigned int v44; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v45; // eax
  unsigned int v46; // edx
  unsigned int v47; // ebx
  unsigned int v48; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v49; // eax
  unsigned int v50; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v51; // ecx
  unsigned int v52; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v53; // eax
  unsigned int v54; // edx
  Scaleform::Render::Tessellator::MonotoneType *v55; // edi
  unsigned int v56; // ebx
  unsigned int v57; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v58; // eax
  unsigned int v59; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v60; // ecx
  unsigned int v61; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v62; // eax
  unsigned int v63; // edx
  unsigned int v64; // ebx
  unsigned int v65; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v66; // eax
  unsigned int v67; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v68; // ecx
  unsigned int v69; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v70; // eax
  unsigned int v71; // edx
  Scaleform::Render::Tessellator::PendingEndType **Pages; // edx
  unsigned int v73; // ecx
  Scaleform::Render::Tessellator::PendingEndType *v74; // eax
  Scaleform::Render::Tessellator::MonotoneType *v75; // eax
  Scaleform::Render::Tessellator::ScanChainType **v76; // edx
  unsigned int v77; // ecx
  Scaleform::Render::Tessellator::ScanChainType *v78; // eax
  Scaleform::Render::Tessellator::MonoChainType *v79; // eax
  unsigned int v80; // eax
  Scaleform::Render::Tessellator::MonotoneType *started; // edi
  Scaleform::Render::Tessellator::PendingEndType *v82; // ebx
  Scaleform::Render::Tessellator::MonotoneType *v83; // eax
  unsigned int v84; // ebp
  Scaleform::Render::Tessellator::MonotoneType *v85; // eax
  Scaleform::Render::Tessellator::ScanChainType *v86; // ebx
  Scaleform::Render::Tessellator::MonotoneType *v87; // eax
  Scaleform::Render::Tessellator::MonotoneType *v88; // edi
  unsigned int v89; // ebx
  unsigned int v90; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v91; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v92; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v93; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v94; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v95; // ebx
  unsigned int v96; // ecx
  unsigned int v97; // ebx
  unsigned int v98; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v99; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v100; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v101; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v102; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v103; // ebx
  unsigned int v104; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v105; // edi
  unsigned int v106; // ebx
  unsigned int v107; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v108; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v109; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v110; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v111; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v112; // ebx
  unsigned int v113; // ecx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // ebp
  unsigned int v115; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v116; // eax
  unsigned int aaVer; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v118; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v119; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v120; // eax
  Scaleform::Render::Tessellator::MonotoneType *v121; // edi
  unsigned int v122; // ebx
  unsigned int v123; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v124; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v125; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v126; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v127; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v128; // ebx
  unsigned int v129; // ecx
  unsigned int v130; // ebx
  unsigned int v131; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v132; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v133; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v134; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v135; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v136; // ebx
  unsigned int v137; // ecx
  unsigned int v138; // ebx
  unsigned int v139; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v140; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v141; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v142; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v143; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v144; // ebx
  unsigned int v145; // ecx
  unsigned int v146; // ebx
  unsigned int v147; // ecx
  Scaleform::Render::Tessellator::ScanChainType *v148; // edi
  Scaleform::Render::Tessellator::MonotoneType *v149; // edi
  unsigned int v150; // ebx
  unsigned int v151; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v152; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v153; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v154; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v155; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v156; // ebx
  unsigned int v157; // ecx
  unsigned int v158; // ebx
  unsigned int v159; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v160; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v161; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v162; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v163; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v164; // ebx
  unsigned int v165; // ecx
  Scaleform::Render::Tessellator::ScanChainType **v166; // ecx
  unsigned int v167; // edx
  Scaleform::Render::Tessellator::ScanChainType *v168; // edi
  unsigned int v169; // ecx
  unsigned int v170; // eax
  unsigned int Size; // eax
  unsigned int lowerTarget; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargeta; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargetb; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargetc; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargetd; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargete; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargetf; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargetg; // [esp+10h] [ebp-DCh]
  unsigned int lowerTargeth; // [esp+10h] [ebp-DCh]
  Scaleform::Render::Tessellator::MonotoneType *monotone; // [esp+14h] [ebp-D8h]
  Scaleform::Render::Tessellator::MonotoneType *monotonea; // [esp+14h] [ebp-D8h]
  Scaleform::Render::Tessellator::MonotoneType *monotoneb; // [esp+14h] [ebp-D8h]
  Scaleform::Render::Tessellator::MonotoneType *monotonec; // [esp+14h] [ebp-D8h]
  Scaleform::Render::Tessellator::MonotoneType *monotoned; // [esp+14h] [ebp-D8h]
  Scaleform::Render::TessBaseLineIterator<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8> > itUpper; // [esp+18h] [ebp-D4h] BYREF
  unsigned int styleBetween; // [esp+3Ch] [ebp-B0h]
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+40h] [ebp-ACh] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v189; // [esp+4Ch] [ebp-A0h] BYREF
  Scaleform::Render::TessBaseLineIterator<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4> > itLower; // [esp+58h] [ebp-94h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v191; // [esp+7Ch] [ebp-70h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v192; // [esp+88h] [ebp-64h] BYREF
  unsigned int v193; // [esp+94h] [ebp-58h] BYREF
  unsigned int v194; // [esp+98h] [ebp-54h]
  Scaleform::Render::Tessellator::MonoVertexType *v195; // [esp+9Ch] [ebp-50h]
  Scaleform::Render::Tessellator::MonoVertexType v196; // [esp+A0h] [ebp-4Ch] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v197; // [esp+ACh] [ebp-40h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v198; // [esp+B8h] [ebp-34h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v199; // [esp+C4h] [ebp-28h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v200; // [esp+D0h] [ebp-1Ch] BYREF
  unsigned int stopNum; // [esp+DCh] [ebp-10h]
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // [esp+E0h] [ebp-Ch]
  Scaleform::Render::Tessellator::PendingEndType scanLeft; // [esp+E4h] [ebp-8h] BYREF

  v3 = scan->monotone;
  style = v3->style;
  v6 = v3->lowerBase;
  v3->lowerBase = 0;
  scanLeft.vertex = v6->vertexLeft;
  scanLeft.monotone = scan->monotone;
  firstChain = v6->firstChain;
  itLower.Num = v6->numChains;
  itLower.VertexRightmost = v6->vertexRight;
  itLower.Chain = &scanLeft;
  vertexLeft = v6->vertexLeft;
  styleBetween = style;
  itLower.Index = firstChain;
  itLower.VertexLeft = vertexLeft;
  itLower.Elements = &this->PendingEnds;
  vertex = this->PendingEnds.Pages[firstChain >> 4][firstChain & 0xF].vertex;
  lowerBase = v6;
  styleLeft = v6->styleLeft;
  itLower.VertexRight = vertex;
  itLower.Style = styleLeft;
  v11 = upperBase->firstChain;
  numChains = upperBase->numChains;
  vertexRight = upperBase->vertexRight;
  itUpper.Chain = scan;
  v14 = upperBase->vertexLeft;
  rightAbove = upperBase->styleLeft;
  itUpper.Index = v11;
  itUpper.VertexLeft = v14;
  itUpper.Elements = &this->ChainsAbove;
  itUpper.VertexRight = this->ChainsAbove.Pages[v11 >> 4][v11 & 0xF].vertex;
  itLower.FlagFirst = 1;
  itUpper.Num = numChains;
  itUpper.VertexRightmost = vertexRight;
  itUpper.FlagFirst = 1;
  stopNum = itLower.Num < numChains;
LABEL_2:
  itUpper.Style = rightAbove;
  while ( 1 )
  {
    v16 = itLower.VertexLeft;
    v17 = itLower.VertexRight;
    if ( (itLower.VertexLeft != itLower.VertexRight || itUpper.VertexLeft != -1 && itUpper.VertexRight != -1)
      && (itUpper.VertexLeft != itUpper.VertexRight || itLower.VertexLeft != -1 && itLower.VertexRight != -1)
      && (itLower.VertexLeft != itLower.VertexRight || itUpper.VertexLeft != itUpper.VertexRight) )
    {
      if ( itLower.Style == styleBetween )
        goto LABEL_27;
      Chain = itLower.Chain;
      Scaleform::Render::Tessellator::replaceMonotone(this, itLower.Chain, styleBetween);
      v19 = Chain->monotone;
      if ( v16 != -1 )
      {
        v20 = v16 | 0x80000000;
        v21 = v19->start == 0;
        val.next = 0;
        val.srcVer = v16 | 0x80000000;
        val.aaVer = v16 | 0x80000000;
        if ( v21 )
        {
          v22 = this->MonoVertices.Size >> 4;
          if ( v22 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v23 = this->MonoVertices.Pages[v22];
          v24 = this->MonoVertices.Size & 0xF;
          v23[v24].srcVer = val.srcVer;
          next = val.next;
          v26 = &v23[v24];
          v26->aaVer = val.aaVer;
          v26->next = next;
          ++this->MonoVertices.Size;
          v27 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v19->d.m.prevIdx2 = -1;
          v19->d.m.prevIdx1 = -1;
          v19->start = v27;
          v19->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v28 = &this->MonoVertices.Pages[v19->d.m.lastIdx >> 4][v19->d.m.lastIdx & 0xF];
          if ( v28->srcVer == v20 )
            goto LABEL_20;
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            &this->MonoVertices,
            &val);
          v28->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          lastIdx = v19->d.m.lastIdx;
          v19->d.m.prevIdx2 = v19->d.m.prevIdx1;
          v19->d.m.prevIdx1 = lastIdx;
          v19->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        v17 = itLower.VertexRight;
      }
LABEL_20:
      if ( v17 != -1 )
      {
        v21 = v19->start == 0;
        v189.next = 0;
        v189.srcVer = v17 & 0x7FFFFFFF;
        v189.aaVer = v17 & 0x7FFFFFFF;
        if ( v21 )
        {
          v30 = this->MonoVertices.Size >> 4;
          if ( v30 >= this->MonoVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              this->MonoVertices.Size >> 4);
          v31 = this->MonoVertices.Size & 0xF;
          v32 = this->MonoVertices.Pages[v30];
          v32[v31].srcVer = v189.srcVer;
          v33 = v189.next;
          v34 = &v32[v31];
          v34->aaVer = v189.aaVer;
          v34->next = v33;
          ++this->MonoVertices.Size;
          v35 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v19->d.m.prevIdx2 = -1;
          v19->d.m.prevIdx1 = -1;
          v19->start = v35;
          v19->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
        else
        {
          v36 = &this->MonoVertices.Pages[v19->d.m.lastIdx >> 4][v19->d.m.lastIdx & 0xF];
          if ( v36->srcVer != (v17 & 0x7FFFFFFF) )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              &v189);
            v36->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
            v37 = v19->d.m.lastIdx;
            v19->d.m.prevIdx2 = v19->d.m.prevIdx1;
            v19->d.m.prevIdx1 = v37;
            v19->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
LABEL_27:
      v38 = itLower.Chain->monotone;
      if ( itUpper.VertexLeft == -1 )
        goto LABEL_37;
      v39 = itUpper.VertexLeft | 0x80000000;
      if ( v38->start )
      {
        monotone = (Scaleform::Render::Tessellator::MonotoneType *)&this->MonoVertices.Pages[v38->d.m.lastIdx >> 4][v38->d.m.lastIdx & 0xF];
        if ( monotone->start == (Scaleform::Render::Tessellator::MonoVertexType *)v39 )
          goto LABEL_37;
        v42 = this->MonoVertices.Size >> 4;
        lowerTargeta = v42;
        if ( v42 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v42);
          v42 = lowerTargeta;
        }
        v43 = this->MonoVertices.Pages[v42];
        v44 = this->MonoVertices.Size & 0xF;
        v43[v44].srcVer = v39;
        v45 = &v43[v44];
        v45->aaVer = v39;
        v45->next = 0;
        ++this->MonoVertices.Size;
        monotone->d.m.prevIdx1 = (unsigned int)&this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v46 = v38->d.m.lastIdx;
        v38->d.m.prevIdx2 = v38->d.m.prevIdx1;
        v38->d.m.prevIdx1 = v46;
      }
      else
      {
        v40 = this->MonoVertices.Size >> 4;
        lowerTarget = v40;
        if ( v40 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v40);
          v40 = lowerTarget;
        }
        v41 = &this->MonoVertices.Pages[v40][this->MonoVertices.Size & 0xF];
        v41->srcVer = v39;
        v41->aaVer = v39;
        v41->next = 0;
        ++this->MonoVertices.Size;
        v38->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v38->d.m.prevIdx2 = -1;
        v38->d.m.prevIdx1 = -1;
      }
      v38->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_37:
      if ( itUpper.VertexRight != -1 )
      {
        v47 = itUpper.VertexRight & 0x7FFFFFFF;
        if ( !v38->start )
        {
          v48 = this->MonoVertices.Size >> 4;
          lowerTargetb = v48;
          if ( v48 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v48);
            v48 = lowerTargetb;
          }
          v49 = &this->MonoVertices.Pages[v48][this->MonoVertices.Size & 0xF];
          v49->srcVer = v47;
          v49->aaVer = v47;
          v49->next = 0;
          ++this->MonoVertices.Size;
          v38->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v38->d.m.prevIdx2 = -1;
          v38->d.m.prevIdx1 = -1;
LABEL_46:
          v38->d.m.lastIdx = this->MonoVertices.Size - 1;
          goto LABEL_47;
        }
        monotonea = (Scaleform::Render::Tessellator::MonotoneType *)&this->MonoVertices.Pages[v38->d.m.lastIdx >> 4][v38->d.m.lastIdx & 0xF];
        if ( monotonea->start != (Scaleform::Render::Tessellator::MonoVertexType *)v47 )
        {
          v50 = this->MonoVertices.Size >> 4;
          lowerTargetc = v50;
          if ( v50 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v50);
            v50 = lowerTargetc;
          }
          v51 = this->MonoVertices.Pages[v50];
          v52 = this->MonoVertices.Size & 0xF;
          v51[v52].srcVer = v47;
          v53 = &v51[v52];
          v53->aaVer = v47;
          v53->next = 0;
          ++this->MonoVertices.Size;
          monotonea->d.m.prevIdx1 = (unsigned int)&this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v54 = v38->d.m.lastIdx;
          v38->d.m.prevIdx2 = v38->d.m.prevIdx1;
          v38->d.m.prevIdx1 = v54;
          goto LABEL_46;
        }
      }
LABEL_47:
      itUpper.Chain->monotone = itLower.Chain->monotone;
    }
    if ( itUpper.Style == styleBetween && itUpper.Chain->monotone )
      goto LABEL_72;
    if ( !itUpper.Style )
    {
      itUpper.Chain->monotone = 0;
      goto LABEL_72;
    }
    Scaleform::Render::Tessellator::replaceMonotone(
      this,
      (Scaleform::Render::Tessellator::PendingEndType *)itUpper.Chain,
      itUpper.Style);
    v55 = itUpper.Chain->monotone;
    if ( itUpper.VertexLeft != -1 )
    {
      v56 = itUpper.VertexLeft | 0x80000000;
      if ( !v55->start )
      {
        v57 = this->MonoVertices.Size >> 4;
        lowerTargetd = v57;
        if ( v57 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v57);
          v57 = lowerTargetd;
        }
        v58 = &this->MonoVertices.Pages[v57][this->MonoVertices.Size & 0xF];
        v58->srcVer = v56;
        v58->aaVer = v56;
        v58->next = 0;
        ++this->MonoVertices.Size;
        v55->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v55->d.m.prevIdx2 = -1;
        v55->d.m.prevIdx1 = -1;
LABEL_61:
        v55->d.m.lastIdx = this->MonoVertices.Size - 1;
        goto LABEL_62;
      }
      monotoneb = (Scaleform::Render::Tessellator::MonotoneType *)&this->MonoVertices.Pages[v55->d.m.lastIdx >> 4][v55->d.m.lastIdx & 0xF];
      if ( monotoneb->start != (Scaleform::Render::Tessellator::MonoVertexType *)v56 )
      {
        v59 = this->MonoVertices.Size >> 4;
        lowerTargete = v59;
        if ( v59 >= this->MonoVertices.NumPages )
        {
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
            &this->MonoVertices,
            v59);
          v59 = lowerTargete;
        }
        v60 = this->MonoVertices.Pages[v59];
        v61 = this->MonoVertices.Size & 0xF;
        v60[v61].srcVer = v56;
        v62 = &v60[v61];
        v62->aaVer = v56;
        v62->next = 0;
        ++this->MonoVertices.Size;
        monotoneb->d.m.prevIdx1 = (unsigned int)&this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
        v63 = v55->d.m.lastIdx;
        v55->d.m.prevIdx2 = v55->d.m.prevIdx1;
        v55->d.m.prevIdx1 = v63;
        goto LABEL_61;
      }
    }
LABEL_62:
    if ( itUpper.VertexRight == -1 )
      goto LABEL_72;
    v64 = itUpper.VertexRight & 0x7FFFFFFF;
    if ( v55->start )
    {
      monotonec = (Scaleform::Render::Tessellator::MonotoneType *)&this->MonoVertices.Pages[v55->d.m.lastIdx >> 4][v55->d.m.lastIdx & 0xF];
      if ( monotonec->start == (Scaleform::Render::Tessellator::MonoVertexType *)v64 )
        goto LABEL_72;
      v67 = this->MonoVertices.Size >> 4;
      lowerTargetg = v67;
      if ( v67 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v67);
        v67 = lowerTargetg;
      }
      v68 = this->MonoVertices.Pages[v67];
      v69 = this->MonoVertices.Size & 0xF;
      v68[v69].srcVer = v64;
      v70 = &v68[v69];
      v70->aaVer = v64;
      v70->next = 0;
      ++this->MonoVertices.Size;
      monotonec->d.m.prevIdx1 = (unsigned int)&this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v71 = v55->d.m.lastIdx;
      v55->d.m.prevIdx2 = v55->d.m.prevIdx1;
      v55->d.m.prevIdx1 = v71;
    }
    else
    {
      v65 = this->MonoVertices.Size >> 4;
      lowerTargetf = v65;
      if ( v65 >= this->MonoVertices.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
          &this->MonoVertices,
          v65);
        v65 = lowerTargetf;
      }
      v66 = &this->MonoVertices.Pages[v65][this->MonoVertices.Size & 0xF];
      v66->srcVer = v64;
      v66->aaVer = v64;
      v66->next = 0;
      ++this->MonoVertices.Size;
      v55->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
      v55->d.m.prevIdx2 = -1;
      v55->d.m.prevIdx1 = -1;
    }
    v55->d.m.lastIdx = this->MonoVertices.Size - 1;
LABEL_72:
    if ( itLower.Num == stopNum )
      break;
    itLower.FlagFirst = 0;
    if ( itLower.Num )
    {
      Pages = this->PendingEnds.Pages;
      itLower.VertexLeft = itLower.VertexRight;
      v73 = itLower.Index + 1;
      v74 = &Pages[itLower.Index >> 4][itLower.Index & 0xF];
      --itLower.Num;
      ++itLower.Index;
      itLower.Chain = v74;
      if ( itLower.Num )
        itLower.VertexRight = Pages[v73 >> 4][v73 & 0xF].vertex;
      else
        itLower.VertexRight = itLower.VertexRightmost;
      v75 = v74->monotone;
      if ( v75 )
        itLower.Style = v75->style;
      else
        itLower.Style = 0;
    }
    itUpper.FlagFirst = 0;
    if ( itUpper.Num )
    {
      v76 = this->ChainsAbove.Pages;
      itUpper.VertexLeft = itUpper.VertexRight;
      v77 = itUpper.Index + 1;
      v78 = &v76[itUpper.Index >> 4][itUpper.Index & 0xF];
      --itUpper.Num;
      ++itUpper.Index;
      itUpper.Chain = v78;
      if ( itUpper.Num )
      {
        v79 = v78->chain;
        itUpper.VertexRight = v76[v77 >> 4][v77 & 0xF].vertex;
        rightAbove = v79->rightAbove;
      }
      else
      {
        rightAbove = v78->chain->rightAbove;
        itUpper.VertexRight = itUpper.VertexRightmost;
      }
      goto LABEL_2;
    }
  }
  v80 = itLower.VertexLeft;
  lowerTargeth = itLower.VertexLeft;
  if ( itLower.VertexRight != -1 )
  {
    v80 = itLower.VertexRight;
    lowerTargeth = itLower.VertexRight;
  }
  if ( itUpper.Num && v80 != -1 )
  {
    started = 0;
    monotoned = 0;
    Scaleform::Render::TessBaseLineIterator<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::PendingEndType,4,4>>::Next<int (__cdecl *)(Scaleform::Render::Tessellator::PendingEndType const *)>(
      &itLower,
      (int (__cdecl *)(const Scaleform::Render::Tessellator::PendingEndType *))Scaleform::Render::Tessellator::pendingMonotoneStyle);
    Scaleform::Render::TessBaseLineIterator<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>>::Next<int (__cdecl *)(Scaleform::Render::Tessellator::ScanChainType const *)>(
      &itUpper,
      Scaleform::Render::Tessellator::startingMonotoneStyle);
    v82 = itLower.Chain;
    v83 = itLower.Chain->monotone;
    v84 = styleBetween;
    if ( v83 && v83->style == styleBetween )
    {
      started = Scaleform::Render::Tessellator::startMonotone(this, styleBetween);
      *started = *v82->monotone;
      v85 = v82->monotone;
      monotoned = started;
      v85->start = 0;
      v85->d.m.lastIdx = -1;
      v85->d.m.prevIdx1 = -1;
      v85->d.m.prevIdx2 = -1;
      v85->style = v84;
      v85->lowerBase = 0;
    }
    while ( 1 )
    {
      v86 = itUpper.Chain;
      if ( itUpper.Num )
      {
        if ( itUpper.VertexLeft != itUpper.VertexRight )
        {
          Scaleform::Render::Tessellator::replaceMonotone(
            this,
            (Scaleform::Render::Tessellator::PendingEndType *)itUpper.Chain,
            v84);
          v121 = v86->monotone;
          v21 = v121->start == 0;
          v200.next = 0;
          v200.srcVer = lowerTargeth | 0x80000000;
          v200.aaVer = lowerTargeth | 0x80000000;
          if ( v21 )
          {
            v122 = this->MonoVertices.Size >> 4;
            if ( v122 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v123 = this->MonoVertices.Size & 0xF;
            v124 = this->MonoVertices.Pages[v122];
            v124[v123].srcVer = v200.srcVer;
            v125 = v200.next;
            v126 = &v124[v123];
            v126->aaVer = v200.aaVer;
            v126->next = v125;
            ++this->MonoVertices.Size;
            v127 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
            v121->d.m.prevIdx2 = -1;
            v121->d.m.prevIdx1 = -1;
            v121->start = v127;
            v121->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
          else
          {
            v128 = &this->MonoVertices.Pages[v121->d.m.lastIdx >> 4][v121->d.m.lastIdx & 0xF];
            if ( v128->srcVer != (lowerTargeth | 0x80000000) )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                &this->MonoVertices,
                &v200);
              v128->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                       & 0xF];
              v129 = v121->d.m.lastIdx;
              v121->d.m.prevIdx2 = v121->d.m.prevIdx1;
              v121->d.m.prevIdx1 = v129;
              v121->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
          }
          v21 = v121->start == 0;
          v198.next = 0;
          v198.srcVer = lowerTargeth & 0x7FFFFFFF;
          v198.aaVer = lowerTargeth & 0x7FFFFFFF;
          if ( v21 )
          {
            v130 = this->MonoVertices.Size >> 4;
            if ( v130 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v131 = this->MonoVertices.Size & 0xF;
            v132 = this->MonoVertices.Pages[v130];
            v132[v131].srcVer = v198.srcVer;
            v133 = v198.next;
            v134 = &v132[v131];
            v134->aaVer = v198.aaVer;
            v134->next = v133;
            ++this->MonoVertices.Size;
            v135 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
            v121->d.m.prevIdx2 = -1;
            v121->d.m.prevIdx1 = -1;
            v121->start = v135;
            v121->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
          else
          {
            v136 = &this->MonoVertices.Pages[v121->d.m.lastIdx >> 4][v121->d.m.lastIdx & 0xF];
            if ( v136->srcVer != (lowerTargeth & 0x7FFFFFFF) )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                &this->MonoVertices,
                &v198);
              v136->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                       & 0xF];
              v137 = v121->d.m.lastIdx;
              v121->d.m.prevIdx2 = v121->d.m.prevIdx1;
              v121->d.m.prevIdx1 = v137;
              v121->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
          }
          v105 = itUpper.Chain->monotone;
          if ( itUpper.VertexLeft != -1 )
          {
            v21 = v105->start == 0;
            v192.next = 0;
            v192.srcVer = itUpper.VertexLeft | 0x80000000;
            v192.aaVer = itUpper.VertexLeft | 0x80000000;
            if ( v21 )
            {
              v138 = this->MonoVertices.Size >> 4;
              if ( v138 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v139 = this->MonoVertices.Size & 0xF;
              v140 = this->MonoVertices.Pages[v138];
              v140[v139].srcVer = v192.srcVer;
              v141 = v192.next;
              v142 = &v140[v139];
              v142->aaVer = v192.aaVer;
              v142->next = v141;
              ++this->MonoVertices.Size;
              v143 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
              v105->d.m.prevIdx2 = -1;
              v105->d.m.prevIdx1 = -1;
              v105->start = v143;
              v105->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
            else
            {
              v144 = &this->MonoVertices.Pages[v105->d.m.lastIdx >> 4][v105->d.m.lastIdx & 0xF];
              if ( v144->srcVer != (itUpper.VertexLeft | 0x80000000) )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                  &this->MonoVertices,
                  &v192);
                v144->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                         & 0xF];
                v145 = v105->d.m.lastIdx;
                v105->d.m.prevIdx2 = v105->d.m.prevIdx1;
                v105->d.m.prevIdx1 = v145;
                v105->d.m.lastIdx = this->MonoVertices.Size - 1;
              }
            }
          }
          if ( itUpper.VertexRight != -1 )
          {
            v21 = v105->start == 0;
            v195 = 0;
            v193 = itUpper.VertexRight & 0x7FFFFFFF;
            v194 = itUpper.VertexRight & 0x7FFFFFFF;
            if ( v21 )
            {
              p_MonoVertices = &this->MonoVertices;
              v146 = this->MonoVertices.Size >> 4;
              if ( v146 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v116 = &this->MonoVertices.Pages[v146][this->MonoVertices.Size & 0xF];
              aaVer = v194;
              v116->srcVer = v193;
              v118 = v195;
              goto LABEL_119;
            }
            v119 = &this->MonoVertices.Pages[v105->d.m.lastIdx >> 4][v105->d.m.lastIdx & 0xF];
            if ( v119->srcVer != (itUpper.VertexRight & 0x7FFFFFFF) )
            {
              v120 = (Scaleform::Render::Tessellator::MonoVertexType *)&v193;
              goto LABEL_149;
            }
          }
        }
      }
      else
      {
        itUpper.Chain->monotone = started;
        if ( !started )
        {
          v87 = Scaleform::Render::Tessellator::startMonotone(this, v84);
          v21 = itLower.VertexLeft == -1;
          v88 = v87;
          v86->monotone = v87;
          if ( !v21 )
          {
            v21 = v87->start == 0;
            v189.next = 0;
            v189.srcVer = itLower.VertexLeft | 0x80000000;
            v189.aaVer = itLower.VertexLeft | 0x80000000;
            if ( v21 )
            {
              v89 = this->MonoVertices.Size >> 4;
              if ( v89 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v90 = this->MonoVertices.Size & 0xF;
              v91 = this->MonoVertices.Pages[v89];
              v91[v90].srcVer = v189.srcVer;
              v92 = v189.next;
              v93 = &v91[v90];
              v93->aaVer = v189.aaVer;
              v93->next = v92;
              ++this->MonoVertices.Size;
              v94 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
              v88->d.m.prevIdx2 = -1;
              v88->d.m.prevIdx1 = -1;
              v88->start = v94;
              v88->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
            else
            {
              v95 = &this->MonoVertices.Pages[v87->d.m.lastIdx >> 4][v87->d.m.lastIdx & 0xF];
              if ( v95->srcVer != (itLower.VertexLeft | 0x80000000) )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                  &this->MonoVertices,
                  &v189);
                v95->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                        & 0xF];
                v96 = v88->d.m.lastIdx;
                v88->d.m.prevIdx2 = v88->d.m.prevIdx1;
                v88->d.m.prevIdx1 = v96;
                v88->d.m.lastIdx = this->MonoVertices.Size - 1;
              }
            }
          }
          if ( itLower.VertexRight != -1 )
          {
            v21 = v88->start == 0;
            val.next = 0;
            val.srcVer = itLower.VertexRight & 0x7FFFFFFF;
            val.aaVer = itLower.VertexRight & 0x7FFFFFFF;
            if ( v21 )
            {
              v97 = this->MonoVertices.Size >> 4;
              if ( v97 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v98 = this->MonoVertices.Size & 0xF;
              v99 = this->MonoVertices.Pages[v97];
              v99[v98].srcVer = val.srcVer;
              v100 = val.next;
              v101 = &v99[v98];
              v101->aaVer = val.aaVer;
              v101->next = v100;
              ++this->MonoVertices.Size;
              v102 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
              v88->d.m.prevIdx2 = -1;
              v88->d.m.prevIdx1 = -1;
              v88->start = v102;
              v88->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
            else
            {
              v103 = &this->MonoVertices.Pages[v88->d.m.lastIdx >> 4][v88->d.m.lastIdx & 0xF];
              if ( v103->srcVer != (itLower.VertexRight & 0x7FFFFFFF) )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                  &this->MonoVertices,
                  &val);
                v103->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                         & 0xF];
                v104 = v88->d.m.lastIdx;
                v88->d.m.prevIdx2 = v88->d.m.prevIdx1;
                v88->d.m.prevIdx1 = v104;
                v88->d.m.lastIdx = this->MonoVertices.Size - 1;
              }
            }
          }
        }
        v105 = itUpper.Chain->monotone;
        if ( itUpper.VertexLeft != -1 )
        {
          v21 = v105->start == 0;
          v191.next = 0;
          v191.srcVer = itUpper.VertexLeft | 0x80000000;
          v191.aaVer = itUpper.VertexLeft | 0x80000000;
          if ( v21 )
          {
            v106 = this->MonoVertices.Size >> 4;
            if ( v106 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v107 = this->MonoVertices.Size & 0xF;
            v108 = this->MonoVertices.Pages[v106];
            v108[v107].srcVer = v191.srcVer;
            v109 = v191.next;
            v110 = &v108[v107];
            v110->aaVer = v191.aaVer;
            v110->next = v109;
            ++this->MonoVertices.Size;
            v111 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
            v105->d.m.prevIdx2 = -1;
            v105->d.m.prevIdx1 = -1;
            v105->start = v111;
            v105->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
          else
          {
            v112 = &this->MonoVertices.Pages[v105->d.m.lastIdx >> 4][v105->d.m.lastIdx & 0xF];
            if ( v112->srcVer != (itUpper.VertexLeft | 0x80000000) )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                &this->MonoVertices,
                &v191);
              v112->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                       & 0xF];
              v113 = v105->d.m.lastIdx;
              v105->d.m.prevIdx2 = v105->d.m.prevIdx1;
              v105->d.m.prevIdx1 = v113;
              v105->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
          }
        }
        if ( itUpper.VertexRight != -1 )
        {
          v21 = v105->start == 0;
          v196.next = 0;
          v196.srcVer = itUpper.VertexRight & 0x7FFFFFFF;
          v196.aaVer = itUpper.VertexRight & 0x7FFFFFFF;
          if ( v21 )
          {
            p_MonoVertices = &this->MonoVertices;
            v115 = this->MonoVertices.Size >> 4;
            if ( v115 >= this->MonoVertices.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                &this->MonoVertices,
                this->MonoVertices.Size >> 4);
            v116 = &this->MonoVertices.Pages[v115][this->MonoVertices.Size & 0xF];
            aaVer = v196.aaVer;
            v116->srcVer = v196.srcVer;
            v118 = v196.next;
LABEL_119:
            v116->aaVer = aaVer;
            v116->next = v118;
            ++p_MonoVertices->Size;
            v105->start = &p_MonoVertices->Pages[(p_MonoVertices->Size - 1) >> 4][(p_MonoVertices->Size - 1) & 0xF];
            v105->d.m.prevIdx2 = -1;
            v105->d.m.prevIdx1 = -1;
            v105->d.m.lastIdx = this->MonoVertices.Size - 1;
            goto LABEL_150;
          }
          v119 = &this->MonoVertices.Pages[v105->d.m.lastIdx >> 4][v105->d.m.lastIdx & 0xF];
          if ( v119->srcVer != (itUpper.VertexRight & 0x7FFFFFFF) )
          {
            v120 = &v196;
LABEL_149:
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              &this->MonoVertices,
              v120);
            v119->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                     & 0xF];
            v147 = v105->d.m.lastIdx;
            v105->d.m.prevIdx2 = v105->d.m.prevIdx1;
            v105->d.m.prevIdx1 = v147;
            v105->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
LABEL_150:
      v148 = itUpper.Chain;
      if ( itUpper.Style != styleBetween || !itUpper.Chain->monotone )
      {
        if ( itUpper.Style )
        {
          Scaleform::Render::Tessellator::replaceMonotone(
            this,
            (Scaleform::Render::Tessellator::PendingEndType *)itUpper.Chain,
            itUpper.Style);
          v149 = v148->monotone;
          if ( itUpper.VertexLeft != -1 )
          {
            v197.next = 0;
            v197.srcVer = itUpper.VertexLeft | 0x80000000;
            v197.aaVer = itUpper.VertexLeft | 0x80000000;
            if ( v149->start )
            {
              v156 = &this->MonoVertices.Pages[v149->d.m.lastIdx >> 4][v149->d.m.lastIdx & 0xF];
              if ( v156->srcVer != (itUpper.VertexLeft | 0x80000000) )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                  &this->MonoVertices,
                  &v197);
                v156->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                         & 0xF];
                v157 = v149->d.m.lastIdx;
                v149->d.m.prevIdx2 = v149->d.m.prevIdx1;
                v149->d.m.prevIdx1 = v157;
                v149->d.m.lastIdx = this->MonoVertices.Size - 1;
              }
            }
            else
            {
              v150 = this->MonoVertices.Size >> 4;
              if ( v150 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v151 = this->MonoVertices.Size & 0xF;
              v152 = this->MonoVertices.Pages[v150];
              v152[v151].srcVer = v197.srcVer;
              v153 = v197.next;
              v154 = &v152[v151];
              v154->aaVer = v197.aaVer;
              v154->next = v153;
              ++this->MonoVertices.Size;
              v155 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
              v149->d.m.prevIdx2 = -1;
              v149->d.m.prevIdx1 = -1;
              v149->start = v155;
              v149->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
          }
          if ( itUpper.VertexRight != -1 )
          {
            v21 = v149->start == 0;
            v199.next = 0;
            v199.srcVer = itUpper.VertexRight & 0x7FFFFFFF;
            v199.aaVer = itUpper.VertexRight & 0x7FFFFFFF;
            if ( v21 )
            {
              v158 = this->MonoVertices.Size >> 4;
              if ( v158 >= this->MonoVertices.NumPages )
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  this->MonoVertices.Size >> 4);
              v159 = this->MonoVertices.Size & 0xF;
              v160 = this->MonoVertices.Pages[v158];
              v160[v159].srcVer = v199.srcVer;
              v161 = v199.next;
              v162 = &v160[v159];
              v162->aaVer = v199.aaVer;
              v162->next = v161;
              ++this->MonoVertices.Size;
              v163 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
              v149->d.m.prevIdx2 = -1;
              v149->d.m.prevIdx1 = -1;
              v149->start = v163;
              v149->d.m.lastIdx = this->MonoVertices.Size - 1;
            }
            else
            {
              v164 = &this->MonoVertices.Pages[v149->d.m.lastIdx >> 4][v149->d.m.lastIdx & 0xF];
              if ( v164->srcVer != (itUpper.VertexRight & 0x7FFFFFFF) )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                  &this->MonoVertices,
                  &v199);
                v164->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                         & 0xF];
                v165 = v149->d.m.lastIdx;
                v149->d.m.prevIdx2 = v149->d.m.prevIdx1;
                v149->d.m.prevIdx1 = v165;
                v149->d.m.lastIdx = this->MonoVertices.Size - 1;
              }
            }
          }
        }
        else
        {
          itUpper.Chain->monotone = 0;
        }
      }
      if ( !itUpper.Num )
        break;
      v166 = itUpper.Elements->Pages;
      itUpper.VertexLeft = itUpper.VertexRight;
      v167 = itUpper.Index + 1;
      v168 = &v166[itUpper.Index >> 4][itUpper.Index & 0xF];
      --itUpper.Num;
      ++itUpper.Index;
      itUpper.Chain = v168;
      if ( itUpper.Num )
        itUpper.VertexRight = v166[v167 >> 4][v167 & 0xF].vertex;
      else
        itUpper.VertexRight = itUpper.VertexRightmost;
      v169 = v168->chain->rightAbove;
      started = monotoned;
      v84 = styleBetween;
      itUpper.Style = v169;
    }
  }
  if ( lowerBase == &this->BaseLines.Pages[(this->BaseLines.Size - 1) >> 4][(this->BaseLines.Size - 1) & 0xF] )
  {
    v170 = lowerBase->firstChain;
    if ( v170 < this->PendingEnds.Size )
      this->PendingEnds.Size = v170;
    Size = this->BaseLines.Size;
    if ( Size )
      this->BaseLines.Size = Size - 1;
    upperBase->numChains = 0;
  }
  else
  {
    upperBase->numChains = 0;
  }
}
