unsigned int __thiscall Scaleform::String::GetNextChar(Scaleform::String *this, char **offset)
{
  unsigned int result; // eax

  result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)offset);
  if ( !result )
    --*offset;
  return result;
}
