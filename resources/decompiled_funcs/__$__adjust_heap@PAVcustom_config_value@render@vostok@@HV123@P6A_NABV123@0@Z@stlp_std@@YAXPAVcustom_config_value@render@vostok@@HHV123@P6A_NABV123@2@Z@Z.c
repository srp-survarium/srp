void __usercall stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        int __holeIndex@<eax>,
        vostok::render::custom_config_value *__first,
        int __len,
        vostok::render::custom_config_value __val,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v6; // edi
  int v7; // esi
  bool i; // zf
  vostok::render::custom_config_value *v10; // eax
  vostok::render::custom_config_value *v11; // ecx
  vostok::render::custom_config_value *v12; // eax

  v6 = __holeIndex;
  v7 = 2 * __holeIndex + 2;
  for ( i = v7 == __len; v7 < __len; v11->destroyer = v10->destroyer )
  {
    if ( __comp(&__first[v7], &__first[v7 - 1]) )
      --v7;
    v10 = &__first[v7];
    v11 = &__first[v6];
    *(_QWORD *)&v11->id = *(_QWORD *)&v10->id;
    *(_QWORD *)&v11->id_crc = *(_QWORD *)&v10->id_crc;
    v6 = v7;
    v7 = 2 * v7 + 2;
    i = v7 == __len;
  }
  if ( i )
  {
    v12 = &__first[v7 - 1];
    __first[v6] = *v12;
    v6 = v7 - 1;
  }
  stlp_std::__push_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    v6,
    __holeIndex,
    __val,
    __comp);
}
