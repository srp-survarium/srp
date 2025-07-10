Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::MeshKeySet::GetBounds(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  this->pDelegate->GetBounds(&this->pDelegate->Scaleform::Render::MeshProvider, result, m);
  return result;
}
