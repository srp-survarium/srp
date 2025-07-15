void __userpurge vostok::input::input_world::input_world(
        vostok::input::input_world *this@<ecx>,
        int a2@<eax>,
        HWND__ *engine,
        HWND__ *window_handle,
        bool use_journaling_devices)
{
  *(_DWORD *)(a2 + 4) = &vostok::debug::crash_handler::`vftable';
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)a2 = &vostok::input::input_world::`vftable'{for `vostok::input::world'};
  *(_DWORD *)(a2 + 4) = &vostok::input::input_world::`vftable'{for `vostok::debug::crash_handler'};
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = this;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = &vostok::journaling::input_handler::`vftable';
  *(_DWORD *)(a2 + 48) = 2;
  *(_BYTE *)(a2 + 52) = 0;
  vostok::input::input_world::create_devices(this, a2, engine, (char)window_handle);
}
