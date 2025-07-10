void __thiscall vostok::sound::voice_bridge::set_sample_rate(
        vostok::sound::voice_bridge *this,
        unsigned int new_sample_rate)
{
  if ( this->m_sample_rate != new_sample_rate )
  {
    this->m_sample_rate = new_sample_rate;
    this->m_source_voice->SetSourceSampleRate(this->m_source_voice, new_sample_rate);
  }
}
