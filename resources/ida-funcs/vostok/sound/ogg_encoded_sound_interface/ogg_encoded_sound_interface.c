void __userpurge vostok::sound::ogg_encoded_sound_interface::ogg_encoded_sound_interface(
        vostok::sound::ogg_encoded_sound_interface *this@<esi>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *ogg_file@<edi>,
        vostok::resources::unmanaged_resource *a3@<ecx>,
        const float *rms_data,
        unsigned int rms_count,
        unsigned int rms_length_in_msec)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(a3, this, fs_iterator_class);
  this->m_active_count = 0;
  this->m_length_in_pcm = 0;
  this->m_length_in_msec = 0;
  this->m_samples_per_sec = 0;
  this->m_bytes_per_sample = 0;
  this->m_channels_num = 0;
  this->__vftable = (vostok::sound::ogg_encoded_sound_interface_vtbl *)&vostok::sound::ogg_encoded_sound_interface::`vftable';
  this->m_raw_file.resource.m_object = 0;
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    ogg_file,
    &this->m_raw_file.resource);
  LODWORD(this->m_length_in_msec) = rms_length_in_msec;
  this->m_rms_count = rms_count;
  this->m_raw_file.pointer = 0;
  HIDWORD(this->m_length_in_msec) = 0;
  this->m_rms_data = rms_data;
}
