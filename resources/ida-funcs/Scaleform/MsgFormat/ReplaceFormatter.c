char __thiscall Scaleform::MsgFormat::ReplaceFormatter(
        Scaleform::MsgFormat *this,
        Scaleform::Formatter *oldf,
        Scaleform::Formatter *newf,
        bool allocated)
{
  unsigned int Size; // edi
  unsigned int v5; // esi
  int i; // edx
  Scaleform::MsgFormat::fmt_record *v7; // eax
  int v9; // [esp+10h] [ebp-4h]

  Size = this->Data.Size;
  v5 = 0;
  if ( !Size )
    return 0;
  for ( i = 0; ; ++i )
  {
    v7 = v5 >= 0x10
       ? &this->Data.DynamicArray.Data.Data[i - 16]
       : (Scaleform::MsgFormat::fmt_record *)&this->Data.StaticArray[i * 12];
    if ( v7->RecType == eFmtType && v7->RecValue.Formatter.Formatter == oldf )
      break;
    if ( ++v5 >= Size )
      return 0;
  }
  LOBYTE(v9) = allocated;
  v7->RecType = eFmtType;
  v7->RecValue.String.Str = (const char *)newf;
  *(_DWORD *)&v7->RecValue.Formatter.Allocated = v9;
  return 1;
}
