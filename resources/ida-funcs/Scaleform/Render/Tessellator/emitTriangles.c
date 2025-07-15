void __thiscall Scaleform::Render::Tessellator::emitTriangles(Scaleform::Render::Tessellator *this)
{
  unsigned int ecx1; // ecx
  Scaleform::Render::Tessellator::MonotoneType *ebp2; // ebp
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
  unsigned int Style1; // ecx
  Scaleform::Render::TessMesh *v18; // eax
  Scaleform::Render::Tessellator::MonoVertexType **v19; // ebp
  unsigned int *v20; // edx
  unsigned int v21; // ecx
  int v22; // ebp
  unsigned int v23; // ebp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // ebx
  int v25; // edx
  int v26; // eax
  unsigned int Size; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v28; // ebx
  unsigned int v29; // edx
  unsigned int v30; // edi
  Scaleform::Render::Tessellator::TriangleType *v31; // ecx
  int v32; // ebx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v33; // ebx
  unsigned int v34; // edi
  unsigned int outVer; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v36; // ebx
  unsigned int v37; // ecx
  unsigned int v38; // edx
  unsigned int v39; // edi
  Scaleform::Render::Tessellator::TriangleType *v40; // edx
  int v41; // ebx
  unsigned int v42; // ebx
  Scaleform::Render::Tessellator::OuterEdgeType *v43; // edi
  Scaleform::Render::Tessellator::MonoVertexType **p_cntVer; // eax
  unsigned int v45; // eax
  unsigned int v46; // ebx
  unsigned int v47; // edi
  unsigned __int16 v48; // bp
  unsigned int v49; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v50; // ebx
  int v51; // eax
  unsigned int v52; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v53; // ebx
  unsigned int v54; // edi
  int v55; // ebp
  Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *v56; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v57; // edi
  unsigned int v58; // ebx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v59; // edi
  unsigned int v60; // ebx
  Scaleform::Render::Tessellator::TriangleType *v61; // ecx
  unsigned int *v62; // ecx
  unsigned int v63; // ebx
  Scaleform::Render::Tessellator::EdgeAAType *v64; // eax
  int v65; // ecx
  unsigned int v66; // edx
  Scaleform::Render::Tessellator::StarVertexType **v67; // edx
  unsigned int v68; // eax
  unsigned int v69; // edi
  unsigned int v70; // ebx
  unsigned int v71; // ecx
  Scaleform::Render::TessVertex **v72; // edx
  int v73; // eax
  Scaleform::Render::TessVertex *v74; // edx
  int v75; // ecx
  unsigned int v76; // ebp
  unsigned int v77; // eax
  unsigned int v78; // ebp
  unsigned int v79; // ecx
  unsigned int v80; // eax
  Scaleform::Render::Tessellator::StarVertexType **Pages; // edx
  unsigned int starVer; // ecx
  Scaleform::Render::TessVertex **v83; // edx
  Scaleform::Render::TessVertex *v84; // edi
  Scaleform::Render::TessVertex *v85; // edx
  int v86; // ecx
  int v87; // ebx
  unsigned int v88; // edi
  unsigned int v89; // ecx
  Scaleform::Render::TessMesh *v90; // ebp
  unsigned int v91; // eax
  unsigned int v92; // edx
  __int16 v93; // ax
  unsigned int v94; // eax
  unsigned int v95; // eax
  unsigned int Flags1; // ecx
  int v97; // eax
  unsigned int v98; // ecx
  unsigned int v99; // eax
  Scaleform::Render::Tessellator::StarVertexType **v100; // eax
  unsigned int v101; // ecx
  Scaleform::Render::TessMesh *v102; // edx
  unsigned int *Array; // eax
  int v104; // ebx
  int v105; // edi
  int v106; // edx
  unsigned int v107; // eax
  unsigned int v108; // eax
  unsigned int v109; // eax
  unsigned int v110; // eax
  unsigned int v111; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v112; // edi
  int v113; // ecx
  unsigned int v114; // ebp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v115; // edi
  unsigned int v116; // ebp
  unsigned int v117; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v118; // ebx
  int v119; // ecx
  unsigned int v120; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v121; // ebx
  unsigned int v122; // edi
  unsigned int v123; // [esp-Ch] [ebp-6Ch]
  int s2; // [esp+10h] [ebp-50h]
  unsigned int s2a; // [esp+10h] [ebp-50h]
  unsigned int s2b; // [esp+10h] [ebp-50h]
  unsigned int s1; // [esp+14h] [ebp-4Ch]
  unsigned int s1a; // [esp+14h] [ebp-4Ch]
  unsigned int s1b; // [esp+14h] [ebp-4Ch]
  unsigned int s1c; // [esp+14h] [ebp-4Ch]
  unsigned int s1d; // [esp+14h] [ebp-4Ch]
  unsigned int s1e; // [esp+14h] [ebp-4Ch]
  unsigned int s1f; // [esp+14h] [ebp-4Ch]
  unsigned int i; // [esp+18h] [ebp-48h]
  unsigned int ia; // [esp+18h] [ebp-48h]
  unsigned int ib; // [esp+18h] [ebp-48h]
  unsigned int ic; // [esp+18h] [ebp-48h]
  unsigned int id; // [esp+18h] [ebp-48h]
  unsigned int m2c; // [esp+1Ch] [ebp-44h]
  unsigned int m2; // [esp+1Ch] [ebp-44h]
  unsigned int m2a; // [esp+1Ch] [ebp-44h]
  unsigned int m2b; // [esp+1Ch] [ebp-44h]
  Scaleform::Render::Tessellator::MonoVertexType *v2; // [esp+20h] [ebp-40h]
  unsigned int v2a; // [esp+20h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v2b; // [esp+20h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v3; // [esp+24h] [ebp-3Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v3a; // [esp+24h] [ebp-3Ch]
  unsigned int v3b; // [esp+24h] [ebp-3Ch]
  Scaleform::Render::Tessellator::MonoVertexType *v3c; // [esp+24h] [ebp-3Ch]
  Scaleform::Render::Tessellator::OuterEdgeType *e1; // [esp+28h] [ebp-38h]
  Scaleform::Render::Tessellator::OuterEdgeType *e1a; // [esp+28h] [ebp-38h]
  Scaleform::Render::Tessellator::OuterEdgeType *e1b; // [esp+28h] [ebp-38h]
  Scaleform::Render::Tessellator::OuterEdgeType *e1c; // [esp+28h] [ebp-38h]
  int e1d; // [esp+28h] [ebp-38h]
  unsigned int endStar; // [esp+2Ch] [ebp-34h]
  unsigned int endStara; // [esp+2Ch] [ebp-34h]
  unsigned int endStarb; // [esp+2Ch] [ebp-34h]
  unsigned int endStarc; // [esp+2Ch] [ebp-34h]
  unsigned int endStard; // [esp+2Ch] [ebp-34h]
  unsigned int c3; // [esp+30h] [ebp-30h]
  unsigned int c3a; // [esp+30h] [ebp-30h]
  unsigned int c3b; // [esp+30h] [ebp-30h]
  unsigned int c3c; // [esp+30h] [ebp-30h]
  unsigned int c3d; // [esp+30h] [ebp-30h]
  Scaleform::Render::Tessellator::OuterEdgeType *f2; // [esp+34h] [ebp-2Ch]
  unsigned int f2a; // [esp+34h] [ebp-2Ch]
  unsigned int i2b; // [esp+38h] [ebp-28h]
  unsigned int i2c; // [esp+38h] [ebp-28h]
  unsigned int i2; // [esp+38h] [ebp-28h]
  unsigned int i2a; // [esp+38h] [ebp-28h]
  unsigned int cntVer; // [esp+3Ch] [ebp-24h]
  unsigned int cntVera; // [esp+3Ch] [ebp-24h]
  Scaleform::Render::Tessellator::OuterEdgeType oppos; // [esp+40h] [ebp-20h] BYREF
  Scaleform::Render::Tessellator::TriangleType tri; // [esp+48h] [ebp-18h] BYREF
  Scaleform::Render::Tessellator::EdgeAAType edgeAA; // [esp+54h] [ebp-Ch] BYREF

  ecx1 = 0;
  for ( i = 0; ecx1 < this->Monotones.Size; i = ecx1 )
  {
    ebp2 = &this->Monotones.Pages[ecx1 >> 4][ecx1 & 0xF];
    if ( ebp2->d.m.prevIdx1 )
    {
      prevIdx2 = ebp2->d.m.prevIdx2;
      endStar = prevIdx2;
      v5 = (ebp2->style != this->Meshes.Pages[prevIdx2 >> 4][prevIdx2 & 0xF].Style1 ? 0 : 8) | 2;
      e1 = 0;
      v6 = 16 * prevIdx2;
      for ( s1 = v6; ; v6 = s1 )
      {
        v7 = &(*(Scaleform::Render::Tessellator::TriangleType ***)((char *)&this->MeshTriangles.Arrays->Pages + v6))[((unsigned int)e1 + ebp2->d.m.lastIdx) >> 4][((unsigned int)e1 + ebp2->d.m.lastIdx) & 0xF];
        *(_DWORD *)(v7->d.t.v1 + 4) = Scaleform::Render::Tessellator::emitVertex(
                                        this,
                                        endStar,
                                        *(_DWORD *)(v7->d.t.v1 + 4),
                                        ebp2->style,
                                        v5);
        *(_DWORD *)(v7->d.t.v2 + 4) = Scaleform::Render::Tessellator::emitVertex(
                                        this,
                                        endStar,
                                        *(_DWORD *)(v7->d.t.v2 + 4),
                                        ebp2->style,
                                        v5);
        *(_DWORD *)(v7->d.t.v3 + 4) = Scaleform::Render::Tessellator::emitVertex(
                                        this,
                                        endStar,
                                        *(_DWORD *)(v7->d.t.v3 + 4),
                                        ebp2->style,
                                        v5);
        v8 = v7->d.m.v2;
        v7->d.t.v1 = *(_DWORD *)(v7->d.t.v1 + 4) & 0xFFFFFFF;
        v9 = v7->d.m.v3;
        v7->d.t.v2 = v8->aaVer & 0xFFFFFFF;
        v7->d.t.v3 = v9->aaVer & 0xFFFFFFF;
        e1 = (Scaleform::Render::Tessellator::OuterEdgeType *)((char *)e1 + 1);
        if ( (unsigned int)e1 >= ebp2->d.m.prevIdx1 )
          break;
      }
      ecx1 = i;
    }
    ++ecx1;
  }
  v10 = 0;
  for ( ia = 0; v10 < this->InnerQuads.Size; ia = v10 )
  {
    v11 = v10;
    v12 = v10 & 0xF;
    v13 = this->InnerQuads.Pages[v11 >> 4];
    c3 = (unsigned int)v13[v12].e2;
    endStara = (unsigned int)v13[v12].e1;
    v14 = *(_WORD *)(endStara + 8) & 0x7FFF;
    s2 = *(_WORD *)(c3 + 8) & 0x7FFF;
    v15 = Scaleform::Render::Tessellator::setMesh(this, v14, s2);
    v16 = this->Meshes.Pages[v15 >> 4];
    Style1 = v16[v15 & 0xF].Style1;
    v18 = &v16[v15 & 0xF];
    if ( !Style1 || v14 == Style1 )
    {
      v19 = (Scaleform::Render::Tessellator::MonoVertexType **)c3;
      v20 = (unsigned int *)endStara;
    }
    else
    {
      v19 = (Scaleform::Render::Tessellator::MonoVertexType **)endStara;
      v20 = (unsigned int *)c3;
      v21 = v14;
      v14 = s2;
      s2 = v21;
    }
    v2 = (Scaleform::Render::Tessellator::MonoVertexType *)v20[1];
    v3 = *v19;
    e1a = (Scaleform::Render::Tessellator::OuterEdgeType *)v19[1];
    v22 = 0;
    c3a = *v20;
    endStarb = v14;
    if ( ((v18->Flags1 ^ v18->Flags2) & 0x8000) != 0 )
    {
      endStarb = s2;
      v22 = 32;
    }
    v23 = v22 | 0xA;
    *(_DWORD *)(c3a + 4) = Scaleform::Render::Tessellator::emitVertex(
                             this,
                             v15,
                             *(_DWORD *)(*v20 + 4),
                             v14,
                             endStarb,
                             v23,
                             0);
    v2->aaVer = Scaleform::Render::Tessellator::emitVertex(this, v15, v2->aaVer, v14, endStarb, v23, 0);
    v3->aaVer = Scaleform::Render::Tessellator::emitVertex(this, v15, v3->aaVer, s2, 2u);
    e1a->outVer = Scaleform::Render::Tessellator::emitVertex(this, v15, e1a->outVer, s2, 2u);
    Arrays = this->MeshTriangles.Arrays;
    v25 = *(_DWORD *)(c3a + 4);
    tri.d.t.v2 = v2->aaVer & 0xFFFFFFF;
    tri.d.t.v3 = v3->aaVer & 0xFFFFFFF;
    v26 = 16 * v15;
    Size = Arrays[v15].Size;
    v28 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)Arrays + v26);
    v29 = v25 & 0xFFFFFFF;
    v30 = Size >> 4;
    tri.d.t.v1 = v29;
    s1a = v26;
    if ( v30 >= v28->NumPages )
    {
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
        &this->MeshTriangles,
        v28,
        v30);
      v29 = tri.d.t.v1;
      v26 = s1a;
    }
    v31 = v28->Pages[v30];
    v32 = v28->Size & 0xF;
    v31[v32].d.t.v1 = v29;
    *(_QWORD *)&v31[v32].d.t.v2 = *(_QWORD *)&tri.d.t.v2;
    ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v26);
    v33 = this->MeshTriangles.Arrays;
    v34 = *(unsigned int *)((char *)&v33->Size + v26);
    outVer = e1a->outVer;
    tri.d.t.v2 = v3->aaVer & 0xFFFFFFF;
    v36 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v33 + v26);
    v37 = outVer & 0xFFFFFFF;
    v38 = v2->aaVer & 0xFFFFFFF;
    v39 = v34 >> 4;
    tri.d.t.v1 = v37;
    tri.d.t.v3 = v38;
    if ( v39 >= v36->NumPages )
    {
      Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
        &this->MeshTriangles,
        v36,
        v39);
      v26 = s1a;
      v37 = tri.d.t.v1;
    }
    v40 = v36->Pages[v39];
    v41 = v36->Size & 0xF;
    v40[v41].d.t.v1 = v37;
    *(_QWORD *)&v40[v41].d.t.v2 = *(_QWORD *)&tri.d.t.v2;
    ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v26);
    v10 = ia + 1;
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,bool (__cdecl *)(Scaleform::Render::Tessellator::StrokerEdgeType const &,Scaleform::Render::Tessellator::StrokerEdgeType const &)>(
    (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16> *)&this->OuterEdges,
    0,
    this->OuterEdges.Size,
    (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpOuterEdges);
  v42 = 0;
  for ( ib = 0; v42 < this->OuterEdges.Size; ib = v42 )
  {
    v43 = &this->OuterEdges.Pages[v42 >> 4][v42 & 0xF];
    e1b = v43;
    if ( (v43->outVer & 0x40000000) == 0 )
    {
      p_cntVer = &v43->edge->cntVer;
      edgeAA.cntVer = v43->edge->rayVer;
      edgeAA.rayVer = *p_cntVer;
      edgeAA.slope = 0;
      oppos.edge = &edgeAA;
      edgeAA.style = 0;
      v123 = this->OuterEdges.Size;
      oppos.outVer = -1;
      v45 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16>,Scaleform::Render::Tessellator::OuterEdgeType,bool (__cdecl *)(Scaleform::Render::Tessellator::OuterEdgeType const &,Scaleform::Render::Tessellator::OuterEdgeType const &)>(
              (const Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16> *)&this->OuterEdges,
              0,
              v123,
              (const Scaleform::Render::Tessellator::StrokerEdgeType *)&oppos,
              (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpOuterEdges);
      if ( v45 < this->OuterEdges.Size )
      {
        f2 = &this->OuterEdges.Pages[v45 >> 4][v45 & 0xF];
        if ( f2->edge->cntVer == v43->edge->rayVer )
        {
          v46 = v43->edge->style & 0x7FFF;
          v47 = Scaleform::Render::Tessellator::setMesh(this, v46);
          v48 = v46 != this->Meshes.Pages[v47 >> 4][v47 & 0xF].Style1 ? 0 : 8;
          i2b = (unsigned int)e1b->edge->rayVer;
          endStarc = Scaleform::Render::Tessellator::emitVertex(this, v47, e1b->edge->cntVer->aaVer, v46, v48 | 2);
          c3b = Scaleform::Render::Tessellator::emitVertex(this, v47, *(_DWORD *)(i2b + 4), v46, v48 | 2);
          e1b->outVer = Scaleform::Render::Tessellator::emitVertex(this, v47, e1b->outVer, v46, v48) | 0x40000000;
          v49 = Scaleform::Render::Tessellator::emitVertex(this, v47, f2->outVer, v46, v48) | 0x40000000;
          f2->outVer = v49;
          v50 = this->MeshTriangles.Arrays;
          cntVer = v49 & 0xFFFFFFF;
          v51 = 16 * v47;
          v52 = v50[v47].Size;
          v53 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v50 + v51);
          v54 = v52 >> 4;
          v55 = e1b->outVer & 0xFFFFFFF;
          s1b = v51;
          if ( v54 >= v53->NumPages )
          {
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v53,
              v54);
            v51 = s1b;
          }
          v56 = (Scaleform::Render::Tessellator::TriangleType::<unnamed_type_d>::<unnamed_type_t> *)&v53->Pages[v54][v53->Size & 0xF];
          v56->v1 = endStarc;
          v56->v2 = c3b;
          v56->v3 = v55;
          ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v51);
          v57 = this->MeshTriangles.Arrays;
          v58 = *(unsigned int *)((char *)&v57->Size + v51);
          v59 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v57 + v51);
          v60 = v58 >> 4;
          if ( v60 >= v59->NumPages )
          {
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v59,
              v60);
            v51 = s1b;
          }
          v61 = v59->Pages[v60];
          v42 = ib;
          v62 = (unsigned int *)&v61[v59->Size & 0xF];
          *v62 = cntVer;
          v62[1] = v55;
          v62[2] = c3b;
          ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v51);
        }
      }
    }
    ++v42;
  }
  v63 = 0;
  ic = 0;
  if ( this->StarVertices.Size )
  {
    while ( 1 )
    {
      v64 = (Scaleform::Render::Tessellator::EdgeAAType *)(4 * (v63 >> 4));
      v65 = v63 & 0xF;
      cntVera = (*(Scaleform::Render::Tessellator::StarVertexType **)((char *)this->StarVertices.Pages
                                                                    + (unsigned int)v64))[v65].cntVer;
      oppos.edge = v64;
      c3c = v65 * 8;
      v66 = v63;
      do
      {
        if ( ++v66 >= this->StarVertices.Size )
          break;
        v65 = v63 & 0xF;
      }
      while ( cntVera == this->StarVertices.Pages[v66 >> 4][v66 & 0xF].cntVer );
      endStard = v66;
      if ( v63 + 3 == v66 )
        break;
LABEL_39:
      v79 = v63;
      v80 = v66 - 1;
      i2a = v63;
      if ( v63 < v66 )
      {
        do
        {
          Pages = this->StarVertices.Pages;
          v3b = Pages[v80 >> 4][v80 & 0xF].starVer;
          starVer = Pages[v79 >> 4][v79 & 0xF].starVer;
          v83 = this->MeshVertices.Pages;
          v84 = v83[v3b >> 4];
          m2a = starVer;
          v85 = v83[starVer >> 4];
          v86 = starVer & 0xF;
          s1d = v84[v3b & 0xF].Styles[0];
          s2b = v85[v86].Styles[0];
          e1d = v84[v3b & 0xF].Flags & 2;
          v87 = v85[v86].Flags & 2;
          v88 = Scaleform::Render::Tessellator::setMesh(this, s1d, s2b);
          v89 = s1d;
          v90 = &this->Meshes.Pages[v88 >> 4][v88 & 0xF];
          v91 = v90->Style1;
          if ( v91 && s1d != v91 )
          {
            v92 = m2a;
            m2a = v3b;
            s1d = s2b;
            v93 = e1d;
            s2b = v89;
            v89 = s1d;
            e1d = v87;
            v3b = v92;
            LOWORD(v87) = v93;
          }
          v94 = e1d | 8;
          v2b = (Scaleform::Render::Tessellator::MonoVertexType *)v89;
          if ( ((v90->Flags2 ^ v90->Flags1) & 0x8000) != 0 )
          {
            v2b = (Scaleform::Render::Tessellator::MonoVertexType *)s2b;
            v94 = e1d | 0x28;
          }
          tri.d.t.v1 = Scaleform::Render::Tessellator::emitVertex(this, v88, v3b, v89, (unsigned int)v2b, v94, 0);
          v95 = Scaleform::Render::Tessellator::emitVertex(this, v88, m2a, s2b, v87);
          Flags1 = v90->Flags1;
          tri.d.t.v2 = v95;
          v97 = (((unsigned __int8)e1d & (unsigned __int8)v87 & 2) != 0) + 1;
          if ( ((v90->Flags2 | Flags1) & 0x8000) != 0 )
          {
            v98 = (unsigned int)v2b;
            v99 = v97 & 0xFFFFFFD3 | 0x24;
          }
          else
          {
            v98 = s2b;
            v99 = v97 | 0x10;
          }
          v117 = Scaleform::Render::Tessellator::emitVertex(this, v88, cntVera, s1d, v98, v99, 1);
          v118 = this->MeshTriangles.Arrays;
          v119 = 16 * v88;
          v120 = v118[v88].Size;
          v121 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v118 + v119);
          v122 = v120 >> 4;
          tri.d.t.v3 = v117;
          s1f = v119;
          if ( v122 >= v121->NumPages )
          {
            Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
              &this->MeshTriangles,
              v121,
              v122);
            v119 = s1f;
          }
          v121->Pages[v122][v121->Size & 0xF] = tri;
          ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v119);
          v66 = endStard;
          v80 = i2a;
          v79 = i2a + 1;
          i2a = v79;
        }
        while ( v79 < endStard );
      }
LABEL_75:
      v63 = v66;
      ic = v66;
      if ( v66 >= this->StarVertices.Size )
        return;
    }
    v67 = this->StarVertices.Pages;
    v68 = *(unsigned int *)((char *)&(*(Scaleform::Render::Tessellator::MonoVertexType **)((char *)&v64->cntVer
                                                                                         + (_DWORD)v67))->aaVer
                          + v65 * 8);
    v69 = v63 + 1;
    m2c = v67[(v63 + 1) >> 4][((_BYTE)v63 + 1) & 0xF].starVer;
    v70 = v63 + 2;
    v71 = v67[v70 >> 4][v70 & 0xF].starVer;
    v72 = this->MeshVertices.Pages;
    i2c = (unsigned int)&v72[v68 >> 4][v68 & 0xF];
    s1c = *(unsigned __int16 *)(i2c + 12);
    v73 = (int)&v72[m2c >> 4][m2c & 0xF];
    s2a = *(unsigned __int16 *)(v73 + 12);
    v74 = v72[v71 >> 4];
    v75 = v71 & 0xF;
    v76 = v74[v75].Styles[0];
    e1c = (Scaleform::Render::Tessellator::OuterEdgeType *)*(unsigned __int16 *)(i2c + 16);
    f2a = *(unsigned __int16 *)(v73 + 16);
    i2 = v74[v75].Flags;
    v2a = v76;
    v3a = (Scaleform::Render::Tessellator::MonoVertexType *)Scaleform::Render::Tessellator::setMesh(this, s1c, s2a);
    m2 = Scaleform::Render::Tessellator::setMesh(this, s2a, v76);
    v77 = Scaleform::Render::Tessellator::setMesh(this, v76, s1c);
    v78 = m2;
    if ( v3a == (Scaleform::Render::Tessellator::MonoVertexType *)m2
      || v3a == (Scaleform::Render::Tessellator::MonoVertexType *)v77 )
    {
      v78 = (unsigned int)v3a;
    }
    else if ( m2 != v77 )
    {
LABEL_38:
      v63 = ic;
      v66 = endStard;
      goto LABEL_39;
    }
    if ( v78 != -1 )
    {
      v100 = this->StarVertices.Pages;
      v3c = *(Scaleform::Render::Tessellator::MonoVertexType **)((char *)&(*(Scaleform::Render::Tessellator::MonoVertexType **)((char *)&oppos.edge->cntVer + (unsigned int)v100))->aaVer
                                                               + c3c);
      m2b = v100[v69 >> 4][v69 & 0xF].starVer;
      v101 = v100[v70 >> 4][v70 & 0xF].starVer;
      memset(&tri, 255, sizeof(tri));
      id = v101;
      v102 = this->Meshes.Pages[v78 >> 4];
      if ( ((v102[v78 & 0xF].Flags1 ^ v102[v78 & 0xF].Flags2) & 0x8000) == 0 )
        goto LABEL_63;
      Array = this->ComplexFlags.Array;
      v104 = Array[s1c >> 5] & (1 << (s1c & 0x1F));
      v105 = Array[s2a >> 5] & (1 << (s2a & 0x1F));
      v106 = Array[v2a >> 5] & (1 << (v2a & 0x1F));
      c3d = v106;
      if ( v104 )
      {
        v107 = v2a;
        if ( !v105 )
          v107 = s2a;
        v108 = Scaleform::Render::Tessellator::emitVertex(
                 this,
                 v78,
                 (unsigned int)v3c,
                 s1c,
                 v107,
                 (unsigned int)e1c | 0x20,
                 0);
        v106 = c3d;
        tri.d.t.v1 = v108;
      }
      if ( v105 )
      {
        v109 = s1c;
        if ( !v106 )
          v109 = v2a;
        v110 = Scaleform::Render::Tessellator::emitVertex(this, v78, m2b, s2a, v109, f2a | 0x20, 0);
        v106 = c3d;
        tri.d.t.v2 = v110;
      }
      if ( v106 )
      {
        v111 = s2a;
        if ( !v104 )
          v111 = s1c;
        tri.d.t.v3 = Scaleform::Render::Tessellator::emitVertex(this, v78, id, v2a, v111, i2 | 0x20, 0);
      }
      if ( tri.d.t.v1 == -1 )
LABEL_63:
        tri.d.t.v1 = Scaleform::Render::Tessellator::emitVertex(
                       this,
                       v78,
                       (unsigned int)v3c,
                       s1c,
                       (unsigned __int16)e1c);
      if ( tri.d.t.v2 == -1 )
        tri.d.t.v2 = Scaleform::Render::Tessellator::emitVertex(this, v78, m2b, s2a, f2a);
      if ( tri.d.t.v3 == -1 )
        tri.d.t.v3 = Scaleform::Render::Tessellator::emitVertex(this, v78, id, v2a, i2);
      v112 = this->MeshTriangles.Arrays;
      v113 = 16 * v78;
      v114 = v112[v78].Size;
      v115 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)((char *)v112 + v113);
      v116 = v114 >> 4;
      s1e = v113;
      if ( v116 >= v115->NumPages )
      {
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
          &this->MeshTriangles,
          v115,
          v116);
        v113 = s1e;
      }
      v115->Pages[v116][v115->Size & 0xF] = tri;
      v66 = endStard;
      ++*(unsigned int *)((char *)&this->MeshTriangles.Arrays->Size + v113);
      goto LABEL_75;
    }
    goto LABEL_38;
  }
}
