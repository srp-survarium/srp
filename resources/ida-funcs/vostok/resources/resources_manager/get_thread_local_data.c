vostok::resources::thread_local_data *__thiscall vostok::resources::resources_manager::get_thread_local_data(
        vostok::resources::resources_manager *this,
        vostok::resources::resources_manager *thread_id,
        unsigned int create_if_not_exist,
        bool create_if_not_exista)
{
  vostok::resources::thread_local_data *p_color; // ebx
  vostok::threading::reader_writer_lock *v5; // ecx
  const char *Value; // edi
  vostok::fixed_string<32> *p_thread_name; // esi
  char *m_begin; // eax
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *left; // eax
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *v11; // edi
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *v12; // ecx
  unsigned int v13; // esi
  void *v14; // eax
  vostok::resources::thread_local_data *v15; // ecx
  vostok::resources::thread_local_data *v16; // eax
  _DWORD *v17; // eax
  vostok::resources::thread_local_data *v18; // ecx
  vostok::resources::thread_local_data *v19; // eax
  vostok::threading::reader_writer_lock *v20; // ecx
  bool v21; // [esp+0h] [ebp-28h]
  char v22[8]; // [esp+14h] [ebp-14h] BYREF
  vostok::threading::reader_writer_lock::mutex_raii raii; // [esp+1Ch] [ebp-Ch] BYREF

  p_color = 0;
  if ( GetCurrentThreadId() != create_if_not_exist
    || (p_color = (vostok::resources::thread_local_data *)TlsGetValue(*(int *)((char *)&dword_203C8 + (_DWORD)thread_id))) == 0 )
  {
    if ( create_if_not_exista )
      vostok::threading::reader_writer_lock::lock_write_impl(v5, v21);
    else
      vostok::threading::reader_writer_lock::lock_read_impl(v5, v21);
    left = *(boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > **)((char *)&dword_203B8 + (_DWORD)thread_id);
    v11 = (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *)((char *)&dword_203B8 + (_DWORD)thread_id);
    v12 = (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *)((char *)&dword_203B8 + (_DWORD)thread_id);
    if ( left )
    {
      do
      {
        v13 = create_if_not_exist;
        if ( left[-1].data_.node_plus_pred_.header_plus_size_.header_.color_ >= create_if_not_exist )
        {
          v12 = left;
          left = (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *)left->data_.node_plus_pred_.header_plus_size_.header_.left_;
        }
        else
        {
          left = (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *)left->data_.node_plus_pred_.header_plus_size_.header_.right_;
        }
      }
      while ( left );
      if ( v12 != v11 && create_if_not_exist >= v12[-1].data_.node_plus_pred_.header_plus_size_.header_.color_ )
      {
LABEL_23:
        if ( v12 != v11 )
        {
          p_color = (vostok::resources::thread_local_data *)&v12[-39].data_.node_plus_pred_.header_plus_size_.header_.color_;
          goto LABEL_33;
        }
        if ( !create_if_not_exista )
        {
LABEL_33:
          if ( GetCurrentThreadId() == v13 && p_color )
            TlsSetValue(*(int *)((char *)&dword_203C8 + (_DWORD)thread_id), p_color);
          if ( !create_if_not_exista )
          {
            vostok::threading::reader_writer_lock::unlock_read(v20);
            return p_color;
          }
          vostok::threading::reader_writer_lock::unlock_write(v20);
          return p_color;
        }
        if ( GetCurrentThreadId() == *(int *)((char *)&dword_203CC + (_DWORD)thread_id) )
        {
          v14 = vostok::memory::doug_lea_allocator::malloc_impl(&vostok::memory::g_resources_helper_allocator, 0x278u);
          if ( v14 )
          {
            vostok::resources::thread_local_data::thread_local_data(
              v15,
              (int)v14,
              v13,
              &vostok::memory::g_resources_helper_allocator);
            p_color = v16;
LABEL_32:
            boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0>>::insert_unique(
              p_color,
              (int)v22,
              v11);
            v13 = create_if_not_exist;
            goto LABEL_33;
          }
        }
        else
        {
          v17 = pt3malloc((char *)0x278);
          if ( v17 )
          {
            vostok::resources::thread_local_data::thread_local_data(v18, (int)v17, v13, &vostok::memory::g_mt_allocator);
            p_color = v19;
            goto LABEL_32;
          }
        }
        p_color = 0;
        goto LABEL_32;
      }
    }
    else
    {
      v13 = create_if_not_exist;
    }
    v12 = (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::resources::thread_local_data,boost::intrusive::set_member_hook<boost::intrusive::link_mode<2>,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,612>,vostok::resources::thread_local_data_compare,unsigned int,0> > *)((char *)&dword_203B8 + (_DWORD)thread_id);
    goto LABEL_23;
  }
  Value = (const char *)TlsGetValue(s_thread_logging_name_tls_key);
  if ( !Value )
    Value = "undefined";
  p_thread_name = &p_color->thread_name;
  if ( p_color->thread_name.m_end != p_color->thread_name.m_begin || !strlen(Value) )
    return p_color;
  vostok::threading::reader_writer_lock::mutex_raii::mutex_raii(
    &raii,
    (const vostok::threading::reader_writer_lock *)((char *)boost::detail::function::functor_manager_common<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>>>::manage_small
                                                  + (_DWORD)thread_id),
    (vostok::threading::reader_writer_lock *)2);
  m_begin = p_thread_name->m_begin;
  if ( p_thread_name->m_begin != Value )
  {
    p_color->thread_name.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&p_color->thread_name, Value);
  }
  vostok::threading::reader_writer_lock::mutex_raii::~mutex_raii(&raii);
  return p_color;
}
