void __thiscall Scaleform::NumericBase::ULong2String(
        Scaleform::NumericBase *this,
        char *buff,
        unsigned int value,
        bool separator,
        unsigned int base)
{
  int v6; // esi
  const char *v7; // ebp
  char *ValueStr; // edi
  unsigned __int8 v9; // dl
  unsigned int v10; // et2
  char *v11; // edi
  char v12; // bl

  if ( !separator || base != 10 || (v6 = 3, (*((_BYTE *)this + 5) & 0x7F) == 0) )
    v6 = 1000;
  v7 = "0123456789ABCDEF";
  if ( (*((_BYTE *)this + 6) & 1) == 0 )
    v7 = "0123456789abcdef";
  if ( base - 2 <= 0xE )
  {
    do
    {
      ValueStr = this->ValueStr;
      if ( buff == ValueStr )
        break;
      v10 = value % base;
      value /= base;
      v9 = v10;
      if ( !v6 )
      {
        v11 = ValueStr - 1;
        v12 = (char)(2 * *((_BYTE *)this + 5)) >> 1;
        this->ValueStr = v11;
        v6 = 3;
        *v11 = v12;
      }
      --this->ValueStr;
      --v6;
      *this->ValueStr = v7[v9];
    }
    while ( value );
  }
}
