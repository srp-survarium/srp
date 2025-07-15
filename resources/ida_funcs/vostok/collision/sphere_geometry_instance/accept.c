void __thiscall vostok::collision::sphere_geometry_instance::accept(
        vostok::collision::sphere_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        vostok::collision::geometry_instance *instance)
{
  instance->visit(instance, dispatcher, this);
}
