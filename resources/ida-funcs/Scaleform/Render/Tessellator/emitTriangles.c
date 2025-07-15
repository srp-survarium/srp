void __thiscall Scaleform::Render::Tessellator::emitTriangles(Scaleform::Render::Tessellator *this)
{
  unsigned int v2; // ecx
  Scaleform::Render::Tessellator::MonotoneType *v3; // ebp
  unsigned int prevIdx2; // ecx
  int v5; // ebx
  int v6; // ecx
  Scaleform::Render::Tessellator::TriangleType *v7; // edi
  Scaleform::Render::Tessellator::MonoVertexType *v8; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // edx
  int v12; // eax
  Scaleform::Render::Tessellator::InnerQuadType *v13; // edx
  unsigned int v14; // ebx
  unsigned int v15; // edi
  Scaleform::Render::TessMesh *v16; // eax
  unsigned int v17; // ecx
  Scaleform::Render::TessMesh *v18; // eax
  unsigned int *v19; // ebp
  _DWORD *p_cntVer; // edx
  unsigned int v21; // ecx
  int v22; // ebp
  unsigned int v23; // ebp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // ebx
  int v25; // edx
  int v26; // eax
  unsigned int Size; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v28; // ebx
  int v29; // edx
  unsigned int v30; // edi
  Scaleform::Render::Tessellator::TriangleType *v31; // ecx
  int v32; // ebx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v33; // ebx
  unsigned int v34; // edi
  int v35; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v36; // ebx
  int v37; // ecx
  int v38; // edx
  unsigned int v39; // edi
  Scaleform::Render::Tessellator::TriangleType *v40; // edx
  int v41; // ebx
  Scaleform::Render::Tessellator::TriangleType *v42; // edx
  unsigned int v43; // ebx
  Scaleform::Render::Tessellator::OuterEdgeType *v44; // edi
  Scaleform::Render::Tessellator::EdgeAAType *edge; // eax
  unsigned int v46; // eax
  unsigned int v47; // ebx
  unsigned int v48; // edi
  unsigned __int16 v49; // bp
  unsigned int v50; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v51; // ebx
  int v52; // eax
  unsigned int v53; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v54; // ebx
  unsigned int v55; // edi
  int v56; // ebp
  Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *v57; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v58; // edi
  unsigned int v59; // ebx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v60; // edi
  unsigned int v61; // ebx
  Scaleform::Render::Tessellator::TriangleType *v62; // ecx
  unsigned int *v63; // ecx
  unsigned int v64; // ebx
  unsigned int v65; // eax
  int v66; // ecx
  unsigned int v67; // edx
  Scaleform::Render::Tessellator::StarVertexType **v68; // edx
  unsigned int v69; // eax
  unsigned int v70; // edi
  unsigned int v71; // ebx
  unsigned int v72; // ecx
  Scaleform::Render::TessVertex **v73; // edx
  int v74; // eax
  Scaleform::Render::TessVertex *v75; // edx
  int v76; // ecx
  unsigned int v77; // ebp
  unsigned int v78; // eax
  unsigned int v79; // ebp
  unsigned int v80; // ecx
  unsigned int v81; // eax
  Scaleform::Render::Tessellator::StarVertexType **Pages; // edx
  unsigned int starVer; // ecx
  Scaleform::Render::TessVertex **v84; // edx
  Scaleform::Render::TessVertex *v85; // edi
  Scaleform::Render::TessVertex *v86; // edx
  int v87; // ecx
  int v88; // ebx
  unsigned int v89; // edi
  unsigned int v90; // ecx
  Scaleform::Render::TessMesh *v91; // ebp
  unsigned int v92; // eax
  unsigned int v93; // edx
  __int16 v94; // ax
  unsigned int v95; // eax
  unsigned int v96; // eax
  unsigned int Flags1; // ecx
  int v98; // eax
  unsigned int v99; // ecx
  unsigned int v100; // eax
  Scaleform::Render::Tessellator::StarVertexType **v101; // eax
  unsigned int v102; // ecx
  Scaleform::Render::TessMesh *v103; // edx
  unsigned int *Array; // eax
  int v105; // ebx
  int v106; // edi
  int v107; // edx
  unsigned int v108; // eax
  unsigned int v109; // eax
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v113; // edi
  int v114; // ecx
  unsigned int v115; // ebp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v116; // edi
  unsigned int v117; // ebp
  Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *v118; // eax
  unsigned int v119; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v120; // ebx
  int v121; // ecx
  unsigned int v122; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v123; // ebx
  unsigned int v124; // edi
  Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *v125; // eax
  unsigned int v126; // [esp-Ch] [ebp-6Ch]
  int style1; // [esp+10h] [ebp-50h]
  unsigned int style1a; // [esp+10h] [ebp-50h]
  unsigned int style1b; // [esp+10h] [ebp-50h]
  unsigned int j; // [esp+14h] [ebp-4Ch]
  unsigned int v131; // [esp+14h] [ebp-4Ch]
  unsigned int v132; // [esp+14h] [ebp-4Ch]
  unsigned int v133; // [esp+14h] [ebp-4Ch]
  unsigned int v134; // [esp+14h] [ebp-4Ch]
  unsigned int v135; // [esp+14h] [ebp-4Ch]
  unsigned int v136; // [esp+14h] [ebp-4Ch]
  unsigned int i; // [esp+18h] [ebp-48h]
  unsigned int k; // [esp+18h] [ebp-48h]
  unsigned int m; // [esp+18h] [ebp-48h]
  unsigned int v140; // [esp+18h] [ebp-48h]
  unsigned int v141; // [esp+18h] [ebp-48h]
  unsigned int meshIdxc; // [esp+1Ch] [ebp-44h]
  unsigned int meshIdx; // [esp+1Ch] [ebp-44h]
  unsigned int meshIdxa; // [esp+1Ch] [ebp-44h]
  unsigned int meshIdxb; // [esp+1Ch] [ebp-44h]
  unsigned int v146; // [esp+20h] [ebp-40h]
  unsigned int v147; // [esp+20h] [ebp-40h]
  unsigned int v148; // [esp+20h] [ebp-40h]
  unsigned int ver; // [esp+24h] [ebp-3Ch]
  unsigned int vera; // [esp+24h] [ebp-3Ch]
  unsigned int verb; // [esp+24h] [ebp-3Ch]
  unsigned int verc; // [esp+24h] [ebp-3Ch]
  int v153; // [esp+28h] [ebp-38h]
  unsigned int v154; // [esp+28h] [ebp-38h]
  unsigned int *v155; // [esp+28h] [ebp-38h]
  int v156; // [esp+28h] [ebp-38h]
  int v157; // [esp+28h] [ebp-38h]
  unsigned int style2; // [esp+2Ch] [ebp-34h]
  unsigned int style2a; // [esp+2Ch] [ebp-34h]
  unsigned int style2b; // [esp+2Ch] [ebp-34h]
  unsigned int style2c; // [esp+2Ch] [ebp-34h]
  unsigned int style2d; // [esp+2Ch] [ebp-34h]
  Scaleform::Render::Tessellator::EdgeAAType *e2; // [esp+30h] [ebp-30h]
  int v164; // [esp+30h] [ebp-30h]
  unsigned int v165; // [esp+30h] [ebp-30h]
  int v166; // [esp+30h] [ebp-30h]
  int v167; // [esp+30h] [ebp-30h]
  Scaleform::Render::Tessellator::OuterEdgeType *v168; // [esp+34h] [ebp-2Ch]
  int v169; // [esp+34h] [ebp-2Ch]
  int v170; // [esp+38h] [ebp-28h]
  int v171; // [esp+38h] [ebp-28h]
  int Flags; // [esp+38h] [ebp-28h]
  unsigned int v173; // [esp+38h] [ebp-28h]
  unsigned int v174; // [esp+3Ch] [ebp-24h]
  unsigned int cntVer; // [esp+3Ch] [ebp-24h]
  Scaleform::Render::Tessellator::StrokerEdgeType val; // [esp+40h] [ebp-20h] BYREF
  unsigned int v177; // [esp+48h] [ebp-18h]
  unsigned int v178; // [esp+4Ch] [ebp-14h]
  unsigned int v179; // [esp+50h] [ebp-10h]
  _DWORD v180[2]; // [esp+54h] [ebp-Ch] BYREF
  __int16 v181; // [esp+5Ch] [ebp-4h]
  __int16 v182; // [esp+5Eh] [ebp-2h]

  v2 = 0;
  for ( i = 0; v2 < this->Monotones.Size; i = v2 )
  {
    v3 = &this->Monotones.Pages[v2 >> 4][v2 & 0xF];
    if ( v3->d.m.prevIdx1 )
    {
      prevIdx2 = v3->d.m.prevIdx2;
      style2 = prevIdx2;
      v5 = (v3->style != this->Meshes.Pages[prevIdx2 >> 4][prevIdx2 & 0xF].Style1 ? 0 : 8) | 2;
      v153 = 0;
      v6 = 16 * prevIdx2;
      for ( j = v6; ; v6 = j )
      {
        v7 = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&this->MeshTriangles.Arrays->Pages + v6))[(v153 + v3->d.m.lastIdx) >> 4][(v153 + v3->d.m.lastIdx) & 0xF];
        *(_DWORD *)(v7->d.t.v1 + 4) = Scaleform::Render::Tessellator::emitVertex(
                                        this,
                                        style2,
                                        *(_DWORD *)(v7->d.t.v1 + 4),
                                        v3->style,
                                        v5);
        *(_DWORD *)(v7->d.t.v2 + 4) = Scaleform::Render::Tessellator::emitVertex(
                                        this,
                                        style2,
                                        *(_DWORD *)(v7->d.t.v2 + 4),
                                        v3->style,
                                        v5);
        *(_DWORD *)(v7->d.t.v3 + 4) = Scaleform::Render::Tessellator::emitVertex(
                                        this,
                                        style2,
                                        *(_DWORD *)(v7->d.t.v3 + 4),
                                        v3->style,
                                        v5);
        v8 = v7->d.m.v2;
        v7->d.t.v1 = *(_DWORD *)(v7->d.t.v1 + 4) & 0xFFFFFFF;
        v9 = v7->d.m.v3;
        v7->d.t.v2 = v8->aaVer & 0xFFFFFFF;
        v7->d.t.v3 = v9->aaVer & 0xFFFFFFF;
        if ( ++v153 >= v3->d.m.prevIdx1 )
          break;
      }
      v2 = i;
    }
    ++v2;
  }
  v10 = 0;
  for ( k = 0; v10 < this->InnerQuads.Size; k = v10 )
  {
    v11 = v10;
    v12 = v10 & 0xF;
    v13 = this->InnerQuads.Pages[v11 >> 4];
    e2 = v13[v12].e2;
    style2a = (unsigned int)v13[v12].e1;
    v14 = *(_WORD *)(style2a + 8) & 0x7FFF;
    style1 = e2->style & 0x7FFF;
    v15 = Scaleform::Render::Tessellator::setMesh(this, v14, style1);
    v16 = this->Meshes.Pages[v15 >> 4];
    v17 = v16[v15 & 0xF].Style1;
    v18 = &v16[v15 & 0xF];
    if ( !v17 || v14 == v17 )
    {
      v19 = (unsigned int *)e2;
      p_cntVer = (_DWORD *)style2a;
    }
    else
    {
      v19 = (unsigned int *)style2a;
      p_cntVer = &e2->cntVer;
      v21 = v14;
      v14 = style1;
      style1 = v21;
    }
    v146 = p_cntVer[1];
    ver = *v19;
    v154 = v19[1];
    v22 = 0;
    v164 = *p_cntVer;
    style2b = v14;
    if ( ((v18->Flags1 ^ v18->Flags2) & 0x8000) != 0 )
    {
      style2b = style1;
      v22 = 32;
    }
    v23 = v22 | 0xA;
    *(_DWORD *)(v164 + 4) = Scaleform::Render::Tessellator::emitVertex(
                              this,
                              v15,
                              *(_DWORD *)(*p_cntVer + 4),
                              v14,
                              style2b,
                              v23,
                              0);
    *(_DWORD *)(v146 + 4) = Scaleform::Render::Tessellator::emitVertex(
                              this,
                              v15,
                              *(_DWORD *)(v146 + 4),
                              v14,
                              style2b,
                              v23,
                              0);
    *(_DWORD *)(ver + 4) = Scaleform::Render::Tessellator::emitVertex(this, v15, *(_DWORD *)(ver + 4), style1, 2u);
    *(_DWORD *)(v154 + 4) = Scaleform::Render::Tessellator::emitVertex(this, v15, *(_DWORD *)(v154 + 4), style1, 2u);
    Arrays = this->MeshTriangles.Arrays;
    v25 = *(_DWORD *)(v164 + 4);
    v178 = *(_DWORD *)(v146 + 4) & 0xFFFFFFF;
    v179 = *(_DWORD *)(ver + 4) & 0xFFFFFFF;
    v26 = 16 * v15;
    Size = Arrays[v15].Size;
    v28 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)Arrays + v26);
    v29 = v25 & 0xFFFFFFF;
    v30 = Size >> 4;
    v177 = v29;
    v131 = v26;
    if ( v30 >= v28->NumPages )
    {
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
        &this->MeshTriangles,
        v28,
        v30);
      v29 = v177;
      v26 = v131;
    }
    v31 = v28->Pages[v30];
    v32 = v28->Size & 0xF;
    v31[v32].d.t.v1 = v29;
    v31[v32].d.t.v2 = v178;
    v31[v32].d.t.v3 = v179;
    ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v26);
    v33 = this->MeshTriangles.Arrays;
    v34 = *(unsigned int *)((char *)&v33->Size + v26);
    v35 = *(_DWORD *)(v154 + 4);
    v178 = *(_DWORD *)(ver + 4) & 0xFFFFFFF;
    v36 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v33 + v26);
    v37 = v35 & 0xFFFFFFF;
    v38 = *(_DWORD *)(v146 + 4) & 0xFFFFFFF;
    v39 = v34 >> 4;
    v177 = v37;
    v179 = v38;
    if ( v39 >= v36->NumPages )
    {
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
        &this->MeshTriangles,
        v36,
        v39);
      v26 = v131;
      v37 = v177;
    }
    v40 = v36->Pages[v39];
    v41 = v36->Size & 0xF;
    v40[v41].d.t.v1 = v37;
    v42 = &v40[v41];
    v42->d.t.v2 = v178;
    v42->d.t.v3 = v179;
    ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v26);
    v10 = k + 1;
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,bool (__cdecl *)(Scaleform::Render::Tessellator::StrokerEdgeType const &,Scaleform::Render::Tessellator::StrokerEdgeType const &)>(
    (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16> *)&this->OuterEdges,
    0,
    this->OuterEdges.Size,
    (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpOuterEdges);
  v43 = 0;
  for ( m = 0; v43 < this->OuterEdges.Size; m = v43 )
  {
    v44 = &this->OuterEdges.Pages[v43 >> 4][v43 & 0xF];
    v155 = (unsigned int *)v44;
    if ( (v44->outVer & 0x40000000) == 0 )
    {
      edge = v44->edge;
      v180[0] = v44->edge->rayVer;
      v180[1] = edge->cntVer;
      v182 = 0;
      val.node1 = (unsigned int)v180;
      v181 = 0;
      v126 = this->OuterEdges.Size;
      val.node2 = -1;
      v46 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16>,Scaleform::Render::Tessellator::OuterEdgeType,bool (__cdecl *)(Scaleform::Render::Tessellator::OuterEdgeType const &,Scaleform::Render::Tessellator::OuterEdgeType const &)>(
              (const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16> *)&this->OuterEdges,
              0,
              v126,
              &val,
              (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpOuterEdges);
      if ( v46 < this->OuterEdges.Size )
      {
        v168 = &this->OuterEdges.Pages[v46 >> 4][v46 & 0xF];
        if ( v168->edge->cntVer == v44->edge->rayVer )
        {
          v47 = v44->edge->style & 0x7FFF;
          v48 = Scaleform::Render::Tessellator::setMesh(this, v47);
          v49 = v47 != this->Meshes.Pages[v48 >> 4][v48 & 0xF].Style1 ? 0 : 8;
          v170 = *(_DWORD *)(*v155 + 4);
          style2c = Scaleform::Render::Tessellator::emitVertex(
                      this,
                      v48,
                      *(_DWORD *)(*(_DWORD *)*v155 + 4),
                      v47,
                      v49 | 2);
          v165 = Scaleform::Render::Tessellator::emitVertex(this, v48, *(_DWORD *)(v170 + 4), v47, v49 | 2);
          v155[1] = Scaleform::Render::Tessellator::emitVertex(this, v48, v155[1], v47, v49) | 0x40000000;
          v50 = Scaleform::Render::Tessellator::emitVertex(this, v48, v168->outVer, v47, v49) | 0x40000000;
          v168->outVer = v50;
          v51 = this->MeshTriangles.Arrays;
          v174 = v50 & 0xFFFFFFF;
          v52 = 16 * v48;
          v53 = v51[v48].Size;
          v54 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v51 + v52);
          v55 = v53 >> 4;
          v56 = v155[1] & 0xFFFFFFF;
          v132 = v52;
          if ( v55 >= v54->NumPages )
          {
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v54,
              v55);
            v52 = v132;
          }
          v57 = (Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *)&v54->Pages[v55][v54->Size & 0xF];
          v57->v1 = style2c;
          v57->v2 = v165;
          v57->v3 = v56;
          ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v52);
          v58 = this->MeshTriangles.Arrays;
          v59 = *(unsigned int *)((char *)&v58->Size + v52);
          v60 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v58 + v52);
          v61 = v59 >> 4;
          if ( v61 >= v60->NumPages )
          {
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v60,
              v61);
            v52 = v132;
          }
          v62 = v60->Pages[v61];
          v43 = m;
          v63 = (unsigned int *)&v62[v60->Size & 0xF];
          *v63 = v174;
          v63[1] = v56;
          v63[2] = v165;
          ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v52);
        }
      }
    }
    ++v43;
  }
  v64 = 0;
  v140 = 0;
  if ( this->StarVertices.Size )
  {
    while ( 1 )
    {
      v65 = v64 >> 4;
      v66 = v64 & 0xF;
      cntVer = this->StarVertices.Pages[v65][v66].cntVer;
      val.node1 = v65 * 4;
      v166 = v66 * 8;
      v67 = v64;
      do
      {
        if ( ++v67 >= this->StarVertices.Size )
          break;
        v66 = v64 & 0xF;
      }
      while ( cntVer == this->StarVertices.Pages[v67 >> 4][v67 & 0xF].cntVer );
      style2d = v67;
      if ( v64 + 3 == v67 )
        break;
LABEL_39:
      v80 = v64;
      v81 = v67 - 1;
      v173 = v64;
      if ( v64 < v67 )
      {
        do
        {
          Pages = this->StarVertices.Pages;
          verb = Pages[v81 >> 4][v81 & 0xF].starVer;
          starVer = Pages[v80 >> 4][v80 & 0xF].starVer;
          v84 = this->MeshVertices.Pages;
          v85 = v84[verb >> 4];
          meshIdxa = starVer;
          v86 = v84[starVer >> 4];
          v87 = starVer & 0xF;
          v134 = v85[verb & 0xF].Styles[0];
          style1b = v86[v87].Styles[0];
          v157 = v85[verb & 0xF].Flags & 2;
          v88 = v86[v87].Flags & 2;
          v89 = Scaleform::Render::Tessellator::setMesh(this, v134, style1b);
          v90 = v134;
          v91 = &this->Meshes.Pages[v89 >> 4][v89 & 0xF];
          v92 = v91->Style1;
          if ( v92 && v134 != v92 )
          {
            v93 = meshIdxa;
            meshIdxa = verb;
            v134 = style1b;
            v94 = v157;
            style1b = v90;
            v90 = v134;
            v157 = v88;
            verb = v93;
            LOWORD(v88) = v94;
          }
          v95 = v157 | 8;
          v148 = v90;
          if ( ((v91->Flags2 ^ v91->Flags1) & 0x8000) != 0 )
          {
            v148 = style1b;
            v95 = v157 | 0x28;
          }
          v177 = Scaleform::Render::Tessellator::emitVertex(this, v89, verb, v90, v148, v95, 0);
          v96 = Scaleform::Render::Tessellator::emitVertex(this, v89, meshIdxa, style1b, v88);
          Flags1 = v91->Flags1;
          v178 = v96;
          v98 = (((unsigned __int8)v157 & (unsigned __int8)v88 & 2) != 0) + 1;
          if ( ((v91->Flags2 | Flags1) & 0x8000) != 0 )
          {
            v99 = v148;
            v100 = v98 & 0xFFFFFFD3 | 0x24;
          }
          else
          {
            v99 = style1b;
            v100 = v98 | 0x10;
          }
          v119 = Scaleform::Render::Tessellator::emitVertex(this, v89, cntVer, v134, v99, v100, 1);
          v120 = this->MeshTriangles.Arrays;
          v121 = 16 * v89;
          v122 = v120[v89].Size;
          v123 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v120 + v121);
          v124 = v122 >> 4;
          v179 = v119;
          v136 = v121;
          if ( v124 >= v123->NumPages )
          {
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v123,
              v124);
            v121 = v136;
          }
          v125 = (Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *)&v123->Pages[v124][v123->Size & 0xF];
          v125->v1 = v177;
          v125->v2 = v178;
          v125->v3 = v179;
          ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v121);
          v67 = style2d;
          v81 = v173;
          v80 = v173 + 1;
          v173 = v80;
        }
        while ( v80 < style2d );
      }
LABEL_75:
      v64 = v67;
      v140 = v67;
      if ( v67 >= this->StarVertices.Size )
        return;
    }
    v68 = this->StarVertices.Pages;
    v69 = v68[v65][v66].starVer;
    v70 = v64 + 1;
    meshIdxc = v68[(v64 + 1) >> 4][((_BYTE)v64 + 1) & 0xF].starVer;
    v71 = v64 + 2;
    v72 = v68[v71 >> 4][v71 & 0xF].starVer;
    v73 = this->MeshVertices.Pages;
    v171 = (int)&v73[v69 >> 4][v69 & 0xF];
    v133 = *(unsigned __int16 *)(v171 + 12);
    v74 = (int)&v73[meshIdxc >> 4][meshIdxc & 0xF];
    style1a = *(unsigned __int16 *)(v74 + 12);
    v75 = v73[v72 >> 4];
    v76 = v72 & 0xF;
    v77 = v75[v76].Styles[0];
    v156 = *(unsigned __int16 *)(v171 + 16);
    v169 = *(unsigned __int16 *)(v74 + 16);
    Flags = v75[v76].Flags;
    v147 = v77;
    vera = Scaleform::Render::Tessellator::setMesh(this, v133, style1a);
    meshIdx = Scaleform::Render::Tessellator::setMesh(this, style1a, v77);
    v78 = Scaleform::Render::Tessellator::setMesh(this, v77, v133);
    v79 = meshIdx;
    if ( vera == meshIdx || vera == v78 )
    {
      v79 = vera;
    }
    else if ( meshIdx != v78 )
    {
LABEL_38:
      v64 = v140;
      v67 = style2d;
      goto LABEL_39;
    }
    if ( v79 != -1 )
    {
      v101 = this->StarVertices.Pages;
      verc = *(unsigned int *)((char *)&(*(Scaleform::Render::Tessellator::StarVertexType **)((char *)v101 + val.node1))->starVer
                             + v166);
      meshIdxb = v101[v70 >> 4][v70 & 0xF].starVer;
      v102 = v101[v71 >> 4][v71 & 0xF].starVer;
      v179 = -1;
      v178 = -1;
      v177 = -1;
      v141 = v102;
      v103 = this->Meshes.Pages[v79 >> 4];
      if ( ((v103[v79 & 0xF].Flags1 ^ v103[v79 & 0xF].Flags2) & 0x8000) == 0 )
        goto LABEL_63;
      Array = this->ComplexFlags.Array;
      v105 = Array[v133 >> 5] & (1 << (v133 & 0x1F));
      v106 = Array[style1a >> 5] & (1 << (style1a & 0x1F));
      v107 = Array[v147 >> 5] & (1 << (v147 & 0x1F));
      v167 = v107;
      if ( v105 )
      {
        v108 = v147;
        if ( !v106 )
          v108 = style1a;
        v109 = Scaleform::Render::Tessellator::emitVertex(this, v79, verc, v133, v108, v156 | 0x20, 0);
        v107 = v167;
        v177 = v109;
      }
      if ( v106 )
      {
        v110 = v133;
        if ( !v107 )
          v110 = v147;
        v111 = Scaleform::Render::Tessellator::emitVertex(this, v79, meshIdxb, style1a, v110, v169 | 0x20, 0);
        v107 = v167;
        v178 = v111;
      }
      if ( v107 )
      {
        v112 = style1a;
        if ( !v105 )
          v112 = v133;
        v179 = Scaleform::Render::Tessellator::emitVertex(this, v79, v141, v147, v112, Flags | 0x20, 0);
      }
      if ( v177 == -1 )
LABEL_63:
        v177 = Scaleform::Render::Tessellator::emitVertex(this, v79, verc, v133, v156);
      if ( v178 == -1 )
        v178 = Scaleform::Render::Tessellator::emitVertex(this, v79, meshIdxb, style1a, v169);
      if ( v179 == -1 )
        v179 = Scaleform::Render::Tessellator::emitVertex(this, v79, v141, v147, Flags);
      v113 = this->MeshTriangles.Arrays;
      v114 = 16 * v79;
      v115 = v113[v79].Size;
      v116 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v113 + v114);
      v117 = v115 >> 4;
      v135 = v114;
      if ( v117 >= v116->NumPages )
      {
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &this->MeshTriangles,
          v116,
          v117);
        v114 = v135;
      }
      v118 = (Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *)&v116->Pages[v117][v116->Size & 0xF];
      v118->v1 = v177;
      v118->v2 = v178;
      v118->v3 = v179;
      v67 = style2d;
      ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v114);
      goto LABEL_75;
    }
    goto LABEL_38;
  }
}
