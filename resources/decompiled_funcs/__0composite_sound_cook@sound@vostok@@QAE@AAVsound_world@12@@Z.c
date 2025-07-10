void __thiscall vostok::sound::composite_sound_cook::composite_sound_cook(
        vostok::sound::composite_sound_cook *this,
        vostok::sound::sound_world *world)
{
  int v2; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::composite_sound_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v4; // [esp+4h] [ebp-8h]

  thisa = this;
  v4 = &v2;
  vostok::resources::translate_query_cook::translate_query_cook(this, composite_sound_class, reuse_true, 0xFFFFFFFC, 0);
  thisa->__vftable = (vostok::sound::composite_sound_cook_vtbl *)&vostok::sound::composite_sound_cook::`vftable';
  thisa->m_world = world;
}
