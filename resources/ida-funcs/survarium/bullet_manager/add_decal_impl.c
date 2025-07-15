void __thiscall survarium::bullet_manager::add_decal_impl(
        survarium::bullet_manager *this,
        survarium::bullet_manager::bullet_functor *const functor)
{
  survarium::bullet_manager::add_decal_impl(
    this,
    functor->target,
    &functor->resource,
    functor->width,
    functor->height,
    &functor->position,
    &functor->direction,
    &functor->normal,
    functor->target_body_idx);
}
