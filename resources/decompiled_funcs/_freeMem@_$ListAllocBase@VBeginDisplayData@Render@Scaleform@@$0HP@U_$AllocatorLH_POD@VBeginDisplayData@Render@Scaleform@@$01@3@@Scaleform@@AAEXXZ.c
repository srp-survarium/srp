void __thiscall Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::freeMem(
        Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::PageType *FirstPage; // eax
  Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2> >::PageType *pNext; // esi

  FirstPage = this->FirstPage;
  if ( this->FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, FirstPage);
      FirstPage = pNext;
    }
    while ( pNext );
  }
}
