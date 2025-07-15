void __thiscall vostok::sound::single_sound_cook::single_sound_cook(vostok::sound::single_sound_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::single_sound_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(this, single_sound_class, reuse_true, 0xFFFFFFFC, 0);
  thisa->__vftable = (vostok::sound::single_sound_cook_vtbl *)&vostok::sound::single_sound_cook::`vftable';
}
