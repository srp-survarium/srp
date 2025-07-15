void __thiscall vostok::network_core::udp_match_connection::enqueue(
        vostok::network_core::udp_match_connection *this,
        int message_type,
        vostok::network_core::buffer_reader *reader,
        vostok::network_core::udp_match_packet *a4)
{
  vostok::network_core::udp_match_packet *v4; // ebx
  vostok::network_core::udp_match_packet *matched; // eax
  int (__thiscall ***v6)(_DWORD, vostok::network_core::udp_match_packet **, vostok::network_core::buffer_reader *); // ecx
  _WORD *v7; // eax
  vostok::network_core::buffer_writer *v8; // ecx
  vostok::network_core::udp_match_packet *v9; // esi
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *v10; // ecx
  int v11; // eax
  unsigned __int8 *p_message_parts_count; // esi
  vostok::network_core::buffer_writer *v13; // ecx
  vostok::network_core::buffer_writer *v14; // ecx
  vostok::network_core::buffer_writer *v15; // ecx
  vostok::network_core::udp_match_packet *v16; // esi
  unsigned int v17; // edi
  boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *v18; // ecx
  vostok::network_core::buffer_writer *p_m_writer; // edi
  vostok::network_core::buffer_writer *v20; // ecx
  boost::intrusive::set<vostok::network_core::udp_match_message_part,boost::intrusive::member_hook<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,boost::intrusive::compare<vostok::network_core::udp_match_packet::part_id_comparer>,boost::intrusive::none,boost::intrusive::none> *v21; // ecx
  boost::intrusive::rbtree_node<void *> *node; // esi
  vostok::network_core::sequence_number<unsigned short> *p_order_id; // [esp-8h] [ebp-54h]
  vostok::network_core::buffer_writer *v24; // [esp-4h] [ebp-50h]
  unsigned __int8 v25; // [esp-4h] [ebp-50h]
  int v26; // [esp+10h] [ebp-3Ch] BYREF
  int v27; // [esp+14h] [ebp-38h] BYREF
  vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *v28; // [esp+18h] [ebp-34h]
  int *v29; // [esp+1Ch] [ebp-30h]
  int v30; // [esp+20h] [ebp-2Ch]
  unsigned __int8 *left; // [esp+28h] [ebp-24h]
  stlp_std::pair<boost::intrusive::tree_iterator<boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> >,0>,bool> v32; // [esp+30h] [ebp-1Ch] BYREF
  unsigned int v33; // [esp+38h] [ebp-14h]
  _BYTE v34[4]; // [esp+3Ch] [ebp-10h] BYREF
  unsigned __int8 *v35; // [esp+40h] [ebp-Ch]
  vostok::network_core::udp_match_packet *v36; // [esp+44h] [ebp-8h]

  v4 = a4;
  if ( !*(_DWORD *)(message_type + 2820) )
  {
    matched = (vostok::network_core::udp_match_packet *)vostok::network_core::new_udp_match_packet(*(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(message_type + 2784));
    v6 = *(int (__thiscall ****)(_DWORD, vostok::network_core::udp_match_packet **, vostok::network_core::buffer_reader *))(message_type + 2788);
    v36 = matched;
    if ( (boost::intrusive::rbtree_node<void *>::color *)((char *)&v4->ordered_multipackets_hook.right_->color_
                                                        + (*(_BYTE *)((**v6)(v6, &a4, reader) + 3) >> 7 != 0 ? 2 : 0)
                                                        - (unsigned int)v4->ordered_multipackets_hook.left_
                                                        + (unsigned int)v4->ordered_multipackets_hook.parent_
                                                        + 1) > (boost::intrusive::rbtree_node<void *>::color *)0x1FC )
    {
      (***(void (__thiscall ****)(_DWORD, _BYTE *, vostok::network_core::buffer_reader *))(message_type + 2788))(
        *(_DWORD *)(message_type + 2788),
        v34,
        reader);
      v7 = (_WORD *)(44 * (v34[3] & 0x3F) + message_type + 2718);
      HIWORD(a4) = *v7;
      v8 = (vostok::network_core::buffer_writer *)(HIWORD(a4) + 1);
      *v7 = (_WORD)v8;
      v9 = v36;
      vostok::network_core::construct_multipacket_part(
        v36,
        v8,
        *(vostok::network_core::udp_match_packets_orderer **)(message_type + 2788),
        (int)reader,
        (vostok::network_core::sequence_number<unsigned short> *)&a4 + 1,
        0);
      v10 = (boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1> > *)v9;
      v11 = 507 - v9->m_buffer.m_size;
      left = (unsigned __int8 *)v4->ordered_multipackets_hook.left_;
      v33 = v11;
      p_message_parts_count = &v9->message_parts_count;
      v4->ordered_multipackets_hook.left_ = (boost::intrusive::rbtree_node<void *> *)&left[v11];
      *p_message_parts_count = 1;
      v27 = 0;
      v30 = 0;
      v26 = 0;
      v35 = p_message_parts_count;
      v28 = (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v27;
      v29 = &v27;
      boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1>>::insert_unique(
        v10,
        (int)&v26,
        &v32,
        (vostok::network_core::udp_match_message_part *)v10);
      while ( v4->ordered_multipackets_hook.left_ != (boost::intrusive::rbtree_node<void *> *)((char *)v4->ordered_multipackets_hook.parent_
                                                                                             + (unsigned int)v4->ordered_multipackets_hook.right_) )
      {
        a4 = (vostok::network_core::udp_match_packet *)vostok::network_core::new_udp_match_packet(*(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(message_type + 2784));
        v25 = *p_message_parts_count;
        p_order_id = &v36->order_id;
        LOBYTE(v14) = *p_message_parts_count + 1;
        *p_message_parts_count = (unsigned __int8)v14;
        vostok::network_core::construct_multipacket_part(
          a4,
          v14,
          *(vostok::network_core::udp_match_packets_orderer **)(message_type + 2788),
          (int)reader,
          p_order_id,
          v25);
        v15 = (vostok::network_core::buffer_writer *)((char *)v4->ordered_multipackets_hook.parent_
                                                    + (char *)v4->ordered_multipackets_hook.right_
                                                    - (char *)v4->ordered_multipackets_hook.left_);
        v16 = a4;
        v17 = (unsigned int)v15
            + (508 - v36->m_buffer.m_size < (unsigned int)v15 ? 508 - v36->m_buffer.m_size - (_DWORD)v15 : 0);
        vostok::network_core::buffer_writer::w(
          v15,
          &a4->m_writer.serialization_operations_descriptors.m_size,
          (unsigned __int8 *)v4->ordered_multipackets_hook.left_,
          v17);
        v4->ordered_multipackets_hook.left_ = (boost::intrusive::rbtree_node<void *> *)((char *)v4->ordered_multipackets_hook.left_
                                                                                      + v17);
        boost::intrusive::rbtree_impl<boost::intrusive::setopt<boost::intrusive::detail::member_hook_traits<vostok::network_core::udp_match_message_part,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,0>,vostok::network_core::udp_match_packet::part_id_comparer,unsigned int,1>>::insert_unique(
          v18,
          (int)&v26,
          &v32,
          v16);
        p_message_parts_count = v35;
      }
      p_m_writer = &v36->m_writer;
      vostok::network_core::buffer_writer::w(
        v13,
        &v36->m_writer.serialization_operations_descriptors.m_size,
        p_message_parts_count,
        1u);
      vostok::network_core::buffer_writer::w(v20, p_m_writer, left, v33);
      node = (boost::intrusive::rbtree_node<void *> *)v28;
      if ( v28 != (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)&v27 )
      {
        do
        {
          if ( (HIBYTE(node[6].right_) & 0x40) != 0 )
            ++*(_DWORD *)(message_type + 2624);
          vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
            (vostok::intrusive_list<vostok::network_core::udp_match_packet,vostok::network_core::udp_match_packet *,60,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)node,
            (_DWORD *)(message_type + 2628));
          node = boost::intrusive::detail::tree_algorithms<boost::intrusive::rbtree_node_traits<void *,0>>::next_node(node);
        }
        while ( node != (boost::intrusive::rbtree_node<void *> *)&v27 );
      }
      boost::intrusive::set<vostok::network_core::udp_match_packet,boost::intrusive::member_hook<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,boost::intrusive::compare<vostok::network_core::udp_match_packet::comparer>,boost::intrusive::none,boost::intrusive::none>::~set<vostok::network_core::udp_match_packet,boost::intrusive::member_hook<vostok::network_core::udp_match_packet,boost::intrusive::set_member_hook<boost::intrusive::none,boost::intrusive::none,boost::intrusive::none,boost::intrusive::none>,20>,boost::intrusive::compare<vostok::network_core::udp_match_packet::comparer>,boost::intrusive::none,boost::intrusive::none>(
        v21,
        &v26);
    }
    else
    {
      vostok::network_core::udp_match_connection::construct_packet(
        v36,
        (vostok::network_core::buffer_writer *)v4->ordered_multipackets_hook.parent_,
        *(vostok::network_core::udp_match_packets_orderer **)(message_type + 2788),
        (int)reader);
      v24 = (vostok::network_core::buffer_writer *)((char *)v4->ordered_multipackets_hook.parent_
                                                  + (char *)v4->ordered_multipackets_hook.right_
                                                  - (char *)v4->ordered_multipackets_hook.left_);
      vostok::network_core::buffer_writer::w(
        v24,
        &v36->m_writer.serialization_operations_descriptors.m_size,
        (unsigned __int8 *)v4->ordered_multipackets_hook.left_,
        (unsigned int)v24);
      vostok::network_core::udp_match_connection::enqueue_impl(
        (vostok::network_core::udp_match_connection *)v36,
        message_type);
    }
  }
}


void __userpurge vostok::network_core::udp_match_connection::enqueue(
        vostok::network_core::udp_match_connection *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::udp_match_connection *packet)
{
  if ( *(_DWORD *)(a2 + 2820) )
    vostok::network_core::delete_udp_match_packet(
      *(vostok::memory::single_size_buffer_allocator<1364,vostok::threading::multi_threading_policy> **)(a2 + 2784),
      (vostok::memory::single_size_buffer_allocator<140,vostok::threading::simple_lock>::node **)&packet);
  else
    vostok::network_core::udp_match_connection::enqueue_impl(packet, a2);
}
