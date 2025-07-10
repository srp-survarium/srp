unsigned int __thiscall Scaleform::Render::TextLayout::ReadNext(
        Scaleform::Render::TextLayout *this,
        unsigned int pos,
        Scaleform::Render::TextLayout::Record *rec)
{
  unsigned int result; // eax
  unsigned __int8 v4; // dl
  unsigned __int8 *p_Flags; // esi
  unsigned int i; // edx

  if ( pos >= this->DataSize )
    return 0;
  v4 = this->Data.Data.Data[pos];
  rec->mChar.Tag = v4;
  p_Flags = &rec->mChar.Flags;
  result = pos + 1;
  for ( i = TextLayout_RecordSizes[v4] - 1; i; --i )
    *p_Flags++ = this->Data.Data.Data[result++];
  return result;
}
