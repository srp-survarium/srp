char *__stdcall Scaleform::GFx::NumberUtil::IntToString(int value, char *destStr, unsigned int destStrSize)
{
  unsigned int v3; // ecx
  unsigned int v4; // edi
  char *v5; // esi
  unsigned int v6; // ebp

  v3 = value;
  v4 = destStrSize - 1;
  v5 = &destStr[destStrSize - 1];
  *v5 = 0;
  if ( value < 0 )
    v3 = -value;
  v6 = 0;
  if ( destStrSize != 1 )
  {
    while ( 1 )
    {
      *--v5 = v3 % 0xA + 48;
      v3 /= 0xAu;
      if ( !v3 )
        break;
      if ( ++v6 >= v4 )
        return v5;
    }
    if ( v6 < v4 && value < 0 )
      *--v5 = 45;
  }
  return v5;
}
