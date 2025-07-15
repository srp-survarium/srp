void __thiscall Scaleform::Render::StrokerAA::calcMiterJoin(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        const Scaleform::Render::StrokerAA::JoinParamType *p,
        Scaleform::Render::StrokerTypes::LineJoinType lineJoin)
{
  const Scaleform::Render::StrokerAA::JoinParamType *v6; // edi
  const Scaleform::Render::StrokerAA::WidthsType *v8; // ebp
  double xMiterThisR; // st7
  double yMiterThisR; // st7
  double xMiterThisL; // st7
  double yMiterThisL; // st7
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v16; // eax
  unsigned int v17; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v18; // eax
  Scaleform::Render::StrokerAA::TriangleType *v19; // eax
  float y; // [esp+4h] [ebp-48h]
  float ya; // [esp+4h] [ebp-48h]
  float yb; // [esp+4h] [ebp-48h]
  float yc; // [esp+4h] [ebp-48h]
  bool overlap; // [esp+23h] [ebp-29h]
  float yTotalL; // [esp+24h] [ebp-28h]
  float xTotalL; // [esp+28h] [ebp-24h]
  unsigned int xTotalLa; // [esp+28h] [ebp-24h]
  float yTotalR; // [esp+2Ch] [ebp-20h]
  float newTotalR; // [esp+30h] [ebp-1Ch]
  unsigned int newTotalRa; // [esp+30h] [ebp-1Ch]
  float xSolidL; // [esp+34h] [ebp-18h]
  float ySolidR; // [esp+38h] [ebp-14h]
  float xSolidR; // [esp+3Ch] [ebp-10h]
  unsigned int SolidL; // [esp+40h] [ebp-Ch]
  unsigned int v35; // [esp+40h] [ebp-Ch]
  unsigned int SolidR; // [esp+44h] [ebp-8h]
  float newSolidR; // [esp+50h] [ebp+4h]
  unsigned int newSolidRa; // [esp+50h] [ebp+4h]
  float wa; // [esp+54h] [ebp+8h]
  float wb; // [esp+54h] [ebp+8h]
  float wc; // [esp+54h] [ebp+8h]
  float wd; // [esp+54h] [ebp+8h]
  float we; // [esp+54h] [ebp+8h]
  float wf; // [esp+54h] [ebp+8h]
  float wg; // [esp+54h] [ebp+8h]
  float wh; // [esp+54h] [ebp+8h]
  unsigned int newSolidL; // [esp+5Ch] [ebp+10h]

  v6 = p;
  overlap = p->overlapPrev || p->overlapThis;
  if ( p->rightTurnThis )
  {
    v8 = w;
    xTotalL = p->xMiterThisL;
    yTotalL = p->yMiterThisL;
    xSolidL = (xTotalL - v1->x) * w->solidCoeffL + v1->x;
    newSolidR = (yTotalL - v1->y) * w->solidCoeffL + v1->y;
    if ( w->totalLimitL < (double)p->dMiterThisL && (unsigned int)lineJoin <= MiterBevelJoin )
    {
      Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, lineJoin);
      return;
    }
    if ( *(_WORD *)&p->overlapPrev )
      xMiterThisR = p->dx1TotalR + v1->x;
    else
      xMiterThisR = p->xMiterThisR;
    newTotalR = xMiterThisR;
    if ( *(_WORD *)&p->overlapPrev )
      yMiterThisR = p->dy1TotalR + v1->y;
    else
      yMiterThisR = p->yMiterThisR;
    yTotalR = yMiterThisR;
    xSolidR = (newTotalR - v1->x) * w->solidCoeffR + v1->x;
    ySolidR = (yTotalR - v1->y) * w->solidCoeffR + v1->y;
  }
  else
  {
    newTotalR = p->xMiterThisR;
    yTotalR = p->yMiterThisR;
    xSolidR = (newTotalR - v1->x) * w->solidCoeffR + v1->x;
    ySolidR = (yTotalR - v1->y) * w->solidCoeffR + v1->y;
    if ( w->totalLimitR < (double)p->dMiterThisR && (unsigned int)lineJoin <= MiterBevelJoin )
    {
      Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, lineJoin);
      return;
    }
    if ( *(_WORD *)&p->overlapPrev )
      xMiterThisL = v1->x - p->dx1TotalL;
    else
      xMiterThisL = p->xMiterThisL;
    xTotalL = xMiterThisL;
    if ( *(_WORD *)&p->overlapPrev )
      yMiterThisL = v1->y - p->dy1TotalL;
    else
      yMiterThisL = p->yMiterThisL;
    yTotalL = yMiterThisL;
    v8 = w;
    xSolidL = (xTotalL - v1->x) * w->solidCoeffL + v1->x;
    newSolidR = (yTotalL - v1->y) * w->solidCoeffL + v1->y;
  }
  v13 = Scaleform::Render::StrokerAA::addVertex(this, xSolidL, newSolidR, this->StyleLeft, 1);
  newSolidL = v13;
  if ( v8->aaFlagL )
    v13 = Scaleform::Render::StrokerAA::addVertex(this, xTotalL, yTotalL, this->StyleLeft, 0);
  xTotalLa = v13;
  if ( v8->solidFlag )
    v14 = Scaleform::Render::StrokerAA::addVertex(this, xSolidR, ySolidR, this->StyleRight, 1);
  else
    v14 = newSolidL;
  newSolidRa = v14;
  if ( v8->aaFlagR )
    newTotalRa = Scaleform::Render::StrokerAA::addVertex(this, newTotalR, yTotalR, this->StyleRight, 0);
  else
    newTotalRa = v14;
  if ( v8->solidFlagL || v8->solidFlagR )
  {
    v15 = this->Triangles.Size >> 4;
    SolidL = this->SolidL;
    if ( v15 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        v15);
    v16 = &this->Triangles.Pages[v15][this->Triangles.Size & 0xF];
    v16->v1 = SolidL;
    v16->v2 = newSolidRa;
    v16->v3 = newSolidL;
    v17 = ++this->Triangles.Size >> 4;
    v35 = this->SolidL;
    SolidR = this->SolidR;
    if ( v17 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        v17);
    v18 = this->Triangles.Pages[v17];
    v8 = w;
    v19 = &v18[this->Triangles.Size & 0xF];
    v19->v1 = v35;
    v19->v2 = SolidR;
    v19->v3 = newSolidRa;
    ++this->Triangles.Size;
    v6 = p;
  }
  if ( v8->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, newSolidL);
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, newSolidL, xTotalLa);
  }
  if ( v8->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, newTotalRa, newSolidRa);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, newTotalRa);
  }
  this->SolidL = newSolidL;
  this->TotalL = xTotalLa;
  this->SolidR = newSolidRa;
  this->TotalR = newTotalRa;
  if ( overlap )
  {
    if ( v6->rightTurnThis )
    {
      wa = v6->dy2SolidR + v1->y;
      y = wa;
      wb = v6->dx2SolidR + v1->x;
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(this, wb, y, this->StyleRight, 1);
      if ( v8->aaFlagR )
      {
        wc = v6->dy2TotalR + v1->y;
        ya = wc;
        wd = v6->dx2TotalR + v1->x;
        this->TotalR = Scaleform::Render::StrokerAA::addVertex(this, wd, ya, this->StyleRight, 0);
      }
      else
      {
        this->TotalR = newSolidRa;
      }
    }
    else
    {
      we = v1->y - v6->dy2SolidL;
      yb = we;
      wf = v1->x - v6->dx2SolidL;
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(this, wf, yb, this->StyleLeft, 1);
      if ( v8->aaFlagL )
      {
        wg = v1->y - v6->dy2TotalL;
        yc = wg;
        wh = v1->x - v6->dx2TotalL;
        this->TotalL = Scaleform::Render::StrokerAA::addVertex(this, wh, yc, this->StyleLeft, 0);
      }
      else
      {
        this->TotalL = newSolidL;
      }
    }
  }
}
