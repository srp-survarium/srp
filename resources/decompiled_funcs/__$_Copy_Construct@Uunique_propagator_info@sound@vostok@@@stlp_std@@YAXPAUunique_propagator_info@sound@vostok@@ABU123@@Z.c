void __cdecl stlp_std::_Copy_Construct<vostok::sound::unique_propagator_info>(
        vostok::sound::unique_propagator_info *__p,
        const vostok::sound::unique_propagator_info *__val)
{
  if ( __p )
  {
    stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
      &__p->voice_params._M_impl,
      &__val->voice_params._M_impl);
    __p->prop = __val->prop;
  }
}
