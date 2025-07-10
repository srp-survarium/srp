void __usercall vostok::resources::resource_flags::resource_flags(
        vostok::resources::resource_flags *this@<esi>,
        volatile int flags@<edi>)
{
  vostok::vfs::vfs_association::vfs_association(this, flags & 7);
  this->__vftable = (vostok::resources::resource_flags_vtbl *)&vostok::resources::resource_flags::`vftable';
  this->m_flags.m_flags = flags;
}
