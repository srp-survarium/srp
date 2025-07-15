void __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt32fixlen(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int v)
{
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // esi
  unsigned int v4; // edi
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // edi
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v11; // esi
  unsigned int v12; // edi

  Data = this->Data;
  v4 = this->Data->Size >> 12;
  if ( v4 >= this->Data->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      Data,
      this->Data->Size >> 12);
  Data->Pages[v4][Data->Size++ & 0xFFF] = v;
  v5 = this->Data;
  v6 = v >> 8;
  v7 = this->Data->Size >> 12;
  if ( v7 >= this->Data->NumPages )
  {
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      v5,
      v7);
    LOBYTE(v6) = BYTE1(v);
  }
  v5->Pages[v7][v5->Size++ & 0xFFF] = v6;
  v8 = this->Data;
  v9 = HIWORD(v);
  v10 = this->Data->Size >> 12;
  if ( v10 >= this->Data->NumPages )
  {
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      v8,
      v10);
    LOBYTE(v9) = BYTE2(v);
  }
  v8->Pages[v10][v8->Size++ & 0xFFF] = v9;
  v11 = this->Data;
  v12 = this->Data->Size >> 12;
  if ( v12 >= this->Data->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      v11,
      this->Data->Size >> 12);
  v11->Pages[v12][v11->Size++ & 0xFFF] = HIBYTE(v);
}
