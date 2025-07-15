void __thiscall Scaleform::LongFormatter::Parse(Scaleform::LongFormatter *this, const Scaleform::StringDataPtr *str)
{
  unsigned int Size; // eax
  Scaleform::StringDataPtr *NextToken; // eax
  const char *pStr; // edi
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  Scaleform::MsgFormat *pParentFmt; // eax
  char *v10; // eax
  Scaleform::Formatter *v11; // eax
  Scaleform::Formatter *v12; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  Scaleform::StringDataPtr v15[2]; // [esp-8h] [ebp-48h] BYREF
  Scaleform::Formatter *impl_ptr; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::StringDataPtr tmp_str; // [esp+10h] [ebp-30h] BYREF
  Scaleform::StringDataPtr impl_param_str; // [esp+18h] [ebp-28h] BYREF
  Scaleform::StringDataPtr result; // [esp+20h] [ebp-20h] BYREF
  int Value; // [esp+28h] [ebp-18h] BYREF
  char v21; // [esp+2Ch] [ebp-14h]
  int v22; // [esp+30h] [ebp-10h]
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
$LN16_38:
    Scaleform::NumericBase::ReadPrintFormat(
      &this->Scaleform::NumericBase,
      (Scaleform::StringDataPtr)__PAIR64__(v6, (unsigned int)pStr));
LABEL_24:
    if ( !tmp_str.Size )
      goto LABEL_30;
  }
  switch ( *pStr )
  {
    case ' ':
    case '#':
    case '+':
    case '-':
    case '.':
      goto $LN16_38;
    case 'X':
      goto $LN64_1;
    case 'b':
      if ( !strncmp(pStr, "base", 4u) )
        *((_DWORD *)this + 7) ^= ((unsigned __int8)Scaleform::ReadInteger(&tmp_str, 10, 58)
                                ^ (unsigned __int8)*((_DWORD *)this + 7))
                               & 0x1F;
      goto LABEL_24;
    case 'o':
      *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 8;
      Scaleform::StringDataPtr::GetNextToken(&tmp_str, v15, 58);
      goto LABEL_12;
    case 's':
      if ( pStr[1] != 119 )
      {
        if ( !strncmp(pStr, "sep", 3u) )
        {
          Scaleform::StringDataPtr::GetNextToken(&tmp_str, &impl_param_str, 58);
          v8 = impl_param_str.Size;
          if ( impl_param_str.Size )
            *((_BYTE *)&this->Scaleform::NumericBase + 5) ^= (*((_BYTE *)&this->Scaleform::NumericBase + 5)
                                                            ^ *impl_param_str.pStr)
                                                           & 0x7F;
          if ( tmp_str.Size < v8 )
            v8 = tmp_str.Size;
          tmp_str.pStr += v8;
          tmp_str.Size -= v8;
        }
        goto LABEL_24;
      }
      v10 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->pParentFmt->MemPool, 0x24u);
      if ( v10 )
      {
        impl_ptr = (Scaleform::Formatter *)this->Value;
        Scaleform::SwitchFormatter::SwitchFormatter(
          (Scaleform::SwitchFormatter *)v10,
          this->pParentFmt,
          (const Scaleform::SwitchFormatter::ValueType *)&impl_ptr);
        impl_ptr = v11;
      }
      else
      {
        impl_ptr = 0;
      }
      tmp_str.pStr += tmp_str.Size;
      tmp_str.Size = 0;
LABEL_30:
      v12 = impl_ptr;
      if ( impl_ptr )
      {
        v13 = str->Size;
        v14 = v6 + 1;
        if ( v13 < v6 + 1 )
          v14 = str->Size;
        impl_param_str.pStr = &str->pStr[v14];
        impl_param_str.Size = v13 - v14;
        if ( v13 != v14 )
          impl_ptr->Parse(impl_ptr, &impl_param_str);
        Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, v12, 1);
      }
      return;
    case 'x':
      *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
$LN64_1:
      *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 0x10;
      Scaleform::StringDataPtr::GetNextToken(&tmp_str, v15, 58);
LABEL_12:
      Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, v15[0]);
      goto LABEL_24;
    default:
      pParentFmt = this->pParentFmt;
      if ( pParentFmt->pLocaleProvider )
      {
        Value = this->Value;
        args.Fmt = pParentFmt;
        args.Name = &tmp_str;
        v21 = 0;
        v22 = 0;
        args.Value = (const Scaleform::ResourceFormatter::ValueType *)&Value;
        impl_ptr = pParentFmt->pLocaleProvider->MakeFormatter(pParentFmt->pLocaleProvider, &args);
      }
      goto LABEL_24;
  }
}
