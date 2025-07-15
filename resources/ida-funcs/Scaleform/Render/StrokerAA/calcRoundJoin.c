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
  float v43; // [esp+4h] [ebp-5Ch]
  float v44; // [esp+4h] [ebp-5Ch]
  float v45; // [esp+4h] [ebp-5Ch]
  float v46; // [esp+4h] [ebp-5Ch]
  float v47; // [esp+4h] [ebp-5Ch]
  float v48; // [esp+4h] [ebp-5Ch]
  float v49; // [esp+4h] [ebp-5Ch]
  float v50; // [esp+4h] [ebp-5Ch]
  float v51; // [esp+4h] [ebp-5Ch]
  float v52; // [esp+4h] [ebp-5Ch]
  float v53; // [esp+4h] [ebp-5Ch]
  float v54; // [esp+4h] [ebp-5Ch]
  unsigned int v3; // [esp+20h] [ebp-40h]
  unsigned int v3a; // [esp+20h] [ebp-40h]
  unsigned int v3b; // [esp+20h] [ebp-40h]
  float v58; // [esp+24h] [ebp-3Ch]
  float v59; // [esp+24h] [ebp-3Ch]
  float v60; // [esp+24h] [ebp-3Ch]
  float v61; // [esp+24h] [ebp-3Ch]
  unsigned int v62; // [esp+24h] [ebp-3Ch]
  float v63; // [esp+24h] [ebp-3Ch]
  float v64; // [esp+24h] [ebp-3Ch]
  float v65; // [esp+24h] [ebp-3Ch]
  float v66; // [esp+24h] [ebp-3Ch]
  float v67; // [esp+24h] [ebp-3Ch]
  float v68; // [esp+24h] [ebp-3Ch]
  unsigned int v69; // [esp+24h] [ebp-3Ch]
  float v70; // [esp+24h] [ebp-3Ch]
  float v71; // [esp+24h] [ebp-3Ch]
  unsigned int v72; // [esp+24h] [ebp-3Ch]
  float v2; // [esp+28h] [ebp-38h]
  unsigned int v2a; // [esp+28h] [ebp-38h]
  float v2f; // [esp+28h] [ebp-38h]
  float v2b; // [esp+28h] [ebp-38h]
  float v2c; // [esp+28h] [ebp-38h]
  unsigned int v2d; // [esp+28h] [ebp-38h]
  float v2g; // [esp+28h] [ebp-38h]
  float v2e; // [esp+28h] [ebp-38h]
  float v81; // [esp+2Ch] [ebp-34h]
  float v82; // [esp+2Ch] [ebp-34h]
  float v83; // [esp+2Ch] [ebp-34h]
  float v84; // [esp+2Ch] [ebp-34h]
  float v85; // [esp+30h] [ebp-30h]
  double v86; // [esp+30h] [ebp-30h]
  float v87; // [esp+30h] [ebp-30h]
  float v88; // [esp+30h] [ebp-30h]
  float v89; // [esp+30h] [ebp-30h]
  float v90; // [esp+30h] [ebp-30h]
  float v91; // [esp+30h] [ebp-30h]
  double v92; // [esp+30h] [ebp-30h]
  float v93; // [esp+30h] [ebp-30h]
  float v94; // [esp+30h] [ebp-30h]
  float v95; // [esp+30h] [ebp-30h]
  float v96; // [esp+30h] [ebp-30h]
  float v97; // [esp+38h] [ebp-28h]
  float v98; // [esp+38h] [ebp-28h]
  float v99; // [esp+38h] [ebp-28h]
  float v100; // [esp+38h] [ebp-28h]
  float v101; // [esp+38h] [ebp-28h]
  float v102; // [esp+38h] [ebp-28h]
  int v103; // [esp+38h] [ebp-28h]
  int v104; // [esp+38h] [ebp-28h]
  float v105; // [esp+38h] [ebp-28h]
  float v106; // [esp+38h] [ebp-28h]
  float v107; // [esp+38h] [ebp-28h]
  float v108; // [esp+38h] [ebp-28h]
  float v109; // [esp+38h] [ebp-28h]
  float v110; // [esp+38h] [ebp-28h]
  int v111; // [esp+38h] [ebp-28h]
  int v112; // [esp+38h] [ebp-28h]
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
  bool pa; // [esp+6Ch] [ebp+Ch]
  float pf; // [esp+6Ch] [ebp+Ch]
  float pg; // [esp+6Ch] [ebp+Ch]
  float ph; // [esp+6Ch] [ebp+Ch]
  float pi; // [esp+6Ch] [ebp+Ch]
  float pb; // [esp+6Ch] [ebp+Ch]
  float pc; // [esp+6Ch] [ebp+Ch]
  float pj; // [esp+6Ch] [ebp+Ch]
  float pk; // [esp+6Ch] [ebp+Ch]
  float pl; // [esp+6Ch] [ebp+Ch]
  float pm; // [esp+6Ch] [ebp+Ch]
  float pd; // [esp+6Ch] [ebp+Ch]
  float pe; // [esp+6Ch] [ebp+Ch]

  v6 = p->overlapPrev || p->overlapThis;
  v7 = !p->rightTurnThis;
  pa = v6;
  if ( v7 )
  {
    v105 = this->Tolerance * 0.125;
    if ( v105 > w->solidWidthL + w->solidWidthL - p->dbTotalL )
      goto LABEL_3;
    v26 = v1;
    if ( v6 )
      xMiterThisL = v1->x - p->dx1TotalL;
    else
      xMiterThisL = p->xMiterThisL;
    v91 = xMiterThisL;
    if ( v6 )
      yMiterThisL = v1->y - p->dy1TotalL;
    else
      yMiterThisL = p->yMiterThisL;
    v83 = yMiterThisL;
    v106 = (v91 - v1->x) * w->solidCoeffL + v1->x;
    v2c = (v83 - v1->y) * w->solidCoeffL + v1->y;
    v65 = p->dy1SolidR + v1->y;
    v49 = v65;
    v66 = p->dx1SolidR + v1->x;
    v29 = Scaleform::Render::StrokerAA::addVertex(this, v66, v49, this->StyleRight, 1);
    if ( w->aaFlagR )
    {
      v67 = p->dy1TotalR + v1->y;
      v50 = v67;
      v68 = p->dx1TotalR + v1->x;
      v69 = Scaleform::Render::StrokerAA::addVertex(this, v68, v50, this->StyleRight, 0);
    }
    else
    {
      v69 = v29;
    }
    v30 = w;
    if ( w->solidFlag )
    {
      v2d = Scaleform::Render::StrokerAA::addVertex(this, v106, v2c, this->StyleLeft, 1);
      v30 = w;
    }
    else
    {
      v2d = v29;
    }
    if ( v30->aaFlagL )
    {
      v3b = Scaleform::Render::StrokerAA::addVertex(this, v91, v83, this->StyleLeft, 0);
      v30 = w;
    }
    else
    {
      v3b = v2d;
    }
    if ( v30->solidFlagL || v30->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v29, v2d);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v2d, this->SolidL);
      v30 = w;
    }
    if ( v30->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v29, this->SolidR);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalR, v69, v29);
      v30 = w;
    }
    if ( v30->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v2d, v3b);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v3b, this->TotalL);
    }
    this->SolidL = v2d;
    this->TotalL = v3b;
    this->SolidR = v29;
    this->TotalR = v69;
    if ( pa )
    {
      pj = v1->y - p->dy2SolidL;
      v51 = pj;
      pk = v1->x - p->dx2SolidL;
      this->SolidL = Scaleform::Render::StrokerAA::addVertex(this, pk, v51, this->StyleLeft, 1);
      if ( w->aaFlagL )
      {
        pl = v1->y - p->dy2TotalL;
        v52 = pl;
        pm = v1->x - p->dx2TotalL;
        v31 = Scaleform::Render::StrokerAA::addVertex(this, pm, v52, this->StyleLeft, 0);
      }
      else
      {
        v31 = v2d;
      }
      this->TotalL = v31;
    }
    pd = atan2(p->dy1TotalR, p->dx1TotalR);
    v107 = atan2(p->dy2TotalR, p->dx2TotalR);
    v32 = v107;
    if ( v107 < (double)pd )
    {
      v2g = v32 + 6.283185482025146;
      v32 = v2g;
    }
    v33 = w;
    v92 = v32 - pd;
    v108 = w->totalWidthR / (this->Tolerance * 0.25 + w->totalWidthR);
    v109 = acos(v108);
    v110 = v109 + v109;
    v34 = v92 / v110;
    v111 = (int)v34 + 1;
    v2e = v92 / (double)v111;
    pe = v2e + pd;
    if ( v111 > 0 )
    {
      v112 = (int)v34 + 1;
      do
      {
        v93 = cos(pe);
        v84 = v93;
        v94 = sin(pe);
        if ( v33->solidFlag )
        {
          v70 = v33->solidWidthR * v94 + v26->y;
          v53 = v70;
          v71 = v33->solidWidthR * v84 + v26->x;
          v29 = Scaleform::Render::StrokerAA::addVertex(this, v71, v53, this->StyleRight, 1);
        }
        if ( v33->aaFlagR )
        {
          v95 = v94 * v33->totalWidthR + v26->y;
          v54 = v95;
          v96 = v84 * v33->totalWidthR + v26->x;
          v72 = Scaleform::Render::StrokerAA::addVertex(this, v96, v54, this->StyleRight, 0);
        }
        else
        {
          v72 = v29;
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
          v42->v2 = v72;
          v42->v3 = v29;
          ++this->Triangles.Size;
          v33 = w;
        }
        v7 = v112-- == 1;
        this->SolidR = v29;
        this->TotalR = v72;
        pe = v2e + pe;
      }
      while ( !v7 );
    }
  }
  else
  {
    v97 = this->Tolerance * 0.125;
    if ( v97 > w->solidWidthR + w->solidWidthR - p->dbTotalR )
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
    v85 = xMiterThisR;
    if ( v6 )
      yMiterThisR = p->dy1TotalR + v1->y;
    else
      yMiterThisR = p->yMiterThisR;
    v81 = yMiterThisR;
    v98 = (v85 - v1->x) * w->solidCoeffR + v1->x;
    v2 = (v81 - v1->y) * w->solidCoeffR + v1->y;
    v58 = v1->y - p->dy1SolidL;
    v43 = v58;
    v59 = v1->x - p->dx1SolidL;
    v11 = Scaleform::Render::StrokerAA::addVertex(this, v59, v43, this->StyleLeft, 1);
    v12 = v11;
    if ( w->aaFlagL )
    {
      v60 = v1->y - p->dy1TotalL;
      v44 = v60;
      v61 = v1->x - p->dx1TotalL;
      v3 = Scaleform::Render::StrokerAA::addVertex(this, v61, v44, this->StyleLeft, 0);
    }
    else
    {
      v3 = v11;
    }
    v13 = w;
    if ( w->solidFlag )
    {
      v2a = Scaleform::Render::StrokerAA::addVertex(this, v98, v2, this->StyleRight, 1);
      v13 = w;
    }
    else
    {
      v2a = v12;
    }
    if ( v13->aaFlagR )
    {
      v62 = Scaleform::Render::StrokerAA::addVertex(this, v85, v81, this->StyleRight, 0);
      v13 = w;
    }
    else
    {
      v62 = v2a;
    }
    if ( v13->solidFlagL || v13->solidFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, v2a, v12);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidL, this->SolidR, v2a);
      v13 = w;
    }
    if ( v13->aaFlagL )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, this->SolidL, v12);
      Scaleform::Render::StrokerAA::addTriangle(this, this->TotalL, v12, v3);
      v13 = w;
    }
    if ( v13->aaFlagR )
    {
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, v62, v2a);
      Scaleform::Render::StrokerAA::addTriangle(this, this->SolidR, this->TotalR, v62);
    }
    this->SolidL = v12;
    this->TotalL = v3;
    this->SolidR = v2a;
    this->TotalR = v62;
    if ( pa )
    {
      pf = p->dy2SolidR + v1->y;
      v45 = pf;
      pg = p->dx2SolidR + v1->x;
      this->SolidR = Scaleform::Render::StrokerAA::addVertex(this, pg, v45, this->StyleRight, 1);
      if ( w->aaFlagR )
      {
        ph = p->dy2TotalR + v1->y;
        v46 = ph;
        pi = p->dx2TotalR + v1->x;
        v14 = Scaleform::Render::StrokerAA::addVertex(this, pi, v46, this->StyleRight, 0);
      }
      else
      {
        v14 = v2a;
      }
      this->TotalR = v14;
    }
    pb = atan2(-p->dy1TotalL, -p->dx1TotalL);
    v99 = atan2(-p->dy2TotalL, -p->dx2TotalL);
    v15 = v99;
    if ( v99 > (double)pb )
    {
      v2f = v15 - 6.283185482025146;
      v15 = v2f;
    }
    v16 = w;
    v86 = pb - v15;
    v100 = w->totalWidthL / (this->Tolerance * 0.25 + w->totalWidthL);
    v101 = acos(v100);
    v102 = v101 + v101;
    v17 = v86 / v102;
    v103 = (int)v17 + 1;
    v2b = v86 / (double)v103;
    pc = pb - v2b;
    if ( v103 > 0 )
    {
      v104 = (int)v17 + 1;
      do
      {
        v87 = cos(pc);
        v82 = v87;
        v88 = sin(pc);
        if ( v16->solidFlag )
        {
          v63 = v16->solidWidthL * v88 + v8->y;
          v47 = v63;
          v64 = v16->solidWidthL * v82 + v8->x;
          v12 = Scaleform::Render::StrokerAA::addVertex(this, v64, v47, this->StyleLeft, 1);
        }
        if ( v16->aaFlagL )
        {
          v89 = v16->totalWidthL * v88 + v8->y;
          v48 = v89;
          v90 = v16->totalWidthL * v82 + v8->x;
          v3a = Scaleform::Render::StrokerAA::addVertex(this, v90, v48, this->StyleLeft, 0);
        }
        else
        {
          v3a = v12;
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
          v25->v3 = v3a;
          ++this->Triangles.Size;
          v16 = w;
        }
        v7 = v104-- == 1;
        this->SolidL = v12;
        this->TotalL = v3a;
        pc = pc - v2b;
      }
      while ( !v7 );
    }
  }
}
