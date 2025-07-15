void __thiscall Scaleform::Render::Tessellator::processFan(
        Scaleform::Render::Tessellator *this,
        unsigned int start,
        unsigned int end)
{
  unsigned int v3; // ebx
  Scaleform::Render::Tessellator::EdgeAAType *v5; // ecx
  unsigned int v6; // ebp
  Scaleform::Render::Tessellator::EdgeAAType *Array; // eax
  int v8; // ecx
  Scaleform::Render::Tessellator::MonoVertexType *rayVer; // edi
  Scaleform::Render::Tessellator::EdgeAAType *v10; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // ebx
  unsigned int *v14; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v15; // edx
  unsigned int v16; // ecx
  Scaleform::Render::TessVertex *v17; // edi
  int v18; // eax
  double v19; // st7
  int v20; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v21; // edx
  unsigned int v22; // edi
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16> *p_MeshVertices; // esi
  unsigned int v24; // edi
  int v25; // eax
  float v26; // edx
  int v27; // ecx
  int v28; // edx
  unsigned int v29; // ebp
  unsigned int Size; // ecx
  unsigned int v31; // eax
  unsigned int v32; // edx
  unsigned int **Pages; // ebx
  unsigned int v34; // ebp
  unsigned int *v35; // ecx
  unsigned int v36; // eax
  Scaleform::Render::Tessellator::EdgeAAType *v37; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v38; // eax
  Scaleform::Render::Tessellator::MonoVertexType *cntVer; // edx
  Scaleform::Render::Tessellator::EdgeAAType *v40; // ebx
  unsigned int srcVer; // ecx
  unsigned int v42; // eax
  Scaleform::Render::TessVertex **v43; // ecx
  int v44; // ecx
  int v45; // eax
  unsigned int v46; // ecx
  Scaleform::Render::TessVertex *v47; // eax
  float y; // ecx
  int v49; // edx
  int v50; // ecx
  unsigned int v51; // ecx
  Scaleform::Render::Tessellator::StarVertexType *v52; // ecx
  unsigned int v53; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v54; // edx
  unsigned int v55; // ecx
  unsigned int v56; // ecx
  unsigned int v57; // eax
  unsigned int v58; // ecx
  Scaleform::Render::Tessellator::InnerQuadType *v59; // ecx
  Scaleform::Render::Tessellator::EdgeAAType *v60; // edx
  unsigned int v61; // eax
  Scaleform::Render::Tessellator::MonoVertexType *v62; // ebx
  int v63; // edx
  Scaleform::Render::TessVertex **v64; // edx
  unsigned int v65; // eax
  unsigned int v66; // ebx
  unsigned __int16 v67; // ax
  unsigned __int16 v68; // cx
  unsigned int v69; // ecx
  Scaleform::Render::TessVertex *v70; // eax
  float v71; // ecx
  unsigned int Idx; // edx
  int v73; // ecx
  int v74; // edx
  unsigned int v75; // ecx
  Scaleform::Render::TessVertex *v76; // eax
  float v77; // ecx
  int v78; // edx
  int v79; // ecx
  unsigned int v80; // ebp
  Scaleform::Render::Tessellator::StarVertexType *v81; // ecx
  Scaleform::Render::Tessellator::StarVertexType *v82; // ebp
  unsigned int v83; // eax
  unsigned int v84; // ebp
  Scaleform::Render::Tessellator::StarVertexType *v85; // edx
  Scaleform::Render::Tessellator::StarVertexType *v86; // ecx
  unsigned int v87; // eax
  unsigned int v88; // ecx
  Scaleform::Render::Tessellator::OuterEdgeType *v89; // ecx
  unsigned int v90; // eax
  unsigned int v91; // ebx
  Scaleform::Render::Tessellator::OuterEdgeType *v92; // ebx
  unsigned int v93; // ecx
  unsigned int v94; // eax
  unsigned int v95; // [esp+8h] [ebp-5Ch] BYREF
  Scaleform::Render::Tessellator::EdgeAAType *v96; // [esp+Ch] [ebp-58h] BYREF
  int v97; // [esp+10h] [ebp-54h]
  Scaleform::Render::Tessellator::EdgeAAType *v98; // [esp+14h] [ebp-50h]
  int v99; // [esp+18h] [ebp-4Ch]
  unsigned int v100; // [esp+1Ch] [ebp-48h]
  unsigned int v101; // [esp+20h] [ebp-44h]
  unsigned int v102; // [esp+24h] [ebp-40h]
  unsigned int v103; // [esp+28h] [ebp-3Ch]
  unsigned int v104; // [esp+2Ch] [ebp-38h]
  int v105; // [esp+38h] [ebp-2Ch]
  Scaleform::Render::TessVertex v106; // [esp+3Ch] [ebp-28h] BYREF
  Scaleform::Render::TessVertex v107; // [esp+50h] [ebp-14h] BYREF
  unsigned int *v108; // [esp+68h] [ebp+4h]
  unsigned int v109; // [esp+68h] [ebp+4h]
  int v110; // [esp+68h] [ebp+4h]
  unsigned int v111; // [esp+68h] [ebp+4h]
  unsigned int v112; // [esp+68h] [ebp+4h]
  unsigned int v113; // [esp+68h] [ebp+4h]
  char v114; // [esp+68h] [ebp+4h]
  Scaleform::Render::Tessellator::StarVertexType *v115; // [esp+68h] [ebp+4h]
  unsigned int v116; // [esp+68h] [ebp+4h]

  v3 = start;
  if ( start != end )
  {
    v97 = end - start;
    v5 = (Scaleform::Render::Tessellator::EdgeAAType *)(end - 1);
    v6 = start;
    v96 = (Scaleform::Render::Tessellator::EdgeAAType *)(end - 1);
    this->StartFan.Size = 0;
    this->EndFan.Size = 0;
    v95 = start;
    if ( start < end )
    {
      while ( 1 )
      {
        Array = this->EdgeFans.Array;
        v8 = (int)v5;
        rayVer = Array[v8].rayVer;
        v10 = &Array[v8];
        v11 = &Array[v6];
        if ( ((rayVer->srcVer ^ v11->rayVer->srcVer) & 0xFFFFFFF) != 0 )
        {
          if ( v10->slope != v11->slope && (v10->style & 0x8000u) == 0 && (v11->style & 0x8000) != 0 )
          {
            Scaleform::Render::ArrayPaged<unsigned int,3,4>::PushBack(&this->StartFan, &v95);
            Scaleform::Render::ArrayPaged<unsigned int,3,4>::PushBack(&this->EndFan, (unsigned int *)&v96);
          }
        }
        else if ( ((v10->style ^ v11->style) & 0x7FFF) != 0 )
        {
          v12 = this->StartFan.Size >> 3;
          if ( v12 >= this->StartFan.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->StartFan,
              this->StartFan.Size >> 3);
          this->StartFan.Pages[v12][this->StartFan.Size++ & 7] = v6;
          v13 = this->EndFan.Size >> 3;
          if ( v13 >= this->EndFan.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->EndFan,
              this->EndFan.Size >> 3);
          v14 = this->EndFan.Pages[v13];
          v3 = start;
          v14[this->EndFan.Size++ & 7] = (unsigned int)v96;
        }
        v96 = (Scaleform::Render::Tessellator::EdgeAAType *)v6++;
        v95 = v6;
        if ( v6 >= end )
          break;
        v5 = v96;
      }
    }
    if ( this->StartFan.Size )
    {
      v29 = this->EndFan.Size >> 3;
      v108 = *this->EndFan.Pages;
      if ( v29 >= this->EndFan.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->EndFan,
          v29);
      this->EndFan.Pages[v29][this->EndFan.Size++ & 7] = *v108;
      Size = this->StarVertices.Size;
      v31 = this->EdgeFans.Array[v3].cntVer->srcVer & 0xFFFFFFF;
      v32 = 0;
      v103 = Size;
      v104 = v31;
      if ( this->StartFan.Size )
      {
        do
        {
          Pages = this->StartFan.Pages;
          v100 = 4 * (v32 >> 3);
          v34 = Pages[v100 / 4][v32 & 7];
          v101 = 4 * (v32 & 7);
          v35 = this->EndFan.Pages[(v32 + 1) >> 3];
          v102 = v32 + 1;
          v36 = v35[(v32 + 1) & 7];
          v37 = this->EdgeFans.Array;
          v95 = v36;
          v38 = &v37[v36];
          cntVer = v37[v34].cntVer;
          v99 = 12 * v34;
          v40 = &v37[v34];
          srcVer = v40->rayVer->srcVer;
          v96 = v38;
          v42 = cntVer->srcVer & 0xFFFFFFF;
          v98 = v40;
          if ( (srcVer & 0xFFFFFFF) == v42 || (v96->rayVer->srcVer & 0xFFFFFFF) == v42 )
          {
            v43 = this->MeshVertices.Pages;
            v109 = cntVer->srcVer & 0xFFFFFFF;
            v106.x = v43[v109 >> 4][cntVer->srcVer & 0xF].x;
            v106.y = v43[v109 >> 4][v109 & 0xF].y;
          }
          else
          {
            Scaleform::Render::Tessellator::computeMiter(
              this,
              &this->MeshVertices.Pages[(srcVer & 0xFFFFFFF) >> 4][srcVer & 0xF],
              &this->MeshVertices.Pages[v42 >> 4][v42 & 0xF],
              &this->MeshVertices.Pages[(v96->rayVer->srcVer & 0xFFFFFFF) >> 4][v96->rayVer->srcVer & 0xF],
              &v106,
              0);
            v40 = v98;
          }
          v96 = (Scaleform::Render::Tessellator::EdgeAAType *)this->MeshVertices.Size;
          if ( v95 >= v34 || (v95 += v97, v34 <= v95) )
          {
            v44 = v99;
            v110 = v99;
            v45 = 12 * (v34 - v97);
            do
            {
              if ( v34 >= end )
                v44 = v45;
              (*(Scaleform::Render::Tessellator::MonoVertexType **)((char *)&this->EdgeFans.Array->cntVer + v44))->aaVer = (unsigned int)v96;
              ++v34;
              v44 = v110 + 12;
              v45 += 12;
              v110 += 12;
            }
            while ( v34 <= v95 );
          }
          v46 = this->MeshVertices.Size >> 4;
          v106.Styles[1] = v40->style & 0x7FFF;
          v106.Styles[0] = v106.Styles[1];
          *(_DWORD *)&v106.Flags = -65534;
          v111 = v46;
          if ( v46 >= this->MeshVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v46);
            v46 = v111;
          }
          v47 = &this->MeshVertices.Pages[v46][this->MeshVertices.Size & 0xF];
          y = v106.y;
          v47->x = v106.x;
          v49 = *(_DWORD *)v106.Styles;
          v47->y = y;
          v47->Idx = -1;
          v50 = *(_DWORD *)&v106.Flags;
          *(_DWORD *)v47->Styles = v49;
          *(_DWORD *)&v47->Flags = v50;
          ++this->MeshVertices.Size;
          v51 = this->StarVertices.Size >> 4;
          v112 = v51;
          if ( v51 >= this->StarVertices.NumPages )
          {
            Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StarVertices,
              v51);
            v51 = v112;
          }
          v52 = this->StarVertices.Pages[v51];
          v53 = this->StarVertices.Size & 0xF;
          v52[v53].cntVer = v104;
          v52[v53].starVer = (unsigned int)v96;
          ++this->StarVertices.Size;
          v54 = this->EdgeFans.Array[*(unsigned int *)((char *)this->EndFan.Pages[v100 / 4] + v101)].rayVer;
          v55 = v54->srcVer;
          v96 = &this->EdgeFans.Array[*(unsigned int *)((char *)this->EndFan.Pages[v100 / 4] + v101)];
          v56 = v55 & 0xFFFFFFF;
          v57 = v40->rayVer->srcVer & 0xFFFFFFF;
          if ( v57 == v56 )
          {
            if ( (v54->aaVer & 0x40000000) == 0 )
            {
              v58 = this->InnerQuads.Size >> 4;
              v113 = v58;
              if ( v58 >= this->InnerQuads.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->InnerQuads,
                  v58);
                v58 = v113;
              }
              v59 = this->InnerQuads.Pages[v58];
              v60 = v96;
              v61 = this->InnerQuads.Size & 0xF;
              v59[v61].e1 = v40;
              v59[v61].e2 = v60;
              ++this->InnerQuads.Size;
              v40->cntVer->aaVer |= 0x40000000u;
            }
          }
          else
          {
            v62 = v40->cntVer;
            v63 = v62->srcVer & 0xFFFFFFF;
            v114 = 0;
            v101 = v63;
            if ( v57 == v63 || v56 == v63 )
            {
              v64 = this->MeshVertices.Pages;
              v65 = v62->srcVer & 0xFFFFFFF;
              v106.x = v64[v65 >> 4][v62->srcVer & 0xF].x;
              v106.y = v64[v65 >> 4][v65 & 0xF].y;
            }
            else
            {
              v114 = Scaleform::Render::Tessellator::computeMiter(
                       this,
                       &this->MeshVertices.Pages[v56 >> 4][v56 & 0xF],
                       &this->MeshVertices.Pages[v101 >> 4][v101 & 0xF],
                       &this->MeshVertices.Pages[v57 >> 4][v57 & 0xF],
                       &v106,
                       &v107);
            }
            v66 = this->MeshVertices.Size;
            v67 = v96->style & 0x7FFF;
            v68 = v98->style & 0x7FFF;
            *(_DWORD *)&v107.Flags = -65536;
            *(_DWORD *)&v106.Flags = -65536;
            v95 = v66;
            v106.Idx = -1;
            v106.Styles[1] = v67;
            v106.Styles[0] = v67;
            v107.Styles[1] = v68;
            v107.Styles[0] = v68;
            if ( v67 != v68 )
              Scaleform::Render::Tessellator::setMesh(this, v67, v68);
            v69 = this->MeshVertices.Size >> 4;
            v101 = v69;
            if ( v69 >= this->MeshVertices.NumPages )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v69);
              v69 = v101;
            }
            v70 = &this->MeshVertices.Pages[v69][this->MeshVertices.Size & 0xF];
            v71 = v106.y;
            v70->x = v106.x;
            Idx = v106.Idx;
            v70->y = v71;
            v73 = *(_DWORD *)v106.Styles;
            v70->Idx = Idx;
            v74 = *(_DWORD *)&v106.Flags;
            *(_DWORD *)v70->Styles = v73;
            *(_DWORD *)&v70->Flags = v74;
            ++this->MeshVertices.Size;
            if ( v114 )
            {
              v75 = this->MeshVertices.Size >> 4;
              v95 = this->MeshVertices.Size;
              v101 = v75;
              if ( v75 >= this->MeshVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(&this->MeshVertices, v75);
                v75 = v101;
              }
              v76 = &this->MeshVertices.Pages[v75][this->MeshVertices.Size & 0xF];
              v77 = v107.y;
              v76->x = v107.x;
              v78 = *(_DWORD *)v107.Styles;
              v76->y = v77;
              v76->Idx = -1;
              v79 = *(_DWORD *)&v107.Flags;
              *(_DWORD *)v76->Styles = v78;
              *(_DWORD *)&v76->Flags = v79;
              ++this->MeshVertices.Size;
            }
            v80 = this->StarVertices.Size >> 4;
            v81 = &this->StarVertices.Pages[(this->StarVertices.Size - 1) >> 4][(this->StarVertices.Size - 1) & 0xF];
            v101 = (unsigned int)v81;
            if ( v80 >= this->StarVertices.NumPages )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StarVertices,
                v80);
              v81 = (Scaleform::Render::Tessellator::StarVertexType *)v101;
            }
            v82 = this->StarVertices.Pages[v80];
            v83 = this->StarVertices.Size & 0xF;
            v82[v83].cntVer = v81->cntVer;
            v82[v83].starVer = v81->starVer;
            ++this->StarVertices.Size;
            if ( v114 )
            {
              v84 = this->StarVertices.Size >> 4;
              v85 = &this->StarVertices.Pages[(this->StarVertices.Size - 1) >> 4][(this->StarVertices.Size - 1) & 0xF];
              v115 = v85;
              if ( v84 >= this->StarVertices.NumPages )
              {
                Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                  (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->StarVertices,
                  v84);
                v85 = v115;
              }
              v86 = this->StarVertices.Pages[v84];
              v87 = this->StarVertices.Size & 0xF;
              v86[v87].cntVer = v85->cntVer;
              v86[v87].starVer = v85->starVer;
              ++this->StarVertices.Size;
              this->StarVertices.Pages[(this->StarVertices.Size - 3) >> 4][(this->StarVertices.Size - 3) & 0xF].starVer = v66;
              this->StarVertices.Pages[(this->StarVertices.Size - 2) >> 4][(this->StarVertices.Size - 2) & 0xF].starVer = v95;
            }
            else
            {
              this->StarVertices.Pages[(this->StarVertices.Size - 2) >> 4][(this->StarVertices.Size - 2) & 0xF].starVer = v66;
            }
            v88 = this->OuterEdges.Size >> 4;
            v116 = v88;
            if ( v88 >= this->OuterEdges.NumPages )
            {
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->OuterEdges,
                v88);
              v88 = v116;
            }
            v89 = this->OuterEdges.Pages[v88];
            v90 = this->OuterEdges.Size & 0xF;
            v89[v90].edge = v98;
            v89[v90].outVer = v95;
            ++this->OuterEdges.Size;
            v105 = v66 | 0x40000000;
            v91 = this->OuterEdges.Size >> 4;
            if ( v91 >= this->OuterEdges.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->OuterEdges,
                this->OuterEdges.Size >> 4);
            v92 = this->OuterEdges.Pages[v91];
            v93 = v105;
            v94 = this->OuterEdges.Size & 0xF;
            v92[v94].edge = v96;
            v92[v94].outVer = v93;
            ++this->OuterEdges.Size;
          }
          v32 = v102;
        }
        while ( v102 < this->StartFan.Size );
        Size = v103;
      }
      if ( Size + 3 > this->StarVertices.Size && Size < this->StarVertices.Size )
        this->StarVertices.Size = Size;
    }
    else
    {
      v15 = this->EdgeFans.Array;
      v16 = v3;
      v17 = this->MeshVertices.Pages[(v15[v3].cntVer->srcVer & 0xFFFFFFF) >> 4];
      v18 = 5 * (v15[v3].cntVer->srcVer & 0xF);
      v106.x = v17[v15[v3].cntVer->srcVer & 0xF].x;
      v19 = *(&v17->y + v18);
      LOWORD(v18) = v15[v3].style;
      v106.y = v19;
      v106.Styles[1] = v18 & 0x7FFF;
      v106.Styles[0] = v18 & 0x7FFF;
      *(_DWORD *)&v106.Flags = -65534;
      if ( v3 < end )
      {
        v20 = v97;
        do
        {
          v21 = this->EdgeFans.Array[v16++].cntVer;
          --v20;
          v21->aaVer = this->MeshVertices.Size;
        }
        while ( v20 );
      }
      v22 = this->MeshVertices.Size;
      p_MeshVertices = &this->MeshVertices;
      v24 = v22 >> 4;
      if ( v24 >= p_MeshVertices->NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::allocPage(p_MeshVertices, v24);
      v25 = (int)&p_MeshVertices->Pages[v24][p_MeshVertices->Size & 0xF];
      v26 = v106.y;
      *(float *)v25 = v106.x;
      v27 = *(_DWORD *)v106.Styles;
      *(float *)(v25 + 4) = v26;
      v28 = *(_DWORD *)&v106.Flags;
      *(_DWORD *)(v25 + 8) = -1;
      *(_DWORD *)(v25 + 12) = v27;
      *(_DWORD *)(v25 + 16) = v28;
      ++p_MeshVertices->Size;
    }
  }
}
