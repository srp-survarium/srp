void __thiscall Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner,
        unsigned int targetFrame)
{
  unsigned int v4; // edi
  int v5; // ebp
  Scaleform::GFx::DisplayObjectBase *pCharacter; // esi
  Scaleform::GFx::DisplayList::DisplayEntry *v7; // eax
  unsigned int n; // [esp+8h] [ebp-4h]

  v4 = 0;
  n = this->DisplayObjectArray.Data.Size;
  if ( n )
  {
    v5 = 0;
    do
    {
      pCharacter = this->DisplayObjectArray.Data.Data[v5].pCharacter;
      v7 = &this->DisplayObjectArray.Data.Data[v5];
      if ( pCharacter )
        ++pCharacter->RefCount;
      if ( pCharacter->Depth <= 0x3FFFu && pCharacter->CreateFrame > targetFrame )
      {
        v7->pCharacter->Flags |= 0x40u;
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, owner, v4);
      }
      Scaleform::RefCountNTSImpl::Release(pCharacter);
      ++v4;
      ++v5;
    }
    while ( v4 < n );
  }
}
