void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        float x,
        float y)
{
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // esi
  unsigned int Size; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > encoder; // [esp+10h] [ebp-4h] BYREF

  Data = this->Data;
  Size = Data->Data.Size;
  v6 = Size + 1;
  encoder.Data = Data;
  if ( Size + 1 >= Size )
  {
    if ( v6 >= Data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)Data,
        Data,
        v6 + (v6 >> 2));
  }
  else if ( v6 < Data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)Data,
      Data,
      v6);
  }
  v7 = &Data->Data.Data[v6 - 1];
  Data->Data.Size = v6;
  if ( v7 )
    *v7 = 3;
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    x);
  Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteFloat(
    &encoder,
    y);
  this->LastX = x;
  this->LastY = y;
  this->Status = Status_EdgeTo;
}
