void __thiscall Scaleform::Render::Tessellator::processStrokerEdges(Scaleform::Render::Tessellator *this)
{
  unsigned int v2; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *start; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType *next; // edx
  unsigned int srcVer; // edi
  unsigned int node1; // ebx
  int v7; // ecx
  unsigned int v8; // ecx
  Scaleform::Render::Tessellator::StrokerEdgeType *v9; // ecx
  unsigned int v10; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType *v11; // esi
  int v12; // eax
  int v13; // edx
  int v14; // ebx
  unsigned int v15; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v16; // ecx
  unsigned int v17; // eax
  int v18; // edx
  int v19; // ebx
  unsigned int v20; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v21; // ecx
  unsigned int v22; // eax
  int v23; // edx
  int v24; // ebx
  unsigned int v25; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v26; // ecx
  unsigned int v27; // eax
  unsigned int j; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v29; // esi
  Scaleform::Render::Tessellator::StrokerEdgeType *node2; // ecx
  unsigned int v31; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType *v32; // eax
  unsigned int v33; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType *v34; // ebx
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int Size; // edx
  Scaleform::Render::Tessellator::StrokerEdgeType *v38; // esi
  unsigned int v39; // ecx
  unsigned int v40; // eax
  unsigned int v41; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // esi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *p_MeshTriangles; // ebp
  unsigned int v44; // edi
  int v45; // ecx
  unsigned int v46; // ebx
  Scaleform::Render::Tessellator::TriangleType *v47; // edx
  int v48; // eax
  Scaleform::Render::Tessellator::TriangleType *v49; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v50; // edi
  int v51; // eax
  unsigned int v52; // esi
  int v53; // ebx
  Scaleform::Render::Tessellator::TriangleType *v54; // ecx
  int *v55; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v56; // esi
  int v57; // ecx
  unsigned int v58; // edx
  unsigned int v59; // edi
  unsigned int v60; // eax
  Scaleform::Render::Tessellator::TriangleType *v61; // esi
  int v62; // eax
  Scaleform::Render::Tessellator::TriangleType *v63; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v64; // edi
  int v65; // eax
  int v66; // ecx
  unsigned int v67; // esi
  Scaleform::Render::Tessellator::TriangleType *v68; // edx
  int v69; // edi
  Scaleform::Render::Tessellator::TriangleType *v70; // edx
  Scaleform::Render::Tessellator::StrokerEdgeType *thisEdge; // [esp+10h] [ebp-40h]
  Scaleform::Render::Tessellator::StrokerEdgeType *thisEdgea; // [esp+10h] [ebp-40h]
  Scaleform::Render::Tessellator::StrokerEdgeType *thisEdgeb; // [esp+10h] [ebp-40h]
  unsigned int i; // [esp+14h] [ebp-3Ch]
  unsigned int ia; // [esp+14h] [ebp-3Ch]
  unsigned int strtVer; // [esp+18h] [ebp-38h]
  unsigned int strtVera; // [esp+18h] [ebp-38h]
  unsigned int prevVer; // [esp+1Ch] [ebp-34h]
  unsigned int prevVera; // [esp+1Ch] [ebp-34h]
  Scaleform::Render::Tessellator::StrokerEdgeType *strtEdge; // [esp+20h] [ebp-30h]
  Scaleform::Render::Tessellator::StrokerEdgeType *strtEdgea; // [esp+20h] [ebp-30h]
  unsigned int v82; // [esp+24h] [ebp-2Ch]
  int v83; // [esp+28h] [ebp-28h]
  Scaleform::Render::Tessellator::StrokerEdgeType *e; // [esp+2Ch] [ebp-24h] BYREF
  unsigned int v85; // [esp+30h] [ebp-20h]
  Scaleform::Render::Tessellator *v86; // [esp+34h] [ebp-1Ch]
  int v87; // [esp+38h] [ebp-18h]
  int v88; // [esp+3Ch] [ebp-14h]
  int v89; // [esp+44h] [ebp-Ch]
  int v90; // [esp+48h] [ebp-8h]

  v2 = 0;
  v86 = this;
  for ( i = 0; v2 < this->Monotones.Size; i = v2 )
  {
    start = this->Monotones.Pages[v2 >> 4][v2 & 0xF].start;
    if ( start )
    {
      next = (Scaleform::Render::Tessellator::StrokerEdgeType *)start->next;
      srcVer = start->srcVer;
      strtVer = start->srcVer;
      thisEdge = next;
      if ( next )
      {
        node1 = next->node1;
        v7 = next->node1 & 0xFFFFFFF;
        prevVer = next->node1;
        e = (Scaleform::Render::Tessellator::StrokerEdgeType *)(srcVer & 0xFFFFFFF);
        v85 = v7;
        if ( (srcVer & 0xFFFFFFF) != v7 )
        {
          v8 = this->StrokerEdges.Size >> 4;
          strtEdge = (Scaleform::Render::Tessellator::StrokerEdgeType *)v8;
          if ( v8 >= this->StrokerEdges.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
              v8);
            v8 = (unsigned int)strtEdge;
          }
          v9 = this->StrokerEdges.Pages[v8];
          v10 = this->StrokerEdges.Size & 0xF;
          v9[v10].node1 = (unsigned int)e;
          v9[v10].node2 = v85;
          ++this->StrokerEdges.Size;
          next = thisEdge;
        }
        v11 = (Scaleform::Render::Tessellator::StrokerEdgeType *)next[1].node1;
        thisEdgea = v11;
        if ( v11 )
        {
          while ( 1 )
          {
            v12 = v11->node1 & 0xFFFFFFF;
            if ( (v11->node1 & 0x80000000) == 0 )
            {
              v18 = v11->node1 & 0xFFFFFFF;
              v19 = node1 & 0xFFFFFFF;
              v88 = v18;
              if ( v19 != v12 )
              {
                v20 = this->StrokerEdges.Size >> 4;
                if ( v20 >= this->StrokerEdges.NumPages )
                {
                  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
                    this->StrokerEdges.Size >> 4);
                  v18 = v88;
                }
                v21 = this->StrokerEdges.Pages[v20];
                srcVer = strtVer;
                v22 = this->StrokerEdges.Size & 0xF;
                v21[v22].node1 = v19;
                v21[v22].node2 = v18;
                ++this->StrokerEdges.Size;
                v11 = thisEdgea;
              }
              prevVer = v11->node1;
            }
            else
            {
              v13 = srcVer & 0xFFFFFFF;
              v14 = v11->node1 & 0xFFFFFFF;
              v83 = srcVer & 0xFFFFFFF;
              if ( v12 != (srcVer & 0xFFFFFFF) )
              {
                v15 = this->StrokerEdges.Size >> 4;
                if ( v15 >= this->StrokerEdges.NumPages )
                {
                  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
                    this->StrokerEdges.Size >> 4);
                  v13 = v83;
                }
                v16 = this->StrokerEdges.Pages[v15];
                v17 = this->StrokerEdges.Size & 0xF;
                v16[v17].node1 = v14;
                v16[v17].node2 = v13;
                ++this->StrokerEdges.Size;
                v11 = thisEdgea;
              }
              strtVer = v11->node1;
              srcVer = v11->node1;
            }
            node1 = prevVer;
            thisEdgea = (Scaleform::Render::Tessellator::StrokerEdgeType *)v11[1].node1;
            if ( !thisEdgea )
              break;
            v11 = (Scaleform::Render::Tessellator::StrokerEdgeType *)v11[1].node1;
          }
        }
        v23 = srcVer & 0xFFFFFFF;
        v24 = node1 & 0xFFFFFFF;
        v90 = srcVer & 0xFFFFFFF;
        if ( v24 != (srcVer & 0xFFFFFFF) )
        {
          v25 = this->StrokerEdges.Size >> 4;
          if ( v25 >= this->StrokerEdges.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
              this->StrokerEdges.Size >> 4);
            v23 = v90;
          }
          v26 = this->StrokerEdges.Pages[v25];
          v27 = this->StrokerEdges.Size & 0xF;
          v26[v27].node1 = v24;
          v26[v27].node2 = v23;
          ++this->StrokerEdges.Size;
        }
        v2 = i;
      }
    }
    ++v2;
  }
  if ( this->StrokerEdges.Size >= 2 )
  {
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,bool (__cdecl *)(Scaleform::Render::Tessellator::StrokerEdgeType const &,Scaleform::Render::Tessellator::StrokerEdgeType const &)>(
      &this->StrokerEdges,
      0,
      this->StrokerEdges.Size,
      (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpStrokerEdges);
    for ( j = 0; j < this->StrokerEdges.Size; ++j )
    {
      v29 = &this->StrokerEdges.Pages[j >> 4][j & 0xF];
      if ( (v29->node1 & 0x40000000) == 0 )
      {
        node2 = (Scaleform::Render::Tessellator::StrokerEdgeType *)v29->node2;
        v85 = v29->node1;
        e = node2;
        v31 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16>,Scaleform::Render::Tessellator::OuterEdgeType,bool (__cdecl *)(Scaleform::Render::Tessellator::OuterEdgeType const &,Scaleform::Render::Tessellator::OuterEdgeType const &)>(
                &this->StrokerEdges,
                0,
                this->StrokerEdges.Size,
                (const Scaleform::Render::Tessellator::StrokerEdgeType *)&e,
                (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpStrokerEdges);
        if ( v31 < this->StrokerEdges.Size )
        {
          v32 = &this->StrokerEdges.Pages[v31 >> 4][v31 & 0xF];
          if ( v29->node1 == v32->node2 && v29->node2 == v32->node1 )
          {
            v29->node1 |= 0x40000000u;
            v32->node1 |= 0x40000000u;
          }
        }
      }
    }
    v33 = 0;
    for ( ia = 0; v33 < this->StrokerEdges.Size; ia = v33 )
    {
      v34 = &this->StrokerEdges.Pages[v33 >> 4][v33 & 0xF];
      strtEdgea = v34;
      if ( (v34->node1 & 0x40000000) == 0 )
      {
        v35 = -1;
        thisEdgeb = v34;
        strtVera = -1;
        while ( 1 )
        {
          prevVera = v35;
          v36 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,unsigned int,bool (__cdecl *)(Scaleform::Render::Tessellator::StrokerEdgeType const &,unsigned int)>(
                  &this->StrokerEdges,
                  0,
                  this->StrokerEdges.Size,
                  &v34->node2,
                  (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, unsigned int))Scaleform::Render::Tessellator::cmpStrokerNode1);
          Size = this->StrokerEdges.Size;
          if ( v36 >= Size )
            break;
          while ( 1 )
          {
            v38 = &this->StrokerEdges.Pages[v36 >> 4][v36 & 0xF];
            v39 = v38->node1;
            e = v38;
            if ( (v39 & 0x40000000) == 0 && ((v39 ^ v34->node2) & 0xFFFFFFF) == 0 )
              break;
            if ( ++v36 >= Size )
              goto LABEL_59;
          }
          v40 = Scaleform::Render::Tessellator::addStrokerJoin(this, v34, v38);
          if ( prevVera == -1 )
          {
            strtVera = this->MeshVertices.Size - v40;
          }
          else
          {
            v41 = this->MeshVertices.Size;
            Arrays = this->MeshTriangles.Arrays;
            p_MeshTriangles = &this->MeshTriangles;
            v44 = v41 - v40;
            v45 = v34->node1 & 0xFFFFFFF;
            v46 = Arrays->Size >> 4;
            v82 = v44;
            v87 = v45;
            if ( v46 >= Arrays->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                p_MeshTriangles,
                Arrays,
                v46);
              v45 = v87;
            }
            v47 = Arrays->Pages[v46];
            v48 = Arrays->Size & 0xF;
            v47[v48].d.t.v1 = v45;
            v49 = &v47[v48];
            v49->d.t.v2 = prevVera;
            v49->d.t.v3 = v44;
            ++p_MeshTriangles->Arrays->Size;
            v50 = p_MeshTriangles->Arrays;
            v51 = thisEdgeb->node1 & 0xFFFFFFF;
            v52 = v50->Size >> 4;
            v53 = thisEdgeb->node2 & 0xFFFFFFF;
            v88 = v51;
            if ( v52 >= v50->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                p_MeshTriangles,
                v50,
                v52);
              v51 = v88;
            }
            v54 = v50->Pages[v52];
            v38 = e;
            v55 = (int *)&v54[v50->Size & 0xF];
            *v55 = v53;
            v55[1] = v51;
            v55[2] = v82;
            ++p_MeshTriangles->Arrays->Size;
            thisEdgeb->node1 |= 0x40000000u;
            this = v86;
          }
          if ( v38 == strtEdgea )
          {
            v56 = this->MeshTriangles.Arrays;
            v57 = strtEdgea->node1 & 0xFFFFFFF;
            v58 = this->MeshVertices.Size - 1;
            v59 = v56->Size >> 4;
            v89 = v57;
            v90 = v58;
            if ( v59 >= v56->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &this->MeshTriangles,
                v56,
                v59);
              v58 = v90;
              v57 = v89;
            }
            v60 = v56->Size;
            v61 = v56->Pages[v59];
            v62 = v60 & 0xF;
            v61[v62].d.t.v1 = v57;
            v63 = &v61[v62];
            v63->d.t.v2 = v58;
            v63->d.t.v3 = strtVera;
            ++this->MeshTriangles.Arrays->Size;
            v64 = this->MeshTriangles.Arrays;
            v65 = strtEdgea->node2 & 0xFFFFFFF;
            v66 = strtEdgea->node1 & 0xFFFFFFF;
            v67 = v64->Size >> 4;
            v89 = v65;
            v90 = v66;
            if ( v67 >= v64->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &this->MeshTriangles,
                v64,
                v67);
              v66 = v90;
              v65 = v89;
            }
            v68 = v64->Pages[v67];
            v69 = v64->Size & 0xF;
            v68[v69].d.t.v1 = v65;
            v70 = &v68[v69];
            v70->d.t.v2 = v66;
            v70->d.t.v3 = strtVera;
            ++this->MeshTriangles.Arrays->Size;
            strtEdgea->node1 |= 0x40000000u;
            break;
          }
          v35 = this->MeshVertices.Size - 1;
          thisEdgeb = v38;
          v34 = v38;
        }
      }
LABEL_59:
      v33 = ia + 1;
    }
  }
}
