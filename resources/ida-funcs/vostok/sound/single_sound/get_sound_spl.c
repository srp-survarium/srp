const vostok::resources::resource_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::sound::single_sound::get_sound_spl(
        vostok::sound::single_sound *this)
{
  return (const vostok::resources::resource_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base> *)&this->m_reconstruction_info_actuality_tick
       + 1;
}
