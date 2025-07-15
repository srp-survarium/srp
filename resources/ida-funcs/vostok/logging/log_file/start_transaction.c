void __usercall vostok::logging::log_file::start_transaction(vostok::logging::log_file *this@<ecx>, int a2@<esi>)
{
  vostok::threading::mutex::lock((vostok::threading::mutex *)this, (_RTL_CRITICAL_SECTION *)(a2 + 17432));
  ++*(_DWORD *)(a2 + 17456);
  *(_DWORD *)(a2 + 17500) = GetCurrentThreadId();
}
