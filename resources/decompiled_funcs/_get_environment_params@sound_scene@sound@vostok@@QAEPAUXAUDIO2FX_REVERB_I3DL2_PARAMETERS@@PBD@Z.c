XAUDIO2FX_REVERB_I3DL2_PARAMETERS *__thiscall vostok::sound::sound_scene::get_environment_params(
        vostok::sound::sound_scene *this,
        const char *name)
{
  unsigned int i; // [esp+2Ch] [ebp-8h]
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *params; // [esp+30h] [ebp-4h]

  params = 0;
  for ( i = 0; i < this->m_environment_parameters._M_impl._M_finish - this->m_environment_parameters._M_impl._M_start; ++i )
  {
    if ( !strcmp(this->m_environment_parameters._M_impl._M_start[i].first.m_begin, name) )
      return this->m_environment_parameters._M_impl._M_start[i].second;
  }
  return params;
}
