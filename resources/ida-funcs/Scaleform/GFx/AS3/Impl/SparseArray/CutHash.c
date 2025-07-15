void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::CutHash(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int pos,
        unsigned int del_num,
        Scaleform::GFx::AS3::Impl::SparseArray *deleted)
{
  unsigned int v4; // esi
  unsigned int ValueHLowInd; // ecx
  unsigned int ValueHHighInd; // eax
  unsigned int v8; // ebx
  __int16 Flags; // dx
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // esi
  int v12; // ecx
  int v13; // eax
  int v14; // edx
  signed int Index; // eax
  int v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  void *pHeap; // [esp-10h] [ebp-3Ch]
  unsigned int cutLowInd; // [esp+8h] [ebp-24h]
  unsigned int cutHighInd; // [esp+Ch] [ebp-20h]
  unsigned int lastDelInd; // [esp+10h] [ebp-1Ch]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+14h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+1Ch] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+2Ch] [ebp+0h]

  v4 = del_num;
  if ( del_num )
  {
    ValueHLowInd = this->ValueHLowInd;
    lastDelInd = pos + del_num - 1;
    cutLowInd = pos;
    if ( ValueHLowInd >= pos )
      cutLowInd = ValueHLowInd;
    ValueHHighInd = this->ValueHHighInd;
    cutHighInd = pos + del_num - 1;
    if ( cutHighInd >= ValueHHighInd )
      cutHighInd = this->ValueHHighInd;
    v8 = cutLowInd;
    Flags = 0;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    pos = cutLowInd;
    if ( cutLowInd <= ValueHHighInd )
    {
      p_ValueH = &this->ValueH;
      do
      {
        pTable = p_ValueH->mHash.pTable;
        if ( p_ValueH->mHash.pTable )
        {
          v12 = 5381;
          v13 = 4;
          do
          {
            v14 = *((unsigned __int8 *)&retaddr + v13-- + 3);
            v12 = v14 + 65599 * v12;
          }
          while ( v13 );
          Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexCore<unsigned int>(
                    &this->ValueH.mHash,
                    &pos,
                    v12 & pTable->SizeMask);
          if ( Index >= 0 )
          {
            v16 = (int)&pTable[4 * Index + 2];
            if ( v16 )
            {
              Scaleform::GFx::AS3::Value::Assign(&v, (const Scaleform::GFx::AS3::Value *)(v16 + 8));
              Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::RemoveAlt<unsigned int>(
                &this->ValueH.mHash,
                &pos);
              v8 = pos;
              if ( pos <= lastDelInd )
              {
                if ( deleted )
                  Scaleform::GFx::AS3::Impl::SparseArray::PushBack(deleted, &v);
              }
              else if ( (v.Flags & 0x1F) != 0 )
              {
                pos -= del_num;
                key.pFirst = &pos;
                pHeap = this->ValueH.mHash.pHeap;
                key.pSecond = &v;
                Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
                  &this->ValueH.mHash,
                  pHeap,
                  &key);
              }
            }
          }
        }
        pos = ++v8;
      }
      while ( v8 <= this->ValueHHighInd );
      v4 = del_num;
      Flags = v.Flags;
      v8 = cutLowInd;
    }
    v17 = this->ValueHLowInd;
    if ( v17 >= v8 )
      v17 = v8;
    this->ValueHLowInd = v17;
    if ( v17 <= v4 )
      v18 = 0;
    else
      v18 = v17 - v4;
    this->ValueHLowInd = v18;
    v19 = this->ValueHHighInd;
    if ( cutHighInd >= v19 )
      v19 = cutHighInd;
    this->ValueHHighInd = v19;
    if ( v19 <= v4 )
      v20 = 0;
    else
      v20 = v19 - v4;
    this->ValueHHighInd = v20;
    if ( (Flags & 0x1Fu) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
  }
}
