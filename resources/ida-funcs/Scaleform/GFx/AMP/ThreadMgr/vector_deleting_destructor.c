Scaleform::GFx::AMP::ThreadMgr *__thiscall Scaleform::GFx::AMP::ThreadMgr::`vector deleting destructor'(
        Scaleform::GFx::AMP::ThreadMgr *this,
        char a2)
{
  Scaleform::GFx::AMP::ThreadMgr::~ThreadMgr(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
