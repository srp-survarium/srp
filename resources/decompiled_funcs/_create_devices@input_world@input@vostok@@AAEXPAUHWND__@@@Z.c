void __userpurge vostok::input::input_world::create_devices(
        vostok::input::input_world *this@<ecx>,
        vostok::input::world *a2@<edi>,
        HWND__ *window_handle)
{
  HMODULE ModuleHandleA; // eax
  IDirectInput8A **v4; // ebx
  int *v5; // eax
  vostok::input::world_vtbl *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  int *v8; // esi
  vostok::input::world_vtbl *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  int *v11; // esi
  vostok::input::world_vtbl *v12; // eax

  ModuleHandleA = GetModuleHandleA(0);
  v4 = (IDirectInput8A **)&a2[5];
  DirectInput8Create(ModuleHandleA, 0x800u, &IID_IDirectInput8A, (LPVOID *)&a2[5].__vftable, 0);
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(vostok::input::g_allocator, 0x60u);
  if ( v5 )
    vostok::input::receiver::gamepad::gamepad((vostok::input::receiver::gamepad *)v5, a2);
  else
    v6 = 0;
  v7 = vostok::input::g_allocator;
  a2[6].__vftable = v6;
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, 0x914u);
  if ( v8 )
    vostok::input::receiver::keyboard::keyboard((vostok::input::receiver::keyboard *)v8, *v4, a2, window_handle);
  else
    v9 = 0;
  v10 = vostok::input::g_allocator;
  a2[7].__vftable = v9;
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, 0x30u);
  if ( v11 )
  {
    vostok::input::receiver::mouse::mouse((vostok::input::receiver::mouse *)v11, *v4, a2, window_handle);
    a2[8].__vftable = v12;
  }
  else
  {
    a2[8].__vftable = 0;
  }
}
