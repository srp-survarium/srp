void __userpurge vostok::collision::colliders::cuboid_object::cuboid_object(
        const vostok::collision::loose_oct_tree *tree@<eax>,
        vostok::math::cuboid *cuboid@<ecx>,
        bool a3@<bl>,
        vostok::collision::colliders::cuboid_object *this,
        unsigned int query_type,
        boost::function<void __cdecl(vostok::collision::object const &)> *callback)
{
  this->m_tree = tree;
  this->m_objects = 0;
  this->m_triangles = 0;
  this->m_cuboid = cuboid;
  this->m_callback = callback;
  this->m_query_type = query_type;
  vostok::collision::colliders::cuboid_object::process((vostok::collision::colliders::cuboid_object *)cuboid, a3, this);
}
