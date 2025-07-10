void __userpurge vostok::animation::bone_name_index::bone_name_index(
        char *aname@<edi>,
        vostok::animation::bone_name_index *this,
        unsigned int idx)
{
  vostok::animation::bone_name_index *v3; // ebx

  v3 = this;
  this->index = -1;
  this = (vostok::animation::bone_name_index *)boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&this,
    (unsigned __int8 *)aname,
    (unsigned __int8 *)&aname[strlen(aname)]);
  v3->crc = ~(unsigned int)this;
  strcpy_s(v3->name, 0x40u, aname);
}
