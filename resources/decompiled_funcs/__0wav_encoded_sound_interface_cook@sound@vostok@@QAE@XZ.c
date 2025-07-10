void __thiscall vostok::sound::wav_encoded_sound_interface_cook::wav_encoded_sound_interface_cook(
        vostok::sound::wav_encoded_sound_interface_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::wav_encoded_sound_interface_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(
    this,
    wav_encoded_sound_interface_class,
    reuse_true,
    0xFFFFFFFC,
    0);
  thisa->__vftable = (vostok::sound::wav_encoded_sound_interface_cook_vtbl *)&vostok::sound::wav_encoded_sound_interface_cook::`vftable';
}
