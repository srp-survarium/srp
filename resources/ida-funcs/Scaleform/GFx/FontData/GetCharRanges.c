Scaleform::String *__thiscall Scaleform::GFx::FontData::GetCharRanges(
        Scaleform::GFx::FontData *this,
        Scaleform::String *result)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // eax
  unsigned __int16 v3; // bx
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *p_CodeTable; // edx
  unsigned int Size; // ebp
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *v6; // eax
  unsigned int v7; // ecx
  unsigned int SizeMask; // esi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v9; // eax
  unsigned int v10; // esi
  char v11; // dl
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v12; // ecx
  unsigned int v13; // edi
  unsigned __int16 v14; // ax
  unsigned int v15; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,261>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned short,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v16; // eax
  unsigned int v17; // esi
  __int16 v19; // [esp+10h] [ebp-20h]
  Scaleform::GFx::AS3::Instances::fl::Object *v20; // [esp+14h] [ebp-1Ch]
  unsigned __int16 v21; // [esp+18h] [ebp-18h]
  Scaleform::GFx::AS3::Instances::fl::Object *v22; // [esp+18h] [ebp-18h]
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *v23; // [esp+1Ch] [ebp-14h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+24h] [ebp-Ch] BYREF

  pTable = this->CodeTable.mHash.pTable;
  v3 = 0;
  p_CodeTable = &this->CodeTable;
  Size = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v7 = 0;
    v9 = pTable + 1;
    do
    {
      if ( v9->EntryCount != -2 )
        break;
      ++v7;
      ++v9;
    }
    while ( v7 <= SizeMask );
    v6 = p_CodeTable;
  }
  else
  {
    v6 = 0;
    v7 = 0;
  }
  v23 = v6;
  v10 = v7;
  v19 = 0;
  v21 = 0;
LABEL_8:
  v11 = 0;
  while ( v23 )
  {
    v12 = v23->mHash.pTable;
    if ( !v23->mHash.pTable )
      break;
    v13 = v12->SizeMask;
    if ( (int)v10 > (int)v13 )
      break;
    v14 = v12[v10 + 1].SizeMask;
    if ( v11 )
    {
      if ( v3 != v14 - 1 )
      {
        v3 = v21;
        LOWORD(v20) = v19;
        v15 = pheapAddr.Size + 1;
        HIWORD(v20) = v21;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v15 >= pheapAddr.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v15 + (v15 >> 2));
        }
        else if ( v15 < pheapAddr.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            pheapAddr.Size + 1);
        }
        Size = v15;
        pheapAddr.Size = v15;
        if ( &pheapAddr.Data[v15] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
          pheapAddr.Data[v15 - 1] = v20;
        goto LABEL_8;
      }
      Size = pheapAddr.Size;
    }
    else
    {
      v19 = v12[v10 + 1].SizeMask;
      v11 = 1;
    }
    v3 = v12[++v10].SizeMask;
    v21 = v14;
    if ( v10 <= v13 )
    {
      v16 = &v12[v10 + 1];
      do
      {
        if ( v16->EntryCount != -2 )
          break;
        ++v10;
        ++v16;
      }
      while ( v10 <= v13 );
    }
  }
  if ( v11 )
  {
    v17 = Size + 1;
    LOWORD(v22) = v19;
    HIWORD(v22) = v3;
    if ( Size + 1 >= Size )
    {
      if ( v17 >= pheapAddr.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v17 + (v17 >> 2));
    }
    else if ( v17 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        Size + 1);
    }
    ++Size;
    pheapAddr.Size = v17;
    if ( &pheapAddr.Data[v17] != (Scaleform::GFx::AS3::Instances::fl::Object **)4 )
      pheapAddr.Data[v17 - 1] = v22;
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    (Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    0,
    Size);
  Scaleform::GFx::BuildStringFromRanges(
    (const Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
    result);
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
  return result;
}
