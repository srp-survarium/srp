bool __usercall bone_crc_predicate::operator()@<al>(
        const vostok::animation::skeleton_bone *const left@<edx>,
        const vostok::animation::skeleton_bone *const right@<eax>)
{
  unsigned int m_sorted_by_id_bone_index; // ecx
  unsigned int v3; // esi

  m_sorted_by_id_bone_index = left->m_sorted_by_id_bone_index;
  v3 = right->m_sorted_by_id_bone_index;
  if ( m_sorted_by_id_bone_index == v3 )
    return vostok::strings::compare(left->m_id, right->m_id) < 0;
  else
    return m_sorted_by_id_bone_index < v3;
}
