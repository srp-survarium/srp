survarium::game_material_manager_cook::query_ext_data *__thiscall stlp_std::priv::_STLP_alloc_proxy<survarium::hit_receiver_info *,survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::allocate(
        stlp_std::priv::_STLP_alloc_proxy<survarium::game_material_manager_cook::query_ext_data *,survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *this,
        unsigned int __n,
        unsigned int *__allocated_n)
{
  const unsigned int *v3; // eax
  unsigned int __a; // [esp+4h] [ebp-10h] BYREF
  unsigned int __b; // [esp+Ch] [ebp-8h] BYREF
  char v7; // [esp+13h] [ebp-1h]

  v7 = 0;
  *__allocated_n = __n;
  __a = __n;
  __b = 1;
  v3 = stlp_std::max<unsigned int>(&__a, &__b);
  return (survarium::game_material_manager_cook::query_ext_data *)vostok::memory::doug_lea_allocator::realloc_impl(
                                                                    (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                                                                    0,
                                                                    12 * *v3);
}
