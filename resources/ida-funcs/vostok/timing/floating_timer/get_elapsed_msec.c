unsigned __int64 __usercall vostok::timing::floating_timer::get_elapsed_msec@<edx:eax>(
        vostok::timing::floating_timer *this@<ecx>,
        vostok::timing::floating_timer *a2@<esi>)
{
  LARGE_INTEGER v3; // [esp+4h] [ebp-8h] BYREF

  return 1000
       * vostok::timing::floating_timer::get_elapsed_ticks_impl(a2, &v3)
       / *(_QWORD *)(*(_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 8);
}
