char __thiscall survarium::left_objects_predicate::operator()(
        survarium::left_objects_predicate *this,
        vostok::physics::base_physics_object *obj)
{
  vostok::physics::base_physics_object **m_end; // [esp+10h] [ebp-14h]

  m_end = this->m_current_objects->m_end;
  if ( stlp_std::find<vostok::physics::base_physics_object * const *,vostok::physics::base_physics_object *>(
         (survarium::collision_geometry_subscriber **)this->m_current_objects->m_begin,
         (survarium::collision_geometry_subscriber **)m_end,
         (survarium::collision_geometry_subscriber *const *)&obj) != (survarium::collision_geometry_subscriber **)m_end )
    return 0;
  vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
    (vostok::buffer_vector<void const *> *)this->m_objects_to_delete,
    (const void **)&obj);
  return 1;
}
