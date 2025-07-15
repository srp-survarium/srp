void __thiscall Scaleform::Render::Tessellator::processStrokerEdges(Scaleform::Render::Tessellator *this)
{
  unsigned int v2; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *start; // eax
  Scaleform::Render::Tessellator::MonoVertexType *next; // edx
  unsigned int srcVer; // edi
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ebx
  unsigned int v13; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v14; // ecx
  unsigned int v15; // eax
  int v16; // edx
  int v17; // ebx
  unsigned int v18; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v19; // ecx
  unsigned int v20; // eax
  int v21; // edx
  int v22; // ebx
  unsigned int v23; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v24; // ecx
  unsigned int v25; // eax
  unsigned int j; // edi
  Scaleform::Render::Tessellator::StrokerEdgeType *v27; // esi
  unsigned int node2; // ecx
  unsigned int v29; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType *v30; // eax
  unsigned int v31; // eax
  Scaleform::Render::Tessellator::StrokerEdgeType *v32; // ebx
  unsigned int v33; // eax
  unsigned int v34; // eax
  unsigned int Size; // edx
  Scaleform::Render::Tessellator::StrokerEdgeType *v36; // esi
  unsigned int node1; // ecx
  unsigned int v38; // eax
  unsigned int v39; // edi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *Arrays; // esi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *p_MeshTriangles; // ebp
  unsigned int v42; // edi
  int v43; // ecx
  unsigned int v44; // ebx
  Scaleform::Render::Tessellator::TriangleType *v45; // edx
  int v46; // eax
  Scaleform::Render::Tessellator::TriangleType *v47; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v48; // edi
  int v49; // eax
  unsigned int v50; // esi
  int v51; // ebx
  Scaleform::Render::Tessellator::TriangleType *v52; // ecx
  int *v53; // ecx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v54; // esi
  int v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // edi
  unsigned int v58; // eax
  Scaleform::Render::Tessellator::TriangleType *v59; // esi
  int v60; // eax
  Scaleform::Render::Tessellator::TriangleType *v61; // eax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v62; // edi
  int v63; // eax
  int v64; // ecx
  unsigned int v65; // esi
  Scaleform::Render::Tessellator::TriangleType *v66; // edx
  int v67; // edi
  Scaleform::Render::Tessellator::TriangleType *v68; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v69; // [esp+10h] [ebp-40h]
  Scaleform::Render::Tessellator::MonoVertexType *v70; // [esp+10h] [ebp-40h]
  Scaleform::Render::Tessellator::StrokerEdgeType *v71; // [esp+10h] [ebp-40h]
  unsigned int i; // [esp+14h] [ebp-3Ch]
  unsigned int k; // [esp+14h] [ebp-3Ch]
  unsigned int v74; // [esp+18h] [ebp-38h]
  int v75; // [esp+18h] [ebp-38h]
  int v76; // [esp+1Ch] [ebp-34h]
  unsigned int v77; // [esp+1Ch] [ebp-34h]
  unsigned int v78; // [esp+20h] [ebp-30h]
  Scaleform::Render::Tessellator::StrokerEdgeType *v79; // [esp+20h] [ebp-30h]
  unsigned int v80; // [esp+24h] [ebp-2Ch]
  int v81; // [esp+28h] [ebp-28h]
  Scaleform::Render::Tessellator::StrokerEdgeType val; // [esp+2Ch] [ebp-24h] BYREF
  Scaleform::Render::Tessellator *v83; // [esp+34h] [ebp-1Ch]
  int v84; // [esp+38h] [ebp-18h]
  int v85; // [esp+3Ch] [ebp-14h]
  int v86; // [esp+44h] [ebp-Ch]
  int v87; // [esp+48h] [ebp-8h]

  v2 = 0;
  v83 = this;
  for ( i = 0; v2 < this->Monotones.Size; i = v2 )
  {
    start = this->Monotones.Pages[v2 >> 4][v2 & 0xF].start;
    if ( start )
    {
      next = start->next;
      srcVer = start->srcVer;
      v74 = start->srcVer;
      v69 = next;
      if ( next )
      {
        v6 = next->srcVer;
        v7 = next->srcVer & 0xFFFFFFF;
        v76 = next->srcVer;
        val.node1 = srcVer & 0xFFFFFFF;
        val.node2 = v7;
        if ( (srcVer & 0xFFFFFFF) != v7 )
        {
          v8 = this->StrokerEdges.Size >> 4;
          v78 = v8;
          if ( v8 >= this->StrokerEdges.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
              v8);
            v8 = v78;
          }
          this->StrokerEdges.Pages[v8][this->StrokerEdges.Size++ & 0xF] = val;
          next = v69;
        }
        v9 = next->next;
        v70 = v9;
        if ( v9 )
        {
          while ( 1 )
          {
            v10 = v9->srcVer & 0xFFFFFFF;
            if ( (v9->srcVer & 0x80000000) == 0 )
            {
              v16 = v9->srcVer & 0xFFFFFFF;
              v17 = v6 & 0xFFFFFFF;
              v85 = v16;
              if ( v17 != v10 )
              {
                v18 = this->StrokerEdges.Size >> 4;
                if ( v18 >= this->StrokerEdges.NumPages )
                {
                  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
                    this->StrokerEdges.Size >> 4);
                  v16 = v85;
                }
                v19 = this->StrokerEdges.Pages[v18];
                srcVer = v74;
                v20 = this->StrokerEdges.Size & 0xF;
                v19[v20].node1 = v17;
                v19[v20].node2 = v16;
                ++this->StrokerEdges.Size;
                v9 = v70;
              }
              v76 = v9->srcVer;
            }
            else
            {
              v11 = srcVer & 0xFFFFFFF;
              v12 = v9->srcVer & 0xFFFFFFF;
              v81 = srcVer & 0xFFFFFFF;
              if ( v10 != (srcVer & 0xFFFFFFF) )
              {
                v13 = this->StrokerEdges.Size >> 4;
                if ( v13 >= this->StrokerEdges.NumPages )
                {
                  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                    (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
                    this->StrokerEdges.Size >> 4);
                  v11 = v81;
                }
                v14 = this->StrokerEdges.Pages[v13];
                v15 = this->StrokerEdges.Size & 0xF;
                v14[v15].node1 = v12;
                v14[v15].node2 = v11;
                ++this->StrokerEdges.Size;
                v9 = v70;
              }
              v74 = v9->srcVer;
              srcVer = v9->srcVer;
            }
            v6 = v76;
            v70 = v9->next;
            if ( !v70 )
              break;
            v9 = v9->next;
          }
        }
        v21 = srcVer & 0xFFFFFFF;
        v22 = v6 & 0xFFFFFFF;
        v87 = srcVer & 0xFFFFFFF;
        if ( v22 != (srcVer & 0xFFFFFFF) )
        {
          v23 = this->StrokerEdges.Size >> 4;
          if ( v23 >= this->StrokerEdges.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StrokerEdges,
              this->StrokerEdges.Size >> 4);
            v21 = v87;
          }
          v24 = this->StrokerEdges.Pages[v23];
          v25 = this->StrokerEdges.Size & 0xF;
          v24[v25].node1 = v22;
          v24[v25].node2 = v21;
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
      v27 = &this->StrokerEdges.Pages[j >> 4][j & 0xF];
      if ( (v27->node1 & 0x40000000) == 0 )
      {
        node2 = v27->node2;
        val.node2 = v27->node1;
        val.node1 = node2;
        v29 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::OuterEdgeType,4,16>,Scaleform::Render::Tessellator::OuterEdgeType,bool (__cdecl *)(Scaleform::Render::Tessellator::OuterEdgeType const &,Scaleform::Render::Tessellator::OuterEdgeType const &)>(
                &this->StrokerEdges,
                0,
                this->StrokerEdges.Size,
                &val,
                (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, const Scaleform::Render::Tessellator::StrokerEdgeType *))Scaleform::Render::Tessellator::cmpStrokerEdges);
        if ( v29 < this->StrokerEdges.Size )
        {
          v30 = &this->StrokerEdges.Pages[v29 >> 4][v29 & 0xF];
          if ( v27->node1 == v30->node2 && v27->node2 == v30->node1 )
          {
            v27->node1 |= 0x40000000u;
            v30->node1 |= 0x40000000u;
          }
        }
      }
    }
    v31 = 0;
    for ( k = 0; v31 < this->StrokerEdges.Size; k = v31 )
    {
      v32 = &this->StrokerEdges.Pages[v31 >> 4][v31 & 0xF];
      v79 = v32;
      if ( (v32->node1 & 0x40000000) == 0 )
      {
        v33 = -1;
        v71 = v32;
        v75 = -1;
        while ( 1 )
        {
          v77 = v33;
          v34 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::StrokerEdgeType,4,16>,unsigned int,bool (__cdecl *)(Scaleform::Render::Tessellator::StrokerEdgeType const &,unsigned int)>(
                  &this->StrokerEdges,
                  0,
                  this->StrokerEdges.Size,
                  &v32->node2,
                  (bool (__cdecl *)(const Scaleform::Render::Tessellator::StrokerEdgeType *, unsigned int))Scaleform::Render::Tessellator::cmpStrokerNode1);
          Size = this->StrokerEdges.Size;
          if ( v34 >= Size )
            break;
          while ( 1 )
          {
            v36 = &this->StrokerEdges.Pages[v34 >> 4][v34 & 0xF];
            node1 = v36->node1;
            val.node1 = (unsigned int)v36;
            if ( (node1 & 0x40000000) == 0 && ((node1 ^ v32->node2) & 0xFFFFFFF) == 0 )
              break;
            if ( ++v34 >= Size )
              goto LABEL_59;
          }
          v38 = Scaleform::Render::Tessellator::addStrokerJoin(this, v32, v36);
          if ( v77 == -1 )
          {
            v75 = this->MeshVertices.Size - v38;
          }
          else
          {
            v39 = this->MeshVertices.Size;
            Arrays = this->MeshTriangles.Arrays;
            p_MeshTriangles = &this->MeshTriangles;
            v42 = v39 - v38;
            v43 = v32->node1 & 0xFFFFFFF;
            v44 = Arrays->Size >> 4;
            v80 = v42;
            v84 = v43;
            if ( v44 >= Arrays->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                p_MeshTriangles,
                Arrays,
                v44);
              v43 = v84;
            }
            v45 = Arrays->Pages[v44];
            v46 = Arrays->Size & 0xF;
            v45[v46].d.t.v1 = v43;
            v47 = &v45[v46];
            v47->d.t.v2 = v77;
            v47->d.t.v3 = v42;
            ++p_MeshTriangles->Arrays->Size;
            v48 = p_MeshTriangles->Arrays;
            v49 = v71->node1 & 0xFFFFFFF;
            v50 = v48->Size >> 4;
            v51 = v71->node2 & 0xFFFFFFF;
            v85 = v49;
            if ( v50 >= v48->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                p_MeshTriangles,
                v48,
                v50);
              v49 = v85;
            }
            v52 = v48->Pages[v50];
            v36 = (Scaleform::Render::Tessellator::StrokerEdgeType *)val.node1;
            v53 = (int *)&v52[v48->Size & 0xF];
            *v53 = v51;
            v53[1] = v49;
            v53[2] = v80;
            ++p_MeshTriangles->Arrays->Size;
            v71->node1 |= 0x40000000u;
            this = v83;
          }
          if ( v36 == v79 )
          {
            v54 = this->MeshTriangles.Arrays;
            v55 = v79->node1 & 0xFFFFFFF;
            v56 = this->MeshVertices.Size - 1;
            v57 = v54->Size >> 4;
            v86 = v55;
            v87 = v56;
            if ( v57 >= v54->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &this->MeshTriangles,
                v54,
                v57);
              v56 = v87;
              v55 = v86;
            }
            v58 = v54->Size;
            v59 = v54->Pages[v57];
            v60 = v58 & 0xF;
            v59[v60].d.t.v1 = v55;
            v61 = &v59[v60];
            v61->d.t.v2 = v56;
            v61->d.t.v3 = v75;
            ++this->MeshTriangles.Arrays->Size;
            v62 = this->MeshTriangles.Arrays;
            v63 = v79->node2 & 0xFFFFFFF;
            v64 = v79->node1 & 0xFFFFFFF;
            v65 = v62->Size >> 4;
            v86 = v63;
            v87 = v64;
            if ( v65 >= v62->NumPages )
            {
              Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
                &this->MeshTriangles,
                v62,
                v65);
              v64 = v87;
              v63 = v86;
            }
            v66 = v62->Pages[v65];
            v67 = v62->Size & 0xF;
            v66[v67].d.t.v1 = v63;
            v68 = &v66[v67];
            v68->d.t.v2 = v64;
            v68->d.t.v3 = v75;
            ++this->MeshTriangles.Arrays->Size;
            v79->node1 |= 0x40000000u;
            break;
          }
          v33 = this->MeshVertices.Size - 1;
          v71 = v36;
          v32 = v36;
        }
      }
LABEL_59:
      v31 = k + 1;
    }
  }
}
