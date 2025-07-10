vostok::resources::cook_base *__usercall vostok::resources::unregister_cook@<eax>(
        vostok::resources::class_id_enum resource_class@<eax>)
{
  return vostok::resources::resources_manager::unregister_cook(resource_class);
}
