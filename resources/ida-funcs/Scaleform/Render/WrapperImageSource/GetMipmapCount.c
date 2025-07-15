unsigned int __thiscall Scaleform::Render::WrapperImageSource::GetMipmapCount(
        Scaleform::Render::WrapperImageSource *this)
{
  return this->pDelegate.pObject->GetMipmapCount(this->pDelegate.pObject);
}
