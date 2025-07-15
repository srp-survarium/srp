void __cdecl vostok::ui::create_world(
        vostok::ui::engine *engine,
        vostok::render::ui::renderer *renderer,
        vostok::input::world *input_world)
{
  vostok::memory::base_allocator *f; // esi
  vostok::ui::ui_world *v4; // edi

  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v4 = (vostok::ui::ui_world *)(*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)LODWORD(survarium::g_allocator.f_.f_) + 16))(
                                 survarium::g_allocator.f_.f_,
                                 88);
  if ( v4 )
    vostok::ui::ui_world::ui_world(v4, f, input_world, engine, renderer);
}
