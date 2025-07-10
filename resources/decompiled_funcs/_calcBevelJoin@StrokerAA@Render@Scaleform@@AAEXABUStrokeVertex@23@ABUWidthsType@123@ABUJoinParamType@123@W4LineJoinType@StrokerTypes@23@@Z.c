void __thiscall Scaleform::Render::StrokerAA::calcBevelJoin(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        const Scaleform::Render::StrokerAA::JoinParamType *p,
        Scaleform::Render::StrokerTypes::LineJoinType lineJoin)
{
  bool v7; // al
  bool v8; // zf
  double xMiterThisR; // st6
  double yMiterThisR; // st6
  double v13; // st6
  double v14; // st6
  double v15; // st7
  unsigned int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // edi
  double xMiterThisL; // st6
  double yMiterThisL; // st6
  double v22; // st6
  double v23; // st6
  double v24; // st7
  unsigned int v25; // eax
  unsigned int v26; // eax
  unsigned int v27; // edi
  float yb; // [esp+4h] [ebp-3Ch]
  float yc; // [esp+4h] [ebp-3Ch]
  float yd; // [esp+4h] [ebp-3Ch]
  float ye; // [esp+4h] [ebp-3Ch]
  float yf; // [esp+4h] [ebp-3Ch]
  float yg; // [esp+4h] [ebp-3Ch]
  float y; // [esp+4h] [ebp-3Ch]
  float yh; // [esp+4h] [ebp-3Ch]
  float yi; // [esp+4h] [ebp-3Ch]
  float yj; // [esp+4h] [ebp-3Ch]
  float yk; // [esp+4h] [ebp-3Ch]
  float yl; // [esp+4h] [ebp-3Ch]
  float ym; // [esp+4h] [ebp-3Ch]
  float yn; // [esp+4h] [ebp-3Ch]
  float ya; // [esp+4h] [ebp-3Ch]
  float yo; // [esp+4h] [ebp-3Ch]
  unsigned int StyleLeft; // [esp+8h] [ebp-38h]
  unsigned int StyleRight; // [esp+8h] [ebp-38h]
  unsigned int newSolidR; // [esp+20h] [ebp-20h]
  unsigned int newSolidRa; // [esp+20h] [ebp-20h]
  float newTotalRb; // [esp+24h] [ebp-1Ch]
  float newTotalRc; // [esp+24h] [ebp-1Ch]
  unsigned int newTotalR; // [esp+24h] [ebp-1Ch]
  float newTotalRd; // [esp+24h] [ebp-1Ch]
  float newTotalRe; // [esp+24h] [ebp-1Ch]
  float newTotalRf; // [esp+24h] [ebp-1Ch]
  float newTotalRg; // [esp+24h] [ebp-1Ch]
  unsigned int newTotalRa; // [esp+24h] [ebp-1Ch]
  float newTotalRh; // [esp+24h] [ebp-1Ch]
  float newTotalRi; // [esp+24h] [ebp-1Ch]
  float kSolid; // [esp+28h] [ebp-18h]
  float kSolida; // [esp+28h] [ebp-18h]
  float kSolidb; // [esp+28h] [ebp-18h]
  float kTotal; // [esp+2Ch] [ebp-14h]
  float kTotala; // [esp+2Ch] [ebp-14h]
  float yTotal; // [esp+30h] [ebp-10h]
  float yTotala; // [esp+30h] [ebp-10h]
  float xTotal; // [esp+34h] [ebp-Ch]
  float xTotala; // [esp+34h] [ebp-Ch]
  float ySolid; // [esp+38h] [ebp-8h]
  float ySolida; // [esp+38h] [ebp-8h]
  float xSolid; // [esp+3Ch] [ebp-4h]
  float xSolida; // [esp+3Ch] [ebp-4h]
  float y1f; // [esp+44h] [ebp+4h]
  float y1g; // [esp+44h] [ebp+4h]
  float y1; // [esp+44h] [ebp+4h]
  float y1h; // [esp+44h] [ebp+4h]
  float y1i; // [esp+44h] [ebp+4h]
  float y1j; // [esp+44h] [ebp+4h]
  float y1k; // [esp+44h] [ebp+4h]
  float y1l; // [esp+44h] [ebp+4h]
  float y1a; // [esp+44h] [ebp+4h]
  float y1m; // [esp+44h] [ebp+4h]
  float y1n; // [esp+44h] [ebp+4h]
  float y1o; // [esp+44h] [ebp+4h]
  unsigned int y1b; // [esp+44h] [ebp+4h]
  float y1p; // [esp+44h] [ebp+4h]
  float y1q; // [esp+44h] [ebp+4h]
  float y1r; // [esp+44h] [ebp+4h]
  float y1s; // [esp+44h] [ebp+4h]
  float y1t; // [esp+44h] [ebp+4h]
  float y1u; // [esp+44h] [ebp+4h]
  float y1v; // [esp+44h] [ebp+4h]
  float y1w; // [esp+44h] [ebp+4h]
  float y1x; // [esp+44h] [ebp+4h]
  float y1c; // [esp+44h] [ebp+4h]
  float y1y; // [esp+44h] [ebp+4h]
  float y1z; // [esp+44h] [ebp+4h]
  float y1ba; // [esp+44h] [ebp+4h]
  float y1bb; // [esp+44h] [ebp+4h]
  float y1bc; // [esp+44h] [ebp+4h]
  float y1d; // [esp+44h] [ebp+4h]
  float y1bd; // [esp+44h] [ebp+4h]
  float y1be; // [esp+44h] [ebp+4h]
  float y1bf; // [esp+44h] [ebp+4h]
  unsigned int y1e; // [esp+44h] [ebp+4h]
  float y1bg; // [esp+44h] [ebp+4h]
  float y1bh; // [esp+44h] [ebp+4h]
  float y1bi; // [esp+44h] [ebp+4h]
  float y1bj; // [esp+44h] [ebp+4h]
  float y1bk; // [esp+44h] [ebp+4h]
  float y1bl; // [esp+44h] [ebp+4h]
  float y1bm; // [esp+44h] [ebp+4h]
  float newSolidLb; // [esp+48h] [ebp+8h]
  float newSolidLc; // [esp+48h] [ebp+8h]
  unsigned int newSolidL; // [esp+48h] [ebp+8h]
  float newSolidLd; // [esp+48h] [ebp+8h]
  float newSolidLe; // [esp+48h] [ebp+8h]
  unsigned int newSolidLa; // [esp+48h] [ebp+8h]
  bool overlap; // [esp+4Ch] [ebp+Ch]
  float lineJoina; // [esp+50h] [ebp+10h]
  float lineJoinb; // [esp+50h] [ebp+10h]
  float lineJoinc; // [esp+50h] [ebp+10h]
  float lineJoind; // [esp+50h] [ebp+10h]
  float lineJoine; // [esp+50h] [ebp+10h]
  float lineJoinf; // [esp+50h] [ebp+10h]
  float lineJoing; // [esp+50h] [ebp+10h]
  float lineJoinh; // [esp+50h] [ebp+10h]
  float lineJoini; // [esp+50h] [ebp+10h]
  float lineJoinj; // [esp+50h] [ebp+10h]
  float lineJoink; // [esp+50h] [ebp+10h]
  float lineJoinl; // [esp+50h] [ebp+10h]

  kSolid = 0.0;
  v7 = p->overlapPrev || p->overlapThis;
  v8 = !p->rightTurnThis;
  overlap = v7;
  if ( v8 )
  {
    if ( v7 )
      xMiterThisL = v1->x - p->dx1TotalL;
    else
      xMiterThisL = p->xMiterThisL;
    xTotala = xMiterThisL;
    if ( v7 )
      yMiterThisL = v1->y - p->dy1TotalL;
    else
      yMiterThisL = p->yMiterThisL;
    yTotala = yMiterThisL;
    xSolida = (xTotala - v1->x) * w->solidCoeffL + v1->x;
    ySolida = (yTotala - v1->y) * w->solidCoeffL + v1->y;
    if ( lineJoin )
    {
      y1bb = p->dy1SolidR + v1->y;
      yj = y1bb;
      y1bc = p->dx1SolidR + v1->x;
      newSolidRa = Scaleform::Render::StrokerAA::addVertex(this, y1bc, yj, this->StyleRight, 1);
      y1d = p->dMiterThisR - p->dbTotalR;
      if ( 0.0 == y1d )
        y1d = 1.0;
      kTotala = (p->dbSolidR + w->totalWidthR - w->solidWidthR - p->dbTotalR) / y1d;
    }
    else
    {
      y1w = p->dSolidMiterR - p->dbSolidR;
      v22 = y1w;
      if ( y1w == 0.0 )
        v22 = (float)1.0;
      kSolidb = w->totalLimitR - p->dbSolidR - w->totalWidthR + w->solidWidthR;
      if ( kSolidb > v22 )
        kSolidb = v22;
      y1x = w->solidLimitR - p->dbSolidR;
      kSolid = (y1x + kSolidb) / (v22 * 2.0);
      y1c = p->dMiterThisR - p->dbTotalR;
      if ( 0.0 == y1c )
        y1c = 1.0;
      newSolidLd = w->solidLimitR - p->dbTotalR + w->totalWidthR - w->solidWidthR;
      v23 = newSolidLd;
      newSolidLe = w->totalLimitR - p->dbTotalR;
      kTotala = (v23 + newSolidLe) / (2.0 * y1c);
      newTotalRf = p->dx1SolidR + v1->x;
      y1y = p->dy1SolidR + v1->y;
      y1z = y1y + (p->ySolidMiterR - y1y) * kSolid;
      yi = y1z;
      y1ba = kSolid * (p->xSolidMiterR - newTotalRf) + newTotalRf;
      newSolidRa = Scaleform::Render::StrokerAA::addVertex(this, y1ba, yi, this->StyleRight, 1);
    }
    v24 = kTotala;
    if ( w->aaFlagR )
    {
      newTotalRg = p->dx1TotalR + v1->x;
      y1bd = p->dy1TotalR + v1->y;
      y1be = (p->yMiterThisR - y1bd) * v24 + y1bd;
      yk = y1be;
      y1bf = v24 * (p->xMiterThisR - newTotalRg) + newTotalRg;
      v25 = Scaleform::Render::StrokerAA::addVertex(this, y1bf, yk, this->StyleRight, 0);
    }
    else
    {
      v25 = newSolidRa;
    }
    newTotalRa = v25;
    if ( w->solidFlag )
      newSolidLa = Scaleform::Render::StrokerAA::addVertex(this, xSolida, ySolida, this->StyleLeft, 1);
    else
      newSolidLa = newSolidRa;
    if ( w->aaFlagL )
      y1e = Scaleform::Render::StrokerAA::addVertex(this, xTotala, yTotala, this->StyleLeft, 0);
    else
      y1e = newSolidLa;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newSolidRa, newSolidLa);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newSolidLa, this->SolidL);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, newSolidRa, this->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, newTotalRa, newSolidRa);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, newSolidLa, y1e);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, y1e, this->TotalL);
    }
    this->SolidL = newSolidLa;
    this->TotalL = y1e;
    this->SolidR = newSolidRa;
    this->TotalR = newTotalRa;
    if ( overlap )
    {
      y1bg = v1->y - p->dy2SolidL;
      yl = y1bg;
      y1bh = v1->x - p->dx2SolidL;
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(this, y1bh, yl, this->StyleLeft, 1);
      if ( w->aaFlagL )
      {
        y1bi = v1->y - p->dy2TotalL;
        ym = y1bi;
        y1bj = v1->x - p->dx2TotalL;
        v26 = Scaleform::Render::StrokerAA::addVertex(this, y1bj, ym, this->StyleLeft, 0);
      }
      else
      {
        v26 = newSolidLa;
      }
      this->TotalL = v26;
    }
    y1bk = this->Tolerance * 0.25 * 0.25;
    if ( y1bk < w->totalWidthR - p->dbTotalR )
    {
      if ( w->solidFlag )
      {
        StyleRight = this->StyleRight;
        if ( lineJoin )
        {
          lineJoini = p->dy2SolidR + v1->y;
          ya = lineJoini;
          lineJoinj = p->dx2SolidR + v1->x;
          newSolidRa = Scaleform::Render::StrokerAA::addVertex(this, lineJoinj, ya, StyleRight, 1);
        }
        else
        {
          newTotalRh = p->dx2SolidR + v1->x;
          y1bl = p->dy2SolidR + v1->y;
          lineJoing = y1bl + (p->ySolidMiterR - y1bl) * kSolid;
          yn = lineJoing;
          lineJoinh = kSolid * (p->xSolidMiterR - newTotalRh) + newTotalRh;
          newSolidRa = Scaleform::Render::StrokerAA::addVertex(this, lineJoinh, yn, StyleRight, 1);
        }
      }
      if ( w->aaFlagR )
      {
        newTotalRi = p->dx2TotalR + v1->x;
        y1bm = p->dy2TotalR + v1->y;
        lineJoink = y1bm + (p->yMiterThisR - y1bm) * kTotala;
        yo = lineJoink;
        lineJoinl = kTotala * (p->xMiterThisR - newTotalRi) + newTotalRi;
        v27 = Scaleform::Render::StrokerAA::addVertex(this, lineJoinl, yo, this->StyleRight, 0);
      }
      else
      {
        v27 = newSolidRa;
      }
      if ( w->solidFlagR )
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, newSolidRa);
      if ( w->aaFlagR )
      {
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, newSolidRa);
        Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v27, newSolidRa);
      }
      this->SolidR = newSolidRa;
      this->TotalR = v27;
    }
  }
  else
  {
    if ( v7 )
      xMiterThisR = p->dx1TotalR + v1->x;
    else
      xMiterThisR = p->xMiterThisR;
    xTotal = xMiterThisR;
    if ( v7 )
      yMiterThisR = p->dy1TotalR + v1->y;
    else
      yMiterThisR = p->yMiterThisR;
    yTotal = yMiterThisR;
    xSolid = (xTotal - v1->x) * w->solidCoeffR + v1->x;
    ySolid = (yTotal - v1->y) * w->solidCoeffR + v1->y;
    if ( lineJoin )
    {
      y1k = v1->y - p->dy1SolidL;
      yc = y1k;
      y1l = v1->x - p->dx1SolidL;
      newSolidL = Scaleform::Render::StrokerAA::addVertex(this, y1l, yc, this->StyleLeft, 1);
      y1a = p->dMiterThisL - p->dbTotalL;
      if ( 0.0 == y1a )
        y1a = 1.0;
      kTotal = (p->dbSolidL + w->totalWidthL - w->solidWidthL - p->dbTotalL) / y1a;
    }
    else
    {
      y1f = p->dSolidMiterL - p->dbSolidL;
      v13 = y1f;
      if ( y1f == 0.0 )
        v13 = (float)1.0;
      kSolida = w->totalLimitL - p->dbSolidL - w->totalWidthL + w->solidWidthL;
      if ( kSolida > v13 )
        kSolida = v13;
      y1g = w->solidLimitL - p->dbSolidL;
      kSolid = (y1g + kSolida) / (v13 * 2.0);
      y1 = p->dMiterThisL - p->dbTotalL;
      if ( 0.0 == y1 )
        y1 = 1.0;
      newSolidLb = w->solidLimitL - p->dbTotalL + w->totalWidthL - w->solidWidthL;
      v14 = newSolidLb;
      newSolidLc = w->totalLimitL - p->dbTotalL;
      kTotal = (v14 + newSolidLc) / (2.0 * y1);
      newTotalRb = v1->x - p->dx1SolidL;
      y1h = v1->y - p->dy1SolidL;
      y1i = y1h + (p->ySolidMiterL - y1h) * kSolid;
      yb = y1i;
      y1j = kSolid * (p->xSolidMiterL - newTotalRb) + newTotalRb;
      newSolidL = Scaleform::Render::StrokerAA::addVertex(this, y1j, yb, this->StyleLeft, 1);
    }
    v15 = kTotal;
    if ( w->aaFlagL )
    {
      newTotalRc = v1->x - p->dx1TotalL;
      y1m = v1->y - p->dy1TotalL;
      y1n = (p->yMiterThisL - y1m) * v15 + y1m;
      yd = y1n;
      y1o = v15 * (p->xMiterThisL - newTotalRc) + newTotalRc;
      v16 = Scaleform::Render::StrokerAA::addVertex(this, y1o, yd, this->StyleLeft, 0);
    }
    else
    {
      v16 = newSolidL;
    }
    y1b = v16;
    if ( w->solidFlag )
      newSolidR = Scaleform::Render::StrokerAA::addVertex(this, xSolid, ySolid, this->StyleRight, 1);
    else
      newSolidR = newSolidL;
    if ( w->aaFlagR )
      newTotalR = Scaleform::Render::StrokerAA::addVertex(this, xTotal, yTotal, this->StyleRight, 0);
    else
      newTotalR = newSolidR;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, newSolidR, newSolidL);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, newSolidR);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, newSolidL);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, newSolidL, y1b);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newTotalR, newSolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, newTotalR);
    }
    this->SolidL = newSolidL;
    this->TotalL = y1b;
    this->SolidR = newSolidR;
    this->TotalR = newTotalR;
    if ( overlap )
    {
      y1p = p->dy2SolidR + v1->y;
      ye = y1p;
      y1q = p->dx2SolidR + v1->x;
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(this, y1q, ye, this->StyleRight, 1);
      if ( w->aaFlagR )
      {
        y1r = p->dy2TotalR + v1->y;
        yf = y1r;
        y1s = p->dx2TotalR + v1->x;
        v17 = Scaleform::Render::StrokerAA::addVertex(this, y1s, yf, this->StyleRight, 0);
      }
      else
      {
        v17 = newSolidR;
      }
      this->TotalR = v17;
    }
    y1t = this->Tolerance * 0.25 * 0.25;
    if ( y1t < w->totalWidthL - p->dbTotalL )
    {
      if ( w->solidFlag )
      {
        StyleLeft = this->StyleLeft;
        if ( lineJoin )
        {
          lineJoinc = v1->y - p->dy2SolidL;
          y = lineJoinc;
          lineJoind = v1->x - p->dx2SolidL;
          newSolidL = Scaleform::Render::StrokerAA::addVertex(this, lineJoind, y, StyleLeft, 1);
        }
        else
        {
          newTotalRd = v1->x - p->dx2SolidL;
          y1u = v1->y - p->dy2SolidL;
          lineJoina = y1u + (p->ySolidMiterL - y1u) * kSolid;
          yg = lineJoina;
          lineJoinb = kSolid * (p->xSolidMiterL - newTotalRd) + newTotalRd;
          newSolidL = Scaleform::Render::StrokerAA::addVertex(this, lineJoinb, yg, StyleLeft, 1);
        }
      }
      if ( w->aaFlagL )
      {
        newTotalRe = v1->x - p->dx2TotalL;
        y1v = v1->y - p->dy2TotalL;
        lineJoine = y1v + (p->yMiterThisL - y1v) * kTotal;
        yh = lineJoine;
        lineJoinf = kTotal * (p->xMiterThisL - newTotalRe) + newTotalRe;
        v18 = Scaleform::Render::StrokerAA::addVertex(this, lineJoinf, yh, this->StyleLeft, 0);
      }
      else
      {
        v18 = newSolidL;
      }
      if ( w->solidFlagL )
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newSolidL, this->SolidL);
      if ( w->aaFlagL )
      {
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, newSolidL, this->TotalL);
        Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, newSolidL, v18);
      }
      this->TotalL = v18;
      this->SolidL = newSolidL;
    }
  }
}
