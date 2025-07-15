void __thiscall Scaleform::Render::StrokerAA::calcButtJoin(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        const Scaleform::Render::StrokerAA::WidthsType *w)
{
  unsigned int v6; // eax
  unsigned int v7; // ebx
  unsigned int v8; // esi
  unsigned int v9; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v10; // eax
  unsigned int v11; // ebx
  Scaleform::Render::StrokerAA::TriangleType *v12; // eax
  Scaleform::Render::StrokerAA::TriangleType *v13; // eax
  float y; // [esp+4h] [ebp-114h]
  float ya; // [esp+4h] [ebp-114h]
  float yb; // [esp+4h] [ebp-114h]
  float yc; // [esp+4h] [ebp-114h]
  float newTotalRa; // [esp+20h] [ebp-F8h]
  float newTotalRb; // [esp+20h] [ebp-F8h]
  float newTotalRc; // [esp+20h] [ebp-F8h]
  float newTotalRd; // [esp+20h] [ebp-F8h]
  unsigned int newTotalR; // [esp+20h] [ebp-F8h]
  float dya; // [esp+24h] [ebp-F4h]
  float dyb; // [esp+24h] [ebp-F4h]
  float dyc; // [esp+24h] [ebp-F4h]
  unsigned int dy; // [esp+24h] [ebp-F4h]
  float newSolidLa; // [esp+28h] [ebp-F0h]
  float newSolidLb; // [esp+28h] [ebp-F0h]
  float newSolidLc; // [esp+28h] [ebp-F0h]
  unsigned int newSolidL; // [esp+28h] [ebp-F0h]
  unsigned int newSolidR; // [esp+2Ch] [ebp-ECh]
  unsigned int SolidL; // [esp+30h] [ebp-E8h]
  unsigned int v33; // [esp+30h] [ebp-E8h]
  unsigned int SolidR; // [esp+34h] [ebp-E4h]
  float p; // [esp+3Ch] [ebp-DCh]
  float p_4; // [esp+40h] [ebp-D8h]
  float p_8; // [esp+44h] [ebp-D4h]
  float p_12; // [esp+48h] [ebp-D0h]
  float p_48; // [esp+6Ch] [ebp-ACh]
  float p_52; // [esp+70h] [ebp-A8h]
  float p_56; // [esp+74h] [ebp-A4h]
  float p_60; // [esp+78h] [ebp-A0h]

  newSolidLa = (v1->y - v0->y) / len;
  dya = (v0->x - v1->x) / len;
  p = w->solidWidthL * newSolidLa;
  p_4 = w->solidWidthL * dya;
  p_48 = newSolidLa * w->solidWidthR;
  p_52 = dya * w->solidWidthR;
  p_8 = newSolidLa * w->totalWidthL;
  p_12 = dya * w->totalWidthL;
  p_56 = newSolidLa * w->totalWidthR;
  p_60 = dya * w->totalWidthR;
  newSolidLb = v1->y - p_4;
  y = newSolidLb;
  newSolidLc = v1->x - p;
  v6 = Scaleform::Render::StrokerAA::addVertex(this, newSolidLc, y, this->StyleLeft, 1);
  v7 = v6;
  newSolidL = v6;
  if ( w->aaFlagL )
  {
    dyb = v1->y - p_12;
    ya = dyb;
    dyc = v1->x - p_8;
    dy = Scaleform::Render::StrokerAA::addVertex(this, dyc, ya, this->StyleLeft, 0);
  }
  else
  {
    dy = v6;
  }
  if ( w->solidFlag )
  {
    newTotalRa = p_52 + v1->y;
    yb = newTotalRa;
    newTotalRb = v1->x + p_48;
    newSolidR = Scaleform::Render::StrokerAA::addVertex(this, newTotalRb, yb, this->StyleRight, 1);
  }
  else
  {
    newSolidR = v7;
  }
  if ( w->aaFlagR )
  {
    newTotalRc = p_60 + v1->y;
    yc = newTotalRc;
    newTotalRd = v1->x + p_56;
    v8 = Scaleform::Render::StrokerAA::addVertex(this, newTotalRd, yc, this->StyleRight, 0);
    newTotalR = v8;
  }
  else
  {
    newTotalR = newSolidR;
    v8 = newSolidR;
  }
  if ( w->solidFlagL || w->solidFlagR )
  {
    v9 = this->Triangles.Size >> 4;
    SolidL = this->SolidL;
    if ( v9 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        v9);
    v10 = &this->Triangles.Pages[v9][this->Triangles.Size & 0xF];
    v10->v1 = SolidL;
    v10->v2 = newSolidR;
    v10->v3 = newSolidL;
    v11 = ++this->Triangles.Size >> 4;
    v33 = this->SolidL;
    SolidR = this->SolidR;
    if ( v11 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        v11);
    v12 = this->Triangles.Pages[v11];
    v7 = newSolidL;
    v13 = &v12[this->Triangles.Size & 0xF];
    v13->v1 = v33;
    v13->v2 = SolidR;
    v13->v3 = newSolidR;
    ++this->Triangles.Size;
    v8 = newTotalR;
  }
  if ( w->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v7);
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v7, dy);
  }
  if ( w->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v8, newSolidR);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v8);
  }
  this->SolidL = v7;
  this->TotalR = v8;
  this->TotalL = dy;
  this->SolidR = newSolidR;
}
