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
  Scaleform::StringDataPtr impl_param_str; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::StringDataPtr token; // [esp+10h] [ebp-14h] BYREF
  Scaleform::FormatterFactory::Args args; // [esp+18h] [ebp-Ch] BYREF

  Scaleform::StringDataPtr::GetNextToken(str, &token, 58);
  if ( token.pStr && token.Size )
  {
    if ( *token.pStr == 115 && *((_BYTE *)token.pStr + 1) == 119 )
    {
      Size = str->Size;
      v4 = token.Size + 1;
      if ( Size < token.Size + 1 )
        v4 = str->Size;
      pStr = str->pStr;
      impl_param_str.Size = Size - v4;
      impl_param_str.pStr = &pStr[v4];
      NextToken = Scaleform::StringDataPtr::GetNextToken(&impl_param_str, (Scaleform::StringDataPtr *)&args, 58);
      v7 = (*((_BYTE *)this + 12) & 1) == 0;
      this->result.pStr = NextToken->pStr;
      v8 = NextToken->Size;
      this->result.Size = v8;
      if ( v7 )
      {
        Scaleform::StringDataPtr::TrimLeft(&impl_param_str, v8 + 1);
        this->result = *Scaleform::StringDataPtr::GetNextToken(&impl_param_str, (Scaleform::StringDataPtr *)&args, 58);
      }
      *((_BYTE *)this + 12) |= 2u;
    }
    else
    {
      pParentFmt = this->pParentFmt;
      if ( pParentFmt->pLocaleProvider )
      {
        args.Name = &token;
        args.Value = (const Scaleform::ResourceFormatter::ValueType *)&args;
        args.Fmt = pParentFmt;
        v10 = pParentFmt->pLocaleProvider->MakeFormatter(pParentFmt->pLocaleProvider, &args);
        if ( v10 )
        {
          v11 = str->Size;
          v12 = token.Size + 1;
          if ( v11 < token.Size + 1 )
            v12 = str->Size;
          impl_param_str.pStr = &str->pStr[v12];
          impl_param_str.Size = v11 - v12;
          if ( v11 != v12 )
            v10->Parse(v10, &impl_param_str);
          Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v10, 1);
        }
      }
    }
  }
}
