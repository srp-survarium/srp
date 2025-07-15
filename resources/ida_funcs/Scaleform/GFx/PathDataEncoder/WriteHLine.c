unsigned int __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteHLine(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        int x)
{
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // esi
  unsigned int v5; // edi
  unsigned __int8 v6; // al
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v7; // esi
  unsigned int v8; // edi
  int v9; // ebx
  unsigned __int8 v11; // al
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v12; // esi
  int v13; // eax
  unsigned int v14; // edi
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v15; // esi
  unsigned int v16; // edi
  int v17; // ebx
  unsigned __int8 xa; // [esp+14h] [ebp+4h]
  unsigned __int8 xb; // [esp+14h] [ebp+4h]

  Data = this->Data;
  v5 = this->Data->Size >> 12;
  if ( (unsigned int)(x + 2048) > 0xFFF )
  {
    v11 = (16 * x) | 1;
    xb = v11;
    if ( v5 >= Data->NumPages )
    {
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Data,
        v5);
      v11 = xb;
    }
    Data->Pages[v5][Data->Size++ & 0xFFF] = v11;
    v12 = this->Data;
    v13 = x >> 4;
    v14 = this->Data->Size >> 12;
    if ( v14 >= this->Data->NumPages )
    {
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v12,
        v14);
      LOBYTE(v13) = x >> 4;
    }
    v12->Pages[v14][v12->Size++ & 0xFFF] = v13;
    v15 = this->Data;
    v16 = this->Data->Size >> 12;
    v17 = x >> 12;
    if ( v16 >= this->Data->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v15,
        this->Data->Size >> 12);
    v15->Pages[v16][v15->Size++ & 0xFFF] = v17;
    return 3;
  }
  else
  {
    v6 = 16 * x;
    xa = 16 * x;
    if ( v5 >= Data->NumPages )
    {
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Data,
        v5);
      v6 = xa;
    }
    Data->Pages[v5][Data->Size++ & 0xFFF] = v6;
    v7 = this->Data;
    v8 = this->Data->Size >> 12;
    v9 = x >> 4;
    if ( v8 >= this->Data->NumPages )
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        v7,
        this->Data->Size >> 12);
    v7->Pages[v8][v7->Size++ & 0xFFF] = v9;
    return 2;
  }
}
