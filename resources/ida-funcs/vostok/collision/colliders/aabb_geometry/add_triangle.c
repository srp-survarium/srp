void __userpurge vostok::collision::colliders::aabb_geometry::add_triangle(
        vostok::collision::colliders::aabb_geometry *this@<ecx>,
        int a2@<eax>,
        unsigned int triangle_id)
{
  vostok::buffer_vector<vostok::collision::triangle_result> *v3; // esi
  vostok::collision::triangle_result v4; // [esp+8h] [ebp-Ch] BYREF

  v3 = *(vostok::buffer_vector<vostok::collision::triangle_result> **)(a2 + 76);
  v4.object = *(const vostok::collision::object **)(a2 + 68);
  v4.triangle_id = triangle_id;
  vostok::buffer_vector<vostok::collision::triangle_result>::push_back(v3, &v4);
}
