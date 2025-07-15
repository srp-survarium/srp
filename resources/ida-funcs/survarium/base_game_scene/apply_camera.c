void __userpurge survarium::base_game_scene::apply_camera(
        survarium::camera_director *cd@<eax>,
        survarium::base_game_scene *this)
{
  vostok::math::float4x4 *p_m_projection; // esi
  survarium::game *m_game; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > *v4; // edi
  vostok::math::float4x4 *v5; // eax
  vostok::render::scene_renderer *v6; // ecx
  vostok::render::scene_renderer *v7; // ecx
  vostok::math::float4x4 v8; // [esp+10h] [ebp-44h] BYREF

  qmemcpy(&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
  p_m_projection = &cd->m_projection;
  m_game = this->m_game;
  qmemcpy(&this->m_projection_matrix, p_m_projection, sizeof(this->m_projection_matrix));
  v4 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + (unsigned int)m_game->m_renderer);
  v5 = vostok::math::invert4x3(&this->m_inverted_view_matrix, &v8);
  vostok::render::scene_renderer::set_view_matrix(
    v6,
    v4,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene_view,
    v5);
  vostok::render::scene_renderer::set_projection_matrix(
    v7,
    *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> const &,vostok::math::float4x4 const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + (unsigned int)this->m_game->m_renderer),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene_view,
    &this->m_projection_matrix);
}
