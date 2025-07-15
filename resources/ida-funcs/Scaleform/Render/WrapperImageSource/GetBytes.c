unsigned int __thiscall Scaleform::Render::WrapperImageSource::GetBytes(
        Scaleform::Render::WrapperImageSource *this,
        int *memRegion)
{
  return this->pDelegate.pObject->GetBytes(this->pDelegate.pObject, memRegion);
}
