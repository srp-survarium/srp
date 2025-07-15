void __userpurge vostok::render::scene::update_sky_ambient_occlusion(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion> id,
        const vostok::render::sky_ambient_occlusion_properties *properties)
{
  vostok::render::sky_ambient_occlusion **v4; // esi
  char *v5; // edi
  vostok::render::sky_ambient_occlusion **v6; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  vostok::render::sky_ambient_occlusion *v11; // ecx
  unsigned int v12; // eax
  vostok::render::sky_ambient_occlusion *v13; // [esp-4h] [ebp-Ch]
  const char *v14; // [esp+0h] [ebp-8h]
  const char *v15; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v4 = *(vostok::render::sky_ambient_occlusion ***)((char *)&vostok::memory::s_resources.m_buffer[8288] + a2);
  v5 = (char *)&vostok::memory::s_resources.m_buffer[8287] + a2;
  v6 = stlp_std::priv::__find_if<vostok::render::sky_ambient_occlusion * *,vostok::render::find_by_id_predicate<vostok::render::sky_ambient_occlusion>>(
         *(vostok::render::sky_ambient_occlusion ***)((char *)&vostok::memory::s_resources.m_buffer[8287] + a2),
         v4,
         id);
  if ( v6 == v4 )
  {
    v7 = vostok::render::g_allocator;
    v8 = type_info::raw_name(&vostok::render::sky_ambient_occlusion `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x158u, v8, v14, v15, savedregs);
    if ( v10 )
    {
      vostok::render::sky_ambient_occlusion::sky_ambient_occlusion(v11, (int)v10, properties, id.m_id);
      id.m_id = v12;
    }
    else
    {
      id.m_id = 0;
    }
    vostok::buffer_vector<vostok::render::sky_ambient_occlusion *>::push_back(
      (vostok::buffer_vector<vostok::render::sky_ambient_occlusion *> *)v11,
      (int)v5,
      (vostok::render::sky_ambient_occlusion **)&id);
  }
  else
  {
    vostok::render::sky_ambient_occlusion::set_properties(
      v13,
      (const vostok::render::sky_ambient_occlusion_properties *)*v6,
      &properties->texture_name);
  }
}
