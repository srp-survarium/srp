Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::VectorGlyphShape::GetBounds(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::Rect<float> *v3; // eax

  v3 = result;
  result->x1 = *(float *)&this->pShape.pObject;
  result->y1 = *(float *)&this->pRaster.pObject;
  result->x2 = this->Bounds.x1;
  result->y2 = this->Bounds.y1;
  return v3;
}
