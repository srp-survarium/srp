void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3indexOf(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        int *result,
        const Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  unsigned int v4; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  Scaleform::GFx::AS3::Value *p_DefaultValue; // eax
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v10; // eax

  v4 = fromIndex;
  if ( fromIndex < 0 )
    v4 = this->SA.Length + fromIndex;
  v6 = v4;
  if ( v4 >= this->SA.Length )
  {
LABEL_15:
    *result = -1;
  }
  else
  {
    v7 = v4;
    while ( 1 )
    {
      fromIndex = v6;
      if ( v6 >= this->SA.ValueA.Data.Size )
      {
        if ( v6 < this->SA.ValueHLowInd
          || v6 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                        &this->SA.ValueH.mHash,
                        (const unsigned int *)&fromIndex),
              Index < 0)
          || (v10 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v10[1]) == 0 )
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)&this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v7];
      }
      if ( Scaleform::GFx::AS3::StrictEqual(p_DefaultValue, searchElement) )
        break;
      ++v6;
      ++v7;
      if ( v6 >= this->SA.Length )
        goto LABEL_15;
    }
    *result = v6;
  }
}
