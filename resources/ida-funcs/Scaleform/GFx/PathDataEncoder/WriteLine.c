unsigned int __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::WriteLine(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        int x,
        int y)
{
  int v3; // ebx
  int v4; // eax
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v6; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v7; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v9; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v10; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v11; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v12; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v13; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v14; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v15; // ecx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // esi
  unsigned int v17; // ebp
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v18; // esi
  unsigned int v19; // ebp
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v20; // esi
  unsigned int v21; // ebp
  unsigned __int8 v22; // bl
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v23; // esi
  unsigned int v24; // ebp
  int v25; // ebx
  Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *v26; // edi
  unsigned int v27; // esi
  unsigned __int8 v28; // bl

  v3 = x;
  v4 = y;
  if ( (unsigned int)(x + 32) > 0x3F || (unsigned int)(y + 32) > 0x3F )
  {
    if ( (unsigned int)(x + 512) > 0x3FF || (unsigned int)(y + 512) > 0x3FF )
    {
      if ( (unsigned int)(x + 0x2000) > 0x3FFF || (unsigned int)(y + 0x2000) > 0x3FFF )
      {
        Data = this->Data;
        v17 = this->Data->Size >> 12;
        LOBYTE(x) = (16 * x) | 7;
        if ( v17 >= Data->NumPages )
        {
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            Data,
            v17);
          v4 = y;
        }
        Data->Pages[v17][Data->Size++ & 0xFFF] = x;
        v18 = this->Data;
        v19 = this->Data->Size >> 12;
        LOBYTE(x) = v3 >> 4;
        if ( v19 >= v18->NumPages )
        {
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            v18,
            v19);
          v4 = y;
        }
        v18->Pages[v19][v18->Size++ & 0xFFF] = x;
        v20 = this->Data;
        v21 = this->Data->Size >> 12;
        v22 = ((_BYTE)v4 << 6) | (v3 >> 12) & 0x3F;
        if ( v21 >= this->Data->NumPages )
        {
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            v20,
            this->Data->Size >> 12);
          v4 = y;
        }
        v20->Pages[v21][v20->Size++ & 0xFFF] = v22;
        v23 = this->Data;
        v24 = this->Data->Size >> 12;
        v25 = v4 >> 2;
        if ( v24 >= this->Data->NumPages )
        {
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            v23,
            this->Data->Size >> 12);
          v4 = y;
        }
        v23->Pages[v24][v23->Size++ & 0xFFF] = v25;
        v26 = this->Data;
        v27 = v26->Size >> 12;
        v28 = v4 >> 10;
        if ( v27 >= v26->NumPages )
          Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
            v26,
            v26->Size >> 12);
        v26->Pages[v27][v26->Size++ & 0xFFF] = v28;
        return 5;
      }
      else
      {
        v12 = this->Data;
        LOBYTE(x) = (16 * x) | 6;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v12,
          (unsigned __int8 *)&x);
        v13 = this->Data;
        LOBYTE(x) = v3 >> 4;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v13,
          (unsigned __int8 *)&x);
        v14 = this->Data;
        LOBYTE(x) = (4 * y) | (v3 >> 12) & 3;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v14,
          (unsigned __int8 *)&x);
        v15 = this->Data;
        LOBYTE(y) = y >> 6;
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
          v15,
          (unsigned __int8 *)&y);
        return 4;
      }
    }
    else
    {
      v9 = this->Data;
      LOBYTE(x) = (16 * x) | 5;
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        v9,
        (unsigned __int8 *)&x);
      v10 = this->Data;
      LOBYTE(x) = ((_BYTE)y << 6) | (v3 >> 4) & 0x3F;
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        v10,
        (unsigned __int8 *)&x);
      v11 = this->Data;
      LOBYTE(y) = y >> 2;
      Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
        v11,
        (unsigned __int8 *)&y);
      return 3;
    }
  }
  else
  {
    v6 = this->Data;
    LOBYTE(x) = (16 * x) | 4;
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
      v6,
      (unsigned __int8 *)&x);
    v7 = this->Data;
    LOBYTE(y) = (4 * y) | (v3 >> 4) & 3;
    Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::PushBack(
      v7,
      (unsigned __int8 *)&y);
    return 2;
  }
}
