char *__stdcall Scaleform::GFx::NumberUtil::IntToString(int value, char *destStr, unsigned int destStrSize, int radix)
{
  unsigned int v4; // ebp
  char *result; // eax
  unsigned int v6; // edx
  unsigned int v7; // esi
  char v8; // cl
  char v9; // cl
  unsigned int v10; // ecx
  unsigned int v11; // esi
  char v12; // dl
  char *v13; // esi
  int v14; // edx
  unsigned int i; // ecx

  v4 = destStrSize - 1;
  result = &destStr[destStrSize - 1];
  *result = 0;
  switch ( radix )
  {
    case 2:
      v13 = 0;
      v14 = 1;
      for ( i = 0; i < 0x20; ++i )
      {
        if ( i >= v4 )
          break;
        --result;
        if ( (v14 & value) != 0 )
        {
          *result = 49;
          v13 = result;
        }
        else
        {
          *result = 48;
        }
        v14 *= 2;
        if ( !v14 )
          v14 = 1;
      }
      if ( v13 )
        return v13;
      else
        return &destStr[destStrSize - 2];
    case 8:
      v10 = value;
      v11 = 0;
      if ( destStrSize != 1 )
      {
        do
        {
          --result;
          v12 = (v10 & 7) + 48;
          v10 >>= 3;
          *result = v12;
          if ( !v10 )
            break;
          ++v11;
        }
        while ( v11 < v4 );
      }
      break;
    case 16:
      v6 = value;
      v7 = 0;
      if ( destStrSize != 1 )
      {
        do
        {
          --result;
          v8 = v6 & 0xF;
          if ( (v6 & 0xF) > 9 )
            v9 = v8 + 87;
          else
            v9 = v8 + 48;
          v6 >>= 4;
          *result = v9;
          if ( !v6 )
            break;
          ++v7;
        }
        while ( v7 < v4 );
      }
      break;
    default:
      return Scaleform::GFx::NumberUtil::IntToString(value, destStr, destStrSize);
  }
  return result;
}
