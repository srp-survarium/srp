void __usercall vostok::sound::sound_instance_proxy::sound_instance_proxy(
        vostok::sound::sound_instance_proxy *this@<ecx>,
        int a2@<edi>)
{
  *(_DWORD *)a2 = &vostok::sound::sound_instance_proxy::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  vostok::sound::atomic_half3::atomic_half3((vostok::sound::atomic_half3 *)this, (_WORD *)(a2 + 56));
}
