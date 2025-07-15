void __thiscall Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy>::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *this,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *a)
{
  Scaleform::GFx::AS2::WithStackEntry *Data; // ebp
  unsigned int Size; // edi
  unsigned int v5; // ebx

  this->Data.Data = 0;
  this->Data.Size = 0;
  this->Data.Policy.Capacity = 0;
  Data = a->Data.Data;
  Size = a->Data.Size;
  if ( Size )
  {
    v5 = this->Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Data,
      this,
      v5 + Size);
    memcpy((int)&this->Data.Data[v5], (const __m128i *)Data, 8 * Size);
  }
}
