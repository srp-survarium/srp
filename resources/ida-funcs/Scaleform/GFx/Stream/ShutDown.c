void __thiscall Scaleform::GFx::Stream::ShutDown(Scaleform::GFx::Stream *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::String::Clear(&this->FileName);
  pObject = (Scaleform::RefCountVImpl *)this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pInput.pObject = 0;
  this->pLog = 0;
  this->pParseControl = 0;
}
