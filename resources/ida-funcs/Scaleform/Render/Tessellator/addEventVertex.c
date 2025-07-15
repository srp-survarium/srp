unsigned int __thiscall Scaleform::Render::Tessellator::addEventVertex(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::Tessellator::MonoChainType *mc,
        float yb,
        bool enforceFlag)
{
  Scaleform::Render::Tessellator::EdgeType *v5; // ebx
  unsigned __int16 flags; // ax
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v8; // edx
  int v9; // ecx
  double x; // st7
  float *p_x; // ecx
  double v12; // st7
  unsigned int lower; // ecx
  Scaleform::Render::Tessellator::SrcVertexType **v15; // edi
  long double v16; // st7
  Scaleform::Render::Tessellator::SrcVertexType *v17; // eax
  int v18; // ecx
  double v19; // st7
  float *v20; // ecx
  double v21; // st7
  unsigned int v22; // edx
  double v23; // st6
  double v24; // st5
  Scaleform::Render::TessVertex val; // [esp+Ch] [ebp-14h] BYREF
  float v26; // [esp+2Ch] [ebp+Ch]
  float v27; // [esp+2Ch] [ebp+Ch]
  float v28; // [esp+2Ch] [ebp+Ch]

  v5 = &this->Edges.Pages[mc->edge >> 4][mc->edge & 0xF];
  if ( !enforceFlag )
  {
    flags = mc->flags;
    if ( (flags & 0x10) == 0 && mc->leftBelow == mc->leftAbove && mc->rightBelow == mc->rightAbove )
    {
      if ( (flags & 8) == 0 )
        return -1;
      Pages = this->SrcVertices.Pages;
      if ( yb != Pages[v5->lower >> 4][v5->lower & 0xF].y )
        return -1;
      v8 = Pages[v5->lower >> 4];
      v9 = v5->lower & 0xF;
      x = v8[v9].x;
      p_x = &v8[v9].x;
      if ( this->LastX < x )
      {
        v26 = *p_x;
        val.Styles[1] = -1;
        this->LastX = v26;
        val.Idx = -1;
        val.x = v26;
        val.Flags = 2;
        v12 = p_x[1];
        val.Styles[0] = -1;
        val.y = v12;
        val.Mesh = 0;
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &val);
        return this->MeshVertices.Size - 1;
      }
      return this->MeshVertices.Size - 1;
    }
  }
  lower = v5->lower;
  v15 = this->SrcVertices.Pages;
  v16 = yb;
  if ( yb == v15[v5->lower >> 4][v5->lower & 0xF].y )
  {
    v17 = v15[lower >> 4];
    v18 = v5->lower & 0xF;
    v19 = v17[v18].x;
    v20 = &v17[v18].x;
    if ( this->LastX < v19 )
    {
      v21 = *v20;
LABEL_13:
      this->LastX = v21;
      val.x = v21;
      val.Idx = -1;
      val.y = v20[1];
      val.Styles[1] = -1;
      val.Styles[0] = -1;
      val.Mesh = 0;
      val.Flags = 2;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &val);
      return this->MeshVertices.Size - 1;
    }
  }
  else if ( (mc->flags & 2) != 0 && (v22 = mc->dir + lower, v16 == v15[v22 >> 4][v22 & 0xF].y) )
  {
    v20 = &v15[v22 >> 4][v22 & 0xF].x;
    if ( this->LastX < (double)*v20 )
    {
      v21 = *v20;
      goto LABEL_13;
    }
  }
  else
  {
    v27 = (v16 - v15[lower >> 4][lower & 0xF].y) * v5->slope + v15[lower >> 4][lower & 0xF].x;
    v23 = v27;
    v24 = v27 - this->LastX;
    v28 = fabs(v16);
    if ( v28 * this->Epsilon < v24 )
    {
      this->LastX = v23;
      val.x = v23;
      val.Styles[0] = -1;
      val.y = yb;
      val.Styles[1] = -1;
      val.Idx = -1;
      val.Flags = 2;
      val.Mesh = 0;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &val);
      return this->MeshVertices.Size - 1;
    }
  }
  return this->MeshVertices.Size - 1;
}
