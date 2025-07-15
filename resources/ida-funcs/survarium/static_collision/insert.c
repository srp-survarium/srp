void __userpurge survarium::static_collision::insert(
        survarium::static_collision *this@<ecx>,
        const struct btVector3 *a2@<ebx>,
        vostok::physics::world *w)
{
  vostok::physics::bt_static_rigid_body *v4; // eax
  vostok::physics::bt_rigid_body_construction_info construction_info; // [esp+Ch] [ebp-50h] BYREF

  vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info(
    (vostok::physics::bt_rigid_body_construction_info *)this,
    (int)&construction_info);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->shape_,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&construction_info.m_collisionShape);
  construction_info.m_mass = 0.0;
  v4 = vostok::physics::create_static_rigid_body(
         a2,
         (struct btMotionState *)&this->shape_,
         (struct btCollisionShape *)this,
         &construction_info);
  this->physics_rigid_body_ = v4;
  v4->set_transform(v4, &this->matrix_);
  w->add(w, this->physics_rigid_body_, this->filter_group_, this->filter_mask_);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&construction_info.m_collisionShape);
}
