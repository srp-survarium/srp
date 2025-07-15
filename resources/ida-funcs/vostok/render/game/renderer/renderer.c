void __userpurge vostok::render::game::renderer::renderer(
        vostok::render::game::renderer *this@<ecx>,
        vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy> *a2@<edi>,
        vostok::render::world *world,
        vostok::render::engine::world *engine_world)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // ebx
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  _DWORD *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  vostok::render::scene_renderer *v13; // eax
  vostok::math::float4x4 *v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+0h] [ebp-30h]
  const char *v17; // [esp+0h] [ebp-30h]
  const char *v18; // [esp+0h] [ebp-30h]
  const char *v19; // [esp+4h] [ebp-2Ch]
  const char *v20; // [esp+4h] [ebp-2Ch]
  boost::function<void __cdecl(vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy> const &)> on_out_of_memory; // [esp+8h] [ebp-28h] BYREF
  __int64 v22; // [esp+28h] [ebp-8h]

  LODWORD(v22) = vostok::render::game::renderer::on_out_of_memory<vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy>>;
  HIDWORD(v22) = a2;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus((vostok::particle::particle_action *)this) )
  {
    on_out_of_memory.vtable = 0;
  }
  else
  {
    *(_QWORD *)&on_out_of_memory.functor.obj_ptr = v22;
    on_out_of_memory.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy> const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::render::game::renderer,vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy> const &>,boost::_bi::list2<boost::_bi::value<vostok::render::game::renderer *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                                     + 1);
  }
  vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy>::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy>(
    &on_out_of_memory,
    a2,
    (vostok::memory::single_size_buffer_allocator<1024,vostok::threading::multi_threading_policy>::node *)&a2[1],
    v16);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v4,
    (int *)&on_out_of_memory);
  v5 = vostok::render::g_allocator;
  v6 = (char *)&dword_200038 + (_DWORD)a2;
  *((_DWORD *)v6 + 1) = 0;
  *((_DWORD *)v6 + 2) = 0;
  *((_DWORD *)v6 + 3) = 0;
  v6[16] = 0;
  *(_DWORD *)v6 = &vostok::memory::allocator_adapter<vostok::memory::single_size_fixed_allocator<1024,2048,vostok::threading::multi_threading_policy>>::`vftable';
  *((_DWORD *)v6 + 5) = a2;
  *(int *)((char *)&dword_200050 + (_DWORD)a2) = (int)world;
  *(int *)((char *)&dword_200054 + (_DWORD)a2) = (int)engine_world;
  *(int *)((char *)&dword_200058 + (_DWORD)a2) = 0;
  v7 = type_info::raw_name(&vostok::render::ui::renderer `RTTI Type Descriptor');
  v9 = vostok::memory::doug_lea_allocator::malloc_impl(
         v8,
         (int)v5,
         0xCu,
         v7,
         v17,
         v19,
         (const unsigned int)on_out_of_memory.vtable);
  if ( v9 )
  {
    *v9 = world;
    v9[1] = engine_world;
    v9[2] = v6;
  }
  else
  {
    v9 = 0;
  }
  v10 = vostok::render::g_allocator;
  *(int *)((char *)&dword_20005C + (_DWORD)a2) = (int)v9;
  v11 = type_info::raw_name(&vostok::render::scene_renderer `RTTI Type Descriptor');
  v13 = (vostok::render::scene_renderer *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            v12,
                                            (int)v10,
                                            0x90u,
                                            v11,
                                            v18,
                                            v20,
                                            (const unsigned int)on_out_of_memory.vtable);
  if ( v13 )
    vostok::render::scene_renderer::scene_renderer(
      engine_world,
      v14,
      v13,
      &world->m_logic_channel,
      (vostok::memory::base_allocator *)((char *)&dword_200038 + (_DWORD)a2),
      *(vostok::math::frustum **)((char *)&dword_200058 + (_DWORD)a2));
  else
    v15 = 0;
  *(int *)((char *)&dword_200060 + (_DWORD)a2) = v15;
}
