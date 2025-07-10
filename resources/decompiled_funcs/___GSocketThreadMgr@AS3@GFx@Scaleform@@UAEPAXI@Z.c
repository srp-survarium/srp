Scaleform::GFx::AS3::SocketThreadMgr *__thiscall Scaleform::GFx::AS3::SocketThreadMgr::`scalar deleting destructor'(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        char a2)
{
  Scaleform::GFx::AS3::SocketThreadMgr::~SocketThreadMgr(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
