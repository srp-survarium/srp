void __thiscall survarium::game::initialize_ui(survarium::game *this, vostok::ui::engine *engine)
{
  vostok::render::ui::renderer *v3; // edi
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::ui::ui_world *v6; // edx
  int v7; // eax
  vostok::input::world *input_world; // [esp+Ch] [ebp-4h]
  vostok::ui::engine *enginea; // [esp+18h] [ebp+8h]

  if ( engine )
    enginea = engine + 9;
  else
    enginea = 0;
  v3 = *(vostok::render::ui::renderer **)((char *)&dword_20005C + *(_DWORD *)&engine[172]);
  v4 = survarium::g_allocator;
  input_world = *(vostok::input::world **)&engine[164];
  v5 = type_info::raw_name(&vostok::ui::ui_world `RTTI Type Descriptor');
  v6 = (vostok::ui::ui_world *)v4->call_malloc(v4, 88u, v5, "vostok::ui::create_world", ".\\ui_entry_point.cpp", 13u);
  if ( v6 )
    vostok::ui::ui_world::ui_world(v6, v4, input_world, (const char *)v4, enginea, v3);
  else
    v7 = 0;
  *(_DWORD *)&engine[168] = v7;
}
