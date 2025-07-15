void __thiscall Scaleform::GFx::Stream::ShutDown(Scaleform::GFx::Stream *this)
{
  Scaleform::File *pObject; // ecx

  Scaleform::String::Clear(&this->FileName);
  pObject = this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->pInput.pObject = 0;
  this->pLog = 0;
  this->pParseControl = 0;
}
