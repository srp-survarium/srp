void __thiscall Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::UpdateUInt32fixlen(
        Scaleform::GFx::PathDataEncoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int pos,
        unsigned int v)
{
  this->Data->Pages[pos >> 12][pos & 0xFFF] = v;
  this->Data->Pages[(pos + 1) >> 12][(pos + 1) & 0xFFF] = BYTE1(v);
  this->Data->Pages[(pos + 2) >> 12][(pos + 2) & 0xFFF] = BYTE2(v);
  this->Data->Pages[(pos + 3) >> 12][(pos + 3) & 0xFFF] = HIBYTE(v);
}
