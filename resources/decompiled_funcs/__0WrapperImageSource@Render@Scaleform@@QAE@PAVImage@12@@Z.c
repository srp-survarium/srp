void __thiscall Scaleform::Render::WrapperImageSource::WrapperImageSource(
        Scaleform::Render::WrapperImageSource *this,
        Scaleform::Render::Image *pdelegate)
{
  this->__vftable = (Scaleform::Render::WrapperImageSource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::Render::WrapperImageSource_vtbl *)&Scaleform::Render::WrapperImageSource::`vftable';
  if ( pdelegate )
    pdelegate->AddRef(pdelegate);
  this->pDelegate.pObject = pdelegate;
}
