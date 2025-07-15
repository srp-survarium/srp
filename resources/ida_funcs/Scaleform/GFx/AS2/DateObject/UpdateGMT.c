void __thiscall Scaleform::GFx::AS2::DateObject::UpdateGMT(Scaleform::GFx::AS2::DateObject *this)
{
  int LocalOffset; // eax
  int LYear; // ebx
  unsigned int v4; // ecx
  __int64 v5; // kr00_8
  int LJDate; // edi
  int v7; // eax
  int v8; // edi
  int v9; // eax

  LocalOffset = this->LocalOffset;
  LYear = this->LYear;
  v4 = this->LTime - LocalOffset;
  v5 = this->LDate - LocalOffset;
  LODWORD(this->Date) = v5;
  LJDate = this->LJDate;
  this->Time = v4;
  HIDWORD(this->Date) = HIDWORD(v5);
  this->JDate = LJDate;
  this->Year = LYear;
  if ( v4 >= 0x5265C00 )
  {
    v7 = (int)(v4 + 864000000) / 86400000 - 10;
    v8 = v7 + LJDate;
    this->Time = v4 - 86400000 * v7;
    this->JDate = v8;
    v9 = Scaleform::GFx::AS2::IsLeapYear(LYear) + 365;
    if ( v8 < v9 )
    {
      if ( v8 < 0 )
      {
        this->Year = LYear - 1;
        this->JDate = v8 + Scaleform::GFx::AS2::IsLeapYear(LYear - 1);
      }
    }
    else
    {
      this->JDate = v8 - v9;
      this->Year = LYear + 1;
    }
  }
}
