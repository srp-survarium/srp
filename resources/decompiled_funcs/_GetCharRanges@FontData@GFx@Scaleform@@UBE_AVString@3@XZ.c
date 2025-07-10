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
  unsigned __int16 rangeStart; // [esp+10h] [ebp-20h]
  Scaleform::GFx::Range range; // [esp+14h] [ebp-1Ch]
  unsigned __int16 prevValue; // [esp+18h] [ebp-18h]
  Scaleform::GFx::Range prevValuea; // [esp+18h] [ebp-18h]
  Scaleform::HashIdentityLH<unsigned short,unsigned short,261,Scaleform::IdentityHash<unsigned short> > *it; // [esp+1Ch] [ebp-14h]
  Scaleform::Array<Scaleform::GFx::Range,2,Scaleform::ArrayDefaultPolicy> ranges; // [esp+24h] [ebp-Ch] BYREF

  pTable = this->CodeTable.mHash.pTable;
  v3 = 0;
  p_CodeTable = &this->CodeTable;
  Size = 0;
  memset(&ranges, 0, sizeof(ranges));
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
  it = v6;
  v10 = v7;
  rangeStart = 0;
  prevValue = 0;
LABEL_8:
  v11 = 0;
  while ( it )
  {
    v12 = it->mHash.pTable;
    if ( !it->mHash.pTable )
      break;
    v13 = v12->SizeMask;
    if ( (int)v10 > (int)v13 )
      break;
    v14 = v12[v10 + 1].SizeMask;
    if ( v11 )
    {
      if ( v3 != v14 - 1 )
      {
        v3 = prevValue;
        range.start = rangeStart;
        v15 = ranges.Data.Size + 1;
        range.end = prevValue;
        if ( ranges.Data.Size + 1 >= ranges.Data.Size )
        {
          if ( v15 >= ranges.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
              &ranges,
              v15 + (v15 >> 2));
        }
        else if ( v15 < ranges.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
            &ranges,
            ranges.Data.Size + 1);
        }
        Size = v15;
        ranges.Data.Size = v15;
        if ( &ranges.Data.Data[v15] != (Scaleform::GFx::Range *)4 )
          ranges.Data.Data[v15 - 1] = range;
        goto LABEL_8;
      }
      Size = ranges.Data.Size;
    }
    else
    {
      rangeStart = v12[v10 + 1].SizeMask;
      v11 = 1;
    }
    v3 = v12[++v10].SizeMask;
    prevValue = v14;
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
    prevValuea.start = rangeStart;
    prevValuea.end = v3;
    if ( Size + 1 >= Size )
    {
      if ( v17 >= ranges.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
          &ranges,
          v17 + (v17 >> 2));
    }
    else if ( v17 < ranges.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&ranges,
        &ranges,
        Size + 1);
    }
    ++Size;
    ranges.Data.Size = v17;
    if ( &ranges.Data.Data[v17] != (Scaleform::GFx::Range *)4 )
      ranges.Data.Data[v17 - 1] = prevValuea;
  }
  Scaleform::Alg::QuickSortSliced<Scaleform::Array<Scaleform::GFx::`anonymous namespace'::Range,2,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::`anonymous namespace'::RangeLess>(
    &ranges,
    0,
    Size);
  Scaleform::GFx::BuildStringFromRanges(&ranges, result);
  if ( ranges.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ranges.Data.Data);
  return result;
}
