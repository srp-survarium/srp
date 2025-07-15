unsigned int __thiscall Scaleform::Render::Hairliner::processHorizontalEdges(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::Hairliner::MonoChainType *mc,
        unsigned int vertex,
        float yb)
{
  unsigned int v5; // ecx
  double v6; // st7
  unsigned int v7; // esi
  Scaleform::Render::Hairliner::HorizontalEdgeType *v8; // ebp
  unsigned int rv; // ecx
  bool v10; // zf
  Scaleform::Render::Hairliner::SrcEdgeType *edge; // ecx
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // edx
  float *p_x; // edx
  double v14; // st6
  Scaleform::Render::Hairliner::SrcVertexType *v15; // edx
  double v16; // st6
  unsigned int v17; // eax
  char v19; // [esp+7h] [ebp-19h]
  float v20; // [esp+8h] [ebp-18h]
  unsigned int v21; // [esp+Ch] [ebp-14h]
  Scaleform::Render::Hairliner::SrcVertexType v1; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::Hairliner::SrcVertexType v23; // [esp+18h] [ebp-8h] BYREF
  float *v2; // [esp+28h] [ebp+8h]

  v20 = 0.0;
  v5 = 0;
  v19 = 0;
  v21 = 0;
  if ( this->NumHorizontals )
  {
    v6 = yb;
    v7 = vertex;
    while ( 1 )
    {
      v8 = &this->HorizontalEdges.Pages[(v5 + this->StartHorizontals) >> 2][(v5 + this->StartHorizontals) & 3];
      if ( v7 != -1 )
      {
        rv = v8->rv;
        if ( rv == -1 && this->OutVertices.Pages[v7 >> 4][v7 & 0xF].x == v8->x1 )
        {
          v8->lv = v7;
          v8->rv = v7;
          goto LABEL_32;
        }
        if ( this->OutVertices.Pages[v7 >> 4][v7 & 0xF].x == v8->x2 )
        {
          if ( rv != -1 && rv != v7 )
          {
            Scaleform::Render::Hairliner::emitEdge(this, rv, v7);
            goto LABEL_11;
          }
          goto LABEL_12;
        }
      }
      if ( !v19 )
      {
        edge = mc->edge;
        Pages = this->SrcVertices.Pages;
        v2 = &Pages[mc->edge->lower >> 4][mc->edge->lower & 0xF].x;
        p_x = &Pages[mc->edge->upper >> 4][mc->edge->upper & 0xF].x;
        if ( v2[1] == v6 )
        {
          v14 = *v2;
        }
        else if ( p_x[1] == v6 )
        {
          v14 = *p_x;
        }
        else
        {
          v15 = this->SrcVertices.Pages[edge->lower >> 4];
          v14 = (v6 - v15[edge->lower & 0xF].y) * edge->slope + v15[edge->lower & 0xF].x;
        }
        v20 = v14;
        v19 = 1;
      }
      v16 = v20;
      if ( v8->x1 == v20 )
      {
        v1.x = v20;
        v1.y = v6;
        if ( v7 == -1 )
        {
          v6 = yb;
          v7 = Scaleform::Render::Hairliner::addEventVertex(this, &v1);
        }
        v8->rv = v7;
        goto LABEL_32;
      }
      if ( v8->x1 <= v16 && v8->x2 >= v16 )
      {
        v23.x = v20;
        v23.y = v6;
        if ( v7 == -1 )
        {
          v6 = yb;
          v7 = Scaleform::Render::Hairliner::addEventVertex(this, &v23);
        }
        v17 = v8->rv;
        if ( v17 != -1 && v17 != v7 )
        {
          Scaleform::Render::Hairliner::emitEdge(this, v17, v7);
LABEL_11:
          v6 = yb;
        }
LABEL_12:
        v10 = v8->lv == -1;
        v8->rv = v7;
        if ( v10 )
          v8->lv = v7;
      }
LABEL_32:
      v5 = v21 + 1;
      v21 = v5;
      if ( v5 >= this->NumHorizontals )
        return v7;
    }
  }
  return vertex;
}
