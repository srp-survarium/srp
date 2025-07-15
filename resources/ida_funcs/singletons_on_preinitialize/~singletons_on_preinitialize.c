void __usercall singletons_on_preinitialize::~singletons_on_preinitialize(
        singletons_on_preinitialize *this@<ecx>,
        int a2@<edi>)
{
  vostok::render::effect_manager *v2; // ecx
  void *v3; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::scene_manager *v5; // ecx
  vostok::render::device *v6; // ecx
  vostok::render::resource_manager *v7; // ecx

  vostok::render::effect_constant_storage::clear((vostok::render::effect_constant_storage *)this);
  v3 = *(void **)((char *)stlp_std::swap<vostok::size_policy> + a2);
  if ( v3 )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v3);
  }
  vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst = 0;
  vostok::render::effect_manager::~effect_manager(v2);
  *(_DWORD *)(a2 + 3920) = *(_DWORD *)(a2 + 3916);
  vostok::buffer_vector<char const *>::~buffer_vector<char const *>((vostok::buffer_vector<void const *> *)(a2 + 3396));
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[2] = 0;
  vostok::render::scene_manager::~scene_manager(v5);
  vostok::render::backend::~backend((vostok::render::backend *)(a2 + 1060));
  vostok::render::device::destroy(v6);
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game = 0;
  vostok::render::resource_manager::~resource_manager(v7);
}
