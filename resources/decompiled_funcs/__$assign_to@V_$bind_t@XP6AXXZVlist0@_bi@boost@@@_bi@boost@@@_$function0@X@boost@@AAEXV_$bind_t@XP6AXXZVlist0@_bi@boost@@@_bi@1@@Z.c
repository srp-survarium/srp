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
