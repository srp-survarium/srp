void __thiscall Scaleform::Render::StrokeSorter::GenerateDashes(
        Scaleform::Render::StrokeSorter *this,
        const Scaleform::Render::DashArray *da,
        const Scaleform::Render::ToleranceParams *param,
        float scale)
{
  unsigned int v5; // edi
  int v6; // ebp
  float v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // esi
  int v10; // edx
  int v11; // eax
  _DWORD *v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // eax
  Scaleform::Render::StrokeSorter::VertexType **Pages; // edx
  int v17; // edi
  unsigned int v18; // eax
  unsigned int v19; // ebp
  unsigned int v20; // esi
  float v21; // ebp
  unsigned int v22; // eax
  float *v23; // eax
  unsigned int v24; // eax
  unsigned int v25; // ebp
  float *p_x; // eax
  const Scaleform::Render::DashArray *v27; // esi
  signed int DashCount; // eax
  unsigned int v29; // edx
  unsigned int v30; // edi
  float *v31; // ecx
  unsigned int v32; // esi
  unsigned int v33; // ecx
  float *v34; // esi
  float *v35; // edi
  unsigned int v36; // edi
  float *v37; // ecx
  unsigned int v38; // esi
  unsigned int v39; // eax
  float *v40; // esi
  float *v41; // edi
  unsigned int v42; // edi
  Scaleform::Render::StrokeSorter::PathType *v43; // ecx
  unsigned int Vertex; // eax
  unsigned int v45; // esi
  Scaleform::Render::StrokeSorter::PathType *v46; // esi
  unsigned int v47; // eax
  unsigned int Size; // edi
  unsigned int v49; // edi
  Scaleform::Render::StrokeSorter::VertexType *v50; // eax
  float v51; // ecx
  float v52; // edx
  int v53; // ecx
  unsigned int v54; // eax
  int v55; // [esp+38h] [ebp-11Ch]
  unsigned int v56; // [esp+38h] [ebp-11Ch]
  unsigned int v57; // [esp+3Ch] [ebp-118h]
  int v58; // [esp+3Ch] [ebp-118h]
  unsigned int v59; // [esp+3Ch] [ebp-118h]
  unsigned int v60; // [esp+40h] [ebp-114h]
  unsigned int v61; // [esp+40h] [ebp-114h]
  float y; // [esp+44h] [ebp-110h] BYREF
  unsigned int v63; // [esp+48h] [ebp-10Ch]
  float x; // [esp+4Ch] [ebp-108h] BYREF
  float v65; // [esp+50h] [ebp-104h]
  float v66; // [esp+54h] [ebp-100h]
  float v67; // [esp+58h] [ebp-FCh]
  int v68; // [esp+5Ch] [ebp-F8h]
  Scaleform::Render::ToleranceParams parama; // [esp+60h] [ebp-F4h] BYREF
  float dashArray[32]; // [esp+A0h] [ebp-B4h] BYREF
  Scaleform::Render::DashGenerator v71; // [esp+120h] [ebp-34h] BYREF
  float v72; // [esp+160h] [ebp+Ch]

  this->SrcVertices.MaxPages = 0;
  this->SrcVertices.NumPages = 0;
  this->SrcVertices.Size = 0;
  this->SrcVertices.Pages = 0;
  this->SrcPaths.MaxPages = 0;
  this->SrcPaths.NumPages = 0;
  this->SrcPaths.Size = 0;
  this->SrcPaths.Pages = 0;
  this->LastVertex = 0;
  qmemcpy(&parama, param, sizeof(parama));
  v5 = 0;
  v57 = 0;
  v72 = 1.0 / scale;
  parama.CollinearityTolerance = parama.CollinearityTolerance * v72;
  for ( parama.CurveTolerance = v72 * parama.CurveTolerance; v5 < this->OutPaths.Size; v57 = v5 )
  {
    v6 = 4 * (v5 >> 4);
    LODWORD(v7) = 8 * (v5 & 0xF);
    v8 = *(unsigned int *)((_BYTE *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)this->OutPaths.Pages + v6))->numVer
                         + LODWORD(v7))
       & 0xFFFFFFF;
    v55 = v6;
    y = v7;
    v63 = v8;
    v9 = 0;
    if ( v8 )
    {
      do
      {
        v10 = *(int *)((char *)this->OutPaths.Pages + v6);
        v11 = *(_DWORD *)(LODWORD(v7) + v10 + 4);
        v12 = (_DWORD *)(v10 + LODWORD(v7));
        v13 = v11 & 0xFFFFFFF;
        v14 = v9;
        if ( v9 >= v13 )
          v14 = v9 - v13;
        v15 = v14 + *v12;
        Pages = this->OutVertices.Pages;
        ++v9;
        v17 = (int)&Pages[v15 >> 4][v15 & 0xF];
        switch ( *(_BYTE *)(v17 + 12) )
        {
          case 1:
            ((void (__thiscall *)(Scaleform::Render::StrokeSorter *, _DWORD, _DWORD))this->AddVertex)(
              this,
              *(float *)v17,
              *(float *)(v17 + 4));
            break;
          case 2:
            v24 = v12[1] & 0xFFFFFFF;
            v25 = v9;
            if ( v9 >= v24 )
              v25 = v9 - v24;
            p_x = &Pages[(v25 + *v12) >> 4][(v25 + *v12) & 0xF].x;
            ++v9;
            Scaleform::Render::TessellateQuadCurve(this, &parama, *(float *)v17, *(float *)(v17 + 4), *p_x, p_x[1]);
            v6 = v55;
            break;
          case 3:
            v18 = v12[1] & 0xFFFFFFF;
            v19 = v9;
            if ( v9 >= v18 )
              v19 = v9 - v18;
            v20 = v9 + 1;
            LODWORD(v21) = &Pages[(v19 + *v12) >> 4][(v19 + *v12) & 0xF];
            v22 = v12[1] & 0xFFFFFFF;
            x = v21;
            if ( v20 >= v22 )
            {
              v60 = v20 - v22;
              v21 = x;
            }
            else
            {
              v60 = v20;
            }
            v23 = &Pages[(v60 + *v12) >> 4][(v60 + *v12) & 0xF].x;
            v9 = v20 + 1;
            Scaleform::Render::TessellateCubicCurve(
              this,
              &parama,
              *(float *)v17,
              *(float *)(v17 + 4),
              *(float *)LODWORD(v21),
              *(float *)(LODWORD(v21) + 4),
              *v23,
              v23[1]);
            v6 = v55;
            break;
        }
        v7 = y;
      }
      while ( v9 < v63 );
      v5 = v57;
    }
    this->FinalizePath(
      this,
      (*(unsigned int *)((char *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)this->OutPaths.Pages + v6))->numVer
                       + LODWORD(v7)) >> 29)
    & 1,
      0,
      0,
      0);
    ++v5;
  }
  v27 = da;
  this->OutVertices.MaxPages = 0;
  this->OutVertices.NumPages = 0;
  this->OutVertices.Size = 0;
  this->OutVertices.Pages = 0;
  this->OutPaths.MaxPages = 0;
  this->OutPaths.NumPages = 0;
  this->OutPaths.Size = 0;
  this->OutPaths.Pages = 0;
  DashCount = da->DashCount;
  v29 = 0;
  v30 = 0;
  v56 = 0;
  if ( DashCount >= 4 )
  {
    v31 = &da->Dashes[1];
    v63 = (char *)dashArray - (char *)da;
    v32 = ((unsigned int)(DashCount - 4) >> 2) + 1;
    v58 = 4 * v32;
    do
    {
      v29 += 4;
      *(&parama.Scale9LowerScale + v29) = *(v31 - 1);
      v31 += 4;
      --v32;
      *(&parama.Scale9UpperScale + v29) = *(v31 - 4);
      *(&parama.EdgeAAScale + v29) = *(v31 - 3);
      *(float *)((char *)v31 + (char *)dashArray - (char *)da - 16) = *(v31 - 2);
    }
    while ( v32 );
    v27 = da;
    v30 = v58;
    v56 = v29;
  }
  if ( v30 < DashCount )
  {
    v33 = DashCount - v30;
    v34 = &v27->Dashes[v30];
    v63 = DashCount - v30;
    v35 = &dashArray[v29];
    v29 += v63;
    qmemcpy(v35, v34, 4 * v33);
    v27 = da;
    v56 = v29;
  }
  if ( (v29 & 1) != 0 )
  {
    v36 = 0;
    if ( DashCount >= 4 )
    {
      v37 = &v27->Dashes[1];
      v38 = ((unsigned int)(DashCount - 4) >> 2) + 1;
      v36 = 4 * v38;
      do
      {
        v29 += 4;
        *(&parama.Scale9LowerScale + v29) = *(v37 - 1);
        v37 += 4;
        --v38;
        *(&parama.Scale9UpperScale + v29) = *(v37 - 4);
        *(&parama.EdgeAAScale + v29) = *(v37 - 3);
        *(&parama.MorphTolerance + v29) = *(v37 - 2);
      }
      while ( v38 );
      v27 = da;
      v56 = v29;
    }
    if ( v36 < DashCount )
    {
      v39 = DashCount - v36;
      v40 = &v27->Dashes[v36];
      v41 = &dashArray[v29];
      v29 += v39;
      qmemcpy(v41, v40, 4 * v39);
      v56 = v29;
    }
  }
  v42 = 0;
  v61 = 0;
  v59 = 0;
  if ( this->SrcPaths.Size )
  {
    while ( 1 )
    {
      v43 = &this->SrcPaths.Pages[v42 >> 4][v42 & 0xF];
      Scaleform::Render::DashGenerator::DashGenerator(
        &v71,
        dashArray,
        v29,
        da->DashStart,
        &this->SrcVertices.Pages[v43->start >> 4][v43->start & 0xF],
        v43->numVer & 0xFFFFFFF,
        (v43->numVer & 0x20000000) != 0);
      Vertex = Scaleform::Render::DashGenerator::GetVertex(&v71, &x, &y);
      if ( Vertex != 4 )
      {
        do
        {
          if ( !Vertex )
          {
            v45 = this->OutPaths.Size >> 4;
            if ( v45 >= this->OutPaths.NumPages )
              Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
                (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->OutPaths,
                this->OutPaths.Size >> 4);
            v46 = this->OutPaths.Pages[v45];
            v47 = this->OutPaths.Size & 0xF;
            v46[v47].start = v61;
            v46[v47].numVer = 0;
            ++this->OutPaths.Size;
          }
          Size = this->OutVertices.Size;
          v65 = x;
          v49 = Size >> 4;
          v66 = y;
          LOWORD(v68) = 1;
          v67 = 0.0;
          BYTE2(v68) = 0;
          if ( v49 >= this->OutVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(
              &this->OutVertices,
              v49);
          v50 = &this->OutVertices.Pages[v49][this->OutVertices.Size & 0xF];
          v51 = v66;
          v50->x = v65;
          v52 = v67;
          v50->y = v51;
          v53 = v68;
          v50->Dist = v52;
          *(_DWORD *)&v50->segType = v53;
          ++this->OutVertices.Size;
          v54 = this->OutPaths.Size;
          ++v61;
          ++this->OutPaths.Pages[(v54 - 1) >> 4][(v54 - 1) & 0xF].numVer;
          Vertex = Scaleform::Render::DashGenerator::GetVertex(&v71, &x, &y);
        }
        while ( Vertex != 4 );
        v42 = v59;
      }
      v59 = ++v42;
      if ( v42 >= this->SrcPaths.Size )
        break;
      v29 = v56;
    }
  }
}
