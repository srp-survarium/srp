int __usercall _gmtime64_s@<eax>(unsigned int a1@<ebx>, tm *ptm, const __int64 *timp)
{
  unsigned int v5; // ecx
  unsigned int v6; // eax
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // et0
  int v12; // et0
  unsigned int v13; // edi
  unsigned int v14; // et0
  int *v15; // edx
  int tm_yday; // eax
  int i; // ecx
  int v18; // ecx
  signed __int64 v19; // kr28_8
  __int64 caltim; // [esp+8h] [ebp-10h]
  unsigned int caltim_4; // [esp+Ch] [ebp-Ch]
  int v22; // [esp+10h] [ebp-8h]
  int islpyr; // [esp+14h] [ebp-4h]
  int tmptim; // [esp+20h] [ebp+8h]

  islpyr = 0;
  if ( !ptm || (memset((int)ptm, (unsigned __int8 *)0xFF, sizeof(tm)), !timp) )
  {
    *_errno() = 22;
    _invalid_parameter(a1, 0, 0x16u);
    return 22;
  }
  v5 = *(_DWORD *)timp;
  v6 = *((_DWORD *)timp + 1);
  LODWORD(caltim) = *(_DWORD *)timp;
  if ( *timp < -43200 || __SPAIR64__(v6, v5) > 0x7934126CFLL )
  {
    *_errno() = 22;
    return 22;
  }
  v7 = __SPAIR64__(v6, v5) / (unsigned int)&vostok::memory::s_CRT_arena[20332984];
  v22 = v7 + 69;
  tmptim = v7 + 70;
  v8 = 86400 * (-365LL * (int)v7 - (((int)v7 + 369) / 400 - ((int)v7 + 69) / 100 + ((int)v7 + 69) / 4 - 17));
  HIDWORD(caltim) = *((_DWORD *)timp + 1);
  v9 = v8 + caltim;
  HIDWORD(caltim) = (unsigned __int64)(v8 + caltim) >> 32;
  if ( caltim >= 0 )
  {
    if ( (tmptim % 4 || !(tmptim % 100)) && (tmptim + 1900) % 400 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v10 = v22;
  v11 = (unsigned int)&vostok::memory::s_CRT_arena[__PAIR64__(HIDWORD(caltim), v9) + 20332984] >> 32;
  v9 += (unsigned int)&vostok::memory::s_CRT_arena[20332984];
  HIDWORD(caltim) = v11;
  tmptim = v22;
  if ( !(v22 % 4) )
  {
    if ( v22 % 100 )
    {
LABEL_13:
      v12 = (__PAIR64__(HIDWORD(caltim), v9) + 86400) >> 32;
      v9 += 86400;
      HIDWORD(caltim) = v12;
LABEL_17:
      islpyr = 1;
      goto LABEL_18;
    }
    v10 = v22;
  }
  if ( !((v10 + 1900) % 400) )
    goto LABEL_13;
LABEL_18:
  ptm->tm_year = tmptim;
  ptm->tm_yday = __SPAIR64__(HIDWORD(caltim), v9) / 86400;
  v14 = (-86400LL * (int)(__SPAIR64__(HIDWORD(caltim), v9) / 86400) + __PAIR64__(HIDWORD(caltim), v9)) >> 32;
  v13 = __SPAIR64__(HIDWORD(caltim), v9) % 86400;
  caltim_4 = v14;
  v15 = _lpdays;
  if ( !islpyr )
    v15 = _days;
  tm_yday = ptm->tm_yday;
  for ( i = 1; v15[i] < tm_yday; ++i )
    ;
  v18 = i - 1;
  ptm->tm_mon = v18;
  ptm->tm_mday = tm_yday - v15[v18];
  ptm->tm_wday = (int)(*timp / 86400 + 4) % 7;
  ptm->tm_hour = __SPAIR64__(caltim_4, v13) / 3600;
  v19 = -3600LL * (int)(__SPAIR64__(caltim_4, v13) / 3600) + __PAIR64__(caltim_4, v13);
  ptm->tm_min = v19 / 60;
  ptm->tm_isdst = 0;
  ptm->tm_sec = v19 % 60;
  return 0;
}
