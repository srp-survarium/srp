double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphHeight(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int glyphIndex)
{
  unsigned int GlyphInfoTablePos; // eax
  int UInt32fixlen; // eax
  __int16 YMin; // cx
  __int16 YMax; // ax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > it; // [esp+0h] [ebp-28h] BYREF

  GlyphInfoTablePos = this->GlyphInfoTablePos;
  it.Data.Data = this->Decoder.Data;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&this->Decoder,
                   GlyphInfoTablePos + 8 * glyphIndex + 4);
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    &it,
    UInt32fixlen);
  if ( it.XMin >= it.XMax || (YMin = it.YMin, YMax = it.YMax, it.YMin >= it.YMax) )
  {
    YMax = 0;
    YMin = 0;
  }
  return (double)(YMax - YMin);
}


double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphHeight(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int glyphIndex)
{
  unsigned int GlyphInfoTablePos; // edx
  unsigned int v3; // eax
  __int16 YMin; // cx
  __int16 YMax; // ax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > it; // [esp+0h] [ebp-28h] BYREF

  GlyphInfoTablePos = this->GlyphInfoTablePos;
  it.Data.Data = this->Decoder.Data;
  v3 = GlyphInfoTablePos + 8 * glyphIndex + 4;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    &it,
    it.Data.Data->Data[v3]
  | ((it.Data.Data->Data[v3 + 1] | ((it.Data.Data->Data[v3 + 2] | (it.Data.Data->Data[v3 + 3] << 8)) << 8)) << 8));
  if ( it.XMin >= it.XMax || (YMin = it.YMin, YMax = it.YMax, it.YMin >= it.YMax) )
  {
    YMax = 0;
    YMin = 0;
  }
  return (double)(YMax - YMin);
}
