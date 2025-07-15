survarium::hit_type_parameters *__usercall survarium::create_hit_type_parameters@<eax>(
        float absorption@<xmm0>,
        survarium::damage_model *const model,
        vostok::memory::stack_allocator *allocator,
        vostok::configs::binary_config_value *type_value)
{
  vostok::configs::binary_config_value *v4; // eax
  survarium::game_camera *v5; // ecx
  vostok::memory::stack_allocator *v6; // eax
  vostok::configs::binary_config_value *v7; // ecx
  vostok::configs::binary_config_value *v8; // ecx
  vostok::configs::binary_config_value *v9; // ecx
  vostok::sound::encoded_sound_interface *v10; // eax
  int v11; // eax
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v12; // eax
  vostok::configs::binary_config_value *v13; // eax
  vostok::sound::encoded_sound_interface *v14; // eax
  survarium::game_camera *v15; // ecx
  survarium::game_camera *v16; // ecx
  vostok::memory::stack_allocator *v17; // eax
  int v19; // [esp+14h] [ebp-A4h]
  char *v20; // [esp+48h] [ebp-70h]
  char *_Where; // [esp+70h] [ebp-48h]
  float *v22; // [esp+98h] [ebp-20h]
  survarium::hit_type_parameters *v23; // [esp+A0h] [ebp-18h]
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > **body_part; // [esp+A4h] [ebp-14h]
  unsigned int bdb_coeffs_count; // [esp+A8h] [ebp-10h]
  const vostok::configs::binary_config_value *it_bdb_end; // [esp+B0h] [ebp-8h]
  vostok::configs::binary_config_value *it_bdb; // [esp+B4h] [ebp-4h]

  v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](type_value, "bdb_coeff");
  bdb_coeffs_count = vostok::configs::binary_config_value::size(v4);
  survarium::weapon_user_dead_state::finalize(v5);
  _Where = vostok::memory::stack_allocator::malloc_impl(v6, 0x30u);
  v23 = (survarium::hit_type_parameters *)operator new(0x30u, _Where);
  if ( v23 )
  {
    vostok::configs::binary_config_value::operator[](type_value, "reduce");
    vostok::configs::binary_config_value::operator float(v7);
    vostok::configs::binary_config_value::operator[](type_value, "armor");
    vostok::configs::binary_config_value::operator float(v8);
    vostok::configs::binary_config_value::operator[](type_value, "absorption");
    vostok::configs::binary_config_value::operator float(v9);
    v10 = vostok::configs::binary_config_value::key(type_value);
    survarium::hit_type_parameters::hit_type_parameters(
      v23,
      (const char *)v10,
      absorption,
      absorption,
      absorption,
      bdb_coeffs_count);
    v19 = v11;
  }
  else
  {
    v19 = 0;
  }
  v12 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::configs::binary_config_value::operator[](type_value, "bdb_coeff");
  it_bdb = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v12);
  v13 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                  type_value,
                                                  "bdb_coeff");
  it_bdb_end = vostok::configs::binary_config_value::end(v13);
  while ( it_bdb != it_bdb_end )
  {
    v14 = vostok::configs::binary_config_value::key(it_bdb);
    body_part = survarium::damage_model::get_body_part(model, (const char *)v14);
    survarium::weapon_user_dead_state::finalize(v15);
    survarium::weapon_user_dead_state::finalize(v16);
    v20 = vostok::memory::stack_allocator::malloc_impl(v17, 8u);
    v22 = (float *)operator new(8u, v20);
    if ( v22 )
    {
      *(_DWORD *)v22 = body_part;
      vostok::configs::binary_config_value::operator float((vostok::configs::binary_config_value *)body_part);
      v22[1] = absorption;
    }
    ++it_bdb;
  }
  return (survarium::hit_type_parameters *)v19;
}
