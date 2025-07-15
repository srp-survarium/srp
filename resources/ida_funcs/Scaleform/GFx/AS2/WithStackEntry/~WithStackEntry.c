void __thiscall Scaleform::GFx::AS2::WithStackEntry::~WithStackEntry(Scaleform::GFx::AS2::WithStackEntry *this)
{
  signed int BlockEndPc; // eax
  Scaleform::RefCountNTSImpl *pObject; // ecx
  int RefCount; // eax

  BlockEndPc = this->BlockEndPc;
  pObject = (Scaleform::RefCountNTSImpl *)this->pObject;
  if ( BlockEndPc >= 0 )
  {
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else if ( pObject )
  {
    RefCount = pObject[1].RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject[1].RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pObject);
    }
  }
}
