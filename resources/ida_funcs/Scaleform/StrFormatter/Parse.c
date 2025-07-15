void __thiscall Scaleform::StrFormatter::Parse(Scaleform::StrFormatter *this, Scaleform::StringDataPtr *str)
{
  Scaleform::MsgFormat *pParentFmt; // eax
  Scaleform::Formatter *v4; // edi
  unsigned int Size; // eax
  unsigned int v6; // ecx
  Scaleform::StringDataPtr token; // [esp+8h] [ebp-1Ch] BYREF
  Scaleform::StringDataPtr impl_param_str; // [esp+10h] [ebp-14h] BYREF
  Scaleform::FormatterFactory::Args args; // [esp+18h] [ebp-Ch] BYREF

  Scaleform::StringDataPtr::GetNextToken(str, &token, 58);
  pParentFmt = this->pParentFmt;
  if ( pParentFmt )
  {
    if ( pParentFmt->pLocaleProvider )
    {
      args.Name = &token;
      args.Value = (const Scaleform::ResourceFormatter::ValueType *)&args;
      args.Fmt = pParentFmt;
      v4 = pParentFmt->pLocaleProvider->MakeFormatter(pParentFmt->pLocaleProvider, &args);
      if ( v4 )
      {
        Size = str->Size;
        v6 = token.Size + 1;
        if ( Size < token.Size + 1 )
          v6 = str->Size;
        impl_param_str.pStr = &str->pStr[v6];
        impl_param_str.Size = Size - v6;
        if ( Size != v6 )
          v4->Parse(v4, &impl_param_str);
        Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v4, 1);
      }
    }
  }
}
