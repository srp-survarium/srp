void __userpurge vostok::render::stage_view_mode::stage_view_mode(
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::surface_effect_parameters this)
{
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *vertex_input_type; // ebx
  __int64 v3; // rdi
  unsigned int v4; // edx
  vostok::render::effect_manager *v5; // ecx
  vostok::render::effect_descriptor *v6; // eax
  vostok::render::effect_manager *v7; // ecx
  vostok::render::effect_descriptor *v8; // eax
  vostok::render::effect_manager *v9; // ecx
  vostok::render::effect_descriptor *v10; // eax
  vostok::render::effect_manager *v11; // ecx
  vostok::render::effect_descriptor *v12; // eax
  vostok::render::effect_manager *v13; // ecx
  vostok::render::effect_descriptor *v14; // eax
  vostok::render::effect_manager *v15; // ecx
  vostok::render::effect_descriptor *v16; // eax
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v17; // esi
  vostok::render::effect_descriptor *v18; // eax
  vostok::render::effect_manager *v19; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v20; // esi
  vostok::render::effect_descriptor *v21; // eax
  vostok::render::effect_manager *v22; // ecx
  vostok::render::effect_manager *v23; // ecx
  vostok::shared_string *v24; // ecx
  vostok::render::backend *v25; // ecx
  vostok::render::shader_constant_host *v26; // eax
  vostok::shared_string *v27; // ecx
  bool v28; // zf
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v29; // esi
  vostok::render::backend *v30; // ecx
  vostok::render::shader_constant_host *v31; // eax
  vostok::shared_string *v32; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v33; // esi
  vostok::render::backend *v34; // ecx
  vostok::render::shader_constant_host *v35; // eax
  vostok::shared_string *v36; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v37; // esi
  vostok::render::backend *v38; // ecx
  vostok::render::shader_constant_host *v39; // eax
  vostok::shared_string *v40; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v41; // esi
  vostok::render::backend *v42; // ecx
  vostok::render::shader_constant_host *v43; // eax
  vostok::shared_string *v44; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v45; // esi
  vostok::render::backend *v46; // ecx
  vostok::render::shader_constant_host *v47; // eax
  vostok::shared_string *v48; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v49; // esi
  vostok::render::backend *v50; // ecx
  vostok::render::shader_constant_host *v51; // eax
  vostok::shared_string *v52; // ecx
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *v53; // esi
  vostok::render::backend *v54; // ecx
  __int64 v55; // [esp-14h] [ebp-54h]
  __int64 v56; // [esp-14h] [ebp-54h]
  __int64 v57; // [esp-14h] [ebp-54h]
  __int64 v58; // [esp-14h] [ebp-54h]
  __int64 v59; // [esp-14h] [ebp-54h]
  __int64 v60; // [esp-14h] [ebp-54h]
  __int64 v61; // [esp-14h] [ebp-54h]
  vostok::render::effect_manager *v62; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v63; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v64; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v65; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v66; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v67; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v68; // [esp-4h] [ebp-44h]
  vostok::render::effect_manager *v69; // [esp-4h] [ebp-44h]
  vostok::shared_string *v70; // [esp-4h] [ebp-44h]
  vostok::shared_string *v71; // [esp-4h] [ebp-44h]
  vostok::shared_string *v72; // [esp-4h] [ebp-44h]
  vostok::shared_string *v73; // [esp-4h] [ebp-44h]
  vostok::shared_string *v74; // [esp-4h] [ebp-44h]
  vostok::shared_string *v75; // [esp-4h] [ebp-44h]
  vostok::shared_string *v76; // [esp-4h] [ebp-44h]
  vostok::strings::shared::profile *v77; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v78; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v79; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v80; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v81; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v82; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v83; // [esp+0h] [ebp-40h]
  vostok::strings::shared::profile *v84; // [esp+0h] [ebp-40h]
  vostok::render::surface_effect_parameters v85; // [esp+Ch] [ebp-34h] BYREF
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v86; // [esp+1Ch] [ebp-24h] BYREF
  vostok::render::effect_descriptor v87; // [esp+28h] [ebp-18h] BYREF
  vostok::render::effect_descriptor v88; // [esp+2Ch] [ebp-14h] BYREF
  vostok::render::effect_descriptor v89; // [esp+30h] [ebp-10h] BYREF
  vostok::render::effect_descriptor v90; // [esp+34h] [ebp-Ch] BYREF
  vostok::render::effect_descriptor v91; // [esp+38h] [ebp-8h] BYREF
  vostok::render::effect_descriptor descriptor; // [esp+3Ch] [ebp-4h] BYREF

  vertex_input_type = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)this.vertex_input_type;
  vostok::render::stage::stage(
    (vostok::render::stage *)this.vertex_input_type,
    context,
    (vostok::render::renderer *)this.cull_mode);
  vertex_input_type->m_object = (vostok::particle::particle_system_instance_impl *)&vostok::render::stage_view_mode::`vftable';
  memset(&vertex_input_type[4], 0, 0x3Cu);
  HIDWORD(v3) = vertex_input_type + 19;
  memset(&vertex_input_type[19], 0, 0x3Cu);
  memset(&vertex_input_type[34], 0, 0x3Cu);
  memset(&vertex_input_type[49], 0, 0x3Cu);
  v4 = 0;
  memset(&vertex_input_type[64], 0, 0x3Cu);
  vertex_input_type[79].m_object = 0;
  memset(&vertex_input_type[80], 0, 0x3Cu);
  v5 = 0;
  vertex_input_type[95].m_object = 0;
  vertex_input_type[96].m_object = 0;
  vertex_input_type[97].m_object = 0;
  this.cull_mode = 0;
  do
  {
    if ( v4 != 12 )
    {
      v85.draw_to_gbuffer = -1;
      v85.blend_mode = -1;
      LODWORD(v3) = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      v85.vertex_input_type = v4;
      v85.cull_mode = 3;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_wireframe_accumulation::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v5 = v62;
      }
      this.vertex_input_type = 0;
      if ( *(_BYTE *)v3 )
      {
        v6 = vostok::render::effect_manager::create_new_effect(
               v5,
               (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v3,
               &descriptor,
               (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>'::`2'::descriptor_object,
               (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
               &v85);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v6,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(HIDWORD(v3) - 60));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&descriptor);
      }
      else
      {
        HIDWORD(v55) = HIDWORD(v3) - 60;
        LODWORD(v55) = v3;
        vostok::render::effect_manager::create_new_effect(
          v5,
          v55,
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_wireframe_accumulation>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
          &v85);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
      LODWORD(v3) = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_texture_density::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v7 = v63;
      }
      this.vertex_input_type = 0;
      if ( *(_BYTE *)v3 )
      {
        v8 = vostok::render::effect_manager::create_new_effect(
               v7,
               (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v3,
               &v91,
               (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>'::`2'::descriptor_object,
               (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
               &v85);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v8,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)HIDWORD(v3));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v91);
      }
      else
      {
        vostok::render::effect_manager::create_new_effect(
          v7,
          v3,
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_texture_density>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
          &v85);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
      LODWORD(v3) = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_shader_complexity::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v9 = v64;
      }
      this.vertex_input_type = 0;
      if ( *(_BYTE *)v3 )
      {
        v10 = vostok::render::effect_manager::create_new_effect(
                v9,
                (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v3,
                &v90,
                (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>'::`2'::descriptor_object,
                (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
                &v85);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v10,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(HIDWORD(v3) + 60));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v90);
      }
      else
      {
        HIDWORD(v56) = HIDWORD(v3) + 60;
        LODWORD(v56) = v3;
        vostok::render::effect_manager::create_new_effect(
          v9,
          v56,
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_shader_complexity>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
          &v85);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
      LODWORD(v3) = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_show_miplevel::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v11 = v65;
      }
      this.vertex_input_type = 0;
      if ( *(_BYTE *)v3 )
      {
        v12 = vostok::render::effect_manager::create_new_effect(
                v11,
                (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v3,
                &v89,
                (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>'::`2'::descriptor_object,
                (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
                &v85);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v12,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(HIDWORD(v3) + 120));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v89);
      }
      else
      {
        HIDWORD(v57) = HIDWORD(v3) + 120;
        LODWORD(v57) = v3;
        vostok::render::effect_manager::create_new_effect(
          v11,
          v57,
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_miplevel>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
          &v85);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
      LODWORD(v3) = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_accumulate_overdraw::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v13 = v66;
      }
      this.vertex_input_type = 0;
      if ( *(_BYTE *)v3 )
      {
        v14 = vostok::render::effect_manager::create_new_effect(
                v13,
                (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v3,
                &v88,
                (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>'::`2'::descriptor_object,
                (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
                &v85);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v14,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(HIDWORD(v3) + 244));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v88);
      }
      else
      {
        HIDWORD(v58) = HIDWORD(v3) + 244;
        LODWORD(v58) = v3;
        vostok::render::effect_manager::create_new_effect(
          v13,
          v58,
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_accumulate_overdraw>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
          &v85);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
      LODWORD(v3) = vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_geometry_complexity::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v15 = v67;
      }
      this.vertex_input_type = 0;
      if ( *(_BYTE *)v3 )
      {
        v16 = vostok::render::effect_manager::create_new_effect(
                v15,
                (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v3,
                &v87,
                (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>'::`2'::descriptor_object,
                (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
                &v85);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v16,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(HIDWORD(v3) + 180));
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v87);
      }
      else
      {
        HIDWORD(v59) = HIDWORD(v3) + 180;
        LODWORD(v59) = v3;
        vostok::render::effect_manager::create_new_effect(
          v15,
          v59,
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_geometry_complexity>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
          &v85);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
    }
    v4 = this.cull_mode + 1;
    HIDWORD(v3) += 4;
    this.cull_mode = v4;
  }
  while ( v4 < 0xF );
  v85.draw_to_gbuffer = -1;
  v85.blend_mode = -1;
  v17 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v85.vertex_input_type = 1;
  v85.cull_mode = 1;
  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_show_batched_geometry::`vftable';
    atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
    v5 = v68;
  }
  this.vertex_input_type = 0;
  if ( LOBYTE(v17->m_object) )
  {
    v18 = vostok::render::effect_manager::create_new_effect(
            v5,
            v17,
            (vostok::render::effect_descriptor *)&this.cull_mode,
            (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>'::`2'::descriptor_object,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
            &v85);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v18,
      vertex_input_type + 79);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this.cull_mode);
  }
  else
  {
    HIDWORD(v60) = vertex_input_type + 79;
    LODWORD(v60) = v17;
    vostok::render::effect_manager::create_new_effect(
      v5,
      v60,
      (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_batched_geometry>'::`2'::descriptor_object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
      &v85);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  v85.draw_to_gbuffer = -1;
  v85.blend_mode = -1;
  v20 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  v85.vertex_input_type = 2;
  v85.cull_mode = 1;
  if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>'::`2'::`local static guard'
      & 1) == 0 )
  {
    `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>'::`2'::`local static guard' |= 1u;
    `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_vertex_alpha::`vftable';
    atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
    v19 = v69;
  }
  this.vertex_input_type = 0;
  if ( LOBYTE(v20->m_object) )
  {
    v21 = vostok::render::effect_manager::create_new_effect(
            v19,
            v20,
            &v87,
            (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>'::`2'::descriptor_object,
            (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
            &v85);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v21,
      vertex_input_type + 95);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v87);
  }
  else
  {
    HIDWORD(v61) = vertex_input_type + 95;
    LODWORD(v61) = v20;
    vostok::render::effect_manager::create_new_effect(
      v19,
      v61,
      (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_vertex_alpha>'::`2'::descriptor_object,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this,
      &v85);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_apply_wireframe>(
    v22,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    vertex_input_type + 96);
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_show_overdraw>(
    v23,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    vertex_input_type + 97);
  vostok::shared_string::shared_string(
    v24,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "show_component_index");
  v26 = vostok::render::backend::register_constant_host(
          v25,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          (vostok::strings::shared::profile *)1);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[99].m_object = (vostok::particle::particle_system_instance_impl *)v26;
  if ( !v28 )
  {
    v27 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v27 )
    {
      v29 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v29,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v29 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v78);
      v27 = v70;
    }
  }
  vostok::shared_string::shared_string(
    v27,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "debug_color");
  v31 = vostok::render::backend::register_constant_host(
          v30,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          0);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[98].m_object = (vostok::particle::particle_system_instance_impl *)v31;
  if ( !v28 )
  {
    v32 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v32 )
    {
      v33 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v33,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v33 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v79);
      v32 = v71;
    }
  }
  vostok::shared_string::shared_string(
    v32,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "shader_complexity");
  v35 = vostok::render::backend::register_constant_host(
          v34,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          0);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[100].m_object = (vostok::particle::particle_system_instance_impl *)v35;
  if ( !v28 )
  {
    v36 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v36 )
    {
      v37 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v37,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v37 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v80);
      v36 = v72;
    }
  }
  vostok::shared_string::shared_string(
    v36,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "shader_complexity_min");
  v39 = vostok::render::backend::register_constant_host(
          v38,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          0);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[101].m_object = (vostok::particle::particle_system_instance_impl *)v39;
  if ( !v28 )
  {
    v40 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v40 )
    {
      v41 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v41,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v41 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v81);
      v40 = v73;
    }
  }
  vostok::shared_string::shared_string(
    v40,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "shader_complexity_max");
  v43 = vostok::render::backend::register_constant_host(
          v42,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          0);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[102].m_object = (vostok::particle::particle_system_instance_impl *)v43;
  if ( !v28 )
  {
    v44 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v44 )
    {
      v45 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v45,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v45 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v82);
      v44 = v74;
    }
  }
  vostok::shared_string::shared_string(
    v44,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "geometry_complexity_parameters");
  v47 = vostok::render::backend::register_constant_host(
          v46,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          0);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[104].m_object = (vostok::particle::particle_system_instance_impl *)v47;
  if ( !v28 )
  {
    v48 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v48 )
    {
      v49 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v49,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v49 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v83);
      v48 = v75;
    }
  }
  vostok::shared_string::shared_string(
    v48,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "current_max_texture_dimension");
  v51 = vostok::render::backend::register_constant_host(
          v50,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          (const vostok::shared_string *)&this,
          0);
  v28 = this.vertex_input_type == 0;
  vertex_input_type[103].m_object = (vostok::particle::particle_system_instance_impl *)v51;
  if ( !v28 )
  {
    v52 = (vostok::shared_string *)_InterlockedExchangeAdd(
                                     (volatile signed __int32 *)this.vertex_input_type,
                                     0xFFFFFFFF);
    if ( !v52 )
    {
      v53 = (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)this.vertex_input_type;
      this.cull_mode = this.vertex_input_type;
      vostok::threading::mutex::lock(0, &s_manager_buffer);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
        v53,
        &v86,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v77);
      while ( v86.m_value
           && (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)v86.m_value != v53 )
        vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
          &v86,
          (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v85.cull_mode);
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
        v86.m_index,
        v86.m_value);
      LeaveCriticalSection(&s_manager_buffer);
      vostok::strings::shared::profile::destroy((vostok::threading::mutex *)this.cull_mode, v84);
      v52 = v76;
    }
  }
  vostok::shared_string::shared_string(
    v52,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this,
    "start_corner");
  vertex_input_type[105].m_object = (vostok::particle::particle_system_instance_impl *)vostok::render::backend::register_constant_host(
                                                                                         v54,
                                                                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                                                         (const vostok::shared_string *)&this,
                                                                                         0);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&this);
}
