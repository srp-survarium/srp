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
  Scaleform::Formatter *v14; // eax
  Scaleform::Formatter *v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // ecx
  Scaleform::StringDataPtr v18[2]; // [esp-8h] [ebp-48h] BYREF
  Scaleform::Formatter *impl_ptr; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::StringDataPtr tmp_str; // [esp+10h] [ebp-30h] BYREF
  Scaleform::StringDataPtr impl_param_str; // [esp+18h] [ebp-28h] BYREF
  Scaleform::StringDataPtr result; // [esp+20h] [ebp-20h] BYREF
  int v23; // [esp+28h] [ebp-18h] BYREF
  char v24; // [esp+2Ch] [ebp-14h]
  int v25; // [esp+30h] [ebp-10h]
  Scaleform::FormatterFactory::Args args; // [esp+34h] [ebp-Ch] BYREF

  Size = str->Size;
  tmp_str.pStr = str->pStr;
  tmp_str.Size = Size;
  impl_ptr = 0;
  if ( !Size )
    return;
  while ( 1 )
  {
    NextToken = Scaleform::StringDataPtr::GetNextToken(&tmp_str, &result, 58);
    pStr = NextToken->pStr;
    v6 = NextToken->Size;
    if ( !NextToken->pStr || !v6 )
      return;
    v7 = v6 + 1;
    if ( tmp_str.Size < v6 + 1 )
      v7 = tmp_str.Size;
    tmp_str.pStr += v7;
    tmp_str.Size -= v7;
    if ( !isdigit(*pStr) )
      break;
$LN16_39:
    Scaleform::NumericBase::ReadPrintFormat(
      &this->Scaleform::NumericBase,
      (Scaleform::StringDataPtr)__PAIR64__(v6, (unsigned int)pStr));
LABEL_24:
    if ( !tmp_str.Size )
      goto LABEL_33;
  }
  switch ( *pStr )
  {
    case ' ':
    case '#':
    case '+':
    case '-':
    case '.':
      goto $LN16_39;
    case 'E':
      goto $LN58_1;
    case 'G':
      goto $LN62;
    case 'e':
      *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
$LN58_1:
      this->Type = FmtScientific;
      Scaleform::StringDataPtr::GetNextToken(&tmp_str, v18, 58);
      goto LABEL_10;
    case 'f':
      this->Type = FmtDecimal;
      Scaleform::StringDataPtr::GetNextToken(&tmp_str, v18, 58);
      goto LABEL_10;
    case 'g':
      *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
$LN62:
      this->Type = FmtSignificant;
      Scaleform::StringDataPtr::GetNextToken(&tmp_str, v18, 58);
LABEL_10:
      Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, v18[0]);
      goto LABEL_24;
    case 's':
      if ( pStr[1] != 119 )
      {
        if ( !strncmp(pStr, "sep", 3u) )
        {
          Scaleform::StringDataPtr::GetNextToken(&tmp_str, &impl_param_str, 58);
          if ( impl_param_str.Size )
            *((_BYTE *)&this->Scaleform::NumericBase + 5) ^= (*((_BYTE *)&this->Scaleform::NumericBase + 5)
                                                            ^ *impl_param_str.pStr)
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
        impl_ptr = (Scaleform::Formatter *)(int)v13;
        Scaleform::SwitchFormatter::SwitchFormatter(
          (Scaleform::SwitchFormatter *)v11,
          this->pParentFmt,
          (const Scaleform::SwitchFormatter::ValueType *)&impl_ptr);
        impl_ptr = v14;
      }
      else
      {
        impl_ptr = 0;
      }
      tmp_str.pStr += tmp_str.Size;
      tmp_str.Size = 0;
LABEL_33:
      v15 = impl_ptr;
      if ( impl_ptr )
      {
        v16 = str->Size;
        v17 = v6 + 1;
        if ( v16 < v6 + 1 )
          v17 = str->Size;
        impl_param_str.pStr = &str->pStr[v17];
        impl_param_str.Size = v16 - v17;
        if ( v16 != v17 )
          impl_ptr->Parse(impl_ptr, &impl_param_str);
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
        args.Name = &tmp_str;
        args.Value = (const Scaleform::ResourceFormatter::ValueType *)&v23;
        v24 = 1;
        v25 = 0;
        args.Fmt = pParentFmt;
        impl_ptr = pParentFmt->pLocaleProvider->MakeFormatter(pParentFmt->pLocaleProvider, &args);
      }
      goto LABEL_24;
  }
}
