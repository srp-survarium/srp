void __cdecl stlp_std::priv::__introsort_loop<vostok::render::custom_config_value *,vostok::render::custom_config_value,int,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        vostok::render::custom_config_value *__first,
        vostok::render::custom_config_value *__last,
        vostok::render::custom_config_value *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  vostok::render::custom_config_value *v5; // ebx
  const vostok::render::custom_config_value *v6; // esi
  bool v7; // zf
  vostok::render::custom_config_value *v8; // ecx
  bool v9; // al
  vostok::render::custom_config_value *v10; // esi
  const vostok::render::custom_config_value *v11; // [esp-4h] [ebp-14h]
  bool (__cdecl *v12)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // [esp+0h] [ebp-10h]

  v5 = __last;
  if ( __last - __first > 16 )
  {
    do
    {
      if ( !__depth_limit )
      {
        stlp_std::priv::__partial_sort<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
          __first,
          v5,
          v5,
          (vostok::render::custom_config_value *)__comp,
          v12);
        return;
      }
      --__depth_limit;
      v6 = &__first[(v5 - __first) / 2];
      v7 = !__comp(__first, v6);
      v11 = v5 - 1;
      if ( v7 )
      {
        if ( __comp(__first, v11) )
        {
          v8 = __first;
        }
        else
        {
          v9 = __comp(v6, v5 - 1);
          v8 = v5 - 1;
          if ( !v9 )
            goto LABEL_10;
        }
      }
      else
      {
        if ( __comp(v6, v11) || (v6 = v5 - 1, __comp(__first, v5 - 1)) )
        {
LABEL_10:
          v8 = v6;
          goto LABEL_11;
        }
        v8 = __first;
      }
LABEL_11:
      v10 = stlp_std::priv::__unguarded_partition<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
              __first,
              v5,
              *v8,
              __comp);
      stlp_std::priv::__introsort_loop<vostok::render::custom_config_value *,vostok::render::custom_config_value,int,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        v10,
        v5,
        0,
        __depth_limit,
        __comp);
      v5 = v10;
    }
    while ( v10 - __first > 16 );
  }
}
