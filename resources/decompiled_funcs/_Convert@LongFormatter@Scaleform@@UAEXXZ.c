void __thiscall Scaleform::LongFormatter::Convert(Scaleform::LongFormatter *this)
{
  Scaleform::NumericBase *v2; // ebx
  char v3; // al
  int Value_high; // eax
  int Value; // ecx
  signed int v6; // eax
  __int64 v7; // rax
  unsigned int i; // eax
  BOOL v9; // ecx
  char v10; // cl
  int v11; // ecx
  char v12; // al
  bool v13; // zf
  char *ValueStr; // ecx
  char *v15; // ebp
  unsigned int v16; // eax
  unsigned __int8 *v17; // edi
  int v18; // eax
  unsigned __int8 *v19; // edi
  char v20; // cl

  if ( this->IsConverted )
    return;
  v2 = &this->Scaleform::NumericBase;
  if ( (*(_BYTE *)&this->Scaleform::NumericBase & 0x1F) != 0 || this->Value )
  {
    v3 = *((_BYTE *)this + 32);
    if ( (v3 & 2) != 0 )
    {
      Value_high = HIDWORD(this->Value);
      Value = this->Value;
      if ( Value_high < 0 )
      {
        Value = -Value;
        Value_high = (unsigned __int64)-__SPAIR64__(Value_high, Value) >> 32;
      }
      Scaleform::NumericBase::ULongLong2String(
        &this->Scaleform::NumericBase,
        this->Buff,
        __PAIR64__(Value_high, Value),
        1,
        *((_DWORD *)this + 7) & 0x1F);
    }
    else if ( (v3 & 1) != 0 )
    {
      v6 = this->Value;
      if ( v6 < 0 )
        v6 = -v6;
      Scaleform::NumericBase::ULong2String(
        &this->Scaleform::NumericBase,
        this->Buff,
        v6,
        1,
        *((_DWORD *)this + 7) & 0x1F);
    }
    else
    {
      Scaleform::NumericBase::ULong2String(
        &this->Scaleform::NumericBase,
        this->Buff,
        this->Value,
        1,
        *((_DWORD *)this + 7) & 0x1F);
    }
  }
  for ( LODWORD(v7) = (char *)this - this->ValueStr + 76; (unsigned int)v7 < (*(_DWORD *)v2 & 0x1Fu); LODWORD(v7) = v7 + 1 )
    *--this->ValueStr = 48;
  if ( (*(_BYTE *)v2 & 0x1F) == 0 )
    *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
  HIDWORD(v7) = HIDWORD(this->Value);
  if ( v7 >= 0 )
  {
    v11 = *((_DWORD *)this + 7) & 0x1F;
    if ( v11 == 8 || v11 == 16 )
    {
      LODWORD(v7) = this->Value;
      if ( v7 )
      {
        v12 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
        if ( (v12 & 8) != 0 )
        {
          if ( v11 == 16 )
            *--this->ValueStr = (32 * ((v12 & 1) == 0)) | 0x58;
          *--this->ValueStr = 48;
        }
      }
    }
  }
  else
  {
    if ( (*((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x7F) == 0x30 )
    {
      for ( i = (char *)this - this->ValueStr + 76; ; ++i )
      {
        v9 = *((char *)&this->Scaleform::NumericBase + 5) < 0
          || (*((_BYTE *)&this->Scaleform::NumericBase + 6) & 2) != 0;
        if ( i >= ((*(_DWORD *)v2 >> 5) & 0x1Fu) - v9 )
          break;
        v10 = *((_BYTE *)&this->Scaleform::NumericBase + 4);
        *--this->ValueStr = (char)(2 * v10) >> 1;
      }
    }
    if ( this->Value < 0 )
      Scaleform::LongFormatter::AppendSignCharLeft(this, 1);
    else
      Scaleform::LongFormatter::AppendSignCharLeft(this, 0);
  }
  if ( (*((_BYTE *)&this->Scaleform::NumericBase + 6) & 2) != 0 && *((char *)&this->Scaleform::NumericBase + 5) >= 0 )
  {
    v13 = (*((_BYTE *)this + 32) & 1) == 0;
    *((_BYTE *)&this->Scaleform::NumericBase + 4) = *((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x80 | 0x20;
    if ( !v13 && this->Value >= 0 )
      *--this->ValueStr = 32;
  }
  ValueStr = this->ValueStr;
  v15 = (char *)((char *)this - ValueStr + 76);
  v16 = (*(_DWORD *)v2 >> 5) & 0x1F;
  if ( (*((_BYTE *)&this->Scaleform::NumericBase + 6) & 4) == 0 )
  {
    if ( (unsigned int)v15 < v16 )
    {
      do
      {
        v20 = *((_BYTE *)&this->Scaleform::NumericBase + 4);
        *--this->ValueStr = (char)(2 * v20) >> 1;
        ++v15;
      }
      while ( (unsigned int)v15 < ((*(_DWORD *)v2 >> 5) & 0x1Fu) );
    }
    goto LABEL_48;
  }
  if ( (unsigned int)v15 >= v16
    || (v17 = (unsigned __int8 *)&this->Buff[-v16 + 28],
        memmove(v17, (unsigned __int8 *)ValueStr, (char *)this - ValueStr + 76),
        v18 = *(_DWORD *)v2 >> 5,
        this->ValueStr = (char *)v17,
        v19 = &v17[(_DWORD)v15],
        (unsigned int)v15 >= (v18 & 0x1Fu)) )
  {
LABEL_48:
    this->IsConverted = 1;
    return;
  }
  do
  {
    *v19 = (char)(2 * *((_BYTE *)&this->Scaleform::NumericBase + 4)) >> 1;
    ++v15;
    ++v19;
  }
  while ( (unsigned int)v15 < ((*(_DWORD *)v2 >> 5) & 0x1Fu) );
  this->IsConverted = 1;
}
