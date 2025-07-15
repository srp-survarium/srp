unsigned int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadSInt15(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos,
        int *v)
{
  unsigned __int8 **Pages; // edx
  int v4; // eax

  Pages = this->Data->Pages;
  v4 = (char)Pages[pos >> 12][pos & 0xFFF];
  if ( (v4 & 1) != 0 )
  {
    *v = (v4 >> 1) & 0x7F | ((char)Pages[(pos + 1) >> 12][(pos + 1) & 0xFFF] << 7);
    return 2;
  }
  else
  {
    *v = v4 >> 1;
    return 1;
  }
}
