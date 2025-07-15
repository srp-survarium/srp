Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *__thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::`vector deleting destructor'(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this,
        char a2)
{
  Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::~GFxAS2LoadQueueEntry(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
