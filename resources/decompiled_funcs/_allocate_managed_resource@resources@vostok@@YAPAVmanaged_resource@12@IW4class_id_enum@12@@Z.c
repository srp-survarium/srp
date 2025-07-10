vostok::resources::managed_resource *__cdecl vostok::resources::allocate_managed_resource(
        vostok::resources::resources_manager *size,
        vostok::resources::class_id_enum class_id)
{
  return vostok::resources::resources_manager::allocate_managed_resource(size, (unsigned int)size, class_id);
}
