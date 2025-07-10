void __thiscall Scaleform::GFx::AS3::Impl::SparseArray::AdjustValueHLowInd(
        Scaleform::GFx::AS3::Impl::SparseArray *this)
{
  unsigned int ValueHLowInd; // eax
  unsigned int *p_ValueHLowInd; // esi
  __int16 Flags; // bx
  Scaleform::HashDH<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>,2,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> > *p_ValueH; // edi
  signed int Index; // eax
  int v7; // eax
  Scaleform::GFx::AS3::Value hv; // [esp+Ch] [ebp-10h] BYREF

  ValueHLowInd = this->ValueHLowInd;
  p_ValueHLowInd = &this->ValueHLowInd;
  Flags = 0;
  hv.Flags = 0;
  hv.Bonus.pWeakProxy = 0;
  if ( ValueHLowInd <= this->ValueHHighInd )
  {
    p_ValueH = &this->ValueH;
    do
    {
      Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                &this->ValueH.mHash,
                p_ValueHLowInd);
      if ( Index >= 0 )
      {
        v7 = (int)&p_ValueH->mHash.pTable[4 * Index + 2];
        if ( v7 )
        {
          Scaleform::GFx::AS3::Value::Assign(&hv, (const Scaleform::GFx::AS3::Value *)(v7 + 8));
          Flags = hv.Flags;
          if ( (hv.Flags & 0x1F) != 0 )
            break;
          Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::RemoveAlt<unsigned int>(
            &this->ValueH.mHash,
            p_ValueHLowInd);
          Flags = hv.Flags;
        }
      }
      ++*p_ValueHLowInd;
    }
    while ( *p_ValueHLowInd <= this->ValueHHighInd );
  }
  if ( (Flags & 0x1Fu) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&hv);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&hv);
  }
}
