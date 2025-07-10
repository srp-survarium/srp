void __usercall stlp_std::__pop_heap<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &),int>(
        vostok::render::custom_config_value *__last@<edx>,
        vostok::render::custom_config_value *__result@<eax>,
        vostok::render::custom_config_value *__first,
        vostok::render::custom_config_value __val,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  unsigned int v5; // edx

  *__result = *__first;
  v5 = (int)((unsigned __int64)(1717986919LL * ((char *)__last - (char *)__first)) >> 32) >> 3;
  stlp_std::__adjust_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
    __first,
    0,
    v5 + (v5 >> 31),
    __val,
    __comp);
}
