void __thiscall survarium::collision_sensor::filter_sensed_objects(
        survarium::collision_sensor *this,
        vostok::buffer_vector<vostok::physics::base_physics_object *> *sensed_objects)
{
  vostok::ai::planning::action_parameter **v2; // [esp+98h] [ebp-14h] BYREF
  vostok::ai::planning::action_parameter **v3[2]; // [esp+9Ch] [ebp-10h] BYREF
  vostok::ai::planning::action_parameter **begin; // [esp+A4h] [ebp-8h] BYREF
  vostok::ai::planning::action_parameter **end; // [esp+A8h] [ebp-4h] BYREF

  end = (vostok::ai::planning::action_parameter **)sensed_objects->m_end;
  v3[1] = (vostok::ai::planning::action_parameter **)this;
  begin = (vostok::ai::planning::action_parameter **)stlp_std::remove_if<vostok::physics::base_physics_object * *,survarium::objects_filter_predicate>(
                                                       sensed_objects->m_begin,
                                                       sensed_objects->m_end,
                                                       (survarium::objects_filter_predicate)this);
  vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
    (vostok::buffer_vector<vostok::ai::planning::action_parameter *> *)sensed_objects,
    &begin,
    &end);
  stlp_std::sort<vostok::physics::base_physics_object * *>(sensed_objects->m_begin, sensed_objects->m_end);
  v3[0] = (vostok::ai::planning::action_parameter **)sensed_objects->m_end;
  v2 = (vostok::ai::planning::action_parameter **)stlp_std::unique<vostok::physics::base_physics_object * *>(
                                                    sensed_objects->m_begin,
                                                    sensed_objects->m_end);
  vostok::buffer_vector<vostok::ai::planning::action_parameter *>::erase(
    (vostok::buffer_vector<vostok::ai::planning::action_parameter *> *)sensed_objects,
    &v2,
    v3);
}
