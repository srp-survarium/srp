void __thiscall vostok::render::game::renderer::draw_scene_impl(
        vostok::render::game::renderer *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *params)
{
  vostok::particle::particle_system_instance_impl *m_object; // eax
  void (__thiscall *v3)(vostok::render::one_way_render_channel *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *, bool); // ecx
  vostok::render::game::renderer *v4; // esi
  boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > *v5; // ecx
  boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > *v6; // ecx
  boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > *v7; // ecx
  vostok::math::float4x4 *v8; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  boost::detail::function::basic_vtable1<void,bool> *v10; // [esp-10h] [ebp-70h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > v11; // [esp-Ch] [ebp-6Ch] BYREF
  vostok::render::game::renderer *v12; // [esp+Ch] [ebp-54h]
  void (__thiscall *v13)(vostok::render::one_way_render_channel *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *, bool); // [esp+10h] [ebp-50h]
  boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > v14; // [esp+14h] [ebp-4Ch] BYREF
  void (__thiscall *f)(vostok::render::one_way_render_channel *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *, bool); // [esp+20h] [ebp-40h]
  boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > __that; // [esp+24h] [ebp-3Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > result; // [esp+30h] [ebp-30h] BYREF
  boost::function<void __cdecl(bool)> on_draw_scene; // [esp+40h] [ebp-20h] BYREF

  m_object = params[2].m_object;
  v12 = this;
  if ( m_object )
  {
    v11.l_.a2_.t_.m_object = (vostok::render::base_scene *)(unsigned __int8)1_2;
    v11.l_.a1_.t_ = (vostok::render::one_way_render_channel *)this;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11.l_,
      params + 1);
    v11.f_.f_ = v3;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v11,
      params);
    v4 = v12;
    boost::bind<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool,vostok::render::one_way_render_channel *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,boost::arg<1>>(
      &result,
      *(void (__thiscall **)(vostok::render::one_way_render_channel *, const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *, const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *, bool))((char *)&dword_200050 + (_DWORD)v12),
      (vostok::render::one_way_render_channel *)v11.f_.f_,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v11.l_.a1_.t_);
    f = result.f_.f_;
    boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>(
      v5,
      &__that,
      (int)&result.l_);
    on_draw_scene.vtable = 0;
    v13 = f;
    boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>(
      v6,
      &v14,
      (int)&__that);
    v10 = (boost::detail::function::basic_vtable1<void,bool> *)v13;
    boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>(
      &v14,
      (const boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > *)&v11,
      (int)&v14);
    on_draw_scene.vtable = boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>>>(
                             &on_draw_scene.functor,
                             v7,
                             v10,
                             v11) != 0
                         ? (boost::detail::function::vtable_base *)&`boost::function1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::arg<1>>>>'::`2'::stored_vtable
                         : 0;
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14.a3_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v14.a2_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.a3_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that.a2_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a3_);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result.l_.a2_);
    vostok::render::engine::world::draw_scene(
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)params,
      v8,
      *(vostok::render::engine::world **)((char *)&dword_200054 + (_DWORD)v4),
      (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)&params[1],
      (const vostok::resources::resource_ptr<vostok::render::base_output_window,vostok::resources::unmanaged_intrusive_base> *)&params[2],
      (const vostok::math::rectangle<vostok::math::float2> *)&params[3],
      &on_draw_scene,
      (const vostok::ui::font *)params[7].m_object);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v9,
      (int *)&on_draw_scene);
  }
}
