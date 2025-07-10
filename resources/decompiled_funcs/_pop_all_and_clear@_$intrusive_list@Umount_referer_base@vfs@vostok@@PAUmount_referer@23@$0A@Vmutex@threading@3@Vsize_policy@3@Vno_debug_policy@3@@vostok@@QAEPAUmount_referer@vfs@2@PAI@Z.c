vostok::vfs::mount_referer *__thiscall vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::pop_all_and_clear(
        vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *this,
        vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *out_size)
{
  vostok::intrusive_list<vostok::vfs::mount_referer_base,vostok::vfs::mount_referer *,0,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v3; // ecx
  const vostok::variant<32> **v4; // eax
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> *v5; // ecx
  vostok::vfs::mount_referer *result; // [esp+10h] [ebp-Ch]
  vostok::threading::mutex_raii_impl<vostok::threading::mutex> raii; // [esp+14h] [ebp-8h] BYREF

  if ( this->m_first )
  {
    if ( this )
      vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
        (vostok::threading::mutex_raii_impl<vostok::threading::mutex> *)&this->vostok::threading::mutex,
        (int)&raii);
    else
      vostok::threading::mutex_raii_impl<vostok::threading::mutex>::mutex_raii_impl<vostok::threading::mutex>(
        0,
        (int)&raii);
    result = this->m_first;
    v3 = this;
    this->m_first = 0;
    this->m_last = 0;
    if ( out_size )
    {
      v4 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
             (int)this);
      v3 = out_size;
      out_size->m_size = (unsigned int)v4;
    }
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v3);
    vostok::threading::mutex_raii_impl<vostok::threading::mutex>::~mutex_raii_impl<vostok::threading::mutex>(
      v5,
      (int)&raii);
    return result;
  }
  else
  {
    if ( out_size )
      out_size->m_size = 0;
    return 0;
  }
}
