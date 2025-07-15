void __thiscall Scaleform::Render::Tessellator::triangulateMountainAA(Scaleform::Render::Tessellator *this)
{
  unsigned int Size; // ebx
  double v3; // st7
  Scaleform::Render::Tessellator::MonoVertexType ***Pages; // edi
  Scaleform::Render::TessVertex **v5; // ecx
  float *p_x; // edx
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
  double v26; // st7
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
  Scaleform::Render::Tessellator::MonoVertexType ***v68; // eax
  unsigned int v69; // edx
  unsigned int v70; // eax
  Scaleform::Render::Tessellator::MonoVertexType ***v71; // edi
  unsigned int v72; // ecx
  unsigned int v73; // edx
  unsigned int v74; // edi
  int v75; // ebp
  Scaleform::Render::TessVertex **v76; // eax
  Scaleform::Render::TessVertex *v77; // edi
  double v78; // st7
  float *v79; // edi
  Scaleform::Render::TessVertex *v80; // ebp
  Scaleform::Render::TessVertex *v81; // eax
  double v82; // st7
  unsigned int v83; // eax
  unsigned int v84; // ebx
  unsigned int v85; // eax
  float y; // [esp+14h] [ebp-80h]
  float ya; // [esp+14h] [ebp-80h]
  float yb; // [esp+14h] [ebp-80h]
  float yc; // [esp+14h] [ebp-80h]
  float yd; // [esp+14h] [ebp-80h]
  float ye; // [esp+14h] [ebp-80h]
  float yf; // [esp+14h] [ebp-80h]
  float s; // [esp+28h] [ebp-6Ch]
  float sa; // [esp+28h] [ebp-6Ch]
  float sb; // [esp+28h] [ebp-6Ch]
  float sc; // [esp+28h] [ebp-6Ch]
  unsigned int n2; // [esp+2Ch] [ebp-68h]
  unsigned int v98; // [esp+30h] [ebp-64h]
  int v99; // [esp+34h] [ebp-60h]
  unsigned int v100; // [esp+38h] [ebp-5Ch]
  int v101; // [esp+3Ch] [ebp-58h]
  unsigned int i; // [esp+40h] [ebp-54h]
  unsigned int ia; // [esp+40h] [ebp-54h]
  unsigned int ib; // [esp+40h] [ebp-54h]
  unsigned int v105; // [esp+44h] [ebp-50h]
  unsigned int v106; // [esp+48h] [ebp-4Ch]
  unsigned int v107; // [esp+4Ch] [ebp-48h]
  unsigned int n1; // [esp+50h] [ebp-44h]
  unsigned int v109; // [esp+54h] [ebp-40h]
  float s1; // [esp+58h] [ebp-3Ch]
  float s1a; // [esp+58h] [ebp-3Ch]
  unsigned int v112; // [esp+5Ch] [ebp-38h]
  unsigned int v113; // [esp+60h] [ebp-34h]
  int d; // [esp+64h] [ebp-30h]
  float s2; // [esp+68h] [ebp-2Ch]
  float s3; // [esp+6Ch] [ebp-28h]
  float s4; // [esp+70h] [ebp-24h]
  int v118; // [esp+74h] [ebp-20h]
  int v119; // [esp+78h] [ebp-1Ch]
  unsigned int v120; // [esp+7Ch] [ebp-18h]
  unsigned int v121; // [esp+80h] [ebp-14h]
  int v122; // [esp+84h] [ebp-10h]
  int v123; // [esp+88h] [ebp-Ch]
  unsigned int v124; // [esp+8Ch] [ebp-8h]
  const Scaleform::Render::TessVertex *v1c; // [esp+90h] [ebp-4h]
  float v1d; // [esp+90h] [ebp-4h]
  int v1; // [esp+90h] [ebp-4h]
  const Scaleform::Render::TessVertex *v1a; // [esp+90h] [ebp-4h]
  const Scaleform::Render::TessVertex *v1b; // [esp+90h] [ebp-4h]

  Size = this->MonoStack.Size;
  if ( Size <= 2 )
    return;
  v3 = 0.0;
  s = 0.0;
  Pages = this->MonoStack.Pages;
  v5 = this->MeshVertices.Pages;
  v1c = &v5[((**Pages)->srcVer & 0xFFFFFFF) >> 4][(**Pages)->srcVer & 0xF];
  p_x = &v5[(Pages[(Size - 1) >> 4][(Size - 1) & 0xF]->srcVer & 0xFFFFFFF) >> 4][Pages[(Size - 1) >> 4][(Size - 1) & 0xF]->srcVer
                                                                               & 0xF].x;
  v7 = 1;
  v8 = p_x[1] - v1c->y;
  v9 = *p_x - v1c->x;
  do
  {
    v10 = &this->MeshVertices.Pages[(Pages[v7 >> 4][v7 & 0xF]->srcVer & 0xFFFFFFF) >> 4][Pages[v7 >> 4][v7 & 0xF]->srcVer
                                                                                       & 0xF];
    v11 = this->MonoStack.Size;
    ++v7;
    v1d = (v10->x - *p_x) * v8 - (v10->y - p_x[1]) * v9;
    s = v1d + s;
  }
  while ( v7 + 1 < v11 );
  if ( s <= 0.0 )
    v12 = -1;
  else
    v12 = 1;
  v13 = 0;
  d = v12;
  n1 = 0;
  n2 = this->MonoStack.Size;
  if ( v11 <= 3 )
  {
LABEL_64:
    yf = v3;
    Scaleform::Render::Tessellator::addTriangleAA(
      this,
      this->MonoStack.Pages[(v13 - v12 + 1) >> 4][(v13 - v12 + 1) & 0xF],
      this->MonoStack.Pages[(v13 + 1) >> 4][((_BYTE)v13 + 1) & 0xF],
      (unsigned int)this->MonoStack.Pages[(v13 + v12 + 1) >> 4][(v13 + v12 + 1) & 0xF],
      yf);
    return;
  }
  v98 = v11 - 2;
  v106 = v11 - 1;
  v14 = v11 - 3;
  v15 = 2;
  v16 = 1;
  v107 = 3;
  v99 = 1;
  v100 = v14;
  v101 = 2;
  v105 = this->MonoStack.Size - 4;
  v109 = 2;
  while ( 2 )
  {
    v17 = this->MonoStack.Pages;
    i = v16 & 0xF;
    v18 = v16 >> 4;
    v121 = v13 & 0xF;
    v120 = v13 >> 4;
    srcVer = v17[v120][v121]->srcVer;
    v118 = v15 >> 4;
    v20 = v17[v18][i]->srcVer & 0xFFFFFFF;
    v21 = v15 & 0xF;
    v22 = v17[v118][v21]->srcVer;
    v119 = v21 * 4;
    v23 = this->MeshVertices.Pages;
    v24 = v23[v20 >> 4];
    srcVer &= 0xFFFFFFFu;
    v25 = v20 & 0xF;
    v26 = v24[v25].y;
    v27 = &v24[v25].x;
    y = v26;
    v28 = v23[srcVer >> 4];
    v29 = v23[(v22 & 0xFFFFFFF) >> 4];
    v30 = Scaleform::Render::Math2D::LinePointDistance(
            v29[v22 & 0xF].x,
            v29[v22 & 0xF].y,
            v28[srcVer & 0xF].x,
            v28[srcVer & 0xF].y,
            *v27,
            y);
    v31 = this->MonoStack.Pages;
    s1 = v30;
    v32 = (*(Scaleform::Render::Tessellator::MonoVertexType **)((char *)v31[v118] + v119))->srcVer & 0xFFFFFFF;
    v33 = v31[v18][i]->srcVer;
    v34 = this->MeshVertices.Pages;
    v35 = v31[v107 >> 4][v107 & 0xF]->srcVer;
    v36 = v34[v32 >> 4];
    v33 &= 0xFFFFFFFu;
    v37 = v32 & 0xF;
    v38 = v36[v37].y;
    v39 = &v36[v37].x;
    ya = v38;
    v40 = v34[v33 >> 4];
    v41 = v34[(v35 & 0xFFFFFFF) >> 4];
    s2 = Scaleform::Render::Math2D::LinePointDistance(
           v41[v35 & 0xF].x,
           v41[v35 & 0xF].y,
           v40[v33 & 0xF].x,
           v40[v33 & 0xF].y,
           *v39,
           ya);
    v42 = this->MonoStack.Pages;
    v113 = v98 & 0xF;
    v112 = v98 >> 4;
    v122 = v100 >> 4;
    v123 = v100 & 0xF;
    v43 = v42[v112][v113]->srcVer & 0xFFFFFFF;
    v44 = v42[v122][v123]->srcVer & 0xFFFFFFF;
    v124 = v106 >> 4;
    v45 = v42[v124][v106 & 0xF]->srcVer;
    v1 = v106 & 0xF;
    v46 = this->MeshVertices.Pages;
    v47 = v46[v43 >> 4];
    v48 = v43 & 0xF;
    v49 = v47[v48].y;
    v50 = &v47[v48].x;
    yb = v49;
    v51 = v46[v44 >> 4];
    v52 = v46[(v45 & 0xFFFFFFF) >> 4];
    v53 = Scaleform::Render::Math2D::LinePointDistance(
            v52[v45 & 0xF].x,
            v52[v45 & 0xF].y,
            v51[v44 & 0xF].x,
            v51[v44 & 0xF].y,
            *v50,
            yb);
    v54 = this->MonoStack.Pages;
    s3 = v53;
    v55 = v54[v105 >> 4][v105 & 0xF];
    v56 = this->MeshVertices.Pages;
    v57 = v56[(v54[v122][v123]->srcVer & 0xFFFFFFF) >> 4];
    v58 = v57[v54[v122][v123]->srcVer & 0xF].y;
    v59 = &v57[v54[v122][v123]->srcVer & 0xF].x;
    v60 = v54[v112][v113]->srcVer & 0xFFFFFFF;
    v61 = &v56[(v55->srcVer & 0xFFFFFFF) >> 4][v55->srcVer & 0xF].x;
    v62 = &v56[v60 >> 4][v60 & 0xF].x;
    yc = v58;
    v12 = d;
    s4 = Scaleform::Render::Math2D::LinePointDistance(*v62, v62[1], *v61, v61[1], *v59, yc);
    v63 = -1;
    if ( d <= 0 )
    {
      sb = this->EdgeAAWidth;
      v64 = 0.0;
      if ( s1 > 0.0 && s2 > 0.0 )
      {
        if ( sb >= (double)s1 )
        {
          v66 = s2;
        }
        else
        {
          v63 = v99;
          v66 = s2;
          sb = s1;
        }
        if ( sb < v66 )
        {
          v63 = v101;
          sb = v66;
        }
      }
      if ( s3 > 0.0 && s4 > 0.0 )
      {
        if ( sb >= (double)s3 )
        {
          v67 = s4;
        }
        else
        {
          v63 = v98;
          v67 = s4;
          sb = s3;
        }
        if ( sb < v67 )
          v63 = v100;
      }
LABEL_39:
      if ( v63 != -1 )
      {
        yd = v64;
        Scaleform::Render::Tessellator::addTriangleAA(
          this,
          this->MonoStack.Pages[(v63 - d) >> 4][(v63 - d) & 0xF],
          this->MonoStack.Pages[v63 >> 4][v63 & 0xF],
          (unsigned int)this->MonoStack.Pages[(v63 + d) >> 4][(v63 + d) & 0xF],
          yd);
        v68 = this->MonoStack.Pages;
        if ( v63 == v99 )
        {
          v68[v18][i] = v68[v120][v121];
          ++n1;
          ++v101;
          ++v99;
          ++v109;
          ++v107;
        }
        else if ( v63 == v101 )
        {
          *(Scaleform::Render::Tessellator::MonoVertexType **)((char *)v68[v118] + v119) = v68[v18][i];
          this->MonoStack.Pages[v18][i] = this->MonoStack.Pages[v120][v121];
          ++n1;
          ++v101;
          ++v99;
          ++v109;
          ++v107;
        }
        else
        {
          if ( v63 == v98 )
          {
            v68[v112][v113] = v68[v124][v1];
          }
          else
          {
            v68[v122][v123] = v68[v112][v113];
            this->MonoStack.Pages[v112][v113] = this->MonoStack.Pages[v124][v1];
          }
          --n2;
          --v105;
          --v100;
          --v106;
          --v98;
        }
        goto LABEL_62;
      }
      goto LABEL_48;
    }
    sa = -this->EdgeAAWidth;
    v64 = 0.0;
    if ( s1 >= 0.0 )
    {
      v65 = s2;
LABEL_19:
      if ( v65 < 0.0 && s4 < 0.0 )
      {
        if ( sa > (double)s3 )
        {
          v63 = v98;
          sa = s3;
        }
        if ( sa > (double)s4 )
          v63 = v100;
      }
      goto LABEL_39;
    }
    if ( s2 < 0.0 )
    {
      if ( sa <= (double)s1 )
      {
        v65 = s2;
      }
      else
      {
        v63 = v99;
        v65 = s2;
        sa = s1;
      }
      if ( sa > v65 )
      {
        v63 = v101;
        sa = v65;
      }
      goto LABEL_19;
    }
LABEL_48:
    v69 = v109;
    sc = v64;
    v70 = v99;
    ia = v99;
    if ( v109 >= n2 )
      return;
    v1a = (const Scaleform::Render::TessVertex *)v109;
    do
    {
      v71 = this->MonoStack.Pages;
      v72 = v71[(v69 - 2) >> 4][((_BYTE)v69 - 2) & 0xF]->srcVer;
      v73 = v71[v69 >> 4][v69 & 0xF]->srcVer;
      v74 = v71[v70 >> 4][v70 & 0xF]->srcVer & 0xFFFFFFF;
      v75 = v74 & 0xF;
      v76 = this->MeshVertices.Pages;
      v72 &= 0xFFFFFFFu;
      v77 = v76[v74 >> 4];
      v78 = v77[v75].y;
      v79 = &v77[v75].x;
      ye = v78;
      v80 = v76[v72 >> 4];
      v81 = v76[(v73 & 0xFFFFFFF) >> 4];
      v82 = Scaleform::Render::Math2D::LinePointDistance(
              v81[v73 & 0xF].x,
              v81[v73 & 0xF].y,
              v80[v72 & 0xF].x,
              v80[v72 & 0xF].y,
              *v79,
              ye);
      v12 = d;
      s1a = v82;
      if ( d <= 0 )
      {
        if ( sc < (double)s1a )
        {
          v83 = ia;
          sc = v82;
          v63 = ia;
          goto LABEL_56;
        }
      }
      else if ( sc > (double)s1a )
      {
        v83 = ia;
        sc = v82;
        v63 = ia;
        goto LABEL_56;
      }
      v83 = ia;
LABEL_56:
      v69 = (unsigned int)&v1a->x + 1;
      v70 = v83 + 1;
      ia = v70;
      v1a = (const Scaleform::Render::TessVertex *)v69;
    }
    while ( v69 < n2 );
    if ( v63 != -1 )
    {
      Scaleform::Render::Tessellator::addTriangleAA(
        this,
        this->MonoStack.Pages[(v63 - d) >> 4][(v63 - d) & 0xF],
        this->MonoStack.Pages[v63 >> 4][v63 & 0xF],
        (unsigned int)this->MonoStack.Pages[(v63 + d) >> 4][(v63 + d) & 0xF],
        0.0);
      v84 = v63 + 1;
      ib = v84;
      if ( v84 < n2 )
      {
        v85 = v84 - 1;
        v1b = (const Scaleform::Render::TessVertex *)(v84 - 1);
        do
        {
          this->MonoStack.Pages[v85 >> 4][v85 & 0xF] = this->MonoStack.Pages[v84 >> 4][v84 & 0xF];
          v84 = ib + 1;
          v85 = (unsigned int)&v1b->x + 1;
          ib = v84;
          v1b = (const Scaleform::Render::TessVertex *)((char *)v1b + 1);
        }
        while ( v84 < n2 );
      }
      --n2;
      --v105;
      --v100;
      --v106;
      --v98;
LABEL_62:
      v13 = n1;
      if ( n2 <= v107 )
      {
        v3 = 0.0;
        goto LABEL_64;
      }
      v15 = v101;
      v16 = v99;
      continue;
    }
    break;
  }
}
