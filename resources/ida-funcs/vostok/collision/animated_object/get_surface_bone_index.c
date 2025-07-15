unsigned int __usercall vostok::collision::animated_object::get_surface_bone_index@<eax>(
        vostok::collision::animated_object *this@<ecx>,
        const unsigned int surface_id@<eax>)
{
  return *(_DWORD *)(*((_DWORD *)this->m_body->m_shape->m_children.m_data[surface_id].m_childShape[2].__vftable[1].getBoundingSphere
                     + 2)
                   + 104);
}
