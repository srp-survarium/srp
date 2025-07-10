void __userpurge vostok::animation::animation_player::set_object_transform(
        const vostok::math::float4x4 *object_transform@<eax>,
        vostok::animation::mixing::n_ary_tree *animated_object@<ecx>,
        vostok::animation::animation_player *this)
{
  vostok::animation::mixing::n_ary_tree::set_object_transform(animated_object, animated_object, object_transform);
}
