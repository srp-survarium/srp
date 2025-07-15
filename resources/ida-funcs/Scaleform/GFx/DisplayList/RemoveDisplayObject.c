void __thiscall Scaleform::GFx::DisplayList::RemoveDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        int depth,
        Scaleform::GFx::ResourceId id)
{
  unsigned int Size; // ebp
  unsigned int DisplayIndex; // eax
  unsigned int v7; // ecx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ebx
  unsigned int v9; // edx
  unsigned int v10; // [esp+Ch] [ebp-4h]

  Size = this->DisplayObjectArray.Data.Size;
  v10 = Size;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  if ( DisplayIndex < Size )
  {
    v7 = DisplayIndex;
    pCharacter = this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter;
    if ( pCharacter )
      ++pCharacter->RefCount;
    if ( pCharacter->Depth == depth )
    {
      this->pCachedChar = 0;
      if ( id.Id == 0x40000 || this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Id.Id == id.Id )
      {
LABEL_12:
        Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(this, owner, DisplayIndex);
      }
      else
      {
        v9 = DisplayIndex + 1;
        while ( v9 < Size && this->DisplayObjectArray.Data.Data[v7 + 1].pCharacter->Depth == depth )
        {
          v7 = ++DisplayIndex;
          ++v9;
          if ( this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Id.Id == id.Id )
            goto LABEL_12;
          Size = v10;
        }
      }
    }
    Scaleform::RefCountNTSImpl::Release(pCharacter);
  }
}
