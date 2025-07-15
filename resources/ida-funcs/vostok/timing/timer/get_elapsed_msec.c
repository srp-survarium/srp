unsigned __int64 __usercall vostok::timing::timer::get_elapsed_msec@<edx:eax>(
        vostok::timing::timer *this@<ecx>,
        int a2@<esi>)
{
  return 1000
       * vostok::timing::timer::get_elapsed_ticks(this, a2)
       / *(_QWORD *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8);
}
