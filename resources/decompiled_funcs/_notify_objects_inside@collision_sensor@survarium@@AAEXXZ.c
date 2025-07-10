void __thiscall survarium::collision_sensor::notify_objects_inside(survarium::collision_sensor *this)
{
  void *v1; // esp
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  vostok::physics::base_physics_object **v4; // eax
  survarium::collision_sensor *v5; // [esp+0h] [ebp-38h] BYREF
  vostok::physics::base_physics_object **i; // [esp+4h] [ebp-34h]
  boost::arg<1> *v7; // [esp+18h] [ebp-20h]
  boost::arg<1> *result; // [esp+1Ch] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-18h]
  vostok::physics::base_physics_object **v10; // [esp+24h] [ebp-14h]
  char v11; // [esp+2Bh] [ebp-Dh]
  vostok::physics::base_physics_object **end; // [esp+2Ch] [ebp-Ch] BYREF
  vostok::buffer_vector<vostok::physics::base_physics_object *> v13; // [esp+30h] [ebp-8h] BYREF

  v5 = this;
  v1 = alloca(4 * stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_old_objects._M_impl));
  v10 = (vostok::physics::base_physics_object **)&v5;
  v9 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&v5->m_old_objects._M_impl);
  v13.m_begin = v10;
  v13.m_end = v10;
  v11 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v10);
  result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                              v2,
                              (int)&v5->m_old_objects);
  end = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
  v7 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                          v3,
                          (int)&v5->m_old_objects);
  v4 = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v7);
  vostok::buffer_vector<vostok::physics::base_physics_object *>::assign<vostok::physics::base_physics_object * *>(
    &v13,
    v4,
    &end);
  v5->on_inside(v5, &v13);
  for ( i = v13.m_begin; i != v13.m_end; ++i )
    ;
}
