void __thiscall vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this,
        vostok::ai::sound_player *object)
{
  this->m_object = 0;
  if ( this->m_object != object )
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
    this->m_object = object;
    if ( this->m_object )
      vostok::threading::interlocked_increment(&this->m_object->vostok::resources::unmanaged_intrusive_base);
  }
}
