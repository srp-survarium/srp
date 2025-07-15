void __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt16fixlen(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        __int16 v)
{
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // esi
  unsigned int v4; // edi
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v5; // esi
  unsigned int v6; // edi

  Data = this->Data;
  v4 = this->Data->Size >> 12;
  if ( v4 >= this->Data->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      Data,
      this->Data->Size >> 12);
  Data->Pages[v4][Data->Size++ & 0xFFF] = v;
  v5 = this->Data;
  v6 = this->Data->Size >> 12;
  if ( v6 >= this->Data->NumPages )
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
      v5,
      this->Data->Size >> 12);
  v5->Pages[v6][v5->Size++ & 0xFFF] = HIBYTE(v);
}
