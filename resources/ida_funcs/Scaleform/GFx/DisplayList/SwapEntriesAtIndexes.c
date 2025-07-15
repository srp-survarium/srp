char __thiscall Scaleform::GFx::DisplayList::SwapEntriesAtIndexes(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int origIndex1,
        unsigned int origIndex2)
{
  unsigned int v5; // ebp
  Scaleform::GFx::DisplayList::DisplayEntry *v6; // eax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ebx
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // esi
  Scaleform::GFx::DisplayObjectBase *v9; // edx
  unsigned int v10; // edi
  Scaleform::GFx::DisplayObjectBase *v11; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *v12; // esi
  Scaleform::GFx::DisplayList *v13; // [esp+8h] [ebp-14h]
  Scaleform::GFx::DisplayObjectBase *v14; // [esp+Ch] [ebp-10h]
  unsigned int e_4; // [esp+14h] [ebp-8h]
  unsigned int e_8; // [esp+18h] [ebp-4h]
  char origIndex2a; // [esp+28h] [ebp+Ch]

  v13 = this;
  if ( origIndex1 == origIndex2 )
    return 1;
  v5 = origIndex1;
  v6 = &this->DisplayObjectArray.Data.Data[origIndex1];
  pCharacter = v6->pCharacter;
  if ( v6->pCharacter )
    ++pCharacter->RefCount;
  e_4 = v6->TreeIndex;
  e_8 = v6->MaskTreeIndex;
  if ( (pCharacter->Flags & 0x8000u) != 0
    || origIndex2 < this->DisplayObjectArray.Data.Size
    && (this->DisplayObjectArray.Data.Data[origIndex2].pCharacter->Flags & 0x8000u) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(pCharacter);
    return 0;
  }
  else
  {
    Data = this->DisplayObjectArray.Data.Data;
    v9 = this->DisplayObjectArray.Data.Data[origIndex1].pCharacter;
    v10 = origIndex2;
    v11 = this->DisplayObjectArray.Data.Data[origIndex2].pCharacter;
    v14 = v11;
    if ( v9 )
    {
      Scaleform::RefCountNTSImpl::Release(v9);
      v11 = v14;
      this = v13;
    }
    Data[origIndex1].pCharacter = v11;
    if ( v11 )
      ++v11->RefCount;
    Data[v5].TreeIndex = Data[v10].TreeIndex;
    Data[v5].MaskTreeIndex = Data[v10].MaskTreeIndex;
    v12 = &this->DisplayObjectArray.Data.Data[v10];
    if ( this->DisplayObjectArray.Data.Data[origIndex2].pCharacter )
    {
      Scaleform::RefCountNTSImpl::Release(this->DisplayObjectArray.Data.Data[origIndex2].pCharacter);
      this = v13;
    }
    v12->pCharacter = pCharacter;
    ++pCharacter->RefCount;
    v12->TreeIndex = e_4;
    v12->MaskTreeIndex = e_8;
    origIndex2a = Scaleform::GFx::DisplayList::SwapRenderTreeNodes(this, owner, origIndex1, origIndex2);
    Scaleform::RefCountNTSImpl::Release(pCharacter);
    return origIndex2a;
  }
}
