void __userpurge vostok::logging::filter_tree::push_filter(
        vostok::logging::filter_tree *this@<ecx>,
        int a2@<eax>,
        char *initiator,
        vostok::logging::verbosity verbosity,
        unsigned int thread_id)
{
  int v6; // esi
  vostok::threading::mutex *v7; // ecx
  int v8; // eax
  vostok::logging::filter_tree *v9; // ecx
  vostok::threading::reader_writer_lock *v10; // ecx
  vostok::threading::reader_writer_lock *v11; // [esp-4h] [ebp-10h]

  if ( !initiator )
    initiator = (char *)uri;
  v6 = (***(int (__thiscall ****)(_DWORD, int))(a2 + 12))(*(_DWORD *)(a2 + 12), 48);
  vostok::strings::copy<32>((char (*)[32])(v6 + 16), initiator);
  *(_DWORD *)(v6 + 12) = -1;
  *(_DWORD *)(v6 + 8) = verbosity;
  vostok::threading::reader_writer_lock::lock_write_impl(v11, (volatile signed __int64 *)a2);
  vostok::threading::mutex::lock(v7, (_RTL_CRITICAL_SECTION *)(a2 + 32));
  v8 = *(_DWORD *)(a2 + 24);
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = v8;
  if ( *(_DWORD *)(a2 + 20) )
    **(_DWORD **)(a2 + 24) = v6;
  else
    *(_DWORD *)(a2 + 20) = v6;
  *(_DWORD *)(a2 + 24) = v6;
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 32));
  vostok::logging::filter_tree::build_tree(v9, a2);
  vostok::threading::reader_writer_lock::unlock(v10, (volatile signed __int64 *)a2, lock_type_write);
}
