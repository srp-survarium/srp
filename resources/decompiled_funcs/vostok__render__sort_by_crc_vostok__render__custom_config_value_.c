void __cdecl vostok::render::sort_by_crc_vostok::render::custom_config_value_(
        vostok::render::custom_config_value *item)
{
  vostok::render::custom_config_value *data; // esi
  unsigned int i; // edi

  if ( (unsigned int)item->type - 3 <= 1 )
  {
    data = (vostok::render::custom_config_value *)item->data;
    stlp_std::sort<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      data,
      &data[item->count]);
    for ( i = 0; i < item->count; ++data )
    {
      vostok::render::sort_by_crc_vostok::render::custom_config_value_(data);
      ++i;
    }
  }
}
