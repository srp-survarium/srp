void __thiscall vostok::sound::composite_sound::add_sound(
        vostok::sound::composite_sound *this,
        vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> sound,
        const stlp_std::pair<unsigned int,unsigned int> *offsets)
{
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> object; // [esp+2Ch] [ebp-34h] BYREF
  stlp_std::pair<unsigned int,unsigned int> v5; // [esp+30h] [ebp-30h] BYREF
  stlp_std::pair<unsigned int,unsigned int> *p_second; // [esp+38h] [ebp-28h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *p_object; // [esp+3Ch] [ebp-24h]
  volatile int *value; // [esp+40h] [ebp-20h]
  stlp_std::pair<unsigned int,unsigned int> *v9; // [esp+48h] [ebp-18h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > v10; // [esp+4Ch] [ebp-14h] BYREF

  v9 = &v5;
  v5 = *offsets;
  p_object = (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&object;
  object.m_object = 0;
  if ( sound.m_object )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(p_object);
    p_object->m_object = (survarium::game_world_object *)sound.m_object;
    if ( p_object->m_object )
    {
      value = &p_object->m_object->m_reference_count;
      vostok::threading::multi_threading_policy::increment<long volatile>(value);
    }
  }
  v10.first.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10,
    &object);
  p_second = &v10.second;
  v10.second = v5;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&object);
  vostok::buffer_vector<stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int>>>::construct(
    this->m_collection.m_end,
    &v10);
  ++this->m_collection.m_end;
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v10);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&sound);
}
