void __thiscall vostok::sound::effect_cross_fader::tick(
        vostok::sound::effect_cross_fader *this,
        unsigned int delta_time_in_ms,
        vostok::sound::sound_environment *current_environment)
{
  float *p_m_fade_in_value; // [esp+28h] [ebp-9Ch]
  float v5; // [esp+74h] [ebp-50h] BYREF
  char v6; // [esp+7Bh] [ebp-49h]
  float v7; // [esp+7Ch] [ebp-48h]
  XAUDIO2FX_REVERB_PARAMETERS native; // [esp+80h] [ebp-44h] BYREF
  IXAudio2SubmixVoice *m_fade_in_submix; // [esp+B4h] [ebp-10h]
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS *params; // [esp+B8h] [ebp-Ch]
  IXAudio2SubmixVoice *temp; // [esp+BCh] [ebp-8h]
  float fade_out_value; // [esp+C0h] [ebp-4h]

  if ( this->m_fade_in_environment == current_environment )
  {
    fade_out_value = *(float *)&FLOAT_0_0;
    if ( this->m_fade_in_value < 1.0 )
    {
      this->m_fade_in_value = (double)delta_time_in_ms * 1.0 / ((double)this->m_fade_time * 1.0) + this->m_fade_in_value;
      v5 = FLOAT_1_0;
      if ( this->m_fade_in_value <= 1.0 )
        p_m_fade_in_value = &this->m_fade_in_value;
      else
        p_m_fade_in_value = &v5;
      this->m_fade_in_value = *p_m_fade_in_value;
      fade_out_value = 1.0 - this->m_fade_in_value;
    }
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_fade_in_submix->SetVolume)(
      this->m_fade_in_submix,
      this->m_fade_in_value,
      0);
    ((void (__stdcall *)(IXAudio2SubmixVoice *, _DWORD, _DWORD))this->m_fade_out_submix->SetVolume)(
      this->m_fade_out_submix,
      1.0 - this->m_fade_in_value,
      0);
  }
  else
  {
    v7 = FLOAT_1_0;
    if ( fabs(this->m_fade_in_value - 1.0) >= 0.0000099999997 )
    {
      this->m_fade_out_environment = this->m_fade_in_environment;
      this->m_fade_in_environment = current_environment;
      this->m_fade_in_value = 1.0 - this->m_fade_in_value;
      temp = this->m_fade_in_submix;
      this->m_fade_in_submix = this->m_fade_out_submix;
      this->m_fade_out_submix = temp;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_fade_in_submix->SetVolume)(
        this->m_fade_in_submix,
        this->m_fade_in_value,
        0);
      ((void (__stdcall *)(IXAudio2SubmixVoice *, _DWORD, _DWORD))this->m_fade_out_submix->SetVolume)(
        this->m_fade_out_submix,
        1.0 - this->m_fade_in_value,
        0);
    }
    else
    {
      params = vostok::sound::sound_scene::get_environment_params(
                 this->m_scene,
                 this->m_fade_out_environment->m_env_params_id);
      v6 = 0;
      ReverbConvertI3DL2ToNative(params, &native);
      this->m_fade_out_submix->SetEffectParameters(this->m_fade_out_submix, 0, &native, 52u, 0);
      this->m_fade_out_environment = this->m_fade_in_environment;
      this->m_fade_in_environment = current_environment;
      this->m_fade_in_value = *(float *)&FLOAT_0_0;
      m_fade_in_submix = this->m_fade_in_submix;
      this->m_fade_in_submix = this->m_fade_out_submix;
      this->m_fade_out_submix = m_fade_in_submix;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->m_fade_in_submix->SetVolume)(
        this->m_fade_in_submix,
        this->m_fade_in_value,
        0);
      ((void (__stdcall *)(IXAudio2SubmixVoice *, _DWORD, _DWORD))this->m_fade_out_submix->SetVolume)(
        this->m_fade_out_submix,
        1.0 - this->m_fade_in_value,
        0);
    }
  }
}
