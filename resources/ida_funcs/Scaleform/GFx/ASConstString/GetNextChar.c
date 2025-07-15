unsigned int __thiscall Scaleform::GFx::ASConstString::GetNextChar(
        Scaleform::GFx::ASConstString *this,
        const char **offset)
{
  unsigned int result; // eax

  if ( (this->pNode->HashFlags & 0x8000000) != 0 )
  {
    return *(*offset)++;
  }
  else
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0(offset);
    if ( !result )
      --*offset;
  }
  return result;
}
