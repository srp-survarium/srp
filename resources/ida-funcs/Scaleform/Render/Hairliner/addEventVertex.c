unsigned int __thiscall Scaleform::Render::Hairliner::addEventVertex(
        Scaleform::Render::Hairliner *this,
        const Scaleform::Render::Hairliner::SrcVertexType *v1)
{
  unsigned int v3; // edi
  Scaleform::Render::Hairliner::OutVertexType *v4; // eax
  float v2; // [esp+4h] [ebp-Ch]
  float v2_4; // [esp+8h] [ebp-8h]

  if ( this->LastY != v1->y || this->LastX != v1->x )
  {
    *(Scaleform::Render::Hairliner::SrcVertexType *)&this->LastX = *v1;
    v2 = v1->x;
    v3 = this->OutVertices.Size >> 4;
    v2_4 = v1->y;
    if ( v3 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        v3);
    v4 = &this->OutVertices.Pages[v3][this->OutVertices.Size & 0xF];
    v4->x = v2;
    v4->y = v2_4;
    v4->alpha = 1;
    ++this->OutVertices.Size;
  }
  return this->OutVertices.Size - 1;
}


unsigned int __thiscall Scaleform::Render::Hairliner::addEventVertex(
        Scaleform::Render::Hairliner *this,
        const Scaleform::Render::Hairliner::MonoChainType *mc,
        float yb,
        bool enforce)
{
  Scaleform::Render::Hairliner::SrcVertexType **v5; // edx
  double v7; // st7
  Scaleform::Render::Hairliner::SrcVertexType **v8; // edx
  unsigned int lower; // ecx
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // edi
  double v11; // st6
  Scaleform::Render::Hairliner::OutVertexType v2; // [esp+8h] [ebp-Ch] BYREF
  float x; // [esp+20h] [ebp+Ch]
  float xa; // [esp+20h] [ebp+Ch]
  float xb; // [esp+20h] [ebp+Ch]

  if ( enforce )
  {
    v7 = yb;
    if ( (mc->flags & 1) != 0 && (v8 = this->SrcVertices.Pages, v7 == v8[mc->edge->upper >> 4][mc->edge->upper & 0xF].y) )
    {
      return Scaleform::Render::Hairliner::addEventVertex(this, &v8[mc->edge->upper >> 4][mc->edge->upper & 0xF]);
    }
    else
    {
      lower = mc->edge->lower;
      Pages = this->SrcVertices.Pages;
      if ( v7 == Pages[lower >> 4][lower & 0xF].y )
      {
        return Scaleform::Render::Hairliner::addEventVertex(this, &Pages[lower >> 4][lower & 0xF]);
      }
      else
      {
        x = (v7 - Pages[lower >> 4][lower & 0xF].y) * mc->edge->slope + Pages[lower >> 4][lower & 0xF].x;
        v11 = x;
        if ( this->LastY == v7 )
        {
          xa = v11 - this->LastX;
          xb = fabs(xa);
          if ( this->Epsilon < (double)xb )
          {
            this->LastX = v11;
            v2.x = v11;
            this->LastY = yb;
            v2.alpha = 1;
            v2.y = yb;
            Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
              (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
              (const Scaleform::Render::Tessellator::MonoVertexType *)&v2);
          }
          return this->OutVertices.Size - 1;
        }
        else
        {
          this->LastX = x;
          v2.x = x;
          this->LastY = yb;
          v2.alpha = 1;
          v2.y = yb;
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
            (const Scaleform::Render::Tessellator::MonoVertexType *)&v2);
          return this->OutVertices.Size - 1;
        }
      }
    }
  }
  else if ( (mc->flags & 2) != 0
         && (v5 = this->SrcVertices.Pages, yb == v5[mc->edge->lower >> 4][mc->edge->lower & 0xF].y) )
  {
    return Scaleform::Render::Hairliner::addEventVertex(this, &v5[mc->edge->lower >> 4][mc->edge->lower & 0xF]);
  }
  else
  {
    return -1;
  }
}
