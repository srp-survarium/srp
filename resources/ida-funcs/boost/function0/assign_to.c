void __thiscall boost::function0<bool>::assign_to<bool (__cdecl *)(void)>(
        boost::function0<bool> *this,
        bool (__cdecl *f)())
{
  boost::detail::function::function_buffer *p_functor; // [esp+4h] [ebp-Ch]
  char v4; // [esp+9h] [ebp-7h]

  p_functor = &this->functor;
  boost::detail::function::basic_vtable0<bool>::clear(
    (boost::detail::function::basic_vtable0<bool> *)&this->functor,
    (void (__cdecl **)(boost::detail::function::basic_vtable0<bool> *, boost::detail::function::basic_vtable0<bool> *, int))&stru_977EF0.m_fat_it.m_node);
  if ( f )
  {
    p_functor->obj_ptr = f;
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  if ( v4 )
    this->vtable = (boost::detail::function::vtable_base *)((char *)&stru_977EF0.m_fat_it.m_node + 1);
  else
    this->vtable = 0;
}


void __userpurge boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(void),boost::_bi::list0>>(
        boost::function0<void> *this@<ecx>,
        boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *a2@<esi>,
        boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> f)
{
  if ( survarium::generate_shaders_world::is_loading() )
  {
    a2->f_ = 0;
  }
  else
  {
    if ( a2 != (boost::_bi::bind_t<void,void (__cdecl*)(void),boost::_bi::list0> *)-8 )
      a2[1] = f;
    a2->f_ = (void (__cdecl *)())&stru_954D10.m_string.m_buffer[57];
  }
}


void __userpurge boost::function0<void>::assign_to<boost::_bi::bind_t<void,void (__cdecl *)(bool),boost::_bi::list1<boost::_bi::value<bool>>>>(
        boost::function0<void> *this@<ecx>,
        boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *a2@<esi>,
        boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > f)
{
  if ( survarium::generate_shaders_world::is_loading() )
  {
    a2->f_ = 0;
  }
  else
  {
    if ( a2 != (boost::_bi::bind_t<void,void (__cdecl*)(bool),boost::_bi::list1<boost::_bi::value<bool> > > *)-8 )
      a2[1] = f;
    a2->f_ = (void (__cdecl *)(bool))&stru_954D10.m_string.m_buffer[121];
  }
}


void __thiscall boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>(
        boost::function0<bool> *this,
        boost::_bi::bind_t<bool,bool (__cdecl*)(void),boost::_bi::list0> f)
{
  if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable,
         (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)f,
         &this->functor) )
  {
    this->vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,bool (__cdecl *)(void),boost::_bi::list0>>'::`2'::stored_vtable.base.manager
                                                          + 1);
  }
  else
  {
    this->vtable = 0;
  }
}
