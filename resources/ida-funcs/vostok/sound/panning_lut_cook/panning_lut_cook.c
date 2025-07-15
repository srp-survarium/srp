void __thiscall vostok::sound::panning_lut_cook::panning_lut_cook(vostok::sound::panning_lut_cook *this)
{
  int v1; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::panning_lut_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v3; // [esp+4h] [ebp-8h]

  thisa = this;
  v3 = &v1;
  vostok::resources::translate_query_cook::translate_query_cook(
    this,
    sound_panning_lut_class,
    reuse_true,
    0xFFFFFFFC,
    0);
  thisa->__vftable = (vostok::sound::panning_lut_cook_vtbl *)&vostok::sound::panning_lut_cook::`vftable';
}
