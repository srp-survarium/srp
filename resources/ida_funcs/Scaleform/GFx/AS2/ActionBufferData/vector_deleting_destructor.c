Scaleform::GFx::AS2::ActionBufferData *__thiscall Scaleform::GFx::AS2::ActionBufferData::`vector deleting destructor'(
        Scaleform::GFx::AS2::ActionBufferData *this,
        char a2)
{
  unsigned __int8 *pBuffer; // eax

  pBuffer = this->pBuffer;
  this->__vftable = (Scaleform::GFx::AS2::ActionBufferData_vtbl *)&Scaleform::GFx::AS2::ActionBufferData::`vftable';
  if ( pBuffer )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pBuffer);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
