void __usercall vostok::input::input_world::destroy_devices(vostok::input::input_world *this@<ecx>, int a2@<eax>)
{
  vostok::debug::crash_handler *v3; // eax
  __int32 v4; // eax
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // ebp
  vostok::memory::doug_lea_allocator *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // ebp
  vostok::memory::doug_lea_allocator *v10; // ecx
  vostok::memory::doug_lea_allocator *v11; // esi
  char *v12; // ebp
  vostok::memory::doug_lea_allocator *v13; // ecx
  const char *v14; // [esp+0h] [ebp-14h]
  const char *v15; // [esp+4h] [ebp-10h]
  unsigned int v16; // [esp+8h] [ebp-Ch]
  __int32 v17; // [esp+10h] [ebp-4h] BYREF

  if ( a2 )
    v3 = (vostok::debug::crash_handler *)(a2 + 4);
  else
    v3 = 0;
  vostok::debug::remove_crash_handler(v3);
  _InterlockedExchange(&v17, v4);
  v5 = vostok::input::g_allocator;
  if ( *(_DWORD *)(a2 + 40) )
  {
    v6 = __RTCastToVoid(*(void ***)(a2 + 40));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 40) + 12))(*(_DWORD *)(a2 + 40), 0);
    vostok::memory::doug_lea_allocator::free_impl(v7, (int)v5, v6, v14, v15, v16);
    *(_DWORD *)(a2 + 40) = 0;
  }
  v8 = vostok::input::g_allocator;
  if ( *(_DWORD *)(a2 + 36) )
  {
    v9 = __RTCastToVoid(*(void ***)(a2 + 36));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 36) + 20))(*(_DWORD *)(a2 + 36), 0);
    vostok::memory::doug_lea_allocator::free_impl(v10, (int)v8, v9, v14, v15, v16);
    *(_DWORD *)(a2 + 36) = 0;
  }
  v11 = vostok::input::g_allocator;
  if ( *(_DWORD *)(a2 + 32) )
  {
    v12 = __RTCastToVoid(*(void ***)(a2 + 32));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 32) + 12))(*(_DWORD *)(a2 + 32), 0);
    vostok::memory::doug_lea_allocator::free_impl(v13, (int)v11, v12, v14, v15, v16);
    *(_DWORD *)(a2 + 32) = 0;
  }
  (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(a2 + 28) + 8))(*(_DWORD *)(a2 + 28));
}
