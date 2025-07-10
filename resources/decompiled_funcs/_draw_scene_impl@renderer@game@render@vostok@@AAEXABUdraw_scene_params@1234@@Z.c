void __thiscall vostok::render::game::renderer::draw_scene_impl(
        vostok::render::game::renderer *this,
        const vostok::render::game::renderer::draw_scene_params *params)
{
  vostok::render::base_output_window *m_object; // eax
  vostok::render::base_scene_view *v3; // eax
  boost::function<void __cdecl(bool)> *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  vostok::render::base_scene *v6; // [esp-1Ch] [ebp-4Ch]
  vostok::render::base_scene_view *v7; // [esp-18h] [ebp-48h]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> v8; // [esp-14h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool>,boost::_bi::list4<boost::_bi::value<vostok::render::one_way_render_channel *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > v9; // [esp-10h] [ebp-40h] BYREF
  int v10; // [esp+0h] [ebp-30h]
  vostok::render::game::renderer *v11; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(bool)> on_draw_scene; // [esp+10h] [ebp-20h] BYREF

  m_object = params->render_output_window.m_object;
  v11 = this;
  if ( m_object )
  {
    v8.m_object = (vostok::render::base_scene *)(unsigned __int8)1_18;
    v7 = 0;
    v3 = params->scene_view.m_object;
    if ( v3 )
    {
      v7 = params->scene_view.m_object;
      _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
    }
    v6 = 0;
    if ( params->scene.m_object )
    {
      v6 = params->scene.m_object;
      _InterlockedExchangeAdd(&params->scene.m_object->m_reference_count, 1u);
    }
    boost::bind<void,vostok::render::one_way_render_channel,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,bool,vostok::render::one_way_render_channel *,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,boost::arg<1>>(
      (int)&v9,
      &this->m_world->m_logic_channel,
      v6,
      v7,
      v8);
    boost::function<void __cdecl (bool)>::function<void __cdecl (bool)>(v4, &on_draw_scene, v9, v10);
    vostok::render::engine::world::draw_scene(
      &params->scene,
      (vostok::render::scene *)&on_draw_scene,
      v11->m_render_engine_world,
      &params->scene_view,
      (vostok::render::renderer *)&params->render_output_window,
      (vostok::configs::binary_config *)&params->viewport,
      params->default_font);
    if ( on_draw_scene.vtable && ((int)on_draw_scene.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)on_draw_scene.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&on_draw_scene.functor, &on_draw_scene.functor, 2);
    }
  }
}
