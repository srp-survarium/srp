int __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphIndex(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned __int16 code)
{
  signed int v2; // edi
  int v3; // ebx
  int result; // eax
  unsigned int v5; // edx
  unsigned int GlyphInfoTablePos; // [esp+10h] [ebp-4h]

  v2 = this->NumGlyphs - 1;
  v3 = 0;
  if ( v2 < 0 )
    return -1;
  while ( 1 )
  {
    result = (v3 + v2) / 2;
    GlyphInfoTablePos = this->GlyphInfoTablePos;
    v5 = this->Decoder.Data->Pages[(GlyphInfoTablePos + 8 * result) >> 12][(GlyphInfoTablePos + 8 * result) & 0xFFF]
       | (this->Decoder.Data->Pages[(GlyphInfoTablePos + 8 * result + 1) >> 12][(GlyphInfoTablePos + 8 * result + 1)
                                                                              & 0xFFF] << 8);
    if ( code == v5 )
      break;
    if ( code >= v5 )
      v3 = result + 1;
    else
      v2 = result - 1;
    if ( v3 > v2 )
      return -1;
  }
  return result;
}
