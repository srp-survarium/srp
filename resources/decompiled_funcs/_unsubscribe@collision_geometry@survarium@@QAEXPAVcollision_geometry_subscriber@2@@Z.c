void __thiscall survarium::collision_geometry::unsubscribe(
        survarium::collision_geometry *this,
        survarium::collision_geometry_subscriber *subscriber)
{
  survarium::collision_geometry_subscriber **v2; // eax
  survarium::collision_geometry_subscriber **__first; // [esp+24h] [ebp-14h]
  boost::arg<1> *v5; // [esp+28h] [ebp-10h]
  survarium::collision_geometry_subscriber **__last; // [esp+2Ch] [ebp-Ch]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  __last = (survarium::collision_geometry_subscriber **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref((boost::arg<1> *)this->m_subscribers._M_impl._M_finish);
  v5 = (boost::arg<1> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_subscribers);
  __first = (survarium::collision_geometry_subscriber **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v5);
  v2 = stlp_std::find<vostok::physics::base_physics_object * const *,vostok::physics::base_physics_object *>(
         __first,
         __last,
         &subscriber);
  stlp_std::vector<survarium::collision_geometry_subscriber *,stlp_std::allocator<survarium::collision_geometry_subscriber *>>::erase(
    &this->m_subscribers,
    v2);
  if ( this->m_subscribers._M_impl._M_start == this->m_subscribers._M_impl._M_finish )
    survarium::collision_geometry::remove(this);
}
