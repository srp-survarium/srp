void __thiscall vostok::sound::sound_scene_cook::sound_scene_cook(
        vostok::sound::sound_scene_cook *this,
        vostok::sound::sound_world *world)
{
  int v2; // [esp-4h] [ebp-10h] BYREF
  vostok::sound::sound_scene_cook *thisa; // [esp+0h] [ebp-Ch]
  int *v4; // [esp+4h] [ebp-8h]

  thisa = this;
  v4 = &v2;
  vostok::resources::translate_query_cook::translate_query_cook(this, sound_scene_class, reuse_false, 0xFFFFFFFD, 0);
  thisa->__vftable = (vostok::sound::sound_scene_cook_vtbl *)&vostok::sound::sound_scene_cook::`vftable';
  thisa->m_sound_world = world;
}
