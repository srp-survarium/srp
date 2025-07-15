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
  float dy; // [esp+1Ch] [ebp-2Ch]
  float dya; // [esp+1Ch] [ebp-2Ch]
  float v45; // [esp+3Ch] [ebp-Ch]
  float v46; // [esp+3Ch] [ebp-Ch]
  float v47; // [esp+3Ch] [ebp-Ch]
  float v48; // [esp+3Ch] [ebp-Ch]
  float v49; // [esp+3Ch] [ebp-Ch]
  bool v50; // [esp+40h] [ebp-8h]
  float v51; // [esp+50h] [ebp+8h]
  float v52; // [esp+50h] [ebp+8h]
  float v53; // [esp+50h] [ebp+8h]
  float v54; // [esp+50h] [ebp+8h]
  float v55; // [esp+50h] [ebp+8h]
  float v56; // [esp+50h] [ebp+8h]
  float v57; // [esp+50h] [ebp+8h]
  float v58; // [esp+50h] [ebp+8h]
  float v59; // [esp+50h] [ebp+8h]
  float v60; // [esp+50h] [ebp+8h]
  float v61; // [esp+50h] [ebp+8h]
  float v62; // [esp+50h] [ebp+8h]
  float v63; // [esp+50h] [ebp+8h]
  float v64; // [esp+50h] [ebp+8h]
  float v65; // [esp+50h] [ebp+8h]
  float v66; // [esp+50h] [ebp+8h]
  float v67; // [esp+50h] [ebp+8h]
  float v68; // [esp+50h] [ebp+8h]
  float v69; // [esp+50h] [ebp+8h]
  float v70; // [esp+50h] [ebp+8h]
  float v71; // [esp+50h] [ebp+8h]
  float v72; // [esp+50h] [ebp+8h]
  float v73; // [esp+50h] [ebp+8h]
  float v74; // [esp+50h] [ebp+8h]
  float v75; // [esp+50h] [ebp+8h]
  float v76; // [esp+50h] [ebp+8h]
  float v77; // [esp+50h] [ebp+8h]
  float v78; // [esp+50h] [ebp+8h]
  float v79; // [esp+50h] [ebp+8h]
  float v80; // [esp+50h] [ebp+8h]
  float v81; // [esp+54h] [ebp+Ch]
  float v82; // [esp+54h] [ebp+Ch]
  float epsilon; // [esp+58h] [ebp+10h]
  char v84; // [esp+5Ch] [ebp+14h]
  float v85; // [esp+5Ch] [ebp+14h]
  float v86; // [esp+5Ch] [ebp+14h]
  float v87; // [esp+5Ch] [ebp+14h]
  float v88; // [esp+5Ch] [ebp+14h]
  float v89; // [esp+5Ch] [ebp+14h]
  float v90; // [esp+5Ch] [ebp+14h]
  float v91; // [esp+5Ch] [ebp+14h]
  float v92; // [esp+5Ch] [ebp+14h]

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
  v51 = (v3->y - v2->y) / v2->dist;
  v45 = (v2->x - v3->x) / v2->dist;
  p->dx3SolidL = w->solidWidthL * v51;
  p->dy3SolidL = w->solidWidthL * v45;
  p->dx3SolidR = w->solidWidthR * v51;
  p->dy3SolidR = w->solidWidthR * v45;
  p->dx3TotalL = w->totalWidthL * v51;
  p->dy3TotalL = w->totalWidthL * v45;
  p->dx3TotalR = v51 * w->totalWidthR;
  p->dy3TotalR = v45 * w->totalWidthR;
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
  v84 = 1;
  p->yMiterThisR = yMiterNextR;
  p->dMiterThisL = p->dMiterNextL;
  p->dMiterThisR = p->dMiterNextR;
  v15 = !w->rightSideCalc;
  epsilon = (v3->dist + v2->dist) * this->IntersectionEpsilon;
  if ( v15 )
  {
    v65 = (p->dx2TotalL + p->dx1TotalL) * 0.5;
    v47 = 0.5 * (p->dy1TotalL + p->dy2TotalL);
    v66 = v47 * v47 + v65 * v65;
    v67 = sqrt(v66);
    p->dbTotalL = v67;
    p->dbSolidL = v67 * w->solidCoeffL;
    v68 = p->dbTotalL * w->widthCoeff;
    p->dbTotalR = v68;
    p->dbSolidR = v68 * w->solidCoeffR;
    v69 = v3->y - p->dy3TotalL;
    dya = v69;
    v70 = v3->x - p->dx3TotalL;
    v42 = v70;
    v71 = v2->y - p->dy3TotalL;
    cya = v71;
    v72 = v2->x - p->dx3TotalL;
    v38 = v72;
    v73 = v2->y - p->dy2TotalL;
    bya = v73;
    v74 = v2->x - p->dx2TotalL;
    v34 = v74;
    v75 = v1->y - p->dy2TotalL;
    aya = v75;
    v76 = v1->x - p->dx2TotalL;
    if ( !Scaleform::Render::Math2D::Intersection(
            v76,
            aya,
            v34,
            bya,
            v38,
            cya,
            v42,
            dya,
            &p->xMiterNextL,
            &p->yMiterNextL,
            epsilon) )
      goto LABEL_7;
    v77 = *p_xMiterNextL - v2->x;
    v88 = p->yMiterNextL - v2->y;
    v89 = v88 * v88 + v77 * v77;
    v90 = sqrt(v89);
    p->dMiterNextL = v90;
    p->dMiterNextR = v90 * w->widthCoeff;
    p->xMiterNextR = v2->x - (*p_xMiterNextL - v2->x) * w->widthCoeff;
    p->yMiterNextR = v2->y - (p->yMiterNextL - v2->y) * w->widthCoeff;
  }
  else
  {
    v52 = (p->dx1TotalR + p->dx2TotalR) * 0.5;
    v46 = 0.5 * (p->dy1TotalR + p->dy2TotalR);
    v53 = v46 * v46 + v52 * v52;
    v54 = sqrt(v53);
    p->dbTotalR = v54;
    p->dbSolidR = v54 * w->solidCoeffR;
    v55 = v54 * w->widthCoeff;
    p->dbTotalL = v55;
    p->dbSolidL = v55 * w->solidCoeffL;
    v56 = v3->y + p->dy3TotalR;
    dy = v56;
    v57 = v3->x + p->dx3TotalR;
    v41 = v57;
    v58 = v2->y + p->dy3TotalR;
    cy = v58;
    v59 = v2->x + p->dx3TotalR;
    v37 = v59;
    v60 = v2->y + p->dy2TotalR;
    by = v60;
    v61 = v2->x + p->dx2TotalR;
    v33 = v61;
    v62 = v1->y + p->dy2TotalR;
    ay = v62;
    v63 = v1->x + p->dx2TotalR;
    if ( !Scaleform::Render::Math2D::Intersection(
            v63,
            ay,
            v33,
            by,
            v37,
            cy,
            v41,
            dy,
            &p->xMiterNextR,
            &p->yMiterNextR,
            epsilon) )
      goto LABEL_7;
    v64 = p->xMiterNextR - v2->x;
    v85 = p->yMiterNextR - v2->y;
    v86 = v85 * v85 + v64 * v64;
    v87 = sqrt(v86);
    p->dMiterNextR = v87;
    p->dMiterNextL = v87 * w->widthCoeff;
    *p_xMiterNextL = v2->x - (p->xMiterNextR - v2->x) * w->widthCoeff;
    p->yMiterNextL = v2->y - (p->yMiterNextR - v2->y) * w->widthCoeff;
  }
  v84 = 0;
  p->badMiterNextL = 0;
  p->badMiterNextR = 0;
LABEL_7:
  rightTurnNext = p->rightTurnNext;
  p->rightTurnPrev = p->rightTurnThis;
  p->rightTurnThis = rightTurnNext;
  v17 = v1;
  v78 = (v3->x - v2->x) * (v2->y - v1->y) - (v3->y - v2->y) * (v2->x - v1->x);
  v50 = v78 > 0.0;
  p->rightTurnNext = v50;
  if ( v84 )
  {
    rightSideCalc = w->rightSideCalc;
    x = v2->x;
    if ( rightSideCalc )
      v20 = x + p->dx2TotalR;
    else
      v20 = x - p->dx2TotalL;
    v79 = v20;
    y = v2->y;
    if ( rightSideCalc )
      v22 = y + p->dy2TotalR;
    else
      v22 = y - p->dy2TotalL;
    v48 = v22;
    v91 = (v79 - v2->x) * (v2->y - v1->y) - (v48 - v2->y) * (v2->x - v1->x);
    v23 = v91 < 0.0;
    v92 = (v79 - v3->x) * (v3->y - v2->y) - (v3->x - v2->x) * (v48 - v3->y);
    if ( v23 == v92 < 0.0 )
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
      v80 = v2->x - (v1->x + v3->x) * 0.5;
      v49 = v2->y - 0.5 * (v1->y + v3->y);
      v25 = v2->x;
      if ( v50 )
      {
        p->xMiterNextR = v25 + p->dx2TotalR;
        p->yMiterNextR = v2->y + p->dy2TotalR;
        v26 = w->totalLimitR;
        p->badMiterNextR = 1;
        p->dMiterNextR = v26;
        *p_xMiterNextL = v80 * 1024.0 + v2->x;
        v81 = 1024.0 * v49 + v2->y;
        p->yMiterNextL = v81;
        v27 = Scaleform::Render::Math2D::Distance(v2->x, v2->y, *p_xMiterNextL, v81);
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
        p->xMiterNextR = v80 * 1024.0 + v2->x;
        v82 = 1024.0 * v49 + v2->y;
        p->yMiterNextR = v82;
        v29 = Scaleform::Render::Math2D::Distance(v2->x, v2->y, p->xMiterNextR, v82);
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
