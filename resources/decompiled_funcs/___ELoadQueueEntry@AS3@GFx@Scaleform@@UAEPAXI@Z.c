Scaleform::GFx::AS3::LoadQueueEntry *__thiscall Scaleform::GFx::AS3::LoadQueueEntry::`vector deleting destructor'(
        Scaleform::GFx::AS3::LoadQueueEntry *this,
        char a2)
{
  Scaleform::GFx::AS3::LoadQueueEntry::~LoadQueueEntry(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
