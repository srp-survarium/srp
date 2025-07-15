void __thiscall vostok::particle::particle_system_instance_impl::remove_emitter_instances(
        vostok::particle::particle_system_instance_impl *this,
        int a2)
{
  int v2; // eax
  _DWORD *v3; // edi
  _DWORD *i; // esi
  int v5; // ebx
  void **v6; // [esp-10h] [ebp-1Ch]
  _BYTE *v7; // [esp+0h] [ebp-Ch]
  void (__thiscall ***inptr)(void *, _DWORD); // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  v2 = a2;
  v9 = 0;
  if ( *(_DWORD *)(a2 + 740) )
  {
    v3 = (_DWORD *)(a2 + 280);
    do
    {
      for ( i = (_DWORD *)*(v3 - 1); i; v2 = a2 )
      {
        v5 = *(_DWORD *)(v2 + 720);
        inptr = (void (__thiscall ***)(void *, _DWORD))i;
        v6 = (void **)i;
        i = (_DWORD *)i[123];
        v7 = __RTCastToVoid(v6);
        (**inptr)(inptr, 0);
        (*(void (__thiscall **)(int, _BYTE *, const char *, const char *, int))(*(_DWORD *)v5 + 24))(
          v5,
          v7,
          "vostok::particle::particle_system_instance_impl::remove_emitter_instances",
          ".\\particle_system_instance_impl.cpp",
          319);
      }
      ++v9;
      *(v3 - 1) = 0;
      *v3 = 0;
      *(v3 - 3) = 0;
      v3 += 8;
    }
    while ( v9 < *(_DWORD *)(v2 + 740) );
  }
}
