void __thiscall Scaleform::GFx::DisplayList::AddEntryAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        Scaleform::GFx::DisplayObjectBase *index,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned __int8 Flags; // al
  Scaleform::GFx::DisplayList::DisplayEntry val; // [esp+8h] [ebp-Ch] BYREF

  val.MaskTreeIndex = -1;
  val.TreeIndex = -1;
  val.pCharacter = ch;
  if ( ch )
    ++ch->RefCount;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
    &this->DisplayObjectArray,
    (unsigned int)index,
    &val);
  Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, index);
  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
    this->Flags = Flags | 1;
  if ( ch )
    Scaleform::RefCountNTSImpl::Release(ch);
}
