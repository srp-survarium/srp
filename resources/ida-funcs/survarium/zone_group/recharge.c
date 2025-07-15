void __userpurge survarium::zone_group::recharge(
        survarium::zone_group *this@<ecx>,
        int a2@<esi>,
        unsigned int current_time_ms)
{
  int v3; // edi
  void *v4; // esp
  int v5; // ecx
  const char **v6; // eax
  int v7; // ebx
  int v8; // ecx
  int v9; // edx
  unsigned int v10; // edi
  bool v11; // zf
  int *v12; // ecx
  int v13; // eax
  const char *v14; // ebx
  int *v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  const char *v19[3]; // [esp+0h] [ebp-24h] BYREF
  const char **v20; // [esp+Ch] [ebp-18h]
  const char **v21; // [esp+10h] [ebp-14h]
  const char **v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+18h] [ebp-Ch]
  unsigned int v24; // [esp+1Ch] [ebp-8h]
  bool v25; // [esp+23h] [ebp-1h] BYREF

  v3 = (*(_DWORD *)(a2 + 24) - *(_DWORD *)(a2 + 20)) >> 2;
  v4 = alloca(4 * v3);
  v5 = *(_DWORD *)(a2 + 24) - *(_DWORD *)(a2 + 20);
  v23 = 0;
  v24 = 0;
  v6 = v19;
  v22 = v19;
  v20 = v19;
  v21 = &v19[v3];
  if ( v5 >> 2 )
  {
    do
    {
      v7 = *(_DWORD *)(a2 + 20);
      if ( *(_BYTE *)(*(_DWORD *)(v7 + 4 * v24) + 292) )
      {
        v23 = *(_DWORD *)(v7 + 4 * v24);
      }
      else
      {
        if ( v6 >= v21
          && !`vostok::buffer_vector<survarium::damage_zone_core *>::push_back'::`11'::debug_macro_helper_ignore_always )
        {
          v25 = 0;
          vostok::debug::on_error(
            &v25,
            process_error_true,
            0,
            "assertion_failed",
            "fatal error",
            "c:\\survarium.deploy\\sources\\vostok/buffer_vector_inline.h",
            "vostok::buffer_vector<class survarium::damage_zone_core *>::push_back",
            (const char *)0x12E,
            "buffer overflow",
            v19[0]);
          if ( vostok::debug::is_debugger_present() || v25 )
            __debugbreak();
          v6 = v20;
        }
        if ( v6 )
          *v6 = *(const char **)(v7 + 4 * v24);
        v20 = ++v6;
      }
      v8 = *(_DWORD *)(a2 + 24) - *(_DWORD *)(a2 + 20);
      ++v24;
    }
    while ( v24 < v8 >> 2 );
  }
  v9 = v6 - v22;
  v10 = v3 - v9;
  v11 = *(_BYTE *)(a2 + 2) == 0;
  v24 = v10;
  if ( v11 && v10 == *(_DWORD *)(a2 + 12) )
    goto LABEL_16;
  v12 = (int *)(*(_DWORD *)(*(_DWORD *)(a2 + 32) + 40) + 408);
  v13 = 134775813 * *v12 + 1;
  *v12 = v13;
  v14 = v22[((unsigned int)v9 * (unsigned __int64)(unsigned int)v13) >> 32];
  if ( *(_BYTE *)(a2 + 2) )
  {
    if ( v23 )
      (*(void (__thiscall **)(_DWORD, int, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 32) + 40) + 24))(
        *(_DWORD *)(*(_DWORD *)(a2 + 32) + 40),
        v23,
        0);
  }
  (*(void (__thiscall **)(_DWORD, const char *, _DWORD))(**(_DWORD **)(*(_DWORD *)(a2 + 32) + 40) + 20))(
    *(_DWORD *)(*(_DWORD *)(a2 + 32) + 40),
    v14,
    0);
  if ( *(_BYTE *)(a2 + 2) )
  {
    v15 = (int *)(*(_DWORD *)(*(_DWORD *)(a2 + 32) + 40) + 408);
    v16 = 1000 * (*(_DWORD *)(a2 + 8) - *(_DWORD *)(a2 + 4));
    v17 = 134775813 * *v15 + 1;
    *v15 = v17;
    v18 = current_time_ms
        + (((unsigned int)v16 * (unsigned __int64)(unsigned int)v17) >> 32)
        + 1000 * *(_DWORD *)(a2 + 4);
  }
  else
  {
    if ( v24 + 1 == *(_DWORD *)(a2 + 12) )
    {
LABEL_16:
      *(_DWORD *)(a2 + 36) = 0;
      return;
    }
    v18 = current_time_ms + 1000 * *(_DWORD *)(a2 + 16);
  }
  *(_DWORD *)(a2 + 36) = v18;
}
