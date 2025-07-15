void __thiscall Scaleform::GFx::AS3::Instances::fl::Array::AS3lastIndexOf(
        Scaleform::GFx::AS3::Instances::fl::Array *this,
        int *result,
        const Scaleform::GFx::AS3::Value *searchElement,
        int fromIndex)
{
  signed int v4; // edi
  signed int v6; // ebp
  Scaleform::GFx::AS3::Value *p_DefaultValue; // eax
  signed int Index; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int> >::NodeHashF> >::TableType *v9; // eax

  v4 = fromIndex;
  if ( fromIndex < 0 )
    v4 = this->SA.Length + fromIndex;
  if ( v4 >= (signed int)(this->SA.Length - 1) )
    v4 = this->SA.Length - 1;
  if ( v4 < 0 )
  {
LABEL_17:
    *result = -1;
  }
  else
  {
    v6 = v4;
    while ( 1 )
    {
      fromIndex = v4;
      if ( v4 >= this->SA.ValueA.Data.Size )
      {
        if ( v4 < this->SA.ValueHLowInd
          || v4 > this->SA.ValueHHighInd
          || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>,Scaleform::HashNode<unsigned int,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned int>>::NodeHashF>>::findIndexAlt<unsigned int>(
                        &this->SA.ValueH.mHash,
                        (const unsigned int *)&fromIndex),
              Index < 0)
          || (v9 = &this->SA.ValueH.mHash.pTable[4 * Index + 2]) == 0
          || (p_DefaultValue = (Scaleform::GFx::AS3::Value *)&v9[1]) == 0 )
        {
          p_DefaultValue = (Scaleform::GFx::AS3::Value *)&this->SA.DefaultValue;
        }
      }
      else
      {
        p_DefaultValue = &this->SA.ValueA.Data.Data[v6];
      }
      if ( Scaleform::GFx::AS3::StrictEqual(p_DefaultValue, searchElement) )
        break;
      --v4;
      --v6;
      if ( v4 < 0 )
        goto LABEL_17;
    }
    *result = v4;
  }
}
