void __thiscall vostok::collision::initialize(vostok::collision::collision_cook *ecx0)
{
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    vostok::collision::collision_cook::collision_cook(ecx0);
    atexit(vostok::collision::initialize_::_2_::_dynamic_atexit_destructor_for__collision_cooker__);
  }
  vostok::resources::resources_manager::register_cook(&collision_cooker);
}
