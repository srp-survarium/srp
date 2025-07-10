unsigned int __usercall vostok::animation::bone_names::bone_index@<eax>(
        vostok::animation::bone_names *this@<esi>,
        char *name@<eax>)
{
  const vostok::animation::bone_name_index *v3; // eax
  unsigned int v5; // [esp+0h] [ebp-54h]
  vostok::animation::bone_name_index temp; // [esp+8h] [ebp-4Ch] BYREF

  vostok::animation::bone_name_index::bone_name_index(name, &temp, v5);
  v3 = stlp_std::priv::__lower_bound<vostok::animation::bone_name_index const *,vostok::animation::bone_name_index,vostok::animation::bone_names::crc_compare_predicate,vostok::animation::bone_names::crc_compare_predicate,int>(
         (const vostok::animation::bone_name_index *)((char *)this + this->m_internal_memory_position),
         (const vostok::animation::bone_name_index *)((char *)&this[9 * this->m_bone_count]
                                                    + this->m_internal_memory_position),
         &temp);
  if ( temp.crc == v3->crc && *name == v3->name[0] )
    return v3->index;
  else
    return -1;
}
