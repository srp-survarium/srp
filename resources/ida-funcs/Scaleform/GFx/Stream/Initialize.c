void __thiscall Scaleform::GFx::Stream::Initialize(
        Scaleform::GFx::Stream *this,
        Scaleform::GFx::Resource *pinput,
        Scaleform::Log *plog,
        Scaleform::GFx::ParseControl *pparseControl)
{
  Scaleform::File *pObject; // ecx
  unsigned int ParseFlags; // eax
  char *v7; // eax

  if ( pinput )
    Scaleform::RefCountImpl::AddRef(pinput);
  pObject = this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->pInput.pObject = (Scaleform::File *)pinput;
  this->pLog = plog;
  this->pParseControl = pparseControl;
  if ( pparseControl )
    ParseFlags = pparseControl->ParseFlags;
  else
    ParseFlags = 0;
  this->ParseFlags = ParseFlags;
  this->CurrentByte = 0;
  this->UnusedBits = 0;
  if ( pinput )
  {
    v7 = (char *)((int (__thiscall *)(Scaleform::GFx::Resource *))pinput->GetKey)(pinput);
    Scaleform::String::operator=(&this->FileName, v7);
  }
  else
  {
    Scaleform::String::Clear(&this->FileName);
  }
  this->TagStackEntryCount = 0;
  this->TagStack[0] = 0;
  this->TagStack[1] = 0;
  this->Pos = 0;
  this->DataSize = 0;
  this->ResyncFile = 0;
  if ( pinput )
    this->FilePos = ((int (__thiscall *)(Scaleform::GFx::Resource *))pinput->__vftable[1].~Scaleform::GFx::Resource)(pinput);
  else
    this->FilePos = 0;
}
