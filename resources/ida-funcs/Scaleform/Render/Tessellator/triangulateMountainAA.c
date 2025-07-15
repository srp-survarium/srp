void __thiscall Scaleform::Render::Tessellator::triangulateMountainAA(Scaleform::Render::Tessellator *this)
{
  unsigned int Size; // ebx
  double v3; // st7
  Scaleform::Render::Tessellator::MonoVertexType ***Pages; // edi
  Scaleform::Render::TessVertex **v5; // ecx
  float *v6; // edx
  unsigned int v7; // ecx
  double v8; // st6
  double v9; // st5
  Scaleform::Render::TessVertex *v10; // eax
  unsigned int v11; // ebx
  int v12; // ebp
  unsigned int v13; // edx
  unsigned int v14; // edi
  unsigned int v15; // ebx
  unsigned int v16; // eax
  Scaleform::Render::Tessellator::MonoVertexType ***v17; // ebp
  unsigned int v18; // edi
  unsigned int srcVer; // ecx
  unsigned int v20; // eax
  int v21; // ebx
  unsigned int v22; // edx
  Scaleform::Render::TessVertex **v23; // ebx
  Scaleform::Render::TessVertex *v24; // ebp
  int v25; // eax
  double y; // st7
  float *v27; // eax
  Scaleform::Render::TessVertex *v28; // ebp
  Scaleform::Render::TessVertex *v29; // ebx
  double v30; // st7
  Scaleform::Render::Tessellator::MonoVertexType ***v31; // edx
  unsigned int v32; // eax
  unsigned int v33; // ecx
  Scaleform::Render::TessVertex **v34; // ebx
  unsigned int v35; // edx
  Scaleform::Render::TessVertex *v36; // ebp
  int v37; // eax
  double v38; // st7
  float *v39; // eax
  Scaleform::Render::TessVertex *v40; // ebp
  Scaleform::Render::TessVertex *v41; // ebx
  Scaleform::Render::Tessellator::MonoVertexType ***v42; // ebp
  unsigned int v43; // eax
  unsigned int v44; // ecx
  unsigned int v45; // edx
  Scaleform::Render::TessVertex **v46; // ebx
  Scaleform::Render::TessVertex *v47; // ebp
  int v48; // eax
  double v49; // st7
  float *v50; // eax
  Scaleform::Render::TessVertex *v51; // ebp
  Scaleform::Render::TessVertex *v52; // ebx
  double v53; // st7
  Scaleform::Render::Tessellator::MonoVertexType ***v54; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v55; // ecx
  Scaleform::Render::TessVertex **v56; // ebx
  Scaleform::Render::TessVertex *v57; // ebp
  double v58; // st7
  float *v59; // eax
  unsigned int v60; // edx
  float *v61; // ecx
  float *v62; // edx
  unsigned int v63; // ebx
  double v64; // st7
  double v65; // st6
  double v66; // st6
  double v67; // st6
  Scaleform::Render::Tessellator::MonoVertexType ***v68; // ecx
  Scaleform::Render::Tessellator::MonoVertexType ***v69; // eax
  unsigned int v70; // edx
  unsigned int v71; // eax
  Scaleform::Render::Tessellator::MonoVertexType ***v72; // edi
  unsigned int v73; // ecx
  unsigned int v74; // edx
  unsigned int v75; // edi
  int v76; // ebp
  Scaleform::Render::TessVertex **v77; // eax
  Scaleform::Render::TessVertex *v78; // edi
  double v79; // st7
  float *v80; // edi
  Scaleform::Render::TessVertex *v81; // ebp
  Scaleform::Render::TessVertex *v82; // eax
  double v83; // st7
  unsigned int v84; // eax
  Scaleform::Render::Tessellator::MonoVertexType ***v85; // edx
  unsigned int v86; // ebx
  unsigned int v87; // eax
  Scaleform::Render::Tessellator::MonoVertexType ***v88; // edi
  __int64 v89; // [esp+8h] [ebp-8Ch]
  __int64 v90; // [esp+8h] [ebp-8Ch]
  __int64 v91; // [esp+8h] [ebp-8Ch]
  float v92; // [esp+14h] [ebp-80h]
  float v93; // [esp+14h] [ebp-80h]
  float v94; // [esp+14h] [ebp-80h]
  float v95; // [esp+14h] [ebp-80h]
  float v96; // [esp+14h] [ebp-80h]
  float v97; // [esp+14h] [ebp-80h]
  float v98; // [esp+14h] [ebp-80h]
  float v99; // [esp+28h] [ebp-6Ch]
  float v100; // [esp+28h] [ebp-6Ch]
  float EdgeAAWidth; // [esp+28h] [ebp-6Ch]
  float v102; // [esp+28h] [ebp-6Ch]
  unsigned int v103; // [esp+2Ch] [ebp-68h]
  unsigned int v104; // [esp+30h] [ebp-64h]
  int v105; // [esp+34h] [ebp-60h]
  unsigned int v106; // [esp+38h] [ebp-5Ch]
  int v107; // [esp+3Ch] [ebp-58h]
  unsigned int v108; // [esp+40h] [ebp-54h]
  unsigned int v109; // [esp+40h] [ebp-54h]
  unsigned int v110; // [esp+40h] [ebp-54h]
  unsigned int v111; // [esp+44h] [ebp-50h]
  unsigned int v112; // [esp+48h] [ebp-4Ch]
  unsigned int v113; // [esp+4Ch] [ebp-48h]
  unsigned int v114; // [esp+50h] [ebp-44h]
  unsigned int v115; // [esp+54h] [ebp-40h]
  float v116; // [esp+58h] [ebp-3Ch]
  float v117; // [esp+58h] [ebp-3Ch]
  unsigned int v118; // [esp+5Ch] [ebp-38h]
  unsigned int v119; // [esp+60h] [ebp-34h]
  int v120; // [esp+64h] [ebp-30h]
  float v121; // [esp+68h] [ebp-2Ch]
  float v122; // [esp+6Ch] [ebp-28h]
  float v123; // [esp+70h] [ebp-24h]
  int v124; // [esp+74h] [ebp-20h]
  int v125; // [esp+78h] [ebp-1Ch]
  unsigned int v126; // [esp+7Ch] [ebp-18h]
  unsigned int v127; // [esp+80h] [ebp-14h]
  int v128; // [esp+84h] [ebp-10h]
  int v129; // [esp+88h] [ebp-Ch]
  unsigned int v130; // [esp+8Ch] [ebp-8h]
  float *p_x; // [esp+90h] [ebp-4h]
  float v132; // [esp+90h] [ebp-4h]
  int v133; // [esp+90h] [ebp-4h]
  unsigned int v134; // [esp+90h] [ebp-4h]
  unsigned int v135; // [esp+90h] [ebp-4h]

  Size = this->MonoStack.Size;
  if ( Size <= 2 )
    return;
  v3 = 0.0;
  v99 = 0.0;
  Pages = this->MonoStack.Pages;
  v5 = this->MeshVertices.Pages;
  p_x = &v5[((**Pages)->srcVer & 0xFFFFFFF) >> 4][(**Pages)->srcVer & 0xF].x;
  v6 = &v5[(Pages[(Size - 1) >> 4][(Size - 1) & 0xF]->srcVer & 0xFFFFFFF) >> 4][Pages[(Size - 1) >> 4][(Size - 1) & 0xF]->srcVer
                                                                              & 0xF].x;
  v7 = 1;
  v8 = v6[1] - p_x[1];
  v9 = *v6 - *p_x;
  do
  {
    v10 = &this->MeshVertices.Pages[(Pages[v7 >> 4][v7 & 0xF]->srcVer & 0xFFFFFFF) >> 4][Pages[v7 >> 4][v7 & 0xF]->srcVer
                                                                                       & 0xF];
    v11 = this->MonoStack.Size;
    ++v7;
    v132 = (v10->x - *v6) * v8 - (v10->y - v6[1]) * v9;
    v99 = v132 + v99;
  }
  while ( v7 + 1 < v11 );
  if ( v99 <= 0.0 )
    v12 = -1;
  else
    v12 = 1;
  v13 = 0;
  v120 = v12;
  v114 = 0;
  v103 = this->MonoStack.Size;
  if ( v11 <= 3 )
  {
LABEL_64:
    v88 = this->MonoStack.Pages;
    v98 = v3;
    HIDWORD(v91) = v88[(v13 + 1) >> 4][((_BYTE)v13 + 1) & 0xF];
    LODWORD(v91) = v88[(v13 - v12 + 1) >> 4][(v13 - v12 + 1) & 0xF];
    Scaleform::Render::Tessellator::addTriangleAA(
      this,
      v91,
      &v88[(v13 + v12 + 1) >> 4][(v13 + v12 + 1) & 0xF]->srcVer,
      v98);
    return;
  }
  v104 = v11 - 2;
  v112 = v11 - 1;
  v14 = v11 - 3;
  v15 = 2;
  v16 = 1;
  v113 = 3;
  v105 = 1;
  v106 = v14;
  v107 = 2;
  v111 = this->MonoStack.Size - 4;
  v115 = 2;
  while ( 2 )
  {
    v17 = this->MonoStack.Pages;
    v108 = v16 & 0xF;
    v18 = v16 >> 4;
    v127 = v13 & 0xF;
    v126 = v13 >> 4;
    srcVer = v17[v126][v127]->srcVer;
    v124 = v15 >> 4;
    v20 = v17[v18][v108]->srcVer & 0xFFFFFFF;
    v21 = v15 & 0xF;
    v22 = v17[v124][v21]->srcVer;
    v125 = v21 * 4;
    v23 = this->MeshVertices.Pages;
    v24 = v23[v20 >> 4];
    srcVer &= 0xFFFFFFFu;
    v25 = v20 & 0xF;
    y = v24[v25].y;
    v27 = &v24[v25].x;
    v92 = y;
    v28 = v23[srcVer >> 4];
    v29 = v23[(v22 & 0xFFFFFFF) >> 4];
    v30 = Scaleform::Render::Math2D::LinePointDistance(
            v29[v22 & 0xF].x,
            v29[v22 & 0xF].y,
            v28[srcVer & 0xF].x,
            v28[srcVer & 0xF].y,
            *v27,
            v92);
    v31 = this->MonoStack.Pages;
    v116 = v30;
    v32 = (*(Scaleform::Render::Tessellator::MonoVertexType **)((char *)v31[v124] + v125))->srcVer & 0xFFFFFFF;
    v33 = v31[v18][v108]->srcVer;
    v34 = this->MeshVertices.Pages;
    v35 = v31[v113 >> 4][v113 & 0xF]->srcVer;
    v36 = v34[v32 >> 4];
    v33 &= 0xFFFFFFFu;
    v37 = v32 & 0xF;
    v38 = v36[v37].y;
    v39 = &v36[v37].x;
    v93 = v38;
    v40 = v34[v33 >> 4];
    v41 = v34[(v35 & 0xFFFFFFF) >> 4];
    v121 = Scaleform::Render::Math2D::LinePointDistance(
             v41[v35 & 0xF].x,
             v41[v35 & 0xF].y,
             v40[v33 & 0xF].x,
             v40[v33 & 0xF].y,
             *v39,
             v93);
    v42 = this->MonoStack.Pages;
    v119 = v104 & 0xF;
    v118 = v104 >> 4;
    v128 = v106 >> 4;
    v129 = v106 & 0xF;
    v43 = v42[v118][v119]->srcVer & 0xFFFFFFF;
    v44 = v42[v128][v129]->srcVer & 0xFFFFFFF;
    v130 = v112 >> 4;
    v45 = v42[v130][v112 & 0xF]->srcVer;
    v133 = v112 & 0xF;
    v46 = this->MeshVertices.Pages;
    v47 = v46[v43 >> 4];
    v48 = v43 & 0xF;
    v49 = v47[v48].y;
    v50 = &v47[v48].x;
    v94 = v49;
    v51 = v46[v44 >> 4];
    v52 = v46[(v45 & 0xFFFFFFF) >> 4];
    v53 = Scaleform::Render::Math2D::LinePointDistance(
            v52[v45 & 0xF].x,
            v52[v45 & 0xF].y,
            v51[v44 & 0xF].x,
            v51[v44 & 0xF].y,
            *v50,
            v94);
    v54 = this->MonoStack.Pages;
    v122 = v53;
    v55 = v54[v111 >> 4][v111 & 0xF];
    v56 = this->MeshVertices.Pages;
    v57 = v56[(v54[v128][v129]->srcVer & 0xFFFFFFF) >> 4];
    v58 = v57[v54[v128][v129]->srcVer & 0xF].y;
    v59 = &v57[v54[v128][v129]->srcVer & 0xF].x;
    v60 = v54[v118][v119]->srcVer & 0xFFFFFFF;
    v61 = &v56[(v55->srcVer & 0xFFFFFFF) >> 4][v55->srcVer & 0xF].x;
    v62 = &v56[v60 >> 4][v60 & 0xF].x;
    v95 = v58;
    v12 = v120;
    v123 = Scaleform::Render::Math2D::LinePointDistance(*v62, v62[1], *v61, v61[1], *v59, v95);
    v63 = -1;
    if ( v120 <= 0 )
    {
      EdgeAAWidth = this->EdgeAAWidth;
      v64 = 0.0;
      if ( v116 > 0.0 && v121 > 0.0 )
      {
        if ( EdgeAAWidth >= (double)v116 )
        {
          v66 = v121;
        }
        else
        {
          v63 = v105;
          v66 = v121;
          EdgeAAWidth = v116;
        }
        if ( EdgeAAWidth < v66 )
        {
          v63 = v107;
          EdgeAAWidth = v66;
        }
      }
      if ( v122 > 0.0 && v123 > 0.0 )
      {
        if ( EdgeAAWidth >= (double)v122 )
        {
          v67 = v123;
        }
        else
        {
          v63 = v104;
          v67 = v123;
          EdgeAAWidth = v122;
        }
        if ( EdgeAAWidth < v67 )
          v63 = v106;
      }
LABEL_39:
      if ( v63 != -1 )
      {
        v68 = this->MonoStack.Pages;
        v96 = v64;
        HIDWORD(v89) = v68[v63 >> 4][v63 & 0xF];
        LODWORD(v89) = v68[(v63 - v120) >> 4][(v63 - v120) & 0xF];
        Scaleform::Render::Tessellator::addTriangleAA(
          this,
          v89,
          &v68[(v63 + v120) >> 4][(v63 + v120) & 0xF]->srcVer,
          v96);
        v69 = this->MonoStack.Pages;
        if ( v63 == v105 )
        {
          v69[v18][v108] = v69[v126][v127];
          ++v114;
          ++v107;
          ++v105;
          ++v115;
          ++v113;
        }
        else if ( v63 == v107 )
        {
          *(Scaleform::Render::Tessellator::MonoVertexType **)((char *)v69[v124] + v125) = v69[v18][v108];
          this->MonoStack.Pages[v18][v108] = this->MonoStack.Pages[v126][v127];
          ++v114;
          ++v107;
          ++v105;
          ++v115;
          ++v113;
        }
        else
        {
          if ( v63 == v104 )
          {
            v69[v118][v119] = v69[v130][v133];
          }
          else
          {
            v69[v128][v129] = v69[v118][v119];
            this->MonoStack.Pages[v118][v119] = this->MonoStack.Pages[v130][v133];
          }
          --v103;
          --v111;
          --v106;
          --v112;
          --v104;
        }
        goto LABEL_62;
      }
      goto LABEL_48;
    }
    v100 = -this->EdgeAAWidth;
    v64 = 0.0;
    if ( v116 >= 0.0 )
    {
      v65 = v121;
LABEL_19:
      if ( v65 < 0.0 && v123 < 0.0 )
      {
        if ( v100 > (double)v122 )
        {
          v63 = v104;
          v100 = v122;
        }
        if ( v100 > (double)v123 )
          v63 = v106;
      }
      goto LABEL_39;
    }
    if ( v121 < 0.0 )
    {
      if ( v100 <= (double)v116 )
      {
        v65 = v121;
      }
      else
      {
        v63 = v105;
        v65 = v121;
        v100 = v116;
      }
      if ( v100 > v65 )
      {
        v63 = v107;
        v100 = v65;
      }
      goto LABEL_19;
    }
LABEL_48:
    v70 = v115;
    v102 = v64;
    v71 = v105;
    v109 = v105;
    if ( v115 >= v103 )
      return;
    v134 = v115;
    do
    {
      v72 = this->MonoStack.Pages;
      v73 = v72[(v70 - 2) >> 4][((_BYTE)v70 - 2) & 0xF]->srcVer;
      v74 = v72[v70 >> 4][v70 & 0xF]->srcVer;
      v75 = v72[v71 >> 4][v71 & 0xF]->srcVer & 0xFFFFFFF;
      v76 = v75 & 0xF;
      v77 = this->MeshVertices.Pages;
      v73 &= 0xFFFFFFFu;
      v78 = v77[v75 >> 4];
      v79 = v78[v76].y;
      v80 = &v78[v76].x;
      v97 = v79;
      v81 = v77[v73 >> 4];
      v82 = v77[(v74 & 0xFFFFFFF) >> 4];
      v83 = Scaleform::Render::Math2D::LinePointDistance(
              v82[v74 & 0xF].x,
              v82[v74 & 0xF].y,
              v81[v73 & 0xF].x,
              v81[v73 & 0xF].y,
              *v80,
              v97);
      v12 = v120;
      v117 = v83;
      if ( v120 <= 0 )
      {
        if ( v102 < (double)v117 )
        {
          v84 = v109;
          v102 = v83;
          v63 = v109;
          goto LABEL_56;
        }
      }
      else if ( v102 > (double)v117 )
      {
        v84 = v109;
        v102 = v83;
        v63 = v109;
        goto LABEL_56;
      }
      v84 = v109;
LABEL_56:
      v70 = v134 + 1;
      v71 = v84 + 1;
      v109 = v71;
      v134 = v70;
    }
    while ( v70 < v103 );
    if ( v63 != -1 )
    {
      v85 = this->MonoStack.Pages;
      HIDWORD(v90) = v85[v63 >> 4][v63 & 0xF];
      LODWORD(v90) = v85[(v63 - v120) >> 4][(v63 - v120) & 0xF];
      Scaleform::Render::Tessellator::addTriangleAA(this, v90, &v85[(v63 + v120) >> 4][(v63 + v120) & 0xF]->srcVer, 0.0);
      v86 = v63 + 1;
      v110 = v86;
      if ( v86 < v103 )
      {
        v87 = v86 - 1;
        v135 = v86 - 1;
        do
        {
          this->MonoStack.Pages[v87 >> 4][v87 & 0xF] = this->MonoStack.Pages[v86 >> 4][v86 & 0xF];
          v86 = v110 + 1;
          v87 = v135 + 1;
          v110 = v86;
          ++v135;
        }
        while ( v86 < v103 );
      }
      --v103;
      --v111;
      --v106;
      --v112;
      --v104;
LABEL_62:
      v13 = v114;
      if ( v103 <= v113 )
      {
        v3 = 0.0;
        goto LABEL_64;
      }
      v15 = v107;
      v16 = v105;
      continue;
    }
    break;
  }
}
