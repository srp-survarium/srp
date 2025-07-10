void __thiscall survarium::collision_sensor::notify_and_erase_left_objects(
        survarium::collision_sensor *this,
        stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *sensed_objects)
{
  void *v2; // esp
  survarium::game_camera *v3; // ecx
  vostok::physics::base_physics_object **v4; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  _DWORD v7[2]; // [esp+0h] [ebp-94h] BYREF
  survarium::collision_sensor *thisa; // [esp+8h] [ebp-8Ch]
  vostok::physics::base_physics_object **i; // [esp+Ch] [ebp-88h]
  boost::arg<1> *v10; // [esp+10h] [ebp-84h]
  boost::arg<1> *v11; // [esp+14h] [ebp-80h]
  void **v12; // [esp+30h] [ebp-64h]
  void **v13; // [esp+34h] [ebp-60h]
  vostok::physics::base_physics_object **__first; // [esp+5Ch] [ebp-38h]
  boost::arg<1> *v15; // [esp+60h] [ebp-34h]
  vostok::physics::base_physics_object **__last; // [esp+64h] [ebp-30h]
  boost::arg<1> *v17; // [esp+68h] [ebp-2Ch]
  boost::arg<1> *v18; // [esp+6Ch] [ebp-28h]
  boost::arg<1> *result; // [esp+70h] [ebp-24h]
  vostok::physics::base_physics_object **v20; // [esp+74h] [ebp-20h]
  char v21; // [esp+7Bh] [ebp-19h]
  int v22; // [esp+7Ch] [ebp-18h]
  int v23; // [esp+80h] [ebp-14h]
  survarium::left_objects_predicate __pred; // [esp+84h] [ebp-10h]
  vostok::buffer_vector<vostok::physics::base_physics_object *> objects_to_delete; // [esp+8Ch] [ebp-8h] BYREF

  thisa = this;
  v2 = alloca(4 * stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&this->m_old_objects._M_impl));
  v7[1] = v7;
  v23 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl);
  v22 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl);
  survarium::weapon_user_dead_state::finalize(v3);
  v20 = v4;
  objects_to_delete.m_begin = v4;
  objects_to_delete.m_end = v4;
  v21 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v4);
  result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                              v5,
                              (int)&thisa->m_old_objects);
  v18 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
  __pred = (survarium::left_objects_predicate)__PAIR64__(&objects_to_delete, (unsigned int)sensed_objects);
  v17 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                           sensed_objects,
                           (int)&thisa->m_old_objects);
  __last = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v17);
  v15 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                           v6,
                           (int)&thisa->m_old_objects);
  __first = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v15);
  v10 = (boost::arg<1> *)stlp_std::remove_if<vostok::physics::base_physics_object * *,survarium::left_objects_predicate>(
                           __first,
                           __last,
                           __pred);
  v13 = (void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v18);
  v12 = (void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v10);
  v11 = (boost::arg<1> *)stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
                           v12,
                           v13,
                           &thisa->m_old_objects._M_impl);
  stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v11);
  if ( objects_to_delete.m_begin != objects_to_delete.m_end )
    thisa->on_leave(thisa, &objects_to_delete);
  for ( i = objects_to_delete.m_begin; i != objects_to_delete.m_end; ++i )
    ;
}
