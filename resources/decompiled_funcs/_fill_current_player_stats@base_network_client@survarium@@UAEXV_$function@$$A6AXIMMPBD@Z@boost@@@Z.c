void __thiscall survarium::base_network_client::fill_current_player_stats(
        survarium::base_network_client *this,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> callback)
{
  survarium::player *m_object; // edi
  survarium::damage_model **v3; // eax
  void (__cdecl *v4)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> v5; // [esp-20h] [ebp-28h] BYREF

  m_object = this->m_current_player.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(&callback, (int)&v5);
    v3 = (survarium::damage_model **)m_object->damage_model(m_object);
    survarium::damage_model::dump_stats(*v3, v5);
  }
  if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
  {
    v4 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
    if ( v4 )
      v4(&callback.functor, &callback.functor, 2);
  }
}
