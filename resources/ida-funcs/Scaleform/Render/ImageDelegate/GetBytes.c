unsigned int __thiscall Scaleform::Render::ImageDelegate::GetBytes(
        Scaleform::Render::ImageDelegate *this,
        int *memRegion)
{
  return this->pImage.pObject->GetBytes(this->pImage.pObject, memRegion);
}
