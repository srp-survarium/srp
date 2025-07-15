void __thiscall survarium::collision_geometry::subscribe(
        survarium::collision_geometry *this,
        vostok::physics::world *world,
        survarium::collision_geometry_subscriber *subscriber)
{
  void *const *v3; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_subscribers._M_impl._M_start == this->m_subscribers._M_impl._M_finish )
    survarium::collision_geometry::insert(this, world);
  v3 = (void *const *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref((boost::arg<1> *)&subscriber);
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::push_back(&this->m_subscribers._M_impl, v3);
}
