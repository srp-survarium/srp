void __userpurge survarium::game_material_manager_cook::create_game_materials(
        survarium::game_material_manager_cook *this@<ecx>,
        float a2@<xmm0>,
        survarium::game_material_manager *const manager,
        vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *materials_root)
{
  vostok::configs::binary_config_value *v4; // eax
  survarium::game_camera *v5; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  survarium::game_camera *v7; // [esp+0h] [ebp-40h]
  char *left; // [esp+Ch] [ebp-34h]
  int *_Where; // [esp+10h] [ebp-30h]
  survarium::game_material *v10; // [esp+2Ch] [ebp-14h]
  const vostok::configs::binary_config_value *end; // [esp+38h] [ebp-8h]
  vostok::configs::binary_config_value *it; // [esp+3Ch] [ebp-4h]

  vostok::memory::zero<unsigned short,64>((unsigned __int16 (*)[64])survarium::g_material_physics_group);
  it = (vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(materials_root);
  end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)materials_root);
  while ( it != end )
  {
    if ( !vostok::configs::binary_config_value::value_exists(it, "deleted")
      || (v4 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](it, "deleted"),
          !vostok::configs::binary_config_value::operator bool(v4)) )
    {
      _Where = vostok::memory::doug_lea_allocator::malloc_impl(
                 (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                 0x60u);
      v10 = (survarium::game_material *)operator new(0x60u, _Where);
      if ( v10 )
      {
        survarium::game_material::game_material(v10);
        v7 = v5;
      }
      else
      {
        v7 = 0;
      }
      survarium::weapon_user_dead_state::finalize(v7);
      survarium::game_material::load_from_config((survarium::game_material *)v7, a2, it);
      survarium::game_material_manager::add_game_material(manager, (stlp_std::priv::_Rb_tree_node_base *)v7);
      left = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)v7);
      if ( vostok::strings::equal(left, &result.m_buffer[40]) )
        manager->m_default_material_id = LOWORD(v7[1].m_inverted_view_matrix.lines[0].elements[1]);
    }
    ++it;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)it);
  vostok::physics::setup_game_material_groups(survarium::g_material_physics_group, 0x40u);
}
