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
  int v11; // eax
  Scaleform::Formatter *Value; // edi
  unsigned int v13; // eax
  unsigned int v14; // ecx
  Scaleform::StringDataPtr v15[2]; // [esp-8h] [ebp-48h] BYREF
  Scaleform::SwitchFormatter::ValueType v; // [esp+Ch] [ebp-34h] BYREF
  Scaleform::StringDataPtr stra; // [esp+10h] [ebp-30h] BYREF
  Scaleform::StringDataPtr v18; // [esp+18h] [ebp-28h] BYREF
  Scaleform::StringDataPtr result; // [esp+20h] [ebp-20h] BYREF
  int v20; // [esp+28h] [ebp-18h] BYREF
  char v21; // [esp+2Ch] [ebp-14h]
  int v22; // [esp+30h] [ebp-10h]
  _DWORD v23[3]; // [esp+34h] [ebp-Ch] BYREF

  Size = str->Size;
  stra.pStr = str->pStr;
  stra.Size = Size;
  v.Value = 0;
  if ( !Size )
    return;
  while ( 1 )
  {
    NextToken = Scaleform::StringDataPtr::GetNextToken(&stra, &result, 58);
    pStr = NextToken->pStr;
    v6 = NextToken->Size;
    if ( !NextToken->pStr || !v6 )
      return;
    v7 = v6 + 1;
    if ( stra.Size < v6 + 1 )
      v7 = stra.Size;
    stra.pStr += v7;
    stra.Size -= v7;
    if ( !isdigit(*pStr) )
      break;
$LN16_44:
    Scaleform::NumericBase::ReadPrintFormat(
      &this->Scaleform::NumericBase,
      (Scaleform::StringDataPtr)__PAIR64__(v6, (unsigned int)pStr));
LABEL_24:
    if ( !stra.Size )
      goto LABEL_30;
  }
  switch ( *pStr )
  {
    case ' ':
    case '#':
    case '+':
    case '-':
    case '.':
      goto $LN16_44;
    case 'X':
      goto $LN64_4;
    case 'b':
      if ( !strncmp(pStr, "base", 4u) )
        *((_DWORD *)this + 7) ^= ((unsigned __int8)Scaleform::ReadInteger(&stra, 10, 58)
                                ^ (unsigned __int8)*((_DWORD *)this + 7))
                               & 0x1F;
      goto LABEL_24;
    case 'o':
      *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 8;
      Scaleform::StringDataPtr::GetNextToken(&stra, v15, 58);
      goto LABEL_12;
    case 's':
      if ( pStr[1] != 119 )
      {
        if ( !strncmp(pStr, "sep", 3u) )
        {
          Scaleform::StringDataPtr::GetNextToken(&stra, &v18, 58);
          v8 = v18.Size;
          if ( v18.Size )
            *((_BYTE *)&this->Scaleform::NumericBase + 5) ^= (*((_BYTE *)&this->Scaleform::NumericBase + 5)
                                                            ^ *v18.pStr)
                                                           & 0x7F;
          if ( stra.Size < v8 )
            v8 = stra.Size;
          stra.pStr += v8;
          stra.Size -= v8;
        }
        goto LABEL_24;
      }
      v10 = Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(&this->pParentFmt->MemPool, 0x24u);
      if ( v10 )
      {
        v.Value = this->Value;
        Scaleform::SwitchFormatter::SwitchFormatter((Scaleform::SwitchFormatter *)v10, this->pParentFmt, &v);
        v.Value = v11;
      }
      else
      {
        v.Value = 0;
      }
      stra.pStr += stra.Size;
      stra.Size = 0;
LABEL_30:
      Value = (Scaleform::Formatter *)v.Value;
      if ( v.Value )
      {
        v13 = str->Size;
        v14 = v6 + 1;
        if ( v13 < v6 + 1 )
          v14 = str->Size;
        v18.pStr = &str->pStr[v14];
        v18.Size = v13 - v14;
        if ( v13 != v14 )
          (*(void (__thiscall **)(int, Scaleform::StringDataPtr *))(*(_DWORD *)v.Value + 8))(v.Value, &v18);
        Scaleform::MsgFormat::ReplaceFormatter(this->pParentFmt, this, Value, 1);
      }
      return;
    case 'x':
      *((_BYTE *)&this->Scaleform::NumericBase + 6) &= ~1u;
$LN64_4:
      *((_DWORD *)this + 7) = *((_DWORD *)this + 7) & 0xFFFFFFE0 | 0x10;
      Scaleform::StringDataPtr::GetNextToken(&stra, v15, 58);
LABEL_12:
      Scaleform::NumericBase::ReadPrintFormat(&this->Scaleform::NumericBase, v15[0]);
      goto LABEL_24;
    default:
      pParentFmt = this->pParentFmt;
      if ( pParentFmt->pLocaleProvider )
      {
        v20 = this->Value;
        v23[0] = pParentFmt;
        v23[1] = &stra;
        v21 = 0;
        v22 = 0;
        v23[2] = &v20;
        v.Value = (int)pParentFmt->pLocaleProvider->MakeFormatter(
                         pParentFmt->pLocaleProvider,
                         (const Scaleform::FormatterFactory::Args *)v23);
      }
      goto LABEL_24;
  }
}
