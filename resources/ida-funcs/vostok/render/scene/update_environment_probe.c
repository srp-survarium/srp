void __userpurge vostok::render::scene::update_environment_probe(
        vostok::render::scene *this@<ecx>,
        int a2@<edi>,
        vostok::render::find_environment_probe_predicate id,
        const vostok::render::environment_probe_properties *properties,
        volatile int *ready_flag)
{
  vostok::render::environment_probe **v5; // esi
  vostok::collision::geometry_instance **environment_probe; // eax
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  vostok::render::environment_probe *v11; // ecx
  unsigned int v12; // eax
  vostok::render::environment_probe *v13; // [esp-4h] [ebp-10h]
  const char *v14; // [esp+0h] [ebp-Ch]
  const char *v15; // [esp+4h] [ebp-8h]

  v5 = *(vostok::render::environment_probe ***)(a2 + 9135448);
  environment_probe = (vostok::collision::geometry_instance **)stlp_std::priv::__find_if<vostok::render::environment_probe * *,vostok::render::find_environment_probe_predicate>(
                                                                 *(vostok::render::environment_probe ***)&aAvbtcollisionw[a2 + 4],
                                                                 v5,
                                                                 id);
  if ( environment_probe == (vostok::collision::geometry_instance **)v5 )
  {
    v7 = vostok::render::g_allocator;
    v8 = type_info::raw_name(&vostok::render::environment_probe `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(v9, (int)v7, 0x26Cu, v8, v14, v15, 0);
    if ( v10 )
    {
      vostok::render::environment_probe::environment_probe(
        v11,
        (unsigned int)v10,
        *(vostok::collision::space_partitioning_tree **)((char *)&dword_8B9658 + a2),
        properties,
        id.m_id);
      id.m_id = v12;
    }
    else
    {
      id.m_id = 0;
    }
    vostok::buffer_vector<vostok::render::environment_probe *>::push_back(
      (vostok::buffer_vector<vostok::render::environment_probe *> *)v11,
      (int)&aAvbtcollisionw[a2 + 4],
      (vostok::render::environment_probe **)&id);
  }
  else
  {
    vostok::render::environment_probe::set_properties(v13, *environment_probe, (int)properties);
  }
  if ( ready_flag )
    _InterlockedExchange(ready_flag, 1);
}
