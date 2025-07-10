double __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphWidth(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int glyphIndex)
{
  const Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *Data; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ecx
  int v6; // edx
  __int16 XMin; // dx
  __int16 XMax; // ax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > it; // [esp+8h] [ebp-28h] BYREF

  Data = this->Decoder.Data;
  v4 = this->GlyphInfoTablePos + 8 * glyphIndex;
  v5 = Data->Data;
  v6 = Data->Data[v4 + 7];
  it.Data.Data = Data;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    &it,
    v5[v4 + 4] | ((v5[v4 + 5] | ((v5[v4 + 6] | (v6 << 8)) << 8)) << 8));
  XMin = it.XMin;
  XMax = it.XMax;
  if ( it.XMin >= it.XMax || it.YMin >= it.YMax )
  {
    XMin = 0;
    XMax = *(_WORD *)&this->Decoder.Data->Data[v4 + 2];
  }
  return (double)(XMax - XMin);
}
