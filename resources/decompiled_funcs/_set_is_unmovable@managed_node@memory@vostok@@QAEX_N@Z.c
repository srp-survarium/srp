void __usercall vostok::memory::managed_node::set_is_unmovable(
        vostok::memory::managed_node *this@<ecx>,
        bool is_unmovable@<al>)
{
  _InterlockedExchange(&this->m_is_unmovable, is_unmovable);
}
