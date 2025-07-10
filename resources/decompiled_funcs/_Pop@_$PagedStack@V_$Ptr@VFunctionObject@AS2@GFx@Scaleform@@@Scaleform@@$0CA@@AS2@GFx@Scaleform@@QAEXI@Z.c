void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Pop(
        Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *this,
        unsigned int n)
{
  unsigned int i; // edi
  Scaleform::GFx::AS2::FunctionObject *pObject; // ecx
  unsigned int RefCount; // eax

  for ( i = n; i; --i )
  {
    pObject = this->pCurrent->pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    if ( --this->pCurrent < this->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(this);
  }
}
