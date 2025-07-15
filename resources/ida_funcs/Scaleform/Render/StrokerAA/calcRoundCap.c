void __thiscall Scaleform::Render::StrokerAA::calcRoundCap(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        bool endFlag)
{
  const Scaleform::Render::StrokerAA::WidthsType *v7; // ebp
  double totalWidthR; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st5
  double v13; // st6
  int v14; // ebx
  unsigned int SolidR; // eax
  unsigned int TotalR; // ecx
  unsigned int v17; // eax
  double v18; // st7
  unsigned int StyleLeft; // eax
  unsigned int StyleRight; // eax
  unsigned int SolidL; // ebx
  unsigned int v22; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v23; // eax
  Scaleform::Render::StrokerAA::TriangleType *v24; // eax
  unsigned int v25; // ebx
  unsigned int v26; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v30; // eax
  Scaleform::Render::StrokerAA::TriangleType *v31; // eax
  unsigned int v32; // ebx
  unsigned int v33; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v34; // eax
  Scaleform::Render::StrokerAA::TriangleType *v35; // eax
  unsigned int v36; // ebx
  unsigned int v37; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v38; // eax
  unsigned int v39; // ebx
  unsigned int v40; // ebp
  Scaleform::Render::StrokerAA::TriangleType *v41; // eax
  Scaleform::Render::StrokerAA::TriangleType *v42; // eax
  bool v43; // zf
  float y; // [esp+4h] [ebp-70h]
  float ya; // [esp+4h] [ebp-70h]
  float xTotal; // [esp+20h] [ebp-54h]
  float xTotala; // [esp+20h] [ebp-54h]
  float xTotalb; // [esp+20h] [ebp-54h]
  float yTotal; // [esp+24h] [ebp-50h]
  float yTotala; // [esp+24h] [ebp-50h]
  float yTotalb; // [esp+24h] [ebp-50h]
  float totalWidthL; // [esp+28h] [ebp-4Ch]
  double totalWidthLb; // [esp+28h] [ebp-4Ch]
  float totalWidthLc; // [esp+28h] [ebp-4Ch]
  float totalWidthLd; // [esp+28h] [ebp-4Ch]
  float totalWidthLe; // [esp+28h] [ebp-4Ch]
  float totalWidthLf; // [esp+28h] [ebp-4Ch]
  float totalWidthLa; // [esp+28h] [ebp-4Ch]
  float na; // [esp+30h] [ebp-44h]
  float nb; // [esp+30h] [ebp-44h]
  float nc; // [esp+30h] [ebp-44h]
  float nd; // [esp+30h] [ebp-44h]
  float ne; // [esp+30h] [ebp-44h]
  int n; // [esp+30h] [ebp-44h]
  float dySolidL; // [esp+34h] [ebp-40h]
  int dySolidLa; // [esp+34h] [ebp-40h]
  float cyTotal; // [esp+38h] [ebp-3Ch]
  float cyTotala; // [esp+38h] [ebp-3Ch]
  float dxSolidR; // [esp+3Ch] [ebp-38h]
  float dxSolidRa; // [esp+3Ch] [ebp-38h]
  float cySolid; // [esp+40h] [ebp-34h]
  float cySolida; // [esp+40h] [ebp-34h]
  unsigned int v73; // [esp+4Ch] [ebp-28h]
  unsigned int TotalL; // [esp+54h] [ebp-20h]
  unsigned int v75; // [esp+60h] [ebp-14h]
  unsigned int v76; // [esp+6Ch] [ebp-8h]
  float newSolidb; // [esp+78h] [ebp+4h]
  float newSolid; // [esp+78h] [ebp+4h]
  float newSolidc; // [esp+78h] [ebp+4h]
  float newSolidd; // [esp+78h] [ebp+4h]
  unsigned int newSolida; // [esp+78h] [ebp+4h]
  float xSolidc; // [esp+7Ch] [ebp+8h]
  float xSolid; // [esp+7Ch] [ebp+8h]
  float xSolidd; // [esp+7Ch] [ebp+8h]
  float xSolida; // [esp+7Ch] [ebp+8h]
  unsigned int xSolidb; // [esp+7Ch] [ebp+8h]
  float a1a; // [esp+80h] [ebp+Ch]
  float a1; // [esp+80h] [ebp+Ch]

  v7 = w;
  if ( endFlag )
  {
    xTotal = w->solidWidthR;
    yTotal = w->solidWidthL;
    totalWidthL = w->totalWidthR;
    totalWidthR = w->totalWidthL;
  }
  else
  {
    xTotal = w->solidWidthL;
    yTotal = w->solidWidthR;
    totalWidthL = w->totalWidthL;
    totalWidthR = w->totalWidthR;
  }
  na = totalWidthR;
  newSolidb = (v1->y - v0->y) / len;
  xSolidc = (v0->x - v1->x) / len;
  v10 = newSolidb;
  v11 = xTotal;
  xTotala = newSolidb * xTotal;
  v12 = v11 * xSolidc;
  v13 = xSolidc;
  dySolidL = v12;
  dxSolidR = newSolidb * yTotal;
  cySolid = yTotal * xSolidc;
  newSolid = newSolidb * totalWidthL;
  xSolid = totalWidthL * xSolidc;
  yTotala = v10 * na;
  cyTotal = na * v13;
  a1a = atan2(-xSolid, -newSolid);
  nb = a1a + 3.141592741012573;
  totalWidthLb = nb - a1a;
  nc = w->totalWidth / (this->Tolerance * 0.25 + w->totalWidth);
  nd = acos(nc);
  ne = nd + nd;
  v14 = (int)(totalWidthLb / ne) + 1;
  *(float *)&n = totalWidthLb / (double)v14;
  a1 = *(float *)&n + a1a;
  if ( endFlag )
  {
    SolidR = this->SolidR;
    TotalR = this->TotalR;
    this->SolidL = SolidR;
    this->TotalL = TotalR;
  }
  else
  {
    totalWidthLc = v0->y - dySolidL;
    y = totalWidthLc;
    totalWidthLd = v0->x - xTotala;
    v17 = Scaleform::Render::StrokerAA::addVertex(this, totalWidthLd, y, this->StyleLeft, 1);
    this->SolidR = v17;
    this->SolidL = v17;
    if ( w->aaFlagL || w->aaFlagR )
    {
      totalWidthLe = v0->y - xSolid;
      ya = totalWidthLe;
      totalWidthLf = v0->x - newSolid;
      v17 = Scaleform::Render::StrokerAA::addVertex(this, totalWidthLf, ya, this->StyleLeft, 0);
    }
    this->TotalR = v17;
    this->TotalL = v17;
  }
  totalWidthLa = (yTotala - newSolid) * 0.5 + v0->x;
  cyTotala = (cyTotal - xSolid) * 0.5 + v0->y;
  dxSolidRa = (dxSolidR - xTotala) * 0.5 + v0->x;
  cySolida = 0.5 * (cySolid - dySolidL) + v0->y;
  if ( v14 > 0 )
  {
    dySolidLa = v14;
    do
    {
      newSolidc = cos(a1);
      xSolidd = sin(a1);
      xTotalb = v7->totalWidth * newSolidc + totalWidthLa;
      yTotalb = v7->totalWidth * xSolidd + cyTotala;
      v18 = xSolidd;
      xSolida = newSolidc * v7->solidWidth + dxSolidRa;
      if ( v7->solidFlag )
      {
        if ( endFlag )
          StyleLeft = this->StyleLeft;
        else
          StyleLeft = this->StyleRight;
        newSolidd = v18 * v7->solidWidth + cySolida;
        newSolida = Scaleform::Render::StrokerAA::addVertex(this, xSolida, newSolidd, StyleLeft, 1);
      }
      else
      {
        newSolida = this->SolidL;
      }
      if ( v7->aaFlagL || v7->aaFlagR )
      {
        if ( endFlag )
          StyleRight = this->StyleLeft;
        else
          StyleRight = this->StyleRight;
        xSolidb = Scaleform::Render::StrokerAA::addVertex(this, xTotalb, yTotalb, StyleRight, 0);
      }
      else
      {
        xSolidb = newSolida;
      }
      if ( endFlag )
      {
        if ( v7->solidFlagL || v7->solidFlagR )
        {
          SolidL = this->SolidL;
          v22 = this->Triangles.Size >> 4;
          v73 = this->SolidR;
          if ( v22 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v22);
          v23 = this->Triangles.Pages[v22];
          v7 = w;
          v24 = &v23[this->Triangles.Size & 0xF];
          v24->v1 = SolidL;
          v24->v2 = newSolida;
          v24->v3 = v73;
          ++this->Triangles.Size;
        }
        if ( v7->aaFlagL || v7->aaFlagR )
        {
          v25 = this->SolidL;
          v26 = this->Triangles.Size >> 4;
          TotalL = this->TotalL;
          if ( v26 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v26);
          v27 = &this->Triangles.Pages[v26][this->Triangles.Size & 0xF];
          v27->v1 = v25;
          v27->v2 = TotalL;
          v27->v3 = xSolidb;
          ++this->Triangles.Size;
          v28 = this->SolidL;
          v29 = this->Triangles.Size >> 4;
          if ( v29 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v30 = this->Triangles.Pages[v29];
          v7 = w;
          v31 = &v30[this->Triangles.Size & 0xF];
          v31->v1 = v28;
          v31->v2 = xSolidb;
          v31->v3 = newSolida;
          ++this->Triangles.Size;
        }
        this->SolidL = newSolida;
        this->TotalL = xSolidb;
      }
      else
      {
        if ( v7->solidFlagL || v7->solidFlagR )
        {
          v32 = this->SolidL;
          v33 = this->Triangles.Size >> 4;
          v75 = this->SolidR;
          if ( v33 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v33);
          v34 = this->Triangles.Pages[v33];
          v7 = w;
          v35 = &v34[this->Triangles.Size & 0xF];
          v35->v1 = v32;
          v35->v2 = v75;
          v35->v3 = newSolida;
          ++this->Triangles.Size;
        }
        if ( v7->aaFlagL || v7->aaFlagR )
        {
          v36 = this->SolidR;
          v37 = this->Triangles.Size >> 4;
          v76 = this->TotalR;
          if ( v37 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v37);
          v38 = &this->Triangles.Pages[v37][this->Triangles.Size & 0xF];
          v38->v1 = v36;
          v38->v2 = v76;
          v38->v3 = xSolidb;
          ++this->Triangles.Size;
          v39 = this->SolidR;
          v40 = this->Triangles.Size >> 4;
          if ( v40 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              this->Triangles.Size >> 4);
          v41 = this->Triangles.Pages[v40];
          v7 = w;
          v42 = &v41[this->Triangles.Size & 0xF];
          v42->v1 = v39;
          v42->v2 = xSolidb;
          v42->v3 = newSolida;
          ++this->Triangles.Size;
        }
        this->SolidR = newSolida;
        this->TotalR = xSolidb;
      }
      v43 = dySolidLa-- == 1;
      a1 = *(float *)&n + a1;
    }
    while ( !v43 );
  }
}
