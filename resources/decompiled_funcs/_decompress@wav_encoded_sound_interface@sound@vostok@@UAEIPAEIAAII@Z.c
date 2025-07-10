unsigned int __thiscall vostok::sound::wav_encoded_sound_interface::decompress(
        vostok::sound::wav_encoded_sound_interface *this,
        unsigned __int8 *dest,
        unsigned int pcm_pointer,
        unsigned int *pcm_pointer_after_decompress,
        unsigned int bytes_needed)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v6; // [esp-4h] [ebp-70h] BYREF
  unsigned int v7; // [esp+4h] [ebp-68h]
  vostok::sound::wav_encoded_sound_interface *thisa; // [esp+8h] [ebp-64h]
  unsigned int size; // [esp+18h] [ebp-54h]
  char v10; // [esp+1Dh] [ebp-4Fh]
  char v11; // [esp+1Eh] [ebp-4Eh]
  char v12; // [esp+1Fh] [ebp-4Dh]
  unsigned int v13; // [esp+20h] [ebp-4Ch]
  char v14; // [esp+24h] [ebp-48h]
  char v15; // [esp+25h] [ebp-47h]
  char v16; // [esp+26h] [ebp-46h]
  char v17; // [esp+27h] [ebp-45h]
  const unsigned __int8 *m_data; // [esp+28h] [ebp-44h]
  unsigned int m_size; // [esp+2Ch] [ebp-40h]
  vostok::sound::wav_utils::wav_raw_file *p_m_wav_file; // [esp+38h] [ebp-34h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v21; // [esp+3Ch] [ebp-30h]
  volatile int *value; // [esp+40h] [ebp-2Ch]
  unsigned int v23; // [esp+44h] [ebp-28h]
  vostok::memory::reader reader; // [esp+4Ch] [ebp-20h]
  vostok::resources::pinned_ptr_const<unsigned char> pdata; // [esp+58h] [ebp-14h] BYREF
  unsigned int pcms_needed; // [esp+64h] [ebp-8h]
  unsigned int count; // [esp+68h] [ebp-4h]

  thisa = this;
  p_m_wav_file = &this->m_wav_file;
  v21 = &v6;
  v6.m_object = 0;
  if ( this->m_wav_file.resource.m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v21);
    v21->m_object = (vostok::resources::managed_resource *)p_m_wav_file->resource;
    if ( v21->m_object )
    {
      value = &v21->m_object->m_reference_count;
      vostok::threading::multi_threading_policy::increment<long volatile>(value);
    }
  }
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(&pdata, v6);
  m_size = pdata.m_size;
  m_data = pdata.m_data;
  reader.m_data = pdata.m_data;
  reader.m_pointer = pdata.m_data;
  reader.m_size = pdata.m_size;
  v17 = 0;
  pcms_needed = bytes_needed / thisa->m_bytes_per_sample;
  if ( LODWORD(thisa->m_length_in_pcm) - pcm_pointer >= pcms_needed )
    v7 = pcms_needed;
  else
    v7 = LODWORD(thisa->m_length_in_pcm) - pcm_pointer;
  count = v7;
  v13 = thisa->m_wav_file.pointer + thisa->m_bytes_per_sample * pcm_pointer;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  reader.m_pointer = &reader.m_data[v13];
  size = thisa->m_bytes_per_sample * v7;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  vostok::memory::copy(dest, bytes_needed, &reader.m_data[v13], size);
  reader.m_pointer += size;
  *pcm_pointer_after_decompress = count + pcm_pointer;
  v23 = thisa->m_bytes_per_sample * count;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pdata);
  return v23;
}
