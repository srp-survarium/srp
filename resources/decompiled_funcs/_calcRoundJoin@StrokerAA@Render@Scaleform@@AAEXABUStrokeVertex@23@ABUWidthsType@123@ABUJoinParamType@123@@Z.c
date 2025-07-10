void __thiscall Scaleform::Render::StrokerAA::calcRoundJoin(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        const Scaleform::Render::StrokerAA::JoinParamType *p)
{
  bool v6; // cl
  bool v7; // zf
  const Scaleform::Render::StrokeVertex *v8; // ebx
  double xMiterThisR; // st7
  double yMiterThisR; // st7
  unsigned int v11; // eax
  unsigned int v12; // ebp
  const Scaleform::Render::StrokerAA::WidthsType *v13; // eax
  unsigned int v14; // eax
  double v15; // st6
  const Scaleform::Render::StrokerAA::WidthsType *v16; // edi
  double v17; // st6
  unsigned int v18; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v19; // eax
  Scaleform::Render::StrokerAA::TriangleType *v20; // eax
  unsigned int v21; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v22; // eax
  unsigned int v23; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v24; // eax
  Scaleform::Render::StrokerAA::TriangleType *v25; // eax
  const Scaleform::Render::StrokeVertex *v26; // ebx
  double xMiterThisL; // st7
  double yMiterThisL; // st7
  unsigned int v29; // ebp
  const Scaleform::Render::StrokerAA::WidthsType *v30; // eax
  unsigned int v31; // eax
  double v32; // st6
  const Scaleform::Render::StrokerAA::WidthsType *v33; // edi
  double v34; // st6
  unsigned int v35; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v36; // eax
  Scaleform::Render::StrokerAA::TriangleType *v37; // eax
  unsigned int v38; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v39; // eax
  unsigned int v40; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v41; // eax
  Scaleform::Render::StrokerAA::TriangleType *v42; // eax
  float y; // [esp+4h] [ebp-5Ch]
  float ya; // [esp+4h] [ebp-5Ch]
  float yb; // [esp+4h] [ebp-5Ch]
  float yc; // [esp+4h] [ebp-5Ch]
  float yd; // [esp+4h] [ebp-5Ch]
  float ye; // [esp+4h] [ebp-5Ch]
  float yf; // [esp+4h] [ebp-5Ch]
  float yg; // [esp+4h] [ebp-5Ch]
  float yh; // [esp+4h] [ebp-5Ch]
  float yi; // [esp+4h] [ebp-5Ch]
  float yj; // [esp+4h] [ebp-5Ch]
  float yk; // [esp+4h] [ebp-5Ch]
  unsigned int newTotalL; // [esp+20h] [ebp-40h]
  unsigned int newTotalLa; // [esp+20h] [ebp-40h]
  unsigned int newTotalLb; // [esp+20h] [ebp-40h]
  float newTotalRc; // [esp+24h] [ebp-3Ch]
  float newTotalRd; // [esp+24h] [ebp-3Ch]
  float newTotalRe; // [esp+24h] [ebp-3Ch]
  float newTotalRf; // [esp+24h] [ebp-3Ch]
  unsigned int newTotalR; // [esp+24h] [ebp-3Ch]
  float newTotalRg; // [esp+24h] [ebp-3Ch]
  float newTotalRh; // [esp+24h] [ebp-3Ch]
  float newTotalRi; // [esp+24h] [ebp-3Ch]
  float newTotalRj; // [esp+24h] [ebp-3Ch]
  float newTotalRk; // [esp+24h] [ebp-3Ch]
  float newTotalRl; // [esp+24h] [ebp-3Ch]
  unsigned int newTotalRa; // [esp+24h] [ebp-3Ch]
  float newTotalRm; // [esp+24h] [ebp-3Ch]
  float newTotalRn; // [esp+24h] [ebp-3Ch]
  unsigned int newTotalRb; // [esp+24h] [ebp-3Ch]
  float newSolidL; // [esp+28h] [ebp-38h]
  unsigned int newSolidLa; // [esp+28h] [ebp-38h]
  float newSolidLf; // [esp+28h] [ebp-38h]
  float newSolidLb; // [esp+28h] [ebp-38h]
  float newSolidLc; // [esp+28h] [ebp-38h]
  unsigned int newSolidLd; // [esp+28h] [ebp-38h]
  float newSolidLg; // [esp+28h] [ebp-38h]
  float newSolidLe; // [esp+28h] [ebp-38h]
  float yTotal; // [esp+2Ch] [ebp-34h]
  float yTotala; // [esp+2Ch] [ebp-34h]
  float yTotalb; // [esp+2Ch] [ebp-34h]
  float yTotalc; // [esp+2Ch] [ebp-34h]
  float dy; // [esp+30h] [ebp-30h]
  double dyd; // [esp+30h] [ebp-30h]
  float dye; // [esp+30h] [ebp-30h]
  float dya; // [esp+30h] [ebp-30h]
  float dyf; // [esp+30h] [ebp-30h]
  float dyg; // [esp+30h] [ebp-30h]
  float dyb; // [esp+30h] [ebp-30h]
  double dyh; // [esp+30h] [ebp-30h]
  float dyi; // [esp+30h] [ebp-30h]
  float dyc; // [esp+30h] [ebp-30h]
  float dyj; // [esp+30h] [ebp-30h]
  float dyk; // [esp+30h] [ebp-30h]
  float nd; // [esp+38h] [ebp-28h]
  int n; // [esp+38h] [ebp-28h]
  float ne; // [esp+38h] [ebp-28h]
  float nf; // [esp+38h] [ebp-28h]
  float ng; // [esp+38h] [ebp-28h]
  float nh; // [esp+38h] [ebp-28h]
  int ni; // [esp+38h] [ebp-28h]
  int na; // [esp+38h] [ebp-28h]
  float nj; // [esp+38h] [ebp-28h]
  int nb; // [esp+38h] [ebp-28h]
  float nk; // [esp+38h] [ebp-28h]
  float nl; // [esp+38h] [ebp-28h]
  float nm; // [esp+38h] [ebp-28h]
  float nn; // [esp+38h] [ebp-28h]
  int no; // [esp+38h] [ebp-28h]
  int nc; // [esp+38h] [ebp-28h]
  unsigned int v113; // [esp+3Ch] [ebp-24h]
  unsigned int v114; // [esp+3Ch] [ebp-24h]
  unsigned int TotalR; // [esp+40h] [ebp-20h]
  unsigned int v116; // [esp+44h] [ebp-1Ch]
  unsigned int v117; // [esp+48h] [ebp-18h]
  unsigned int SolidL; // [esp+48h] [ebp-18h]
  unsigned int SolidR; // [esp+4Ch] [ebp-14h]
  unsigned int TotalL; // [esp+50h] [ebp-10h]
  unsigned int v121; // [esp+54h] [ebp-Ch]
  unsigned int v122; // [esp+54h] [ebp-Ch]
  bool a1; // [esp+6Ch] [ebp+Ch]
  float a1e; // [esp+6Ch] [ebp+Ch]
  float a1f; // [esp+6Ch] [ebp+Ch]
  float a1g; // [esp+6Ch] [ebp+Ch]
  float a1h; // [esp+6Ch] [ebp+Ch]
  float a1a; // [esp+6Ch] [ebp+Ch]
  float a1b; // [esp+6Ch] [ebp+Ch]
  float a1i; // [esp+6Ch] [ebp+Ch]
  float a1j; // [esp+6Ch] [ebp+Ch]
  float a1k; // [esp+6Ch] [ebp+Ch]
  float a1l; // [esp+6Ch] [ebp+Ch]
  float a1c; // [esp+6Ch] [ebp+Ch]
  float a1d; // [esp+6Ch] [ebp+Ch]

  v6 = p->overlapPrev || p->overlapThis;
  v7 = !p->rightTurnThis;
  a1 = v6;
  if ( v7 )
  {
    nj = this->Tolerance * 0.125;
    if ( nj > w->solidWidthL + w->solidWidthL - p->dbTotalL )
      goto LABEL_3;
    v26 = v1;
    if ( v6 )
      xMiterThisL = v1->x - p->dx1TotalL;
    else
      xMiterThisL = p->xMiterThisL;
    dyb = xMiterThisL;
    if ( v6 )
      yMiterThisL = v1->y - p->dy1TotalL;
    else
      yMiterThisL = p->yMiterThisL;
    yTotalb = yMiterThisL;
    *(float *)&nb = (dyb - v1->x) * w->solidCoeffL + v1->x;
    newSolidLc = (yTotalb - v1->y) * w->solidCoeffL + v1->y;
    newTotalRi = p->dy1SolidR + v1->y;
    yf = newTotalRi;
    newTotalRj = p->dx1SolidR + v1->x;
    v29 = Scaleform::Render::StrokerAA::addVertex(this, newTotalRj, yf, this->StyleRight, 1);
    if ( w->aaFlagR )
    {
      newTotalRk = p->dy1TotalR + v1->y;
      yg = newTotalRk;
      newTotalRl = p->dx1TotalR + v1->x;
      newTotalRa = Scaleform::Render::StrokerAA::addVertex(this, newTotalRl, yg, this->StyleRight, 0);
    }
    else
    {
      newTotalRa = v29;
    }
    v30 = w;
    if ( w->solidFlag )
    {
      newSolidLd = Scaleform::Render::StrokerAA::addVertex(this, *(float *)&nb, newSolidLc, this->StyleLeft, 1);
      v30 = w;
    }
    else
    {
      newSolidLd = v29;
    }
    if ( v30->aaFlagL )
    {
      newTotalLb = Scaleform::Render::StrokerAA::addVertex(this, dyb, yTotalb, this->StyleLeft, 0);
      v30 = w;
    }
    else
    {
      newTotalLb = newSolidLd;
    }
    if ( v30->solidFlagL || v30->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v29, newSolidLd);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newSolidLd, this->SolidL);
      v30 = w;
    }
    if ( v30->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v29, this->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, newTotalRa, v29);
      v30 = w;
    }
    if ( v30->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, newSolidLd, newTotalLb);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, newTotalLb, this->TotalL);
    }
    this->SolidL = newSolidLd;
    this->TotalL = newTotalLb;
    this->SolidR = v29;
    this->TotalR = newTotalRa;
    if ( a1 )
    {
      a1i = v1->y - p->dy2SolidL;
      yh = a1i;
      a1j = v1->x - p->dx2SolidL;
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(this, a1j, yh, this->StyleLeft, 1);
      if ( w->aaFlagL )
      {
        a1k = v1->y - p->dy2TotalL;
        yi = a1k;
        a1l = v1->x - p->dx2TotalL;
        v31 = Scaleform::Render::StrokerAA::addVertex(this, a1l, yi, this->StyleLeft, 0);
      }
      else
      {
        v31 = newSolidLd;
      }
      this->TotalL = v31;
    }
    a1c = atan2(p->dy1TotalR, p->dx1TotalR);
    nk = atan2(p->dy2TotalR, p->dx2TotalR);
    v32 = nk;
    if ( nk < (double)a1c )
    {
      newSolidLg = v32 + 6.283185482025146;
      v32 = newSolidLg;
    }
    v33 = w;
    dyh = v32 - a1c;
    nl = w->totalWidthR / (this->Tolerance * 0.25 + w->totalWidthR);
    nm = acos(nl);
    nn = nm + nm;
    v34 = dyh / nn;
    no = (int)v34 + 1;
    newSolidLe = dyh / (double)no;
    a1d = newSolidLe + a1c;
    if ( no > 0 )
    {
      nc = (int)v34 + 1;
      do
      {
        dyi = cos(a1d);
        yTotalc = dyi;
        dyc = sin(a1d);
        if ( v33->solidFlag )
        {
          newTotalRm = v33->solidWidthR * dyc + v26->y;
          yj = newTotalRm;
          newTotalRn = v33->solidWidthR * yTotalc + v26->x;
          v29 = Scaleform::Render::StrokerAA::addVertex(this, newTotalRn, yj, this->StyleRight, 1);
        }
        if ( v33->aaFlagR )
        {
          dyj = dyc * v33->totalWidthR + v26->y;
          yk = dyj;
          dyk = yTotalc * v33->totalWidthR + v26->x;
          newTotalRb = Scaleform::Render::StrokerAA::addVertex(this, dyk, yk, this->StyleRight, 0);
        }
        else
        {
          newTotalRb = v29;
        }
        if ( v33->solidFlagR )
        {
          v35 = this->Triangles.Size >> 4;
          SolidL = this->SolidL;
          SolidR = this->SolidR;
          if ( v35 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v35);
          v36 = this->Triangles.Pages[v35];
          v26 = v1;
          v37 = &v36[this->Triangles.Size & 0xF];
          v37->v1 = SolidL;
          v37->v2 = SolidR;
          v37->v3 = v29;
          ++this->Triangles.Size;
          v33 = w;
        }
        if ( v33->aaFlagR )
        {
          v38 = this->Triangles.Size >> 4;
          v114 = this->SolidR;
          TotalR = this->TotalR;
          if ( v38 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v38);
          v39 = &this->Triangles.Pages[v38][this->Triangles.Size & 0xF];
          v39->v1 = v114;
          v39->v2 = TotalR;
          v39->v3 = v29;
          v40 = ++this->Triangles.Size >> 4;
          v122 = this->TotalR;
          if ( v40 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v40);
          v41 = this->Triangles.Pages[v40];
          v26 = v1;
          v42 = &v41[this->Triangles.Size & 0xF];
          v42->v1 = v122;
          v42->v2 = newTotalRb;
          v42->v3 = v29;
          ++this->Triangles.Size;
          v33 = w;
        }
        v7 = nc-- == 1;
        this->SolidR = v29;
        this->TotalR = newTotalRb;
        a1d = newSolidLe + a1d;
      }
      while ( !v7 );
    }
  }
  else
  {
    nd = this->Tolerance * 0.125;
    if ( nd > w->solidWidthR + w->solidWidthR - p->dbTotalR )
    {
LABEL_3:
      Scaleform::Render::StrokerAA::calcMiterJoin(this, v1, w, p, MiterJoin);
      return;
    }
    v8 = v1;
    if ( v6 )
      xMiterThisR = p->dx1TotalR + v1->x;
    else
      xMiterThisR = p->xMiterThisR;
    dy = xMiterThisR;
    if ( v6 )
      yMiterThisR = p->dy1TotalR + v1->y;
    else
      yMiterThisR = p->yMiterThisR;
    yTotal = yMiterThisR;
    *(float *)&n = (dy - v1->x) * w->solidCoeffR + v1->x;
    newSolidL = (yTotal - v1->y) * w->solidCoeffR + v1->y;
    newTotalRc = v1->y - p->dy1SolidL;
    y = newTotalRc;
    newTotalRd = v1->x - p->dx1SolidL;
    v11 = Scaleform::Render::StrokerAA::addVertex(this, newTotalRd, y, this->StyleLeft, 1);
    v12 = v11;
    if ( w->aaFlagL )
    {
      newTotalRe = v1->y - p->dy1TotalL;
      ya = newTotalRe;
      newTotalRf = v1->x - p->dx1TotalL;
      newTotalL = Scaleform::Render::StrokerAA::addVertex(this, newTotalRf, ya, this->StyleLeft, 0);
    }
    else
    {
      newTotalL = v11;
    }
    v13 = w;
    if ( w->solidFlag )
    {
      newSolidLa = Scaleform::Render::StrokerAA::addVertex(this, *(float *)&n, newSolidL, this->StyleRight, 1);
      v13 = w;
    }
    else
    {
      newSolidLa = v12;
    }
    if ( v13->aaFlagR )
    {
      newTotalR = Scaleform::Render::StrokerAA::addVertex(this, dy, yTotal, this->StyleRight, 0);
      v13 = w;
    }
    else
    {
      newTotalR = newSolidLa;
    }
    if ( v13->solidFlagL || v13->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, newSolidLa, v12);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, newSolidLa);
      v13 = w;
    }
    if ( v13->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v12);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v12, newTotalL);
      v13 = w;
    }
    if ( v13->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newTotalR, newSolidLa);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, newTotalR);
    }
    this->SolidL = v12;
    this->TotalL = newTotalL;
    this->SolidR = newSolidLa;
    this->TotalR = newTotalR;
    if ( a1 )
    {
      a1e = p->dy2SolidR + v1->y;
      yb = a1e;
      a1f = p->dx2SolidR + v1->x;
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(this, a1f, yb, this->StyleRight, 1);
      if ( w->aaFlagR )
      {
        a1g = p->dy2TotalR + v1->y;
        yc = a1g;
        a1h = p->dx2TotalR + v1->x;
        v14 = Scaleform::Render::StrokerAA::addVertex(this, a1h, yc, this->StyleRight, 0);
      }
      else
      {
        v14 = newSolidLa;
      }
      this->TotalR = v14;
    }
    a1a = atan2(-p->dy1TotalL, -p->dx1TotalL);
    ne = atan2(-p->dy2TotalL, -p->dx2TotalL);
    v15 = ne;
    if ( ne > (double)a1a )
    {
      newSolidLf = v15 - 6.283185482025146;
      v15 = newSolidLf;
    }
    v16 = w;
    dyd = a1a - v15;
    nf = w->totalWidthL / (this->Tolerance * 0.25 + w->totalWidthL);
    ng = acos(nf);
    nh = ng + ng;
    v17 = dyd / nh;
    ni = (int)v17 + 1;
    newSolidLb = dyd / (double)ni;
    a1b = a1a - newSolidLb;
    if ( ni > 0 )
    {
      na = (int)v17 + 1;
      do
      {
        dye = cos(a1b);
        yTotala = dye;
        dya = sin(a1b);
        if ( v16->solidFlag )
        {
          newTotalRg = v16->solidWidthL * dya + v8->y;
          yd = newTotalRg;
          newTotalRh = v16->solidWidthL * yTotala + v8->x;
          v12 = Scaleform::Render::StrokerAA::addVertex(this, newTotalRh, yd, this->StyleLeft, 1);
        }
        if ( v16->aaFlagL )
        {
          dyf = v16->totalWidthL * dya + v8->y;
          ye = dyf;
          dyg = v16->totalWidthL * yTotala + v8->x;
          newTotalLa = Scaleform::Render::StrokerAA::addVertex(this, dyg, ye, this->StyleLeft, 0);
        }
        else
        {
          newTotalLa = v12;
        }
        if ( v16->solidFlagL )
        {
          v18 = this->Triangles.Size >> 4;
          v113 = this->SolidR;
          v116 = this->SolidL;
          if ( v18 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v18);
          v19 = this->Triangles.Pages[v18];
          v8 = v1;
          v20 = &v19[this->Triangles.Size & 0xF];
          v20->v1 = v113;
          v20->v2 = v12;
          v20->v3 = v116;
          ++this->Triangles.Size;
          v16 = w;
        }
        if ( v16->aaFlagL )
        {
          v21 = this->Triangles.Size >> 4;
          v117 = this->SolidL;
          TotalL = this->TotalL;
          if ( v21 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v21);
          v22 = &this->Triangles.Pages[v21][this->Triangles.Size & 0xF];
          v22->v1 = v117;
          v22->v2 = v12;
          v22->v3 = TotalL;
          v23 = ++this->Triangles.Size >> 4;
          v121 = this->TotalL;
          if ( v23 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v23);
          v24 = this->Triangles.Pages[v23];
          v8 = v1;
          v25 = &v24[this->Triangles.Size & 0xF];
          v25->v1 = v121;
          v25->v2 = v12;
          v25->v3 = newTotalLa;
          ++this->Triangles.Size;
          v16 = w;
        }
        v7 = na-- == 1;
        this->SolidL = v12;
        this->TotalL = newTotalLa;
        a1b = a1b - newSolidLb;
      }
      while ( !v7 );
    }
  }
}
