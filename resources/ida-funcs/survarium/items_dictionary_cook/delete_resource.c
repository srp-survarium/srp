void __thiscall survarium::items_dictionary_cook::delete_resource(
        survarium::items_dictionary_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
    this->m_allocator,
    &resource,
    "survarium::items_dictionary_cook::delete_resource",
    ".\\items_dictionary_cook.cpp",
    0x2Au);
}
