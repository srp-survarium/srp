unsigned int __userpurge vostok::render::grass_world::add_instance@<eax>(
        unsigned int in_template_id@<eax>,
        vostok::render::grass_world *a2@<ecx>,
        vostok::render::grass_world *this,
        const vostok::math::color *in_color,
        const vostok::math::float4x4 *in_transform,
        vostok::render::grass_instance *in_layer,
        float in_wind_scale)
{
  vostok::sound::sound_world_vtbl *v7; // eax
  unsigned int v8; // ebx
  vostok::sound::sound_world_vtbl *v9; // ebp
  vostok::render::grass_instance *v10; // eax
  float v11; // xmm0_4
  unsigned __int8 v12; // cl
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *start_destruction; // ecx
  bool v15; // [esp+0h] [ebp-10h]

  v7 = vostok::render::grass_world::id_to_template(a2, (int)this, in_template_id);
  v8 = g_instance_counter + 1;
  v9 = v7;
  ++g_instance_counter;
  v10 = (vostok::render::grass_instance *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x54u);
  if ( v10 )
  {
    v11 = in_wind_scale;
    v10->m_template = (vostok::render::grass_template *)v9;
    v10->m_color = *in_color;
    qmemcpy((void *)&v10->m_transform, in_transform, sizeof(v10->m_transform));
    v12 = (unsigned __int8)in_layer;
    v10->m_wind_scale = v11;
    v10->m_index = v8;
    v10->m_layer_id = v12;
  }
  else
  {
    v10 = 0;
  }
  start_destruction = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v9->start_destruction;
  in_layer = v10;
  if ( start_destruction == (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v9->get_speed_of_sound )
  {
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
      start_destruction,
      (int)&v9->get_logic_world_user,
      (void **)&start_destruction->_M_start,
      (void *const *)&in_layer,
      (const stlp_std::__true_type *)1,
      1,
      v15);
  }
  else
  {
    start_destruction->_M_start = (void **)&v10->m_template;
    v9->start_destruction = (void (__thiscall *)(vostok::sound::world *))((char *)v9->start_destruction + 4);
  }
  return v8;
}
