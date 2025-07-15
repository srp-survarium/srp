double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphHeight(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int glyphIndex)
{
  unsigned int GlyphInfoTablePos; // eax
  unsigned int UInt32fixlen; // eax
  __int16 YMin; // cx
  __int16 YMax; // ax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > v7; // [esp+0h] [ebp-28h] BYREF

  GlyphInfoTablePos = this->GlyphInfoTablePos;
  v7.Data.Data = this->Decoder.Data;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&this->Decoder,
                   GlyphInfoTablePos + 8 * glyphIndex + 4);
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    &v7,
    UInt32fixlen);
  if ( v7.XMin >= v7.XMax || (YMin = v7.YMin, YMax = v7.YMax, v7.YMin >= v7.YMax) )
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
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > v7; // [esp+0h] [ebp-28h] BYREF

  GlyphInfoTablePos = this->GlyphInfoTablePos;
  v7.Data.Data = this->Decoder.Data;
  v3 = GlyphInfoTablePos + 8 * glyphIndex + 4;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    &v7,
    v7.Data.Data->Data[v3]
  | ((v7.Data.Data->Data[v3 + 1] | ((v7.Data.Data->Data[v3 + 2] | (v7.Data.Data->Data[v3 + 3] << 8)) << 8)) << 8));
  if ( v7.XMin >= v7.XMax || (YMin = v7.YMin, YMax = v7.YMax, v7.YMin >= v7.YMax) )
  {
    YMax = 0;
    YMin = 0;
  }
  return (double)(YMax - YMin);
}
