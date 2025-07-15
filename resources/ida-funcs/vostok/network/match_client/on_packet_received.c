void __thiscall vostok::network::match_client::on_packet_received(
        vostok::network::match_client *this,
        unsigned __int8 message_type,
        vostok::network_core::buffer_reader *reader)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *size; // ecx
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *matched; // edi
  bool has_passed_filters; // al
  vostok::network_core::buffer_writer *m_pointer; // ecx
  const unsigned __int8 *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *v11; // ecx
  char *v12; // ebx
  vostok::network::match_client_impl *v13; // edx
  __int32 v14; // eax
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **p_m_object; // edi
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy>::node *v16; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v17; // ecx
  unsigned __int8 *v18; // edx
  vostok::network_core::buffer_writer *v19; // ecx
  int v20; // edi
  unsigned int v21; // edi
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *v22; // ecx
  bool v23; // al
  boost::intrusive::rbtree_node<void *> *nodeptr; // esi
  vostok::network::network_world *m_world; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *p_m_channel; // ecx
  bool v27; // zf
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::network::match_client,unsigned char,vostok::network_core::buffer_reader &>,boost::_bi::list3<boost::_bi::value<vostok::network::match_client *>,boost::_bi::value<unsigned char>,boost::arg<1> > > v28; // [esp-10h] [ebp-68h]
  unsigned __int8 *v29; // [esp-8h] [ebp-60h]
  vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> *v30; // [esp-8h] [ebp-60h]
  boost::intrusive::set_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > v31; // [esp-4h] [ebp-5Ch] BYREF
  int v32; // [esp+10h] [ebp-48h]
  vostok::network::match_client *v33; // [esp+14h] [ebp-44h]
  unsigned int v34; // [esp+18h] [ebp-40h]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,0> *v35; // [esp+1Ch] [ebp-3Ch]
  boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,1> i; // [esp+20h] [ebp-38h] BYREF
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > result; // [esp+24h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+38h] [ebp-20h] BYREF

  v33 = this;
  v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ = red_t;
  if ( !this->m_on_packet_received.vtable )
    return;
  matched = vostok::network_core::new_udp_match_packet(this->m_response_packets_allocator.m_object);
  i.members_.nodeptr_ = (boost::intrusive::rbtree_node<void *> *)matched;
  if ( !matched )
  {
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)&initiator_raw.filter_stack,
                                 (const char *)2),
          size = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v31.tree_.data_.node_plus_pred_.header_plus_size_.size_,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        size,
        &f);
      v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ = black_t;
      vostok::logging::append(
        (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&f,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\match_client.cpp",
        0x131u,
        "void __thiscall vostok::network::match_client::on_packet_received(unsigned char,class vostok::network_core::buffer_reader &)",
        &initiator_raw.filter_stack.gap0,
        error,
        "skipping packet because we are out of response packets");
    }
    if ( (v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ & 1) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)size,
        (int *)&f);
    return;
  }
  m_pointer = (vostok::network_core::buffer_writer *)reader->m_pointer;
  v7 = &reader->m_buffer[reader->m_buffer_size - (_DWORD)m_pointer];
  if ( (unsigned int)v7 <= 0x4B2 )
  {
    vostok::network_core::buffer_writer::w(
      m_pointer,
      &matched->data[1340],
      (unsigned __int8 *)m_pointer,
      (unsigned int)&reader->m_buffer[reader->m_buffer_size - (_DWORD)m_pointer]);
    goto LABEL_10;
  }
  v31.tree_.data_.node_plus_pred_.header_plus_size_.size_ = 1202;
  matched->data[16] = 0;
  v29 = (unsigned __int8 *)reader->m_pointer;
  v34 = (unsigned int)(v7 - 1) / 0x4B2 + 1;
  vostok::network_core::buffer_writer::w(
    (vostok::network_core::buffer_writer *)0x4B2,
    &matched->data[1340],
    v29,
    v31.tree_.data_.node_plus_pred_.header_plus_size_.size_);
  reader->m_pointer += 1202;
  v35 = (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,0> *)&matched->data[36];
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1>>::insert_unique(
    &result,
    (int)&matched->data[36],
    (stlp_std::pair<boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,0>,bool> *)&result,
    (vostok::network_core::udp_match_message_part *)matched);
  v32 = 1;
  if ( v34 <= 1 )
  {
LABEL_10:
    v8 = vostok::network::g_allocator;
    v9 = type_info::raw_name(&vostok::network::receive_udp_response `RTTI Type Descriptor');
    v12 = vostok::memory::doug_lea_allocator::malloc_impl(
            v10,
            (int)v8,
            0xC0u,
            v9,
            (const char *const)v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.parent_,
            (const char *const)v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.left_,
            (const unsigned int)v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.right_);
    if ( v12 )
    {
      LOBYTE(result.data_.node_plus_pred_.header_plus_size_.header_.parent_) = message_type;
      result.data_.node_plus_pred_.header_plus_size_.header_.right_ = (boost::intrusive::rbtree_node<void *> *)v33;
      result.data_.node_plus_pred_.header_plus_size_.header_.color_ = (boost::intrusive::rbtree_node<void *>::color)result.data_.node_plus_pred_.header_plus_size_.header_.parent_;
      result.data_.node_plus_pred_.header_plus_size_.header_.left_ = (boost::intrusive::rbtree_node<void *> *)vostok::network::match_client::on_packet_received_impl;
      v28.l_.a1_.t_ = (vostok::network::match_client *)vostok::network::match_client::on_packet_received_impl;
      *(_DWORD *)&v28.l_.a2_.t_ = v33;
      v28.f_.f_ = (void (__thiscall *)(vostok::network::match_client *, unsigned __int8, vostok::network_core::buffer_reader *))&f;
      boost::function<void __cdecl (vostok::network_core::buffer_reader &)>::function<void __cdecl (vostok::network_core::buffer_reader &)>(
        v11,
        v28,
        (int)result.data_.node_plus_pred_.header_plus_size_.header_.parent_);
      v13 = *v33->m_client;
      v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ = 4;
      vostok::network::receive_udp_response::receive_udp_response(
        vostok::network::g_allocator,
        (const vostok::network_core::udp_match_stats *)((char *)v13 + (_DWORD)&loc_55E22 + 2),
        (vostok::network::receive_udp_response *)v12,
        &f,
        &v33->m_response_packets_allocator,
        (vostok::network_core::udp_match_packet *)i.members_.nodeptr_,
        &v33->m_stats);
    }
    else
    {
      v14 = 0;
    }
    m_world = v33->m_world;
    *(_DWORD *)(v14 + 8) = 0;
    p_m_channel = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&m_world->m_channel;
    _InterlockedExchange((volatile __int32 *)&p_m_channel->vtable[2], v14);
    v27 = (v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ & 4) == 0;
    p_m_channel->vtable = (boost::detail::function::vtable_base *)v14;
    if ( !v27 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        p_m_channel,
        (int *)&f);
    return;
  }
  while ( 1 )
  {
    p_m_object = &v33->m_response_packets_allocator.m_object;
    v16 = vostok::network_core::new_udp_match_packet(v33->m_response_packets_allocator.m_object);
    result.data_.node_plus_pred_.header_plus_size_.size_ = (unsigned int)v16;
    if ( !v16 )
      break;
    v16->data[16] = v32;
    v18 = (unsigned __int8 *)reader->m_pointer;
    v19 = (vostok::network_core::buffer_writer *)&reader->m_buffer[reader->m_buffer_size - (_DWORD)v18];
    v20 = -((unsigned int)v19 < 0x4B2);
    v19 = (vostok::network_core::buffer_writer *)((char *)v19 - 1202);
    v21 = ((unsigned int)v19 & v20) + 1202;
    vostok::network_core::buffer_writer::w(v19, &v16->data[1340], v18, v21);
    v31.tree_.data_.node_plus_pred_.header_plus_size_.size_ = result.data_.node_plus_pred_.header_plus_size_.size_;
    reader->m_pointer += v21;
    boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1>>::insert_unique(
      v22,
      (int)v35,
      (stlp_std::pair<boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,0>,bool> *)&result.data_.node_plus_pred_.header_plus_size_.header_.left_,
      (vostok::network_core::udp_match_message_part *)v31.tree_.data_.node_plus_pred_.header_plus_size_.size_);
    if ( ++v32 >= v34 )
      goto LABEL_10;
  }
  if ( !vostok::core::g_log_filter_tree
    || (v23 = vostok::logging::has_passed_filters(
                (vostok::logging::filter_tree *)&initiator_raw.filter_stack,
                (const char *)2),
        v17 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v31.tree_.data_.node_plus_pred_.header_plus_size_.size_,
        v23) )
  {
    boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
      v17,
      &f);
    v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ = 2;
    vostok::logging::append(
      (const boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)&f,
      (void *const)vostok::core::g_log_flags,
      &vostok::core::g_log_format,
      ".\\match_client.cpp",
      0x140u,
      "void __thiscall vostok::network::match_client::on_packet_received(unsigned char,class vostok::network_core::buffer_reader &)",
      &initiator_raw.filter_stack.gap0,
      error,
      "skipping MULTIpart packet because we are out of response packets");
  }
  if ( (v31.tree_.data_.node_plus_pred_.header_plus_size_.header_.color_ & 2) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v17,
      (int *)&f);
  nodeptr = i.members_.nodeptr_;
  while ( nodeptr[2].right_ )
  {
    result.data_.node_plus_pred_.header_plus_size_.size_ = nodeptr[2].color_;
    boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,vostok::network_core::udp_match_packet::comparer,unsigned int,1>>::erase(
      &v31,
      v35,
      (boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,1>)&i,
      (boost::intrusive::rbtree_node<void *> *)result.data_.node_plus_pred_.header_plus_size_.size_);
    vostok::network_core::delete_udp_match_packet(
      *p_m_object,
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&result);
  }
  v31.tree_.data_.node_plus_pred_.header_plus_size_.size_ = (unsigned int)&result;
  v30 = *p_m_object;
  result.data_.node_plus_pred_.header_plus_size_.size_ = (unsigned int)nodeptr;
  vostok::network_core::delete_udp_match_packet(
    v30,
    (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&result);
}
