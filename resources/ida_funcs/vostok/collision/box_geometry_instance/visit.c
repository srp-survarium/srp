void __thiscall vostok::collision::box_geometry_instance::visit(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        const vostok::collision::box_geometry_instance *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::collision::box_geometry_instance::visit(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        const vostok::collision::capsule_geometry_instance *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::collision::box_geometry_instance::visit(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        const vostok::collision::cylinder_geometry_instance *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::collision::box_geometry_instance::visit(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        const vostok::collision::sphere_geometry_instance *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}


void __thiscall vostok::collision::box_geometry_instance::visit(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::geometry_double_dispatcher *dispatcher,
        const vostok::collision::truncated_sphere_geometry_instance *node)
{
  dispatcher->dispatch(dispatcher, node, this);
}
