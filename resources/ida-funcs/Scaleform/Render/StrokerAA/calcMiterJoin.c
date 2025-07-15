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
  double v12; // st7
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v16; // eax
  unsigned int v17; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v18; // eax
  Scaleform::Render::StrokerAA::TriangleType *v19; // eax
  float v20; // [esp+4h] [ebp-48h]
  float v21; // [esp+4h] [ebp-48h]
  float v22; // [esp+4h] [ebp-48h]
  float v23; // [esp+4h] [ebp-48h]
  bool v24; // [esp+23h] [ebp-29h]
  float yMiterThisL; // [esp+24h] [ebp-28h]
  float v3; // [esp+28h] [ebp-24h]
  unsigned int v3a; // [esp+28h] [ebp-24h]
  float v28; // [esp+2Ch] [ebp-20h]
  float v2; // [esp+30h] [ebp-1Ch]
  unsigned int v2a; // [esp+30h] [ebp-1Ch]
  float v31; // [esp+34h] [ebp-18h]
  float v32; // [esp+38h] [ebp-14h]
  float v33; // [esp+3Ch] [ebp-10h]
  unsigned int SolidL; // [esp+40h] [ebp-Ch]
  unsigned int v35; // [esp+40h] [ebp-Ch]
  unsigned int SolidR; // [esp+44h] [ebp-8h]
  float v1a; // [esp+50h] [ebp+4h]
  Scaleform::Render::StrokeVertex *v1b; // [esp+50h] [ebp+4h]
  float wa; // [esp+54h] [ebp+8h]
  float wb; // [esp+54h] [ebp+8h]
  float wc; // [esp+54h] [ebp+8h]
  float wd; // [esp+54h] [ebp+8h]
  float we; // [esp+54h] [ebp+8h]
  float wf; // [esp+54h] [ebp+8h]
  float wg; // [esp+54h] [ebp+8h]
  float wh; // [esp+54h] [ebp+8h]
  Scaleform::Render::StrokerTypes::LineJoinType lineJoina; // [esp+5Ch] [ebp+10h]

  v6 = p;
  v24 = p->overlapPrev || p->overlapThis;
  if ( p->rightTurnThis )
  {
    v8 = w;
    v3 = p->xMiterThisL;
    yMiterThisL = p->yMiterThisL;
    v31 = (v3 - v1->x) * w->solidCoeffL + v1->x;
    v1a = (yMiterThisL - v1->y) * w->solidCoeffL + v1->y;
    if ( w->totalLimitL < (double)p->dMiterThisL && (unsigned int)lineJoin <= MiterBevelJoin )
    {
      Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, lineJoin);
      return;
    }
    if ( *(_WORD *)&p->overlapPrev )
      xMiterThisR = p->dx1TotalR + v1->x;
    else
      xMiterThisR = p->xMiterThisR;
    v2 = xMiterThisR;
    if ( *(_WORD *)&p->overlapPrev )
      yMiterThisR = p->dy1TotalR + v1->y;
    else
      yMiterThisR = p->yMiterThisR;
    v28 = yMiterThisR;
    v33 = (v2 - v1->x) * w->solidCoeffR + v1->x;
    v32 = (v28 - v1->y) * w->solidCoeffR + v1->y;
  }
  else
  {
    v2 = p->xMiterThisR;
    v28 = p->yMiterThisR;
    v33 = (v2 - v1->x) * w->solidCoeffR + v1->x;
    v32 = (v28 - v1->y) * w->solidCoeffR + v1->y;
    if ( w->totalLimitR < (double)p->dMiterThisR && (unsigned int)lineJoin <= MiterBevelJoin )
    {
      Scaleform::Render::StrokerAA::calcBevelJoin(this, v1, w, p, lineJoin);
      return;
    }
    if ( *(_WORD *)&p->overlapPrev )
      xMiterThisL = v1->x - p->dx1TotalL;
    else
      xMiterThisL = p->xMiterThisL;
    v3 = xMiterThisL;
    if ( *(_WORD *)&p->overlapPrev )
      v12 = v1->y - p->dy1TotalL;
    else
      v12 = p->yMiterThisL;
    yMiterThisL = v12;
    v8 = w;
    v31 = (v3 - v1->x) * w->solidCoeffL + v1->x;
    v1a = (yMiterThisL - v1->y) * w->solidCoeffL + v1->y;
  }
  v13 = Scaleform::Render::StrokerAA::addVertex(this, v31, v1a, this->StyleLeft, 1);
  lineJoina = v13;
  if ( v8->aaFlagL )
    v13 = Scaleform::Render::StrokerAA::addVertex(this, v3, yMiterThisL, this->StyleLeft, 0);
  v3a = v13;
  if ( v8->solidFlag )
    v14 = Scaleform::Render::StrokerAA::addVertex(this, v33, v32, this->StyleRight, 1);
  else
    v14 = lineJoina;
  v1b = (Scaleform::Render::StrokeVertex *)v14;
  if ( v8->aaFlagR )
    v2a = Scaleform::Render::StrokerAA::addVertex(this, v2, v28, this->StyleRight, 0);
  else
    v2a = v14;
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
    v16->v2 = (unsigned int)v1b;
    v16->v3 = lineJoina;
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
    v19->v3 = (unsigned int)v1b;
    ++this->Triangles.Size;
    v6 = p;
  }
  if ( v8->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, lineJoina);
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, lineJoina, v3a);
  }
  if ( v8->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v2a, (unsigned int)v1b);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v2a);
  }
  this->SolidL = lineJoina;
  this->TotalL = v3a;
  this->SolidR = (unsigned int)v1b;
  this->TotalR = v2a;
  if ( v24 )
  {
    if ( v6->rightTurnThis )
    {
      wa = v6->dy2SolidR + v1->y;
      v20 = wa;
      wb = v6->dx2SolidR + v1->x;
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(this, wb, v20, this->StyleRight, 1);
      if ( v8->aaFlagR )
      {
        wc = v6->dy2TotalR + v1->y;
        v21 = wc;
        wd = v6->dx2TotalR + v1->x;
        this->TotalR = Scaleform::Render::StrokerAA::addVertex(this, wd, v21, this->StyleRight, 0);
      }
      else
      {
        this->TotalR = (unsigned int)v1b;
      }
    }
    else
    {
      we = v1->y - v6->dy2SolidL;
      v22 = we;
      wf = v1->x - v6->dx2SolidL;
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(this, wf, v22, this->StyleLeft, 1);
      if ( v8->aaFlagL )
      {
        wg = v1->y - v6->dy2TotalL;
        v23 = wg;
        wh = v1->x - v6->dx2TotalL;
        this->TotalL = Scaleform::Render::StrokerAA::addVertex(this, wh, v23, this->StyleLeft, 0);
      }
      else
      {
        this->TotalL = lineJoina;
      }
    }
  }
}
