IXAudio2SubmixVoice *__thiscall vostok::sound::sound_scene::create_environment_submix_voice(
        vostok::sound::sound_scene *this,
        vostok::sound::sound_world *world)
{
  IXAudio2SubmixVoice *voice; // [esp+24h] [ebp-88h]
  XAUDIO2_EFFECT_DESCRIPTOR effects[1]; // [esp+2Ch] [ebp-80h] BYREF
  XAUDIO2FX_REVERB_PARAMETERS native; // [esp+38h] [ebp-74h] BYREF
  XAUDIO2FX_REVERB_I3DL2_PARAMETERS i3dl2_params; // [esp+6Ch] [ebp-40h] BYREF
  XAUDIO2_EFFECT_CHAIN effectChain; // [esp+A0h] [ebp-Ch] BYREF
  IUnknown *pReverbEffect; // [esp+A8h] [ebp-4h] BYREF

  voice = vostok::sound::sound_world::create_submix_voice(world, 1u, 1u);
  pReverbEffect = 0;
  CoCreateInstance(
    &_GUID_6a93130e_1d53_41d1_a9cf_e758800bb179,
    0,
    1u,
    &_GUID_00000000_0000_0000_c000_000000000046,
    (LPVOID *)&pReverbEffect);
  effects[0].pEffect = pReverbEffect;
  effects[0].InitialState = 1;
  effects[0].OutputChannels = 1;
  effectChain.EffectCount = 1;
  effectChain.pEffectDescriptors = effects;
  voice->SetEffectChain(voice, &effectChain);
  i3dl2_params.WetDryMix = 100.0;
  i3dl2_params.Room = -10000;
  i3dl2_params.RoomHF = 0;
  i3dl2_params.RoomRolloffFactor = *(float *)&FLOAT_0_0;
  i3dl2_params.DecayTime = FLOAT_1_0;
  i3dl2_params.DecayHFRatio = FLOAT_0_5;
  i3dl2_params.Reflections = -10000;
  i3dl2_params.ReflectionsDelay = 0.02;
  i3dl2_params.Reverb = -10000;
  i3dl2_params.ReverbDelay = 0.039999999;
  i3dl2_params.Diffusion = 100.0;
  i3dl2_params.Density = 100.0;
  i3dl2_params.HFReference = 5000.0;
  ReverbConvertI3DL2ToNative(&i3dl2_params, &native);
  ((void (__thiscall *)(IXAudio2SubmixVoice *, IXAudio2SubmixVoice *, _DWORD, XAUDIO2FX_REVERB_PARAMETERS *, int, _DWORD))voice->SetEffectParameters)(
    voice,
    voice,
    0,
    &native,
    52,
    0);
  return voice;
}
