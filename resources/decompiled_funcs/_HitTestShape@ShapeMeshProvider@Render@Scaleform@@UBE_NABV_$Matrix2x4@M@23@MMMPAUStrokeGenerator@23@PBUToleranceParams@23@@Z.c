char __thiscall Scaleform::Render::ShapeMeshProvider::HitTestShape(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  return Scaleform::Render::ShapeMeshProvider::HitTestShape(
           (Scaleform::Render::ShapeMeshProvider *)((char *)this - 8),
           m,
           x,
           y,
           morphRatio,
           gen,
           tol,
           0);
}
