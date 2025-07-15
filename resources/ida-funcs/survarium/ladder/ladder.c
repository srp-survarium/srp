void __thiscall survarium::ladder::ladder(
        survarium::ladder *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *main_animation,
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *p,
        vostok::resources::managed_resource **a4)
{
  survarium::usable_object *v4; // ecx
  _DWORD *v5; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(this, main_animation, fs_iterator_class);
  survarium::usable_object::usable_object(v4, (int)&main_animation[66], 1);
  *v5 = &survarium::ladder::`vftable'{for `survarium::collision_geometry_subscriber'};
  main_animation->m_object = (vostok::resources::managed_resource *)&survarium::ladder::`vftable';
  main_animation[67].m_object = (vostok::resources::managed_resource *)&survarium::ladder::`vftable'{for `survarium::link_resolver'};
  main_animation[83].m_object = 0;
  main_animation[85].m_object = 0;
  main_animation[86].m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    main_animation + 87,
    p);
  main_animation[88].m_object = *a4;
  main_animation[89].m_object = a4[1];
  main_animation[90].m_object = a4[2];
  main_animation[91].m_object = a4[3];
  main_animation[92].m_object = 0;
}
