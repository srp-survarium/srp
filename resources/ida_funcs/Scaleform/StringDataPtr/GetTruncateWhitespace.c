Scaleform::StringDataPtr *__thiscall Scaleform::StringDataPtr::GetTruncateWhitespace(
        Scaleform::StringDataPtr *this,
        Scaleform::StringDataPtr *result)
{
  const char *pStr; // eax
  const char *v4; // esi
  char v5; // bl
  const char *v6; // ebp
  bool v7; // zf
  unsigned int v8; // eax
  Scaleform::StringDataPtr *v9; // eax
  const char *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // eax
  const char *l; // [esp+10h] [ebp-8h] BYREF
  const char *b; // [esp+14h] [ebp-4h] BYREF

  pStr = this->pStr;
  v4 = &this->pStr[this->Size];
  v5 = 0;
  b = pStr;
  v6 = pStr;
  v7 = pStr == v4;
  if ( pStr < v4 )
  {
    while ( 1 )
    {
      v6 = pStr;
      v8 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&b);
      if ( v8 != 32
        && v8 != 10
        && v8 != 13
        && v8 != 9
        && v8 != 12
        && v8 != 11
        && (v8 < 0x2000 || v8 > 0x200B)
        && v8 != 8232
        && v8 != 8233
        && v8 != 8287
        && v8 != 12288 )
      {
        break;
      }
      pStr = b;
      if ( b >= v4 )
        goto LABEL_17;
    }
    pStr = b;
    v5 = 1;
LABEL_17:
    v7 = pStr == v4;
  }
  if ( !v7 || v5 )
  {
    l = pStr;
    v10 = pStr;
    while ( l < v4 )
    {
      v11 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&l);
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
        if ( l >= v4 )
          break;
        while ( 1 )
        {
          v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0(&l);
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
          if ( l >= v4 )
            goto LABEL_51;
        }
      }
      else
      {
        v10 = l;
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
