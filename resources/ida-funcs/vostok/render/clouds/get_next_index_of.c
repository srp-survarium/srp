unsigned int __usercall vostok::render::clouds::get_next_index_of@<eax>(
        vostok::render::clouds *this@<ecx>,
        int a2@<eax>)
{
  return (unsigned int)&this->m_keys[0].cloud_generate_octaves + 1 < *(_DWORD *)(a2 + 2176)
       ? (unsigned int)&this->m_keys[0].cloud_generate_octaves + 1
       : 0;
}
