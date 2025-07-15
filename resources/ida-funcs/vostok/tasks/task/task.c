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
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(a2 + 40));
  *(_DWORD *)(a2 + 72) = type;
  *(_DWORD *)(a2 + 76) = ordinal;
  *(_DWORD *)(a2 + 80) = function;
  *(_DWORD *)(a2 + 84) = HIDWORD(ordinal);
  *(_DWORD *)(a2 + 88) = 1;
  *(_DWORD *)(a2 + 92) = 4;
}


void __usercall vostok::tasks::task::task(vostok::tasks::task *this@<ecx>, _DWORD *a2@<eax>)
{
  a2[1] = 0;
  a2[3] = 0;
  a2[4] = 0;
  a2[6] = 0;
  a2[7] = 0;
  a2[8] = 0;
  a2[9] = 0;
  a2[10] = 0;
  a2[18] = 0;
  a2[19] = 0;
  a2[20] = 0;
  a2[21] = 0;
  a2[22] = 1;
  a2[23] = 4;
}
