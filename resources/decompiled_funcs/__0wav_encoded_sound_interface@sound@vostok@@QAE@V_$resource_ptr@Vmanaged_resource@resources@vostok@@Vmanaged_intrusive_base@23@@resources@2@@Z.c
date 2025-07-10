void __thiscall vostok::sound::wav_encoded_sound_interface::wav_encoded_sound_interface(
        vostok::sound::wav_encoded_sound_interface *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> raw_file)
{
  vostok::resources::managed_resource **v2; // eax
  vostok::resources::managed_resource *v4; // [esp+1Ch] [ebp-14h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v5; // [esp+28h] [ebp-8h] BYREF
  vostok::sound::wav_utils::wav_raw_file *p_m_wav_file; // [esp+2Ch] [ebp-4h]

  vostok::sound::encoded_sound_interface::encoded_sound_interface(this);
  this->__vftable = (vostok::sound::wav_encoded_sound_interface_vtbl *)&vostok::sound::wav_encoded_sound_interface::`vftable';
  p_m_wav_file = &this->m_wav_file;
  this->m_wav_file.resource.m_object = 0;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v5,
    &raw_file);
  v4 = *v2;
  *v2 = this->m_wav_file.resource.m_object;
  this->m_wav_file.resource.m_object = v4;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v5);
  this->m_wav_file.pointer = 0;
  vostok::sound::wav_encoded_sound_interface::read_riff(this);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&raw_file);
}
