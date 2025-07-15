void __usercall stlp_std::vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<void *>>::push_back(
        stlp_std::vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<void *> > *this@<ecx>,
        int a2@<eax>)
{
  vostok::physics::closest_ray_result *v2; // edi
  unsigned int v3; // [esp+0h] [ebp-8h]
  bool v4; // [esp+4h] [ebp-4h]

  v2 = *(vostok::physics::closest_ray_result **)(a2 + 4);
  if ( v2 == *(vostok::physics::closest_ray_result **)(a2 + 12) )
  {
    stlp_std::priv::_Impl_vector<vostok::physics::closest_ray_result,vostok::vectora_allocator<vostok::physics::closest_ray_result>>::_M_insert_overflow(
      &this->_M_impl,
      a2,
      v2,
      (const stlp_std::__true_type *)this,
      v3,
      v4);
  }
  else
  {
    if ( v2 )
      qmemcpy(v2, this, sizeof(vostok::physics::closest_ray_result));
    *(_DWORD *)(a2 + 4) += 40;
  }
}


void __usercall stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::push_back(
        stlp_std::vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *this@<ecx>,
        unsigned int a2@<eax>)
{
  survarium::relocate_item_descr *v2; // edi
  survarium::relocate_item_descr **p_item_dict_id; // edi
  unsigned int v4; // [esp+0h] [ebp-Ch]
  bool v5; // [esp+4h] [ebp-8h]

  v2 = *(survarium::relocate_item_descr **)(a2 + 4);
  if ( v2 == *(survarium::relocate_item_descr **)(a2 + 8) )
  {
    stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr>>::_M_insert_overflow(
      &this->_M_impl,
      a2,
      v2,
      (const stlp_std::__true_type *)this,
      v4,
      v5);
  }
  else
  {
    if ( v2 )
    {
      v2->item_id = (unsigned int)this->_M_impl._M_start;
      p_item_dict_id = (survarium::relocate_item_descr **)&v2->item_dict_id;
      *p_item_dict_id++ = this->_M_impl._M_finish;
      *p_item_dict_id = this->_M_impl._M_end_of_storage._M_data;
      p_item_dict_id[1] = this[1]._M_impl._M_start;
    }
    *(_DWORD *)(a2 + 4) += 16;
  }
}
