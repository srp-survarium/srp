BOOL __thiscall Scaleform::GFx::AS3::AvmSprite::MustBeInPlaylist(Scaleform::GFx::AS3::AvmSprite *this)
{
  unsigned __int8 (__thiscall *v1)(const char **, _DWORD *); // eax
  _DWORD v3[3]; // [esp+4h] [ebp-14h] BYREF
  char v4; // [esp+10h] [ebp-8h]
  char v5; // [esp+14h] [ebp-4h]
  char v6; // [esp+15h] [ebp-3h]
  char v7; // [esp+16h] [ebp-2h]
  char v8; // [esp+17h] [ebp-1h]

  if ( ((int)this->pDispObj & 2) != 0 )
    return 1;
  v3[0] = 2;
  v1 = (unsigned __int8 (__thiscall *)(const char **, _DWORD *))*((_DWORD *)this[-1].pClassName + 7);
  v3[1] = 0;
  v3[2] = 0;
  v4 = 0;
  v5 = 0;
  v7 = 0;
  v8 = 0;
  v6 = -1;
  return v1(&this[-1].pClassName, v3) != 0;
}
