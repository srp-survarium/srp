vostok::render::custom_config_value *__usercall stlp_std::priv::__unguarded_partition<vostok::render::custom_config_value *,vostok::render::custom_config_value,bool (__cdecl *)(vostok::render::custom_config_value const &,vostok::render::custom_config_value const &)>@<eax>(
        vostok::render::custom_config_value *__first@<ecx>,
        vostok::render::custom_config_value *__last@<eax>,
        vostok::render::custom_config_value __pivot,
        bool (__cdecl *__comp)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *))
{
  bool (__cdecl *v4)(const vostok::render::custom_config_value *, const vostok::render::custom_config_value *); // ebx
  __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8
  const void *destroyer; // eax

  v4 = __comp;
  while ( 1 )
  {
    for ( ; v4(__first, &__pivot); ++__first )
      ;
    for ( --__last; v4(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    v7 = *(_QWORD *)&__first->id;
    v8 = *(_QWORD *)&__first->id_crc;
    destroyer = __first->destroyer;
    *(_QWORD *)&__first->id = *(_QWORD *)&__last->id;
    *(_QWORD *)&__first->id_crc = *(_QWORD *)&__last->id_crc;
    __first->destroyer = __last->destroyer;
    *(_QWORD *)&__last->id = v7;
    *(_QWORD *)&__last->id_crc = v8;
    __last->destroyer = destroyer;
    ++__first;
  }
  return __first;
}
