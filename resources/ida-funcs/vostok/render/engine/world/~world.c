void __thiscall vostok::render::engine::world::~world(vostok::render::engine::world *this, void **a2)
{
  unsigned int i; // edi
  char *v3; // esi
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::render::renderer *v5; // ecx
  vostok::ai::fsm_state *v6; // edi
  vostok::memory::doug_lea_allocator *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // ecx
  vostok::render::renderer_context *v9; // ecx
  vostok::render::effect_constant_storage *v10; // ecx
  vostok::render::effect_manager *v11; // ecx
  vostok::render::scene_manager *v12; // ecx
  vostok::render::backend *v13; // ecx
  vostok::render::resource_manager *v14; // ecx
  vostok::render::device *v15; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v16; // ecx
  const char *v17; // [esp+0h] [ebp-14h]
  const char *v18; // [esp+4h] [ebp-10h]
  unsigned int v19; // [esp+8h] [ebp-Ch]
  vostok::memory::doug_lea_allocator *v20; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 0x3C; i += 4 )
  {
    v3 = *(char **)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[i + 4];
    v20 = vostok::render::g_allocator;
    if ( v3 )
    {
      vostok::render::material_effects::~material_effects((vostok::render::material_effects *)this, (int)v3);
      vostok::memory::doug_lea_allocator::free_impl(v4, (int)v20, v3, v17, v18, v19);
      *(_DWORD *)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[i + 4] = 0;
    }
    *(_DWORD *)&s_system_renderer_buffer.m_family[2].orig_name.m_buffer[i + 4] = 0;
  }
  vostok::render::system_renderer::~system_renderer((vostok::render::system_renderer *)this);
  v6 = (vostok::ai::fsm_state *)*a2;
  v7 = vostok::render::g_allocator;
  if ( *a2 )
  {
    vostok::render::renderer::~renderer(v5, v6);
    vostok::memory::doug_lea_allocator::free_impl(v8, (int)v7, (char *)v6, v17, v18, v19);
    *a2 = 0;
  }
  vostok::render::decal_shader_constants_and_geometry::~decal_shader_constants_and_geometry(
    (vostok::render::decal_shader_constants_and_geometry *)v5,
    (int)&unk_D0CF88);
  vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.x = 0.0;
  dword_BF4F4C = dword_BF4F48;
  vostok::quasi_singleton<vostok::render::material_manager>::pinst = 0;
  vostok::render::renderer_context::~renderer_context(v9);
  vostok::render::effect_constant_storage::~effect_constant_storage(v10, dword_DFC4DC);
  vostok::render::effect_manager::~effect_manager(v11, (int)&unk_DB6D34);
  dword_DA5D2C = dword_DA5D28;
  dword_DA5B20 = dword_DA5B1C;
  vostok::quasi_singleton<vostok::render::shader_macros>::pinst = 0;
  vostok::render::scene_manager::~scene_manager(v12, (int)&dword_DA5A38);
  vostok::render::backend::~backend(
    v13,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&unk_DA3C90);
  vostok::render::resource_manager::~resource_manager(v14, (int)&unk_D0D110);
  vostok::render::device::destroy(v15);
  vostok::quasi_singleton<vostok::render::device>::pinst = 0;
  vostok::quasi_singleton<vostok::render::options>::pinst = 0;
  if ( !byte_47E9DA1 )
    byte_47E9DA1 = 1;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v16,
    (int *)a2 + 2);
}
