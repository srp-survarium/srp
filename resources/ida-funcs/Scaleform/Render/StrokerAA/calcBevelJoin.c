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
  float v28; // [esp+4h] [ebp-3Ch]
  float v29; // [esp+4h] [ebp-3Ch]
  float v30; // [esp+4h] [ebp-3Ch]
  float v31; // [esp+4h] [ebp-3Ch]
  float v32; // [esp+4h] [ebp-3Ch]
  float v33; // [esp+4h] [ebp-3Ch]
  float v34; // [esp+4h] [ebp-3Ch]
  float v35; // [esp+4h] [ebp-3Ch]
  float v36; // [esp+4h] [ebp-3Ch]
  float v37; // [esp+4h] [ebp-3Ch]
  float v38; // [esp+4h] [ebp-3Ch]
  float v39; // [esp+4h] [ebp-3Ch]
  float v40; // [esp+4h] [ebp-3Ch]
  float v41; // [esp+4h] [ebp-3Ch]
  float v42; // [esp+4h] [ebp-3Ch]
  float v43; // [esp+4h] [ebp-3Ch]
  unsigned int StyleLeft; // [esp+8h] [ebp-38h]
  unsigned int StyleRight; // [esp+8h] [ebp-38h]
  unsigned int v2; // [esp+20h] [ebp-20h]
  unsigned int v2a; // [esp+20h] [ebp-20h]
  float v48; // [esp+24h] [ebp-1Ch]
  float v49; // [esp+24h] [ebp-1Ch]
  unsigned int v50; // [esp+24h] [ebp-1Ch]
  float v51; // [esp+24h] [ebp-1Ch]
  float v52; // [esp+24h] [ebp-1Ch]
  float v53; // [esp+24h] [ebp-1Ch]
  float v54; // [esp+24h] [ebp-1Ch]
  unsigned int v55; // [esp+24h] [ebp-1Ch]
  float v56; // [esp+24h] [ebp-1Ch]
  float v57; // [esp+24h] [ebp-1Ch]
  float v58; // [esp+28h] [ebp-18h]
  float v59; // [esp+28h] [ebp-18h]
  float v60; // [esp+28h] [ebp-18h]
  float v61; // [esp+2Ch] [ebp-14h]
  float v62; // [esp+2Ch] [ebp-14h]
  float v63; // [esp+30h] [ebp-10h]
  float v64; // [esp+30h] [ebp-10h]
  float v65; // [esp+34h] [ebp-Ch]
  float v66; // [esp+34h] [ebp-Ch]
  float v67; // [esp+38h] [ebp-8h]
  float v68; // [esp+38h] [ebp-8h]
  float v69; // [esp+3Ch] [ebp-4h]
  float v70; // [esp+3Ch] [ebp-4h]
  float v71; // [esp+44h] [ebp+4h]
  float v72; // [esp+44h] [ebp+4h]
  float v73; // [esp+44h] [ebp+4h]
  float v74; // [esp+44h] [ebp+4h]
  float v75; // [esp+44h] [ebp+4h]
  float v76; // [esp+44h] [ebp+4h]
  float v77; // [esp+44h] [ebp+4h]
  float v78; // [esp+44h] [ebp+4h]
  float v79; // [esp+44h] [ebp+4h]
  float v80; // [esp+44h] [ebp+4h]
  float v81; // [esp+44h] [ebp+4h]
  float v82; // [esp+44h] [ebp+4h]
  unsigned int v83; // [esp+44h] [ebp+4h]
  float v84; // [esp+44h] [ebp+4h]
  float v85; // [esp+44h] [ebp+4h]
  float v86; // [esp+44h] [ebp+4h]
  float v87; // [esp+44h] [ebp+4h]
  float v88; // [esp+44h] [ebp+4h]
  float v89; // [esp+44h] [ebp+4h]
  float v90; // [esp+44h] [ebp+4h]
  float v91; // [esp+44h] [ebp+4h]
  float v92; // [esp+44h] [ebp+4h]
  float v93; // [esp+44h] [ebp+4h]
  float v94; // [esp+44h] [ebp+4h]
  float v95; // [esp+44h] [ebp+4h]
  float v96; // [esp+44h] [ebp+4h]
  float v97; // [esp+44h] [ebp+4h]
  float v98; // [esp+44h] [ebp+4h]
  float v99; // [esp+44h] [ebp+4h]
  float v100; // [esp+44h] [ebp+4h]
  float v101; // [esp+44h] [ebp+4h]
  float v102; // [esp+44h] [ebp+4h]
  unsigned int v103; // [esp+44h] [ebp+4h]
  float v104; // [esp+44h] [ebp+4h]
  float v105; // [esp+44h] [ebp+4h]
  float v106; // [esp+44h] [ebp+4h]
  float v107; // [esp+44h] [ebp+4h]
  float v108; // [esp+44h] [ebp+4h]
  float v109; // [esp+44h] [ebp+4h]
  float v110; // [esp+44h] [ebp+4h]
  float v3b; // [esp+48h] [ebp+8h]
  float v3c; // [esp+48h] [ebp+8h]
  unsigned int v3; // [esp+48h] [ebp+8h]
  float v3d; // [esp+48h] [ebp+8h]
  float v3e; // [esp+48h] [ebp+8h]
  unsigned int v3a; // [esp+48h] [ebp+8h]
  bool v117; // [esp+4Ch] [ebp+Ch]
  float v118; // [esp+50h] [ebp+10h]
  float v119; // [esp+50h] [ebp+10h]
  float v120; // [esp+50h] [ebp+10h]
  float v121; // [esp+50h] [ebp+10h]
  float v122; // [esp+50h] [ebp+10h]
  float v123; // [esp+50h] [ebp+10h]
  float v124; // [esp+50h] [ebp+10h]
  float v125; // [esp+50h] [ebp+10h]
  float v126; // [esp+50h] [ebp+10h]
  float v127; // [esp+50h] [ebp+10h]
  float v128; // [esp+50h] [ebp+10h]
  float v129; // [esp+50h] [ebp+10h]

  v58 = 0.0;
  v7 = p->overlapPrev || p->overlapThis;
  v8 = !p->rightTurnThis;
  v117 = v7;
  if ( v8 )
  {
    if ( v7 )
      xMiterThisL = v1->x - p->dx1TotalL;
    else
      xMiterThisL = p->xMiterThisL;
    v66 = xMiterThisL;
    if ( v7 )
      yMiterThisL = v1->y - p->dy1TotalL;
    else
      yMiterThisL = p->yMiterThisL;
    v64 = yMiterThisL;
    v70 = (v66 - v1->x) * w->solidCoeffL + v1->x;
    v68 = (v64 - v1->y) * w->solidCoeffL + v1->y;
    if ( lineJoin )
    {
      v97 = p->dy1SolidR + v1->y;
      v37 = v97;
      v98 = p->dx1SolidR + v1->x;
      v2a = Scaleform::Render::StrokerAA::addVertex(this, v98, v37, this->StyleRight, 1);
      v99 = p->dMiterThisR - p->dbTotalR;
      if ( 0.0 == v99 )
        v99 = 1.0;
      v62 = (p->dbSolidR + w->totalWidthR - w->solidWidthR - p->dbTotalR) / v99;
    }
    else
    {
      v91 = p->dSolidMiterR - p->dbSolidR;
      v22 = v91;
      if ( v91 == 0.0 )
        v22 = (float)1.0;
      v60 = w->totalLimitR - p->dbSolidR - w->totalWidthR + w->solidWidthR;
      if ( v60 > v22 )
        v60 = v22;
      v92 = w->solidLimitR - p->dbSolidR;
      v58 = (v92 + v60) / (v22 * 2.0);
      v93 = p->dMiterThisR - p->dbTotalR;
      if ( 0.0 == v93 )
        v93 = 1.0;
      v3d = w->solidLimitR - p->dbTotalR + w->totalWidthR - w->solidWidthR;
      v23 = v3d;
      v3e = w->totalLimitR - p->dbTotalR;
      v62 = (v23 + v3e) / (2.0 * v93);
      v53 = p->dx1SolidR + v1->x;
      v94 = p->dy1SolidR + v1->y;
      v95 = v94 + (p->ySolidMiterR - v94) * v58;
      v36 = v95;
      v96 = v58 * (p->xSolidMiterR - v53) + v53;
      v2a = Scaleform::Render::StrokerAA::addVertex(this, v96, v36, this->StyleRight, 1);
    }
    v24 = v62;
    if ( w->aaFlagR )
    {
      v54 = p->dx1TotalR + v1->x;
      v100 = p->dy1TotalR + v1->y;
      v101 = (p->yMiterThisR - v100) * v24 + v100;
      v38 = v101;
      v102 = v24 * (p->xMiterThisR - v54) + v54;
      v25 = Scaleform::Render::StrokerAA::addVertex(this, v102, v38, this->StyleRight, 0);
    }
    else
    {
      v25 = v2a;
    }
    v55 = v25;
    if ( w->solidFlag )
      v3a = Scaleform::Render::StrokerAA::addVertex(this, v70, v68, this->StyleLeft, 1);
    else
      v3a = v2a;
    if ( w->aaFlagL )
      v103 = Scaleform::Render::StrokerAA::addVertex(this, v66, v64, this->StyleLeft, 0);
    else
      v103 = v3a;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v2a, v3a);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v3a, this->SolidL);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v2a, this->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v55, v2a);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v3a, v103);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v103, this->TotalL);
    }
    this->SolidL = v3a;
    this->TotalL = v103;
    this->SolidR = v2a;
    this->TotalR = v55;
    if ( v117 )
    {
      v104 = v1->y - p->dy2SolidL;
      v39 = v104;
      v105 = v1->x - p->dx2SolidL;
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(this, v105, v39, this->StyleLeft, 1);
      if ( w->aaFlagL )
      {
        v106 = v1->y - p->dy2TotalL;
        v40 = v106;
        v107 = v1->x - p->dx2TotalL;
        v26 = Scaleform::Render::StrokerAA::addVertex(this, v107, v40, this->StyleLeft, 0);
      }
      else
      {
        v26 = v3a;
      }
      this->TotalL = v26;
    }
    v108 = this->Tolerance * 0.25 * 0.25;
    if ( v108 < w->totalWidthR - p->dbTotalR )
    {
      if ( w->solidFlag )
      {
        StyleRight = this->StyleRight;
        if ( lineJoin )
        {
          v126 = p->dy2SolidR + v1->y;
          v42 = v126;
          v127 = p->dx2SolidR + v1->x;
          v2a = Scaleform::Render::StrokerAA::addVertex(this, v127, v42, StyleRight, 1);
        }
        else
        {
          v56 = p->dx2SolidR + v1->x;
          v109 = p->dy2SolidR + v1->y;
          v124 = v109 + (p->ySolidMiterR - v109) * v58;
          v41 = v124;
          v125 = v58 * (p->xSolidMiterR - v56) + v56;
          v2a = Scaleform::Render::StrokerAA::addVertex(this, v125, v41, StyleRight, 1);
        }
      }
      if ( w->aaFlagR )
      {
        v57 = p->dx2TotalR + v1->x;
        v110 = p->dy2TotalR + v1->y;
        v128 = v110 + (p->yMiterThisR - v110) * v62;
        v43 = v128;
        v129 = v62 * (p->xMiterThisR - v57) + v57;
        v27 = Scaleform::Render::StrokerAA::addVertex(this, v129, v43, this->StyleRight, 0);
      }
      else
      {
        v27 = v2a;
      }
      if ( w->solidFlagR )
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v2a);
      if ( w->aaFlagR )
      {
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v2a);
        Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v27, v2a);
      }
      this->SolidR = v2a;
      this->TotalR = v27;
    }
  }
  else
  {
    if ( v7 )
      xMiterThisR = p->dx1TotalR + v1->x;
    else
      xMiterThisR = p->xMiterThisR;
    v65 = xMiterThisR;
    if ( v7 )
      yMiterThisR = p->dy1TotalR + v1->y;
    else
      yMiterThisR = p->yMiterThisR;
    v63 = yMiterThisR;
    v69 = (v65 - v1->x) * w->solidCoeffR + v1->x;
    v67 = (v63 - v1->y) * w->solidCoeffR + v1->y;
    if ( lineJoin )
    {
      v77 = v1->y - p->dy1SolidL;
      v29 = v77;
      v78 = v1->x - p->dx1SolidL;
      v3 = Scaleform::Render::StrokerAA::addVertex(this, v78, v29, this->StyleLeft, 1);
      v79 = p->dMiterThisL - p->dbTotalL;
      if ( 0.0 == v79 )
        v79 = 1.0;
      v61 = (p->dbSolidL + w->totalWidthL - w->solidWidthL - p->dbTotalL) / v79;
    }
    else
    {
      v71 = p->dSolidMiterL - p->dbSolidL;
      v13 = v71;
      if ( v71 == 0.0 )
        v13 = (float)1.0;
      v59 = w->totalLimitL - p->dbSolidL - w->totalWidthL + w->solidWidthL;
      if ( v59 > v13 )
        v59 = v13;
      v72 = w->solidLimitL - p->dbSolidL;
      v58 = (v72 + v59) / (v13 * 2.0);
      v73 = p->dMiterThisL - p->dbTotalL;
      if ( 0.0 == v73 )
        v73 = 1.0;
      v3b = w->solidLimitL - p->dbTotalL + w->totalWidthL - w->solidWidthL;
      v14 = v3b;
      v3c = w->totalLimitL - p->dbTotalL;
      v61 = (v14 + v3c) / (2.0 * v73);
      v48 = v1->x - p->dx1SolidL;
      v74 = v1->y - p->dy1SolidL;
      v75 = v74 + (p->ySolidMiterL - v74) * v58;
      v28 = v75;
      v76 = v58 * (p->xSolidMiterL - v48) + v48;
      v3 = Scaleform::Render::StrokerAA::addVertex(this, v76, v28, this->StyleLeft, 1);
    }
    v15 = v61;
    if ( w->aaFlagL )
    {
      v49 = v1->x - p->dx1TotalL;
      v80 = v1->y - p->dy1TotalL;
      v81 = (p->yMiterThisL - v80) * v15 + v80;
      v30 = v81;
      v82 = v15 * (p->xMiterThisL - v49) + v49;
      v16 = Scaleform::Render::StrokerAA::addVertex(this, v82, v30, this->StyleLeft, 0);
    }
    else
    {
      v16 = v3;
    }
    v83 = v16;
    if ( w->solidFlag )
      v2 = Scaleform::Render::StrokerAA::addVertex(this, v69, v67, this->StyleRight, 1);
    else
      v2 = v3;
    if ( w->aaFlagR )
      v50 = Scaleform::Render::StrokerAA::addVertex(this, v65, v63, this->StyleRight, 0);
    else
      v50 = v2;
    if ( w->solidFlagL || w->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v2, v3);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v2);
    }
    if ( w->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v3);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v3, v83);
    }
    if ( w->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v50, v2);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v50);
    }
    this->SolidL = v3;
    this->TotalL = v83;
    this->SolidR = v2;
    this->TotalR = v50;
    if ( v117 )
    {
      v84 = p->dy2SolidR + v1->y;
      v31 = v84;
      v85 = p->dx2SolidR + v1->x;
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(this, v85, v31, this->StyleRight, 1);
      if ( w->aaFlagR )
      {
        v86 = p->dy2TotalR + v1->y;
        v32 = v86;
        v87 = p->dx2TotalR + v1->x;
        v17 = Scaleform::Render::StrokerAA::addVertex(this, v87, v32, this->StyleRight, 0);
      }
      else
      {
        v17 = v2;
      }
      this->TotalR = v17;
    }
    v88 = this->Tolerance * 0.25 * 0.25;
    if ( v88 < w->totalWidthL - p->dbTotalL )
    {
      if ( w->solidFlag )
      {
        StyleLeft = this->StyleLeft;
        if ( lineJoin )
        {
          v120 = v1->y - p->dy2SolidL;
          v34 = v120;
          v121 = v1->x - p->dx2SolidL;
          v3 = Scaleform::Render::StrokerAA::addVertex(this, v121, v34, StyleLeft, 1);
        }
        else
        {
          v51 = v1->x - p->dx2SolidL;
          v89 = v1->y - p->dy2SolidL;
          v118 = v89 + (p->ySolidMiterL - v89) * v58;
          v33 = v118;
          v119 = v58 * (p->xSolidMiterL - v51) + v51;
          v3 = Scaleform::Render::StrokerAA::addVertex(this, v119, v33, StyleLeft, 1);
        }
      }
      if ( w->aaFlagL )
      {
        v52 = v1->x - p->dx2TotalL;
        v90 = v1->y - p->dy2TotalL;
        v122 = v90 + (p->yMiterThisL - v90) * v61;
        v35 = v122;
        v123 = v61 * (p->xMiterThisL - v52) + v52;
        v18 = Scaleform::Render::StrokerAA::addVertex(this, v123, v35, this->StyleLeft, 0);
      }
      else
      {
        v18 = v3;
      }
      if ( w->solidFlagL )
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v3, this->SolidL);
      if ( w->aaFlagL )
      {
        Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v3, this->TotalL);
        Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v3, v18);
      }
      this->TotalL = v18;
      this->SolidL = v3;
    }
  }
}
