void __thiscall vostok::collision::collision_cook::translate_query(
        vostok::collision::collision_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::collision::collision_cook::query_triangle_mesh((survarium::animated_model_instance_cook *)parent, this);
}
