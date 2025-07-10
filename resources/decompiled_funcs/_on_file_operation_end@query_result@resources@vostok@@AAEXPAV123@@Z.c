void __usercall vostok::resources::query_result::on_file_operation_end(
        vostok::resources::query_result *this@<ecx>,
        _DWORD *a2@<eax>)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // edx
  volatile __int32 *v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // edx
  volatile __int32 *v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  volatile __int32 *v13; // ecx
  vostok::resources::query_result *v14; // ecx

  v2 = a2[158];
  if ( v2 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(v2 + 212) + 32) )
    {
      v3 = *(_DWORD *)(v2 + 212);
      v4 = *(_DWORD *)(v3 + 32);
      v5 = (volatile __int32 *)(v3 + 32);
      if ( v4 )
        _InterlockedExchange(v5, 0);
    }
  }
  v6 = a2[54];
  if ( v6 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(v6 + 212) + 32) )
    {
      v7 = *(_DWORD *)(v6 + 212);
      v8 = *(_DWORD *)(v7 + 32);
      v9 = (volatile __int32 *)(v7 + 32);
      if ( v8 )
        _InterlockedExchange(v9, 0);
    }
  }
  v10 = a2[157];
  if ( v10 )
  {
    if ( *(_DWORD *)(*(_DWORD *)(v10 + 212) + 32) )
    {
      v11 = *(_DWORD *)(v10 + 212);
      v12 = *(_DWORD *)(v11 + 32);
      v13 = (volatile __int32 *)(v11 + 32);
      if ( v12 )
        _InterlockedExchange(v13, 0);
    }
  }
  v14 = (vostok::resources::query_result *)a2[172];
  if ( ((unsigned __int8)v14 & 2) != 0 )
    vostok::resources::query_result::on_load_operation_end(v14, (int)a2);
  else
    vostok::resources::query_result::on_save_operation_end(v14, (int)a2);
}
