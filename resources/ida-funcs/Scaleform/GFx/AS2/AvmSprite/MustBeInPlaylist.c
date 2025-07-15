int __thiscall Scaleform::GFx::AS2::AvmSprite::MustBeInPlaylist(Scaleform::GFx::AS2::AvmSprite *this)
{
  int (__thiscall *v1)(int *, _DWORD *); // eax
  _DWORD v3[3]; // [esp+0h] [ebp-14h] BYREF
  char v4; // [esp+Ch] [ebp-8h]
  char v5; // [esp+10h] [ebp-4h]
  char v6; // [esp+11h] [ebp-3h]
  char v7; // [esp+12h] [ebp-2h]
  char v8; // [esp+13h] [ebp-1h]

  v3[1] = 0;
  v3[2] = 0;
  v4 = 0;
  v5 = 0;
  v7 = 0;
  v8 = 0;
  v1 = *(int (__thiscall **)(int *, _DWORD *))(this[-1].Level + 28);
  v3[0] = 2;
  v6 = -1;
  return v1(&this[-1].Level, v3);
}
