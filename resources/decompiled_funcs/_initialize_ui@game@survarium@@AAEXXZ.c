void __usercall survarium::game::initialize_ui(survarium::game *this@<ecx>, _DWORD *a2@<esi>)
{
  vostok::render::ui::renderer *v2; // ebx
  vostok::input::world *v3; // ebp
  vostok::ui::ui_world *v4; // edi
  int v5; // eax
  vostok::ui::engine *engine; // [esp+4h] [ebp-8h]
  vostok::memory::base_allocator *allocator; // [esp+8h] [ebp-4h]

  if ( a2 )
    engine = (vostok::ui::engine *)a2 + 9;
  else
    engine = 0;
  v2 = *(vostok::render::ui::renderer **)(a2[37] + 12);
  v3 = (vostok::input::world *)a2[35];
  allocator = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v4 = (vostok::ui::ui_world *)(*(int (__stdcall **)(int))(*(_DWORD *)LODWORD(survarium::g_allocator.f_.f_) + 16))(88);
  if ( v4 )
  {
    vostok::ui::ui_world::ui_world(v4, allocator, v3, engine, v2);
    a2[36] = v5;
  }
  else
  {
    a2[36] = 0;
  }
}
