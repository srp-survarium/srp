void __thiscall survarium::hit_receiver_info::hit_receiver_info(
        survarium::hit_receiver_info *this,
        survarium::hit_receiver *receiver,
        vostok::physics::base_physics_object *rigid_body)
{
  this->m_receiver = receiver;
  this->m_rigid_body = rigid_body;
  this->m_was_hit = 0;
}
