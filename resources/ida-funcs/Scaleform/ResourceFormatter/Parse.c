void __thiscall Scaleform::ResourceFormatter::Parse(Scaleform::ResourceFormatter *this, Scaleform::StringDataPtr *str)
{
  Scaleform::MsgFormat *pParentFmt; // ecx
  Scaleform::Formatter *v4; // esi
  unsigned int Size; // eax
  unsigned int v6; // edx
  unsigned int v7; // eax
  const char *v8; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int v9; // [esp+10h] [ebp-18h]
  Scaleform::StringDataPtr result; // [esp+14h] [ebp-14h] BYREF
  _DWORD v11[3]; // [esp+1Ch] [ebp-Ch] BYREF

  v8 = 0;
  v9 = 0;
  Scaleform::StringDataPtr::GetNextToken(str, &result, 58);
  pParentFmt = this->pParentFmt;
  v4 = 0;
  if ( pParentFmt->pLocaleProvider )
  {
    v11[1] = &result;
    v11[2] = &this->Value;
    v11[0] = pParentFmt;
    v4 = pParentFmt->pLocaleProvider->MakeFormatter(
           pParentFmt->pLocaleProvider,
           (const Scaleform::FormatterFactory::Args *)v11);
  }
  Size = str->Size;
  v6 = result.Size + 1;
  if ( Size < result.Size + 1 )
    v6 = str->Size;
  v7 = Size - v6;
  v8 = &str->pStr[v6];
  v9 = v7;
  if ( v4 )
  {
    if ( v7 )
      v4->Parse(v4, (const Scaleform::StringDataPtr *)&v8);
    Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v4, 1);
  }
}
