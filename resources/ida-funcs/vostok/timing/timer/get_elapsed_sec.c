double __usercall vostok::timing::timer::get_elapsed_sec@<st0>(vostok::timing::timer *this@<ecx>, int a2@<eax>)
{
  return (double)vostok::timing::timer::get_elapsed_ticks(this, a2)
       / (double)*(unsigned __int64 *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8);
}
