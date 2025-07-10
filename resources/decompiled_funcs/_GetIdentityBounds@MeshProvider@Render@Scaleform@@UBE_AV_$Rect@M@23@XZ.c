Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::MeshProvider::GetIdentityBounds(
        Scaleform::Render::MeshProvider *this,
        Scaleform::Render::Rect<float> *result)
{
  this->GetBounds(this, result, &Scaleform::Render::Matrix2x4<float>::Identity);
  return result;
}
