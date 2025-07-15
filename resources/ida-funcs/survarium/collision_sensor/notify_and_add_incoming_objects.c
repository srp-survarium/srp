void __thiscall survarium::collision_sensor::notify_and_add_incoming_objects(
        survarium::collision_sensor *this,
        vostok::buffer_vector<vostok::physics::base_physics_object *> *sensed_objects)
{
  void *v2; // esp
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  survarium::collision_geometry_subscriber **v5; // eax
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *v6; // eax
  survarium::collision_sensor *v7; // [esp+0h] [ebp-58h] BYREF
  const void **i; // [esp+4h] [ebp-54h]
  boost::arg<1> *v9; // [esp+1Ch] [ebp-3Ch]
  boost::arg<1> *v10; // [esp+20h] [ebp-38h]
  survarium::collision_geometry_subscriber **__first; // [esp+24h] [ebp-34h]
  boost::arg<1> *v12; // [esp+28h] [ebp-30h]
  survarium::collision_geometry_subscriber **__last; // [esp+2Ch] [ebp-2Ch]
  boost::arg<1> *result; // [esp+30h] [ebp-28h]
  survarium::game_camera *v15; // [esp+34h] [ebp-24h]
  survarium::collision_sensor **v16; // [esp+38h] [ebp-20h]
  char v17; // [esp+3Fh] [ebp-19h]
  const void **v18; // [esp+40h] [ebp-18h]
  vostok::buffer_vector<void const *> v19; // [esp+44h] [ebp-14h] BYREF
  vostok::physics::base_physics_object **m_end; // [esp+4Ch] [ebp-Ch]
  boost::arg<1> *m_begin; // [esp+50h] [ebp-8h]
  survarium::collision_geometry_subscriber **__val; // [esp+54h] [ebp-4h]

  v7 = this;
  v2 = alloca(4 * (sensed_objects->m_end - sensed_objects->m_begin));
  v16 = &v7;
  v15 = (survarium::game_camera *)(sensed_objects->m_end - sensed_objects->m_begin);
  v19.m_begin = (const void **)&v7;
  v19.m_end = (const void **)&v7;
  v17 = 0;
  survarium::weapon_user_dead_state::finalize(v15);
  __val = (survarium::collision_geometry_subscriber **)sensed_objects->m_begin;
  m_end = sensed_objects->m_end;
  while ( __val != (survarium::collision_geometry_subscriber **)m_end )
  {
    result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)__val,
                                (int)&v7->m_old_objects);
    __last = (survarium::collision_geometry_subscriber **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    v12 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                             v3,
                             (int)&v7->m_old_objects);
    __first = (survarium::collision_geometry_subscriber **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v12);
    v10 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                             v4,
                             (int)&v7->m_old_objects);
    v9 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v10);
    v5 = stlp_std::find<vostok::physics::base_physics_object * const *,vostok::physics::base_physics_object *>(
           __first,
           __last,
           __val);
    if ( v5 == (survarium::collision_geometry_subscriber **)v9 )
      vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(&v19, (const void **)__val);
    ++__val;
  }
  if ( v19.m_end - v19.m_begin )
    v7->on_enter(v7, (const vostok::buffer_vector<vostok::physics::base_physics_object *> *)&v19);
  m_begin = (boost::arg<1> *)v19.m_begin;
  v18 = v19.m_end;
  while ( m_begin != (boost::arg<1> *)v18 )
  {
    v6 = (stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(m_begin);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::push_back(v6, (int)&v7->m_old_objects);
    m_begin += 4;
  }
  for ( i = v19.m_begin; i != v19.m_end; ++i )
    ;
}
