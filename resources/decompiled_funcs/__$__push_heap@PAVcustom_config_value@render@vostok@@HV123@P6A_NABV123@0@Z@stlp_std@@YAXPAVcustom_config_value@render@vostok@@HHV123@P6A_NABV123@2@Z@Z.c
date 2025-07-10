void __usercall stlp_std::__push_heap<vostok::render::custom_config_value *,int,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>(
        int __holeIndex@<eax>,
        vostok::render::custom_config_value *__first,
        int __topIndex,
        vostok::render::custom_config_value __val,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  int v5; // edi
  int v6; // esi
  const vostok::render::custom_config_value *v7; // ebx
  bool v8; // cc
  const void *destroyer; // ecx
  vostok::render::custom_config_value *v10; // eax

  v5 = __holeIndex;
  v6 = (__holeIndex - 1) / 2;
  if ( __holeIndex > __topIndex )
  {
    do
    {
      v7 = &__first[v6];
      if ( !__comp(v7, &__val) )
        break;
      __first[v5] = *v7;
      v5 = v6;
      v8 = v6 <= __topIndex;
      v6 = (v6 - 1) / 2;
    }
    while ( !v8 );
  }
  destroyer = __val.destroyer;
  v10 = &__first[v5];
  *(_QWORD *)&v10->id = *(_QWORD *)&__val.id;
  *(_QWORD *)&v10->id_crc = *(_QWORD *)&__val.id_crc;
  v10->destroyer = destroyer;
}
