void __thiscall vostok::render::stage_shadow_direct::stage_shadow_direct(
        vostok::render::renderer_context *context,
        vostok::shared_string this,
        vostok::strings::shared::profile *in_renderer)
{
  vostok::shared_string v3; // ebx
  vostok::tasks::task *v4; // ecx
  vostok::tasks::task_type *new_task_type; // eax
  vostok::strings::shared::profile **p_next_in_hashset; // edx
  int v7; // esi
  vostok::strings::shared::profile *v8; // ecx
  vostok::strings::shared::profile **v9; // edx
  int v10; // esi
  vostok::strings::shared::profile *v11; // ecx
  vostok::strings::shared::profile **v12; // edx
  int v13; // esi
  vostok::strings::shared::profile *v14; // ecx
  vostok::strings::shared::profile **v15; // edx
  int v16; // esi
  vostok::strings::shared::profile *v17; // ecx
  char *v18; // edi
  vostok::render::effect_manager *v19; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v20; // esi
  vostok::render::effect_manager *v21; // ecx
  vostok::shared_string *v22; // ecx
  vostok::render::backend *v23; // ecx
  vostok::render::shader_constant_host *v24; // eax
  vostok::shared_string *v25; // ecx
  bool v26; // zf
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *m_object; // esi
  vostok::render::backend *v28; // ecx
  vostok::render::shader_constant_host *v29; // eax
  vostok::shared_string *v30; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v31; // esi
  vostok::render::backend *v32; // ecx
  vostok::render::shader_constant_host *v33; // eax
  vostok::shared_string *v34; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v35; // esi
  vostok::render::backend *v36; // ecx
  vostok::render::shader_constant_host *v37; // eax
  vostok::shared_string *v38; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v39; // esi
  vostok::render::backend *v40; // ecx
  vostok::render::shader_constant_host *v41; // eax
  vostok::shared_string *v42; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v43; // esi
  vostok::render::backend *v44; // ecx
  vostok::render::shader_constant_host *v45; // eax
  vostok::shared_string *v46; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v47; // esi
  vostok::render::backend *v48; // ecx
  vostok::render::shader_constant_host *v49; // eax
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v50; // esi
  unsigned int m_shadow_quality; // eax
  int v52; // eax
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> **v53; // eax
  int v54; // ecx
  int *v55; // edi
  unsigned int i; // edi
  stlp_std::priv::_Rb_tree_node_base *render_target; // eax
  stlp_std::priv::_Rb_tree_node_base *v58; // eax
  vostok::math::float4x4 *v59; // ecx
  vostok::math::float4x4 *v60; // esi
  vostok::math::float4x4 *v61; // esi
  vostok::math::float4x4 *v62; // esi
  vostok::math::float4x4 *v63; // eax
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> **p_m_checksum; // edi
  vostok::math::float4x4 *v65; // eax
  vostok::fixed_vector<vostok::render::caster_model,2048>::allign_helper *v66; // edi
  vostok::render::renderer *v67; // edi
  vostok::render::renderer *v68; // edi
  vostok::shared_string *v69; // [esp-4h] [ebp-84h]
  vostok::shared_string *v70; // [esp-4h] [ebp-84h]
  vostok::shared_string *v71; // [esp-4h] [ebp-84h]
  vostok::shared_string *v72; // [esp-4h] [ebp-84h]
  vostok::shared_string *v73; // [esp-4h] [ebp-84h]
  vostok::shared_string *v74; // [esp-4h] [ebp-84h]
  vostok::strings::shared::profile *v75; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v76; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v77; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v78; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v79; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v80; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v81; // [esp+0h] [ebp-80h]
  vostok::strings::shared::profile *v82; // [esp+0h] [ebp-80h]
  unsigned int v83; // [esp+0h] [ebp-80h]
  vostok::math::float4x4 v84; // [esp+10h] [ebp-70h] BYREF
  unsigned int w; // [esp+50h] [ebp-30h]
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v86; // [esp+54h] [ebp-2Ch] BYREF
  unsigned int v87; // [esp+60h] [ebp-20h]
  const char *v88; // [esp+64h] [ebp-1Ch]
  const char *v89; // [esp+68h] [ebp-18h]
  const char *v90; // [esp+6Ch] [ebp-14h]
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v91; // [esp+70h] [ebp-10h] BYREF
  int v92; // [esp+7Ch] [ebp-4h]

  v3.m_pointer.m_object = this.m_pointer.m_object;
  vostok::render::stage::stage(
    (vostok::render::stage *)this.m_pointer.m_object,
    context,
    (vostok::render::renderer *)in_renderer);
  v3.m_pointer.m_object->m_reference_count = (volatile int)&vostok::render::stage_shadow_direct::`vftable';
  LOBYTE(v3.m_pointer.m_object[2].m_checksum) = 1;
  BYTE1(v3.m_pointer.m_object[2].m_checksum) = 0;
  vostok::tasks::task::task(v4, &v3.m_pointer.m_object[3].m_reference_count);
  new_task_type = vostok::tasks::create_new_task_type(
                    "cascaded_shadow_task",
                    (vostok::enum_flags<enum vostok::tasks::task_type_flags_enum>)1);
  p_next_in_hashset = &v3.m_pointer.m_object[9].next_in_hashset;
  v3.m_pointer.m_object[9].m_reference_count = (volatile int)new_task_type;
  v7 = 3;
  v8 = v3.m_pointer.m_object + 10;
  do
  {
    *p_next_in_hashset = v8;
    v8[-1].m_length = (unsigned int)v8;
    v8[-1].m_checksum = (unsigned int)&v8[1024];
    p_next_in_hashset += 4099;
    v8 = (vostok::strings::shared::profile *)((char *)v8 + 16396);
    --v7;
  }
  while ( v7 >= 0 );
  v9 = &v3.m_pointer.m_object[4108].next_in_hashset;
  v10 = 3;
  v11 = v3.m_pointer.m_object + 4109;
  do
  {
    *v9 = v11;
    v11[-1].m_length = (unsigned int)v11;
    v11[-1].m_checksum = (unsigned int)&v11[1024];
    v9 += 4099;
    v11 = (vostok::strings::shared::profile *)((char *)v11 + 16396);
    --v10;
  }
  while ( v10 >= 0 );
  v12 = &v3.m_pointer.m_object[8207].next_in_hashset;
  v13 = 3;
  v14 = v3.m_pointer.m_object + 8208;
  do
  {
    *v12 = v14;
    v14[-1].m_length = (unsigned int)v14;
    v14[-1].m_checksum = (unsigned int)&v14[1024];
    v12 += 4099;
    v14 = (vostok::strings::shared::profile *)((char *)v14 + 16396);
    --v13;
  }
  while ( v13 >= 0 );
  v15 = &v3.m_pointer.m_object[12306].next_in_hashset;
  v16 = 3;
  v17 = v3.m_pointer.m_object + 12307;
  do
  {
    *v15 = v17;
    v17[-1].m_length = (unsigned int)v17;
    v17[-1].m_checksum = (unsigned int)&v17[1024];
    v15 += 4099;
    v17 = (vostok::strings::shared::profile *)((char *)v17 + 16396);
    --v16;
  }
  while ( v16 >= 0 );
  *(_DWORD *)((char *)&loc_4016F + (unsigned int)v3.m_pointer.m_object + 1) = 0;
  *(_DWORD *)((char *)&loc_40174 + (unsigned int)v3.m_pointer.m_object) = 0;
  v18 = (char *)&loc_40179 + (unsigned int)v3.m_pointer.m_object + 3;
  for ( this.m_pointer.m_object = (vostok::strings::shared::profile *)3;
        (int)this.m_pointer.m_object >= 0;
        --this.m_pointer.m_object )
  {
    `vector constructor iterator'(
      v18,
      0x14u,
      16,
      (void *(__thiscall *)(void *))survarium::booby_trap_set_core::cast_booby_trap_set_core);
    v18 += 324;
  }
  *(_DWORD *)((char *)&loc_40BF9 + (unsigned int)v3.m_pointer.m_object + 3) = 0;
  *(_DWORD *)((char *)&loc_40BF9 + (unsigned int)v3.m_pointer.m_object + 7) = 0;
  *(_DWORD *)((char *)&loc_40BF9 + (unsigned int)v3.m_pointer.m_object + 11) = 0;
  *(_DWORD *)((char *)&loc_40BF9 + (unsigned int)v3.m_pointer.m_object + 15) = 0;
  *(_DWORD *)((char *)&loc_40C0C + (unsigned int)v3.m_pointer.m_object) = 0;
  *(_DWORD *)((char *)&loc_40C0C + (unsigned int)v3.m_pointer.m_object + 4) = 0;
  *(_DWORD *)((char *)&loc_40C0C + (unsigned int)v3.m_pointer.m_object + 8) = 0;
  *(_DWORD *)((char *)&loc_40C0C + (unsigned int)v3.m_pointer.m_object + 12) = 0;
  v3.m_pointer.m_object[2].m_length = 0;
  v20 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  *((_BYTE *)&loc_40C7F + (unsigned int)v3.m_pointer.m_object + 1) = 0;
  *(_DWORD *)((char *)&loc_40174 + (unsigned int)v3.m_pointer.m_object + 4) = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_shadow_map>(
    v19,
    v20,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)((char *)&loc_4016F + (unsigned int)v3.m_pointer.m_object + 1));
  vostok::render::effect_manager::create_effect<vostok::render::effect_copy_shadow_map>(
    v21,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)((char *)&loc_40174 + (unsigned int)v3.m_pointer.m_object));
  vostok::shared_string::shared_string(v22, &this.m_pointer, "light_direction");
  v24 = vostok::render::backend::register_constant_host(
          v23,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          0);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_4014F + (unsigned int)v3.m_pointer.m_object + 5) = v24;
  if ( !v26 )
  {
    v25 = (vostok::shared_string *)_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v25 )
    {
      m_object = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
      in_renderer = this.m_pointer.m_object;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        m_object,
        &v91,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v75);
      while ( v91.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != m_object )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v91,
          &v86);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v91.m_index,
        v91.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v76);
      v25 = v69;
    }
  }
  vostok::shared_string::shared_string(v25, &this.m_pointer, "light_position");
  v29 = vostok::render::backend::register_constant_host(
          v28,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          0);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_40155 + (unsigned int)v3.m_pointer.m_object + 3) = v29;
  if ( !v26 )
  {
    v30 = (vostok::shared_string *)_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v30 )
    {
      v31 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
      in_renderer = this.m_pointer.m_object;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v31,
        &v91,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v75);
      while ( v91.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != v31 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v91,
          &v86);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v91.m_index,
        v91.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v77);
      v30 = v70;
    }
  }
  vostok::shared_string::shared_string(v30, &this.m_pointer, "light_attenuation");
  v33 = vostok::render::backend::register_constant_host(
          v32,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          0);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_4015A + (unsigned int)v3.m_pointer.m_object + 2) = v33;
  if ( !v26 )
  {
    v34 = (vostok::shared_string *)_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v34 )
    {
      v35 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
      in_renderer = this.m_pointer.m_object;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v35,
        &v91,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v75);
      while ( v91.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != v35 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v91,
          &v86);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v91.m_index,
        v91.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v78);
      v34 = v71;
    }
  }
  vostok::shared_string::shared_string(v34, &this.m_pointer, "start_corner");
  v37 = vostok::render::backend::register_constant_host(
          v36,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          0);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_4015A + (unsigned int)v3.m_pointer.m_object + 6) = v37;
  if ( !v26 )
  {
    v38 = (vostok::shared_string *)_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v38 )
    {
      v39 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
      in_renderer = this.m_pointer.m_object;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v39,
        &v91,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v75);
      while ( v91.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != v39 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v91,
          &v86);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v91.m_index,
        v91.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v79);
      v38 = v72;
    }
  }
  vostok::shared_string::shared_string(v38, &this.m_pointer, "wind_info_parameters");
  v41 = vostok::render::backend::register_constant_host(
          v40,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          0);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_40163 + (unsigned int)v3.m_pointer.m_object + 1) = v41;
  if ( !v26 )
  {
    v42 = (vostok::shared_string *)_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v42 )
    {
      v43 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
      in_renderer = this.m_pointer.m_object;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v43,
        &v91,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v75);
      while ( v91.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != v43 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v91,
          &v86);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v91.m_index,
        v91.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v80);
      v42 = v73;
    }
  }
  vostok::shared_string::shared_string(v42, &this.m_pointer, "buffer_offset");
  v45 = vostok::render::backend::register_constant_host(
          v44,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          (vostok::strings::shared::profile *)1);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_40166 + (unsigned int)v3.m_pointer.m_object + 2) = v45;
  if ( !v26 )
  {
    v46 = (vostok::shared_string *)_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v46 )
    {
      v47 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
      in_renderer = this.m_pointer.m_object;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v47,
        &v91,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v75);
      while ( v91.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != v47 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v91,
          &v86);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v91.m_index,
        v91.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v81);
      v46 = v74;
    }
  }
  vostok::shared_string::shared_string(v46, &this.m_pointer, "cascade_offset");
  v49 = vostok::render::backend::register_constant_host(
          v48,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &this,
          0);
  v26 = this.m_pointer.m_object == 0;
  *(_DWORD *)((char *)&loc_4016C + (unsigned int)v3.m_pointer.m_object) = v49;
  if ( !v26 && !_InterlockedExchangeAdd(&this.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    v50 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.m_pointer.m_object;
    in_renderer = this.m_pointer.m_object;
    vostok::threading::mutex::lock(0, &s_manager_buffer);
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
      v50,
      &v91,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
      v75);
    while ( v91.m_value
         && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value != v50 )
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
        &v91,
        &v86);
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
      v91.m_index,
      v91.m_value);
    LeaveCriticalSection(&s_manager_buffer);
    vostok::strings::shared::profile::destroy((vostok::threading::mutex *)in_renderer, v82);
  }
  m_shadow_quality = vostok::quasi_singleton<vostok::render::options>::pinst->current.m_shadow_quality;
  if ( m_shadow_quality )
  {
    if ( m_shadow_quality == 3 )
      v52 = 2048;
    else
      v52 = 1024;
  }
  else
  {
    v52 = 512;
  }
  *(_DWORD *)((char *)&loc_40BF4 + (unsigned int)v3.m_pointer.m_object + 4) = v52;
  memset(&v91, 0, sizeof(v91));
  v53 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> **)((char *)&loc_40689 + (unsigned int)v3.m_pointer.m_object + 3);
  v54 = 4;
  do
  {
    *v53 = v91.m_container;
    v53[1] = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value;
    v55 = (int *)(v53 + 2);
    v53 += 3;
    --v54;
    *v55 = v91.m_index;
  }
  while ( v54 );
  w = (unsigned int)"$user$cascaded_shadow_map0";
  v86.m_container = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)"$user$cascaded_shadow_map1";
  v86.m_value = (vostok::strings::shared::profile *)"$user$cascaded_shadow_map2";
  v86.m_index = (int)"$user$cascaded_shadow_map3";
  v87 = (unsigned int)"$user$cascaded_shadow_map0_cached";
  v88 = "$user$cascaded_shadow_map1_cached";
  v89 = "$user$cascaded_shadow_map2_cached";
  v90 = "$user$cascaded_shadow_map3_cached";
  in_renderer = (vostok::strings::shared::profile *)((char *)&loc_40C0C + (unsigned int)v3.m_pointer.m_object);
  for ( i = 0; i < 0x10; i += 4 )
  {
    render_target = vostok::render::resource_manager::create_render_target(
                      0,
                      (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                      *(_BYTE **)((char *)&w + i),
                      *(_DWORD *)((char *)&loc_40BF4 + (unsigned int)v3.m_pointer.m_object + 4),
                      *(_DWORD *)((char *)&loc_40BF4 + (unsigned int)v3.m_pointer.m_object + 4),
                      (char *)0x35,
                      DXGI_FORMAT_UNKNOWN,
                      0,
                      0,
                      0,
                      (unsigned int)v75);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&in_renderer[-1],
      (vostok::render::render_target *)render_target);
    v58 = vostok::render::resource_manager::create_render_target(
            0,
            (const char **)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            *(_BYTE **)((char *)&v87 + i),
            *(_DWORD *)((char *)&loc_40BF4 + (unsigned int)v3.m_pointer.m_object + 4),
            *(_DWORD *)((char *)&loc_40BF4 + (unsigned int)v3.m_pointer.m_object + 4),
            (char *)0x35,
            DXGI_FORMAT_UNKNOWN,
            0,
            0,
            0,
            v83);
    vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)in_renderer,
      (vostok::render::render_target *)v58);
    in_renderer = (vostok::strings::shared::profile *)((char *)in_renderer + 4);
  }
  in_renderer = (vostok::strings::shared::profile *)((char *)&loc_40C4C + (unsigned int)v3.m_pointer.m_object);
  memset(&v91, 0, sizeof(v91));
  v88 = 0;
  v89 = 0;
  v90 = 0;
  memset(&v86, 0, sizeof(v86));
  this.m_pointer.m_object = (vostok::strings::shared::profile *)((char *)&loc_406F3
                                                               + (unsigned int)v3.m_pointer.m_object
                                                               + 5);
  v92 = 4;
  do
  {
    v60 = vostok::math::float4x4::identity(v59, &v84);
    qmemcpy(&this.m_pointer.m_object[48], v60, 0x40u);
    v61 = vostok::math::float4x4::identity(0, &v84);
    qmemcpy(this.m_pointer.m_object, v61, 0x40u);
    v62 = vostok::math::float4x4::identity(0, &v84);
    qmemcpy(&this.m_pointer.m_object[16], v62, 0x40u);
    v63 = vostok::math::float4x4::identity(0, &v84);
    qmemcpy(&this.m_pointer.m_object[32], v63, 0x40u);
    p_m_checksum = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> **)&in_renderer[-89].m_checksum;
    *p_m_checksum++ = v91.m_container;
    *p_m_checksum = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_value;
    p_m_checksum[1] = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v91.m_index;
    v65 = vostok::math::float4x4::identity(0, &v84);
    v66 = (vostok::fixed_vector<vostok::render::caster_model,2048>::allign_helper *)&this.m_pointer.m_object[64];
    this.m_pointer.m_object += 4;
    qmemcpy(v66, v65, 0x40u);
    v59 = 0;
    v67 = (vostok::render::renderer *)in_renderer;
    in_renderer->m_reference_count = (volatile int)v88;
    v67 = (vostok::render::renderer *)((char *)v67 + 4);
    LODWORD(v67->m_prev_viewport.TopLeftX) = v89;
    LODWORD(v67->m_prev_viewport.TopLeftY) = v90;
    v68 = (vostok::render::renderer *)in_renderer;
    in_renderer = (vostok::strings::shared::profile *)((char *)in_renderer + 12);
    v68 = (vostok::render::renderer *)((char *)v68 - 48);
    v26 = v92-- == 1;
    LODWORD(v68->m_prev_viewport.TopLeftX) = v86.m_container;
    v68 = (vostok::render::renderer *)((char *)v68 + 4);
    LODWORD(v68->m_prev_viewport.TopLeftX) = v86.m_value;
    LODWORD(v68->m_prev_viewport.TopLeftY) = v86.m_index;
  }
  while ( !v26 );
  *(_DWORD *)((char *)&loc_40C7C + (unsigned int)v3.m_pointer.m_object) = 16843009;
  v86.m_value = 0;
  *(float *)&v86.m_index = s_bm_current_air_resistance;
  *(_DWORD *)((char *)&loc_406B8 + (unsigned int)v3.m_pointer.m_object + 4) = 0;
  *(_DWORD *)((char *)&loc_406B8 + (unsigned int)v3.m_pointer.m_object + 8) = v86.m_value;
  *(_DWORD *)((char *)&loc_406B8 + (unsigned int)v3.m_pointer.m_object + 12) = v86.m_index;
}
