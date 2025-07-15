void __userpurge survarium::victory_item_core::initialize_logic(
        survarium::victory_item_core *this@<ecx>,
        survarium::victory_item_core *a2@<eax>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *take_animations,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *take_animations_count,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *take_time,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *carry_animations,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *carry_animations_count,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *put_animations,
        const unsigned int put_animations_count,
        const float put_time)
{
  vostok::memory::doug_lea_allocator *v10; // esi
  char *v12; // eax
  vostok::memory::doug_lea_allocator *v13; // ecx
  char *v14; // eax
  vostok::ai::fsm *v15; // ebx
  vostok::ai::fsm *v16; // eax
  vostok::memory::doug_lea_allocator *v17; // esi
  char *v18; // eax
  vostok::memory::doug_lea_allocator *v19; // ecx
  char *v20; // eax
  vostok::ai::fsm *v21; // eax
  vostok::memory::doug_lea_allocator *v22; // esi
  char *v23; // eax
  vostok::memory::doug_lea_allocator *v24; // ecx
  char *v25; // eax
  vostok::ai::fsm *v26; // eax
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  boost::function<bool __cdecl(void)> *v29; // ecx
  vostok::ai::fsm *v30; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v31; // ecx
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v32; // ecx
  const char *v33; // [esp+4h] [ebp-58h]
  const char *v34; // [esp+4h] [ebp-58h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v35; // [esp+4h] [ebp-58h]
  unsigned int v36; // [esp+4h] [ebp-58h]
  const char *v37; // [esp+8h] [ebp-54h]
  const char *v38; // [esp+8h] [ebp-54h]
  const char *v39; // [esp+8h] [ebp-54h]
  float v40; // [esp+8h] [ebp-54h]
  unsigned int v41; // [esp+Ch] [ebp-50h]
  unsigned int v42; // [esp+Ch] [ebp-50h]
  unsigned int v43; // [esp+Ch] [ebp-50h]
  vostok::ai::fsm *v44; // [esp+14h] [ebp-48h]
  vostok::ai::fsm *v45; // [esp+18h] [ebp-44h]
  boost::function<bool __cdecl(void)> v46; // [esp+1Ch] [ebp-40h] BYREF
  boost::function<bool __cdecl(void)> transition_predicate; // [esp+3Ch] [ebp-20h] BYREF

  v10 = survarium::g_allocator;
  v12 = type_info::raw_name(&survarium::victory_item_core_take_state `RTTI Type Descriptor');
  v14 = vostok::memory::doug_lea_allocator::malloc_impl(v13, (int)v10, 0x50u, v12, v33, v37, v41);
  v15 = 0;
  if ( v14 )
  {
    survarium::victory_item_core_take_state::victory_item_core_take_state(
      (survarium::victory_item_core_take_state *)v14,
      a2,
      take_animations,
      take_animations_count,
      (unsigned int)v34,
      *(const float *)&v38);
    v45 = v16;
  }
  else
  {
    v45 = 0;
  }
  v17 = survarium::g_allocator;
  v18 = type_info::raw_name(&survarium::victory_item_core_carry_state `RTTI Type Descriptor');
  v20 = vostok::memory::doug_lea_allocator::malloc_impl(v19, (int)v17, 0x44u, v18, v34, v38, v42);
  if ( v20 )
  {
    survarium::victory_item_core_carry_state::victory_item_core_carry_state(
      (survarium::victory_item_core_carry_state *)v20,
      a2,
      take_time,
      v35,
      (unsigned int)v39);
    v44 = v21;
  }
  else
  {
    v44 = 0;
  }
  v22 = survarium::g_allocator;
  v23 = type_info::raw_name(&survarium::victory_item_core_put_state `RTTI Type Descriptor');
  v25 = vostok::memory::doug_lea_allocator::malloc_impl(v24, (int)v22, 0x50u, v23, (const char *const)v35, v39, v43);
  if ( v25 )
  {
    survarium::victory_item_core_put_state::victory_item_core_put_state(
      (survarium::victory_item_core_put_state *)v25,
      a2,
      carry_animations,
      carry_animations_count,
      v36,
      v40);
    v15 = v26;
  }
  vostok::ai::fsm::add_state(v45, &a2->m_logic.m_states.m_size);
  vostok::ai::fsm::add_state(v44, v27);
  vostok::ai::fsm::add_state(v15, v28);
  boost::function<bool __cdecl (void)>::function<bool __cdecl (void)>(
    v29,
    &transition_predicate,
    (bool (__cdecl *)())vostok::collision::box_geometry_instance::is_valid,
    v36);
  vostok::ai::fsm::append_transition(
    v30,
    (vostok::ai::fsm_state *)v45,
    (vostok::ai::fsm_state *)v44,
    &transition_predicate);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v31,
    (int *)&transition_predicate);
  v46.functor.obj_ptr = (void *)a2;
  v46.vtable = (boost::detail::function::vtable_base *)survarium::victory_item_core::put_predicate;
  (&v46.vtable)[1] = 0;
  transition_predicate.vtable = (boost::detail::function::vtable_base *)survarium::victory_item_core::put_predicate;
  (&transition_predicate.vtable)[1] = 0;
  *(_QWORD *)&transition_predicate.functor.obj_ptr = __PAIR64__(
                                                       (unsigned int)v46.functor.vostok_pointer_size_alignment[1],
                                                       (unsigned int)a2);
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v46.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v46.functor.obj_ptr = *(_QWORD *)&transition_predicate.vtable;
    *((_QWORD *)&v46.functor.data + 1) = *(_QWORD *)&transition_predicate.functor.obj_ptr;
    v46.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<bool>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::cmf0<bool,survarium::victory_item_core>,boost::_bi::list1<boost::_bi::value<survarium::victory_item_core *>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  vostok::ai::fsm::append_transition(
    (vostok::ai::fsm *)&transition_predicate,
    (vostok::ai::fsm_state *)v44,
    (vostok::ai::fsm_state *)v15,
    &v46);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v32,
    (int *)&v46);
}
