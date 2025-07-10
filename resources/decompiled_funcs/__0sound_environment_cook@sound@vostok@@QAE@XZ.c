void __thiscall vostok::sound::sound_environment_cook::sound_environment_cook(
        vostok::sound::sound_environment_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::sound_environment_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(
    this,
    sound_environment_class,
    reuse_false,
    0xFFFFFFFD,
    0);
  thisa->__vftable = (vostok::sound::sound_environment_cook_vtbl *)&vostok::sound::sound_environment_cook::`vftable';
}
