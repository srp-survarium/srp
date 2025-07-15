int __thiscall Scaleform::Render::MeshKeySet::HitTestShape(
        Scaleform::Render::MeshKeySet *this,
        const Scaleform::Render::Matrix2x4<float> *m,
        float x,
        float y,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  return ((int (__thiscall *)(Scaleform::Render::MeshProvider *, const Scaleform::Render::Matrix2x4<float> *, _DWORD, _DWORD, _DWORD, Scaleform::Render::StrokeGenerator *, const Scaleform::Render::ToleranceParams *))this->pDelegate->HitTestShape)(
           &this->pDelegate->Scaleform::Render::MeshProvider,
           m,
           LODWORD(x),
           LODWORD(y),
           LODWORD(morphRatio),
           gen,
           tol);
}
