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
  float v14; // [esp+4h] [ebp-114h]
  float v15; // [esp+4h] [ebp-114h]
  float v16; // [esp+4h] [ebp-114h]
  float v17; // [esp+4h] [ebp-114h]
  float v18; // [esp+20h] [ebp-F8h]
  float v19; // [esp+20h] [ebp-F8h]
  float v20; // [esp+20h] [ebp-F8h]
  float v21; // [esp+20h] [ebp-F8h]
  unsigned int v22; // [esp+20h] [ebp-F8h]
  float v3a; // [esp+24h] [ebp-F4h]
  float v3b; // [esp+24h] [ebp-F4h]
  float v3c; // [esp+24h] [ebp-F4h]
  unsigned int v3; // [esp+24h] [ebp-F4h]
  float v27; // [esp+28h] [ebp-F0h]
  float v28; // [esp+28h] [ebp-F0h]
  float v29; // [esp+28h] [ebp-F0h]
  unsigned int v30; // [esp+28h] [ebp-F0h]
  unsigned int v31; // [esp+2Ch] [ebp-ECh]
  unsigned int SolidL; // [esp+30h] [ebp-E8h]
  unsigned int v33; // [esp+30h] [ebp-E8h]
  unsigned int SolidR; // [esp+34h] [ebp-E4h]
  float v35; // [esp+3Ch] [ebp-DCh]
  float v36; // [esp+40h] [ebp-D8h]
  float v37; // [esp+44h] [ebp-D4h]
  float v38; // [esp+48h] [ebp-D0h]
  float v39; // [esp+6Ch] [ebp-ACh]
  float v40; // [esp+70h] [ebp-A8h]
  float v41; // [esp+74h] [ebp-A4h]
  float v42; // [esp+78h] [ebp-A0h]

  v27 = (v1->y - v0->y) / len;
  v3a = (v0->x - v1->x) / len;
  v35 = w->solidWidthL * v27;
  v36 = w->solidWidthL * v3a;
  v39 = v27 * w->solidWidthR;
  v40 = v3a * w->solidWidthR;
  v37 = v27 * w->totalWidthL;
  v38 = v3a * w->totalWidthL;
  v41 = v27 * w->totalWidthR;
  v42 = v3a * w->totalWidthR;
  v28 = v1->y - v36;
  v14 = v28;
  v29 = v1->x - v35;
  v6 = Scaleform::Render::StrokerAA::addVertex(this, v29, v14, this->StyleLeft, 1);
  v7 = v6;
  v30 = v6;
  if ( w->aaFlagL )
  {
    v3b = v1->y - v38;
    v15 = v3b;
    v3c = v1->x - v37;
    v3 = Scaleform::Render::StrokerAA::addVertex(this, v3c, v15, this->StyleLeft, 0);
  }
  else
  {
    v3 = v6;
  }
  if ( w->solidFlag )
  {
    v18 = v40 + v1->y;
    v16 = v18;
    v19 = v1->x + v39;
    v31 = Scaleform::Render::StrokerAA::addVertex(this, v19, v16, this->StyleRight, 1);
  }
  else
  {
    v31 = v7;
  }
  if ( w->aaFlagR )
  {
    v20 = v42 + v1->y;
    v17 = v20;
    v21 = v1->x + v41;
    v8 = Scaleform::Render::StrokerAA::addVertex(this, v21, v17, this->StyleRight, 0);
    v22 = v8;
  }
  else
  {
    v22 = v31;
    v8 = v31;
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
    v10->v2 = v31;
    v10->v3 = v30;
    v11 = ++this->Triangles.Size >> 4;
    v33 = this->SolidL;
    SolidR = this->SolidR;
    if ( v11 >= this->Triangles.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        v11);
    v12 = this->Triangles.Pages[v11];
    v7 = v30;
    v13 = &v12[this->Triangles.Size & 0xF];
    v13->v1 = v33;
    v13->v2 = SolidR;
    v13->v3 = v31;
    ++this->Triangles.Size;
    v8 = v22;
  }
  if ( w->aaFlagL )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v7);
    Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v7, v3);
  }
  if ( w->aaFlagR )
  {
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v8, v31);
    Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v8);
  }
  this->SolidL = v7;
  this->TotalR = v8;
  this->TotalL = v3;
  this->SolidR = v31;
}
