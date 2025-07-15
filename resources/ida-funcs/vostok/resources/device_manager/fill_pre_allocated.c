void __usercall vostok::resources::device_manager::fill_pre_allocated(
        vostok::resources::device_manager *this@<ecx>,
        vostok::resources::query_result *a2@<edi>)
{
  vostok::resources::device_manager *v2; // ecx
  int v3; // eax
  int v4; // esi
  bool v5; // [esp+Fh] [ebp-11h]
  int v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-8h]
  int v8; // [esp+1Ch] [ebp-4h]

  v6 = 0;
  v7 = 0;
  v8 = 0;
  do
  {
    ((void (__thiscall *)(vostok::resources::query_result *, int *))a2->link_child_resource)(a2, &v6);
    v3 = v7;
    v5 = v7 != 0;
    if ( v7 )
    {
      do
      {
        v4 = *(_DWORD *)(v3 + 624);
        vostok::resources::device_manager::pre_allocate(v2, a2, (vostok::fs_new::asynchronous_device_interface *)v3);
        v3 = v4;
      }
      while ( v4 );
      if ( v7 )
      {
        v7 = 0;
        v8 = 0;
        v6 = 0;
      }
    }
  }
  while ( v5 );
}
