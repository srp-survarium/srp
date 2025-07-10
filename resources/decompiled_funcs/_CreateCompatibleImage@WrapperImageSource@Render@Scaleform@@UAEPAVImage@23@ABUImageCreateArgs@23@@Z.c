Scaleform::Render::Image *__thiscall Scaleform::Render::WrapperImageSource::CreateCompatibleImage(
        Scaleform::Render::WrapperImageSource *this,
        const Scaleform::Render::ImageCreateArgs *args)
{
  if ( !this->IsDecodeOnlyImageCompatible(this, args) )
    return Scaleform::Render::ImageSource::CreateCompatibleImage(this, args);
  this->pDelegate.pObject->AddRef(this->pDelegate.pObject);
  return this->pDelegate.pObject;
}
