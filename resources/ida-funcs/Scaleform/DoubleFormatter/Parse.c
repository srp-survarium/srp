void __thiscall Scaleform::DoubleFormatter::Parse(
        Scaleform::DoubleFormatter *this,
        const Scaleform::StringDataPtr *str)
{
  unsigned int Size; // eax
  Scaleform::StringDataPtr *NextToken; // eax
  const char *pStr; // edi
  unsigned int v6; // ebx
  unsigned int v7; // eax
  Scaleform::MsgFormat *pParentFmt; // edi
  long double v9; // st7
  long double v10; // st7
  char *v11; // edi
  long double Value; // st7
  long double v13; // st7
  int v14; // eax
  Scaleform::Formatter *v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // ecx
  Scaleform::StringDataPtr v18[2]; // [esp-8h] [ebp-48h] BYREF
  Scaleform::SwitchFormatter::ValueType v; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::StringDataPtr v20; // [esp+10h] [ebp-30h] BYREF
  Scaleform::StringDataPtr v21; // [esp+18h] [ebp-28h] BYREF
  Scaleform::StringDataPtr result; // [esp+20h] [ebp-20h] BYREF
  int v23; // [esp+28h] [ebp-18h] BYREF
  char v24; // [esp+2Ch] [ebp-14h]
  int v25; // [esp+30h] [ebp-10h]
  _DWORD v26[3]; // [esp+34h] [ebp-Ch] BYREF

  Size = str->Size;
  v20.pStr = str->pStr;
  v20.Size = Size;
  v.Value = 0;
  if ( !Size )
    return;
  while ( 1 )
  {
    NextToken = Scaleform::StringDataPtr::GetNextToken(&v20, &result, 58);
    pStr = NextToken->pStr;
    v6 = NextToken->Size;
    if ( !NextToken->pStr || !v6 )
      return;
    v7 = v6 + 1;
    if ( v20.Size < v6 + 1 )
      v7 = v20.Size;
    v20.pStr += v7;
    v20.Size -= v7;
    if ( !isdigit(*pStr) )
      break;
$LN16_45:
    Scaleform::NumericBase::ReadPrintFormat(
      &this->Scaleform::NumericBase,
      (Scaleform::StringDataPtr)__PAIR64__(v6, (unsigned int)pStr));
LABEL_24:
    if ( !v20.Size )
      goto LABEL_33;
  }
  switch ( *pStr )
  {
    case ' ':
    case '#':
    case '+':
    case '-':
    case '.':
      goto $LN16_45;
    case 'E':
      goto $LN58_2;
    case 'G':
      goto $LN62_2;
    case 'e':
      *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
$LN58_2:
      this->Type = FmtScientific;
      Scaleform::StringDataPtr::GetNextToken(&v20, v18, 58);
      goto LABEL_10;
    case 'f':
      this->Type = FmtDecimal;
      Scaleform::StringDataPtr::GetNextToken(&v20, v18, 58);
      goto LABEL_10;
    case 'g':
      *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
$LN62_2:
      this->Type = FmtSignificant;
      Scaleform::StringDataPtr::GetNextToken(&v20, v18, 58);
LABEL_10:
      Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, v18[0]);
      goto LABEL_24;
    case 's':
      if ( pStr[1] != 119 )
      {
        if ( !strncmp(pStr, "sep", 3u) )
        {
          Scaleform::StringDataPtr::GetNextToken(&v20, &v21, 58);
          if ( v21.Size )
            *((_BYTE *)&this->Scaleform::NumericBase + 5) ^= (*((_BYTE *)&this->Scaleform::NumericBase + 5)
                                                            ^ *v21.pStr)
                                                           & 0x7F;
        }
        goto LABEL_24;
      }
      v11 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->pParentFmt->MemPool, 0x24u);
      if ( v11 )
      {
        Value = this->Value;
        if ( Value <= 0.0 )
          v13 = Value - 0.5;
        else
          v13 = Value + 0.5;
        v.Value = (int)v13;
        Scaleform::SwitchFormatter::SwitchFormatter((Scaleform::SwitchFormatter *)v11, this->pParentFmt, &v);
        v.Value = v14;
      }
      else
      {
        v.Value = 0;
      }
      v20.pStr += v20.Size;
      v20.Size = 0;
LABEL_33:
      v15 = (Scaleform::Formatter *)v.Value;
      if ( v.Value )
      {
        v16 = str->Size;
        v17 = v6 + 1;
        if ( v16 < v6 + 1 )
          v17 = str->Size;
        v21.pStr = &str->pStr[v17];
        v21.Size = v16 - v17;
        if ( v16 != v17 )
          (*(void (__thiscall **)(int, Scaleform::StringDataPtr *))(*(_DWORD *)v.Value + 8))(v.Value, &v21);
        Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v15, 1);
      }
      return;
    default:
      pParentFmt = this->pParentFmt;
      if ( pParentFmt->pLocaleProvider )
      {
        v9 = this->Value;
        if ( v9 <= 0.0 )
          v10 = v9 - 0.5;
        else
          v10 = v9 + 0.5;
        v23 = (int)v10;
        v26[1] = &v20;
        v26[2] = &v23;
        v24 = 1;
        v25 = 0;
        v26[0] = pParentFmt;
        v.Value = (int)pParentFmt->pLocaleProvider->MakeFormatter(
                         pParentFmt->pLocaleProvider,
                         (const Scaleform::FormatterFactory::Args *)v26);
      }
      goto LABEL_24;
  }
}
