int __usercall _gmtime64_s@<eax>(int a1@<ebx>, tm *ptm, const __int64 *timp)
{
  unsigned int v5; // ecx
  unsigned int v6; // eax
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // edi
  int v10; // eax
  int v11; // et0
  unsigned int v12; // et0
  __int64 v13; // rax
  unsigned int v14; // edi
  unsigned int v15; // et0
  int *v16; // edx
  int tm_yday; // eax
  int i; // ecx
  int v19; // ecx
  signed __int64 v20; // kr28_8
  __int64 v21; // [esp+8h] [ebp-10h]
  unsigned int v22; // [esp+Ch] [ebp-Ch]
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int v25; // [esp+20h] [ebp+8h]

  v24 = 0;
  if ( !ptm || (memset((int)ptm, 255, sizeof(tm)), !timp) )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 22);
    return 22;
  }
  v5 = *(_DWORD *)timp;
  v6 = *((_DWORD *)timp + 1);
  LODWORD(v21) = *(_DWORD *)timp;
  if ( *timp < -43200 || __SPAIR64__(v6, v5) > 0x7934126CFLL )
  {
    *_errno() = 22;
    return 22;
  }
  v7 = __SPAIR64__(v6, v5) / 31536000;
  v23 = v7 + 69;
  v25 = v7 + 70;
  v8 = (-365LL * (int)v7 - (((int)v7 + 369) / 400 - ((int)v7 + 69) / 100 + ((int)v7 + 69) / 4 - 17))
     * (unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}};
  HIDWORD(v21) = *((_DWORD *)timp + 1);
  v9 = v8 + v21;
  HIDWORD(v21) = (unsigned __int64)(v8 + v21) >> 32;
  if ( v21 >= 0 )
  {
    if ( (v25 % 4 || !(v25 % 100)) && (v25 + 1900) % 400 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v10 = v23;
  v11 = (__PAIR64__(HIDWORD(v21), v9) + 31536000) >> 32;
  v9 += 31536000;
  HIDWORD(v21) = v11;
  v25 = v23;
  if ( !(v23 % 4) )
  {
    if ( v23 % 100 )
    {
LABEL_13:
      v12 = (unsigned int)((unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}}
                         + __PAIR64__(HIDWORD(v21), v9)) >> 32;
      v9 += (unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}};
      HIDWORD(v21) = v12;
LABEL_17:
      v24 = 1;
      goto LABEL_18;
    }
    v10 = v23;
  }
  if ( !((v10 + 1900) % 400) )
    goto LABEL_13;
LABEL_18:
  ptm->tm_year = v25;
  v13 = __SPAIR64__(HIDWORD(v21), v9) / (unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}};
  ptm->tm_yday = v13;
  v15 = (-86400LL * (int)v13 + __PAIR64__(HIDWORD(v21), v9)) >> 32;
  v14 = -86400 * v13 + v9;
  v22 = v15;
  v16 = _lpdays;
  if ( !v24 )
    v16 = _days;
  tm_yday = ptm->tm_yday;
  for ( i = 1; v16[i] < tm_yday; ++i )
    ;
  v19 = i - 1;
  ptm->tm_mon = v19;
  ptm->tm_mday = tm_yday - v16[v19];
  ptm->tm_wday = (int)(*timp / (unsigned int) __thiscall vostok::sound::world::`vcall'{12,{flat}} + 4) % 7;
  ptm->tm_hour = __SPAIR64__(v22, v14) / 3600;
  v20 = -3600LL * (int)(__SPAIR64__(v22, v14) / 3600) + __PAIR64__(v22, v14);
  ptm->tm_min = v20 / 60;
  ptm->tm_isdst = 0;
  ptm->tm_sec = v20 % 60;
  return 0;
}
