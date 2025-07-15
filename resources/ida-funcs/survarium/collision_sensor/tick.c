void __thiscall survarium::collision_sensor::tick(
        survarium::collision_sensor *this,
        unsigned int time_delta_ms,
        survarium::game_camera *current_time_ms)
{
  _BYTE *v3; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v4; // ecx
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v5; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  survarium::game_camera *v7; // ecx
  void *v8; // esp
  void *v9; // esp
  survarium::game_camera *v10; // ecx
  unsigned __int8 v11; // al
  int v12; // [esp+0h] [ebp-A8h] BYREF
  survarium::collision_sensor *thisa; // [esp+4h] [ebp-A4h]
  vostok::physics::base_physics_object **n; // [esp+8h] [ebp-A0h]
  vostok::physics::base_physics_object **m; // [esp+Ch] [ebp-9Ch]
  char v16; // [esp+1Bh] [ebp-8Dh]
  vostok::physics::base_physics_object **v17; // [esp+1Ch] [ebp-8Ch]
  char v18; // [esp+23h] [ebp-85h]
  int *v19; // [esp+24h] [ebp-84h]
  char v20; // [esp+2Bh] [ebp-7Dh]
  int *v21; // [esp+2Ch] [ebp-7Ch]
  char v22; // [esp+33h] [ebp-75h]
  int ii; // [esp+34h] [ebp-74h]
  char v24; // [esp+3Bh] [ebp-6Dh]
  boost::arg<1> *v25; // [esp+3Ch] [ebp-6Ch]
  boost::arg<1> *v26; // [esp+40h] [ebp-68h]
  void **v27; // [esp+48h] [ebp-60h]
  void **v28; // [esp+4Ch] [ebp-5Ch]
  vostok::physics::base_physics_object **__first; // [esp+5Ch] [ebp-4Ch]
  boost::arg<1> *v30; // [esp+60h] [ebp-48h]
  vostok::physics::base_physics_object **__last; // [esp+64h] [ebp-44h]
  boost::arg<1> *v32; // [esp+68h] [ebp-40h]
  boost::arg<1> *v33; // [esp+6Ch] [ebp-3Ch]
  boost::arg<1> *result; // [esp+70h] [ebp-38h]
  char v35; // [esp+77h] [ebp-31h]
  unsigned int k; // [esp+78h] [ebp-30h]
  unsigned int j; // [esp+7Ch] [ebp-2Ch]
  int v38; // [esp+80h] [ebp-28h] BYREF
  int v39; // [esp+84h] [ebp-24h]
  unsigned int i; // [esp+88h] [ebp-20h]
  unsigned int old_objects_count; // [esp+8Ch] [ebp-1Ch]
  unsigned int objects_count; // [esp+90h] [ebp-18h]
  unsigned int all_sensed_objects_count; // [esp+94h] [ebp-14h]
  vostok::buffer_vector<vostok::physics::base_physics_object *> sensed_objects; // [esp+98h] [ebp-10h] BYREF
  vostok::buffer_vector<vostok::physics::base_physics_object *> all_sensed_objects; // [esp+A0h] [ebp-8h] BYREF

  thisa = this;
  v35 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(current_time_ms);
  old_objects_count = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl);
  result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                              v4,
                              (int)&thisa->m_old_objects);
  v33 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
  v32 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                           v5,
                           (int)&thisa->m_old_objects);
  __last = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v32);
  v30 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                           v6,
                           (int)&thisa->m_old_objects);
  __first = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v30);
  v25 = (boost::arg<1> *)stlp_std::remove_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
                           __first,
                           __last,
                           (bool (__cdecl *)(vostok::physics::base_physics_object *))survarium::remove_loosed_ptrs_predicate);
  v28 = (void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v33);
  v27 = (void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v25);
  v26 = (boost::arg<1> *)stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
                           v27,
                           v28,
                           &thisa->m_old_objects._M_impl);
  stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v26);
  if ( old_objects_count != stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl) )
    thisa->on_objetcs_loosed(thisa, &thisa->m_old_objects);
  objects_count = 0;
  for ( i = 0; i < thisa->m_collision_geometries_count; ++i )
  {
    objects_count += survarium::collision_geometry::get_overlapping_objects_count(thisa->m_collision_geometries[i]);
    v7 = (survarium::game_camera *)(i + 1);
  }
  if ( objects_count )
  {
    v8 = alloca(4 * objects_count);
    v21 = &v12;
    all_sensed_objects.m_begin = (vostok::physics::base_physics_object **)&v12;
    all_sensed_objects.m_end = (vostok::physics::base_physics_object **)&v12;
    v22 = 0;
    survarium::weapon_user_dead_state::finalize(v7);
    for ( j = 0; j < thisa->m_collision_geometries_count; ++j )
      survarium::collision_geometry::get_overlapping_objects(thisa->m_collision_geometries[j], &all_sensed_objects);
    survarium::collision_sensor::filter_sensed_objects(thisa, &all_sensed_objects);
    all_sensed_objects_count = all_sensed_objects.m_end - all_sensed_objects.m_begin;
    v9 = alloca(4 * objects_count);
    v19 = &v12;
    sensed_objects.m_begin = (vostok::physics::base_physics_object **)&v12;
    sensed_objects.m_end = (vostok::physics::base_physics_object **)&v12;
    v20 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)all_sensed_objects_count);
    for ( k = 0; k < all_sensed_objects_count; ++k )
    {
      v18 = 0;
      survarium::weapon_user_dead_state::finalize(v10);
      v17 = &all_sensed_objects.m_begin[k];
      v11 = survarium::collision_sensor::contact_test(thisa, *v17);
      v10 = (survarium::game_camera *)v11;
      if ( v11 )
      {
        v16 = 0;
        survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v11);
        vostok::buffer_vector<enum vostok::logging::format_specifier_enum>::push_back(
          (vostok::buffer_vector<void const *> *)&sensed_objects,
          (const void **)&all_sensed_objects.m_begin[k]);
      }
    }
    survarium::collision_sensor::notify_and_erase_left_objects(
      thisa,
      (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)&sensed_objects);
    survarium::collision_sensor::notify_objects_inside(thisa);
    survarium::collision_sensor::notify_and_add_incoming_objects(thisa, &sensed_objects);
    for ( m = sensed_objects.m_begin; m != sensed_objects.m_end; ++m )
      ;
    sensed_objects.m_end = sensed_objects.m_begin;
    for ( n = all_sensed_objects.m_begin; n != all_sensed_objects.m_end; ++n )
      ;
  }
  else
  {
    v38 = 0;
    v39 = 0;
    v24 = 0;
    survarium::weapon_user_dead_state::finalize(0);
    survarium::collision_sensor::notify_and_erase_left_objects(
      thisa,
      (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)&v38);
    for ( ii = v38; ii != v39; ii += 4 )
      ;
    v39 = v38;
  }
}
