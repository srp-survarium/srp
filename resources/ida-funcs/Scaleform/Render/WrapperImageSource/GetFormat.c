Scaleform::Render::ImageFormat __thiscall Scaleform::Render::WrapperImageSource::GetFormat(
        Scaleform::Render::WrapperImageSource *this)
{
  return this->pDelegate.pObject->GetFormat(this->pDelegate.pObject);
}
