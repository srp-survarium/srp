void __thiscall Scaleform::Render::StrokerAA::calcInitialJoinParam(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokeVertex *v2,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        Scaleform::Render::StrokerAA::JoinParamType *p)
{
  float v6; // [esp+4h] [ebp+4h]
  float v7; // [esp+8h] [ebp+8h]

  v6 = (v2->y - v1->y) / v1->dist;
  v7 = (v1->x - v2->x) / v1->dist;
  p->dx3SolidL = w->solidWidthL * v6;
  p->dy3SolidL = w->solidWidthL * v7;
  p->dx3SolidR = w->solidWidthR * v6;
  p->dy3SolidR = w->solidWidthR * v7;
  p->dx3TotalL = w->totalWidthL * v6;
  p->dy3TotalL = w->totalWidthL * v7;
  p->dx3TotalR = v6 * w->totalWidthR;
  p->dy3TotalR = v7 * w->totalWidthR;
  p->xMiterNextL = v1->x - p->dx3TotalL;
  p->yMiterNextL = v1->y - p->dy3TotalL;
  p->xMiterNextR = v1->x + p->dx3TotalR;
  p->yMiterNextR = p->dy3TotalR + v1->y;
  p->dMiterNextL = w->totalWidthL;
  p->dMiterNextR = w->totalWidthR;
  p->overlapThis = 0;
  p->rightTurnNext = 0;
  p->badMiterNextR = 0;
  p->badMiterNextL = 0;
}
