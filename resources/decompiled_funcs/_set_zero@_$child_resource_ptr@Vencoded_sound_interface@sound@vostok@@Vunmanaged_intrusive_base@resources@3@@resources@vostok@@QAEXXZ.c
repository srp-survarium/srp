void __thiscall vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::set_zero(
        vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *this)
{
  vostok::sound::encoded_sound_interface *m_object; // [esp+Ch] [ebp-24h]
  vostok::intrusive_ptr<vostok::sound::sound_spl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp+20h] [ebp-10h] BYREF

  vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed(this);
  v3.m_object = 0;
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v3,
    0);
  m_object = (vostok::sound::encoded_sound_interface *)v3.m_object;
  v3.m_object = (vostok::sound::sound_spl *)this->m_object;
  this->m_object = m_object;
  vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v3);
}
