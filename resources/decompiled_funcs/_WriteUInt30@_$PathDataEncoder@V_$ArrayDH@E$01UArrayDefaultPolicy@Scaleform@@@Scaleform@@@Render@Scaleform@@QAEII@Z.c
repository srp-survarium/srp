unsigned int __thiscall Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v4; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v6; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v7; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v8; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *Data; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v10; // ecx
  Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v11; // ecx

  v2 = v;
  if ( v > 0x3F )
  {
    if ( v > 0x3FFF )
    {
      if ( v > (unsigned int)&byte_3FFFFF )
      {
        Data = this->Data;
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        v10 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v10,
          (unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v11 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v11,
          (unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v7 = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v7,
          (unsigned __int8 *)&v);
        v8 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          v8,
          (unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      LOBYTE(v) = (4 * v) | 1;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        this->Data,
        (unsigned __int8 *)&v);
      v6 = this->Data;
      LOBYTE(v) = v2 >> 6;
      Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        v6,
        (unsigned __int8 *)&v);
      return 2;
    }
  }
  else
  {
    v4 = this->Data;
    LOBYTE(v) = 4 * v;
    Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned char,Scaleform::AllocatorDH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
      v4,
      (unsigned __int8 *)&v);
    return 1;
  }
}
