survarium::affects_threshold *__usercall survarium::create_threshold@<eax>(
        float value@<xmm0>,
        vostok::memory::stack_allocator *allocator,
        vostok::configs::binary_config_value *threshold_value,
        survarium::damage_model *const model)
{
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  vostok::memory::stack_allocator *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  int v10; // eax
  survarium::game_camera *v11; // ecx
  vostok::memory::stack_allocator *v12; // eax
  int v14; // [esp+10h] [ebp-98h]
  char *v15; // [esp+14h] [ebp-94h]
  char *_Where; // [esp+4Ch] [ebp-5Ch]
  const vostok::variant<32> ***v17; // [esp+64h] [ebp-44h]
  survarium::affects_threshold *v18; // [esp+68h] [ebp-40h]
  const vostok::variant<32> **type; // [esp+74h] [ebp-34h]
  const vostok::configs::binary_config_value *it_affect_end; // [esp+78h] [ebp-30h]
  survarium::body_part_parameters *bodypart; // [esp+7Ch] [ebp-2Ch]
  const char *bodypart_name; // [esp+84h] [ebp-24h]
  unsigned int affects_count; // [esp+88h] [ebp-20h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *it_affect; // [esp+8Ch] [ebp-1Ch]
  vostok::configs::binary_config_value affects_table; // [esp+90h] [ebp-18h] BYREF

  affects_table = *vostok::configs::binary_config_value::operator[](threshold_value, "affects");
  affects_count = vostok::configs::binary_config_value::size(&affects_table);
  v4 = vostok::configs::binary_config_value::operator[](threshold_value, "target_bodypart");
  bodypart_name = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                  v5,
                                  (int)v4);
  bodypart = (survarium::body_part_parameters *)survarium::damage_model::get_body_part(model, bodypart_name);
  survarium::weapon_user_dead_state::finalize(v6);
  survarium::weapon_user_dead_state::finalize(v7);
  _Where = vostok::memory::stack_allocator::malloc_impl(v8, 0x10u);
  v18 = (survarium::affects_threshold *)operator new(0x10u, _Where);
  if ( v18 )
  {
    vostok::configs::binary_config_value::operator[](threshold_value, (char *)&stru_955964);
    vostok::configs::binary_config_value::operator float(v9);
    survarium::affects_threshold::affects_threshold(v18, value, affects_count, bodypart);
    v14 = v10;
  }
  else
  {
    v14 = 0;
  }
  it_affect = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&affects_table);
  it_affect_end = vostok::configs::binary_config_value::end(&affects_table);
  while ( it_affect != (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it_affect_end )
  {
    type = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
             it_affect,
             (int)it_affect);
    survarium::weapon_user_dead_state::finalize(v11);
    v15 = vostok::memory::stack_allocator::malloc_impl(v12, 4u);
    v17 = (const vostok::variant<32> ***)operator new(4u, v15);
    if ( v17 )
      *v17 = type;
    it_affect += 2;
  }
  return (survarium::affects_threshold *)v14;
}
