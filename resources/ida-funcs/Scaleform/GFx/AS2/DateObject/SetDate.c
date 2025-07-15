void __thiscall Scaleform::GFx::AS2::DateObject::SetDate(Scaleform::GFx::AS2::DateObject *this, __int64 val)
{
  Scaleform::GFx::AS2::DateObject *v2; // esi
  int v3; // edi
  int v4; // ebp
  int v5; // ecx
  bool v6; // al
  bool v7; // al
  unsigned int v8; // ecx
  int Year; // esi
  bool v10; // al
  int v11; // ecx
  bool v12; // al
  __int64 v13; // rax
  int v15; // [esp+14h] [ebp-8h]

  v2 = this;
  this->Time = val % 86400000;
  v3 = val / 86400000 % 146097;
  v4 = (unsigned __int64)(val / 86400000 % 146097) >> 32;
  v15 = v3;
  this->Year = 400 * (val / 86400000 / 146097) + 1970;
  if ( val < 0 )
  {
    while ( 1 )
    {
      if ( v4 < 0 )
      {
        v3 = -v3;
        v8 = (unsigned __int64)-__SPAIR64__(v4, v3) >> 32;
      }
      else
      {
        v8 = v4;
      }
      Year = v2->Year;
      v10 = !(Year % 4) && (Year % 100 || !(Year % 400));
      if ( __SPAIR64__(v8, v3) < v10 + 365 )
        break;
      v11 = Year - 1;
      this->Year = Year - 1;
      v12 = !((Year - 1) % 4) && (v11 % 100 || !(v11 % 400));
      v2 = this;
      v13 = v12 + 365;
      v3 = v13 + v15;
      v4 = (v13 + __PAIR64__(v4, v15)) >> 32;
      v15 += v13;
    }
    v2 = this;
    v3 = v15;
  }
  else
  {
    while ( 1 )
    {
      v5 = v2->Year;
      v6 = !(v5 % 4) && (v5 % 100 || !(v5 % 400));
      if ( __SPAIR64__(v4, v3) < v6 + 365 )
        break;
      v7 = !(v5 % 4) && (v5 % 100 || !(v5 % 400));
      v4 = (__PAIR64__(v4, v3) - (v7 + 365)) >> 32;
      v3 -= v7 + 365;
      v2->Year = v5 + 1;
    }
  }
  v2->JDate = v3;
  v2->Date = val;
  Scaleform::GFx::AS2::DateObject::UpdateLocal(v2);
}
