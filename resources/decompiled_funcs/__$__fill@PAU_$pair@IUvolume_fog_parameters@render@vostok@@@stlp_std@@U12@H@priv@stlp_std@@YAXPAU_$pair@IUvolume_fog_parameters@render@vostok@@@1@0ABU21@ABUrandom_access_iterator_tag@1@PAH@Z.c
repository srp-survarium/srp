void __usercall stlp_std::priv::__fill<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *,stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>,int>(
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__last@<eax>,
        stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__first,
        const stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *__val)
{
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v3; // ebx
  int i; // eax
  stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> *v5; // edi

  v3 = __first;
  for ( i = __last - __first; i > 0; --i )
  {
    v5 = v3++;
    qmemcpy(v5, __val, sizeof(stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>));
  }
}
