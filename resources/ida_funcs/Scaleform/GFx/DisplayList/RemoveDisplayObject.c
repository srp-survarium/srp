void __thiscall Scaleform::GFx::DisplayList::RemoveDisplayObject(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        int depth,
        Scaleform::GFx::ResourceId id)
{
  unsigned int v5; // ebp
  unsigned int DisplayIndex; // eax
  unsigned int v7; // ecx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ebx
  unsigned int v9; // edx
  unsigned int size; // [esp+Ch] [ebp-4h]

  v5 = this->DisplayObjectArray.Data.Size;
  size = v5;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth);
  if ( DisplayIndex < v5 )
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
        while ( v9 < v5 && this->DisplayObjectArray.Data.Data[v7 + 1].pCharacter->Depth == depth )
        {
          v7 = ++DisplayIndex;
          ++v9;
          if ( this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Id.Id == id.Id )
            goto LABEL_12;
          v5 = size;
        }
      }
    }
    Scaleform::RefCountNTSImpl::Release(pCharacter);
  }
}
