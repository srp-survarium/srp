void __thiscall survarium::base_game_scene::~base_game_scene(survarium::base_game_scene *this)
{
  int f; // esi
  survarium::base_game_scene *v2; // edi
  _BYTE *v3; // eax
  vostok::resources::unmanaged_resource *m_object; // eax

  f = (int)survarium::g_allocator.f_.f_;
  v2 = this;
  this->survarium::game_scene::__vftable = (survarium::base_game_scene_vtbl *)&survarium::base_game_scene::`vftable'{for `survarium::game_scene'};
  this->survarium::engine::__vftable = (survarium::engine_vtbl *)&survarium::base_game_scene::`vftable'{for `survarium::engine'};
  if ( this->m_camera_director )
  {
    v3 = __RTCastToVoid((void **)&this->m_camera_director->__vftable);
    if ( v3 )
    {
      *(_BYTE *)(f + 42) = 0;
      vostok_mspace_free(*(void **)(f + 20), v3);
    }
    v2->m_camera_director = 0;
  }
  m_object = v2->m_sound_scene.m_object;
  if ( m_object )
  {
    this = (survarium::base_game_scene *)_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF);
    if ( !this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v2->m_sound_scene.m_object->vostok::resources::unmanaged_intrusive_base,
        v2->m_sound_scene.m_object);
  }
  boost::_bi::storage3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>>::~storage3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::tracer_model_instance,vostok::resources::unmanaged_intrusive_base>>>(
    this,
    (int)v2);
}
