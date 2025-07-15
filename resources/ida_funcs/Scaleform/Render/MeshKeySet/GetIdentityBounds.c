Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::MeshKeySet::GetIdentityBounds(
        Scaleform::Render::MeshKeySet *this,
        Scaleform::Render::Rect<float> *result)
{
  this->pDelegate->GetIdentityBounds(&this->pDelegate->Scaleform::Render::MeshProvider, result);
  return result;
}
