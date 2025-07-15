void __thiscall Scaleform::GFx::ResourceBinding::Destroy(Scaleform::GFx::ResourceBinding *this)
{
  Scaleform::GFx::ResourceBindData *volatile pResources; // esi
  volatile unsigned int ResourceCount; // ebx

  if ( this->pResources )
  {
    pResources = this->pResources;
    if ( this->ResourceCount )
    {
      ResourceCount = this->ResourceCount;
      do
      {
        if ( pResources->pResource.pObject )
          Scaleform::GFx::Resource::Release(pResources->pResource.pObject);
        ++pResources;
        --ResourceCount;
      }
      while ( ResourceCount );
    }
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pResources);
    this->pResources = 0;
  }
}
