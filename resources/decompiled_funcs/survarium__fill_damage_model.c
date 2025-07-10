void __usercall survarium::fill_damage_model(
        float a1@<xmm0>,
        survarium::game_camera *model,
        vostok::memory::stack_allocator *allocator,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *model_value,
        vostok::configs::binary_config_value *damage_groups)
{
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::configs::binary_config_value *v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // esi
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  const vostok::variant<32> **v11; // eax
  const vostok::configs::binary_config_value *v12; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v13; // ecx
  const vostok::variant<32> **v14; // eax
  survarium::game_camera *v15; // ecx
  survarium::body_part_parameters *body_part; // [esp+50h] [ebp-20h]
  const vostok::configs::binary_config_value *it_part; // [esp+54h] [ebp-1Ch]
  const vostok::configs::binary_config_value *it_part_end; // [esp+58h] [ebp-18h]
  unsigned __int8 i; // [esp+5Eh] [ebp-12h]
  unsigned __int8 damage_group; // [esp+5Fh] [ebp-11h]
  survarium::body_part_parameters *new_body_part; // [esp+64h] [ebp-Ch]
  survarium::game_camera *it_model; // [esp+68h] [ebp-8h]
  vostok::configs::binary_config_value *it_modela; // [esp+68h] [ebp-8h]
  const vostok::configs::binary_config_value *it_model_end; // [esp+6Ch] [ebp-4h]

  it_model = (survarium::game_camera *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(model_value);
  it_model_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)model_value);
  while ( it_model != (survarium::game_camera *)it_model_end )
  {
    damage_group = -1;
    survarium::weapon_user_dead_state::finalize(it_model);
    for ( i = 0; i != vostok::configs::binary_config_value::size(damage_groups); ++i )
    {
      v5 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](damage_groups, i);
      it_part = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v5);
      v6 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](damage_groups, i);
      it_part_end = vostok::configs::binary_config_value::end(v6);
      while ( it_part != it_part_end )
      {
        v7 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)it_model, "name");
        v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)v7);
        v11 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)it_part);
        if ( vostok::strings::equal((const char *)v11, (const char *)v9) )
        {
          damage_group = i;
          break;
        }
        ++it_part;
      }
    }
    new_body_part = survarium::create_body_part_parameters(
                      model,
                      a1,
                      allocator,
                      (vostok::configs::binary_config_value *)it_model,
                      (survarium::damage_model *)model,
                      damage_group);
    survarium::damage_model::add_body_part((survarium::damage_model *)model, (survarium::game_camera *)new_body_part);
    it_model = (survarium::game_camera *)((char *)it_model + 24);
  }
  for ( it_modela = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(model_value);
        it_modela != it_model_end;
        ++it_modela )
  {
    v12 = vostok::configs::binary_config_value::operator[](it_modela, "name");
    v14 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v13, (int)v12);
    body_part = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(
                                                     (survarium::damage_model *)model,
                                                     (const char *)v14);
    survarium::weapon_user_dead_state::finalize(v15);
    survarium::fill_body_part_parameters(a1, body_part, (survarium::damage_model *const)model, allocator, it_modela);
  }
}
