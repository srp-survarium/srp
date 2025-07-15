void __thiscall vostok::sound::sound_world::free_submix_voice(
        vostok::sound::sound_world *this,
        IXAudio2SubmixVoice *voice)
{
  if ( voice )
  {
    voice->SetOutputVoices(voice, 0);
    voice->DestroyVoice(voice);
  }
}
