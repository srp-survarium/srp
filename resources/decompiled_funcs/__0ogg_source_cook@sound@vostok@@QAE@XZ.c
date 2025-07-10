void __thiscall vostok::sound::ogg_source_cook::ogg_source_cook(vostok::sound::ogg_source_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::ogg_source_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(this, ogg_raw_file, reuse_true, 0xFFFFFFFD, 0);
  thisa->__vftable = (vostok::sound::ogg_source_cook_vtbl *)&vostok::sound::ogg_source_cook::`vftable';
}
