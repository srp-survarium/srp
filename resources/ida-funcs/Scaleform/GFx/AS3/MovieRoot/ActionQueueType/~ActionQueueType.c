void __thiscall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::~ActionQueueType(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pFreeEntry; // esi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pNextEntry; // edi

  Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(this);
  pFreeEntry = this->pFreeEntry;
  if ( pFreeEntry )
  {
    do
    {
      pNextEntry = pFreeEntry->pNextEntry;
      Scaleform::GFx::AS3::MovieRoot::ActionEntry::~ActionEntry(pFreeEntry);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pFreeEntry);
      pFreeEntry = pNextEntry;
    }
    while ( pNextEntry );
  }
}
