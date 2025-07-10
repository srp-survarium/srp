void __userpurge survarium::static_collision::insert(
        survarium::static_collision *this@<ecx>,
        btRigidBody *a2@<ebx>,
        int a3@<edi>,
        vostok::physics::bt_collision_shape *a4@<esi>,
        vostok::physics::world *w)
{
  vostok::physics::bt_rigid_body_construction_info info; // [esp+14h] [ebp-34h] BYREF

  vostok::physics::bt_rigid_body_construction_info::bt_rigid_body_construction_info((vostok::physics::bt_rigid_body_construction_info *)this);
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    &info.m_collisionShape,
    &this->shape_);
  info.m_mass = *(float *)&FLOAT_0_0;
  this->physics_rigid_body_ = vostok::physics::create_static_rigid_body(&info, a2, a3, a4);
  this->physics_rigid_body_->set_transform(this->physics_rigid_body_, (const vostok::math::float4x4 *)this);
  w->add(w, this->physics_rigid_body_, this->filter_group_, this->filter_mask_);
  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&info.m_collisionShape);
}
