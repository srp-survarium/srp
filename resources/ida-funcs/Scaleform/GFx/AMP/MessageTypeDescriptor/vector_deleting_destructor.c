Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog> *__thiscall Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageImageRequest>::`vector deleting destructor'(
        Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog> *this,
        char a2)
{
  volatile LONG *v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  v3 = (volatile LONG *)(this->MessageTypeName.HeapTypeBits & 0xFFFFFFFC);
  this->__vftable = (Scaleform::GFx::AMP::MessageTypeDescriptor<Scaleform::GFx::AMP::MessageLog>_vtbl *)&Scaleform::GFx::AMP::BaseMessageTypeDescriptor::`vftable';
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  pObject = (Scaleform::RefCountVImpl *)this->MessageHandler.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
