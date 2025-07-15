void __thiscall Scaleform::StrFormatter::Parse(Scaleform::StrFormatter *this, Scaleform::StringDataPtr *str)
{
  Scaleform::MsgFormat *pParentFmt; // eax
  Scaleform::Formatter *v4; // edi
  unsigned int Size; // eax
  unsigned int v6; // ecx
  Scaleform::StringDataPtr result; // [esp+8h] [ebp-1Ch] BYREF
  _DWORD v8[2]; // [esp+10h] [ebp-14h] BYREF
  _DWORD v9[3]; // [esp+18h] [ebp-Ch] BYREF

  Scaleform::StringDataPtr::GetNextToken(str, &result, 58);
  pParentFmt = this->pParentFmt;
  if ( pParentFmt )
  {
    if ( pParentFmt->pLocaleProvider )
    {
      v9[1] = &result;
      v9[2] = v9;
      v9[0] = pParentFmt;
      v4 = pParentFmt->pLocaleProvider->MakeFormatter(
             pParentFmt->pLocaleProvider,
             (const Scaleform::FormatterFactory::Args *)v9);
      if ( v4 )
      {
        Size = str->Size;
        v6 = result.Size + 1;
        if ( Size < result.Size + 1 )
          v6 = str->Size;
        v8[0] = &str->pStr[v6];
        v8[1] = Size - v6;
        if ( Size != v6 )
          v4->Parse(v4, (const Scaleform::StringDataPtr *)v8);
        Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v4, 1);
      }
    }
  }
}
