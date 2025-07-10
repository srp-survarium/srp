void __usercall vostok::resources::query_result::set_result_iterator(
        vostok::resources::query_result *this@<ecx>,
        const vostok::vfs::vfs_locked_iterator *it@<eax>)
{
  vostok::resources::query_result *v2; // edi
  vostok::vfs::vfs_locked_iterator *p_m_result_iterator; // esi

  v2 = this;
  p_m_result_iterator = &this->m_result_iterator;
  vostok::vfs::vfs_locked_iterator::grab(&this->m_result_iterator, it);
  v2 = (vostok::resources::query_result *)((char *)v2 + 688);
  vostok::threading::interlocked_or((volatile int *)v2, 0x200u);
  vostok::threading::interlocked_and((volatile int *)v2, 0xFFFDFFFF);
  vostok::vfs::vfs_iterator::operator bool(p_m_result_iterator);
}
