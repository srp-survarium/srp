void __thiscall Scaleform::GFx::Stream::~Stream(Scaleform::GFx::Stream *this)
{
  volatile LONG *v2; // edi
  Scaleform::File *pObject; // ecx

  v2 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::Stream::`vftable';
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  pObject = this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
}
