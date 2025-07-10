void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float x,
        float y)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // edx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+10h] [ebp-4h] BYREF

  Data = this->Data;
  Size = Data->Data.Size;
  v6 = Size + 1;
  encoder.Data = Data;
  if ( Size + 1 >= Size )
  {
    if ( v6 >= Data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
        Data,
        v6 + (v6 >> 2));
  }
  else if ( v6 < Data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v6);
  }
  v7 = Data->Data.Data;
  Data->Data.Size = v6;
  v7[v6 - 1] = 2;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    x);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    y);
  this->StartX = x;
  this->StartY = y;
  this->Status = Status_MoveTo;
  this->LastY = y;
  this->LastX = x;
}
