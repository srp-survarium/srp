Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetGlyphBounds(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  const Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *p_Decoder; // esi
  unsigned int v4; // edi
  unsigned int UInt32fixlen; // eax
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > v7; // [esp+8h] [ebp-28h] BYREF

  p_Decoder = &this->Decoder;
  v4 = this->GlyphInfoTablePos + 8 * glyphIndex;
  v7.Data.Data = this->Decoder.Data;
  UInt32fixlen = Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadUInt32fixlen(
                   (Scaleform::GFx::PathDataDecoder<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261> > *)&this->Decoder,
                   v4 + 4);
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::ReadBounds(
    &v7,
    UInt32fixlen);
  if ( v7.XMin >= v7.XMax || v7.YMin >= v7.YMax )
  {
    v7.YMax = 0;
    v7.YMin = 0;
    v7.XMin = 0;
    LOBYTE(v7.XMax) = p_Decoder->Data->Pages[(v4 + 2) >> 12][(v4 + 2) & 0xFFF];
    HIBYTE(v7.XMax) = p_Decoder->Data->Pages[(v4 + 3) >> 12][(v4 + 3) & 0xFFF];
  }
  return Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetBounds(
           (Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *)&v7,
           prect);
}


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
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > v11; // [esp+8h] [ebp-28h] BYREF

  Data = this->Decoder.Data;
  v5 = this->GlyphInfoTablePos + 8 * glyphIndex;
  v6 = Data->Data;
  v7 = Data->Data[v5 + 7];
  v11.Data.Data = Data;
  Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::ReadBounds(
    &v11,
    v6[v5 + 4] | ((v6[v5 + 5] | ((v6[v5 + 6] | (v7 << 8)) << 8)) << 8));
  if ( v11.XMin >= v11.XMax || v11.YMin >= v11.YMax )
  {
    v11.YMax = 0;
    v8 = this->Decoder.Data;
    v11.YMin = 0;
    v9 = (__int16 *)&v8->Data[v5 + 2];
    v11.XMin = 0;
    v11.XMax = *v9;
  }
  return Scaleform::GFx::GlyphPathIterator<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::GetBounds(
           &v11,
           prect);
}
