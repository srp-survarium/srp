void __thiscall vostok::sound::ogg_file_contents_cook::ogg_file_contents_cook(
        vostok::sound::ogg_file_contents_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::ogg_file_contents_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(
    this,
    ogg_file_contents_class,
    reuse_false,
    0xFFFFFFFC,
    0);
  thisa->__vftable = (vostok::sound::ogg_file_contents_cook_vtbl *)&vostok::sound::ogg_file_contents_cook::`vftable';
}
