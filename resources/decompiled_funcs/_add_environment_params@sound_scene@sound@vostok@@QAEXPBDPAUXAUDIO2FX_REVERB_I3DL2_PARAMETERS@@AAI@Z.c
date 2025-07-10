void __thiscall vostok::sound::sound_scene::add_environment_params(
        vostok::sound::sound_scene *this,
        const char *name,
        XAUDIO2FX_REVERB_I3DL2_PARAMETERS *params,
        unsigned int *id)
{
  vostok::fixed_string<64> src; // [esp+3Ch] [ebp-D0h] BYREF
  vostok::vectora<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> > *p_m_environment_parameters; // [esp+B4h] [ebp-58h]
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> v7; // [esp+B8h] [ebp-54h] BYREF

  p_m_environment_parameters = &this->m_environment_parameters;
  *id = this->m_environment_parameters._M_impl._M_finish - this->m_environment_parameters._M_impl._M_start;
  vostok::fixed_string<64>::fixed_string<64>(&src, name);
  vostok::fixed_string<64>::fixed_string<64>(&v7.first, &src);
  v7.second = params;
  stlp_std::priv::_Impl_vector<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>,vostok::vectora_allocator<stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *>>>::push_back(
    &this->m_environment_parameters._M_impl,
    &v7);
}
