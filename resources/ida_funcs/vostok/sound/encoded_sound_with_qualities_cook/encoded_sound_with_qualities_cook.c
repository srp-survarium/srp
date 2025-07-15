void __thiscall vostok::sound::encoded_sound_with_qualities_cook::encoded_sound_with_qualities_cook(
        vostok::sound::encoded_sound_with_qualities_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::encoded_sound_with_qualities_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(
    this,
    encoded_sound_interface_class,
    reuse_true,
    0xFFFFFFFC,
    0);
  thisa->__vftable = (vostok::sound::encoded_sound_with_qualities_cook_vtbl *)&vostok::sound::encoded_sound_with_qualities_cook::`vftable';
}
