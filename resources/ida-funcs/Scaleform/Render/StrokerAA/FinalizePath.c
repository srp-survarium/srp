void __thiscall Scaleform::Render::StrokerAA::FinalizePath(
        Scaleform::Render::StrokerAA *this,
        unsigned int __formal,
        unsigned int a3,
        bool a4,
        bool a5)
{
  unsigned int Size; // eax
  const Scaleform::Render::StrokeVertex **Pages; // ebx
  const Scaleform::Render::StrokeVertex *v8; // ebp
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // edi
  unsigned int v13; // edx
  unsigned int v14; // ebx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  Scaleform::Render::StrokerAA::TriangleType *v17; // eax
  double v18; // st7
  Scaleform::Render::StrokeVertex *v19; // eax
  unsigned int v20; // ecx
  Scaleform::Render::StrokeVertex **v21; // edx
  Scaleform::Render::StrokeVertex *v22; // edi
  int v23; // eax
  float *p_x; // eax
  Scaleform::Render::StrokeVertex *v25; // edx
  int v26; // ecx
  double x; // st6
  float *v28; // ecx
  Scaleform::Render::StrokeVertex *v29; // ecx
  Scaleform::Render::StrokerTypes::LineCapType StartLineCap; // edx
  const Scaleform::Render::StrokeVertex *v31; // eax
  unsigned int v32; // ebp
  Scaleform::Render::StrokeVertex *v33; // edi
  unsigned int v34; // ebx
  unsigned int v35; // edi
  unsigned int v36; // ebp
  Scaleform::Render::StrokeVertex **v37; // eax
  float *v38; // ecx
  unsigned int v39; // ebx
  Scaleform::Render::StrokeVertex *v40; // edx
  int v41; // ebx
  unsigned int v42; // ecx
  unsigned int v43; // ecx
  Scaleform::Render::StrokeVertex **v44; // edi
  const Scaleform::Render::StrokeVertex *v45; // edx
  const Scaleform::Render::StrokeVertex *v46; // ecx
  Scaleform::Render::StrokerTypes::LineCapType EndLineCap; // eax
  unsigned int i; // [esp+1Ch] [ebp-12Ch]
  float ia; // [esp+1Ch] [ebp-12Ch]
  float ib; // [esp+1Ch] [ebp-12Ch]
  unsigned int avrInc; // [esp+20h] [ebp-128h]
  float avrInca; // [esp+20h] [ebp-128h]
  Scaleform::Render::StrokerAA::WidthsType widths; // [esp+24h] [ebp-124h] BYREF
  Scaleform::Render::StrokeVertex vLast; // [esp+60h] [ebp-E8h] BYREF
  Scaleform::Render::StrokerAA::JoinParamType joinParam; // [esp+6Ch] [ebp-DCh] BYREF

  if ( !this->Closed )
    this->Closed = Scaleform::Render::StrokePath::ClosePath(&this->Path);
  widths.solidWidthL = 0.0;
  widths.solidWidthR = 0.0;
  widths.solidWidth = 0.0;
  this->SolidL = -4;
  widths.totalWidthL = 0.0;
  this->SolidR = -3;
  widths.totalWidthR = 0.0;
  this->TotalL = -2;
  widths.totalWidth = 0.0;
  this->TotalR = -1;
  widths.widthCoeff = 0.0;
  widths.solidFlagL = 0;
  widths.solidCoeffL = 0.0;
  widths.solidFlagR = 0;
  widths.solidCoeffR = 0.0;
  widths.aaFlagL = 0;
  widths.solidLimitL = 0.0;
  widths.aaFlagR = 0;
  widths.solidLimitR = 0.0;
  widths.solidFlag = 0;
  widths.totalLimitL = 0.0;
  widths.rightSideCalc = 0;
  widths.totalLimitR = 0.0;
  Scaleform::Render::StrokerAA::calcWidths(this, &widths);
  Scaleform::Render::StrokerAA::JoinParamType::JoinParamType(&joinParam);
  if ( this->Closed )
  {
    Size = this->Path.Path.Size;
    if ( Size > 2 )
    {
      Pages = (const Scaleform::Render::StrokeVertex **)this->Path.Path.Pages;
      v8 = *Pages;
      v9 = Size - 1;
      Scaleform::Render::StrokerAA::calcJoinParam(
        this,
        &Pages[(Size - 2) >> 4][(Size - 2) & 0xF],
        &Pages[(Size - 1) >> 4][((_BYTE)Size - 1) & 0xF],
        *Pages,
        &widths,
        &joinParam);
      Scaleform::Render::StrokerAA::calcJoinParam(this, &Pages[v9 >> 4][v9 & 0xF], v8, v8 + 1, &widths, &joinParam);
      avrInc = this->Triangles.Size;
      if ( this->Path.Path.Size )
      {
        v10 = 1;
        do
        {
          v11 = this->Path.Path.Size;
          v12 = v10 + 1;
          v13 = v10 + 1;
          if ( v10 + 1 >= v11 )
            v13 -= v11;
          v14 = this->Path.Path.Size;
          v15 = v10;
          if ( v10 >= v14 )
            v15 = v10 - v14;
          Scaleform::Render::StrokerAA::calcJoin(
            this,
            &this->Path.Path.Pages[(v10 - 1) >> 4][((_BYTE)v10 - 1) & 0xF],
            &this->Path.Path.Pages[v15 >> 4][v15 & 0xF],
            &this->Path.Path.Pages[v13 >> 4][v13 & 0xF],
            &widths,
            &joinParam);
          v10 = v12;
        }
        while ( v12 - 1 < this->Path.Path.Size );
      }
      v16 = avrInc;
      for ( i = 0; i < 6; ++i )
      {
        if ( v16 >= this->Triangles.Size )
          break;
        v17 = &this->Triangles.Pages[v16 >> 4][v16 & 0xF];
        if ( v17->v1 == -4 )
          v17->v1 = this->SolidL;
        if ( v17->v1 == -3 )
          v17->v1 = this->SolidR;
        if ( v17->v1 == -2 )
          v17->v1 = this->TotalL;
        if ( v17->v1 == -1 )
          v17->v1 = this->TotalR;
        if ( v17->v2 == -4 )
          v17->v2 = this->SolidL;
        if ( v17->v2 == -3 )
          v17->v2 = this->SolidR;
        if ( v17->v2 == -2 )
          v17->v2 = this->TotalL;
        if ( v17->v2 == -1 )
          v17->v2 = this->TotalR;
        if ( v17->v3 == -4 )
          v17->v3 = this->SolidL;
        if ( v17->v3 == -3 )
          v17->v3 = this->SolidR;
        if ( v17->v3 == -2 )
          v17->v3 = this->TotalL;
        if ( v17->v3 == -1 )
          v17->v3 = this->TotalR;
        ++v16;
      }
    }
  }
  else if ( this->Path.Path.Size > 1 )
  {
    avrInca = (this->WidthRight + this->WidthLeft) * 0.5;
    v18 = avrInca;
    if ( this->StartLineCap == SquareCap )
    {
      v19 = *this->Path.Path.Pages;
      v19->x = v19->x - (v19[1].x - v19->x) * v18 / v19->dist;
      v19->y = v19->y - (v19[1].y - v19->y) * v18 / v19->dist;
      v19->dist = v19->dist + v18;
    }
    if ( this->EndLineCap == SquareCap )
    {
      v20 = this->Path.Path.Size;
      v21 = this->Path.Path.Pages;
      v22 = v21[(v20 - 2) >> 4];
      v23 = (v20 - 2) & 0xF;
      --v20;
      p_x = &v22[v23].x;
      v25 = v21[v20 >> 4];
      v26 = v20 & 0xF;
      x = v25[v26].x;
      v28 = &v25[v26].x;
      *v28 = (x - *p_x) * v18 / p_x[2] + *v28;
      v28[1] = (v28[1] - p_x[1]) * v18 / p_x[2] + v28[1];
      p_x[2] = v18 + p_x[2];
    }
    v29 = *this->Path.Path.Pages;
    StartLineCap = this->StartLineCap;
    ia = v29->dist;
    v31 = v29 + 1;
    if ( StartLineCap >= ButtCap )
    {
      if ( StartLineCap <= SquareCap )
      {
        Scaleform::Render::StrokerAA::calcButtCap(this, v29, v31, ia, &widths, 0);
      }
      else if ( StartLineCap == RoundCap )
      {
        Scaleform::Render::StrokerAA::calcRoundCap(this, v29, v31, ia, &widths, 0);
      }
    }
    v32 = this->Path.Path.Size;
    if ( v32 > 2 )
    {
      v33 = *this->Path.Path.Pages;
      Scaleform::Render::StrokerAA::calcInitialJoinParam(this, v33, v33 + 1, &widths, &joinParam);
      Scaleform::Render::StrokerAA::calcJoinParam(this, v33, v33 + 1, v33 + 2, &widths, &joinParam);
      v34 = v32 - 2;
      v35 = 1;
      if ( v32 - 2 > 1 )
      {
        v36 = 2;
        do
        {
          Scaleform::Render::StrokerAA::calcJoin(
            this,
            &this->Path.Path.Pages[v35 >> 4][v35 & 0xF],
            &this->Path.Path.Pages[v36 >> 4][v36 & 0xF],
            &this->Path.Path.Pages[(v36 + 1) >> 4][(v36 + 1) & 0xF],
            &widths,
            &joinParam);
          ++v35;
          ++v36;
        }
        while ( v35 < v34 );
      }
      v37 = this->Path.Path.Pages;
      v38 = &v37[v34 >> 4][v34 & 0xF].x;
      v39 = v34 + 1;
      v40 = v37[v39 >> 4];
      v41 = v39 & 0xF;
      vLast.x = v40[v41].x * 2.0 - *v38;
      vLast.y = 2.0 * v40[v41].y - v38[1];
      vLast.dist = v38[2];
      Scaleform::Render::StrokerAA::calcJoin(
        this,
        &v37[v35 >> 4][v35 & 0xF],
        &v37[(v35 + 1) >> 4][(v35 + 1) & 0xF],
        &vLast,
        &widths,
        &joinParam);
    }
    v42 = this->Path.Path.Size;
    Scaleform::Render::StrokerAA::calcButtJoin(
      this,
      &this->Path.Path.Pages[(v42 - 2) >> 4][(v42 - 2) & 0xF],
      &this->Path.Path.Pages[(v42 - 1) >> 4][(v42 - 1) & 0xF],
      this->Path.Path.Pages[(v42 - 2) >> 4][((_BYTE)v42 - 2) & 0xF].dist,
      &widths);
    v43 = this->Path.Path.Size;
    v44 = this->Path.Path.Pages;
    ib = v44[(v43 - 2) >> 4][((_BYTE)v43 - 2) & 0xF].dist;
    v45 = &v44[(v43 - 2) >> 4][(v43 - 2) & 0xF];
    v46 = &v44[(v43 - 1) >> 4][(v43 - 1) & 0xF];
    EndLineCap = this->EndLineCap;
    if ( EndLineCap >= ButtCap )
    {
      if ( EndLineCap <= SquareCap )
      {
        Scaleform::Render::StrokerAA::calcButtCap(this, v46, v45, ib, &widths, 1);
      }
      else if ( EndLineCap == RoundCap )
      {
        Scaleform::Render::StrokerAA::calcRoundCap(this, v46, v45, ib, &widths, 1);
      }
    }
  }
  Scaleform::Render::StrokePath::Clear(&this->Path);
  this->Closed = 0;
}
