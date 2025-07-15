void __thiscall Scaleform::ResourceFormatter::Parse(Scaleform::ResourceFormatter *this, Scaleform::StringDataPtr *str)
{
  Scaleform::MsgFormat *pParentFmt; // ecx
  Scaleform::Formatter *v4; // esi
  unsigned int Size; // eax
  unsigned int v6; // edx
  unsigned int v7; // eax
  Scaleform::StringDataPtr impl_param_str; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::StringDataPtr token; // [esp+14h] [ebp-14h] BYREF
  Scaleform::FormatterFactory::Args args; // [esp+1Ch] [ebp-Ch] BYREF

  impl_param_str.pStr = 0;
  impl_param_str.Size = 0;
  Scaleform::StringDataPtr::GetNextToken(str, &token, 58);
  pParentFmt = this->pParentFmt;
  v4 = 0;
  if ( pParentFmt->pLocaleProvider )
  {
    args.Name = &token;
    args.Value = &this->Value;
    args.Fmt = pParentFmt;
    v4 = pParentFmt->pLocaleProvider->MakeFormatter(pParentFmt->pLocaleProvider, &args);
  }
  Size = str->Size;
  v6 = token.Size + 1;
  if ( Size < token.Size + 1 )
    v6 = str->Size;
  v7 = Size - v6;
  impl_param_str.pStr = &str->pStr[v6];
  impl_param_str.Size = v7;
  if ( v4 )
  {
    if ( v7 )
      v4->Parse(v4, &impl_param_str);
    Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v4, 1);
  }
}
