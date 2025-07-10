void __thiscall vostok::sound::sound_rms::sound_rms(
        vostok::sound::sound_rms *this,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *ogg_raw_file,
        float samples_discr)
{
  ov_callbacks v3; // [esp-Ch] [ebp-394h]
  __int64 v4; // [esp-Ch] [ebp-394h]
  float value; // [esp+0h] [ebp-388h]
  __int64 v6; // [esp+30h] [ebp-358h]
  vostok::resources::managed_resource *m_object; // [esp+58h] [ebp-330h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v9; // [esp+5Ch] [ebp-32Ch] BYREF
  char v10; // [esp+62h] [ebp-326h]
  char v11; // [esp+63h] [ebp-325h]
  float sample; // [esp+64h] [ebp-324h]
  int sit; // [esp+68h] [ebp-320h]
  float *src; // [esp+6Ch] [ebp-31Ch]
  int samples_readed; // [esp+70h] [ebp-318h]
  unsigned int samples_per_sec; // [esp+74h] [ebp-314h]
  int current_section; // [esp+78h] [ebp-310h] BYREF
  float **pcm_buffer; // [esp+7Ch] [ebp-30Ch] BYREF
  unsigned __int64 samples_discr_in_pcm; // [esp+80h] [ebp-308h]
  unsigned int one_sec_samples; // [esp+88h] [ebp-300h]
  unsigned int rms_idx; // [esp+8Ch] [ebp-2FCh]
  float rms; // [esp+90h] [ebp-2F8h]
  unsigned int curr_samples_counter; // [esp+94h] [ebp-2F4h]
  OggVorbis_File ovf; // [esp+98h] [ebp-2F0h] BYREF
  vorbis_info *ovi; // [esp+368h] [ebp-20h]
  ov_callbacks ovc; // [esp+36Ch] [ebp-1Ch]
  vostok::sound::ogg_file_source ogg; // [esp+37Ch] [ebp-Ch] BYREF
  int res; // [esp+384h] [ebp-4h]

  this->m_samples_discr = samples_discr;
  ogg.resource.m_object = 0;
  v9.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v9,
    ogg_raw_file);
  m_object = v9.m_object;
  v9.m_object = ogg.resource.m_object;
  ogg.resource.m_object = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  ogg.pointer = 0;
  ovc.read_func = vostok::sound::ogg_utils::ov_read_func;
  ovc.seek_func = vostok::sound::ogg_utils::ov_seek_func;
  ovc.close_func = vostok::sound::ogg_utils::ov_close_func;
  ovc.tell_func = vostok::sound::ogg_utils::ov_tell_func;
  v3.read_func = vostok::sound::ogg_utils::ov_read_func;
  v3.seek_func = vostok::sound::ogg_utils::ov_seek_func;
  v3.close_func = vostok::sound::ogg_utils::ov_close_func;
  v3.tell_func = vostok::sound::ogg_utils::ov_tell_func;
  res = ov_open_callbacks(&ogg, &ovf, 0, 0, v3);
  v11 = 0;
  ovi = ov_info(&ovf, -1);
  samples_per_sec = ovi->rate;
  one_sec_samples = samples_per_sec;
  v4 = 1000 * ov_pcm_total(&ovf, -1);
  this->m_length_in_msec = v4 / samples_per_sec;
  samples_discr_in_pcm = (unsigned __int64)((double)ovi->rate * this->m_samples_discr);
  v6 = ov_pcm_total(&ovf, -1);
  value = (double)v6 / (double)samples_discr_in_pcm;
  this->m_count = vostok::math::ceil(value);
  rms = *(float *)&FLOAT_0_0;
  curr_samples_counter = 0;
  rms_idx = 0;
  while ( 1 )
  {
    samples_readed = ov_read_float(&ovf, &pcm_buffer, one_sec_samples, &current_section);
    if ( !samples_readed )
      break;
    src = *pcm_buffer;
    for ( sit = 0; sit < samples_readed; ++sit )
    {
      sample = src[sit];
      rms = (float)(sample * sample) + rms;
      if ( ++curr_samples_counter == samples_discr_in_pcm )
      {
        rms = rms / (double)curr_samples_counter;
        this->m_data[rms_idx++] = fsqrt(rms);
        rms = *(float *)&FLOAT_0_0;
        curr_samples_counter = 0;
      }
    }
  }
  if ( curr_samples_counter )
  {
    rms = rms / (double)curr_samples_counter;
    this->m_data[rms_idx++] = fsqrt(rms);
    rms = *(float *)&FLOAT_0_0;
    curr_samples_counter = 0;
  }
  ov_clear(&ovf);
  v10 = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&ogg.resource);
}
