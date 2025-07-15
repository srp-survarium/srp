unsigned int __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt30(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int v)
{
  unsigned int v2; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v4; // ebp
  unsigned int v5; // esi
  unsigned __int8 v6; // bl
  unsigned int result; // eax
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v8; // esi
  unsigned __int8 v9; // al
  unsigned int v10; // edi
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v14; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v15; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v17; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v18; // ecx

  v2 = v;
  if ( v > 0x3F )
  {
    if ( v > 0x3FFF )
    {
      if ( v > (unsigned int)&loc_3FFFFE + 1 )
      {
        LOBYTE(v) = (4 * v) | 3;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        Data = this->Data;
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          Data,
          (unsigned __int8 *)&v);
        v17 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v17,
          (unsigned __int8 *)&v);
        v18 = this->Data;
        LOBYTE(v) = v2 >> 22;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v18,
          (unsigned __int8 *)&v);
        return 4;
      }
      else
      {
        v14 = this->Data;
        LOBYTE(v) = (4 * v) | 2;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v14,
          (unsigned __int8 *)&v);
        LOBYTE(v) = v2 >> 6;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          this->Data,
          (unsigned __int8 *)&v);
        v15 = this->Data;
        LOBYTE(v) = v2 >> 14;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v15,
          (unsigned __int8 *)&v);
        return 3;
      }
    }
    else
    {
      v8 = this->Data;
      v9 = (4 * v) | 1;
      v10 = this->Data->Size >> 12;
      LOBYTE(v) = v9;
      if ( v10 >= v8->NumPages )
      {
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v8,
          v10);
        v9 = v;
      }
      v8->Pages[v10][v8->Size++ & 0xFFF] = v9;
      v11 = this->Data;
      v12 = this->Data->Size >> 12;
      v13 = v2 >> 6;
      if ( v12 >= this->Data->NumPages )
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
          v11,
          this->Data->Size >> 12);
      v11->Pages[v12][v11->Size++ & 0xFFF] = v13;
      return 2;
    }
  }
  else
  {
    v4 = this->Data;
    v5 = this->Data->Size >> 12;
    v6 = 4 * v;
    if ( v5 >= this->Data->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v4,
        v4->Size >> 12);
    v4->Pages[v5][v4->Size & 0xFFF] = v6;
    result = 1;
    ++v4->Size;
  }
  return result;
}
