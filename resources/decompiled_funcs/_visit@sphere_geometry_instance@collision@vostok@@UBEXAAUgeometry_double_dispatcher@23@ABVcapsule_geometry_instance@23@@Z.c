void __thiscall vostok::collision::sphere_geometry_instance::visit(
        vostok::collision::sphere_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        const vostok::collision::capsule_geometry_instance *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}
