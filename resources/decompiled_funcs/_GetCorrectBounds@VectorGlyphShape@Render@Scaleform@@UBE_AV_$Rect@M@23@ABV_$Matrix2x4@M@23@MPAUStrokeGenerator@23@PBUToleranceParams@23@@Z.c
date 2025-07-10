Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::VectorGlyphShape::GetCorrectBounds(
        Scaleform::Render::VectorGlyphShape *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::Rect<float> *v6; // eax

  v6 = result;
  result->x1 = *(float *)&this->pShape.pObject;
  result->y1 = *(float *)&this->pRaster.pObject;
  result->x2 = this->Bounds.x1;
  result->y2 = this->Bounds.y1;
  return v6;
}
