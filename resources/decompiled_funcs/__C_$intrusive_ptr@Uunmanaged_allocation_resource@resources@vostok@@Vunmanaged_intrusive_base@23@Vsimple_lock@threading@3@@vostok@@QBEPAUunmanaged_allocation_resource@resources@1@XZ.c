vostok::physics::bt_collision_shape *__thiscall vostok::intrusive_ptr<vostok::resources::unmanaged_allocation_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator->(
        vostok::intrusive_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_object;
}
