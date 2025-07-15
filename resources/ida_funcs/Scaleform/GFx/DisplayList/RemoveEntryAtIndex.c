void __thiscall Scaleform::GFx::DisplayList::RemoveEntryAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index)
{
  unsigned __int8 Flags; // al

  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index);
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
    &this->DisplayObjectArray,
    index);
  Flags = this->Flags;
  this->pCachedChar = 0;
  if ( (Flags & 2) != 0 )
    this->Flags = Flags | 1;
}
