void __thiscall Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::~PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(
        Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *this)
{
  Scaleform::GFx::AS2::FunctionObject *pObject; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *v4; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *pNext; // edi

  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Pop(
    this,
    32 * (this->Pages.Data.Size - 1) + this->pCurrent - this->pPageStart);
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
  v4 = this->Pages.Data.Data[this->Pages.Data.Size - 1];
  v4->pNext = this->pReserved;
  this->pReserved = v4;
  do
  {
    pNext = this->pReserved->pNext;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pReserved);
    this->pReserved = pNext;
  }
  while ( pNext );
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Pages.Data.Data);
}
