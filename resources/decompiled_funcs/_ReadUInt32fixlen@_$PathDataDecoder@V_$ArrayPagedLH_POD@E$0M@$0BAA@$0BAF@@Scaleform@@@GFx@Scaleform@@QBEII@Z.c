int __thiscall Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
        Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos)
{
  unsigned __int8 **Pages; // ecx

  Pages = this->Data->Pages;
  return Pages[pos >> 12][pos & 0xFFF]
       | ((Pages[(pos + 1) >> 12][(pos + 1) & 0xFFF]
         | ((Pages[(pos + 2) >> 12][(pos + 2) & 0xFFF] | (Pages[(pos + 3) >> 12][(pos + 3) & 0xFFF] << 8)) << 8)) << 8);
}
