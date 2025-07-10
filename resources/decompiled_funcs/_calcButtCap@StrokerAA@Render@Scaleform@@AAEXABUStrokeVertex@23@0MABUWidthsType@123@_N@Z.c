void __thiscall Scaleform::Render::StrokerAA::calcButtCap(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        bool endFlag)
{
  double totalWidthR; // st7
  double v10; // st7
  double v11; // st4
  double v12; // st4
  double v13; // st5
  bool v14; // cl
  bool v15; // al
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int TotalL; // eax
  unsigned int SolidL; // eax
  unsigned int v22; // ebx
  unsigned int v23; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v24; // eax
  unsigned int v25; // ebx
  unsigned int v26; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v27; // eax
  float y; // [esp+4h] [ebp-58h]
  float ya; // [esp+4h] [ebp-58h]
  float yb; // [esp+4h] [ebp-58h]
  float yc; // [esp+4h] [ebp-58h]
  float yd; // [esp+4h] [ebp-58h]
  float ye; // [esp+4h] [ebp-58h]
  float yf; // [esp+4h] [ebp-58h]
  float yg; // [esp+4h] [ebp-58h]
  unsigned int buttSolidR; // [esp+20h] [ebp-3Ch]
  float dyTotalL; // [esp+24h] [ebp-38h]
  float dxTotalL; // [esp+28h] [ebp-34h]
  float dySolidR; // [esp+2Ch] [ebp-30h]
  float dxSolidR; // [esp+30h] [ebp-2Ch]
  float dyTotalR; // [esp+34h] [ebp-28h]
  float dxTotalR; // [esp+38h] [ebp-24h]
  float buttTotalLa; // [esp+3Ch] [ebp-20h]
  unsigned int buttTotalL; // [esp+3Ch] [ebp-20h]
  float totalWidthL; // [esp+40h] [ebp-1Ch]
  unsigned int totalWidthLa; // [esp+40h] [ebp-1Ch]
  float solidWidthR; // [esp+44h] [ebp-18h]
  unsigned int solidWidthRa; // [esp+44h] [ebp-18h]
  float solidWidthRb; // [esp+44h] [ebp-18h]
  float solidWidthRc; // [esp+44h] [ebp-18h]
  float solidWidthRd; // [esp+44h] [ebp-18h]
  float solidWidthRe; // [esp+44h] [ebp-18h]
  float solidWidthRf; // [esp+44h] [ebp-18h]
  float solidWidthRg; // [esp+44h] [ebp-18h]
  float dySolidL; // [esp+48h] [ebp-14h]
  float dxSolidL; // [esp+4Ch] [ebp-10h]
  unsigned int SolidR; // [esp+58h] [ebp-4h]
  bool aaFlagR; // [esp+60h] [ebp+4h]
  float dya; // [esp+64h] [ebp+8h]
  float dy; // [esp+64h] [ebp+8h]
  float dyb; // [esp+64h] [ebp+8h]
  float dyc; // [esp+64h] [ebp+8h]
  float lenb; // [esp+68h] [ebp+Ch]
  float lena; // [esp+68h] [ebp+Ch]
  float aaFlagL; // [esp+6Ch] [ebp+10h]
  bool aaFlagLa; // [esp+6Ch] [ebp+10h]
  float endFlaga; // [esp+70h] [ebp+14h]
  float endFlagb; // [esp+70h] [ebp+14h]
  float endFlagc; // [esp+70h] [ebp+14h]
  float endFlagd; // [esp+70h] [ebp+14h]
  float endFlage; // [esp+70h] [ebp+14h]
  float endFlagf; // [esp+70h] [ebp+14h]
  float endFlagg; // [esp+70h] [ebp+14h]
  float endFlagh; // [esp+70h] [ebp+14h]

  if ( endFlag )
  {
    aaFlagL = w->solidWidthR;
    solidWidthR = w->solidWidthL;
    totalWidthL = w->totalWidthR;
    totalWidthR = w->totalWidthL;
  }
  else
  {
    aaFlagL = w->solidWidthL;
    solidWidthR = w->solidWidthR;
    totalWidthL = w->totalWidthL;
    totalWidthR = w->totalWidthR;
  }
  buttTotalLa = totalWidthR;
  buttSolidR = 0;
  v10 = len;
  lenb = (v1->y - v0->y) / len;
  dya = (v0->x - v1->x) / v10;
  dxSolidL = lenb * aaFlagL;
  dySolidL = aaFlagL * dya;
  v11 = solidWidthR;
  solidWidthRa = 0;
  dxSolidR = lenb * v11;
  dySolidR = v11 * dya;
  v12 = totalWidthL;
  totalWidthLa = 0;
  dxTotalL = lenb * v12;
  dyTotalL = v12 * dya;
  v13 = buttTotalLa;
  buttTotalL = 0;
  dxTotalR = lenb * v13;
  dyTotalR = v13 * dya;
  lena = (dyTotalL - dySolidL + dyTotalR - dySolidR) * 0.5;
  dy = 0.5 * (dxSolidR - dxTotalR + dxSolidL - dxTotalL);
  if ( endFlag )
  {
    v14 = w->aaFlagR;
    v15 = w->aaFlagL;
    aaFlagLa = v14;
    aaFlagR = v15;
  }
  else
  {
    v15 = w->aaFlagL;
    v14 = w->aaFlagR;
    aaFlagLa = v15;
    aaFlagR = v14;
  }
  if ( v15 || v14 )
  {
    solidWidthRb = v0->y - dySolidL + dy;
    y = solidWidthRb;
    solidWidthRc = v0->x - dxSolidL + lena;
    v16 = Scaleform::Render::StrokerAA::addVertex(this, solidWidthRc, y, this->StyleLeft, 0);
    v17 = v16;
    totalWidthLa = v16;
    if ( w->solidFlag )
    {
      solidWidthRd = dySolidR + v0->y + dy;
      ya = solidWidthRd;
      solidWidthRe = v0->x + dxSolidR + lena;
      buttSolidR = Scaleform::Render::StrokerAA::addVertex(this, solidWidthRe, ya, this->StyleRight, 0);
    }
    else
    {
      buttSolidR = v16;
    }
    if ( aaFlagLa )
    {
      solidWidthRf = v0->y - dyTotalL + dy;
      yb = solidWidthRf;
      solidWidthRg = v0->x - dxTotalL + lena;
      buttTotalL = Scaleform::Render::StrokerAA::addVertex(this, solidWidthRg, yb, this->StyleLeft, 0);
    }
    else
    {
      buttTotalL = v17;
    }
    if ( aaFlagR )
    {
      dyb = dyTotalR + v0->y + dy;
      yc = dyb;
      dyc = v0->x + dxTotalR + lena;
      solidWidthRa = Scaleform::Render::StrokerAA::addVertex(this, dyc, yc, this->StyleRight, 0);
    }
    else
    {
      solidWidthRa = buttSolidR;
    }
  }
  if ( endFlag )
  {
    TotalL = this->TotalL;
    this->TotalL = this->TotalR;
    this->TotalR = TotalL;
    SolidL = this->SolidL;
    this->SolidL = this->SolidR;
    this->SolidR = SolidL;
  }
  else
  {
    endFlaga = v0->y - dySolidL;
    yd = endFlaga;
    endFlagb = v0->x - dxSolidL;
    v18 = Scaleform::Render::StrokerAA::addVertex(this, endFlagb, yd, this->StyleLeft, 1);
    this->SolidL = v18;
    if ( w->aaFlagL )
    {
      endFlagc = v0->y - dyTotalL;
      ye = endFlagc;
      endFlagd = v0->x - dxTotalL;
      v18 = Scaleform::Render::StrokerAA::addVertex(this, endFlagd, ye, this->StyleLeft, 0);
    }
    this->TotalL = v18;
    if ( w->solidFlag )
    {
      endFlage = dySolidR + v0->y;
      yf = endFlage;
      endFlagf = v0->x + dxSolidR;
      v19 = Scaleform::Render::StrokerAA::addVertex(this, endFlagf, yf, this->StyleRight, 1);
    }
    else
    {
      v19 = this->SolidL;
    }
    this->SolidR = v19;
    if ( w->aaFlagR )
    {
      endFlagg = dyTotalR + v0->y;
      yg = endFlagg;
      endFlagh = v0->x + dxTotalR;
      v19 = Scaleform::Render::StrokerAA::addVertex(this, endFlagh, yg, this->StyleRight, 0);
    }
    this->TotalR = v19;
  }
  if ( (w->aaFlagL || w->aaFlagR) && (w->solidFlagL || w->solidFlagR) )
  {
    v22 = this->SolidL;
    v23 = this->Triangles.Size >> 4;
    if ( v23 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        this->Triangles.Size >> 4);
    v24 = &this->Triangles.Pages[v23][this->Triangles.Size & 0xF];
    v24->v1 = totalWidthLa;
    v24->v2 = buttSolidR;
    v24->v3 = v22;
    ++this->Triangles.Size;
    v25 = this->SolidL;
    v26 = this->Triangles.Size >> 4;
    SolidR = this->SolidR;
    if ( v26 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        v26);
    v27 = &this->Triangles.Pages[v26][this->Triangles.Size & 0xF];
    v27->v1 = v25;
    v27->v2 = buttSolidR;
    v27->v3 = SolidR;
    ++this->Triangles.Size;
  }
  if ( aaFlagLa )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->TotalL, buttTotalL);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, buttTotalL, totalWidthLa);
  }
  if ( aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, solidWidthRa, this->TotalR);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, buttSolidR, solidWidthRa);
  }
}
