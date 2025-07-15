void __userpurge vostok::render::one_way_render_channel::one_way_render_channel(
        vostok::render::one_way_render_channel *this@<ecx>,
        int a2@<esi>,
        vostok::memory::base_allocator *owner_allocator)
{
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = -1;
  *(_DWORD *)(a2 + 8) = -1;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = -1;
  *(_DWORD *)(a2 + 76) = -1;
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = owner_allocator;
  *(_DWORD *)(a2 + 144) = CreateEventA(0, 0, 0, 0);
  *(_DWORD *)(a2 + 152) = 0;
  *(_DWORD *)(a2 + 160) = 0;
  *(_DWORD *)(a2 + 164) = 0;
  *(_DWORD *)(a2 + 168) = 0;
  *(_DWORD *)(a2 + 172) = 0;
  *(_DWORD *)(a2 + 176) = 0;
  *(_BYTE *)(a2 + 180) = 0;
  _InterlockedExchange((volatile __int32 *)(a2 + 8), GetCurrentThreadId());
  _InterlockedExchange((volatile __int32 *)(a2 + 72), GetCurrentThreadId());
}
