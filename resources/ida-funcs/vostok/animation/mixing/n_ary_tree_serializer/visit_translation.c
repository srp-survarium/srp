void __userpurge vostok::animation::mixing::n_ary_tree_serializer::visit_translation(
        const vostok::math::float3 *translation@<esi>,
        vostok::animation::mixing::n_ary_tree_serializer *this)
{
  vostok::animation::mixing::n_ary_tree_serializer::append(this, translation->x);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, translation->y);
  vostok::animation::mixing::n_ary_tree_serializer::append(this, translation->z);
}
