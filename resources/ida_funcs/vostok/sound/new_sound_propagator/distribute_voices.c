void __thiscall vostok::sound::new_sound_propagator::distribute_voices(
        vostok::sound::new_sound_propagator *this,
        unsigned int count,
        const vostok::vectora<vostok::sound::sound_voice_params> *voices_params)
{
  vostok::sound::new_sound_propagator::attach_voices(this, count, voices_params);
}
