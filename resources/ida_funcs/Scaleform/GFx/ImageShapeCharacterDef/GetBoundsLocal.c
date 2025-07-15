Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::ImageShapeCharacterDef::GetBoundsLocal(
        Scaleform::GFx::ImageShapeCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float __formal)
{
  this->pShapeMeshProvider.pObject->GetIdentityBounds(
    &this->pShapeMeshProvider.pObject->Scaleform::Render::MeshProvider,
    result);
  return result;
}
