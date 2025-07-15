void __thiscall Scaleform::Render::StrokerAA::calcButtCap(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        bool endFlag)
{
  double totalWidthL; // st7
  double v10; // st7
  double v11; // st4
  double v12; // st4
  double v13; // st5
  bool aaFlagR; // cl
  bool aaFlagL; // al
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
  float v28; // [esp+4h] [ebp-58h]
  float v29; // [esp+4h] [ebp-58h]
  float v30; // [esp+4h] [ebp-58h]
  float v31; // [esp+4h] [ebp-58h]
  float v32; // [esp+4h] [ebp-58h]
  float v33; // [esp+4h] [ebp-58h]
  float v34; // [esp+4h] [ebp-58h]
  float v35; // [esp+4h] [ebp-58h]
  unsigned int v36; // [esp+20h] [ebp-3Ch]
  float v37; // [esp+24h] [ebp-38h]
  float v38; // [esp+28h] [ebp-34h]
  float v39; // [esp+2Ch] [ebp-30h]
  float v40; // [esp+30h] [ebp-2Ch]
  float v41; // [esp+34h] [ebp-28h]
  float v42; // [esp+38h] [ebp-24h]
  float v3a; // [esp+3Ch] [ebp-20h]
  unsigned int v3; // [esp+3Ch] [ebp-20h]
  float totalWidthR; // [esp+40h] [ebp-1Ch]
  unsigned int v46; // [esp+40h] [ebp-1Ch]
  float v2; // [esp+44h] [ebp-18h]
  unsigned int v2a; // [esp+44h] [ebp-18h]
  float v2b; // [esp+44h] [ebp-18h]
  float v2c; // [esp+44h] [ebp-18h]
  float v2d; // [esp+44h] [ebp-18h]
  float v2e; // [esp+44h] [ebp-18h]
  float v2f; // [esp+44h] [ebp-18h]
  float v2g; // [esp+44h] [ebp-18h]
  float v55; // [esp+48h] [ebp-14h]
  float v56; // [esp+4Ch] [ebp-10h]
  unsigned int SolidR; // [esp+58h] [ebp-4h]
  bool v58; // [esp+60h] [ebp+4h]
  float v59; // [esp+64h] [ebp+8h]
  float v60; // [esp+64h] [ebp+8h]
  float v61; // [esp+64h] [ebp+8h]
  float v62; // [esp+64h] [ebp+8h]
  float v63; // [esp+68h] [ebp+Ch]
  float v64; // [esp+68h] [ebp+Ch]
  float solidWidthR; // [esp+6Ch] [ebp+10h]
  bool v66; // [esp+6Ch] [ebp+10h]
  float v67; // [esp+70h] [ebp+14h]
  float v68; // [esp+70h] [ebp+14h]
  float v69; // [esp+70h] [ebp+14h]
  float v70; // [esp+70h] [ebp+14h]
  float v71; // [esp+70h] [ebp+14h]
  float v72; // [esp+70h] [ebp+14h]
  float v73; // [esp+70h] [ebp+14h]
  float v74; // [esp+70h] [ebp+14h]

  if ( endFlag )
  {
    solidWidthR = w->solidWidthR;
    v2 = w->solidWidthL;
    totalWidthR = w->totalWidthR;
    totalWidthL = w->totalWidthL;
  }
  else
  {
    solidWidthR = w->solidWidthL;
    v2 = w->solidWidthR;
    totalWidthR = w->totalWidthL;
    totalWidthL = w->totalWidthR;
  }
  v3a = totalWidthL;
  v36 = 0;
  v10 = len;
  v63 = (v1->y - v0->y) / len;
  v59 = (v0->x - v1->x) / v10;
  v56 = v63 * solidWidthR;
  v55 = solidWidthR * v59;
  v11 = v2;
  v2a = 0;
  v40 = v63 * v11;
  v39 = v11 * v59;
  v12 = totalWidthR;
  v46 = 0;
  v38 = v63 * v12;
  v37 = v12 * v59;
  v13 = v3a;
  v3 = 0;
  v42 = v63 * v13;
  v41 = v13 * v59;
  v64 = (v37 - v55 + v41 - v39) * 0.5;
  v60 = 0.5 * (v40 - v42 + v56 - v38);
  if ( endFlag )
  {
    aaFlagR = w->aaFlagR;
    aaFlagL = w->aaFlagL;
    v66 = aaFlagR;
    v58 = aaFlagL;
  }
  else
  {
    aaFlagL = w->aaFlagL;
    aaFlagR = w->aaFlagR;
    v66 = aaFlagL;
    v58 = aaFlagR;
  }
  if ( aaFlagL || aaFlagR )
  {
    v2b = v0->y - v55 + v60;
    v28 = v2b;
    v2c = v0->x - v56 + v64;
    v16 = Scaleform::Render::StrokerAA::addVertex(this, v2c, v28, this->StyleLeft, 0);
    v17 = v16;
    v46 = v16;
    if ( w->solidFlag )
    {
      v2d = v39 + v0->y + v60;
      v29 = v2d;
      v2e = v0->x + v40 + v64;
      v36 = Scaleform::Render::StrokerAA::addVertex(this, v2e, v29, this->StyleRight, 0);
    }
    else
    {
      v36 = v16;
    }
    if ( v66 )
    {
      v2f = v0->y - v37 + v60;
      v30 = v2f;
      v2g = v0->x - v38 + v64;
      v3 = Scaleform::Render::StrokerAA::addVertex(this, v2g, v30, this->StyleLeft, 0);
    }
    else
    {
      v3 = v17;
    }
    if ( v58 )
    {
      v61 = v41 + v0->y + v60;
      v31 = v61;
      v62 = v0->x + v42 + v64;
      v2a = Scaleform::Render::StrokerAA::addVertex(this, v62, v31, this->StyleRight, 0);
    }
    else
    {
      v2a = v36;
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
    v67 = v0->y - v55;
    v32 = v67;
    v68 = v0->x - v56;
    v18 = Scaleform::Render::StrokerAA::addVertex(this, v68, v32, this->StyleLeft, 1);
    this->SolidL = v18;
    if ( w->aaFlagL )
    {
      v69 = v0->y - v37;
      v33 = v69;
      v70 = v0->x - v38;
      v18 = Scaleform::Render::StrokerAA::addVertex(this, v70, v33, this->StyleLeft, 0);
    }
    this->TotalL = v18;
    if ( w->solidFlag )
    {
      v71 = v39 + v0->y;
      v34 = v71;
      v72 = v0->x + v40;
      v19 = Scaleform::Render::StrokerAA::addVertex(this, v72, v34, this->StyleRight, 1);
    }
    else
    {
      v19 = this->SolidL;
    }
    this->SolidR = v19;
    if ( w->aaFlagR )
    {
      v73 = v41 + v0->y;
      v35 = v73;
      v74 = v0->x + v42;
      v19 = Scaleform::Render::StrokerAA::addVertex(this, v74, v35, this->StyleRight, 0);
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
    v24->v1 = v46;
    v24->v2 = v36;
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
    v27->v2 = v36;
    v27->v3 = SolidR;
    ++this->Triangles.Size;
  }
  if ( v66 )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->TotalL, v3);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v3, v46);
  }
  if ( v58 )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v2a, this->TotalR);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v36, v2a);
  }
}
