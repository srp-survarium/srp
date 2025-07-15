void __thiscall vostok::sound::wav_encoded_sound_interface::read_riff(vostok::sound::wav_encoded_sound_interface *this)
{
  vostok::sound::wav_encoded_sound_interface *v1; // ecx
  unsigned __int64 v2; // rax
  unsigned __int64 m_samples_per_sec; // [esp-8h] [ebp-90h] BYREF
  vostok::sound::wav_encoded_sound_interface *thisa; // [esp+4h] [ebp-84h]
  char v5; // [esp+14h] [ebp-74h]
  char v6; // [esp+15h] [ebp-73h]
  char v7; // [esp+16h] [ebp-72h]
  char v8; // [esp+17h] [ebp-71h]
  char v9; // [esp+18h] [ebp-70h]
  char v10; // [esp+19h] [ebp-6Fh]
  char v11; // [esp+1Ah] [ebp-6Eh]
  char v12; // [esp+1Bh] [ebp-6Dh]
  char v13; // [esp+1Ch] [ebp-6Ch]
  char v14; // [esp+1Dh] [ebp-6Bh]
  char v15; // [esp+1Eh] [ebp-6Ah]
  char v16; // [esp+1Fh] [ebp-69h]
  const unsigned __int8 *m_data; // [esp+20h] [ebp-68h]
  unsigned int m_size; // [esp+24h] [ebp-64h]
  vostok::sound::wav_utils::wav_raw_file *p_m_wav_file; // [esp+30h] [ebp-58h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v20; // [esp+34h] [ebp-54h]
  volatile int *value; // [esp+38h] [ebp-50h]
  char v22; // [esp+3Eh] [ebp-4Ah]
  char v23; // [esp+3Fh] [ebp-49h]
  vostok::memory::reader reader; // [esp+44h] [ebp-44h]
  vostok::sound::riff r; // [esp+50h] [ebp-38h] BYREF
  vostok::sound::data d; // [esp+5Ch] [ebp-2Ch] BYREF
  vostok::sound::fmt format; // [esp+64h] [ebp-24h] BYREF
  vostok::resources::pinned_ptr_const<unsigned char> pdata; // [esp+7Ch] [ebp-Ch] BYREF

  thisa = this;
  p_m_wav_file = &this->m_wav_file;
  v20 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&m_samples_per_sec
      + 1;
  HIDWORD(m_samples_per_sec) = 0;
  if ( this->m_wav_file.resource.m_object )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v20);
    v20->m_object = (vostok::resources::managed_resource *)p_m_wav_file->resource;
    if ( v20->m_object )
    {
      value = &v20->m_object->m_reference_count;
      vostok::threading::multi_threading_policy::increment<long volatile>(value);
    }
  }
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    &pdata,
    *(vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)((char *)&m_samples_per_sec + 4));
  m_size = pdata.m_size;
  m_data = pdata.m_data;
  reader.m_data = pdata.m_data;
  reader.m_pointer = pdata.m_data;
  reader.m_size = pdata.m_size;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  vostok::memory::copy(&r, 0xCu, pdata.m_data, 0xCu);
  reader.m_pointer += 12;
  v23 = 0;
  v22 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  vostok::memory::copy(&format, 0x18u, reader.m_pointer, 0x18u);
  reader.m_pointer += 24;
  v9 = 0;
  v8 = 0;
  v7 = 0;
  vostok::memory::copy(&d, 8u, reader.m_pointer, 8u);
  reader.m_pointer += 8;
  v6 = 0;
  v5 = 0;
  thisa->m_wav_file.pointer = reader.m_pointer - reader.m_data;
  thisa->m_samples_per_sec = format.fmt_format.nSamplesPerSec;
  thisa->m_bytes_per_sample = (int)format.fmt_format.wBitsPerSample >> 3;
  thisa->m_channels_num = format.fmt_format.nChannels;
  v1 = thisa;
  LODWORD(thisa->m_length_in_pcm) = d.data_size / thisa->m_bytes_per_sample;
  HIDWORD(v1->m_length_in_pcm) = 0;
  HIDWORD(m_samples_per_sec) = 0;
  v2 = 1000 * thisa->m_length_in_pcm;
  m_samples_per_sec = thisa->m_samples_per_sec;
  thisa->m_length_in_msec = v2 / m_samples_per_sec;
  vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pdata);
}
