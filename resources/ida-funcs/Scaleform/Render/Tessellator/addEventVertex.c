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
  double v10; // st7
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
  Scaleform::Render::TessVertex v2; // [esp+Ch] [ebp-14h] BYREF
  float x; // [esp+2Ch] [ebp+Ch]
  float xa; // [esp+2Ch] [ebp+Ch]
  float xb; // [esp+2Ch] [ebp+Ch]

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
      v10 = v8[v9].x;
      p_x = &v8[v9].x;
      if ( this->LastX < v10 )
      {
        x = *p_x;
        v2.Styles[1] = -1;
        this->LastX = x;
        v2.Idx = -1;
        v2.x = x;
        v2.Flags = 2;
        v12 = p_x[1];
        v2.Styles[0] = -1;
        v2.y = v12;
        v2.Mesh = 0;
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &v2);
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
      v2.x = v21;
      v2.Idx = -1;
      v2.y = v20[1];
      v2.Styles[1] = -1;
      v2.Styles[0] = -1;
      v2.Mesh = 0;
      v2.Flags = 2;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &v2);
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
    xa = (v16 - v15[lower >> 4][lower & 0xF].y) * v5->slope + v15[lower >> 4][lower & 0xF].x;
    v23 = xa;
    v24 = xa - this->LastX;
    xb = fabs(v16);
    if ( xb * this->Epsilon < v24 )
    {
      this->LastX = v23;
      v2.x = v23;
      v2.Styles[0] = -1;
      v2.y = yb;
      v2.Styles[1] = -1;
      v2.Idx = -1;
      v2.Flags = 2;
      v2.Mesh = 0;
      Scaleform::Render::ArrayPaged<Scaleform::Render::TessVertex,4,16>::PushBack(&this->MeshVertices, &v2);
      return this->MeshVertices.Size - 1;
    }
  }
  return this->MeshVertices.Size - 1;
}
