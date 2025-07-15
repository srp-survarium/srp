void __userpurge vostok::collision::colliders::aabb_object::aabb_object(
        const vostok::math::aabb *aabb@<eax>,
        vostok::vectora<vostok::collision::object const *> *objects@<ecx>,
        bool a3@<bpl>,
        vostok::collision::colliders::aabb_object *this,
        unsigned int query_type,
        const vostok::collision::loose_oct_tree *tree)
{
  this->m_aabb = aabb;
  this->m_objects = objects;
  this->m_triangles = 0;
  this->m_tree = tree;
  this->m_query_type = query_type;
  vostok::collision::colliders::aabb_object::process((vostok::collision::colliders::aabb_object *)objects, a3, this);
}


void __userpurge vostok::collision::colliders::aabb_object::aabb_object(
        const vostok::math::aabb *aabb@<eax>,
        vostok::vectora<vostok::collision::triangle_result> *triangles@<ecx>,
        bool a3@<bpl>,
        vostok::collision::colliders::aabb_object *this,
        unsigned int query_type,
        const vostok::collision::loose_oct_tree *tree)
{
  this->m_aabb = aabb;
  this->m_objects = 0;
  this->m_triangles = triangles;
  this->m_tree = tree;
  this->m_query_type = query_type;
  vostok::collision::colliders::aabb_object::process((vostok::collision::colliders::aabb_object *)triangles, a3, this);
}
