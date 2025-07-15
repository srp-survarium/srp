void __thiscall Scaleform::GFx::Stream::Stream(
        Scaleform::GFx::Stream *this,
        Scaleform::GFx::Resource *pinput,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Log *plog,
        Scaleform::GFx::ParseControl *pparseControl)
{
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::Stream::`vftable';
  this->pInput.pObject = 0;
  Scaleform::StringDH::StringDH(&this->FileName, pheap);
  this->pBuffer = this->BuiltinBuffer;
  this->BufferSize = 512;
  Scaleform::GFx::Stream::Initialize(this, pinput, plog, pparseControl);
}


void __thiscall Scaleform::GFx::Stream::Stream(
        Scaleform::GFx::Stream *this,
        unsigned __int8 *pbuffer,
        unsigned int bufSize,
        Scaleform::MemoryHeap *pheap,
        Scaleform::Log *plog,
        Scaleform::GFx::ParseControl *pparseControl)
{
  Scaleform::StringDH *p_FileName; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  unsigned int ParseFlags; // eax
  unsigned int BufferSize; // eax

  p_FileName = &this->FileName;
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::Stream::`vftable';
  this->pInput.pObject = 0;
  Scaleform::StringDH::StringDH(&this->FileName, pheap);
  this->pBuffer = pbuffer;
  if ( pbuffer )
    this->BufferSize = bufSize;
  else
    this->BufferSize = 0;
  pObject = (Scaleform::RefCountVImpl *)this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pInput.pObject = 0;
  this->pLog = plog;
  this->pParseControl = pparseControl;
  if ( pparseControl )
    ParseFlags = pparseControl->ParseFlags;
  else
    ParseFlags = 0;
  this->ParseFlags = ParseFlags;
  this->CurrentByte = 0;
  this->UnusedBits = 0;
  Scaleform::String::Clear(p_FileName);
  BufferSize = this->BufferSize;
  this->DataSize = BufferSize;
  this->FilePos = BufferSize;
  this->TagStackEntryCount = 0;
  this->TagStack[0] = 0;
  this->TagStack[1] = 0;
  this->Pos = 0;
  this->ResyncFile = 0;
}
