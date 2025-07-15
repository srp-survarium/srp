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
  signed int v28; // eax
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
  float Dist; // edx
  int v53; // ecx
  unsigned int v54; // eax
  unsigned int dashCount; // [esp+38h] [ebp-11Ch]
  unsigned int dashCounta; // [esp+38h] [ebp-11Ch]
  unsigned int i; // [esp+3Ch] [ebp-118h]
  unsigned int ia; // [esp+3Ch] [ebp-118h]
  unsigned int ib; // [esp+3Ch] [ebp-118h]
  unsigned int start; // [esp+40h] [ebp-114h]
  unsigned int starta; // [esp+40h] [ebp-114h]
  float y; // [esp+44h] [ebp-110h] BYREF
  unsigned int n; // [esp+48h] [ebp-10Ch]
  float x; // [esp+4Ch] [ebp-108h] BYREF
  Scaleform::Render::StrokeSorter::VertexType ver; // [esp+50h] [ebp-104h]
  Scaleform::Render::ToleranceParams p2; // [esp+60h] [ebp-F4h] BYREF
  float dashArray[32]; // [esp+A0h] [ebp-B4h] BYREF
  Scaleform::Render::DashGenerator dash; // [esp+120h] [ebp-34h] BYREF
  float scalea; // [esp+160h] [ebp+Ch]

  this->SrcVertices.MaxPages = 0;
  this->SrcVertices.NumPages = 0;
  this->SrcVertices.Size = 0;
  this->SrcVertices.Pages = 0;
  this->SrcPaths.MaxPages = 0;
  this->SrcPaths.NumPages = 0;
  this->SrcPaths.Size = 0;
  this->SrcPaths.Pages = 0;
  this->LastVertex = 0;
  qmemcpy(&p2, param, sizeof(p2));
  v5 = 0;
  i = 0;
  scalea = 1.0 / scale;
  p2.CollinearityTolerance = p2.CollinearityTolerance * scalea;
  for ( p2.CurveTolerance = scalea * p2.CurveTolerance; v5 < this->OutPaths.Size; i = v5 )
  {
    v6 = 4 * (v5 >> 4);
    LODWORD(v7) = 8 * (v5 & 0xF);
    v8 = *(unsigned int *)((_BYTE *)&(*(Scaleform::Render::StrokeSorter::PathType **)((char *)this->OutPaths.Pages + v6))->numVer
                         + LODWORD(v7))
       & 0xFFFFFFF;
    dashCount = v6;
    y = v7;
    n = v8;
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
            Scaleform::Render::TessellateQuadCurve(this, &p2, *(float *)v17, *(float *)(v17 + 4), *p_x, p_x[1]);
            v6 = dashCount;
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
              start = v20 - v22;
              v21 = x;
            }
            else
            {
              start = v20;
            }
            v23 = &Pages[(start + *v12) >> 4][(start + *v12) & 0xF].x;
            v9 = v20 + 1;
            Scaleform::Render::TessellateCubicCurve(
              this,
              &p2,
              *(float *)v17,
              *(float *)(v17 + 4),
              *(float *)LODWORD(v21),
              *(float *)(LODWORD(v21) + 4),
              *v23,
              v23[1]);
            v6 = dashCount;
            break;
        }
        v7 = y;
      }
      while ( v9 < n );
      v5 = i;
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
  v28 = da->DashCount;
  v29 = 0;
  v30 = 0;
  dashCounta = 0;
  if ( v28 >= 4 )
  {
    v31 = &da->Dashes[1];
    n = (char *)dashArray - (char *)da;
    v32 = ((unsigned int)(v28 - 4) >> 2) + 1;
    ia = 4 * v32;
    do
    {
      v29 += 4;
      *(&p2.Scale9LowerScale + v29) = *(v31 - 1);
      v31 += 4;
      --v32;
      *(&p2.Scale9UpperScale + v29) = *(v31 - 4);
      *(&p2.EdgeAAScale + v29) = *(v31 - 3);
      *(float *)((char *)v31 + (char *)dashArray - (char *)da - 16) = *(v31 - 2);
    }
    while ( v32 );
    v27 = da;
    v30 = ia;
    dashCounta = v29;
  }
  if ( v30 < v28 )
  {
    v33 = v28 - v30;
    v34 = &v27->Dashes[v30];
    n = v28 - v30;
    v35 = &dashArray[v29];
    v29 += n;
    qmemcpy(v35, v34, 4 * v33);
    v27 = da;
    dashCounta = v29;
  }
  if ( (v29 & 1) != 0 )
  {
    v36 = 0;
    if ( v28 >= 4 )
    {
      v37 = &v27->Dashes[1];
      v38 = ((unsigned int)(v28 - 4) >> 2) + 1;
      v36 = 4 * v38;
      do
      {
        v29 += 4;
        *(&p2.Scale9LowerScale + v29) = *(v37 - 1);
        v37 += 4;
        --v38;
        *(&p2.Scale9UpperScale + v29) = *(v37 - 4);
        *(&p2.EdgeAAScale + v29) = *(v37 - 3);
        *(&p2.MorphTolerance + v29) = *(v37 - 2);
      }
      while ( v38 );
      v27 = da;
      dashCounta = v29;
    }
    if ( v36 < v28 )
    {
      v39 = v28 - v36;
      v40 = &v27->Dashes[v36];
      v41 = &dashArray[v29];
      v29 += v39;
      qmemcpy(v41, v40, 4 * v39);
      dashCounta = v29;
    }
  }
  v42 = 0;
  starta = 0;
  ib = 0;
  if ( this->SrcPaths.Size )
  {
    while ( 1 )
    {
      v43 = &this->SrcPaths.Pages[v42 >> 4][v42 & 0xF];
      Scaleform::Render::DashGenerator::DashGenerator(
        &dash,
        dashArray,
        v29,
        da->DashStart,
        &this->SrcVertices.Pages[v43->start >> 4][v43->start & 0xF],
        v43->numVer & 0xFFFFFFF,
        (v43->numVer & 0x20000000) != 0);
      Vertex = Scaleform::Render::DashGenerator::GetVertex(&dash, &x, &y);
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
            v46[v47].start = starta;
            v46[v47].numVer = 0;
            ++this->OutPaths.Size;
          }
          Size = this->OutVertices.Size;
          ver.x = x;
          v49 = Size >> 4;
          ver.y = y;
          ver.segType = 1;
          ver.snapX = 0;
          ver.Dist = 0.0;
          ver.snapY = 0;
          if ( v49 >= this->OutVertices.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(
              &this->OutVertices,
              v49);
          v50 = &this->OutVertices.Pages[v49][this->OutVertices.Size & 0xF];
          v51 = ver.y;
          v50->x = ver.x;
          Dist = ver.Dist;
          v50->y = v51;
          v53 = *(_DWORD *)&ver.segType;
          v50->Dist = Dist;
          *(_DWORD *)&v50->segType = v53;
          ++this->OutVertices.Size;
          v54 = this->OutPaths.Size;
          ++starta;
          ++this->OutPaths.Pages[(v54 - 1) >> 4][(v54 - 1) & 0xF].numVer;
          Vertex = Scaleform::Render::DashGenerator::GetVertex(&dash, &x, &y);
        }
        while ( Vertex != 4 );
        v42 = ib;
      }
      ib = ++v42;
      if ( v42 >= this->SrcPaths.Size )
        break;
      v29 = dashCounta;
    }
  }
}
