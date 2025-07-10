void __thiscall Scaleform::GFx::DisplayList::DisplayEntry::DisplayEntry(
        Scaleform::GFx::DisplayList::DisplayEntry *this,
        const Scaleform::GFx::DisplayList::DisplayEntry *di)
{
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  this->pCharacter = 0;
  pCharacter = di->pCharacter;
  this->pCharacter = di->pCharacter;
  if ( pCharacter )
    ++pCharacter->RefCount;
  this->TreeIndex = di->TreeIndex;
  this->MaskTreeIndex = di->MaskTreeIndex;
}
