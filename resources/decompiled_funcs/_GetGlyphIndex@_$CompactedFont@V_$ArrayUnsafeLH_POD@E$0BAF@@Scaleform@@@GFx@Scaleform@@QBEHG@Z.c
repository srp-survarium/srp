int __thiscall Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261>>::GetGlyphIndex(
        Scaleform::GFx::CompactedFont<Scaleform::ArrayUnsafeLH_POD<unsigned char,261> > *this,
        unsigned __int16 code)
{
  signed int v2; // edi
  int v3; // ebx
  unsigned __int8 *Data; // esi
  int result; // eax
  unsigned int v6; // ecx
  unsigned int GlyphInfoTablePos; // [esp+10h] [ebp-4h]

  v2 = this->NumGlyphs - 1;
  v3 = 0;
  if ( v2 < 0 )
    return -1;
  Data = this->Decoder.Data->Data;
  GlyphInfoTablePos = this->GlyphInfoTablePos;
  while ( 1 )
  {
    result = (v3 + v2) / 2;
    v6 = *(unsigned __int16 *)&Data[8 * result + GlyphInfoTablePos];
    if ( code == v6 )
      break;
    if ( code >= v6 )
      v3 = result + 1;
    else
      v2 = result - 1;
    if ( v3 > v2 )
      return -1;
  }
  return result;
}
