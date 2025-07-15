void __thiscall Scaleform::MsgFormat::Bind(
        Scaleform::MsgFormat *this,
        Scaleform::Formatter *formatter,
        const bool allocated)
{
  unsigned int DataInd; // eax
  char *v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ebx
  char *v9; // eax
  Scaleform::Formatter_vtbl *v10; // eax
  int v11; // [esp+10h] [ebp-10h] BYREF
  int v12; // [esp+14h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-8h]

  DataInd = this->DataInd;
  if ( DataInd >= 0x10 )
    v5 = (char *)&this->Data.DynamicArray.Data.Data[DataInd - 16];
  else
    v5 = &this->Data.StaticArray[12 * DataInd];
  v6 = *((_DWORD *)v5 + 1);
  v7 = *((_DWORD *)v5 + 2);
  v13 = v6;
  LOBYTE(v12) = allocated;
  v8 = v12;
  if ( DataInd >= 0x10 )
    v9 = (char *)&this->Data.DynamicArray.Data.Data[DataInd - 16];
  else
    v9 = &this->Data.StaticArray[12 * DataInd];
  *(_DWORD *)v9 = 2;
  *((_DWORD *)v9 + 1) = formatter;
  *((_DWORD *)v9 + 2) = v8;
  if ( (_BYTE)v7 )
  {
    v10 = formatter->__vftable;
    v11 = v13;
    v12 = (unsigned __int8)v7;
    v10->Parse(formatter, (const Scaleform::StringDataPtr *)&v11);
  }
}
