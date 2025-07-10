void __userpurge vostok::animation::bone_names::create_internals_in_place(
        const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *names@<eax>,
        vostok::animation::bone_names *this,
        _BYTE *memory)
{
  const vostok::configs::binary_config_value *v3; // eax
  vostok::animation::bone_names *v4; // edi
  int v5; // ecx
  void *v6; // esp
  unsigned int v7; // ebx
  char *v8; // edi
  unsigned int m_bone_count; // eax
  vostok::animation::bone_name_index *v10; // ebx
  int v11; // eax
  int i; // ecx
  unsigned int v13; // ebx
  int v14; // eax
  _BYTE v15[12]; // [esp+0h] [ebp-20h] BYREF
  unsigned int n; // [esp+Ch] [ebp-14h]
  const vostok::configs::binary_config_value *bones_names; // [esp+10h] [ebp-10h]
  boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> processor; // [esp+14h] [ebp-Ch] BYREF
  int v19; // [esp+18h] [ebp-8h]
  int v20; // [esp+1Ch] [ebp-4h]

  v3 = vostok::configs::binary_config_value::operator[](names->m_object->m_root, "bones_names");
  v4 = this;
  v5 = 3 * v3->count;
  bones_names = v3;
  vostok::animation::bone_names::create_internals_in_place(this, memory, 8 * v5 / 24);
  v6 = alloca(72 * this->m_bone_count);
  v7 = 0;
  n = this->m_bone_count;
  if ( n )
  {
    v19 = 0;
    v20 = 0;
    v8 = v15;
    do
    {
      strcpy_s(v8, 0x40u, *(const char **)((char *)bones_names->data.pointer + v20));
      *((_DWORD *)v8 + 17) = v7;
      processor.rem_ = boost::detail::crc_helper<32,1>::reflect(0xFFFFFFFF);
      boost::detail::crc_table_t<32,79764919,1>::init_table();
      boost::crc_optimal<32,79764919,4294967295,4294967295,1,1>::process_block(
        &processor,
        (unsigned __int8 *)v8,
        &v15[strlen(v8) + v19]);
      v20 += 24;
      v19 += 72;
      *((_DWORD *)v8 + 16) = ~processor.rem_;
      ++v7;
      v8 += 72;
    }
    while ( v7 < n );
    v4 = this;
  }
  m_bone_count = v4->m_bone_count;
  v10 = (vostok::animation::bone_name_index *)&v15[72 * m_bone_count];
  LOBYTE(processor.rem_) = 0;
  if ( v15 != (_BYTE *)v10 )
  {
    v11 = (int)(72 * m_bone_count) / 72;
    for ( i = 0; v11 != 1; ++i )
      v11 >>= 1;
    stlp_std::priv::__introsort_loop<vostok::animation::bone_name_index *,vostok::animation::bone_name_index,int,vostok::animation::bone_names::crc_compare_predicate>(
      (vostok::animation::bone_name_index *)v15,
      v10,
      0,
      2 * i,
      (vostok::animation::bone_name_index *)processor.rem_);
    stlp_std::priv::__final_insertion_sort<vostok::animation::bone_name_index *,vostok::animation::bone_names::crc_compare_predicate>(
      (vostok::animation::bone_name_index *)v15,
      (vostok::animation::bone_names::crc_compare_predicate)v4,
      v10,
      (vostok::animation::bone_name_index *)processor.rem_);
    v4 = this;
  }
  v13 = 0;
  if ( v4->m_bone_count )
  {
    v14 = 0;
    do
    {
      ++v13;
      qmemcpy((char *)&this[v14] + this->m_internal_memory_position, &v15[v14 * 8], 0x48u);
      v14 += 9;
    }
    while ( v13 < this->m_bone_count );
  }
}
