void __thiscall vostok::physics::bullet_physics_world::notify_about_contact(
        vostok::physics::bullet_physics_world *this,
        int a2)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int v4; // edx
  float *v5; // ebx
  boost::detail::function::vtable_base *v6; // ecx
  int v7; // xmm0_4
  int v8; // xmm1_4
  int v9; // xmm2_4
  int v10; // xmm3_4
  void *v11; // xmm1_4
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *v12; // eax
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v13; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_node; // esi
  int v15; // xmm0_4
  int v16; // xmm1_4
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *v17; // eax
  int v18; // xmm1_4
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v19; // ecx
  stlp_std::priv::_Rb_tree_node_base *v20; // esi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v21; // [esp-4h] [ebp-94h]
  boost::function1<void,vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> const &> *v22; // [esp-4h] [ebp-94h]
  int v23; // [esp+10h] [ebp-80h]
  vostok::physics::base_physics_object *__x; // [esp+14h] [ebp-7Ch] BYREF
  vostok::physics::base_physics_object *v25; // [esp+18h] [ebp-78h] BYREF
  int v26; // [esp+1Ch] [ebp-74h]
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > >,stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > > result; // [esp+20h] [ebp-70h] BYREF
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > >,stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *>,stlp_std::priv::_MultimapTraitsT<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > > v28; // [esp+28h] [ebp-68h] BYREF
  __int64 v29; // [esp+30h] [ebp-60h]
  void *v30; // [esp+38h] [ebp-58h]
  int v31; // [esp+3Ch] [ebp-54h]
  int v32; // [esp+40h] [ebp-50h]
  void *v33; // [esp+44h] [ebp-4Ch]
  __int64 v34; // [esp+48h] [ebp-48h]
  void *v35; // [esp+50h] [ebp-40h]
  __int64 v36; // [esp+54h] [ebp-3Ch]
  void *v37; // [esp+5Ch] [ebp-34h]
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> a0; // [esp+60h] [ebp-30h] BYREF

  v23 = 0;
  v26 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(a2 + 40) + 32))(*(_DWORD *)(a2 + 40));
  if ( v26 > 0 )
  {
    do
    {
      v2 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a2 + 40) + 36))(*(_DWORD *)(a2 + 40), v23);
      v3 = v2[294];
      v4 = 0;
      if ( v3 > 0 )
      {
        v5 = (float *)(v2 + 4);
        while ( v5[20] >= 0.0 )
        {
          ++v4;
          v5 += 72;
          if ( v4 >= v3 )
            goto LABEL_13;
        }
        v6 = *(boost::detail::function::vtable_base **)(v2[292] + 248);
        v7 = *((_DWORD *)v5 + 12);
        v8 = *((_DWORD *)v5 + 14);
        v9 = *((_DWORD *)v5 + 16);
        v10 = *((_DWORD *)v5 + 17);
        (&a0.m_on_out_of_memory.vtable)[1] = *(boost::detail::function::vtable_base **)(v2[293] + 248);
        LODWORD(v29) = v7;
        *((float *)&v29 + 1) = v5[13];
        a0.m_on_out_of_memory.vtable = v6;
        v30 = (void *)(v8 ^ _mask__NegFloat_);
        v11 = (void *)*((_DWORD *)v5 + 18);
        *(_QWORD *)&a0.m_on_out_of_memory.functor.obj_ptr = v29;
        a0.m_on_out_of_memory.functor.vostok_pointer_size_alignment[2] = v30;
        v31 = v9 ^ _mask__NegFloat_;
        v32 = v10 ^ _mask__NegFloat_;
        v33 = v11;
        a0.m_on_out_of_memory.functor.vostok_pointer_size_alignment[3] = (void *)(v9 ^ _mask__NegFloat_);
        a0.m_on_out_of_memory.functor.bound_memfunc_ptr.obj_ptr = (void *)(v10 ^ _mask__NegFloat_);
        v25 = (vostok::physics::base_physics_object *)(&a0.m_on_out_of_memory.vtable)[1];
        v12 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *)*((_DWORD *)v5 + 23);
        a0.m_on_out_of_memory.functor.vostok_pointer_size_alignment[5] = v11;
        a0.m_free_list_head.pointer = v12;
        a0.m_allocated_count = (unsigned int)v5[24];
        a0.m_max_count = (unsigned int)v5[25];
        a0.m_arena = (void *)v5[26];
        __x = (vostok::physics::base_physics_object *)v6;
        stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl (vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::equal_range<vostok::physics::base_physics_object *>(
          (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)v6,
          (stlp_std::priv::_Rb_tree_node_base *)(a2 + 8),
          &result,
          &__x);
        M_node = result.first._M_node;
        if ( result.first._M_node != result.second._M_node )
        {
          do
          {
            boost::function1<void,vostok::collision::object const &>::operator()(
              v13,
              &M_node[1]._M_parent->_M_color,
              &a0);
            M_node = stlp_std::priv::_Rb_global<bool>::_M_increment(M_node);
            v13 = v21;
          }
          while ( M_node != result.second._M_node );
          result.first._M_node = M_node;
        }
        v15 = *((_DWORD *)v5 + 8);
        v16 = *((_DWORD *)v5 + 10);
        a0.m_on_out_of_memory.vtable = (boost::detail::function::vtable_base *)v25;
        (&a0.m_on_out_of_memory.vtable)[1] = (boost::detail::function::vtable_base *)__x;
        v17 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy>::node *)*((_DWORD *)v5 + 24);
        LODWORD(v34) = v15;
        *((float *)&v34 + 1) = v5[9];
        v35 = (void *)(v16 ^ _mask__NegFloat_);
        v18 = *((_DWORD *)v5 + 16);
        *(_QWORD *)&a0.m_on_out_of_memory.functor.obj_ptr = v34;
        a0.m_on_out_of_memory.functor.vostok_pointer_size_alignment[2] = v35;
        LODWORD(v36) = v18;
        *((float *)&v36 + 1) = v5[17];
        v37 = (void *)(*((_DWORD *)v5 + 18) ^ _mask__NegFloat_);
        *(_QWORD *)(&a0.m_on_out_of_memory.functor.data + 12) = v36;
        a0.m_on_out_of_memory.functor.vostok_pointer_size_alignment[5] = v37;
        a0.m_free_list_head.pointer = v17;
        a0.m_allocated_count = (unsigned int)v5[23];
        a0.m_max_count = (unsigned int)v5[26];
        a0.m_arena = (void *)v5[25];
        stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl (vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl (vostok::physics::contact_point const &)> *>>>::equal_range<vostok::physics::base_physics_object *>(
          (stlp_std::multimap<vostok::physics::base_physics_object *,boost::function<void __cdecl(vostok::physics::contact_point const &)> *,stlp_std::less<vostok::physics::base_physics_object *>,stlp_std::allocator<stlp_std::pair<vostok::physics::base_physics_object * const,boost::function<void __cdecl(vostok::physics::contact_point const &)> *> > > *)v13,
          (stlp_std::priv::_Rb_tree_node_base *)(a2 + 8),
          &v28,
          &v25);
        v20 = v28.first._M_node;
        if ( v28.first._M_node != v28.second._M_node )
        {
          do
          {
            boost::function1<void,vostok::collision::object const &>::operator()(v19, &v20[1]._M_parent->_M_color, &a0);
            v20 = stlp_std::priv::_Rb_global<bool>::_M_increment(v20);
            v19 = v22;
          }
          while ( v20 != v28.second._M_node );
          v28.first._M_node = v20;
        }
      }
LABEL_13:
      ++v23;
    }
    while ( v23 < v26 );
  }
}
