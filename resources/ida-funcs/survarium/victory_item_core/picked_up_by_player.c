void __thiscall survarium::victory_item_core::picked_up_by_player(survarium::victory_item_core *this)
{
  survarium::usable_object *v2; // edi
  survarium::base_player *m_user; // eax

  if ( this->m_usable_object_users.m_first )
  {
    v2 = &this->survarium::usable_object;
    do
      v2->use_finalize(&this->survarium::usable_object, this->m_usable_object_users.m_last);
    while ( this->m_usable_object_users.m_first );
  }
  survarium::usable_object::remove((survarium::usable_object *)this, &this->survarium::usable_object);
  m_user = this->m_user;
  this->m_collision_is_inserted = 0;
  m_user->m_inventory.m_object->m_carried_item = this;
}
