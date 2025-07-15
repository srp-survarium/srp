void __thiscall Scaleform::GFx::AS3::Instances::fl::Date::Parser::Parser(
        Scaleform::GFx::AS3::Instances::fl::Date::Parser *this,
        int str)
{
  char *v3; // edi
  int *p_Year; // ebx
  char i; // cl
  char *v6; // eax
  char v7; // cl
  char v8; // dl
  char *v9; // edx
  char v10; // al
  int v11; // eax
  int v12; // ecx
  char j; // al
  char v14; // al
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  const char *v18; // eax
  char *v19; // eax
  char v20; // cl
  int v21; // ebp
  char v22; // cl
  int v23; // eax
  int Hour; // eax

  v3 = (char *)str;
  p_Year = &this->Year;
  this->Valid = 1;
  this->HasYear = 0;
  this->HasMonth = 0;
  this->HasDay = 0;
  this->HasTime = 0;
  this->HasTZA = 0;
  this->Month = -1;
  this->Day = -1;
  this->Year = -1;
  this->DayOfWeek = -1;
  this->TZA = 0;
  this->Hour = 0;
  this->Minute = 0;
  this->Sec = 0;
  for ( i = *v3; *v3; i = *v3 )
  {
    v6 = v3;
    do
    {
      if ( i > 32 && i != 44 )
      {
        if ( i != 45 )
          break;
        v7 = v6[1];
        if ( v7 >= 48 && v7 <= 57 )
          break;
      }
      i = *++v6;
    }
    while ( i );
    v8 = *v6;
    if ( !*v6 )
      break;
    if ( v8 == 45 )
    {
      if ( this->HasYear )
        goto $LN1_23;
      v9 = v6;
      *p_Year = 0;
      v10 = *v6;
      if ( v10 >= 48 )
      {
        do
        {
          if ( v10 > 57 )
            break;
          ++v9;
          *p_Year = v10 + 10 * *p_Year - 48;
          v10 = *v9;
        }
        while ( *v9 >= 48 );
      }
      v11 = -*p_Year;
      this->HasYear = 1;
      *p_Year = v11;
      v3 = v9 + 1;
    }
    else if ( (unsigned __int8)(v8 - 48) > 9u )
    {
      v3 = v6;
      if ( v8 > 32 )
      {
        v20 = *v6;
        do
        {
          if ( v20 == 44 )
            break;
          if ( v20 == 45 )
            break;
          v20 = *++v3;
        }
        while ( v20 > 32 );
      }
      v21 = 1;
      switch ( Scaleform::GFx::AS3::Instances::fl::Date::Parser::interpretDateString(v6, v3 - v6, &str) )
      {
        case 0:
          goto $LN1_23;
        case 1:
          if ( this->HasMonth )
            goto $LN1_23;
          this->Month = str;
          this->HasMonth = 1;
          continue;
        case 2:
          if ( this->DayOfWeek != -1 )
            goto $LN1_23;
          this->DayOfWeek = str;
          continue;
        case 3:
          if ( this->HasTZA )
            goto $LN1_23;
          if ( *v3 == 43 )
            goto LABEL_59;
          if ( *v3 != 45 )
            goto $LN1_23;
          v21 = -1;
LABEL_59:
          v22 = v3[1];
          if ( v22 < 48 || v22 > 57 )
            goto $LN1_23;
          v3 = Scaleform::GFx::AS3::Instances::fl::Date::Parser::scanUnsignedInt(v3 + 1, &str);
          this->TZA = 60000 * v21 * (str - 40 * (str / 100));
          this->HasTZA = 1;
          break;
        case 4:
          if ( this->HasTZA )
            goto $LN1_23;
          this->HasTZA = 1;
          continue;
        case 5:
          if ( !this->HasTime )
            goto $LN1_23;
          Hour = this->Hour;
          if ( Hour > 12 )
            goto $LN1_23;
          if ( Hour == 12 )
            this->Hour = 0;
          continue;
        case 6:
          if ( !this->HasTime )
            goto $LN1_23;
          v23 = this->Hour;
          if ( v23 > 12 )
            goto $LN1_23;
          if ( v23 != 12 )
            this->Hour = v23 + 12;
          continue;
        default:
          continue;
      }
    }
    else
    {
      v12 = 0;
      str = 0;
      if ( v8 >= 48 )
      {
        do
        {
          if ( v8 > 57 )
            break;
          ++v6;
          v12 = v8 + 10 * v12 - 48;
          v8 = *v6;
        }
        while ( *v6 >= 48 );
        str = v12;
      }
      v3 = v6;
      for ( j = *v6; j; j = *++v3 )
      {
        if ( j > 32 && j != 44 )
        {
          if ( j != 45 )
            break;
          v14 = v3[1];
          if ( v14 >= 48 && v14 <= 57 )
            break;
        }
      }
      if ( *v3 == 58 )
      {
        if ( this->HasTime )
          goto $LN1_23;
        this->HasTime = 1;
        this->Hour = v12;
        v3 = (char *)Scaleform::GFx::AS3::Instances::fl::Date::Parser::skipWhitespace(v3 + 1);
        if ( (unsigned __int8)(*v3 - 48) <= 9u )
        {
          v15 = Scaleform::GFx::AS3::Instances::fl::Date::Parser::scanUnsignedInt(v3, &this->Minute);
          v3 = v15;
          if ( *v15 == 58 )
          {
            v3 = (char *)Scaleform::GFx::AS3::Instances::fl::Date::Parser::skipWhitespace(v15 + 1);
            if ( (unsigned __int8)(*v3 - 48) <= 9u )
              v3 = Scaleform::GFx::AS3::Instances::fl::Date::Parser::scanUnsignedInt(v3, &this->Sec);
          }
        }
      }
      else if ( *v3 == 47 )
      {
        if ( this->HasYear )
          goto $LN1_23;
        this->Month = v12 - 1;
        v16 = (char *)Scaleform::GFx::AS3::Instances::fl::Date::Parser::skipWhitespace(v3 + 1);
        if ( (unsigned __int8)(*v16 - 48) > 9u )
          goto $LN1_23;
        v17 = Scaleform::GFx::AS3::Instances::fl::Date::Parser::scanUnsignedInt(v16, &this->Day);
        v18 = Scaleform::GFx::AS3::Instances::fl::Date::Parser::skipWhitespace(v17);
        if ( *v18 != 47 )
          goto $LN1_23;
        v19 = (char *)Scaleform::GFx::AS3::Instances::fl::Date::Parser::skipWhitespace(v18 + 1);
        if ( (unsigned __int8)(*v19 - 48) > 9u )
          goto $LN1_23;
        v3 = Scaleform::GFx::AS3::Instances::fl::Date::Parser::scanUnsignedInt(v19, p_Year);
        this->HasDay = 1;
        this->HasMonth = 1;
        this->HasYear = 1;
      }
      else if ( this->HasDay || v12 > 31 )
      {
        if ( this->HasYear )
          goto $LN1_23;
        this->HasYear = 1;
        *p_Year = v12;
      }
      else
      {
        this->HasDay = 1;
        this->Day = v12;
      }
    }
  }
  if ( !this->HasYear || !this->HasMonth || !this->HasDay )
$LN1_23:
    this->Valid = 0;
}
