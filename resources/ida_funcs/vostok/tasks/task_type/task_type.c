void __userpurge vostok::tasks::task_type::task_type(
        vostok::tasks::task_type *this@<ecx>,
        int a2@<esi>,
        const char *description,
        vostok::tasks::task_type_flags_enum flags)
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(a2 + 72), 0x2710u);
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 96) = 0;
  *(_DWORD *)(a2 + 100) = 0;
  *(_DWORD *)(a2 + 104) = 0;
  *(_DWORD *)(a2 + 108) = description;
  *(_BYTE *)(a2 + 112) = flags;
}
