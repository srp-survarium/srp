Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::MeshKeySet::GetCorrectBounds(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m,
        float morphRatio,
        Scaleform::Render::StrokeGenerator *gen,
        const Scaleform::Render::ToleranceParams *tol)
{
  ((void (__stdcall *)(Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *, _DWORD, Scaleform::Render::StrokeGenerator *, const Scaleform::Render::ToleranceParams *))this->pDelegate->GetCorrectBounds)(
    result,
    m,
    LODWORD(morphRatio),
    gen,
    tol);
  return result;
}
