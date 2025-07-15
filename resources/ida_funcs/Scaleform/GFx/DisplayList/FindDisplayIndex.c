int __thiscall Scaleform::GFx::DisplayList::FindDisplayIndex(
        Scaleform::GFx::DisplayList *this,
        const Scaleform::GFx::DisplayObjectBase *ch)
{
  unsigned int Size; // edx
  int result; // eax
  Scaleform::GFx::DisplayList::DisplayEntry *i; // ecx

  Size = this->DisplayObjectArray.Data.Size;
  result = 0;
  if ( !Size )
    return -1;
  for ( i = this->DisplayObjectArray.Data.Data; i->pCharacter != ch; ++i )
  {
    if ( ++result >= Size )
      return -1;
  }
  return result;
}


unsigned int __thiscall Scaleform::GFx::DisplayList::FindDisplayIndex(Scaleform::GFx::DisplayList *this, int depth)
{
  int v3; // ebp
  unsigned int v4; // edi
  unsigned int v5; // ebx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v6; // eax
  int v7; // ebp
  Scaleform::GFx::DisplayList::DisplayEntry *v8; // eax
  Scaleform::GFx::DisplayObjectBase *pCharacter; // eax
  int v10; // edx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v11; // ecx
  Scaleform::GFx::DisplayList::DepthToIndexMapElem *Data; // eax
  Scaleform::GFx::DisplayList::DepthToIndexContainer *DepthToIndexMap; // ecx
  unsigned int result; // eax
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v15; // eax
  unsigned int v16; // eax
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v17; // ecx
  int v18; // ecx
  Scaleform::GFx::DisplayList::DisplayEntry *i; // esi
  int rv; // [esp+Ch] [ebp-10h]
  unsigned int n; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::DisplayList::DepthToIndexMapElem val; // [esp+14h] [ebp-8h] BYREF

  if ( (this->Flags & 1) == 0 )
    goto LABEL_25;
  v3 = -1;
  rv = -1;
  if ( this->DisplayObjectArray.Data.Size <= 0xA )
  {
    DepthToIndexMap = this->DepthToIndexMap;
    if ( DepthToIndexMap )
      Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &DepthToIndexMap->Array.Data,
        0);
  }
  else
  {
    v4 = 0;
    v5 = 0;
    if ( !this->DepthToIndexMap )
    {
      n = 322;
      v6 = (Scaleform::GFx::DisplayList::DepthToIndexContainer *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   12,
                                                                   &n);
      if ( v6 )
      {
        v6->Array.Data.Data = 0;
        v6->Array.Data.Size = 0;
        v6->Array.Data.Policy.Capacity = 0;
      }
      else
      {
        v6 = 0;
      }
      this->DepthToIndexMap = v6;
    }
    n = this->DisplayObjectArray.Data.Size;
    if ( n )
    {
      v7 = 0;
      do
      {
        v8 = &this->DisplayObjectArray.Data.Data[v7];
        if ( rv == -1 && v8->pCharacter->Depth >= depth )
          rv = v4;
        pCharacter = v8->pCharacter;
        v10 = pCharacter->Depth;
        if ( v10 != -1 )
        {
          v11 = this->DepthToIndexMap;
          if ( v5 >= v11->Array.Data.Size )
          {
            val.Depth = pCharacter->Depth;
            val.Index = v4;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              &v11->Array,
              &val);
          }
          else
          {
            Data = v11->Array.Data.Data;
            Data[v5].Depth = v10;
            Data[v5].Index = v4;
          }
          ++v5;
        }
        ++v4;
        ++v7;
      }
      while ( v4 < n );
      v3 = rv;
    }
    Scaleform::ArrayData<Scaleform::GFx::DisplayList::DepthToIndexMapElem,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DepthToIndexMapElem,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->DepthToIndexMap->Array.Data,
      v5);
  }
  this->Flags &= ~1u;
  if ( v3 != -1 )
    return v3;
LABEL_25:
  if ( (this->Flags & 2) == 0 )
    return Scaleform::Alg::LowerBoundSliced<Scaleform::ArrayLH<Scaleform::GFx::DisplayList::DisplayEntry,2,Scaleform::ArrayDefaultPolicy>,int,int (__cdecl *)(Scaleform::GFx::DisplayList::DisplayEntry const &,int)>(
             &this->DisplayObjectArray,
             0,
             this->DisplayObjectArray.Data.Size,
             &depth,
             Scaleform::GFx::DisplayList::DepthLess);
  v15 = this->DepthToIndexMap;
  if ( v15 && this->DisplayObjectArray.Data.Size > 0xA )
  {
    v16 = Scaleform::Alg::LowerBoundSliced<Scaleform::GFx::DisplayList::DepthToIndexContainer,int,int (__cdecl *)(Scaleform::GFx::DisplayList::DepthToIndexMapElem const &,int)>(
            v15,
            0,
            v15->Array.Data.Size,
            &depth,
            Scaleform::GFx::DisplayList::DepthLess1);
    v17 = this->DepthToIndexMap;
    if ( v16 == v17->Array.Data.Size )
      return this->DisplayObjectArray.Data.Size;
    else
      return v17->Array.Data.Data[v16].Index;
  }
  else
  {
    result = this->DisplayObjectArray.Data.Size;
    v18 = 0;
    if ( result )
    {
      for ( i = this->DisplayObjectArray.Data.Data; i->pCharacter->Depth < depth; ++i )
      {
        if ( ++v18 >= result )
          return result;
      }
      return v18;
    }
  }
  return result;
}
