void __usercall vostok::fs_new::file_type_pointer::close(
        vostok::fs_new::file_type_pointer *this@<ecx>,
        _DWORD *a2@<esi>)
{
  int v2; // ecx

  v2 = a2[1];
  if ( v2 && !vostok::fs_new::g_use_open_file_cache )
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(*a2 + 4) + 8))(*(_DWORD *)(*a2 + 4), v2);
  a2[1] = 0;
}
