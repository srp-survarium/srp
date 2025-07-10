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
