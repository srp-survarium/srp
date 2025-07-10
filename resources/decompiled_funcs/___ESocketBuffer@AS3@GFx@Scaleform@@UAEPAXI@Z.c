Scaleform::GFx::AS3::SocketBuffer *__thiscall Scaleform::GFx::AS3::SocketBuffer::`vector deleting destructor'(
        Scaleform::GFx::AS3::SocketBuffer *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data.Data.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
