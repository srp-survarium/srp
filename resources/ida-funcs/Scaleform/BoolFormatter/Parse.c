void __thiscall Scaleform::BoolFormatter::Parse(Scaleform::BoolFormatter *this, Scaleform::StringDataPtr *str)
{
  unsigned int Size; // eax
  unsigned int v4; // ecx
  const char *pStr; // edx
  Scaleform::StringDataPtr *NextToken; // eax
  bool v7; // zf
  unsigned int v8; // edx
  Scaleform::MsgFormat *pParentFmt; // eax
  Scaleform::Formatter *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  Scaleform::StringDataPtr v13; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::StringDataPtr result; // [esp+10h] [ebp-14h] BYREF
  Scaleform::StringDataPtr v15; // [esp+18h] [ebp-Ch] BYREF
  Scaleform::StringDataPtr *v16; // [esp+20h] [ebp-4h]

  Scaleform::StringDataPtr::GetNextToken(str, &result, 58);
  if ( result.pStr && result.Size )
  {
    if ( *result.pStr == 115 && *((_BYTE *)result.pStr + 1) == 119 )
    {
      Size = str->Size;
      v4 = result.Size + 1;
      if ( Size < result.Size + 1 )
        v4 = str->Size;
      pStr = str->pStr;
      v13.Size = Size - v4;
      v13.pStr = &pStr[v4];
      NextToken = Scaleform::StringDataPtr::GetNextToken(&v13, &v15, 58);
      v7 = (*((_BYTE *)this + 12) & 1) == 0;
      this->result.pStr = NextToken->pStr;
      v8 = NextToken->Size;
      this->result.Size = v8;
      if ( v7 )
      {
        Scaleform::StringDataPtr::TrimLeft(&v13, v8 + 1);
        this->result = *Scaleform::StringDataPtr::GetNextToken(&v13, &v15, 58);
      }
      *((_BYTE *)this + 12) |= 2u;
    }
    else
    {
      pParentFmt = this->pParentFmt;
      if ( pParentFmt->pLocaleProvider )
      {
        v15.Size = (unsigned int)&result;
        v16 = &v15;
        v15.pStr = (const char *)pParentFmt;
        v10 = pParentFmt->pLocaleProvider->MakeFormatter(
                pParentFmt->pLocaleProvider,
                (const Scaleform::FormatterFactory::Args *)&v15);
        if ( v10 )
        {
          v11 = str->Size;
          v12 = result.Size + 1;
          if ( v11 < result.Size + 1 )
            v12 = str->Size;
          v13.pStr = &str->pStr[v12];
          v13.Size = v11 - v12;
          if ( v11 != v12 )
            v10->Parse(v10, &v13);
          Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v10, 1);
        }
      }
    }
  }
}
