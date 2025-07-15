unsigned int __thiscall vostok::sound::sound_scene::get_environment_params_id(
        vostok::sound::sound_scene *this,
        const char *name)
{
  unsigned int i; // [esp+28h] [ebp-4h]

  for ( i = 0; i < this->m_environment_parameters._M_impl._M_finish - this->m_environment_parameters._M_impl._M_start; ++i )
  {
    if ( !strcmp(this->m_environment_parameters._M_impl._M_start[i].first.m_begin, name) )
      return i;
  }
  return -1;
}
