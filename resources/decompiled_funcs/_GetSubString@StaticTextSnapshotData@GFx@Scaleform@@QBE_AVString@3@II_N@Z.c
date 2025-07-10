Scaleform::String *__thiscall Scaleform::GFx::StaticTextSnapshotData::GetSubString(
        Scaleform::GFx::StaticTextSnapshotData *this,
        Scaleform::String *result,
        unsigned int start,
        unsigned int end,
        bool binclNewLines)
{
  Scaleform::String *v5; // esi
  Scaleform::String::DataDesc *pData; // eax
  unsigned int v8; // edi
  unsigned int v9; // ebp
  bool v10; // bl
  unsigned int Char_Advance0; // eax

  v5 = result;
  Scaleform::String::String(result);
  pData = this->SnapshotString.pData;
  v8 = start;
  v9 = end;
  result = (Scaleform::String *)(((unsigned int)pData & 0xFFFFFFFC) + 8);
  if ( start >= end )
    return v5;
  v10 = binclNewLines;
  do
  {
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&result);
    if ( !Char_Advance0 )
      break;
    if ( Char_Advance0 == 10 )
    {
      if ( v10 )
        Scaleform::String::AppendChar(v5, 0xAu);
    }
    else
    {
      Scaleform::String::AppendChar(v5, Char_Advance0);
      ++v8;
    }
  }
  while ( v8 < v9 );
  return v5;
}
