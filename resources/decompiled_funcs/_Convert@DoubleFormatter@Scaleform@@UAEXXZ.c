void __thiscall Scaleform::DoubleFormatter::Convert(Scaleform::DoubleFormatter *this)
{
  Scaleform::DoubleFormatter::PresentationType Type; // eax
  char v3; // dl
  __int32 v4; // eax
  bool v5; // zf
  char *v6; // eax
  char v7; // cl
  int v8; // edi
  char *v9; // eax
  char *v10; // eax
  char *Buff; // edi
  char *ValueStr; // eax
  char *v13; // eax
  int v14; // [esp+4h] [ebp-4Ch]
  char fmt[32]; // [esp+10h] [ebp-40h] BYREF
  char format[32]; // [esp+30h] [ebp-20h] BYREF

  if ( !this->IsConverted )
  {
    Type = this->Type;
    v3 = 32;
    if ( Type )
    {
      v4 = Type - 1;
      if ( v4 )
      {
        if ( v4 == 1 )
          v3 = (32 * ((*((_BYTE *)&this->Scaleform::NumericBase + 6) & 1) == 0)) | 0x47;
      }
      else
      {
        v3 = (32 * ((*((_BYTE *)&this->Scaleform::NumericBase + 6) & 1) == 0)) | 0x45;
      }
    }
    else
    {
      v3 = 102;
    }
    v5 = *((_BYTE *)&this->Scaleform::NumericBase + 5) >= 0;
    memset(fmt, 37, 2);
    v6 = &fmt[2];
    if ( !v5 )
    {
      fmt[2] = 43;
      v6 = &fmt[3];
    }
    v7 = *((_BYTE *)&this->Scaleform::NumericBase + 6);
    if ( (v7 & 8) != 0 )
      *v6++ = 35;
    if ( (v7 & 2) != 0 )
      *v6++ = 32;
    if ( (v7 & 4) != 0 )
      *v6++ = 45;
    if ( (*((_BYTE *)&this->Scaleform::NumericBase + 4) & 0x7F) == 0x30 )
      *v6++ = 48;
    v8 = (*(_DWORD *)&this->Scaleform::NumericBase >> 5) & 0x1F;
    v14 = *(_DWORD *)&this->Scaleform::NumericBase & 0x1F;
    if ( v8 == 1 )
    {
      *v6 = 46;
      v10 = v6 + 1;
      *v10++ = 37;
      *v10++ = 100;
      *v10 = v3;
      v10[1] = 0;
      Scaleform::SFsprintf(format, 0x20u, fmt, v14);
    }
    else
    {
      *v6 = 37;
      v6[1] = 100;
      v9 = v6 + 1;
      v9[1] = 46;
      v9 += 2;
      *v9++ = 37;
      *v9++ = 100;
      *v9 = v3;
      v9[1] = 0;
      Scaleform::SFsprintf(format, 0x20u, fmt, v8, v14);
    }
    Buff = this->Buff;
    this->Len = Scaleform::SFsprintf(this->Buff, 0x15Cu, format, this->Value);
    this->ValueStr = this->Buff;
    if ( this->Buff[0] )
    {
      while ( 1 )
      {
        ValueStr = this->ValueStr;
        if ( *ValueStr == 44 )
          break;
        v13 = ValueStr + 1;
        this->ValueStr = v13;
        if ( !*v13 )
        {
          this->ValueStr = Buff;
          this->IsConverted = 1;
          return;
        }
      }
      *ValueStr = 46;
    }
    this->ValueStr = Buff;
    this->IsConverted = 1;
  }
}
