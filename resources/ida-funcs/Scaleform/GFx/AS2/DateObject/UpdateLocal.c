void __thiscall Scaleform::GFx::AS2::DateObject::UpdateLocal(Scaleform::GFx::AS2::DateObject *this)
{
  int LocalOffset; // eax
  int Year; // ebx
  unsigned int v4; // ecx
  __int64 v5; // kr00_8
  int JDate; // edi
  int v7; // eax
  int v8; // edi
  int v9; // eax

  LocalOffset = this->LocalOffset;
  Year = this->Year;
  v4 = LocalOffset + this->Time;
  v5 = this->Date + LocalOffset;
  HIDWORD(this->LDate) = HIDWORD(v5);
  JDate = this->JDate;
  this->LTime = v4;
  LODWORD(this->LDate) = v5;
  this->LJDate = JDate;
  this->LYear = Year;
  if ( v4 >= 0x5265C00 )
  {
    v7 = (int)(v4 + 864000000) / 86400000 - 10;
    v8 = v7 + JDate;
    this->LTime = v4 - 86400000 * v7;
    this->LJDate = v8;
    v9 = Scaleform::GFx::AS2::IsLeapYear(Year) + 365;
    if ( v8 < v9 )
    {
      if ( v8 < 0 )
      {
        this->LYear = Year - 1;
        this->LJDate = v8 + Scaleform::GFx::AS2::IsLeapYear(Year - 1) + 365;
      }
    }
    else
    {
      this->LJDate = v8 - v9;
      this->LYear = Year + 1;
    }
  }
}
