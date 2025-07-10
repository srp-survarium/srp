void __userpurge vostok::tasks::task::task(
        vostok::tasks::task *this@<ecx>,
        int a2@<esi>,
        const boost::function<void __cdecl(void)> *function,
        vostok::tasks::task_type *type,
        unsigned __int64 ordinal,
        vostok::tasks::task *parent)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  boost::function0<void>::assign_to_own((boost::function0<void> *)(a2 + 40), function);
  *(_DWORD *)(a2 + 72) = ordinal;
  *(_DWORD *)(a2 + 80) = type;
  *(_DWORD *)(a2 + 76) = HIDWORD(ordinal);
  *(_DWORD *)(a2 + 84) = parent;
  *(_DWORD *)(a2 + 88) = 1;
  *(_DWORD *)(a2 + 92) = 4;
}
