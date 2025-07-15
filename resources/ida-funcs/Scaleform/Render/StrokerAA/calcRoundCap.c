void __thiscall Scaleform::Render::StrokerAA::calcRoundCap(
        Scaleform::Render::StrokerAA *this,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        const Scaleform::Render::StrokerAA::WidthsType *w,
        bool endFlag)
{
  const Scaleform::Render::StrokerAA::WidthsType *v7; // ebp
  double totalWidthL; // st7
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
  unsigned int v21; // ebx
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
  float v44; // [esp+4h] [ebp-70h]
  float v45; // [esp+4h] [ebp-70h]
  float solidWidthR; // [esp+20h] [ebp-54h]
  float v47; // [esp+20h] [ebp-54h]
  float v48; // [esp+20h] [ebp-54h]
  float solidWidthL; // [esp+24h] [ebp-50h]
  float v50; // [esp+24h] [ebp-50h]
  float v51; // [esp+24h] [ebp-50h]
  float totalWidthR; // [esp+28h] [ebp-4Ch]
  double v53; // [esp+28h] [ebp-4Ch]
  float v54; // [esp+28h] [ebp-4Ch]
  float v55; // [esp+28h] [ebp-4Ch]
  float v56; // [esp+28h] [ebp-4Ch]
  float v57; // [esp+28h] [ebp-4Ch]
  float v58; // [esp+28h] [ebp-4Ch]
  float v59; // [esp+30h] [ebp-44h]
  float v60; // [esp+30h] [ebp-44h]
  float v61; // [esp+30h] [ebp-44h]
  float v62; // [esp+30h] [ebp-44h]
  float v63; // [esp+30h] [ebp-44h]
  float v64; // [esp+30h] [ebp-44h]
  float v65; // [esp+34h] [ebp-40h]
  int v66; // [esp+34h] [ebp-40h]
  float v67; // [esp+38h] [ebp-3Ch]
  float v68; // [esp+38h] [ebp-3Ch]
  float v69; // [esp+3Ch] [ebp-38h]
  float v70; // [esp+3Ch] [ebp-38h]
  float v71; // [esp+40h] [ebp-34h]
  float v72; // [esp+40h] [ebp-34h]
  unsigned int v73; // [esp+4Ch] [ebp-28h]
  unsigned int TotalL; // [esp+54h] [ebp-20h]
  unsigned int v75; // [esp+60h] [ebp-14h]
  unsigned int v76; // [esp+6Ch] [ebp-8h]
  float v77; // [esp+78h] [ebp+4h]
  float v78; // [esp+78h] [ebp+4h]
  float v79; // [esp+78h] [ebp+4h]
  float v80; // [esp+78h] [ebp+4h]
  unsigned int SolidL; // [esp+78h] [ebp+4h]
  float v82; // [esp+7Ch] [ebp+8h]
  float v83; // [esp+7Ch] [ebp+8h]
  float v84; // [esp+7Ch] [ebp+8h]
  float v85; // [esp+7Ch] [ebp+8h]
  unsigned int v86; // [esp+7Ch] [ebp+8h]
  float v87; // [esp+80h] [ebp+Ch]
  float v88; // [esp+80h] [ebp+Ch]

  v7 = w;
  if ( endFlag )
  {
    solidWidthR = w->solidWidthR;
    solidWidthL = w->solidWidthL;
    totalWidthR = w->totalWidthR;
    totalWidthL = w->totalWidthL;
  }
  else
  {
    solidWidthR = w->solidWidthL;
    solidWidthL = w->solidWidthR;
    totalWidthR = w->totalWidthL;
    totalWidthL = w->totalWidthR;
  }
  v59 = totalWidthL;
  v77 = (v1->y - v0->y) / len;
  v82 = (v0->x - v1->x) / len;
  v10 = v77;
  v11 = solidWidthR;
  v47 = v77 * solidWidthR;
  v12 = v11 * v82;
  v13 = v82;
  v65 = v12;
  v69 = v77 * solidWidthL;
  v71 = solidWidthL * v82;
  v78 = v77 * totalWidthR;
  v83 = totalWidthR * v82;
  v50 = v10 * v59;
  v67 = v59 * v13;
  v87 = atan2(-v83, -v78);
  v60 = v87 + 3.141592741012573;
  v53 = v60 - v87;
  v61 = w->totalWidth / (this->Tolerance * 0.25 + w->totalWidth);
  v62 = acos(v61);
  v63 = v62 + v62;
  v14 = (int)(v53 / v63) + 1;
  v64 = v53 / (double)v14;
  v88 = v64 + v87;
  if ( endFlag )
  {
    SolidR = this->SolidR;
    TotalR = this->TotalR;
    this->SolidL = SolidR;
    this->TotalL = TotalR;
  }
  else
  {
    v54 = v0->y - v65;
    v44 = v54;
    v55 = v0->x - v47;
    v17 = Scaleform::Render::StrokerAA::addVertex(this, v55, v44, this->StyleLeft, 1);
    this->SolidR = v17;
    this->SolidL = v17;
    if ( w->aaFlagL || w->aaFlagR )
    {
      v56 = v0->y - v83;
      v45 = v56;
      v57 = v0->x - v78;
      v17 = Scaleform::Render::StrokerAA::addVertex(this, v57, v45, this->StyleLeft, 0);
    }
    this->TotalR = v17;
    this->TotalL = v17;
  }
  v58 = (v50 - v78) * 0.5 + v0->x;
  v68 = (v67 - v83) * 0.5 + v0->y;
  v70 = (v69 - v47) * 0.5 + v0->x;
  v72 = 0.5 * (v71 - v65) + v0->y;
  if ( v14 > 0 )
  {
    v66 = v14;
    do
    {
      v79 = cos(v88);
      v84 = sin(v88);
      v48 = v7->totalWidth * v79 + v58;
      v51 = v7->totalWidth * v84 + v68;
      v18 = v84;
      v85 = v79 * v7->solidWidth + v70;
      if ( v7->solidFlag )
      {
        if ( endFlag )
          StyleLeft = this->StyleLeft;
        else
          StyleLeft = this->StyleRight;
        v80 = v18 * v7->solidWidth + v72;
        SolidL = Scaleform::Render::StrokerAA::addVertex(this, v85, v80, StyleLeft, 1);
      }
      else
      {
        SolidL = this->SolidL;
      }
      if ( v7->aaFlagL || v7->aaFlagR )
      {
        if ( endFlag )
          StyleRight = this->StyleLeft;
        else
          StyleRight = this->StyleRight;
        v86 = Scaleform::Render::StrokerAA::addVertex(this, v48, v51, StyleRight, 0);
      }
      else
      {
        v86 = SolidL;
      }
      if ( endFlag )
      {
        if ( v7->solidFlagL || v7->solidFlagR )
        {
          v21 = this->SolidL;
          v22 = this->Triangles.Size >> 4;
          v73 = this->SolidR;
          if ( v22 >= this->Triangles.NumPages )
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
              v22);
          v23 = this->Triangles.Pages[v22];
          v7 = w;
          v24 = &v23[this->Triangles.Size & 0xF];
          v24->v1 = v21;
          v24->v2 = SolidL;
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
          v27->v3 = v86;
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
          v31->v2 = v86;
          v31->v3 = SolidL;
          ++this->Triangles.Size;
        }
        this->SolidL = SolidL;
        this->TotalL = v86;
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
          v35->v3 = SolidL;
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
          v38->v3 = v86;
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
          v42->v2 = v86;
          v42->v3 = SolidL;
          ++this->Triangles.Size;
        }
        this->SolidR = SolidL;
        this->TotalR = v86;
      }
      v43 = v66-- == 1;
      v88 = v64 + v88;
    }
    while ( !v43 );
  }
}
