void __thiscall vostok::buffer_vector<stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int>>>::clear(
        vostok::buffer_vector<stlp_std::pair<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>,stlp_std::pair<unsigned int,unsigned int> > > *this)
{
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *i; // [esp+4h] [ebp-Ch]

  for ( i = (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this->m_begin;
        i != (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this->m_end;
        i += 3 )
  {
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  this->m_end = this->m_begin;
}
