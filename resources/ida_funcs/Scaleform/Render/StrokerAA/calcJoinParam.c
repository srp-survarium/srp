void __thiscall Scaleform::Render::StrokerAA::calcJoinParam(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokeVertex *v2,
        const Scaleform::Render::StrokeVertex *v3,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p)
{
  double xMiterThisR; // st7
  bool badMiterThisR; // dl
  float *p_xMiterNextL; // ebx
  bool badMiterNextL; // dl
  bool badMiterNextR; // dl
  double yMiterNextR; // st7
  bool v15; // zf
  bool rightTurnNext; // cl
  const Scaleform::Render::StrokeVertex *v17; // ecx
  bool rightSideCalc; // al
  double x; // st6
  double v20; // st6
  double y; // st6
  double v22; // st6
  BOOL v23; // edx
  double totalLimitR; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double totalLimitL; // st7
  double v29; // st7
  bool badMiterThisL; // al
  float ay; // [esp+4h] [ebp-44h]
  float aya; // [esp+4h] [ebp-44h]
  float v33; // [esp+8h] [ebp-40h]
  float v34; // [esp+8h] [ebp-40h]
  float by; // [esp+Ch] [ebp-3Ch]
  float bya; // [esp+Ch] [ebp-3Ch]
  float v37; // [esp+10h] [ebp-38h]
  float v38; // [esp+10h] [ebp-38h]
  float cy; // [esp+14h] [ebp-34h]
  float cya; // [esp+14h] [ebp-34h]
  float v41; // [esp+18h] [ebp-30h]
  float v42; // [esp+18h] [ebp-30h]
  float x1; // [esp+1Ch] [ebp-2Ch]
  float x1a; // [esp+1Ch] [ebp-2Ch]
  float dya; // [esp+3Ch] [ebp-Ch]
  float dyb; // [esp+3Ch] [ebp-Ch]
  float dyc; // [esp+3Ch] [ebp-Ch]
  float dyd; // [esp+3Ch] [ebp-Ch]
  float dy; // [esp+3Ch] [ebp-Ch]
  bool v50; // [esp+40h] [ebp-8h]
  float v2c; // [esp+50h] [ebp+8h]
  float v2d; // [esp+50h] [ebp+8h]
  float v2e; // [esp+50h] [ebp+8h]
  float v2f; // [esp+50h] [ebp+8h]
  float v2g; // [esp+50h] [ebp+8h]
  float v2h; // [esp+50h] [ebp+8h]
  float v2i; // [esp+50h] [ebp+8h]
  float v2j; // [esp+50h] [ebp+8h]
  float v2k; // [esp+50h] [ebp+8h]
  float v2l; // [esp+50h] [ebp+8h]
  float v2m; // [esp+50h] [ebp+8h]
  float v2n; // [esp+50h] [ebp+8h]
  float v2o; // [esp+50h] [ebp+8h]
  float v2p; // [esp+50h] [ebp+8h]
  float v2q; // [esp+50h] [ebp+8h]
  float v2r; // [esp+50h] [ebp+8h]
  float v2s; // [esp+50h] [ebp+8h]
  float v2t; // [esp+50h] [ebp+8h]
  float v2u; // [esp+50h] [ebp+8h]
  float v2v; // [esp+50h] [ebp+8h]
  float v2w; // [esp+50h] [ebp+8h]
  float v2x; // [esp+50h] [ebp+8h]
  float v2y; // [esp+50h] [ebp+8h]
  float v2z; // [esp+50h] [ebp+8h]
  float v2ba; // [esp+50h] [ebp+8h]
  float v2bb; // [esp+50h] [ebp+8h]
  float v2bc; // [esp+50h] [ebp+8h]
  float v2bd; // [esp+50h] [ebp+8h]
  float v2a; // [esp+50h] [ebp+8h]
  float v2b; // [esp+50h] [ebp+8h]
  float v3a; // [esp+54h] [ebp+Ch]
  float v3b; // [esp+54h] [ebp+Ch]
  float epsilon; // [esp+58h] [ebp+10h]
  char intersectionFailed; // [esp+5Ch] [ebp+14h]
  float intersectionFaileda; // [esp+5Ch] [ebp+14h]
  float intersectionFailedb; // [esp+5Ch] [ebp+14h]
  float intersectionFailedc; // [esp+5Ch] [ebp+14h]
  float intersectionFailedd; // [esp+5Ch] [ebp+14h]
  float intersectionFailede; // [esp+5Ch] [ebp+14h]
  float intersectionFailedf; // [esp+5Ch] [ebp+14h]
  float intersectionFailedg; // [esp+5Ch] [ebp+14h]
  float intersectionFailedh; // [esp+5Ch] [ebp+14h]

  p->dx1SolidL = p->dx2SolidL;
  p->dy1SolidL = p->dy2SolidL;
  p->dx1SolidR = p->dx2SolidR;
  p->dy1SolidR = p->dy2SolidR;
  p->dx1TotalL = p->dx2TotalL;
  p->dy1TotalL = p->dy2TotalL;
  p->dx1TotalR = p->dx2TotalR;
  p->dy1TotalR = p->dy2TotalR;
  p->dx2SolidL = p->dx3SolidL;
  p->dy2SolidL = p->dy3SolidL;
  p->dx2SolidR = p->dx3SolidR;
  p->dy2SolidR = p->dy3SolidR;
  p->dx2TotalL = p->dx3TotalL;
  p->dy2TotalL = p->dy3TotalL;
  p->dx2TotalR = p->dx3TotalR;
  p->dy2TotalR = p->dy3TotalR;
  v2c = (v3->y - v2->y) / v2->dist;
  dya = (v2->x - v3->x) / v2->dist;
  p->dx3SolidL = w->solidWidthL * v2c;
  p->dy3SolidL = w->solidWidthL * dya;
  p->dx3SolidR = w->solidWidthR * v2c;
  p->dy3SolidR = w->solidWidthR * dya;
  p->dx3TotalL = w->totalWidthL * v2c;
  p->dy3TotalL = w->totalWidthL * dya;
  p->dx3TotalR = v2c * w->totalWidthR;
  p->dy3TotalR = dya * w->totalWidthR;
  p->xMiterPrevL = p->xMiterThisL;
  p->yMiterPrevL = p->yMiterThisL;
  xMiterThisR = p->xMiterThisR;
  p->badMiterPrevL = p->badMiterThisL;
  p->xMiterPrevR = xMiterThisR;
  badMiterThisR = p->badMiterThisR;
  p->yMiterPrevR = p->yMiterThisR;
  p_xMiterNextL = &p->xMiterNextL;
  p->dMiterPrevL = p->dMiterThisL;
  p->badMiterPrevR = badMiterThisR;
  badMiterNextL = p->badMiterNextL;
  p->dMiterPrevR = p->dMiterThisR;
  p->xMiterThisL = p->xMiterNextL;
  p->badMiterThisL = badMiterNextL;
  badMiterNextR = p->badMiterNextR;
  p->yMiterThisL = p->yMiterNextL;
  p->xMiterThisR = p->xMiterNextR;
  p->badMiterThisR = badMiterNextR;
  yMiterNextR = p->yMiterNextR;
  intersectionFailed = 1;
  p->yMiterThisR = yMiterNextR;
  p->dMiterThisL = p->dMiterNextL;
  p->dMiterThisR = p->dMiterNextR;
  v15 = !w->rightSideCalc;
  epsilon = (v3->dist + v2->dist) * this->IntersectionEpsilon;
  if ( v15 )
  {
    v2q = (p->dx2TotalL + p->dx1TotalL) * 0.5;
    dyc = 0.5 * (p->dy1TotalL + p->dy2TotalL);
    v2r = dyc * dyc + v2q * v2q;
    v2s = sqrt(v2r);
    p->dbTotalL = v2s;
    p->dbSolidL = v2s * w->solidCoeffL;
    v2t = p->dbTotalL * w->widthCoeff;
    p->dbTotalR = v2t;
    p->dbSolidR = v2t * w->solidCoeffR;
    v2u = v3->y - p->dy3TotalL;
    x1a = v2u;
    v2v = v3->x - p->dx3TotalL;
    v42 = v2v;
    v2w = v2->y - p->dy3TotalL;
    cya = v2w;
    v2x = v2->x - p->dx3TotalL;
    v38 = v2x;
    v2y = v2->y - p->dy2TotalL;
    bya = v2y;
    v2z = v2->x - p->dx2TotalL;
    v34 = v2z;
    v2ba = v1->y - p->dy2TotalL;
    aya = v2ba;
    v2bb = v1->x - p->dx2TotalL;
    if ( !Scaleform::Render::Math2D::Intersection(
            v2bb,
            aya,
            v34,
            bya,
            v38,
            cya,
            v42,
            x1a,
            &p->xMiterNextL,
            &p->yMiterNextL,
            epsilon) )
      goto LABEL_7;
    v2bc = *p_xMiterNextL - v2->x;
    intersectionFailedd = p->yMiterNextL - v2->y;
    intersectionFailede = intersectionFailedd * intersectionFailedd + v2bc * v2bc;
    intersectionFailedf = sqrt(intersectionFailede);
    p->dMiterNextL = intersectionFailedf;
    p->dMiterNextR = intersectionFailedf * w->widthCoeff;
    p->xMiterNextR = v2->x - (*p_xMiterNextL - v2->x) * w->widthCoeff;
    p->yMiterNextR = v2->y - (p->yMiterNextL - v2->y) * w->widthCoeff;
  }
  else
  {
    v2d = (p->dx1TotalR + p->dx2TotalR) * 0.5;
    dyb = 0.5 * (p->dy1TotalR + p->dy2TotalR);
    v2e = dyb * dyb + v2d * v2d;
    v2f = sqrt(v2e);
    p->dbTotalR = v2f;
    p->dbSolidR = v2f * w->solidCoeffR;
    v2g = v2f * w->widthCoeff;
    p->dbTotalL = v2g;
    p->dbSolidL = v2g * w->solidCoeffL;
    v2h = v3->y + p->dy3TotalR;
    x1 = v2h;
    v2i = v3->x + p->dx3TotalR;
    v41 = v2i;
    v2j = v2->y + p->dy3TotalR;
    cy = v2j;
    v2k = v2->x + p->dx3TotalR;
    v37 = v2k;
    v2l = v2->y + p->dy2TotalR;
    by = v2l;
    v2m = v2->x + p->dx2TotalR;
    v33 = v2m;
    v2n = v1->y + p->dy2TotalR;
    ay = v2n;
    v2o = v1->x + p->dx2TotalR;
    if ( !Scaleform::Render::Math2D::Intersection(
            v2o,
            ay,
            v33,
            by,
            v37,
            cy,
            v41,
            x1,
            &p->xMiterNextR,
            &p->yMiterNextR,
            epsilon) )
      goto LABEL_7;
    v2p = p->xMiterNextR - v2->x;
    intersectionFaileda = p->yMiterNextR - v2->y;
    intersectionFailedb = intersectionFaileda * intersectionFaileda + v2p * v2p;
    intersectionFailedc = sqrt(intersectionFailedb);
    p->dMiterNextR = intersectionFailedc;
    p->dMiterNextL = intersectionFailedc * w->widthCoeff;
    *p_xMiterNextL = v2->x - (p->xMiterNextR - v2->x) * w->widthCoeff;
    p->yMiterNextL = v2->y - (p->yMiterNextR - v2->y) * w->widthCoeff;
  }
  intersectionFailed = 0;
  p->badMiterNextL = 0;
  p->badMiterNextR = 0;
LABEL_7:
  rightTurnNext = p->rightTurnNext;
  p->rightTurnPrev = p->rightTurnThis;
  p->rightTurnThis = rightTurnNext;
  v17 = v1;
  v2bd = (v3->x - v2->x) * (v2->y - v1->y) - (v3->y - v2->y) * (v2->x - v1->x);
  v50 = v2bd > 0.0;
  p->rightTurnNext = v50;
  if ( intersectionFailed )
  {
    rightSideCalc = w->rightSideCalc;
    x = v2->x;
    if ( rightSideCalc )
      v20 = x + p->dx2TotalR;
    else
      v20 = x - p->dx2TotalL;
    v2a = v20;
    y = v2->y;
    if ( rightSideCalc )
      v22 = y + p->dy2TotalR;
    else
      v22 = y - p->dy2TotalL;
    dyd = v22;
    intersectionFailedg = (v2a - v2->x) * (v2->y - v1->y) - (dyd - v2->y) * (v2->x - v1->x);
    v23 = intersectionFailedg < 0.0;
    intersectionFailedh = (v2a - v3->x) * (v3->y - v2->y) - (v3->x - v2->x) * (dyd - v3->y);
    if ( v23 == intersectionFailedh < 0.0 )
    {
      *p_xMiterNextL = v2->x - p->dx2TotalL;
      p->yMiterNextL = v2->y - p->dy2TotalL;
      p->dMiterNextL = w->totalLimitL;
      p->xMiterNextR = v2->x + p->dx2TotalR;
      p->yMiterNextR = v2->y + p->dy2TotalR;
      totalLimitR = w->totalLimitR;
      p->badMiterNextR = 0;
      p->dMiterNextR = totalLimitR;
      p->badMiterNextL = 0;
    }
    else
    {
      v2b = v2->x - (v1->x + v3->x) * 0.5;
      dy = v2->y - 0.5 * (v1->y + v3->y);
      v25 = v2->x;
      if ( v50 )
      {
        p->xMiterNextR = v25 + p->dx2TotalR;
        p->yMiterNextR = v2->y + p->dy2TotalR;
        v26 = w->totalLimitR;
        p->badMiterNextR = 1;
        p->dMiterNextR = v26;
        *p_xMiterNextL = v2b * 1024.0 + v2->x;
        v3a = 1024.0 * dy + v2->y;
        p->yMiterNextL = v3a;
        v27 = Scaleform::Render::Math2D::Distance(v2->x, v2->y, *p_xMiterNextL, v3a);
        v17 = v1;
        p->dMiterNextL = v27;
        p->badMiterNextL = 0;
      }
      else
      {
        *p_xMiterNextL = v25 - p->dx2TotalL;
        p->yMiterNextL = v2->y - p->dy2TotalL;
        totalLimitL = w->totalLimitL;
        p->badMiterNextL = 1;
        p->dMiterNextL = totalLimitL;
        p->xMiterNextR = v2b * 1024.0 + v2->x;
        v3b = 1024.0 * dy + v2->y;
        p->yMiterNextR = v3b;
        v29 = Scaleform::Render::Math2D::Distance(v2->x, v2->y, p->xMiterNextR, v3b);
        v17 = v1;
        p->dMiterNextR = v29;
        p->badMiterNextR = 0;
      }
    }
  }
  v15 = !p->rightTurnThis;
  p->overlapPrev = p->overlapThis;
  if ( v15 )
    badMiterThisL = p->badMiterThisL;
  else
    badMiterThisL = p->badMiterThisR;
  p->overlapThis = badMiterThisL;
  if ( !badMiterThisL )
    p->overlapThis = Scaleform::Render::StrokerAA::MitersIntersect(
                       p->xMiterThisL,
                       p->yMiterThisL,
                       p->xMiterThisR,
                       p->yMiterThisR,
                       *p_xMiterNextL,
                       p->yMiterNextL,
                       p->xMiterNextR,
                       p->yMiterNextR,
                       epsilon);
  p->xSolidMiterL = (p->xMiterThisL - v17->x) * w->solidCoeffL + v17->x;
  p->ySolidMiterL = (p->yMiterThisL - v17->y) * w->solidCoeffL + v17->y;
  p->xSolidMiterR = (p->xMiterThisR - v17->x) * w->solidCoeffR + v17->x;
  p->ySolidMiterR = (p->yMiterThisR - v17->y) * w->solidCoeffR + v17->y;
  p->dSolidMiterL = p->dMiterThisL * w->solidCoeffL;
  p->dSolidMiterR = p->dMiterThisR * w->solidCoeffR;
}
