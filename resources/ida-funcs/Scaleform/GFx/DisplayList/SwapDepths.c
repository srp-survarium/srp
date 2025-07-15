char __thiscall Scaleform::GFx::DisplayList::SwapDepths(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        int depth1,
        int depth2,
        unsigned int frame)
{
  unsigned int DisplayIndex; // edi
  unsigned int v8; // ebp
  unsigned int v9; // eax
  unsigned int Size; // ecx
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // edi
  Scaleform::GFx::DisplayList::DisplayEntry *v12; // ebx
  Scaleform::GFx::DisplayObjectBase *v13; // eax
  unsigned int v14; // ecx
  unsigned int *p_TreeIndex; // edx
  unsigned int *p_MaskTreeIndex; // eax
  Scaleform::RefCountNTSImpl *v17; // ecx
  unsigned int v18; // edx
  Scaleform::GFx::DisplayObjectBase *v19; // ebp
  unsigned int v20; // ebp
  Scaleform::GFx::DisplayObjectBase *v21; // eax
  unsigned __int8 Flags; // al
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ebx
  Scaleform::GFx::DisplayList::DisplayEntry *v24; // eax
  unsigned int MaskTreeIndex; // edx
  unsigned int index; // [esp+8h] [ebp-24h]
  Scaleform::GFx::DisplayObjectBase *v27; // [esp+Ch] [ebp-20h]
  Scaleform::RefCountNTSImpl *v28; // [esp+10h] [ebp-1Ch]
  unsigned int v29; // [esp+14h] [ebp-18h]
  Scaleform::GFx::DisplayList::DisplayEntry val; // [esp+20h] [ebp-Ch] BYREF

  if ( depth1 == depth2 )
    return 1;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth1);
  v29 = DisplayIndex;
  if ( DisplayIndex >= this->DisplayObjectArray.Data.Size )
    return 0;
  v8 = DisplayIndex;
  if ( this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Depth != depth1 )
    return 0;
  if ( DisplayIndex == -1 )
    return 0;
  v9 = Scaleform::GFx::DisplayList::FindDisplayIndex(this, depth2);
  Size = this->DisplayObjectArray.Data.Size;
  index = v9;
  if ( DisplayIndex < Size && (this->DisplayObjectArray.Data.Data[DisplayIndex].pCharacter->Flags & 0x8000u) != 0 )
    return 0;
  if ( v9 < Size && (this->DisplayObjectArray.Data.Data[v9].pCharacter->Flags & 0x8000u) != 0 )
    return 0;
  this->pCachedChar = 0;
  if ( v9 >= Size )
    goto LABEL_34;
  Data = this->DisplayObjectArray.Data.Data;
  v12 = &this->DisplayObjectArray.Data.Data[v9];
  if ( v12->pCharacter->Depth != depth2 )
  {
    DisplayIndex = v29;
LABEL_34:
    pCharacter = this->DisplayObjectArray.Data.Data[v8].pCharacter;
    v24 = &this->DisplayObjectArray.Data.Data[v8];
    val.pCharacter = pCharacter;
    if ( pCharacter )
      ++pCharacter->RefCount;
    MaskTreeIndex = v24->MaskTreeIndex;
    val.TreeIndex = v24->TreeIndex;
    val.MaskTreeIndex = MaskTreeIndex;
    Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, DisplayIndex);
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      &this->DisplayObjectArray,
      DisplayIndex);
    v20 = index;
    if ( DisplayIndex < index )
      v20 = index - 1;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
      &this->DisplayObjectArray,
      v20,
      &val);
    Scaleform::GFx::DisplayList::InsertIntoRenderTree(this, owner, (Scaleform::GFx::DisplayObjectBase *)v20);
    if ( pCharacter )
      Scaleform::RefCountNTSImpl::Release(pCharacter);
    goto LABEL_28;
  }
  v13 = Data[v8].pCharacter;
  v28 = v13;
  if ( v13 )
    ++v13->RefCount;
  v14 = Data[v8].MaskTreeIndex;
  p_TreeIndex = &Data[v8].TreeIndex;
  val.TreeIndex = *p_TreeIndex;
  p_MaskTreeIndex = &Data[v8].MaskTreeIndex;
  val.MaskTreeIndex = v14;
  v27 = v12->pCharacter;
  v17 = Data[v8].pCharacter;
  if ( v17 )
  {
    Scaleform::RefCountNTSImpl::Release(v17);
    p_TreeIndex = &Data[v8].TreeIndex;
    p_MaskTreeIndex = &Data[v8].MaskTreeIndex;
  }
  Data[v8].pCharacter = v27;
  if ( v27 )
    ++v27->RefCount;
  *p_TreeIndex = v12->TreeIndex;
  *p_MaskTreeIndex = v12->MaskTreeIndex;
  if ( v12->pCharacter )
    Scaleform::RefCountNTSImpl::Release(v12->pCharacter);
  v12->pCharacter = (Scaleform::GFx::DisplayObjectBase *)v28;
  if ( v28 )
    ++v28->RefCount;
  v18 = val.MaskTreeIndex;
  v12->TreeIndex = val.TreeIndex;
  v12->MaskTreeIndex = v18;
  if ( v28 )
    Scaleform::RefCountNTSImpl::Release(v28);
  Scaleform::GFx::DisplayList::SwapRenderTreeNodes(this, owner, v29, index);
  v19 = this->DisplayObjectArray.Data.Data[v8].pCharacter;
  if ( v19 )
  {
    v19->Depth = depth1;
    v19->CreateFrame = frame + 1;
  }
  v20 = index;
LABEL_28:
  v21 = this->DisplayObjectArray.Data.Data[v20].pCharacter;
  if ( v21 )
  {
    v21->Depth = depth2;
    v21->CreateFrame = frame + 1;
  }
  Flags = this->Flags;
  if ( (Flags & 2) != 0 )
    this->Flags = Flags | 1;
  return 1;
}
