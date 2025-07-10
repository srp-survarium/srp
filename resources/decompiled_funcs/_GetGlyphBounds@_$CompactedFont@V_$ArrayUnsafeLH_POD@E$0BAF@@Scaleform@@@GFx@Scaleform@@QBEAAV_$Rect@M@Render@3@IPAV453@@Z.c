Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphBounds(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  const Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *Data; // eax
  unsigned int v5; // edi
  unsigned __int8 *v6; // ecx
  int v7; // edx
  const Scaleform::ArrayUnsafeLH_POD<unsigned char,261> *v8; // eax
  __int16 *v9; // eax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > it; // [esp+8h] [ebp-28h] BYREF

  Data = this->Decoder.Data;
  v5 = this->GlyphInfoTablePos + 8 * glyphIndex;
  v6 = Data->Data;
  v7 = Data->Data[v5 + 7];
  it.Data.Data = Data;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    &it,
    v6[v5 + 4] | ((v6[v5 + 5] | ((v6[v5 + 6] | (v7 << 8)) << 8)) << 8));
  if ( it.XMin >= it.XMax || it.YMin >= it.YMax )
  {
    it.YMax = 0;
    v8 = this->Decoder.Data;
    it.YMin = 0;
    v9 = (__int16 *)&v8->Data[v5 + 2];
    it.XMin = 0;
    it.XMax = *v9;
  }
  return Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetBounds(&it, prect);
}
