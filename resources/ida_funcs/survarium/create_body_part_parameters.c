survarium::body_part_parameters *__usercall survarium::create_body_part_parameters@<eax>(
        survarium::game_camera *a1@<ecx>,
        float health@<xmm0>,
        vostok::memory::stack_allocator *allocator,
        vostok::configs::binary_config_value *part_value,
        survarium::damage_model *model,
        unsigned __int8 damage_group)
{
  vostok::memory::stack_allocator *v6; // eax
  vostok::configs::binary_config_value *v7; // eax
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::configs::binary_config_value *v10; // ecx
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  const vostok::variant<32> **v13; // eax
  int v14; // eax
  bool v16; // [esp+Ch] [ebp-58h]
  char *_Where; // [esp+54h] [ebp-10h]
  survarium::body_part_parameters *v19; // [esp+5Ch] [ebp-8h]

  survarium::weapon_user_dead_state::finalize(a1);
  _Where = vostok::memory::stack_allocator::malloc_impl(v6, 0xB8u);
  v19 = (survarium::body_part_parameters *)operator new(0xB8u, _Where);
  if ( !v19 )
    return 0;
  v7 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 part_value,
                                                 "can_be_assigned");
  v16 = vostok::configs::binary_config_value::operator bool(v7);
  vostok::configs::binary_config_value::operator[](part_value, "regeneration_timeout");
  vostok::configs::binary_config_value::operator float(v8);
  vostok::configs::binary_config_value::operator[](part_value, "regeneration_speed");
  vostok::configs::binary_config_value::operator float(v9);
  vostok::configs::binary_config_value::operator[](part_value, "health");
  vostok::configs::binary_config_value::operator float(v10);
  v11 = vostok::configs::binary_config_value::operator[](part_value, "name");
  v13 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v12, (int)v11);
  survarium::body_part_parameters::body_part_parameters(
    v19,
    (const char *)v13,
    health,
    health,
    health,
    v16,
    model,
    damage_group);
  return (survarium::body_part_parameters *)v14;
}
