unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx

  v2 = v;
  if ( v > 0x7F )
  {
    LOBYTE(v) = (2 * v) | 1;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      this->Data,
      (unsigned __int8 *)&v);
    Data = this->Data;
    LOBYTE(v) = v2 >> 7;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      Data,
      (unsigned __int8 *)&v);
    return 2;
  }
  else
  {
    v4 = this->Data;
    LOBYTE(v) = 2 * v;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v4,
      (unsigned __int8 *)&v);
    return 1;
  }
}
