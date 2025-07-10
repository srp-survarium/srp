void __thiscall survarium::base_player::tick_active_object(survarium::base_player *this)
{
  bool v1; // al
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  survarium::engine *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  vostok::render::skeleton_model_instance *v6; // esi
  vostok::render::skeleton_model_instance *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::resources::resource_ptr<survarium::damage_model,vostok::resources::unmanaged_intrusive_base> *v9; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v10; // ecx
  bool v11; // al
  const vostok::variant<32> **v12; // eax
  survarium::inventory *v13; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v14; // ecx
  const vostok::variant<32> **v15; // eax
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> *v16; // eax
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v17; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v18; // ecx
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v19; // ecx
  const vostok::variant<32> **v20; // eax
  survarium::profile_slot_enum v21; // [esp-8h] [ebp-68h]
  const vostok::variant<32> **v22; // [esp+4h] [ebp-5Ch]
  const survarium::weapon_core *v23; // [esp+8h] [ebp-58h]
  const vostok::variant<32> **v24; // [esp+Ch] [ebp-54h]
  const vostok::variant<32> **v25; // [esp+10h] [ebp-50h]
  const vostok::variant<32> **v26; // [esp+14h] [ebp-4Ch]
  const vostok::variant<32> **v27; // [esp+18h] [ebp-48h]
  const vostok::variant<32> **v28; // [esp+1Ch] [ebp-44h]
  const vostok::variant<32> **v29; // [esp+20h] [ebp-40h]
  const vostok::variant<32> **v30; // [esp+24h] [ebp-3Ch]
  const vostok::variant<32> **v32; // [esp+34h] [ebp-2Ch]
  vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base> another_item; // [esp+4Ch] [ebp-14h] BYREF
  survarium::profile_slot_enum another_weapon_slot_id; // [esp+50h] [ebp-10h]
  const survarium::weapon_core *another_weapon; // [esp+54h] [ebp-Ch]
  unsigned __int8 broken_hands_count; // [esp+5Bh] [ebp-5h]
  const survarium::weapon_core *current_weapon; // [esp+5Ch] [ebp-4h]

  v30 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
          (int)&this->m_current_active_object);
  ((void (__thiscall *)(const vostok::variant<32> **))(*v30)->m_helper)(v30);
  v1 = vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::operator!=(
         (const stlp_std::reverse_iterator<unsigned int *> *)&this->m_current_active_object,
         (const stlp_std::reverse_iterator<unsigned int *> *)&this->m_target_active_object);
  if ( v1 )
  {
    v29 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v1,
            (int)&this->m_current_active_object);
    if ( ((unsigned __int8 (__thiscall *)(const vostok::variant<32> **))(*v29)->m_type_id)(v29) )
    {
      this->on_before_active_object_changed(this, &this->m_current_active_object, &this->m_target_active_object);
      v28 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v2,
              (int)&this->m_current_active_object);
      (*(void (__thiscall **)(const vostok::variant<32> **))&(*v28)->m_storage[24])(v28);
      vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
        (vostok::resources::resource_ptr<vostok::animation::skeleton,vostok::resources::unmanaged_intrusive_base> *)&this->m_target_active_object,
        &this->m_current_active_object.m_object);
      v27 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v3,
              (int)&this->m_current_active_object);
      v4 = this->get_engine(this);
      (*(void (__thiscall **)(const vostok::variant<32> **, survarium::base_player *, survarium::engine *))&(*v27)->m_storage[20])(
        v27,
        this,
        v4);
      v26 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
              v5,
              (int)&this->m_current_active_object);
      ((void (__thiscall *)(const vostok::variant<32> **))(*v26)->m_helper)(v26);
    }
  }
  v6 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_target_active_object);
  v7 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_current_active_object);
  v8 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)(v7 == v6);
  if ( v7 == v6 )
  {
    v25 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
            v8,
            (int)&this->m_current_active_object);
    current_weapon = (const survarium::weapon_core *)(*(int (__thiscall **)(const vostok::variant<32> **))&(*v25)[1].m_storage[28])(v25);
    if ( current_weapon )
    {
      v9 = this->damage_model(this);
      v32 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v10, (int)v9);
      v8 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)(*((unsigned __int8 *)v32 + 827) + *((unsigned __int8 *)v32 + 826));
      broken_hands_count = *((_BYTE *)v32 + 827) + *((_BYTE *)v32 + 826);
      if ( broken_hands_count )
      {
        v11 = survarium::weapon_core::could_be_used(current_weapon, this);
        v8 = (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)v11;
        if ( !v11 )
        {
          v12 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  0,
                  (int)&this->m_inventory);
          another_weapon_slot_id = survarium::inventory::get_active_slot(v13, (int)v12) != weapon1_slot
                                 ? weapon1_slot
                                 : weapon2_slot;
          v15 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                  v14,
                  (int)&this->m_inventory);
          v16 = survarium::inventory::item_in_slot((survarium::inventory *)another_weapon_slot_id, (int)v15);
          vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
            (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v16,
            (survarium::inventory **)&another_item);
          if ( vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator survarium::inventory_item * (__thiscall vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::*)(void)const(
                 v17,
                 &another_item) )
          {
            v24 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                    v18,
                    (int)&another_item);
            v23 = (const survarium::weapon_core *)(*(int (__thiscall **)(const vostok::variant<32> **))&(*v24)[1].m_storage[28])(v24);
          }
          else
          {
            v23 = 0;
          }
          another_weapon = v23;
          if ( v23 && survarium::weapon_core::could_be_used(another_weapon, this) )
          {
            v21 = another_weapon_slot_id;
            v20 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                    v19,
                    (int)&this->m_inventory);
            survarium::inventory::action((survarium::inventory *)v20, v21, 1);
          }
          vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&another_item);
        }
      }
    }
  }
  v22 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
          v8,
          (int)&this->m_current_active_object);
  (*(void (__thiscall **)(const vostok::variant<32> **))&(*v22)[1].m_storage[28])(v22);
}
