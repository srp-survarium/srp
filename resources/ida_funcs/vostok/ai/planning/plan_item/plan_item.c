void __thiscall vostok::ai::planning::plan_item::plan_item(
        vostok::ai::planning::plan_item *this,
        const vostok::ai::planning::plan_item *__that)
{
  vostok::physics::base_physics_object **end; // [esp+24h] [ebp-8h] BYREF
  vostok::fixed_vector<void const *,4>::allign_helper *m_buffer; // [esp+28h] [ebp-4h]

  this->action = __that->action;
  m_buffer = this->parameters.m_buffer;
  this->parameters.m_begin = (const void **)this->parameters.m_buffer;
  this->parameters.m_end = (const void **)m_buffer;
  end = (vostok::physics::base_physics_object **)__that->parameters.m_end;
  vostok::buffer_vector<vostok::physics::base_physics_object *>::assign<vostok::physics::base_physics_object * *>(
    (vostok::buffer_vector<vostok::physics::base_physics_object *> *)&this->parameters,
    (vostok::physics::base_physics_object **)__that->parameters.m_begin,
    &end);
}
