Scaleform::GFx::Stream *__thiscall Scaleform::GFx::Stream::`scalar deleting destructor'(
        Scaleform::GFx::Stream *this,
        char a2)
{
  volatile LONG *v3; // edi
  Scaleform::File *pObject; // ecx

  v3 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::Stream::`vftable';
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  pObject = this->pInput.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  this->__vftable = (Scaleform::GFx::Stream_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
