void __thiscall survarium::grenade::throw_grenade(
        survarium::grenade *this,
        const vostok::math::float4x4 *transform,
        const vostok::math::float3 *force)
{
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::grenade,vostok::physics::contact_point const &>,boost::_bi::list2<boost::_bi::value<survarium::grenade *>,boost::arg<1> > > v4; // [esp-20h] [ebp-44h]
  _DWORD v5[8]; // [esp+4h] [ebp-20h] BYREF

  v5[7] = 0;
  *(float *)&v5[1] = float_min_18;
  *(float *)&v5[2] = float_min_18;
  *(float *)&v5[3] = float_min_18;
  LOWORD(v5[0]) = -1;
  v5[4] = 0;
  *(float *)&v5[5] = s_bm_current_air_resistance;
  v5[6] = 0;
  qmemcpy(&this->m_last_contact, v5, sizeof(this->m_last_contact));
  survarium::grenade_core::throw_grenade(this, transform, force);
  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
    *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_world->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_world->m_render_scene,
    transform,
    transform);
  v5[0] =  __thiscall survarium::grenade::`vcall'{32,{flat}};
  v5[1] = 0;
  v5[2] = this;
  HIDWORD(v4.f_.f_) =  __thiscall survarium::grenade::`vcall'{32,{flat}};
  *(_QWORD *)&v4.l_.a1_.t_ = __PAIR64__((unsigned int)this, 0);
  LODWORD(v4.f_.f_) = &this->m_collide_callback;
  boost::function<void __cdecl (vostok::physics::contact_point const &)>::operator=<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::grenade,vostok::physics::contact_point const &>,boost::_bi::list2<boost::_bi::value<survarium::grenade *>,boost::arg<1>>>>(
    0,
    v4,
    v5[3]);
  this->m_physics_world->subscribe_on_contact(this->m_physics_world, this->m_rigid_body, &this->m_collide_callback);
}
