void __thiscall Scaleform::GFx::AS2::GFxAS2LoadQueueEntry::PConstruct(
        Scaleform::GFx::AS2::GFxAS2LoadQueueEntry *this,
        Scaleform::GFx::CharacterHandle *pchar,
        int level)
{
  Scaleform::GFx::CharacterHandle *pObject; // esi

  if ( pchar )
    ++pchar->RefCount;
  pObject = this->pCharacter.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
    this->pCharacter.pObject = pchar;
    this->Level = level;
  }
  else
  {
    this->pCharacter.pObject = pchar;
    this->Level = level;
  }
}
