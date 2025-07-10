void __thiscall stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
        stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *this,
        const stlp_std::priv::_Impl_vector<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params> > *__x)
{
  int v2; // eax
  vostok::sound::sound_voice_params *M_start; // [esp+0h] [ebp-34h]
  unsigned __int8 *src; // [esp+Ch] [ebp-28h]
  vostok::sound::sound_voice_params *M_finish; // [esp+10h] [ebp-24h]
  vostok::vectora_allocator<vostok::sound::sound_voice_params> __a; // [esp+30h] [ebp-4h] BYREF

  __a.m_allocator = __x->_M_end_of_storage.m_allocator;
  stlp_std::priv::_Vector_base<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>::_Vector_base<vostok::sound::sound_voice_params,vostok::vectora_allocator<vostok::sound::sound_voice_params>>(
    this,
    __x->_M_finish - __x->_M_start,
    &__a);
  M_finish = __x->_M_finish;
  src = (unsigned __int8 *)__x->_M_start;
  if ( M_finish == __x->_M_start )
  {
    M_start = this->_M_start;
  }
  else
  {
    memcpy((unsigned __int8 *)this->_M_start, src, (char *)M_finish - (char *)src);
    M_start = (vostok::sound::sound_voice_params *)((char *)M_finish - (char *)src + v2);
  }
  this->_M_finish = M_start;
}
