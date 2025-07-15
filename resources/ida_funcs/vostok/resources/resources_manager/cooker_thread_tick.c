void __usercall vostok::resources::resources_manager::cooker_thread_tick(
        vostok::resources::resources_manager *this@<ecx>,
        vostok::resources::resources_manager *a2@<eax>)
{
  int v3; // ebx
  vostok::resources::resources_manager *v4; // ecx
  vostok::resources::query_result *v5; // ecx
  int v6; // eax
  int v7; // edi

  if ( *(int *)((char *)&dword_2040C + (_DWORD)a2) )
  {
    vostok::threading::mutex::lock((vostok::threading::mutex *)((char *)nullsub_154 + (_DWORD)a2));
    v3 = *(int *)((char *)&dword_2040C + (_DWORD)a2);
    *(int *)((char *)&dword_2040C + (_DWORD)a2) = 0;
    *(_UNKNOWN **)((char *)&off_20410 + (_DWORD)a2) = 0;
    *(int *)((char *)&dword_203E8 + (_DWORD)a2) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)((char *)nullsub_154 + (_DWORD)a2));
  }
  else
  {
    v3 = 0;
  }
  vostok::resources::resources_manager::dispatch_callbacks(a2, 0);
  vostok::resources::resources_manager::delete_delayed_unmanaged_resources(v4);
  v6 = v3;
  if ( v3 )
  {
    do
    {
      v7 = *(_DWORD *)(v6 + 608);
      vostok::resources::query_result::do_create_resource(v5, v6, 0);
      v6 = v7;
    }
    while ( v7 );
  }
  vostok::resources::resources_manager::decompress_resources((vostok::resources::resources_manager *)v5, a2);
}
