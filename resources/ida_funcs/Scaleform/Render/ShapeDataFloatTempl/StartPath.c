void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle)
{
  bool v5; // zf
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v8; // edi
  unsigned __int8 *v9; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+8h] [ebp-4h] BYREF

  v5 = this->Status == Status_Clean;
  Data = this->Data;
  encoder.Data = Data;
  if ( v5 )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(this);
  Size = Data->Data.Size;
  v8 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v8 >= Data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)Data,
        Data,
        v8 + (v8 >> 2));
  }
  else if ( v8 < Data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v8);
  }
  v9 = &Data->Data.Data[v8 - 1];
  Data->Data.Size = v8;
  if ( v9 )
    *v9 = 1;
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &encoder,
    leftStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &encoder,
    rightStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &encoder,
    strokeStyle);
  this->Status = Status_StartPath;
}


void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int leftStyle,
        unsigned int rightStyle,
        unsigned int strokeStyle)
{
  bool v5; // zf
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v8; // edi
  unsigned __int8 *v9; // edx
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+Ch] [ebp-4h] BYREF

  v5 = this->Status == Status_Clean;
  Data = this->Data;
  encoder.Data = Data;
  if ( v5 )
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(this);
  Size = Data->Data.Size;
  v8 = Size + 1;
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
  v9[v8 - 1] = 1;
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &encoder,
    leftStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &encoder,
    rightStyle);
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
    &encoder,
    strokeStyle);
  this->Status = Status_StartPath;
}
