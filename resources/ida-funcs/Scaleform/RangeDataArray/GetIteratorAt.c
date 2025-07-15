Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *__thiscall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::GetIteratorAt(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *result,
        int index)
{
  int RangeIndex; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> >::Iterator *v5; // eax
  unsigned int Size; // esi

  RangeIndex = Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
                 this,
                 index);
  if ( RangeIndex == -1 )
  {
    v5 = result;
    result->pArray = 0;
    result->Index = -1;
  }
  else
  {
    result->pArray = this;
    result->Index = 0;
    if ( RangeIndex >= 0 )
    {
      Size = this->Ranges.Data.Size;
      if ( RangeIndex < Size )
        result->Index = RangeIndex;
      else
        result->Index = Size - 1;
      return result;
    }
    else
    {
      result->Index = 0;
      return result;
    }
  }
  return v5;
}
