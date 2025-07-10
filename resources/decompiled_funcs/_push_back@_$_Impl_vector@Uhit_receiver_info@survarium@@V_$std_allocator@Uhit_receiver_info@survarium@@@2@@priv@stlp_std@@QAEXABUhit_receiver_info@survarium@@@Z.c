void __thiscall stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::push_back(
        stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info> > *this,
        const survarium::hit_receiver_info *__x)
{
  stlp_std::__true_type __formal; // [esp+Fh] [ebp-1h] BYREF

  if ( this->_M_finish == this->_M_end_of_storage._M_data )
  {
    __formal = 0;
    stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data>>::_M_insert_overflow(
      (stlp_std::priv::_Impl_vector<survarium::game_material_manager_cook::query_ext_data,survarium::std_allocator<survarium::game_material_manager_cook::query_ext_data> > *)this,
      (survarium::game_material_manager_cook::query_ext_data *)this->_M_finish,
      (const survarium::game_material_manager_cook::query_ext_data *)__x,
      &__formal,
      1u,
      1);
  }
  else
  {
    stlp_std::_Copy_Construct<vostok::ai::planning::world_state_property>(
      (vostok::ai::planning::world_state_property *)this->_M_finish,
      (const vostok::ai::planning::world_state_property *)__x);
    ++this->_M_finish;
  }
}
