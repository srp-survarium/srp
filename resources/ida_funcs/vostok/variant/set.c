void __thiscall vostok::variant<32>::set<unsigned char>(vostok::variant<32> *this, const unsigned __int8 *value)
{
  vostok::detail::abstract_type_helper *v2; // [esp+0h] [ebp-14h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<unsigned char>::get();
  if ( this != (vostok::variant<32> *)-8 )
    this->m_storage[0] = *value;
  if ( this )
  {
    *(_DWORD *)this->m_helper_storage = &vostok::detail::abstract_type_helper::`vftable';
    *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<unsigned char>::`vftable';
    v2 = (vostok::detail::abstract_type_helper *)this;
  }
  else
  {
    v2 = 0;
  }
  this->m_helper = v2;
}


void __thiscall vostok::variant<32>::set<unsigned short>(vostok::variant<32> *this, const unsigned __int16 *value)
{
  vostok::detail::abstract_type_helper *v2; // ecx
  vostok::detail::abstract_type_helper *v3; // [esp+0h] [ebp-14h]
  vostok::detail::abstract_type_helper *v5; // [esp+Ch] [ebp-8h]
  _WORD *v6; // [esp+10h] [ebp-4h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<unsigned short>::get();
  v6 = operator new(2u, this->m_storage);
  if ( v6 )
    *v6 = *value;
  v5 = (vostok::detail::abstract_type_helper *)operator new(4u, this);
  if ( v5 )
  {
    vostok::detail::abstract_type_helper::abstract_type_helper(v2, v5);
    v5->__vftable = (vostok::detail::abstract_type_helper_vtbl *)&vostok::detail::concrete_type_helper<unsigned short>::`vftable';
    v3 = v5;
  }
  else
  {
    v3 = 0;
  }
  this->m_helper = v3;
}


void __userpurge vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::material_effects_instance_cook_data *const *value)
{
  int v3; // ecx

  v3 = *(_DWORD *)(a2 + 40);
  if ( v3 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 4))(v3, a2 + 8);
    *(_DWORD *)(a2 + 40) = 0;
  }
  *(_DWORD *)(a2 + 44) = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  if ( a2 != -8 )
    *(vostok::render::material_effects_instance_cook_data **)(a2 + 8) = *value;
  *(_DWORD *)(a2 + 40) = a2;
  *(_DWORD *)a2 = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
}


void __usercall vostok::variant<32>::set<vostok::animation::animation_collection_cook_user_data>(
        vostok::variant<32> *this@<esi>,
        const vostok::animation::animation_collection_cook_user_data *value@<eax>)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_helper = this->m_helper;
  if ( m_helper )
  {
    m_helper->destroy(m_helper, this->m_storage);
    this->m_helper = 0;
  }
  this->m_type_id = vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get();
  if ( this != (vostok::variant<32> *)-8 )
  {
    *(_DWORD *)this->m_storage = value->val;
    *(_DWORD *)&this->m_storage[4] = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[4],
      &value->cfg_ptr);
  }
  this->m_helper = (vostok::detail::abstract_type_helper *)this;
  *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::`vftable';
}


void __userpurge vostok::variant<32>::set<vostok::ai::behaviour_cook_params>(
        vostok::variant<32> *this@<ecx>,
        vostok::ai::behaviour_cook_params *a2@<esi>,
        const vostok::ai::behaviour_cook_params *value)
{
  const vostok::configs::binary_config_value *behaviour_config; // ecx

  behaviour_config = a2[10].behaviour_config;
  if ( behaviour_config )
  {
    (*((void (__thiscall **)(const vostok::configs::binary_config_value *, vostok::ai::behaviour_cook_params *))behaviour_config->data.pointer
     + 1))(
      behaviour_config,
      a2 + 2);
    a2[10].behaviour_config = 0;
  }
  a2[11].behaviour_config = (const vostok::configs::binary_config_value *)vostok::detail::type_to_int<vostok::ai::behaviour_cook_params>::get();
  if ( a2 != (vostok::ai::behaviour_cook_params *)-8 )
    a2[2].behaviour_config = value->behaviour_config;
  a2[10].behaviour_config = (const vostok::configs::binary_config_value *)a2;
  a2->behaviour_config = (const vostok::configs::binary_config_value *)&vostok::detail::concrete_type_helper<vostok::ai::behaviour_cook_params>::`vftable';
}


void __thiscall vostok::variant<32>::set<survarium::booby_trap_set_cook_data>(
        vostok::variant<32> *this,
        const survarium::booby_trap_set_cook_data *value)
{
  vostok::detail::abstract_type_helper *v2; // ecx
  vostok::detail::abstract_type_helper *v3; // [esp+0h] [ebp-14h]
  vostok::detail::abstract_type_helper *v5; // [esp+Ch] [ebp-8h]
  survarium::booby_trap_set_cook_data *v6; // [esp+10h] [ebp-4h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<survarium::booby_trap_set_cook_data>::get();
  v6 = (survarium::booby_trap_set_cook_data *)operator new(2u, this->m_storage);
  if ( v6 )
    *v6 = *value;
  v5 = (vostok::detail::abstract_type_helper *)operator new(4u, this);
  if ( v5 )
  {
    vostok::detail::abstract_type_helper::abstract_type_helper(v2, v5);
    v5->__vftable = (vostok::detail::abstract_type_helper_vtbl *)&vostok::detail::concrete_type_helper<survarium::booby_trap_set_cook_data>::`vftable';
    v3 = v5;
  }
  else
  {
    v3 = 0;
  }
  this->m_helper = v3;
}


void __userpurge vostok::variant<32>::set<vostok::ai::brain_unit_cook_params>(
        vostok::variant<32> *this@<ecx>,
        vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<esi>,
        const vostok::ai::brain_unit_cook_params *value)
{
  vostok::configs::binary_config *m_object; // ecx

  m_object = a2[10].m_object;
  if ( m_object )
  {
    m_object->log_string(m_object, (vostok::fixed_string<512> *)&a2[2]);
    a2[10].m_object = 0;
  }
  a2[11].m_object = (vostok::configs::binary_config *)vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::get();
  if ( a2 != (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)-8 )
  {
    a2[2].m_object = (vostok::configs::binary_config *)value->sound_world_user;
    a2[3].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      a2 + 3,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->sound_scene);
    a2[4].m_object = (vostok::configs::binary_config *)value->npc;
  }
  a2[10].m_object = (vostok::configs::binary_config *)a2;
  a2->m_object = (vostok::configs::binary_config *)&vostok::detail::concrete_type_helper<vostok::ai::brain_unit_cook_params>::`vftable';
}


void __thiscall vostok::variant<32>::set<vostok::sound::sound_collection_cook_user_data>(
        vostok::variant<32> *this,
        const vostok::sound::sound_collection_cook_user_data *value)
{
  vostok::detail::abstract_type_helper *v2; // [esp+0h] [ebp-24h]

  vostok::variant<32>::~variant<32>(this);
  this->m_type_id = vostok::detail::type_to_int<vostok::sound::sound_collection_cook_user_data>::get();
  if ( this != (vostok::variant<32> *)-8 )
  {
    *(_DWORD *)this->m_storage = value->val;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&this->m_storage[4],
      &value->cfg_ptr);
  }
  if ( this )
  {
    *(_DWORD *)this->m_helper_storage = &vostok::detail::abstract_type_helper::`vftable';
    *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::`vftable';
    v2 = (vostok::detail::abstract_type_helper *)this;
  }
  else
  {
    v2 = 0;
  }
  this->m_helper = v2;
}


void __usercall vostok::variant<32>::set<vostok::render::static_model_instance_user_data>(
        vostok::variant<32> *this@<esi>,
        const vostok::render::static_model_instance_user_data *value@<eax>)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_helper = this->m_helper;
  if ( m_helper )
  {
    m_helper->destroy(m_helper, this->m_storage);
    this->m_helper = 0;
  }
  this->m_type_id = vostok::detail::type_to_int<vostok::render::static_model_instance_user_data>::get();
  if ( this != (vostok::variant<32> *)-8 )
  {
    *(_DWORD *)this->m_storage = value->config;
    *(_DWORD *)&this->m_storage[4] = value->sound_world;
    *(_DWORD *)&this->m_storage[8] = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[8],
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&value->sound_scene);
  }
  this->m_helper = (vostok::detail::abstract_type_helper *)this;
  *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::`vftable';
}


void __usercall vostok::variant<32>::set<vostok::configs::binary_config_value>(
        vostok::variant<32> *this@<esi>,
        const vostok::configs::binary_config_value *value@<edi>)
{
  vostok::detail::abstract_type_helper *m_helper; // ecx

  m_helper = this->m_helper;
  if ( m_helper )
  {
    m_helper->destroy(m_helper, this->m_storage);
    this->m_helper = 0;
  }
  this->m_type_id = vostok::detail::type_to_int<vostok::configs::binary_config_value>::get();
  if ( this != (vostok::variant<32> *)-8 )
    *(vostok::configs::binary_config_value *)this->m_storage = *value;
  this->m_helper = (vostok::detail::abstract_type_helper *)this;
  *(_DWORD *)this->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::configs::binary_config_value>::`vftable';
}
