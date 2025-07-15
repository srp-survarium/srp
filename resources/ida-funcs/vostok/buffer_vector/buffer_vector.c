void __thiscall vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
        vostok::buffer_vector<unsigned int> *this,
        unsigned int *buffer,
        unsigned int max_count,
        const vostok::buffer_vector<unsigned int> *other)
{
  unsigned int *end; // [esp+18h] [ebp-4h] BYREF

  this->m_begin = buffer;
  this->m_end = buffer;
  end = other->m_end;
  vostok::buffer_vector<unsigned int>::assign<unsigned int const *>(
    this,
    other->m_begin,
    (const unsigned int *const *)&end);
}


void __thiscall vostok::buffer_vector<unsigned int>::buffer_vector<unsigned int>(
        vostok::buffer_vector<unsigned int> *this,
        unsigned int *buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  this->m_begin = buffer;
  this->m_end = &buffer[live_count];
}


void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<ecx>,
        vostok::buffer_vector<vostok::variant<32> const *> **a2@<eax>,
        unsigned int buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  *a2 = this;
  a2[1] = (vostok::buffer_vector<vostok::variant<32> const *> *)((char *)this + 4 * buffer);
}


void __userpurge vostok::buffer_vector<vostok::variant<32> const *>::buffer_vector<vostok::variant<32> const *>(
        vostok::buffer_vector<vostok::variant<32> const *> *this@<eax>,
        const vostok::variant<32> **buffer@<ecx>,
        const vostok::variant<32> **value@<esi>,
        unsigned int max_count,
        unsigned int count)
{
  const vostok::variant<32> **v5; // edx

  v5 = &buffer[max_count];
  this->m_begin = buffer;
  for ( this->m_end = v5; buffer != this->m_end; ++buffer )
  {
    if ( buffer )
      *buffer = *value;
  }
}


void __thiscall vostok::buffer_vector<void const *>::buffer_vector<void const *>(
        vostok::buffer_vector<void const *> *this,
        const void **buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  survarium::game_camera *v4; // ecx

  this->m_begin = buffer;
  v4 = (survarium::game_camera *)&buffer[live_count];
  this->m_end = (const void **)&v4->__vftable;
  survarium::weapon_user_dead_state::finalize(v4);
}


void __userpurge vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
        vostok::buffer_vector<vostok::resources::request> *this@<ecx>,
        vostok::buffer_vector<vostok::resources::request> **a2@<eax>,
        unsigned int buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  *a2 = this;
  a2[1] = &this[buffer];
}


void __thiscall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::buffer_vector<vostok::animation::mixing::animation_interval>(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this,
        vostok::animation::mixing::animation_interval *buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  this->m_begin = buffer;
  this->m_end = &buffer[live_count];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer);
}


void __thiscall vostok::buffer_vector<vostok::resources::creation_request>::buffer_vector<vostok::resources::creation_request>(
        vostok::buffer_vector<vostok::resources::creation_request> *this,
        vostok::resources::creation_request *buffer,
        unsigned int max_count,
        unsigned int live_count)
{
  this->m_begin = buffer;
  this->m_end = &buffer[live_count];
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer);
}


void __thiscall vostok::buffer_vector<vostok::ai::planning::object_instance>::buffer_vector<vostok::ai::planning::object_instance>(
        vostok::buffer_vector<vostok::ai::planning::object_instance> *this,
        vostok::ai::planning::object_instance *buffer,
        unsigned int max_count,
        const vostok::buffer_vector<vostok::ai::planning::object_instance> *other)
{
  vostok::ai::planning::object_instance *end; // [esp+34h] [ebp-4h] BYREF

  this->m_begin = buffer;
  this->m_end = buffer;
  end = other->m_end;
  vostok::buffer_vector<vostok::ai::planning::object_instance>::assign<vostok::ai::planning::object_instance const *>(
    this,
    other->m_begin,
    (const vostok::ai::planning::object_instance *const *)&end);
}
