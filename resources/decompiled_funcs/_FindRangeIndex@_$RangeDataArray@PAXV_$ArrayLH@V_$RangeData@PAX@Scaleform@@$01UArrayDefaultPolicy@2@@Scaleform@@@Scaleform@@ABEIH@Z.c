unsigned int __thiscall Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy>>::FindRangeIndex(
        Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *this,
        int index)
{
  unsigned int v2; // ebp
  unsigned int v3; // ebx
  unsigned int result; // eax
  Scaleform::RangeData<void *> *v5; // edi
  int v6; // edx
  int v7; // edx
  Scaleform::RangeData<void *> *v8; // ecx
  int v9; // eax
  int v10; // eax
  Scaleform::RangeDataArray<void *,Scaleform::ArrayLH<Scaleform::RangeData<void *>,2,Scaleform::ArrayDefaultPolicy> > *v11; // [esp+10h] [ebp-4h]

  v2 = 0;
  v3 = this->Ranges.Data.Size - 1;
  v11 = this;
  if ( this->Ranges.Data.Size != 1 )
  {
    while ( v3 != -1 )
    {
      result = (v3 + v2) >> 1;
      v5 = &this->Ranges.Data.Data[result];
      v6 = v5->Index;
      if ( index < v5->Index )
        goto LABEL_6;
      if ( index <= (signed int)(v5->Length + v6 - 1) )
        return result;
      this = v11;
      if ( index >= v6 )
        v7 = v5->Length - index + v6 - 1;
      else
LABEL_6:
        v7 = v6 - index;
      if ( !v7 )
        return result;
      if ( v7 >= 0 )
        v3 = result - 1;
      else
        v2 = result + 1;
      if ( v2 >= v3 )
        break;
    }
  }
  if ( v2 == v3 )
  {
    v8 = &this->Ranges.Data.Data[v2];
    v9 = v8->Index;
    if ( index < v8->Index )
      goto LABEL_17;
    if ( index <= (signed int)(v8->Length + v9 - 1) )
      return v2;
    if ( index >= v9 )
      v10 = v8->Length - index + v9 - 1;
    else
LABEL_17:
      v10 = v9 - index;
    if ( !v10 )
      return v2;
  }
  return -1;
}
