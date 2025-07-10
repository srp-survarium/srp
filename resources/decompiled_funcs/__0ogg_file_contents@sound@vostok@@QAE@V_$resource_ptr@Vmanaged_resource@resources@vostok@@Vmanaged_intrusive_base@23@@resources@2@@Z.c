void __thiscall vostok::sound::ogg_file_contents::ogg_file_contents(
        vostok::sound::ogg_file_contents *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> raw_file)
{
  vorbis_info *v2; // eax
  ov_callbacks v3; // [esp-10h] [ebp-50h]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  this->__vftable = (vostok::sound::ogg_file_contents_vtbl *)&vostok::sound::ogg_file_contents::`vftable';
  this->m_raw_file.resource.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_raw_file.resource,
    &raw_file);
  this->m_raw_file.pointer = 0;
  vostok::memory::zero(&this->m_wfx, 0x12u);
  v3.read_func = vostok::sound::ogg_utils::ov_read_func;
  v3.seek_func = vostok::sound::ogg_utils::ov_seek_func;
  v3.close_func = vostok::sound::ogg_utils::ov_close_func;
  v3.tell_func = vostok::sound::ogg_utils::ov_tell_func;
  ov_open_callbacks(&this->m_raw_file, &this->m_ovf, 0, 0, v3);
  v2 = ov_info(&this->m_ovf, -1);
  this->m_wfx.nSamplesPerSec = v2->rate;
  this->m_wfx.wFormatTag = 1;
  this->m_wfx.nChannels = v2->channels;
  this->m_wfx.wBitsPerSample = 16;
  this->m_wfx.nBlockAlign = this->m_wfx.wBitsPerSample * this->m_wfx.nChannels / 8;
  this->m_wfx.nAvgBytesPerSec = this->m_wfx.nSamplesPerSec * this->m_wfx.nBlockAlign;
  this->m_pcm_total = ov_pcm_total(&this->m_ovf, -1);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&raw_file);
}
