void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::Insert(
        Scaleform::GFx::AS3::Impl::SparseArray *this,
        unsigned int pos,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int Size; // eax
  unsigned int v6; // ecx
  unsigned int v7; // edi
  Scaleform::GFx::AS3::Value *v8; // ebp
  unsigned int v9; // eax
  unsigned int v10; // ebx
  Scaleform::GFx::AS3::Value *v11; // edi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *pTable; // eax
  unsigned int ValueHLowInd; // eax
  unsigned int v15; // edi
  void *pHeap; // [esp-8h] [ebp-20h]
  Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeRef key; // [esp+10h] [ebp-8h] BYREF
  const Scaleform::GFx::AS3::Value *argca; // [esp+20h] [ebp+8h]

  Size = this->ValueA.Data.Size;
  if ( pos >= Size )
  {
    if ( pos == Size )
    {
      v10 = argc;
      if ( argc )
      {
        v11 = argv;
        do
        {
          Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
            &this->ValueA.Data,
            v11++);
          --v10;
        }
        while ( v10 );
        v10 = argc;
      }
      pTable = this->ValueH.mHash.pTable;
      if ( pTable && pTable->EntryCount )
      {
        Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(this, this->ValueHLowInd, v10);
        goto LABEL_16;
      }
      this->Length += v10;
    }
    else
    {
      ValueHLowInd = this->ValueHLowInd;
      if ( pos >= ValueHLowInd )
      {
        if ( pos > this->ValueHHighInd )
        {
          this->ValueHHighInd = pos + argc - 1;
        }
        else
        {
          Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(this, pos, argc);
          this->ValueHHighInd += argc;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(this, ValueHLowInd, argc);
        this->ValueHHighInd += argc;
        this->ValueHLowInd = pos;
      }
      v15 = 0;
      if ( argc )
      {
        key.pFirst = (const unsigned int *)&argv;
        argca = argv;
        do
        {
          argv = (Scaleform::GFx::AS3::Value *)(v15 + pos);
          pHeap = this->ValueH.mHash.pHeap;
          key.pSecond = argca;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeRef>(
            &this->ValueH.mHash,
            pHeap,
            &key);
          ++argca;
          ++v15;
        }
        while ( v15 < argc );
      }
      this->Length += argc;
    }
  }
  else
  {
    v6 = argc;
    v7 = 0;
    if ( argc )
    {
      v8 = argv;
      do
      {
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          &this->ValueA,
          v7 + pos,
          v8);
        ++v7;
        ++v8;
      }
      while ( v7 < argc );
      v6 = argc;
    }
    v9 = this->ValueHLowInd;
    if ( v9 )
    {
      Scaleform::GFx::AS3::Impl::SparseArray::MoveHashRight(this, v9, v6);
LABEL_16:
      this->ValueHLowInd += argc;
      this->ValueHHighInd += argc;
      this->Length += argc;
      return;
    }
    this->Length += v6;
  }
}
