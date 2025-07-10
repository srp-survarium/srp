void __thiscall vostok::resources::queries_result::push_to_grm_cache(
        vostok::resources::queries_result *this,
        vostok::resources::queries_result *thisa)
{
  unsigned int v2; // edi
  vostok::resources::class_id_enum *p_m_class_id; // esi
  boost::function1<void,char const *> *v4; // ecx
  volatile signed __int32 *v5; // eax

  v2 = 0;
  if ( thisa->m_size )
  {
    p_m_class_id = &thisa->m_queries[0].m_class_id;
    do
    {
      if ( *p_m_class_id != fs_iterator_class && *p_m_class_id != fs_iterator_recursive_class )
      {
        v4 = (boost::function1<void,char const *> *)*((_DWORD *)p_m_class_id + 143);
        if ( v4 )
        {
          if ( *((_DWORD *)p_m_class_id + 31) || *((_DWORD *)p_m_class_id + 32) == 1 )
          {
            if ( ((int)v4->functor.obj_ptr & 1) != 0 )
            {
              v5 = (volatile signed __int32 *)&v4[6].functor.vostok_pointer_size_alignment[5];
            }
            else if ( ((int)v4->functor.obj_ptr & 4) != 0 )
            {
              v5 = (volatile signed __int32 *)&v4[6].functor.vostok_pointer_size_alignment[2];
            }
            else
            {
              v5 = 0;
            }
            _InterlockedExchangeAdd(v5, 0xFFFFFFFF);
            vostok::threading::interlocked_and(v5 + 1, 0xFFFFFFFD);
          }
          else if ( (*(int *)((char *)&dword_205B0 + (unsigned int)vostok::resources::g_resources_manager.m_variable) != 0
                   ? (unsigned int)survarium::weapon_user_dead_state::finalize
                   : 0) != 0 )
          {
            boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
              v4,
              (int *)((char *)&dword_205B0 + (unsigned int)vostok::resources::g_resources_manager.m_variable),
              *((const char **)p_m_class_id + 143));
          }
        }
      }
      ++v2;
      p_m_class_id += 180;
    }
    while ( v2 < thisa->m_size );
  }
}
