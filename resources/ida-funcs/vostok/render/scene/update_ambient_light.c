void __userpurge vostok::render::scene::update_ambient_light(
        vostok::render::scene *this@<ecx>,
        int a2@<edi>,
        vostok::render::find_by_id_predicate<vostok::render::ambient_light> id,
        const vostok::render::ambient_light_properties *properties)
{
  vostok::render::ambient_light **v4; // esi
  vostok::collision::geometry_instance **v5; // eax
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::ambient_light *v10; // ecx
  unsigned int v11; // eax
  vostok::render::ambient_light *v12; // [esp-4h] [ebp-Ch]
  const char *v13; // [esp+0h] [ebp-8h]
  const char *v14; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v4 = *(vostok::render::ambient_light ***)((char *)&randomizer_16.m_seed + a2);
  v5 = (vostok::collision::geometry_instance **)stlp_std::priv::__find_if<vostok::render::ambient_light * *,vostok::render::find_by_id_predicate<vostok::render::ambient_light>>(
                                                  *(vostok::render::ambient_light ***)((char *)&SNaN_33 + a2),
                                                  v4,
                                                  id);
  if ( v5 == (vostok::collision::geometry_instance **)v4 )
  {
    v6 = vostok::render::g_allocator;
    v7 = type_info::raw_name(&vostok::render::ambient_light `RTTI Type Descriptor');
    v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0xA8u, v7, v13, v14, savedregs);
    if ( v9 )
    {
      vostok::render::ambient_light::ambient_light(
        v10,
        (int)v9,
        *(vostok::collision::space_partitioning_tree **)((char *)&dword_8B965C + a2),
        properties,
        id.m_id);
      id.m_id = v11;
    }
    else
    {
      id.m_id = 0;
    }
    vostok::buffer_vector<vostok::render::ambient_light *>::push_back(
      (vostok::buffer_vector<vostok::render::ambient_light *> *)v10,
      (int)&SNaN_33 + a2,
      (vostok::render::ambient_light **)&id);
  }
  else
  {
    vostok::render::ambient_light::set_properties(v12, *v5, (int)properties);
  }
}
