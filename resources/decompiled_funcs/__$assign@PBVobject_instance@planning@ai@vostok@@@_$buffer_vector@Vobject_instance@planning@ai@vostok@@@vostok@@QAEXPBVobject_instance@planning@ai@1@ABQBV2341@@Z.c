void __thiscall vostok::buffer_vector<vostok::ai::planning::object_instance>::assign<vostok::ai::planning::object_instance const *>(
        vostok::buffer_vector<vostok::ai::planning::object_instance> *this,
        const vostok::ai::planning::object_instance *begin,
        const vostok::ai::planning::object_instance *const *end)
{
  vostok::ai::planning::object_instance *i; // [esp+20h] [ebp-Ch]
  vostok::ai::planning::object_instance *I; // [esp+28h] [ebp-4h]

  for ( i = this->m_begin; i != this->m_end; ++i )
    ;
  this->m_end = &this->m_begin[*end - begin];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  I = this->m_begin;
  while ( begin != *end )
    vostok::buffer_vector<vostok::ai::planning::object_instance>::construct(I++, begin++);
}
