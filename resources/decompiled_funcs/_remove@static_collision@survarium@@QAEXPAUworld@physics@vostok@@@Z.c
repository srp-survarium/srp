void __thiscall survarium::static_collision::remove(survarium::static_collision *this, vostok::physics::world *w)
{
  w->remove(w, this->physics_rigid_body_);
  vostok::physics::destroy_static_rigid_body(this->physics_rigid_body_);
  this->physics_rigid_body_ = 0;
}
