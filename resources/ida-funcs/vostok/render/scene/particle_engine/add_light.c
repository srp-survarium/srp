void __thiscall vostok::render::scene::particle_engine::add_light(
        vostok::render::scene::particle_engine *this,
        unsigned int id,
        bool enable_shadows,
        bool static_shadows,
        float shadow_transparency,
        unsigned int shadow_map_size_index)
{
  long double v6; // rdi
  vostok::render::light_props props; // [esp+10h] [ebp-F0h] BYREF

  v6 = COERCE_DOUBLE(__PAIR64__(&props, (unsigned int)this));
  vostok::render::light_props::light_props((vostok::render::light_props *)this, (int)&props);
  vostok::render::initialize_base_particle_light_properties(
    &props,
    enable_shadows,
    static_shadows,
    shadow_transparency,
    shadow_map_size_index);
  vostok::render::lights_db::add_light(
    id,
    v6,
    *(vostok::render::lights_db **)((char *)&dword_8B9660 + *(_DWORD *)(LODWORD(v6) + 8)),
    &props);
}
