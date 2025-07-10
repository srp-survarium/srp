void __thiscall vostok::resources::game_resources_manager::~game_resources_manager(
        vostok::resources::game_resources_manager *this,
        vostok::resources::releasing_functionality releasing)
{
  char *v2; // esi
  int v3; // eax
  void (__cdecl *v4)(char *, char *, int); // eax

  vostok::resources::releasing_functionality::release_all_resources((vostok::resources::releasing_functionality *)this);
  v2 = (char *)&loc_20600 + (unsigned int)vostok::resources::g_resources_manager.m_variable;
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&byte_20168[(_DWORD)&loc_20600 + (unsigned int)vostok::resources::g_resources_manager.m_variable]);
  v3 = *(int *)((char *)&dword_201A8 + (_DWORD)v2);
  if ( v3 )
  {
    if ( (v3 & 1) == 0 )
    {
      v4 = *(void (__cdecl **)(char *, char *, int))(v3 & 0xFFFFFFFE);
      if ( v4 )
        v4((char *)&loc_201B0 + (_DWORD)v2, (char *)&loc_201B0 + (_DWORD)v2, 2);
    }
    *(int *)((char *)&dword_201A8 + (_DWORD)v2) = 0;
  }
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v2[(_DWORD)&loc_20186 + 2]);
  boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::clear_and_dispose<boost::intrusive::detail::node_disposer<boost::intrusive::detail::null_disposer,boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0>>>>((boost::intrusive::rbtree_node<void *> *)&releasing.m_data[1].memory_types.m_last);
  releasing.m_data[1].memory_types.m_last = 0;
  *((_DWORD *)&releasing.m_data[1].memory_types.m_last + 1) = (char *)releasing.m_data + 152;
  releasing.m_data[1].increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_ = (boost::intrusive::rbtree_node<void *> *)&releasing.m_data[1].memory_types.m_last;
  releasing.m_data[1].increase_quality_tree.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_ = 0;
  DeleteCriticalSection((LPCRITICAL_SECTION)&releasing.m_data[1].memory_types);
  DeleteCriticalSection((LPCRITICAL_SECTION)&releasing.m_data->increase_quality_tree);
  DeleteCriticalSection((LPCRITICAL_SECTION)&releasing.m_data->memory_types);
}
