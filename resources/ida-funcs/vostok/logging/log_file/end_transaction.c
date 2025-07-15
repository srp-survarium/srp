void __usercall vostok::logging::log_file::end_transaction(vostok::logging::log_file *this@<ecx>, int a2@<eax>)
{
  if ( (*(_DWORD *)(a2 + 17456))-- == 1 )
    *(_DWORD *)(a2 + 17500) = -1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(a2 + 17432));
}
