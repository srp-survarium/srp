Scaleform::StringDataPtr *__thiscall Scaleform::StringDataPtr::GetTruncateWhitespace(
        Scaleform::StringDataPtr *this,
        Scaleform::StringDataPtr *result)
{
  char *pStr; // eax
  const char *v4; // esi
  char v5; // bl
  const char *v6; // ebp
  bool v7; // zf
  unsigned int Char_Advance0; // eax
  Scaleform::StringDataPtr *v9; // eax
  char *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // eax
  char *v13; // [esp+10h] [ebp-8h] BYREF
  char *putf8Buffer; // [esp+14h] [ebp-4h] BYREF

  pStr = (char *)this->pStr;
  v4 = &this->pStr[this->Size];
  v5 = 0;
  putf8Buffer = pStr;
  v6 = pStr;
  v7 = pStr == v4;
  if ( pStr < v4 )
  {
    while ( 1 )
    {
      v6 = pStr;
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
      if ( Char_Advance0 != 32
        && Char_Advance0 != 10
        && Char_Advance0 != 13
        && Char_Advance0 != 9
        && Char_Advance0 != 12
        && Char_Advance0 != 11
        && (Char_Advance0 < 0x2000 || Char_Advance0 > 0x200B)
        && Char_Advance0 != 8232
        && Char_Advance0 != 8233
        && Char_Advance0 != 8287
        && Char_Advance0 != 12288 )
      {
        break;
      }
      pStr = putf8Buffer;
      if ( putf8Buffer >= v4 )
        goto LABEL_17;
    }
    pStr = putf8Buffer;
    v5 = 1;
LABEL_17:
    v7 = pStr == v4;
  }
  if ( !v7 || v5 )
  {
    v13 = pStr;
    v10 = pStr;
    while ( v13 < v4 )
    {
      v11 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v13);
      if ( v11 == 32
        || v11 == 10
        || v11 == 13
        || v11 == 9
        || v11 == 12
        || v11 == 11
        || v11 >= 0x2000 && v11 <= 0x200B
        || v11 == 8232
        || v11 == 8233
        || v11 == 8287
        || v11 == 12288 )
      {
        if ( v13 >= v4 )
          break;
        while ( 1 )
        {
          v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&v13);
          if ( v12 != 32
            && v12 != 10
            && v12 != 13
            && v12 != 9
            && v12 != 12
            && v12 != 11
            && (v12 < 0x2000 || v12 > 0x200B)
            && v12 != 8232
            && v12 != 8233
            && v12 != 8287
            && v12 != 12288 )
          {
            break;
          }
          if ( v13 >= v4 )
            goto LABEL_51;
        }
      }
      else
      {
        v10 = v13;
      }
    }
LABEL_51:
    if ( v6 == this->pStr && v10 == v4 )
    {
      v9 = result;
      *result = *this;
    }
    else
    {
      v9 = result;
      result->pStr = v6;
      result->Size = v10 - v6;
    }
  }
  else
  {
    v9 = result;
    result->pStr = 0;
    result->Size = 0;
  }
  return v9;
}
