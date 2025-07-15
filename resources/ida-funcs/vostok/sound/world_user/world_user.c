void __userpurge vostok::sound::world_user::world_user(
        vostok::sound::world_user *this@<ecx>,
        const char *a2@<ebp>,
        int a3@<edi>,
        const char *a4@<esi>,
        vostok::sound::sound_world *owner,
        vostok::memory::base_allocator *allocator)
{
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  _DWORD *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  int v11; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  _DWORD *v14; // eax
  vostok::memory::doug_lea_allocator *v15; // ecx
  _DWORD *v16; // ebp
  const char *v18; // [esp-8h] [ebp-Ch]
  const char *v19; // [esp-4h] [ebp-8h]
  unsigned int v20; // [esp+0h] [ebp-4h]
  unsigned int v21; // [esp+0h] [ebp-4h]
  _DWORD *v22; // [esp+8h] [ebp+4h]

  *(_DWORD *)a3 = 0;
  *(_DWORD *)(a3 + 4) = -1;
  *(_DWORD *)(a3 + 8) = -1;
  *(_DWORD *)(a3 + 64) = 0;
  *(_DWORD *)(a3 + 68) = 0;
  *(_DWORD *)(a3 + 72) = -1;
  *(_DWORD *)(a3 + 76) = -1;
  *(_DWORD *)(a3 + 132) = 0;
  *(_DWORD *)(a3 + 136) = 0;
  *(_DWORD *)(a3 + 140) = -1;
  *(_DWORD *)(a3 + 144) = -1;
  *(_DWORD *)(a3 + 200) = 0;
  *(_DWORD *)(a3 + 204) = 0;
  *(_DWORD *)(a3 + 208) = -1;
  *(_DWORD *)(a3 + 212) = -1;
  *(_DWORD *)(a3 + 268) = 0;
  *(_DWORD *)(a3 + 280) = owner;
  v6 = vostok::sound::g_allocator;
  *(_DWORD *)(a3 + 272) = 0;
  *(_DWORD *)(a3 + 276) = 0;
  *(_DWORD *)(a3 + 284) = allocator;
  *(_BYTE *)(a3 + 288) = 0;
  v7 = type_info::raw_name(&vostok::sound::sound_response `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0xCu, v7, a4, a2, v20);
  v10 = vostok::sound::g_allocator;
  if ( v9 )
  {
    *v9 = &vostok::sound::sound_response::`vftable';
    v9[1] = v10;
    v9[2] = 0;
    v22 = v9;
  }
  else
  {
    v22 = 0;
  }
  v11 = (int)v10;
  v12 = type_info::raw_name(&vostok::sound::sound_response `RTTI Type Descriptor');
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, v11, 0xCu, v12, v18, v19, v21);
  if ( v14 )
  {
    v15 = vostok::sound::g_allocator;
    *v14 = &vostok::sound::sound_response::`vftable';
    v14[1] = v15;
    v14[2] = 0;
    v16 = v14;
  }
  else
  {
    v16 = 0;
  }
  _InterlockedExchange((volatile __int32 *)(a3 + 4), GetCurrentThreadId());
  v22[2] = 0;
  *(_DWORD *)(a3 + 64) = v22;
  *(_DWORD *)a3 = v22;
  _InterlockedExchange((volatile __int32 *)(a3 + 76), GetCurrentThreadId());
  v16[2] = 0;
  *(_DWORD *)(a3 + 132) = v16;
  *(_DWORD *)(a3 + 68) = v16;
  _InterlockedExchange((volatile __int32 *)(a3 + 144), GetCurrentThreadId());
  _InterlockedExchange((volatile __int32 *)(a3 + 208), GetCurrentThreadId());
}
