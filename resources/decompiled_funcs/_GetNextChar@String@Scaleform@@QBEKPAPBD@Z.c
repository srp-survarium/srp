unsigned int __thiscall Scaleform::String::GetNextChar(Scaleform::String *this, const char **offset)
{
  unsigned int result; // eax

  result = Scaleform::UTF8Util::DecodeNextChar_Advance0(offset);
  if ( !result )
    --*offset;
  return result;
}
