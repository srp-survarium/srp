void __usercall stlp_std::__make_heap<vostok::render::custom_config_value *,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),vostok::render::custom_config_value,int>(
        vostok::render::custom_config_value *__last@<eax>,
        vostok::render::custom_config_value *__first,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v3; // edi
  int v4; // esi
  vostok::render::custom_config_value *v5; // ebx
  __int64 v6; // xmm0_8
  const void *destroyer; // ecx
  vostok::render::custom_config_value v8; // [esp-18h] [ebp-28h]

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  v5 = &__first[v4];
  stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    v4,
    v3,
    *v5,
    __comp);
  while ( v4 )
  {
    v6 = *(_QWORD *)&v5[-1].id;
    destroyer = v5[-1].destroyer;
    --v5;
    *(_QWORD *)&v8.id = v6;
    *(_QWORD *)&v8.id_crc = *(_QWORD *)&v5->id_crc;
    --v4;
    v8.destroyer = destroyer;
    stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
      __first,
      v4,
      v3,
      v8,
      __comp);
  }
}
