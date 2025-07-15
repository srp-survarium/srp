void __thiscall Scaleform::GFx::DisplayList::ReplaceDisplayObjectAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayList::DisplayEntry *v5; // edi
  unsigned __int8 Flags; // al

  if ( index < this->DisplayObjectArray.Data.Size )
  {
    v5 = &this->DisplayObjectArray.Data.Data[index];
    this->pCachedChar = 0;
    if ( v5->pCharacter )
      Scaleform::RefCountNTSImpl::Release(v5->pCharacter);
    v5->pCharacter = ch;
    if ( ch )
      ++ch->RefCount;
    if ( v5->TreeIndex == -1 )
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, (Scaleform::GFx::DisplayObjectBase *)index);
    else
      Scaleform::GFx::DisplayList::ReplaceRenderTreeNode(this, owner, (Scaleform::GFx::DisplayObjectBase *)index);
    Flags = this->Flags;
    if ( (Flags & 2) != 0 )
      this->Flags = Flags | 1;
  }
}
