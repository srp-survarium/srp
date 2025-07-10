void __thiscall survarium::bullet_manager::add_decal_impl(
        survarium::bullet_manager *this,
        survarium::bullet_manager::bullet_functor *const functor)
{
  survarium::bullet_manager::add_decal_impl(
    this,
    &functor->resource,
    functor->size,
    &functor->position,
    &functor->direction,
    &functor->normal,
    functor->is_front_face);
}
