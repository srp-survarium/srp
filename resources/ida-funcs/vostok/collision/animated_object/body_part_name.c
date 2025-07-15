char *__usercall vostok::collision::animated_object::body_part_name@<eax>(
        vostok::collision::animated_object *this@<ecx>,
        const unsigned int bone_index@<eax>)
{
  return this->m_geometries_data.m_begin[bone_index].body_part_name.m_begin;
}
