void __thiscall survarium::collision_sensor::remove(survarium::collision_sensor *this)
{
  void **M_start; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  void *v4; // esp
  survarium::game_camera *v5; // ecx
  vostok::physics::base_physics_object **v6; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v7; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  vostok::physics::base_physics_object **v9; // eax
  stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *> > *v10; // ecx
  _DWORD v11[3]; // [esp+0h] [ebp-A8h] BYREF
  survarium::collision_sensor *thisa; // [esp+Ch] [ebp-9Ch]
  vostok::physics::base_physics_object **j; // [esp+10h] [ebp-98h]
  boost::arg<1> *v14; // [esp+40h] [ebp-68h]
  boost::arg<1> *v15; // [esp+44h] [ebp-64h]
  vostok::physics::base_physics_object **v16; // [esp+48h] [ebp-60h]
  char v17; // [esp+4Fh] [ebp-59h]
  int v18; // [esp+50h] [ebp-58h]
  int v19; // [esp+54h] [ebp-54h]
  boost::arg<1> *v20; // [esp+58h] [ebp-50h]
  boost::arg<1> *v21; // [esp+5Ch] [ebp-4Ch]
  void **v22; // [esp+64h] [ebp-44h]
  void **v23; // [esp+68h] [ebp-40h]
  vostok::physics::base_physics_object **__first; // [esp+78h] [ebp-30h]
  boost::arg<1> *v25; // [esp+7Ch] [ebp-2Ch]
  vostok::physics::base_physics_object **__last; // [esp+80h] [ebp-28h]
  boost::arg<1> *v27; // [esp+84h] [ebp-24h]
  boost::arg<1> *v28; // [esp+88h] [ebp-20h]
  boost::arg<1> *result; // [esp+8Ch] [ebp-1Ch]
  survarium::vector<vostok::physics::base_physics_object *> *p_m_old_objects; // [esp+90h] [ebp-18h]
  vostok::physics::base_physics_object **end; // [esp+94h] [ebp-14h] BYREF
  char v32; // [esp+9Bh] [ebp-Dh]
  unsigned int i; // [esp+9Ch] [ebp-Ch]
  vostok::buffer_vector<vostok::physics::base_physics_object *> leaved; // [esp+A0h] [ebp-8h] BYREF

  thisa = this;
  v32 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  thisa->m_is_active = 0;
  for ( i = 0; i < thisa->m_collision_geometries_count; ++i )
    survarium::collision_geometry::unsubscribe(thisa->m_collision_geometries[i], thisa);
  p_m_old_objects = &thisa->m_old_objects;
  M_start = thisa->m_old_objects._M_impl._M_start;
  if ( M_start != thisa->m_old_objects._M_impl._M_finish )
  {
    result = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                                (stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *)(M_start == thisa->m_old_objects._M_impl._M_finish),
                                (int)&thisa->m_old_objects);
    v28 = stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(result);
    v27 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                             v2,
                             (int)&thisa->m_old_objects);
    __last = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v27);
    v25 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                             v3,
                             (int)&thisa->m_old_objects);
    __first = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v25);
    v20 = (boost::arg<1> *)stlp_std::remove_if<vostok::physics::base_physics_object * *,bool (__cdecl *)(vostok::physics::base_physics_object *)>(
                             __first,
                             __last,
                             (bool (__cdecl *)(vostok::physics::base_physics_object *))survarium::remove_loosed_ptrs_predicate);
    v23 = (void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v28);
    v22 = (void **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v20);
    v21 = (boost::arg<1> *)stlp_std::vector<vostok::render::render_surface_instance *,vostok::render::std_allocator<vostok::render::render_surface_instance *>>::erase(
                             v22,
                             v23,
                             &thisa->m_old_objects._M_impl);
    stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v21);
    v4 = alloca(
           4
         * stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl));
    v11[2] = v11;
    v19 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl);
    v18 = stlp_std::priv::_Impl_vector<void *,vostok::vectora_allocator<void *>>::size(&thisa->m_old_objects._M_impl);
    survarium::weapon_user_dead_state::finalize(v5);
    v16 = v6;
    leaved.m_begin = v6;
    leaved.m_end = v6;
    v17 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v6);
    v15 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
                             v7,
                             (int)&thisa->m_old_objects);
    end = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v15);
    v14 = (boost::arg<1> *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                             v8,
                             (int)&thisa->m_old_objects);
    v9 = (vostok::physics::base_physics_object **)stlp_std::priv::_VoidCastTraitsAux<void *,void *>::cv_ref(v14);
    vostok::buffer_vector<vostok::physics::base_physics_object *>::assign<vostok::physics::base_physics_object * *>(
      &leaved,
      v9,
      &end);
    thisa->on_leave(thisa, &leaved);
    stlp_std::priv::_Impl_vector<void *,survarium::std_allocator<void *>>::clear(
      v10,
      &thisa->m_old_objects._M_impl._M_start);
    for ( j = leaved.m_begin; j != leaved.m_end; ++j )
      ;
  }
}
