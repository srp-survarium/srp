unsigned int __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteUInt15(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int v)
{
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // esi
  unsigned int v5; // edi
  unsigned int result; // eax
  unsigned __int8 v7; // al
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v8; // esi
  unsigned int v9; // edi
  unsigned int v10; // ebx
  unsigned __int8 va; // [esp+14h] [ebp+4h]

  Data = this->Data;
  v5 = this->Data->Size >> 12;
  if ( v > 0x7F )
  {
    v7 = (2 * v) | 1;
    va = v7;
    if ( v5 >= Data->NumPages )
    {
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Data,
        v5);
      v7 = va;
    }
    Data->Pages[v5][Data->Size++ & 0xFFF] = v7;
    v8 = this->Data;
    v9 = this->Data->Size >> 12;
    v10 = v >> 7;
    if ( v9 >= this->Data->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v8,
        this->Data->Size >> 12);
    v8->Pages[v9][v8->Size++ & 0xFFF] = v10;
    return 2;
  }
  else
  {
    if ( v5 >= Data->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Data,
        this->Data->Size >> 12);
    Data->Pages[v5][Data->Size & 0xFFF] = 2 * v;
    result = 1;
    ++Data->Size;
  }
  return result;
}
