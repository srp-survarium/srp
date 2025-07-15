void __thiscall Scaleform::GFx::DisplayList::Clear(
        Scaleform::GFx::DisplayList *this,
        Scaleform::GFx::DisplayObjectBase *owner)
{
  Scaleform::GFx::DisplayObjectBase *v2; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::MovieDefImpl *v5; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // edi
  Scaleform::GFx::DisplayList::DisplayEntry *v7; // edi
  int v8; // ebx
  Scaleform::GFx::DisplayObjectBase *pCharacter; // ecx

  v2 = owner;
  pMovieImpl = owner->pASRoot->pMovieImpl;
  v5 = owner->GetResourceMovieDef(owner);
  Scaleform::GFx::MovieImpl::AddMovieDefToKillList(pMovieImpl, v5);
  while ( this->DisplayObjectArray.Data.Size )
  {
    Data = this->DisplayObjectArray.Data.Data;
    this->pCachedChar = 0;
    Data->pCharacter->OnEventUnload(Data->pCharacter);
    Scaleform::GFx::DisplayList::RemoveFromRenderTree(this, v2, 0);
    Data->pCharacter->pParent = 0;
    if ( this->DisplayObjectArray.Data.Size == 1 )
    {
      v7 = this->DisplayObjectArray.Data.Data;
      v8 = 1;
      do
      {
        if ( v7->pCharacter )
          Scaleform::RefCountNTSImpl::Release(v7->pCharacter);
        --v7;
        --v8;
      }
      while ( v8 );
      if ( (this->DisplayObjectArray.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
      {
        if ( this->DisplayObjectArray.Data.Data )
        {
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->DisplayObjectArray.Data.Data);
          this->DisplayObjectArray.Data.Data = 0;
        }
        this->DisplayObjectArray.Data.Policy.Capacity = 0;
      }
      v2 = owner;
      this->DisplayObjectArray.Data.Size = 0;
    }
    else
    {
      pCharacter = this->DisplayObjectArray.Data.Data->pCharacter;
      if ( pCharacter )
        Scaleform::RefCountNTSImpl::Release(pCharacter);
      memmove(
        (int)this->DisplayObjectArray.Data.Data,
        (const __m128i *)&this->DisplayObjectArray.Data.Data[1],
        12 * (this->DisplayObjectArray.Data.Size - 1));
      --this->DisplayObjectArray.Data.Size;
    }
  }
  this->pCachedChar = 0;
  Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->DisplayObjectArray.Data,
    this,
    0);
}
