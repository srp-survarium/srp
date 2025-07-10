char __thiscall Scaleform::MsgFormat::NextFormatter(Scaleform::MsgFormat *this)
{
  unsigned int Size; // ebp
  unsigned int UnboundFmtrInd; // esi
  char v3; // bl
  unsigned int i; // edi
  char *v5; // edx

  Size = this->Data.Size;
  UnboundFmtrInd = this->UnboundFmtrInd;
  v3 = 1;
  this->DataInd = -1;
  if ( UnboundFmtrInd >= Size )
    return 0;
  for ( i = UnboundFmtrInd; ; ++i )
  {
    if ( UnboundFmtrInd >= 0x10 )
      v5 = (char *)&this->Data.DynamicArray.Data.Data[i - 16];
    else
      v5 = &this->Data.StaticArray[i * 12];
    if ( *(_DWORD *)v5 != 1 )
    {
      if ( v3 )
        ++this->UnboundFmtrInd;
      goto LABEL_12;
    }
    if ( BYTE1(*((_DWORD *)v5 + 2)) == this->FirstArgNum )
      break;
    if ( v3 )
      v3 = 0;
LABEL_12:
    if ( ++UnboundFmtrInd >= Size )
      return 0;
  }
  if ( v3 )
    ++this->UnboundFmtrInd;
  this->DataInd = UnboundFmtrInd;
  return 1;
}
