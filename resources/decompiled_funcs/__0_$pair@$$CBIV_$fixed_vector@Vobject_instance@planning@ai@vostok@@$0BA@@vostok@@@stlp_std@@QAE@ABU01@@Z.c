void __thiscall stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>(
        stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > *this,
        const stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > *__o)
{
  vostok::ai::planning::object_instance *end; // [esp+3Ch] [ebp-8h] BYREF
  vostok::ai::planning::object_instance *m_buffer; // [esp+40h] [ebp-4h]

  this->first = __o->first;
  m_buffer = (vostok::ai::planning::object_instance *)this->second.m_buffer;
  this->second.m_begin = (vostok::ai::planning::object_instance *)this->second.m_buffer;
  this->second.m_end = m_buffer;
  end = __o->second.m_end;
  vostok::buffer_vector<vostok::ai::planning::object_instance>::assign<vostok::ai::planning::object_instance const *>(
    &this->second,
    __o->second.m_begin,
    (const vostok::ai::planning::object_instance *const *)&end);
}
