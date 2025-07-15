unsigned int __thiscall Scaleform::Render::Hairliner::addJoin(
        Scaleform::Render::Hairliner *this,
        unsigned int refVertex,
        const Scaleform::Render::TessVertex *v1,
        float v2,
        float v3,
        float len1,
        float len2,
        float width)
{
  float *v8; // ebx
  const Scaleform::Render::TessVertex *v9; // ebp
  float *v10; // esi
  double v12; // st7
  double v13; // st7
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_OutVertices; // esi
  unsigned int v15; // edi
  int v16; // eax
  float y; // edx
  unsigned int alpha; // ecx
  double v20; // st6
  unsigned int Size; // eax
  unsigned int v22; // eax
  float ay; // [esp+4h] [ebp-80h]
  float by; // [esp+Ch] [ebp-78h]
  float cy; // [esp+14h] [ebp-70h]
  float v26; // [esp+18h] [ebp-6Ch]
  float dy; // [esp+1Ch] [ebp-68h]
  float v28; // [esp+28h] [ebp-5Ch]
  float yi; // [esp+3Ch] [ebp-48h] BYREF
  float dx1; // [esp+40h] [ebp-44h]
  float dx2; // [esp+44h] [ebp-40h]
  float turn; // [esp+48h] [ebp-3Ch]
  float v33; // [esp+4Ch] [ebp-38h]
  float v34; // [esp+50h] [ebp-34h]
  float d1; // [esp+54h] [ebp-30h]
  float epsilon; // [esp+58h] [ebp-2Ch]
  double v37; // [esp+5Ch] [ebp-28h]
  double v38; // [esp+64h] [ebp-20h]
  Scaleform::Render::Hairliner::OutVertexType o1; // [esp+6Ch] [ebp-18h] BYREF
  Scaleform::Render::Hairliner::TriangleType tri; // [esp+78h] [ebp-Ch] BYREF

  v8 = (float *)LODWORD(v3);
  v9 = v1;
  v10 = (float *)LODWORD(v2);
  turn = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
           v1,
           (const Scaleform::Render::TessVertex *)LODWORD(v2),
           (const Scaleform::Render::TessVertex *)LODWORD(v3),
           len1,
           len2);
  tri.v3 = 0;
  o1.alpha = 0;
  epsilon = (len1 + len2) * this->IntersectionEpsilon;
  dx1 = (v9->y - v10[1]) * width / len1;
  v3 = (*v10 - v9->x) * width / len1;
  dx2 = (v10[1] - v8[1]) * width / len2;
  v2 = width * (*v8 - *v10) / len2;
  v1 = *(const Scaleform::Render::TessVertex **)v10;
  yi = v10[1];
  d1 = fabs(turn);
  if ( d1 >= 0.125 )
  {
    v38 = *v10 + dx2;
    v34 = v38;
    v37 = *v10 + dx1;
    v33 = v37;
    v28 = epsilon;
    epsilon = v8[1] + v2;
    dy = epsilon;
    epsilon = dx2 + *v8;
    v26 = epsilon;
    epsilon = v2 + v10[1];
    cy = epsilon;
    epsilon = v10[1] + v3;
    by = epsilon;
    epsilon = v3 + v9->y;
    ay = epsilon;
    epsilon = dx1 + v9->x;
    if ( Scaleform::Render::Math2D::Intersection(epsilon, ay, v33, by, v34, cy, v26, dy, (float *)&v1, &yi, v28) )
    {
      d1 = *(float *)&v1 - *v10;
      epsilon = yi - v10[1];
      epsilon = epsilon * epsilon + d1 * d1;
      epsilon = sqrt(epsilon);
      d1 = epsilon;
      if ( turn > 0.0 )
      {
        v20 = len1;
        if ( len2 <= (double)len1 )
          v20 = len2;
        len1 = v20;
        len1 = len1 / turn;
        if ( len1 < (double)d1 )
        {
          o1.x = v33;
          o1.y = v10[1] + v3;
          *(float *)&tri.v1 = v34;
          *(float *)&tri.v2 = v10[1] + v2;
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
            (const Scaleform::Render::Tessellator::MonoVertexType *)&o1);
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
            (const Scaleform::Render::Tessellator::MonoVertexType *)&tri);
          return 2;
        }
        goto LABEL_16;
      }
      len1 = -width * 4.0;
      if ( len1 >= (double)d1 )
      {
LABEL_16:
        o1.x = *(float *)&v1;
        o1.y = yi;
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
          (const Scaleform::Render::Tessellator::MonoVertexType *)&o1);
        return 1;
      }
      o1.x = v37 - v3 * 2.0;
      o1.y = v3 + v10[1] + dx1 * 2.0;
      *(float *)&tri.v1 = v2 * 2.0 + v38;
      *(float *)&tri.v2 = v2 + v10[1] - 2.0 * dx2;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        (const Scaleform::Render::Tessellator::MonoVertexType *)&o1);
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        (const Scaleform::Render::Tessellator::MonoVertexType *)&tri);
      Size = this->OutVertices.Size;
      tri.v3 = Size - 1;
      tri.v1 = refVertex;
      tri.v2 = Size - 2;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        (const Scaleform::Render::Tessellator::MonoVertexType *)&tri);
    }
    else
    {
      o1.x = v37 - v3;
      o1.y = v3 + v10[1] + dx1;
      *(float *)&tri.v1 = v38 + v2;
      *(float *)&tri.v2 = v2 + v10[1] - dx2;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        (const Scaleform::Render::Tessellator::MonoVertexType *)&o1);
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        (const Scaleform::Render::Tessellator::MonoVertexType *)&tri);
      tri.v1 = refVertex;
      v22 = this->OutVertices.Size;
      tri.v2 = v22 - 2;
      tri.v3 = v22 - 1;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        (const Scaleform::Render::Tessellator::MonoVertexType *)&tri);
    }
    return 2;
  }
  v12 = *v10;
  if ( len2 >= (double)len1 )
  {
    o1.x = v12 + dx2;
    v13 = v10[1] + v2;
  }
  else
  {
    o1.x = v12 + dx1;
    v13 = v10[1] + v3;
  }
  p_OutVertices = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices;
  o1.y = v13;
  v15 = this->OutVertices.Size >> 4;
  if ( v15 >= p_OutVertices->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(p_OutVertices, v15);
  v16 = (int)&p_OutVertices->Pages[v15][p_OutVertices->Size & 0xF];
  y = o1.y;
  *(float *)v16 = o1.x;
  alpha = o1.alpha;
  *(float *)(v16 + 4) = y;
  *(_DWORD *)(v16 + 8) = alpha;
  ++p_OutVertices->Size;
  return 1;
}
