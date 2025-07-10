void __userpurge vostok::resources::query_result::unset_flag(
        unsigned int flag@<eax>,
        vostok::resources::query_result *this)
{
  vostok::threading::interlocked_and(&this->m_flags, ~flag);
}
