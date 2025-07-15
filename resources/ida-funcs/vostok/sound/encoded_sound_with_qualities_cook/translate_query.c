void __thiscall vostok::sound::encoded_sound_with_qualities_cook::translate_query(
        vostok::sound::encoded_sound_with_qualities_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *v2; // eax
  vostok::configs::binary_config *v3; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-4h] [ebp-4Ch] BYREF
  const vostok::resources::memory_type *target_satisfaction; // [esp+0h] [ebp-48h]
  unsigned int v6; // [esp+4h] [ebp-44h]
  vostok::configs::binary_config *v7; // [esp+8h] [ebp-40h]
  vostok::sound::encoded_sound_with_qualities *v8; // [esp+Ch] [ebp-3Ch]
  vostok::sound::encoded_sound_with_qualities_cook *thisa; // [esp+10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v10; // [esp+18h] [ebp-30h]
  char v11; // [esp+37h] [ebp-11h]
  vostok::sound::encoded_sound_with_qualities *v12; // [esp+38h] [ebp-10h]
  char v13; // [esp+3Fh] [ebp-9h]
  vostok::sound::encoded_sound_with_qualities *sound; // [esp+40h] [ebp-8h]
  unsigned int target_quality_level; // [esp+44h] [ebp-4h]

  thisa = this;
  v13 = 0;
  v2 = type_info::name(&vostok::sound::encoded_sound_with_qualities `RTTI Type Descriptor', &__type_info_root_node);
  sound = (vostok::sound::encoded_sound_with_qualities *)vostok::resources::allocate_unmanaged_memory(0x238u, v2);
  if ( sound )
  {
    v12 = sound;
    vostok::sound::encoded_sound_with_qualities::encoded_sound_with_qualities(sound);
    v7 = v3;
    v8 = (vostok::sound::encoded_sound_with_qualities *)v3;
  }
  else
  {
    v8 = 0;
  }
  sound = v8;
  target_quality_level = parent->m_target_quality_level;
  v11 = 0;
  v6 = 568;
  target_satisfaction = &vostok::resources::nocache_memory;
  v10 = &v4;
  v4.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v4,
    (vostok::configs::binary_config *)v8);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    parent,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v4.m_object,
    target_satisfaction,
    v6);
  vostok::resources::resource_quality::increase_quality(
    sound,
    target_quality_level,
    parent->m_target_satisfaction,
    parent);
}
