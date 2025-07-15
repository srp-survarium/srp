bool __thiscall vostok::resources::resource_base::try_unregister_from_fat_or_from_name_registry(
        vostok::resources::resource_base *this,
        volatile int count_that_allows_unregister)
{
  vostok::resources::base_of_intrusive_base *v2; // eax
  vostok::resources::managed_resource *const v3; // edx

  v2 = vostok::resources::resource_flags::cast_base_of_intrusive_base(this);
  return vostok::resources::base_of_intrusive_base::try_unregister_from_fat_or_from_name_registry<vostok::resources::managed_resource>(
           v3,
           v2,
           count_that_allows_unregister);
}
