void __thiscall vostok::buffer_vector<vostok::physics::base_physics_object *>::assign<vostok::physics::base_physics_object * *>(
        vostok::buffer_vector<vostok::physics::base_physics_object *> *this,
        vostok::physics::base_physics_object **begin,
        vostok::physics::base_physics_object **const *end)
{
  _DWORD *v4; // [esp+8h] [ebp-10h]
  vostok::physics::base_physics_object **i; // [esp+Ch] [ebp-Ch]
  vostok::physics::base_physics_object **I; // [esp+14h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = &this->m_begin[*end - begin];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  I = this->m_begin;
  while ( begin != *end )
  {
    v4 = operator new(4u, I);
    if ( v4 )
      *v4 = *begin;
    ++begin;
    ++I;
  }
}
