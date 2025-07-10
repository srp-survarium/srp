void __userpurge vostok::collision::aabb_object::aabb_object(
        vostok::collision::aabb_object *this@<esi>,
        const vostok::math::aabb *aabb@<edi>,
        vostok::collision::object *a3@<ecx>,
        unsigned int object_type,
        void *user_data)
{
  vostok::collision::object::object(a3, (int)this);
  this->m_type = object_type;
  this->__vftable = (vostok::collision::aabb_object_vtbl *)&vostok::collision::aabb_object::`vftable';
  this->m_user_data = user_data;
  this->m_aabb = *aabb;
}
