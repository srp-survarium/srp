void __usercall set_animation_user_data(
        vostok::animation::mixing::n_ary_tree_animation_node *n_ary_animation@<edx>,
        const vostok::animation::mixing::binary_tree_animation_node *binary_animation@<eax>)
{
  n_ary_animation->user_data = binary_animation->user_data;
}
