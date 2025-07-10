Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::VectorGlyphShape::GetIdentityBounds(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  result->x1 = *(float *)&this->pShape.pObject;
  result->y1 = *(float *)&this->pRaster.pObject;
  result->x2 = this->Bounds.x1;
  result->y2 = this->Bounds.y1;
  return v2;
}
