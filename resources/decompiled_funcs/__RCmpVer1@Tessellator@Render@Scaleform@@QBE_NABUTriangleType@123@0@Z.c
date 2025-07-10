BOOL __thiscall Scaleform::Render::Tessellator::CmpVer1::operator()(
        Scaleform::Render::Tessellator::CmpVer1 *this,
        const Scaleform::Render::Tessellator::TriangleType *a,
        const Scaleform::Render::Tessellator::TriangleType *b)
{
  Scaleform::Render::TessVertex **Pages; // ecx
  Scaleform::Render::TessVertex *v4; // edx
  double y; // st7
  float *p_x; // edx
  Scaleform::Render::TessVertex *v7; // ecx
  double v8; // st6
  float *v9; // ecx
  double v10; // st7
  double v11; // st6

  Pages = this->Ver->Pages;
  v4 = Pages[a->d.t.v1 >> 4];
  y = v4[a->d.t.v1 & 0xF].y;
  p_x = &v4[a->d.t.v1 & 0xF].x;
  v7 = Pages[b->d.t.v1 >> 4];
  v8 = v7[b->d.t.v1 & 0xF].y;
  v9 = &v7[b->d.t.v1 & 0xF].x;
  if ( v8 == y )
  {
    v10 = *p_x;
    v11 = *v9;
  }
  else
  {
    v10 = p_x[1];
    v11 = v9[1];
  }
  return v11 > v10;
}
