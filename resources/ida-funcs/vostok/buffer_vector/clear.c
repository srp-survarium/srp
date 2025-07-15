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


void __thiscall vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::clear(
        vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> > *this)
{
  vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *i; // [esp+4h] [ebp-8h]

  for ( i = (vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)this->m_begin;
        i != (vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)this->m_end;
        ++i )
  {
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>(i);
  }
  this->m_end = this->m_begin;
}


void __thiscall vostok::buffer_vector<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>>::clear(
        vostok::buffer_vector<vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> > *this)
{
  vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> **p_m_end; // edi

  p_m_end = &this->m_end;
  vostok::buffer_vector<vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base>>::destroy(
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *)this->m_begin,
    (vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *const *)&this->m_end);
  *p_m_end = this->m_begin;
}


void __thiscall vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>>::clear(
        vostok::buffer_vector<vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> > *this)
{
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *i; // [esp+4h] [ebp-8h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  this->m_end = this->m_begin;
}


void __thiscall vostok::buffer_vector<vostok::variant<32>>::clear(vostok::buffer_vector<vostok::variant<32> > *this)
{
  vostok::variant<32> **p_m_end; // edi

  p_m_end = &this->m_end;
  vostok::buffer_vector<vostok::variant<32>>::destroy(this->m_begin, &this->m_end);
  *p_m_end = this->m_begin;
}
