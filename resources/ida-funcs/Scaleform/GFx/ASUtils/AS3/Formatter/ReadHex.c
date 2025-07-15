unsigned __int16 __thiscall Scaleform::GFx::ASUtils::AS3::Formatter::ReadHex(
        Scaleform::GFx::ASUtils::AS3::Formatter *this,
        const char **pStr,
        const char *end,
        unsigned __int8 max_chars)
{
  unsigned __int16 v5; // di
  int v6; // ebp
  const char *v7; // edx
  char v8; // cl
  unsigned __int8 v9; // cl
  unsigned __int16 result; // ax
  const char *prev_ptr; // [esp+10h] [ebp+4h]

  prev_ptr = *pStr;
  v5 = 0;
  v6 = 0;
  if ( max_chars )
  {
    do
    {
      v7 = *pStr;
      if ( *pStr >= end )
        break;
      v8 = *v7;
      if ( (*v7 < 48 || v8 > 57) && (v8 < 65 || v8 > 70) && (unsigned __int8)(v8 - 97) > 5u )
        break;
      *pStr = v7 + 1;
      if ( (unsigned __int8)(v8 - 48) > 9u )
      {
        if ( (unsigned __int8)(v8 - 65) > 5u )
          v9 = (unsigned __int8)(v8 - 97) > 5u ? 0 : v8 - 87;
        else
          v9 = v8 - 55;
      }
      else
      {
        v9 = v8 - 48;
      }
      ++v6;
      v5 = v9 | (unsigned __int16)(16 * v5);
    }
    while ( v6 < max_chars );
  }
  result = v5;
  if ( *pStr - prev_ptr < max_chars )
    *pStr = prev_ptr;
  return result;
}
