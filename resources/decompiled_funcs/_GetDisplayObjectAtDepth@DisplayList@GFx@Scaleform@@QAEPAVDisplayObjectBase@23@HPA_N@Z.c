Scaleform::GFx::DisplayObjectBase *__thiscall Scaleform::GFx::DisplayList::GetDisplayObjectAtDepth(
        Scaleform::GFx::DisplayList *this,
        int depth,
        bool *pisMarkedForRemove)
{
  unsigned int DisplayIndex; // eax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  if ( DisplayIndex >= this->DisplayObjectArray.Data.Size )
    return 0;
  pCharacter = this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter;
  if ( pCharacter->Depth != depth || DisplayIndex == -1 || pCharacter->Depth != depth )
    return 0;
  if ( pisMarkedForRemove )
    *pisMarkedForRemove = (pCharacter->Flags & 0x40) != 0;
  return pCharacter;
}
