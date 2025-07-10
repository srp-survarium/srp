void __thiscall Scaleform::Render::Tessellator::sweepScanbeam(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *aet,
        float yb)
{
  const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType *,4,8> *v3; // eax
  unsigned int v4; // edx
  Scaleform::Render::Tessellator::MonoChainType *v6; // ebx
  bool v7; // zf
  unsigned int v8; // ebp
  Scaleform::Render::Tessellator::ScanChainType *v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // ebp
  unsigned int Size; // eax
  Scaleform::Render::Tessellator::ScanChainType *v13; // ebx
  unsigned int posScan; // edx
  const Scaleform::Render::Tessellator::MonoChainType *chain; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  Scaleform::Render::Tessellator::ScanChainType *v18; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v19; // ebx
  unsigned int v20; // eax
  unsigned int v21; // eax
  Scaleform::Render::Tessellator::ScanChainType *v22; // ecx
  signed int vertex; // ebp
  Scaleform::Render::Tessellator::ScanChainType *v24; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v25; // edi
  signed int v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // eax
  Scaleform::Render::Tessellator::MonotoneType *v30; // edi
  Scaleform::Render::Tessellator::BaseLineType *v31; // edx
  unsigned int v32; // ebx
  unsigned int v33; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v34; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v35; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v36; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v37; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v38; // ebx
  unsigned int v39; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v40; // edi
  unsigned int v41; // ecx
  Scaleform::Render::Tessellator::BaseLineType *v42; // ebx
  unsigned int v43; // ebx
  unsigned int v44; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v45; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v46; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v47; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v48; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v49; // ebx
  unsigned int v50; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v51; // eax
  Scaleform::Render::Tessellator::MonotoneType *v52; // eax
  Scaleform::Render::Tessellator::BaseLineType *v53; // edx
  Scaleform::Render::Tessellator::MonotoneType *v54; // edi
  Scaleform::Render::Tessellator::BaseLineType *v55; // ebx
  unsigned int v56; // ebx
  unsigned int v57; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v58; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v59; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v60; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v61; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v62; // ebx
  unsigned int v63; // ecx
  Scaleform::Render::Tessellator::MonotoneType *monotone; // edi
  Scaleform::Render::Tessellator::BaseLineType *lowerBase; // edx
  unsigned int v66; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v67; // ecx
  unsigned int v68; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v70; // eax
  unsigned int lastIdx; // edx
  Scaleform::Render::Tessellator::MonotoneType *v72; // edi
  Scaleform::Render::Tessellator::BaseLineType *v73; // edx
  unsigned int v74; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v75; // ecx
  unsigned int v76; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v77; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v78; // eax
  unsigned int v79; // edx
  Scaleform::Render::Tessellator::ScanChainType *v80; // eax
  Scaleform::Render::Tessellator::ScanChainType *v81; // edi
  Scaleform::Render::Tessellator::ScanChainType *v82; // ebx
  unsigned int v83; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v84; // edi
  Scaleform::Render::Tessellator::BaseLineType *v85; // eax
  Scaleform::Render::Tessellator::MonotoneType *v86; // edi
  Scaleform::Render::Tessellator::BaseLineType *v87; // eax
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_MonoVertices; // ebx
  unsigned int v89; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v90; // eax
  unsigned int aaVer; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v92; // edx
  unsigned int v93; // edx
  unsigned int v94; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v95; // ecx
  unsigned int v96; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v97; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v98; // eax
  unsigned int v99; // edx
  Scaleform::Render::Tessellator::BaseLineType *v100; // eax
  unsigned int v101; // ecx
  unsigned int v102; // edx
  unsigned int v103; // ebx
  Scaleform::Render::Tessellator::MonotoneType *v104; // edi
  Scaleform::Render::Tessellator::BaseLineType *v105; // eax
  unsigned int v106; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v107; // ecx
  unsigned int v108; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v109; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v110; // eax
  unsigned int v111; // edx
  Scaleform::Render::Tessellator::MonotoneType *v112; // edi
  Scaleform::Render::Tessellator::BaseLineType *v113; // edx
  unsigned int v114; // ebx
  unsigned int v115; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v116; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v117; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v118; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v119; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v120; // ebx
  unsigned int v121; // ecx
  Scaleform::Render::Tessellator::ScanChainType *v122; // ecx
  signed int v123; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v124; // ebp
  Scaleform::Render::Tessellator::MonotoneType *v125; // edi
  Scaleform::Render::Tessellator::BaseLineType *v126; // eax
  unsigned int v127; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v128; // eax
  unsigned int v129; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v130; // ecx
  unsigned int v131; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v132; // eax
  unsigned int v133; // edx
  Scaleform::Render::Tessellator::ScanChainType *v134; // ecx
  signed int v135; // ebx
  Scaleform::Render::Tessellator::MonotoneType *v136; // edi
  Scaleform::Render::Tessellator::BaseLineType *v137; // edx
  unsigned int v138; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v139; // eax
  unsigned int v140; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v141; // ecx
  unsigned int v142; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v143; // eax
  unsigned int v144; // edx
  Scaleform::Render::Tessellator::ScanChainType *v145; // ebp
  Scaleform::Render::Tessellator::MonotoneType *v146; // edi
  unsigned int v147; // ebx
  Scaleform::Render::Tessellator::BaseLineType *v148; // eax
  unsigned int v149; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v150; // eax
  unsigned int v151; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v152; // ecx
  unsigned int v153; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v154; // eax
  unsigned int v155; // edx
  unsigned int v156; // ecx
  unsigned int v157; // ebp
  Scaleform::Render::Tessellator::ScanChainType *v158; // ebx
  Scaleform::Render::Tessellator::ScanChainType *v159; // eax
  unsigned int j; // ecx
  Scaleform::Render::Tessellator::MonoChainType *v161; // eax
  Scaleform::Render::Tessellator::ScanChainType *v162; // [esp+0h] [ebp-D0h]
  Scaleform::Render::Tessellator::MonoVertexType *v163; // [esp+18h] [ebp-B8h]
  Scaleform::Render::Tessellator::MonoVertexType *v164; // [esp+18h] [ebp-B8h]
  unsigned int v165; // [esp+18h] [ebp-B8h]
  unsigned int v166; // [esp+18h] [ebp-B8h]
  Scaleform::Render::Tessellator::MonoVertexType *v167; // [esp+18h] [ebp-B8h]
  unsigned int v168; // [esp+18h] [ebp-B8h]
  unsigned int v169; // [esp+18h] [ebp-B8h]
  unsigned int v170; // [esp+18h] [ebp-B8h]
  unsigned int v171; // [esp+18h] [ebp-B8h]
  unsigned int v172; // [esp+18h] [ebp-B8h]
  unsigned int v173; // [esp+18h] [ebp-B8h]
  unsigned int prevAbove; // [esp+1Ch] [ebp-B4h]
  unsigned int prevAbovea; // [esp+1Ch] [ebp-B4h]
  unsigned int prevAboveb; // [esp+1Ch] [ebp-B4h]
  unsigned int prevAbovec; // [esp+1Ch] [ebp-B4h]
  unsigned int prevAboved; // [esp+1Ch] [ebp-B4h]
  Scaleform::Render::Tessellator::MonoVertexType *prevAbovee; // [esp+1Ch] [ebp-B4h]
  unsigned int prevAbovef; // [esp+1Ch] [ebp-B4h]
  Scaleform::Render::Tessellator::MonoVertexType *prevAboveg; // [esp+1Ch] [ebp-B4h]
  unsigned int prevAboveh; // [esp+1Ch] [ebp-B4h]
  Scaleform::Render::Tessellator::MonoVertexType *prevAbovei; // [esp+1Ch] [ebp-B4h]
  Scaleform::Render::Tessellator::ScanChainType *leftBelow; // [esp+20h] [ebp-B0h]
  Scaleform::Render::Tessellator::ScanChainType *leftBelowa; // [esp+20h] [ebp-B0h]
  Scaleform::Render::Tessellator::ScanChainType *leftAbove; // [esp+24h] [ebp-ACh]
  unsigned int i; // [esp+28h] [ebp-A8h]
  unsigned int ia; // [esp+28h] [ebp-A8h]
  unsigned int ib; // [esp+28h] [ebp-A8h]
  Scaleform::Render::Tessellator::ScanChainType *thisBelow; // [esp+2Ch] [ebp-A4h]
  Scaleform::Render::Tessellator::ScanChainType *thisBelowa; // [esp+2Ch] [ebp-A4h]
  unsigned int above; // [esp+30h] [ebp-A0h]
  Scaleform::Render::Tessellator::ScanChainType *thisAbove; // [esp+34h] [ebp-9Ch]
  Scaleform::Render::Tessellator::ScanChainType *thisAbovea; // [esp+34h] [ebp-9Ch]
  unsigned int v195; // [esp+38h] [ebp-98h]
  Scaleform::Render::Tessellator::MonoVertexType *v196; // [esp+38h] [ebp-98h]
  Scaleform::Render::Tessellator::MonoVertexType *v197; // [esp+38h] [ebp-98h]
  Scaleform::Render::Tessellator::MonoVertexType *v198; // [esp+38h] [ebp-98h]
  Scaleform::Render::Tessellator::BaseLineType upperBase; // [esp+3Ch] [ebp-94h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+58h] [ebp-78h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v201; // [esp+64h] [ebp-6Ch] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v202; // [esp+70h] [ebp-60h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v203; // [esp+7Ch] [ebp-54h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v204; // [esp+88h] [ebp-48h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v205; // [esp+94h] [ebp-3Ch] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v206; // [esp+A0h] [ebp-30h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v207; // [esp+ACh] [ebp-24h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v208; // [esp+B8h] [ebp-18h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v209; // [esp+C4h] [ebp-Ch] BYREF

  v3 = aet;
  v4 = 0;
  this->LastX = -1.0e30;
  this->ChainsAbove.Size = 0;
  for ( i = 0; v4 < v3->Size; i = v4 )
  {
    v6 = v3->Pages[v4 >> 4][v4 & 0xF];
    v7 = (v6->flags & 4) == 0;
    v6->posScan = v4;
    if ( !v7 )
    {
      v8 = this->ChainsAbove.Size >> 4;
      if ( v8 >= this->ChainsAbove.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
          &this->ChainsAbove,
          this->ChainsAbove.Size >> 4);
        v4 = i;
      }
      v9 = &this->ChainsAbove.Pages[v8][this->ChainsAbove.Size & 0xF];
      v9->chain = v6;
      v9->monotone = 0;
      v9->vertex = -1;
      ++this->ChainsAbove.Size;
      v3 = aet;
    }
    ++v4;
  }
  v10 = 0;
  upperBase.y = yb;
  v11 = 0;
  prevAbove = -1;
  leftBelow = 0;
  leftAbove = 0;
  upperBase.numChains = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        Size = this->ChainsBelow.Size;
        if ( v10 >= Size )
          break;
        if ( v11 >= this->ChainsAbove.Size )
          goto LABEL_17;
        v13 = &this->ChainsBelow.Pages[v10 >> 4][v10 & 0xF];
        posScan = v13->chain->posScan;
        thisAbove = &this->ChainsAbove.Pages[v11 >> 4][v11 & 0xF];
        chain = thisAbove->chain;
        v16 = thisAbove->chain->posScan;
        if ( v16 == posScan )
        {
          v17 = Scaleform::Render::Tessellator::addEventVertex(this, chain, yb, 0);
          thisAbove->vertex = v17;
          ++v10;
          v13->vertex = v17;
          ++v11;
        }
        else if ( v16 >= posScan )
        {
          v13->vertex = Scaleform::Render::Tessellator::addEventVertex(this, v13->chain, yb, 1);
          ++v10;
        }
        else
        {
          thisAbove->vertex = Scaleform::Render::Tessellator::addEventVertex(this, chain, yb, 1);
          ++v11;
        }
      }
      if ( v11 >= this->ChainsAbove.Size )
        break;
      v18 = &this->ChainsAbove.Pages[v11 >> 4][v11 & 0xF];
      v18->vertex = Scaleform::Render::Tessellator::addEventVertex(this, v18->chain, yb, 1);
      ++v11;
    }
LABEL_17:
    if ( v10 >= Size )
      break;
    v19 = &this->ChainsBelow.Pages[v10 >> 4][v10 & 0xF];
    v19->vertex = Scaleform::Render::Tessellator::addEventVertex(this, v19->chain, yb, 1);
    ++v10;
  }
  v20 = 0;
  ia = 0;
LABEL_20:
  above = v20;
  while ( 2 )
  {
    while ( 2 )
    {
      while ( 1 )
      {
        v21 = this->ChainsBelow.Size;
        if ( ia >= v21 || above >= this->ChainsAbove.Size )
          break;
        v22 = this->ChainsBelow.Pages[ia >> 4];
        vertex = v22[ia & 0xF].vertex;
        v24 = &v22[ia & 0xF];
        v25 = &this->ChainsAbove.Pages[above >> 4][above & 0xF];
        v26 = v25->vertex;
        thisBelow = v24;
        thisAbovea = v25;
        v27 = 1;
        if ( vertex != v26 )
          v27 = 3 - (v25->chain->posScan < v24->chain->posScan);
        v28 = v27 - 1;
        if ( !v28 )
        {
          if ( vertex != -1 )
          {
            if ( leftBelow )
            {
              monotone = leftBelow->monotone;
              if ( monotone )
              {
                lowerBase = monotone->lowerBase;
                if ( !lowerBase )
                {
                  v7 = monotone->start == 0;
                  v206.next = 0;
                  v206.srcVer = vertex;
                  v206.aaVer = vertex;
                  if ( v7 )
                  {
                    v66 = this->MonoVertices.Size >> 4;
                    prevAbovea = v66;
                    if ( v66 >= this->MonoVertices.NumPages )
                    {
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                        &this->MonoVertices,
                        v66);
                      v66 = prevAbovea;
                    }
                    v67 = this->MonoVertices.Pages[v66];
                    v68 = this->MonoVertices.Size & 0xF;
                    v67[v68].srcVer = v206.srcVer;
                    next = v206.next;
                    v70 = &v67[v68];
                    v70->aaVer = v206.aaVer;
                    v70->next = next;
                    ++this->MonoVertices.Size;
                    monotone->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
                    monotone->d.m.prevIdx2 = -1;
                    monotone->d.m.prevIdx1 = -1;
                  }
                  else
                  {
                    v163 = &this->MonoVertices.Pages[monotone->d.m.lastIdx >> 4][monotone->d.m.lastIdx & 0xF];
                    if ( v163->srcVer == vertex )
                      goto LABEL_99;
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                      &this->MonoVertices,
                      &v206);
                    v163->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                              - 1)
                                                                                             & 0xF];
                    lastIdx = monotone->d.m.lastIdx;
                    monotone->d.m.prevIdx2 = monotone->d.m.prevIdx1;
                    monotone->d.m.prevIdx1 = lastIdx;
                  }
                  monotone->d.m.lastIdx = this->MonoVertices.Size - 1;
                  goto LABEL_99;
                }
                if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == lowerBase->y )
                {
                  lowerBase->vertexRight = vertex & 0xFFFFFFF;
                }
                else if ( vertex >= 0 )
                {
                  Scaleform::Render::Tessellator::connectPendingToRight(this, leftBelow, vertex);
                }
                else
                {
                  Scaleform::Render::Tessellator::connectPendingToLeft(this, leftBelow, vertex);
                }
              }
            }
LABEL_99:
            if ( leftAbove )
            {
              v72 = leftAbove->monotone;
              if ( v72 )
              {
                v73 = v72->lowerBase;
                if ( v73 )
                {
                  if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == v73->y )
                  {
                    v73->vertexRight = vertex & 0xFFFFFFF;
                  }
                  else if ( vertex >= 0 )
                  {
                    Scaleform::Render::Tessellator::connectPendingToRight(this, leftAbove, vertex);
                  }
                  else
                  {
                    Scaleform::Render::Tessellator::connectPendingToLeft(this, leftAbove, vertex);
                  }
                }
                else
                {
                  v7 = v72->start == 0;
                  v204.next = 0;
                  v204.srcVer = vertex;
                  v204.aaVer = vertex;
                  if ( v7 )
                  {
                    v74 = this->MonoVertices.Size >> 4;
                    prevAboveb = v74;
                    if ( v74 >= this->MonoVertices.NumPages )
                    {
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                        &this->MonoVertices,
                        v74);
                      v74 = prevAboveb;
                    }
                    v75 = this->MonoVertices.Pages[v74];
                    v76 = this->MonoVertices.Size & 0xF;
                    v75[v76].srcVer = v204.srcVer;
                    v77 = v204.next;
                    v78 = &v75[v76];
                    v78->aaVer = v204.aaVer;
                    v78->next = v77;
                    ++this->MonoVertices.Size;
                    v72->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                              - 1)
                                                                                             & 0xF];
                    v72->d.m.prevIdx2 = -1;
                    v72->d.m.prevIdx1 = -1;
                  }
                  else
                  {
                    v164 = &this->MonoVertices.Pages[v72->d.m.lastIdx >> 4][v72->d.m.lastIdx & 0xF];
                    if ( v164->srcVer == vertex )
                      goto LABEL_114;
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                      &this->MonoVertices,
                      &v204);
                    v164->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                              - 1)
                                                                                             & 0xF];
                    v79 = v72->d.m.lastIdx;
                    v72->d.m.prevIdx2 = v72->d.m.prevIdx1;
                    v72->d.m.prevIdx1 = v79;
                  }
                  v72->d.m.lastIdx = this->MonoVertices.Size - 1;
                }
              }
            }
LABEL_114:
            if ( upperBase.numChains )
              Scaleform::Render::Tessellator::connectStarting(this, leftBelow, &upperBase);
            v165 = ia + 1;
            v195 = above + 1;
            while ( 1 )
            {
              v80 = 0;
              v81 = 0;
              prevAbovec = 0;
              if ( v165 < this->ChainsBelow.Size )
              {
                v80 = &this->ChainsBelow.Pages[v165 >> 4][v165 & 0xF];
                prevAbovec = (unsigned int)v80;
              }
              if ( v195 < this->ChainsAbove.Size )
              {
                v81 = &this->ChainsAbove.Pages[v195 >> 4][v195 & 0xF];
                v80 = (Scaleform::Render::Tessellator::ScanChainType *)prevAbovec;
              }
              if ( v80 )
              {
                if ( !v81 )
                  goto LABEL_126;
                if ( v80->vertex == v81->vertex )
                  goto LABEL_167;
              }
              if ( v81 && v81->vertex == vertex )
              {
                v82 = thisAbovea;
                ++v195;
                ++above;
                v162 = thisAbovea;
                leftAbove = thisAbovea;
                thisAbovea = &this->ChainsAbove.Pages[above >> 4][above & 0xF];
                Scaleform::Render::Tessellator::startMonotone(this, v162, vertex | 0x80000000);
                if ( v82 )
                {
                  v86 = v82->monotone;
                  if ( v86 )
                  {
                    v87 = v86->lowerBase;
                    if ( v87 )
                    {
                      if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == v87->y )
                      {
                        v87->vertexRight = vertex & 0xFFFFFFF;
                        continue;
                      }
LABEL_138:
                      if ( vertex >= 0 )
                        Scaleform::Render::Tessellator::connectPendingToRight(this, v82, vertex);
                      else
                        Scaleform::Render::Tessellator::connectPendingToLeft(this, v82, vertex);
                      continue;
                    }
                    v7 = v86->start == 0;
                    v208.next = 0;
                    v208.srcVer = vertex;
                    v208.aaVer = vertex;
                    if ( v7 )
                    {
                      p_MonoVertices = &this->MonoVertices;
                      v89 = this->MonoVertices.Size >> 4;
                      prevAboved = v89;
                      if ( v89 >= this->MonoVertices.NumPages )
                      {
                        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                          &this->MonoVertices,
                          v89);
                        v89 = prevAboved;
                      }
                      v90 = &this->MonoVertices.Pages[v89][this->MonoVertices.Size & 0xF];
                      aaVer = v208.aaVer;
                      v90->srcVer = v208.srcVer;
                      v92 = v208.next;
                      goto LABEL_164;
                    }
                    prevAbovee = &this->MonoVertices.Pages[v86->d.m.lastIdx >> 4][v86->d.m.lastIdx & 0xF];
                    if ( prevAbovee->srcVer != vertex )
                    {
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                        &this->MonoVertices,
                        &v208);
                      prevAbovee->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
                      v93 = v86->d.m.lastIdx;
                      v86->d.m.prevIdx2 = v86->d.m.prevIdx1;
                      v86->d.m.prevIdx1 = v93;
                      v86->d.m.lastIdx = this->MonoVertices.Size - 1;
                    }
                  }
                }
              }
              else
              {
LABEL_126:
                if ( !v80 || v80->vertex != vertex )
                {
LABEL_167:
                  v103 = vertex | 0x80000000;
                  if ( thisBelow )
                  {
                    v104 = thisBelow->monotone;
                    if ( v104 )
                    {
                      v105 = v104->lowerBase;
                      if ( v105 )
                      {
                        if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == v105->y )
                          v105->vertexRight = vertex & 0xFFFFFFF;
                        else
                          Scaleform::Render::Tessellator::connectPendingToLeft(this, thisBelow, vertex | 0x80000000);
                      }
                      else
                      {
                        v7 = v104->start == 0;
                        v205.next = 0;
                        v205.srcVer = vertex | 0x80000000;
                        v205.aaVer = vertex | 0x80000000;
                        if ( v7 )
                        {
                          v106 = this->MonoVertices.Size >> 4;
                          v166 = v106;
                          if ( v106 >= this->MonoVertices.NumPages )
                          {
                            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                              &this->MonoVertices,
                              v106);
                            v106 = v166;
                          }
                          v107 = this->MonoVertices.Pages[v106];
                          v108 = this->MonoVertices.Size & 0xF;
                          v107[v108].srcVer = v205.srcVer;
                          v109 = v205.next;
                          v110 = &v107[v108];
                          v110->aaVer = v205.aaVer;
                          v110->next = v109;
                          ++this->MonoVertices.Size;
                          v103 = vertex | 0x80000000;
                          v104->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
                          v104->d.m.prevIdx2 = -1;
                          v104->d.m.prevIdx1 = -1;
                        }
                        else
                        {
                          v167 = &this->MonoVertices.Pages[v104->d.m.lastIdx >> 4][v104->d.m.lastIdx & 0xF];
                          if ( v167->srcVer == v103 )
                            goto LABEL_180;
                          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                            &this->MonoVertices,
                            &v205);
                          v167->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
                          v111 = v104->d.m.lastIdx;
                          v104->d.m.prevIdx2 = v104->d.m.prevIdx1;
                          v104->d.m.prevIdx1 = v111;
                        }
                        v104->d.m.lastIdx = this->MonoVertices.Size - 1;
                      }
                    }
                  }
LABEL_180:
                  if ( thisBelow->chain->rightBelow != thisAbovea->chain->rightAbove )
                  {
                    Scaleform::Render::Tessellator::startMonotone(this, thisAbovea, v103);
                    goto LABEL_201;
                  }
                  if ( leftAbove )
                  {
                    v112 = leftAbove->monotone;
                    if ( v112 )
                    {
                      v113 = v112->lowerBase;
                      if ( v113 )
                      {
                        if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == v113->y )
                        {
                          v113->vertexRight = vertex & 0xFFFFFFF;
                          thisAbovea->monotone = thisBelow->monotone;
                        }
                        else
                        {
                          if ( vertex >= 0 )
                            Scaleform::Render::Tessellator::connectPendingToRight(this, leftAbove, vertex);
                          else
                            Scaleform::Render::Tessellator::connectPendingToLeft(this, leftAbove, vertex);
                          thisAbovea->monotone = thisBelow->monotone;
                        }
                        goto LABEL_201;
                      }
                      v7 = v112->start == 0;
                      v207.next = 0;
                      v207.srcVer = vertex;
                      v207.aaVer = vertex;
                      if ( v7 )
                      {
                        v114 = this->MonoVertices.Size >> 4;
                        if ( v114 >= this->MonoVertices.NumPages )
                          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                            &this->MonoVertices,
                            this->MonoVertices.Size >> 4);
                        v115 = this->MonoVertices.Size & 0xF;
                        v116 = this->MonoVertices.Pages[v114];
                        v116[v115].srcVer = v207.srcVer;
                        v117 = v207.next;
                        v118 = &v116[v115];
                        v118->aaVer = v207.aaVer;
                        v118->next = v117;
                        ++this->MonoVertices.Size;
                        v119 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                           & 0xF];
                        v112->d.m.prevIdx2 = -1;
                        v112->d.m.prevIdx1 = -1;
                        v112->start = v119;
                        v112->d.m.lastIdx = this->MonoVertices.Size - 1;
                        thisAbovea->monotone = thisBelow->monotone;
                        goto LABEL_201;
                      }
                      v120 = &this->MonoVertices.Pages[v112->d.m.lastIdx >> 4][v112->d.m.lastIdx & 0xF];
                      if ( v120->srcVer != vertex )
                      {
                        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                          &this->MonoVertices,
                          &v207);
                        v120->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                                  - 1)
                                                                                                 & 0xF];
                        v121 = v112->d.m.lastIdx;
                        v112->d.m.prevIdx2 = v112->d.m.prevIdx1;
                        v112->d.m.prevIdx1 = v121;
                        v112->d.m.lastIdx = this->MonoVertices.Size - 1;
                      }
                    }
                  }
                  thisAbovea->monotone = thisBelow->monotone;
                  goto LABEL_201;
                }
                v82 = thisBelow;
                v83 = ++ia >> 4;
                ++v165;
                leftBelowa = thisBelow;
                thisBelow = &this->ChainsBelow.Pages[v83][ia & 0xF];
                if ( !leftBelowa )
                  continue;
                v84 = v82->monotone;
                if ( v84 )
                {
                  v85 = v84->lowerBase;
                  if ( v85 )
                  {
                    if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y != v85->y )
                    {
                      v82 = leftBelowa;
                      Scaleform::Render::Tessellator::connectPendingToLeft(this, leftBelowa, vertex | 0x80000000);
                      goto LABEL_155;
                    }
                    v85->vertexRight = vertex & 0xFFFFFFF;
                    goto LABEL_154;
                  }
                  v7 = v84->start == 0;
                  v201.next = 0;
                  v201.srcVer = vertex | 0x80000000;
                  v201.aaVer = vertex | 0x80000000;
                  if ( v7 )
                  {
                    v94 = this->MonoVertices.Size >> 4;
                    prevAbovef = v94;
                    if ( v94 >= this->MonoVertices.NumPages )
                    {
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                        &this->MonoVertices,
                        v94);
                      v94 = prevAbovef;
                    }
                    v95 = this->MonoVertices.Pages[v94];
                    v96 = this->MonoVertices.Size & 0xF;
                    v95[v96].srcVer = v201.srcVer;
                    v97 = v201.next;
                    v98 = &v95[v96];
                    v98->aaVer = v201.aaVer;
                    v98->next = v97;
                    ++this->MonoVertices.Size;
                    v84->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                              - 1)
                                                                                             & 0xF];
                    v84->d.m.prevIdx2 = -1;
                    v84->d.m.prevIdx1 = -1;
LABEL_153:
                    v84->d.m.lastIdx = this->MonoVertices.Size - 1;
                  }
                  else
                  {
                    prevAboveg = &this->MonoVertices.Pages[v84->d.m.lastIdx >> 4][v84->d.m.lastIdx & 0xF];
                    if ( prevAboveg->srcVer != (vertex | 0x80000000) )
                    {
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                        &this->MonoVertices,
                        &v201);
                      prevAboveg->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
                      v99 = v84->d.m.lastIdx;
                      v84->d.m.prevIdx2 = v84->d.m.prevIdx1;
                      v84->d.m.prevIdx1 = v99;
                      goto LABEL_153;
                    }
                  }
LABEL_154:
                  v82 = leftBelowa;
                }
LABEL_155:
                v86 = v82->monotone;
                if ( !v86 )
                  continue;
                v100 = v86->lowerBase;
                if ( v100 )
                {
                  if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == v100->y )
                  {
                    v100->vertexRight = vertex & 0xFFFFFFF;
                    continue;
                  }
                  goto LABEL_138;
                }
                v7 = v86->start == 0;
                v203.next = 0;
                v203.srcVer = vertex;
                v203.aaVer = vertex;
                if ( v7 )
                {
                  p_MonoVertices = &this->MonoVertices;
                  v101 = this->MonoVertices.Size >> 4;
                  prevAboveh = v101;
                  if ( v101 >= this->MonoVertices.NumPages )
                  {
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                      &this->MonoVertices,
                      v101);
                    v101 = prevAboveh;
                  }
                  v90 = &this->MonoVertices.Pages[v101][this->MonoVertices.Size & 0xF];
                  aaVer = v203.aaVer;
                  v90->srcVer = v203.srcVer;
                  v92 = v203.next;
LABEL_164:
                  v90->aaVer = aaVer;
                  v90->next = v92;
                  ++p_MonoVertices->Size;
                  v86->start = &p_MonoVertices->Pages[(p_MonoVertices->Size - 1) >> 4][(p_MonoVertices->Size - 1) & 0xF];
                  v86->d.m.prevIdx2 = -1;
                  v86->d.m.prevIdx1 = -1;
                  v86->d.m.lastIdx = this->MonoVertices.Size - 1;
                  continue;
                }
                prevAbovei = &this->MonoVertices.Pages[v86->d.m.lastIdx >> 4][v86->d.m.lastIdx & 0xF];
                if ( prevAbovei->srcVer != vertex )
                {
                  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                    &this->MonoVertices,
                    &v203);
                  prevAbovei->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                                  - 1)
                                                                                                 & 0xF];
                  v102 = v86->d.m.lastIdx;
                  v86->d.m.prevIdx2 = v86->d.m.prevIdx1;
                  v86->d.m.prevIdx1 = v102;
                  v86->d.m.lastIdx = this->MonoVertices.Size - 1;
                }
              }
            }
          }
          if ( upperBase.numChains )
            Scaleform::Render::Tessellator::connectStarting(this, leftBelow, &upperBase);
          v25->monotone = v24->monotone;
LABEL_201:
          ++ia;
          prevAbove = above;
          leftBelow = thisBelow;
          leftAbove = thisAbovea;
          v20 = above + 1;
          goto LABEL_20;
        }
        v29 = v28 - 1;
        if ( v29 )
        {
          if ( v29 == 1 )
          {
            if ( leftBelow )
            {
              v30 = leftBelow->monotone;
              if ( v30 )
              {
                v31 = v30->lowerBase;
                if ( v31 )
                {
                  if ( this->MeshVertices.Pages[(vertex & 0xFFFFFFFu) >> 4][vertex & 0xF].y == v31->y )
                  {
                    v31->vertexRight = vertex & 0xFFFFFFF;
                  }
                  else if ( vertex >= 0 )
                  {
                    Scaleform::Render::Tessellator::connectPendingToRight(this, leftBelow, vertex);
                  }
                  else
                  {
                    Scaleform::Render::Tessellator::connectPendingToLeft(this, leftBelow, vertex);
                  }
                }
                else
                {
                  v7 = v30->start == 0;
                  val.next = 0;
                  val.srcVer = vertex;
                  val.aaVer = vertex;
                  if ( v7 )
                  {
                    v32 = this->MonoVertices.Size >> 4;
                    if ( v32 >= this->MonoVertices.NumPages )
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                        &this->MonoVertices,
                        this->MonoVertices.Size >> 4);
                    v33 = this->MonoVertices.Size & 0xF;
                    v34 = this->MonoVertices.Pages[v32];
                    v34[v33].srcVer = val.srcVer;
                    v35 = val.next;
                    v36 = &v34[v33];
                    v36->aaVer = val.aaVer;
                    v36->next = v35;
                    ++this->MonoVertices.Size;
                    v37 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                      & 0xF];
                    v30->d.m.prevIdx2 = -1;
                    v30->d.m.prevIdx1 = -1;
                    v30->start = v37;
                    v30->d.m.lastIdx = this->MonoVertices.Size - 1;
                  }
                  else
                  {
                    v38 = &this->MonoVertices.Pages[v30->d.m.lastIdx >> 4][v30->d.m.lastIdx & 0xF];
                    if ( v38->srcVer != vertex )
                    {
                      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                        &this->MonoVertices,
                        &val);
                      v38->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                               - 1)
                                                                                              & 0xF];
                      v39 = v30->d.m.lastIdx;
                      v30->d.m.prevIdx2 = v30->d.m.prevIdx1;
                      v30->d.m.prevIdx1 = v39;
                      v30->d.m.lastIdx = this->MonoVertices.Size - 1;
                    }
                  }
                }
              }
            }
            v40 = thisBelow->monotone;
            v41 = thisBelow->vertex | 0x80000000;
            if ( v40 )
            {
              v42 = v40->lowerBase;
              if ( v42 )
              {
                if ( this->MeshVertices.Pages[(thisBelow->vertex & 0xFFFFFFF) >> 4][thisBelow->vertex & 0xF].y == v42->y )
                  v42->vertexRight = thisBelow->vertex & 0xFFFFFFF;
                else
                  Scaleform::Render::Tessellator::connectPendingToLeft(this, thisBelow, thisBelow->vertex | 0x80000000);
              }
              else
              {
                v7 = v40->start == 0;
                v209.next = 0;
                v209.srcVer = v41;
                v209.aaVer = v41;
                if ( v7 )
                {
                  v43 = this->MonoVertices.Size >> 4;
                  if ( v43 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                      &this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v44 = this->MonoVertices.Size & 0xF;
                  v45 = this->MonoVertices.Pages[v43];
                  v45[v44].srcVer = v209.srcVer;
                  v46 = v209.next;
                  v47 = &v45[v44];
                  v47->aaVer = v209.aaVer;
                  v47->next = v46;
                  ++this->MonoVertices.Size;
                  v48 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
                  v40->d.m.prevIdx2 = -1;
                  v40->d.m.prevIdx1 = -1;
                  v40->start = v48;
                  v40->d.m.lastIdx = this->MonoVertices.Size - 1;
                }
                else
                {
                  v49 = &this->MonoVertices.Pages[v40->d.m.lastIdx >> 4][v40->d.m.lastIdx & 0xF];
                  if ( v49->srcVer != v41 )
                  {
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                      &this->MonoVertices,
                      &v209);
                    v49->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                             - 1)
                                                                                            & 0xF];
                    v50 = v40->d.m.lastIdx;
                    v40->d.m.prevIdx2 = v40->d.m.prevIdx1;
                    v40->d.m.prevIdx1 = v50;
                    v40->d.m.lastIdx = this->MonoVertices.Size - 1;
                  }
                }
              }
            }
            if ( upperBase.numChains )
              Scaleform::Render::Tessellator::connectStarting(this, leftBelow, &upperBase);
            Scaleform::Render::Tessellator::addPendingEnd(this, leftAbove, thisBelow, yb);
            ++ia;
            prevAbove = -1;
            leftBelow = thisBelow;
          }
        }
        else if ( leftBelow && (v51 = leftBelow->monotone) != 0 && v51->style )
        {
          if ( upperBase.numChains )
          {
            ++upperBase.numChains;
          }
          else
          {
            upperBase.styleLeft = v25->chain->leftAbove;
            upperBase.numChains = 1;
            upperBase.firstChain = above;
            upperBase.leftAbove = prevAbove;
          }
          if ( !leftAbove )
            goto LABEL_82;
          v52 = leftAbove->monotone;
          if ( !v52 )
            goto LABEL_82;
          v53 = v52->lowerBase;
          if ( !v53 || yb != v53->y )
            goto LABEL_82;
          ++above;
          v53->vertexRight = v26;
          leftAbove = v25;
        }
        else
        {
          if ( leftAbove )
          {
            v54 = leftAbove->monotone;
            if ( v54 )
            {
              v55 = v54->lowerBase;
              if ( v55 )
              {
                if ( this->MeshVertices.Pages[(v26 & 0xFFFFFFFu) >> 4][v26 & 0xF].y == v55->y )
                {
                  v55->vertexRight = v26 & 0xFFFFFFF;
                }
                else if ( v26 >= 0 )
                {
                  Scaleform::Render::Tessellator::connectPendingToRight(this, leftAbove, v26);
                }
                else
                {
                  Scaleform::Render::Tessellator::connectPendingToLeft(this, leftAbove, v26);
                }
              }
              else
              {
                v7 = v54->start == 0;
                v202.next = 0;
                v202.srcVer = v26;
                v202.aaVer = v26;
                if ( v7 )
                {
                  v56 = this->MonoVertices.Size >> 4;
                  if ( v56 >= this->MonoVertices.NumPages )
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                      &this->MonoVertices,
                      this->MonoVertices.Size >> 4);
                  v57 = this->MonoVertices.Size & 0xF;
                  v58 = this->MonoVertices.Pages[v56];
                  v58[v57].srcVer = v202.srcVer;
                  v59 = v202.next;
                  v60 = &v58[v57];
                  v60->aaVer = v202.aaVer;
                  v60->next = v59;
                  ++this->MonoVertices.Size;
                  v61 = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
                  v54->d.m.prevIdx2 = -1;
                  v54->d.m.prevIdx1 = -1;
                  v54->start = v61;
                  v54->d.m.lastIdx = this->MonoVertices.Size - 1;
                }
                else
                {
                  v62 = &this->MonoVertices.Pages[v54->d.m.lastIdx >> 4][v54->d.m.lastIdx & 0xF];
                  if ( v62->srcVer != v26 )
                  {
                    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
                      &this->MonoVertices,
                      &v202);
                    v62->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size
                                                                                             - 1)
                                                                                            & 0xF];
                    v63 = v54->d.m.lastIdx;
                    v54->d.m.prevIdx2 = v54->d.m.prevIdx1;
                    v54->d.m.prevIdx1 = v63;
                    v54->d.m.lastIdx = this->MonoVertices.Size - 1;
                  }
                }
              }
            }
          }
          Scaleform::Render::Tessellator::startMonotone(this, thisAbovea, thisAbovea->vertex | 0x80000000);
          v25 = thisAbovea;
LABEL_82:
          ++above;
          leftAbove = v25;
        }
      }
      if ( above < this->ChainsAbove.Size )
      {
        v122 = this->ChainsAbove.Pages[above >> 4];
        v123 = v122[above & 0xF].vertex;
        v124 = &v122[above & 0xF];
        if ( !leftAbove )
          goto LABEL_220;
        v125 = leftAbove->monotone;
        if ( !v125 )
          goto LABEL_220;
        v126 = v125->lowerBase;
        if ( v126 )
        {
          if ( this->MeshVertices.Pages[(v123 & 0xFFFFFFFu) >> 4][v123 & 0xF].y == v126->y )
          {
            v126->vertexRight = v123 & 0xFFFFFFF;
          }
          else if ( v123 >= 0 )
          {
            Scaleform::Render::Tessellator::connectPendingToRight(this, leftAbove, v123);
          }
          else
          {
            Scaleform::Render::Tessellator::connectPendingToLeft(this, leftAbove, v123);
          }
          goto LABEL_220;
        }
        if ( !v125->start )
        {
          v127 = this->MonoVertices.Size >> 4;
          v168 = v127;
          if ( v127 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v127);
            v127 = v168;
          }
          v128 = &this->MonoVertices.Pages[v127][this->MonoVertices.Size & 0xF];
          v128->srcVer = v123;
          v128->aaVer = v123;
          v128->next = 0;
          ++this->MonoVertices.Size;
          v125->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
          v125->d.m.prevIdx2 = -1;
          v125->d.m.prevIdx1 = -1;
          goto LABEL_219;
        }
        v196 = &this->MonoVertices.Pages[v125->d.m.lastIdx >> 4][v125->d.m.lastIdx & 0xF];
        if ( v196->srcVer != v123 )
        {
          v129 = this->MonoVertices.Size >> 4;
          v169 = v129;
          if ( v129 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v129);
            v129 = v169;
          }
          v130 = this->MonoVertices.Pages[v129];
          v131 = this->MonoVertices.Size & 0xF;
          v130[v131].srcVer = v123;
          v132 = &v130[v131];
          v132->aaVer = v123;
          v132->next = 0;
          ++this->MonoVertices.Size;
          v196->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v133 = v125->d.m.lastIdx;
          v125->d.m.prevIdx2 = v125->d.m.prevIdx1;
          v125->d.m.prevIdx1 = v133;
LABEL_219:
          v125->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
LABEL_220:
        Scaleform::Render::Tessellator::startMonotone(this, v124, v124->vertex | 0x80000000);
        ++above;
        leftAbove = v124;
        continue;
      }
      break;
    }
    if ( ia < v21 )
    {
      v134 = this->ChainsBelow.Pages[ia >> 4];
      v135 = v134[ia & 0xF].vertex;
      thisBelowa = &v134[ia & 0xF];
      if ( leftBelow )
      {
        v136 = leftBelow->monotone;
        if ( v136 )
        {
          v137 = v136->lowerBase;
          if ( v137 )
          {
            if ( this->MeshVertices.Pages[(v135 & 0xFFFFFFFu) >> 4][v135 & 0xF].y == v137->y )
            {
              v137->vertexRight = v135 & 0xFFFFFFF;
            }
            else if ( v135 >= 0 )
            {
              Scaleform::Render::Tessellator::connectPendingToRight(this, leftBelow, v135);
            }
            else
            {
              Scaleform::Render::Tessellator::connectPendingToLeft(this, leftBelow, v135);
            }
          }
          else
          {
            if ( v136->start )
            {
              v197 = &this->MonoVertices.Pages[v136->d.m.lastIdx >> 4][v136->d.m.lastIdx & 0xF];
              if ( v197->srcVer == v135 )
                goto LABEL_239;
              v140 = this->MonoVertices.Size >> 4;
              v171 = v140;
              if ( v140 >= this->MonoVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  v140);
                v140 = v171;
              }
              v141 = this->MonoVertices.Pages[v140];
              v142 = this->MonoVertices.Size & 0xF;
              v141[v142].srcVer = v135;
              v143 = &v141[v142];
              v143->aaVer = v135;
              v143->next = 0;
              ++this->MonoVertices.Size;
              v197->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                       & 0xF];
              v144 = v136->d.m.lastIdx;
              v136->d.m.prevIdx2 = v136->d.m.prevIdx1;
              v136->d.m.prevIdx1 = v144;
            }
            else
            {
              v138 = this->MonoVertices.Size >> 4;
              v170 = v138;
              if ( v138 >= this->MonoVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
                  &this->MonoVertices,
                  v138);
                v138 = v170;
              }
              v139 = &this->MonoVertices.Pages[v138][this->MonoVertices.Size & 0xF];
              v139->srcVer = v135;
              v139->aaVer = v135;
              v139->next = 0;
              ++this->MonoVertices.Size;
              v136->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                        & 0xF];
              v136->d.m.prevIdx2 = -1;
              v136->d.m.prevIdx1 = -1;
            }
            v136->d.m.lastIdx = this->MonoVertices.Size - 1;
          }
        }
      }
LABEL_239:
      v145 = thisBelowa;
      v146 = thisBelowa->monotone;
      v147 = thisBelowa->vertex | 0x80000000;
      if ( v146 )
      {
        v148 = v146->lowerBase;
        if ( v148 )
        {
          if ( this->MeshVertices.Pages[(thisBelowa->vertex & 0xFFFFFFF) >> 4][thisBelowa->vertex & 0xF].y == v148->y )
            v148->vertexRight = thisBelowa->vertex & 0xFFFFFFF;
          else
            Scaleform::Render::Tessellator::connectPendingToLeft(this, thisBelowa, v147);
          goto LABEL_253;
        }
        if ( !v146->start )
        {
          v149 = this->MonoVertices.Size >> 4;
          v172 = v149;
          if ( v149 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v149);
            v149 = v172;
          }
          v150 = &this->MonoVertices.Pages[v149][this->MonoVertices.Size & 0xF];
          v150->srcVer = v147;
          v150->aaVer = v147;
          v150->next = 0;
          ++this->MonoVertices.Size;
          v146->start = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1)
                                                                                    & 0xF];
          v146->d.m.prevIdx2 = -1;
          v146->d.m.prevIdx1 = -1;
          goto LABEL_252;
        }
        v198 = &this->MonoVertices.Pages[v146->d.m.lastIdx >> 4][v146->d.m.lastIdx & 0xF];
        if ( v198->srcVer != v147 )
        {
          v151 = this->MonoVertices.Size >> 4;
          v173 = v151;
          if ( v151 >= this->MonoVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              &this->MonoVertices,
              v151);
            v151 = v173;
          }
          v152 = this->MonoVertices.Pages[v151];
          v153 = this->MonoVertices.Size & 0xF;
          v152[v153].srcVer = v147;
          v154 = &v152[v153];
          v154->aaVer = v147;
          v154->next = 0;
          ++this->MonoVertices.Size;
          v198->next = &this->MonoVertices.Pages[(this->MonoVertices.Size - 1) >> 4][(this->MonoVertices.Size - 1) & 0xF];
          v155 = v146->d.m.lastIdx;
          v146->d.m.prevIdx2 = v146->d.m.prevIdx1;
          v146->d.m.prevIdx1 = v155;
LABEL_252:
          v145 = thisBelowa;
          v146->d.m.lastIdx = this->MonoVertices.Size - 1;
        }
      }
LABEL_253:
      if ( upperBase.numChains )
        Scaleform::Render::Tessellator::connectStarting(this, leftBelow, &upperBase);
      Scaleform::Render::Tessellator::addPendingEnd(this, leftAbove, v145, yb);
      ++ia;
      prevAbove = -1;
      leftBelow = v145;
      continue;
    }
    break;
  }
  this->ChainsBelow.Size = 0;
  ib = 0;
  if ( this->ChainsAbove.Size )
  {
    v156 = 0;
    do
    {
      v157 = this->ChainsBelow.Size >> 4;
      v158 = &this->ChainsAbove.Pages[v156 >> 4][v156 & 0xF];
      if ( v157 >= this->ChainsBelow.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::ScanChainType,4,8>::allocPage(
          &this->ChainsBelow,
          this->ChainsBelow.Size >> 4);
        v156 = ib;
      }
      v159 = &this->ChainsBelow.Pages[v157][this->ChainsBelow.Size & 0xF];
      v159->chain = v158->chain;
      v159->monotone = v158->monotone;
      v159->vertex = v158->vertex;
      ++this->ChainsBelow.Size;
      ib = ++v156;
    }
    while ( v156 < this->ChainsAbove.Size );
  }
  for ( j = 0; j < aet->Size; ++j )
  {
    v161 = aet->Pages[j >> 4][j & 0xF];
    v161->leftBelow = v161->leftAbove;
    v161->rightBelow = v161->rightAbove;
    v161->flags &= ~0x10u;
  }
}
