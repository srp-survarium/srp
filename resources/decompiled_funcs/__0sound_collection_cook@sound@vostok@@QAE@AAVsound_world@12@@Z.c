void __thiscall vostok::sound::sound_collection_cook::sound_collection_cook(
        vostok::sound::sound_collection_cook *this,
        vostok::sound::sound_world *world)
{
  int v2; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::sound_collection_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v4; // [esp+4h] [ebp-8h]

  thisa = this;
  v4 = &v2;
  vostok::resources::translate_query_cook::translate_query_cook(this, sound_collection_class, reuse_true, 0xFFFFFFFC, 0);
  thisa->__vftable = (vostok::sound::sound_collection_cook_vtbl *)&vostok::sound::sound_collection_cook::`vftable';
  thisa->m_world = world;
}
