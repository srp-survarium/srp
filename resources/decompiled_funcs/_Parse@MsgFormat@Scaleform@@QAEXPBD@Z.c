void __thiscall Scaleform::MsgFormat::Parse(Scaleform::MsgFormat *this, const char *fmt)
{
  int v4; // ebp
  const char *v5; // eax
  const char *v6; // ebx
  int v7; // ecx
  char v8; // al
  char v9; // cl
  unsigned int Size; // eax
  char *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edx
  char *v14; // eax
  const char *str; // [esp+10h] [ebp-2Ch]
  unsigned int value_4; // [esp+1Ch] [ebp-20h]
  Scaleform::StringDataPtr v17; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::StringDataPtr v18; // [esp+28h] [ebp-14h] BYREF
  Scaleform::MsgFormat::fmt_record val; // [esp+30h] [ebp-Ch] BYREF
  char escape; // [esp+40h] [ebp+4h]

  v4 = 0;
  v5 = fmt;
  str = fmt;
  v6 = fmt;
  this->UnboundFmtrInd = -1;
  escape = 0;
  if ( !v5 )
    return;
  this->NonPosParamNum = 0;
  if ( !*fmt )
    return;
  do
  {
    if ( v4 )
    {
      if ( *v5 == 125 )
      {
        if ( v6 != v5 )
        {
          if ( isspace(*v6) )
          {
            do
              v7 = *++v6;
            while ( isspace(v7) );
          }
          if ( isdigit(*v6) )
          {
            v8 = atoi(v6);
            v9 = *v6;
            if ( *v6 )
            {
              while ( v9 != 58 && v9 != 125 )
              {
                v9 = *++v6;
                if ( !v9 )
                  goto LABEL_17;
              }
              if ( *v6 == 58 )
                ++v6;
            }
          }
          else
          {
            ++this->NonPosParamNum;
            v8 = -1;
          }
LABEL_17:
          BYTE1(value_4) = v8;
          Size = this->Data.Size;
          LOBYTE(value_4) = (_BYTE)str - (_BYTE)v6;
          val.RecType = eParamStrType;
          val.RecValue = (Scaleform::MsgFormat::fmt_value)__PAIR64__(value_4, (unsigned int)v6);
          if ( Size >= 0x10 )
          {
            Scaleform::ArrayData<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
              &this->Data.DynamicArray.Data,
              &val);
          }
          else
          {
            v11 = &this->Data.StaticArray[12 * Size];
            *(_DWORD *)v11 = 1;
            *((_DWORD *)v11 + 1) = v6;
            *((_DWORD *)v11 + 2) = value_4;
          }
          ++this->Data.Size;
          if ( this->UnboundFmtrInd == 0xFFFF )
            this->UnboundFmtrInd = LOWORD(this->Data.Size) - 1;
          v5 = str;
        }
        v6 = ++v5;
        v4 = 0;
      }
      else
      {
        ++v5;
      }
      goto LABEL_28;
    }
    if ( escape )
    {
      escape = 0;
LABEL_27:
      ++v5;
LABEL_28:
      str = v5;
      continue;
    }
    if ( *v5 == 123 )
    {
      if ( v6 != v5 )
      {
        v17.pStr = v6;
        v17.Size = v5 - v6;
        Scaleform::MsgFormat::AddStringRecord(this, &v17);
        v5 = str;
      }
      v6 = ++v5;
      v4 = 1;
      goto LABEL_28;
    }
    if ( *v5 != this->EscapeChar || !v5[1] )
      goto LABEL_27;
    if ( v6 != v5 )
    {
      v18.pStr = v6;
      v18.Size = v5 - v6;
      Scaleform::MsgFormat::AddStringRecord(this, &v18);
      v5 = str;
    }
    v6 = v5 + 1;
    str = v5 + 1;
    escape = 1;
    ++v5;
  }
  while ( *v5 );
  if ( !v4 && v6 != v5 )
  {
    LOBYTE(v18.Size) = (_BYTE)v5 - (_BYTE)v6;
    v12 = this->Data.Size;
    v13 = v18.Size;
    val.RecType = eStrType;
    val.RecValue = (Scaleform::MsgFormat::fmt_value)__PAIR64__(v18.Size, (unsigned int)v6);
    if ( v12 >= 0x10 )
    {
      Scaleform::ArrayData<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->Data.DynamicArray.Data,
        &val);
    }
    else
    {
      v14 = &this->Data.StaticArray[12 * v12];
      *(_DWORD *)v14 = 0;
      *((_DWORD *)v14 + 1) = v6;
      *((_DWORD *)v14 + 2) = v13;
    }
    ++this->Data.Size;
  }
}
