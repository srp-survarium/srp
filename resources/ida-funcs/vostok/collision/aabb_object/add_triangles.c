void __thiscall vostok::collision::aabb_object::add_triangles(
        vostok::collision::aabb_object *this,
        vostok::buffer_vector<vostok::collision::triangle_result> *triangles)
{
  vostok::collision::triangle_result value; // [esp+8h] [ebp-8h] BYREF

  value.triangle_id = -1;
  value.object = this;
  vostok::buffer_vector<vostok::collision::triangle_result>::push_back(triangles, &value);
}
