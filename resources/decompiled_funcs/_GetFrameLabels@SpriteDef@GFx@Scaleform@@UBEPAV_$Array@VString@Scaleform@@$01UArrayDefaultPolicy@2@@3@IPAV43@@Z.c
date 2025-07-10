Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__thiscall Scaleform::GFx::SpriteDef::GetFrameLabels(
        Scaleform::GFx::SpriteDef *this,
        unsigned int frameNumber,
        Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  Scaleform::StringHashLH<unsigned int,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_NamedFrames; // esi
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int v5; // eax
  unsigned int SizeMask; // edx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v7; // ecx
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v8; // edx
  signed int v9; // edi
  unsigned int EntryCount; // eax
  const Scaleform::String *v11; // eax
  const Scaleform::String *v12; // ebp
  unsigned int Size; // eax
  unsigned int v14; // esi
  Scaleform::String *v15; // ecx
  unsigned int v16; // eax
  _DWORD *v17; // ecx
  int i; // [esp+10h] [ebp-Ch]
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *it; // [esp+14h] [ebp-8h]

  p_NamedFrames = &this->NamedFrames;
  pTable = this->NamedFrames.mHash.pTable;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v5 = 0;
    v7 = pTable + 1;
    do
    {
      if ( v7->EntryCount != -2 )
        break;
      ++v5;
      v7 += 2;
    }
    while ( v5 <= SizeMask );
    pTable = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *)p_NamedFrames;
  }
  else
  {
    v5 = 0;
  }
  v8 = pTable;
  it = pTable;
  v9 = v5;
  i = 0;
  while ( v8 )
  {
    EntryCount = v8->EntryCount;
    if ( !v8->EntryCount || v9 > *(_DWORD *)(EntryCount + 4) )
      break;
    v11 = (const Scaleform::String *)(16 * v9 + EntryCount);
    if ( frameNumber == v11[5].HeapTypeBits )
    {
      v12 = v11 + 4;
      Size = destArr->Data.Size;
      v14 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v14 >= destArr->Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)destArr,
            destArr,
            v14 + (v14 >> 2));
      }
      else
      {
        Scaleform::ConstructorMov<Scaleform::String>::DestructArray(&destArr->Data.Data[Size + 1], 0xFFFFFFFF);
        if ( v14 < destArr->Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)destArr,
            destArr,
            v14);
      }
      v15 = &destArr->Data.Data[v14 - 1];
      destArr->Data.Size = v14;
      if ( v15 )
        Scaleform::String::String(v15, v12);
      ++i;
      v8 = it;
    }
    v16 = *(_DWORD *)(v8->EntryCount + 4);
    if ( v9 <= (int)v16 && ++v9 <= v16 )
    {
      v17 = (_DWORD *)(16 * v9 + v8->EntryCount + 8);
      do
      {
        if ( *v17 != -2 )
          break;
        ++v9;
        v17 += 4;
      }
      while ( v9 <= v16 );
    }
  }
  return i != 0 ? destArr : 0;
}
