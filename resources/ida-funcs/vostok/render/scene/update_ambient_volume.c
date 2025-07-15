void __userpurge vostok::render::scene::update_ambient_volume(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        vostok::render::find_by_id_predicate<vostok::render::ambient_volume> id,
        vostok::math::aabb *properties)
{
  vostok::render::ambient_volume **v4; // esi
  char *v5; // edi
  const vostok::render::ambient_volume_properties **v6; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  vostok::buffer_vector<vostok::render::ambient_volume *> *v11; // ecx
  char *v12; // esi
  vostok::render::ambient_volume *v13; // ecx
  vostok::render::ambient_volume *v14; // [esp-4h] [ebp-14h]
  vostok::math::aabb *v15; // [esp-4h] [ebp-14h]
  const char *v16; // [esp+0h] [ebp-10h]
  const char *v17; // [esp+4h] [ebp-Ch]
  unsigned int v18; // [esp+8h] [ebp-8h]

  v4 = *(vostok::render::ambient_volume ***)((char *)&vostok::memory::s_resources.m_buffer[9315] + a2);
  v5 = (char *)&vostok::memory::s_resources.m_buffer[9314] + a2;
  v6 = (const vostok::render::ambient_volume_properties **)stlp_std::find_if<vostok::render::ambient_volume * *,vostok::render::find_by_id_predicate<vostok::render::ambient_volume>>(
                                                             *(vostok::render::ambient_volume ***)((char *)&vostok::memory::s_resources.m_buffer[9314]
                                                                                                 + a2),
                                                             v4,
                                                             id);
  if ( v6 == (const vostok::render::ambient_volume_properties **)v4 )
  {
    v7 = vostok::render::g_allocator;
    v8 = type_info::raw_name(&vostok::render::ambient_volume `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x70u, v8, v16, v17, v18);
    v12 = v10;
    if ( v10 )
    {
      *(_DWORD *)v10 = 0;
      vostok::math::create_identity_aabb((vostok::math::aabb *)(v10 + 76));
      v15 = properties;
      *((_DWORD *)v12 + 26) = -1;
      *((vostok::render::find_by_id_predicate<vostok::render::ambient_volume> *)v12 + 25) = id;
      v12[108] = 0;
      vostok::render::ambient_volume::set_properties(v13, (const vostok::render::ambient_volume_properties *)v12, v15);
      properties = (vostok::math::aabb *)v12;
    }
    else
    {
      properties = 0;
    }
    vostok::buffer_vector<vostok::render::ambient_volume *>::push_back(
      v11,
      (int)v5,
      (vostok::render::ambient_volume **)&properties);
  }
  else
  {
    vostok::render::ambient_volume::set_properties(v14, *v6, properties);
  }
}
