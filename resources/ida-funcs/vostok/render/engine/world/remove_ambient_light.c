void __thiscall vostok::render::engine::world::remove_ambient_light(
        vostok::render::engine::world *this,
        vostok::render::ambient_light **in_scene,
        vostok::render::find_by_id_predicate<vostok::render::ambient_light> id)
{
  vostok::render::ambient_light **v3; // esi
  vostok::buffer_vector<vostok::render::ambient_light *> *v4; // ebx
  vostok::render::ambient_light **v5; // eax
  vostok::render::ambient_light **v6; // edi
  char *v7; // esi
  vostok::memory::doug_lea_allocator *v8; // ecx
  vostok::render::ambient_light *v9; // [esp-4h] [ebp-14h]
  const char *v10; // [esp+0h] [ebp-10h]
  const char *v11; // [esp+4h] [ebp-Ch]
  unsigned int v12; // [esp+8h] [ebp-8h]

  v3 = *(vostok::render::ambient_light ***)((char *)&randomizer_16.m_seed + (_DWORD)*in_scene);
  v4 = (vostok::buffer_vector<vostok::render::ambient_light *> *)((int)&SNaN_33 + (_DWORD)*in_scene);
  v5 = stlp_std::priv::__find_if<vostok::render::ambient_light * *,vostok::render::find_by_id_predicate<vostok::render::ambient_light>>(
         v4->m_begin,
         v3,
         id);
  v6 = v5;
  id.m_id = (unsigned int)v5;
  if ( v5 != v3 )
  {
    v7 = (char *)*v5;
    in_scene = (vostok::render::ambient_light **)vostok::render::g_allocator;
    if ( v7 )
    {
      vostok::render::ambient_light::remove_collision(v9, (int)v7);
      vostok::memory::doug_lea_allocator::free_impl(v8, (int)in_scene, v7, v10, v11, v12);
    }
    in_scene = v6 + 1;
    vostok::buffer_vector<vostok::particle::render_particle_emitter_instance *>::erase(
      v4,
      (vostok::render::ambient_light ***)&id,
      &in_scene);
  }
}
