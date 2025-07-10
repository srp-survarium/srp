void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float cx,
        float cy,
        float ax,
        float ay)
{
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v8; // edi
  unsigned __int8 *v9; // edx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+10h] [ebp-4h] BYREF

  Data = this->Data;
  Size = Data->Data.Size;
  v8 = Size + 1;
  encoder.Data = Data;
  if ( Size + 1 >= Size )
  {
    if ( v8 >= Data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
        Data,
        v8 + (v8 >> 2));
  }
  else if ( v8 < Data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v8);
  }
  v9 = Data->Data.Data;
  Data->Data.Size = v8;
  v9[v8 - 1] = 4;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    cx);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    cy);
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
