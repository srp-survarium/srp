void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float cx1,
        float cy1,
        float cx2,
        float cy2,
        float ax,
        float ay)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v10; // edi
  unsigned __int8 *v11; // edx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+10h] [ebp-4h] BYREF

  Data = this->Data;
  Size = Data->Data.Size;
  v10 = Size + 1;
  encoder.Data = Data;
  if ( Size + 1 >= Size )
  {
    if ( v10 >= Data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
        Data,
        v10 + (v10 >> 2));
  }
  else if ( v10 < Data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v10);
  }
  v11 = Data->Data.Data;
  Data->Data.Size = v10;
  v11[v10 - 1] = 5;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    cx1);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    cy1);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    cx2);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    cy2);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    ax);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    ay);
  this->LastX = ax;
  this->LastY = ay;
  this->Status = Status_EdgeTo;
}
