void __thiscall vostok::render::moved_object_predicate_helper::check_object(
        vostok::render::moved_object_predicate_helper *this,
        const vostok::collision::object *obj)
{
  if ( obj->m_moved )
    vostok::buffer_vector<vostok::collision::object const *>::push_back(
      (vostok::buffer_vector<vostok::collision::object const *> *)this,
      (int)this->m_array,
      &obj);
}
