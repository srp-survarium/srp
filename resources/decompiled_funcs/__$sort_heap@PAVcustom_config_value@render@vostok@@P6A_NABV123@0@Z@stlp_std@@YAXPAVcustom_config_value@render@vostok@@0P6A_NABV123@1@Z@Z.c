void __usercall stlp_std::sort_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first@<esi>,
        vostok::render::custom_config_value *__last@<ecx>,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v3; // ecx
  const void *v4; // edx
  __int64 v5; // xmm0_8
  __int64 v6; // xmm1_8
  int v7; // edi
  vostok::render::custom_config_value v8; // [esp-18h] [ebp-20h]

  v3 = (char *)__last - (char *)__first;
  if ( v3 / 20 > 1 )
  {
    do
    {
      v4 = *(const void **)((char *)__first + v3 - 4);
      v5 = *(_QWORD *)((char *)&__first[-1].id + v3);
      v6 = *(_QWORD *)((char *)__first + v3 - 12);
      *(vostok::render::custom_config_value *)((char *)__first + v3 - 20) = *__first;
      *(_QWORD *)&v8.id = v5;
      *(_QWORD *)&v8.id_crc = v6;
      v8.destroyer = v4;
      v7 = v3 - 20;
      stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        __first,
        0,
        (v3 - 20) / 20,
        v8,
        __comp);
      v3 = v7;
    }
    while ( v7 / 20 > 1 );
  }
}
