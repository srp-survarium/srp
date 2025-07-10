void __thiscall vostok::sound::sound_spl_cook::sound_spl_cook(vostok::sound::sound_spl_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::sound_spl_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(this, sound_spl_class, reuse_true, 0xFFFFFFFC, 0);
  thisa->__vftable = (vostok::sound::sound_spl_cook_vtbl *)&vostok::sound::sound_spl_cook::`vftable';
}
