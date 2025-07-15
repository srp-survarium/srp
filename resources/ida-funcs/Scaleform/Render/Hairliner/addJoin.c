unsigned int __thiscall Scaleform::Render::Hairliner::addJoin(
        Scaleform::Render::Hairliner *this,
        unsigned int refVertex,
        Scaleform::Render::TessVertex *v1,
        Scaleform::Render::TessVertex *v2,
        Scaleform::Render::TessVertex *v3,
        float len1,
        float len2,
        float width)
{
  Scaleform::Render::TessVertex *v8; // ebx
  Scaleform::Render::TessVertex *v9; // ebp
  Scaleform::Render::TessVertex *v10; // esi
  double x; // st7
  double v13; // st7
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_OutVertices; // esi
  unsigned int v15; // edi
  Scaleform::Render::Tessellator::MonoVertexType *v16; // eax
  unsigned int aaVer; // edx
  Scaleform::Render::Tessellator::MonoVertexType *next; // ecx
  double v20; // st6
  unsigned int Size; // eax
  unsigned int v22; // eax
  float ay; // [esp+4h] [ebp-80h]
  float by; // [esp+Ch] [ebp-78h]
  float cy; // [esp+14h] [ebp-70h]
  float v26; // [esp+18h] [ebp-6Ch]
  float dy; // [esp+1Ch] [ebp-68h]
  float len2a; // [esp+28h] [ebp-5Ch]
  unsigned int y; // [esp+3Ch] [ebp-48h] BYREF
  float v30; // [esp+40h] [ebp-44h]
  float v31; // [esp+44h] [ebp-40h]
  float v32; // [esp+48h] [ebp-3Ch]
  float v33; // [esp+4Ch] [ebp-38h]
  float v34; // [esp+50h] [ebp-34h]
  float v35; // [esp+54h] [ebp-30h]
  float v36; // [esp+58h] [ebp-2Ch]
  double v37; // [esp+5Ch] [ebp-28h]
  double v38; // [esp+64h] [ebp-20h]
  Scaleform::Render::Tessellator::MonoVertexType val; // [esp+6Ch] [ebp-18h] BYREF
  Scaleform::Render::Tessellator::MonoVertexType v40; // [esp+78h] [ebp-Ch] BYREF

  v8 = v3;
  v9 = v1;
  v10 = v2;
  v32 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
          v1,
          v2,
          v3,
          len1,
          len2);
  v40.next = 0;
  val.next = 0;
  v36 = (len1 + len2) * this->IntersectionEpsilon;
  v30 = (v9->y - v10->y) * width / len1;
  *(float *)&v3 = (v10->x - v9->x) * width / len1;
  v31 = (v10->y - v8->y) * width / len2;
  *(float *)&v2 = width * (v8->x - v10->x) / len2;
  v1 = (Scaleform::Render::TessVertex *)LODWORD(v10->x);
  y = LODWORD(v10->y);
  v35 = fabs(v32);
  if ( v35 >= 0.125 )
  {
    v38 = v10->x + v31;
    v34 = v38;
    v37 = v10->x + v30;
    v33 = v37;
    len2a = v36;
    v36 = v8->y + *(float *)&v2;
    dy = v36;
    v36 = v31 + v8->x;
    v26 = v36;
    v36 = *(float *)&v2 + v10->y;
    cy = v36;
    v36 = v10->y + *(float *)&v3;
    by = v36;
    v36 = *(float *)&v3 + v9->y;
    ay = v36;
    v36 = v30 + v9->x;
    if ( Scaleform::Render::Math2D::Intersection(v36, ay, v33, by, v34, cy, v26, dy, (float *)&v1, (float *)&y, len2a) )
    {
      v35 = *(float *)&v1 - v10->x;
      v36 = *(float *)&y - v10->y;
      v36 = v36 * v36 + v35 * v35;
      v36 = sqrt(v36);
      v35 = v36;
      if ( v32 > 0.0 )
      {
        v20 = len1;
        if ( len2 <= (double)len1 )
          v20 = len2;
        len1 = v20;
        len1 = len1 / v32;
        if ( len1 < (double)v35 )
        {
          *(float *)&val.srcVer = v33;
          *(float *)&val.aaVer = v10->y + *(float *)&v3;
          *(float *)&v40.srcVer = v34;
          *(float *)&v40.aaVer = v10->y + *(float *)&v2;
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
            &val);
          Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
            (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
            &v40);
          return 2;
        }
        goto LABEL_16;
      }
      len1 = -width * 4.0;
      if ( len1 >= (double)v35 )
      {
LABEL_16:
        val.srcVer = (unsigned int)v1;
        val.aaVer = y;
        Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
          &val);
        return 1;
      }
      *(float *)&val.srcVer = v37 - *(float *)&v3 * 2.0;
      *(float *)&val.aaVer = *(float *)&v3 + v10->y + v30 * 2.0;
      *(float *)&v40.srcVer = *(float *)&v2 * 2.0 + v38;
      *(float *)&v40.aaVer = *(float *)&v2 + v10->y - 2.0 * v31;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        &val);
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        &v40);
      Size = this->OutVertices.Size;
      v40.next = (Scaleform::Render::Tessellator::MonoVertexType *)(Size - 1);
      v40.srcVer = refVertex;
      v40.aaVer = Size - 2;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        &v40);
    }
    else
    {
      *(float *)&val.srcVer = v37 - *(float *)&v3;
      *(float *)&val.aaVer = *(float *)&v3 + v10->y + v30;
      *(float *)&v40.srcVer = v38 + *(float *)&v2;
      *(float *)&v40.aaVer = *(float *)&v2 + v10->y - v31;
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        &val);
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        &v40);
      v40.srcVer = refVertex;
      v22 = this->OutVertices.Size;
      v40.aaVer = v22 - 2;
      v40.next = (Scaleform::Render::Tessellator::MonoVertexType *)(v22 - 1);
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::OutVertexType,4,16>::PushBack(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
        &v40);
    }
    return 2;
  }
  x = v10->x;
  if ( len2 >= (double)len1 )
  {
    *(float *)&val.srcVer = x + v31;
    v13 = v10->y + *(float *)&v2;
  }
  else
  {
    *(float *)&val.srcVer = x + v30;
    v13 = v10->y + *(float *)&v3;
  }
  p_OutVertices = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices;
  *(float *)&val.aaVer = v13;
  v15 = this->OutVertices.Size >> 4;
  if ( v15 >= p_OutVertices->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(p_OutVertices, v15);
  v16 = &p_OutVertices->Pages[v15][p_OutVertices->Size & 0xF];
  aaVer = val.aaVer;
  v16->srcVer = val.srcVer;
  next = val.next;
  v16->aaVer = aaVer;
  v16->next = next;
  ++p_OutVertices->Size;
  return 1;
}
