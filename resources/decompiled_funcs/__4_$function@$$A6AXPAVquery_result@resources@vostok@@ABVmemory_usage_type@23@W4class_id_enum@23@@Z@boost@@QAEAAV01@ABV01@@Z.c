boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> *__thiscall boost::function<void __cdecl (vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)>::operator=(
        boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> *this)
{
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *v1; // ecx
  void (__cdecl *v2)(_BYTE *, _BYTE *, int); // eax
  const boost::function4<void,unsigned int,float,float,char const *> *v4; // [esp+0h] [ebp-28h]
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+8h] [ebp-20h]
  _BYTE v7[24]; // [esp+10h] [ebp-18h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)this,
    v4);
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::swap(
    v1,
    v5);
  if ( v6 )
  {
    if ( (v6 & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v6 & 0xFFFFFFFE);
      if ( v2 )
        v2(v7, v7, 2);
    }
  }
  return &s_resource_freed_callback;
}
