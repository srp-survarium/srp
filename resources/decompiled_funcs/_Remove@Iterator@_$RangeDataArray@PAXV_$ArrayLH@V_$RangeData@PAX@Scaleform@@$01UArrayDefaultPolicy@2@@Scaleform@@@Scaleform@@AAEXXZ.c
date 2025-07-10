void __thiscall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::Iterator::Remove(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *this)
{
  signed int Index; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *pArray; // ecx

  Index = this->Index;
  if ( Index >= 0 )
  {
    pArray = this->pArray;
    if ( Index < pArray->Ranges.Data.Size )
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
        &pArray->Ranges,
        Index);
  }
}
