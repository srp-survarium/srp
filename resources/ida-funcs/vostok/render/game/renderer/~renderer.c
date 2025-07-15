void __usercall vostok::render::game::renderer::~renderer(vostok::render::game::renderer *this@<ecx>, int *a2@<edi>)
{
  const char *v2; // [esp+0h] [ebp-Ch]
  const char *v3; // [esp+4h] [ebp-8h]
  unsigned int v4; // [esp+8h] [ebp-4h]

  if ( *(int *)((char *)&dword_200060 + (_DWORD)a2) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      *(void **)((char *)&dword_200060 + (_DWORD)a2),
      v2,
      v3,
      v4);
    *(int *)((char *)&dword_200060 + (_DWORD)a2) = 0;
  }
  if ( *(int *)((char *)&dword_20005C + (_DWORD)a2) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      *(void **)((char *)&dword_20005C + (_DWORD)a2),
      v2,
      v3,
      v4);
    *(int *)((char *)&dword_20005C + (_DWORD)a2) = 0;
  }
  if ( *(int *)((char *)&dword_200058 + (_DWORD)a2) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)this,
      (int)vostok::render::g_allocator,
      *(void **)((char *)&dword_200058 + (_DWORD)a2),
      v2,
      v3,
      v4);
    *(int *)((char *)&dword_200058 + (_DWORD)a2) = 0;
  }
  *(int *)((char *)&dword_200038 + (_DWORD)a2) = (int)&vostok::memory::base_allocator::`vftable';
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    a2);
}
