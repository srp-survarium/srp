unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt30(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos,
        unsigned int *v)
{
  const Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> *Data; // edi
  unsigned __int8 **Pages; // esi
  int v5; // eax
  unsigned int v6; // edx

  Pages = this->Data->Pages;
  v5 = Pages[pos >> 12][pos & 0xFFF] >> 2;
  if ( (Pages[pos >> 12][pos & 0xFFF] & 3) != 0 )
  {
    if ( (Pages[pos >> 12][pos & 0xFFF] & 3) == 1 )
    {
      *v = v5 | (Pages[(pos + 1) >> 12][(pos + 1) & 0xFFF] << 6);
      return 2;
    }
    else
    {
      v6 = pos + 1;
      if ( (Pages[pos >> 12][pos & 0xFFF] & 3) == 2 )
      {
        *v = v5 | ((Pages[v6 >> 12][v6 & 0xFFF] | (Pages[(pos + 2) >> 12][(pos + 2) & 0xFFF] << 8)) << 6);
        return 3;
      }
      else
      {
        Data = this->Data;
        *v = v5
           | ((Data->Pages[v6 >> 12][v6 & 0xFFF]
             | ((Data->Pages[(pos + 2) >> 12][(pos + 2) & 0xFFF] | (Data->Pages[(pos + 3) >> 12][(pos + 3) & 0xFFF] << 8)) << 8)) << 6);
        return 4;
      }
    }
  }
  else
  {
    *v = v5;
    return 1;
  }
}
