unsigned int __cdecl vostok::sound::ogg_utils::decompress(
        OggVorbis_File *ovf,
        unsigned __int8 *dest,
        unsigned int *pcm_pointer,
        unsigned int bytes_needed)
{
  unsigned int v4; // edi
  int v5; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-3Ch]
  int v10; // [esp+10h] [ebp-28h]
  int bitstream; // [esp+14h] [ebp-24h] BYREF
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+18h] [ebp-20h] BYREF

  v10 = 0;
  v4 = 0;
  ov_pcm_seek(ovf, *pcm_pointer);
  if ( bytes_needed )
  {
    do
    {
      v5 = ov_read(ovf, (char *)&dest[v4], bytes_needed - v4, 0, 2, 1, &bitstream);
      if ( !v5 )
        break;
      if ( v5 >= 0 )
      {
        v4 += v5;
      }
      else
      {
        if ( !vostok::core::g_log_filter_tree
          || (has_passed_filters = vostok::logging::has_passed_filters(
                                     (vostok::logging::filter_tree *)&initiator_raw.filter_stack.m_last,
                                     (const char *)2),
              v6 = v9,
              has_passed_filters) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
            v6,
            &log_callback);
          v10 |= 1u;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\ogg_utils.cpp",
            0x91u,
            "unsigned int __cdecl vostok::sound::ogg_utils::decompress(struct OggVorbis_File *,unsigned char *,unsigned i"
            "nt &,unsigned int)",
            (char *)&initiator_raw.filter_stack.m_last,
            error,
            "Error in vorbis bitstream");
        }
        if ( (v10 & 1) != 0 )
        {
          v10 &= ~1u;
          boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
            (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v6,
            (int *)&log_callback);
        }
      }
    }
    while ( v4 < bytes_needed );
  }
  *pcm_pointer = ov_pcm_tell(ovf);
  return v4;
}
