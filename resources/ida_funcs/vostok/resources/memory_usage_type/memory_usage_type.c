void __userpurge vostok::resources::memory_usage_type::memory_usage_type(
        boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *this@<ecx>,
        boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **eax0@<eax>,
        vostok::network_core::packet_reader *a1,
        vostok::network_core::packet_reader *a2)
{
  *eax0 = this;
  eax0[1] = (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)a1;
}
