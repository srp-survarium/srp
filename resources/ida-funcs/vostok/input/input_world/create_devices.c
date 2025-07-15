void __userpurge vostok::input::input_world::create_devices(
        vostok::input::input_world *this@<ecx>,
        int a2@<edi>,
        HWND__ *window_handle,
        char use_journaling_devices)
{
  HMODULE ModuleHandleA; // eax
  IDirectInput8A **v5; // ebx
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // esi
  char *v15; // eax
  vostok::memory::doug_lea_allocator *v16; // ecx
  char *v17; // eax
  vostok::debug::crash_handlers_guard *v18; // ecx
  char *v19; // eax
  vostok::memory::doug_lea_allocator *v20; // ecx
  char *v21; // edx
  int v22; // eax
  vostok::memory::doug_lea_allocator *v23; // esi
  char *v24; // eax
  vostok::memory::doug_lea_allocator *v25; // ecx
  char *v26; // esi
  int v27; // eax
  vostok::memory::doug_lea_allocator *v28; // esi
  char *v29; // eax
  vostok::memory::doug_lea_allocator *v30; // ecx
  char *v31; // esi
  const char *v32; // [esp+0h] [ebp-8h]
  const char *v33; // [esp+0h] [ebp-8h]
  const char *v34; // [esp+0h] [ebp-8h]
  const char *v35; // [esp+0h] [ebp-8h]
  const char *v36; // [esp+0h] [ebp-8h]
  const char *v37; // [esp+4h] [ebp-4h]
  const char *v38; // [esp+4h] [ebp-4h]
  const char *v39; // [esp+4h] [ebp-4h]
  const char *v40; // [esp+4h] [ebp-4h]
  const char *v41; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]
  unsigned int savedregsa; // [esp+8h] [ebp+0h]
  unsigned int savedregsb; // [esp+8h] [ebp+0h]
  unsigned int savedregsc; // [esp+8h] [ebp+0h]
  unsigned int savedregsd; // [esp+8h] [ebp+0h]

  ModuleHandleA = GetModuleHandleA(0);
  v5 = (IDirectInput8A **)(a2 + 28);
  DirectInput8Create(ModuleHandleA, 0x800u, &IID_IDirectInput8A, (LPVOID *)(a2 + 28), 0);
  v6 = vostok::input::g_allocator;
  if ( !use_journaling_devices )
  {
    v19 = type_info::raw_name(&vostok::input::platform::gamepad `RTTI Type Descriptor');
    v21 = vostok::memory::doug_lea_allocator::malloc_impl(v20, (int)v6, 0x60u, v19, v32, v37, savedregs);
    if ( v21 )
      vostok::input::platform::gamepad::gamepad((vostok::input::platform::gamepad *)v21, (vostok::input::world *)a2);
    else
      v22 = 0;
    v23 = vostok::input::g_allocator;
    *(_DWORD *)(a2 + 32) = v22;
    v24 = type_info::raw_name(&vostok::input::platform::keyboard `RTTI Type Descriptor');
    v26 = vostok::memory::doug_lea_allocator::malloc_impl(v25, (int)v23, 0x91Cu, v24, v35, v40, savedregsc);
    if ( v26 )
      vostok::input::platform::keyboard::keyboard(
        (vostok::input::platform::keyboard *)v26,
        *v5,
        window_handle,
        (vostok::input::world *)a2);
    else
      v27 = 0;
    v28 = vostok::input::g_allocator;
    *(_DWORD *)(a2 + 36) = v27;
    v29 = type_info::raw_name(&vostok::input::platform::mouse `RTTI Type Descriptor');
    v31 = vostok::memory::doug_lea_allocator::malloc_impl(v30, (int)v28, 0x38u, v29, v36, v41, savedregsd);
    if ( v31 )
    {
      vostok::input::platform::mouse::mouse(
        (vostok::input::platform::mouse *)v31,
        *v5,
        (vostok::input::world *)a2,
        window_handle);
      goto LABEL_19;
    }
LABEL_18:
    v17 = 0;
    goto LABEL_19;
  }
  v7 = type_info::raw_name(&vostok::journaling::gamepad `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 8u, v7, v32, v37, savedregs);
  if ( v9 )
  {
    *(_DWORD *)v9 = &vostok::journaling::gamepad::`vftable';
    *((_DWORD *)v9 + 1) = a2;
  }
  else
  {
    v9 = 0;
  }
  v10 = vostok::input::g_allocator;
  *(_DWORD *)(a2 + 32) = v9;
  v11 = type_info::raw_name(&vostok::journaling::keyboard `RTTI Type Descriptor');
  v13 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v10, 8u, v11, v33, v38, savedregsa);
  if ( v13 )
  {
    *(_DWORD *)v13 = &vostok::journaling::keyboard::`vftable';
    *((_DWORD *)v13 + 1) = a2;
  }
  else
  {
    v13 = 0;
  }
  v14 = vostok::input::g_allocator;
  *(_DWORD *)(a2 + 36) = v13;
  v15 = type_info::raw_name(&vostok::journaling::mouse `RTTI Type Descriptor');
  v17 = vostok::memory::doug_lea_allocator::malloc_impl(v16, (int)v14, 8u, v15, v34, v39, savedregsb);
  if ( !v17 )
    goto LABEL_18;
  *(_DWORD *)v17 = &vostok::journaling::mouse::`vftable';
  *((_DWORD *)v17 + 1) = a2;
LABEL_19:
  *(_DWORD *)(a2 + 40) = v17;
  _InterlockedExchange((volatile __int32 *)&use_journaling_devices, (__int32)v17);
  vostok::debug::add_crash_handler((vostok::debug::crash_handler *)(a2 + 4), v18);
}
