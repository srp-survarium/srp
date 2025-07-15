bool __thiscall Scaleform::GFx::DisplayList::UnloadDisplayObjectAtIndex(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int index)
{
  unsigned int v4; // ebx
  const Scaleform::GFx::DisplayList::DisplayEntry *v5; // ebp
  Scaleform::GFx::DisplayObjectBase *pCharacter; // edi
  bool v8; // al
  Scaleform::GFx::DisplayObjectBase *v9; // ebx
  int Depth; // eax
  int v11; // edi
  Scaleform::GFx::DisplayObjectBase *v12; // ebx
  unsigned int DisplayIndex; // eax
  unsigned __int8 Flags; // al
  Scaleform::GFx::DisplayObjectBase *v15; // ebx
  unsigned __int8 v16; // al
  Scaleform::GFx::DisplayList::DisplayEntry val; // [esp+10h] [ebp-Ch] BYREF
  bool ownera; // [esp+20h] [ebp+4h]

  v4 = index;
  v5 = &this->DisplayObjectArray.Data.Data[index];
  Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, index);
  pCharacter = v5->pCharacter;
  if ( (v5->pCharacter->Flags & 0x40) != 0 )
    return 0;
  if ( pCharacter )
  {
    if ( (pCharacter->Flags & 0x1000) != 0 || pCharacter->Depth < -1 )
      return 0;
    v8 = pCharacter->OnUnloading(v5->pCharacter);
    pCharacter->Flags |= 0x1000u;
    ownera = v8;
    if ( v8 )
    {
      pCharacter->OnEventUnload(pCharacter);
      v9 = this->DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( v9 )
        v9->pParent = 0;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &this->DisplayObjectArray,
        index);
    }
    else
    {
      Depth = v5->pCharacter->Depth;
      if ( Depth >= 0 )
      {
        v11 = -1 - Depth;
        Scaleform::GFx::DisplayList::DisplayEntry::DisplayEntry(&val, v5);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
          &this->DisplayObjectArray,
          index);
        v12 = val.pCharacter;
        val.pCharacter->Depth = v11;
        DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, v11);
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &this->DisplayObjectArray,
          DisplayIndex,
          &val);
        Scaleform::RefCountNTSImpl::Release(v12);
      }
    }
    Flags = this->Flags;
    this->pCachedChar = 0;
    if ( (Flags & 2) != 0 )
      this->Flags = Flags | 1;
    return ownera;
  }
  else
  {
    v15 = this->DisplayObjectArray.Data.Data[v4].pCharacter;
    if ( v15 )
      v15->pParent = 0;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      &this->DisplayObjectArray,
      index);
    v16 = this->Flags;
    this->pCachedChar = 0;
    if ( (v16 & 2) != 0 )
      this->Flags = v16 | 1;
    return 1;
  }
}
