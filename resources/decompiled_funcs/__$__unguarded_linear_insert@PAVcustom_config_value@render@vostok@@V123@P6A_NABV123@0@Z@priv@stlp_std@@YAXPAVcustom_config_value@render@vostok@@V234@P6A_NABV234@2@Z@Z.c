void __cdecl stlp_std::priv::__unguarded_linear_insert<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value __val)
{
  vostok::render::custom_config_value *__last; // ecx
  unsigned int id_crc; // edx
  vostok::render::custom_config_value *v3; // eax
  const void *destroyer; // eax

  id_crc = __val.id_crc;
  v3 = __last - 1;
  if ( __val.id_crc < __last[-1].id_crc )
  {
    do
    {
      *__last = *v3;
      __last = v3--;
    }
    while ( id_crc < v3->id_crc );
  }
  destroyer = __val.destroyer;
  *(_QWORD *)&__last->id = *(_QWORD *)&__val.id;
  *(_QWORD *)&__last->id_crc = *(_QWORD *)&__val.id_crc;
  __last->destroyer = destroyer;
}
