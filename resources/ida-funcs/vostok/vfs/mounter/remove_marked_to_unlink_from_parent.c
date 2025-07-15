void __cdecl vostok::vfs::mounter::remove_marked_to_unlink_from_parent(vostok::vfs::base_folder_node<1> *parent)
{
  vostok::vfs::base_folder_node<1> *v1; // ebx
  vostok::vfs::base_node<1> *p_base; // eax
  vostok::vfs::base_node<1> *pointer; // eax
  vostok::vfs::base_folder_node<1> *v4; // esi
  vostok::vfs::base_node<1> *v5; // eax
  vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> v6; // [esp-8h] [ebp-3Ch] BYREF
  vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper v7; // [esp+10h] [ebp-24h] BYREF
  vostok::vfs::base_node<1> *v8; // [esp+18h] [ebp-1Ch]
  int v9; // [esp+1Ch] [ebp-18h]
  int v10; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  vostok::vfs::base_node<1> *v12; // [esp+2Ch] [ebp-8h]

  v1 = parent;
  if ( parent )
    p_base = &parent->base;
  else
    p_base = 0;
  pointer = p_base->m_next_overlapped.pointer;
  if ( !pointer || (pointer->m_flags & 0x300) != 0 )
    v4 = 0;
  else
    v4 = vostok::vfs::cast_folder<1>(pointer);
  v5 = parent->m_first_child.pointer;
  v7.pointer = 0;
  v9 = 0;
  v8 = 0;
  v11 = 0;
  v10 = 0;
  if ( v5 )
  {
    do
    {
      v12 = v5->m_next.pointer;
      if ( (v5->m_flags & 0x4000) == 0x4000 )
      {
        _InterlockedAnd((volatile signed __int32 *)&v5->m_flags, 0xFFFFBFFF);
        v5->m_parent.pointer = v4;
        v5->m_next.pointer = v4->m_first_child.pointer;
        HIDWORD(v5->m_next.max_storage) = HIDWORD(v4->m_first_child.max_storage);
        v4->m_first_child.pointer = v5;
      }
      else
      {
        vostok::intrusive_list<vostok::vfs::base_node<1>,vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper,24,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          &v6,
          &v7,
          (vostok::platform_pointer_selector<vostok::vfs::base_node<1>,1>::helper)(unsigned int)v5,
          (bool *)v6.m_first.pointer);
      }
      v5 = v12;
    }
    while ( v12 );
    v1 = parent;
  }
  v1->m_first_child.pointer = v8;
  HIDWORD(v1->m_first_child.max_storage) = v9;
}
