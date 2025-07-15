void __thiscall vostok::sound::ogg_encoded_sound_interface::ogg_encoded_sound_interface(
        vostok::sound::ogg_encoded_sound_interface *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> raw_file)
{
  ov_callbacks v2; // [esp-10h] [ebp-54h]
  vorbis_info *ovi; // [esp+30h] [ebp-14h]

  vostok::sound::encoded_sound_interface::encoded_sound_interface(this);
  this->__vftable = (vostok::sound::ogg_encoded_sound_interface_vtbl *)&vostok::sound::ogg_encoded_sound_interface::`vftable';
  this->m_raw_file.resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_raw_file.resource,
    &raw_file);
  this->m_raw_file.pointer = 0;
  v2.read_func = vostok::sound::ogg_utils::ov_read_func;
  v2.seek_func = vostok::sound::ogg_utils::ov_seek_func;
  v2.close_func = vostok::sound::ogg_utils::ov_close_func;
  v2.tell_func = vostok::sound::ogg_utils::ov_tell_func;
  ov_open_callbacks(&this->m_raw_file, &this->m_ovf, 0, 0, v2);
  ovi = ov_info(&this->m_ovf, -1);
  vostok::memory::zero(&this->m_wfx, 0x12u);
  this->m_wfx.nSamplesPerSec = ovi->rate;
  this->m_wfx.wFormatTag = 1;
  this->m_wfx.nChannels = ovi->channels;
  this->m_wfx.wBitsPerSample = 16;
  this->m_wfx.nBlockAlign = this->m_wfx.wBitsPerSample * this->m_wfx.nChannels / 8;
  this->m_wfx.nAvgBytesPerSec = this->m_wfx.nSamplesPerSec * this->m_wfx.nBlockAlign;
  this->m_bytes_per_sample = 2;
  this->m_length_in_pcm = ov_pcm_total(&this->m_ovf, -1);
  this->m_samples_per_sec = ovi->rate;
  this->m_length_in_msec = 1000 * this->m_length_in_pcm / this->m_samples_per_sec;
  this->m_channels_num = ovi->channels;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&raw_file);
}
