void __userpurge vostok::animation::mixing::n_ary_tree_serializer::append(
        vostok::animation::mixing::n_ary_tree_serializer *this@<ecx>,
        int a2@<edi>,
        unsigned int value,
        unsigned int bits_to_write)
{
  unsigned int v4; // ebx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v5; // ecx
  bool has_passed_filters; // al
  unsigned int v7; // edx
  int v8; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  char v10; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v11; // [esp+10h] [ebp-20h] BYREF

  v10 = 0;
  v4 = bits_to_write;
  v5 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)bits_to_write;
  if ( (unsigned __int64)value >> bits_to_write )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"animation",
                                 (const char *)2),
          v5 = v9,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v5,
        &v11);
      v10 = 1;
      vostok::logging::append(
        &v11,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\mixing_n_ary_tree_serializer.cpp",
        0x24u,
        "void __thiscall vostok::animation::mixing::n_ary_tree_serializer::append(const unsigned int,const unsigned int)",
        "animation",
        error,
        "value[0x%08x] - bits[%d]",
        value,
        bits_to_write);
    }
    if ( (v10 & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v5,
        (int *)&v11);
  }
  while ( v4 )
  {
    value &= (1LL << v4) - 1;
    v7 = v4 + (*(_DWORD *)(a2 + 8236) + 1 < v4 ? *(_DWORD *)(a2 + 8236) + 1 - v4 : 0);
    v4 = -(*(_DWORD *)(a2 + 8236) + 1 < v4 ? *(_DWORD *)(a2 + 8236) + 1 - v4 : 0);
    **(_BYTE **)(a2 + 8228) |= (unsigned __int8)(value >> v4) << (*(_BYTE *)(a2 + 8236) - v7 + 1);
    v8 = ((unsigned __int8)*(_DWORD *)(a2 + 8236) - (_BYTE)v7) & 7;
    *(_DWORD *)(a2 + 8236) = v8;
    if ( v8 == 7 )
      *(_BYTE *)++*(_DWORD *)(a2 + 8228) = 0;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_serializer::append(
        vostok::animation::mixing::n_ary_tree_serializer *this,
        const float value)
{
  vostok::buffer_vector<float>::push_back(
    (vostok::buffer_vector<float> *)this,
    (int)&this->m_floats_stream,
    (float *)&value);
}
