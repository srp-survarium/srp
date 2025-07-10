void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        const Scaleform::RangeData<void *> *val)
{
  unsigned int Size; // eax
  Scaleform::RangeData<void *> *v5; // eax
  unsigned int Length; // edx

  Scaleform::ArrayData<Scaleform::RangeData<void *>,Scaleform::AllocatorLH<Scaleform::RangeData<void *>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->Data,
    this->Data.Size + 1);
  Size = this->Data.Size;
  if ( index < Size - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      12 * (Size - index - 1));
  v5 = &this->Data.Data[index];
  if ( v5 )
  {
    Length = val->Length;
    v5->Index = val->Index;
    v5->Length = Length;
    v5->Data = val->Data;
  }
}
