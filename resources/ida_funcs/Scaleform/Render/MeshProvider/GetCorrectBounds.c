Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::MeshProvider::GetCorrectBounds(
        Scaleform::Render::MeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  Scaleform::Render::Rect<float> *v6; // eax

  v6 = result;
  result->x1 = 0.0;
  result->y1 = 0.0;
  result->x2 = 0.0;
  result->y2 = 0.0;
  return v6;
}
