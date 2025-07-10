void __thiscall stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::_M_clear(
        stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *this)
{
  vostok::render::skeleton_model_instance *v1; // eax
  void **v2; // ecx
  survarium::game_camera *v3; // ecx
  stlp_std::reverse_iterator<void * *> v4; // [esp-8h] [ebp-3Ch] BYREF
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *v5; // [esp-4h] [ebp-38h] BYREF
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *thisa; // [esp+0h] [ebp-34h]
  int v7; // [esp+4h] [ebp-30h]
  void *__p; // [esp+8h] [ebp-2Ch]
  stlp_std::reverse_iterator<void * *> *v9; // [esp+20h] [ebp-14h]
  void **__x; // [esp+24h] [ebp-10h]
  stlp_std::reverse_iterator<void * *> *v11; // [esp+28h] [ebp-Ch]

  thisa = this;
  v5 = this;
  v11 = (stlp_std::reverse_iterator<void * *> *)&v5;
  v1 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)this);
  stlp_std::reverse_iterator<void * *>::reverse_iterator<void * *>(v11, (void **)&v1->__vftable);
  v4.current = v2;
  v9 = &v4;
  __x = thisa->_M_finish;
  stlp_std::reverse_iterator<void * *>::reverse_iterator<void * *>(&v4, __x);
  survarium::weapon_user_dead_state::finalize(v3);
  v7 = thisa->_M_end_of_storage._M_data - thisa->_M_start;
  __p = thisa->_M_start;
  if ( __p )
    stlp_std::__node_alloc::deallocate(__p, 4 * v7);
}
