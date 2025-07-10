vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__thiscall vostok::intrusive_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
        vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::sound::sound_spl *object)
{
  vostok::sound::encoded_sound_interface *m_object; // [esp+Ch] [ebp-18h]
  vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v5; // [esp+20h] [ebp-4h] BYREF

  v5.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v5,
    object);
  m_object = (vostok::sound::encoded_sound_interface *)v5.m_object;
  v5.m_object = (vostok::sound::sound_spl *)this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5);
  return this;
}
