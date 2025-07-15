void __usercall vostok::engine::engine_world::destroy_render(vostok::engine::engine_world *this@<ecx>, int a2@<esi>)
{
  HWND v2; // [esp-Ch] [ebp-Ch]

  vostok::render::world::~world((vostok::render::world *)this);
  s_world_0.m_initialized = 0;
  v2 = *(HWND *)(a2 + 672);
  *(_DWORD *)(a2 + 632) = 0;
  ShowWindow(v2, 0);
  s_world_4 = 0;
}
