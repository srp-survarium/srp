void __userpurge survarium::human_npc_cook::on_npc_options_received(
        survarium::human_npc_cook *this@<ecx>,
        unsigned int a2@<eax>,
        vostok::resources::query_result_for_cook *config_value,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::configs::binary_config_value *v5; // esi
  unsigned int m_size; // edx
  vostok::memory::doug_lea_allocator *v7; // eax
  int *v8; // eax
  int v9; // eax
  vostok::sound::encoded_sound_interface *v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // esi
  void (__cdecl *v15)(char *, char *, int); // eax
  vostok::resources::unmanaged_resource *v16; // eax
  vostok::resources::unmanaged_intrusive_base *v17; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::human_npc_cook,vostok::resources::queries_result &,survarium::human_npc *>,boost::_bi::list3<boost::_bi::value<survarium::human_npc_cook *>,boost::arg<1>,boost::_bi::value<survarium::human_npc *> > > v18; // [esp+5F8h] [ebp-E8h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v19; // [esp+604h] [ebp-DCh]
  int v20; // [esp+608h] [ebp-D8h]
  __int64 v21; // [esp+618h] [ebp-C8h] BYREF
  vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp+620h] [ebp-C0h] BYREF
  unsigned int v23; // [esp+624h] [ebp-BCh]
  const char *pointer; // [esp+628h] [ebp-B8h]
  const void *v25; // [esp+62Ch] [ebp-B4h]
  vostok::variant<32> value; // [esp+630h] [ebp-B0h] BYREF
  vostok::resources::request v27; // [esp+660h] [ebp-80h] BYREF
  const void *v28; // [esp+668h] [ebp-78h]
  int v29; // [esp+66Ch] [ebp-74h]
  const char *v30; // [esp+670h] [ebp-70h]
  int v31; // [esp+674h] [ebp-6Ch]
  vostok::sound::encoded_sound_interface *m_object; // [esp+678h] [ebp-68h]
  int v33; // [esp+67Ch] [ebp-64h]
  _DWORD v34[2]; // [esp+680h] [ebp-60h] BYREF
  int v35[8]; // [esp+688h] [ebp-58h] BYREF
  _DWORD *v36; // [esp+6A8h] [ebp-38h]
  int v37; // [esp+6ACh] [ebp-34h]
  boost::function1<void,vostok::resources::queries_result &> v38; // [esp+6B0h] [ebp-30h] BYREF
  int v39; // [esp+6D8h] [ebp-8h]
  int v40; // [esp+6DCh] [ebp-4h]

  v5 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                 (vostok::configs::binary_config_value *)this,
                                                 "attributes");
  m_size = config_value->m_creation_data_from_user.m_size;
  v22.m_object = (vostok::sound::encoded_sound_interface *)config_value->m_creation_data_from_user.m_data;
  v23 = m_size;
  LODWORD(v21) = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(&v22);
  v7 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  v8 = vostok::memory::doug_lea_allocator::malloc_impl(v7, 0x2E0u);
  if ( v8 )
  {
    survarium::human_npc::human_npc(
      *(survarium::human_npc **)(a2 + 32),
      (survarium::human_npc *)v8,
      *(survarium::game_world **)(a2 + 32));
    HIDWORD(v21) = v9;
  }
  else
  {
    HIDWORD(v21) = 0;
  }
  pointer = (const char *)vostok::configs::binary_config_value::operator[](v5, "brain_unit")->data.pointer;
  v25 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)v21, "model")->data.pointer;
  v10 = (vostok::sound::encoded_sound_interface *)vostok::configs::binary_config_value::operator[](
                                                    v5,
                                                    "animation_space_graph")->data.pointer;
  v11 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 168);
  v22.m_object = v10;
  v12 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v11 + 132) + 8))(*(_DWORD *)(v11 + 132));
  v19 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(a2 + 32) + 156);
  *(_DWORD *)value.m_helper_storage = v12;
  LODWORD(v21) = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v21,
    v19);
  *(_QWORD *)&value.m_helper_storage[4] = v21;
  v39 = 0;
  v40 = 0;
  vostok::variant<32>::set<vostok::ai::brain_unit_cook_params>(
    &value,
    (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v38,
    (const vostok::ai::brain_unit_cook_params *)&value);
  v13 = *(_DWORD *)(a2 + 32);
  v36 = 0;
  v37 = 0;
  v14 = *(_DWORD *)(v13 + 176);
  v37 = vostok::detail::type_to_int<vostok::physics::world *>::get();
  v36 = v34;
  m_object = v22.m_object;
  *(_DWORD *)value.m_helper_storage = survarium::human_npc_cook::on_subresources_loaded;
  *(_DWORD *)&value.m_helper_storage[4] = 0;
  v27.path = pointer;
  v28 = v25;
  *(_QWORD *)value.m_storage = __PAIR64__(HIDWORD(v21), a2);
  v18.f_.f_ = (void (__thiscall *__ptr64)(survarium::human_npc_cook *, vostok::resources::queries_result *, survarium::human_npc *))(unsigned int)survarium::human_npc_cook::on_subresources_loaded;
  v35[0] = v14;
  v34[0] = &vostok::detail::concrete_type_helper<vostok::physics::world *>::`vftable';
  v27.id = brain_unit_class;
  v29 = 103;
  v30 = "resources/animations/single/slot_1/walk/on_site_idle";
  v31 = 61;
  v33 = 96;
  *(_DWORD *)&value.m_storage[24] = &v38;
  *(_DWORD *)&value.m_storage[28] = v34;
  value.m_helper = 0;
  value.m_type_id = 0;
  v18.l_ = (boost::_bi::list3<boost::_bi::value<survarium::human_npc_cook *>,boost::arg<1>,boost::_bi::value<survarium::human_npc *> >)__PAIR64__(HIDWORD(v21), a2);
  boost::function1<void,vostok::resources::queries_result &>::function1<void,vostok::resources::queries_result &>(
    &v38,
    (int)&value,
    v14,
    v18,
    v20);
  vostok::resources::query_resources(
    &v27,
    4u,
    (boost::function4<void,unsigned int,float,float,char const *> *)&value,
    (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_,
    (const vostok::variant<32> **)&value.m_storage[24],
    config_value,
    assert_on_fail_true);
  if ( *(_DWORD *)value.m_helper_storage )
  {
    if ( (value.m_helper_storage[0] & 1) == 0 )
    {
      v15 = *(void (__cdecl **)(char *, char *, int))(*(_DWORD *)value.m_helper_storage & 0xFFFFFFFE);
      if ( v15 )
        v15(value.m_storage, value.m_storage, 2);
    }
  }
  if ( v36 )
  {
    (*(void (__thiscall **)(_DWORD *, int *))(*v36 + 4))(v36, v35);
    v36 = 0;
  }
  if ( v39 )
  {
    (*(void (__thiscall **)(int, boost::detail::function::function_buffer *))(*(_DWORD *)v39 + 4))(v39, &v38.functor);
    v39 = 0;
  }
  v16 = (vostok::resources::unmanaged_resource *)v21;
  if ( (_DWORD)v21 )
  {
    v17 = (vostok::resources::unmanaged_intrusive_base *)(v21 + 208);
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v21 + 208), 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v17, v16);
  }
}
