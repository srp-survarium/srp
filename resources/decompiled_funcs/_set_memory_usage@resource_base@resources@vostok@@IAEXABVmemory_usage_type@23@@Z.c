void __usercall vostok::resources::resource_base::set_memory_usage(
        vostok::resources::resource_base *this@<ecx>,
        const vostok::resources::memory_usage_type *usage@<eax>)
{
  this->m_memory_usage_self = *usage;
}
