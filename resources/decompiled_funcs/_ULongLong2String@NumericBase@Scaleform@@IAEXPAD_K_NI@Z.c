void __thiscall Scaleform::NumericBase::ULongLong2String(
        Scaleform::NumericBase *this,
        char *buff,
        unsigned __int64 value,
        bool separator,
        unsigned int base)
{
  int v7; // edi
  char *ValueStr; // ebp
  unsigned __int64 v9; // rcx
  char *v10; // ebp
  char v11; // bl
  const char *chars; // [esp+18h] [ebp+10h]

  if ( !separator || base != 10 || (v7 = 3, (*((_BYTE *)this + 5) & 0x7F) == 0) )
    v7 = 1000;
  chars = "0123456789ABCDEF";
  if ( (*((_BYTE *)this + 6) & 1) == 0 )
    chars = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    do
    {
      ValueStr = this->ValueStr;
      if ( buff == ValueStr )
        break;
      v9 = value % base;
      value /= base;
      if ( !v7 )
      {
        v10 = ValueStr - 1;
        v11 = (char)(2 * *((_BYTE *)this + 5)) >> 1;
        this->ValueStr = v10;
        v7 = 3;
        *v10 = v11;
      }
      *--this->ValueStr = chars[(unsigned __int8)v9];
      --v7;
    }
    while ( value );
  }
}
