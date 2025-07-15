unsigned int __cdecl vostok::sound::ogg_utils::decompress(
        OggVorbis_File *ovf,
        unsigned __int8 *dest,
        unsigned int *pcm_pointer,
        unsigned int bytes_needed)
{
  int v5; // [esp+18h] [ebp-3Ch]
  boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> v6; // [esp+1Ch] [ebp-38h] BYREF
  char *dest_ptr; // [esp+40h] [ebp-14h]
  int current_section; // [esp+44h] [ebp-10h] BYREF
  int bigendianp; // [esp+48h] [ebp-Ch]
  unsigned int total_readed; // [esp+4Ch] [ebp-8h]
  int ret; // [esp+50h] [ebp-4h]

  v5 = 0;
  total_readed = 0;
  ov_pcm_seek(ovf, *pcm_pointer);
  bigendianp = 0;
  while ( total_readed < bytes_needed )
  {
    dest_ptr = (char *)&dest[total_readed];
    ret = ov_read(ovf, (char *)&dest[total_readed], bytes_needed - total_readed, bigendianp, 2, 1, &current_section);
    if ( !ret )
      break;
    if ( ret >= 0 )
    {
      total_readed += ret;
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "sound:", error) )
      {
        v6.vtable = 0;
        boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          &v6,
          vostok::core::g_log_callback);
        v5 |= 1u;
        vostok::logging::append(
          (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&v6,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\ogg_utils.cpp",
          0x66u,
          "unsigned int __cdecl vostok::sound::ogg_utils::decompress(struct OggVorbis_File *,unsigned char *,unsigned int"
          " &,unsigned int)",
          "sound:",
          error,
          "Error in vorbis bitstream");
      }
      if ( (v5 & 1) != 0 )
      {
        v5 &= ~1u;
        boost::function<void __cdecl (void)>::~function<void __cdecl (void)>(&v6);
      }
    }
  }
  *pcm_pointer = ov_pcm_tell(ovf);
  return total_readed;
}
