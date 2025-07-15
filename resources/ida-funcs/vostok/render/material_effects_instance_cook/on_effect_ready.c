void __thiscall vostok::render::material_effects_instance_cook::on_effect_ready(
        vostok::render::material_effects_instance_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::material_effects_instance_cook_data *cook_data,
        vostok::variant<32> *exists_stages,
        bool *exists_vertex_inputs,
        const vostok::configs::binary_config_value *num_vertex_inputs)
{
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  vostok::render::material_effects_instance *v9; // ecx
  vostok::render::material_effects_instance *v10; // eax
  vostok::particle::particle_system_instance_impl *m_object; // esi
  char *v12; // edx
  vostok::fs_new::virtual_path_string *p_m_material_name; // eax
  char *m_begin; // ecx
  vostok::variant<32> *v15; // ecx
  vostok::variant<32> *v16; // edi
  vostok::render::enum_vertex_input_type v17; // esi
  vostok::render::material_effects *material_effects_or_new; // eax
  int v19; // edi
  vostok::particle::particle_system_instance_impl *v20; // esi
  vostok::configs::binary_config_value *v21; // ecx
  vostok::configs::binary_config_value *v22; // ecx
  const vostok::configs::binary_config_value *v23; // eax
  vostok::configs::binary_config_value *v24; // ecx
  vostok::configs::binary_config_value *v25; // eax
  const vostok::configs::binary_config_value *v26; // eax
  vostok::configs::binary_config_value *v27; // ecx
  vostok::configs::binary_config_value *v28; // eax
  vostok::configs::binary_config_value *v29; // eax
  vostok::configs::binary_config_value *v30; // eax
  const vostok::configs::binary_config_value *v31; // eax
  vostok::configs::binary_config_value *v32; // ecx
  const vostok::configs::binary_config_value *v33; // eax
  vostok::configs::binary_config_value *v34; // ecx
  vostok::configs::binary_config_value *v35; // eax
  vostok::configs::binary_config_value *v36; // eax
  const vostok::configs::binary_config_value *v37; // eax
  vostok::configs::binary_config_value *v38; // ecx
  const vostok::configs::binary_config_value *v39; // eax
  vostok::configs::binary_config_value *v40; // ecx
  vostok::configs::binary_config_value *v41; // eax
  const vostok::configs::binary_config_value *v42; // eax
  vostok::configs::binary_config_value *v43; // ecx
  vostok::configs::binary_config_value *v44; // eax
  vostok::configs::binary_config_value *v45; // eax
  vostok::configs::binary_config_value *v46; // eax
  const vostok::configs::binary_config_value *v47; // eax
  vostok::configs::binary_config_value *v48; // ecx
  const vostok::configs::binary_config_value *v49; // eax
  vostok::configs::binary_config_value *v50; // ecx
  vostok::configs::binary_config_value *v51; // eax
  const vostok::configs::binary_config_value *v52; // eax
  vostok::configs::binary_config_value *v53; // ecx
  vostok::configs::binary_config_value *v54; // eax
  vostok::configs::binary_config_value *v55; // eax
  vostok::configs::binary_config_value *v56; // eax
  const vostok::configs::binary_config_value *v57; // eax
  vostok::configs::binary_config_value *v58; // ecx
  const vostok::configs::binary_config_value *v59; // eax
  vostok::configs::binary_config_value *v60; // ecx
  vostok::configs::binary_config_value *v61; // eax
  const vostok::configs::binary_config_value *v62; // eax
  vostok::configs::binary_config_value *v63; // ecx
  vostok::configs::binary_config_value *v64; // eax
  vostok::configs::binary_config_value *v65; // eax
  vostok::configs::binary_config_value *v66; // eax
  const vostok::configs::binary_config_value *v67; // eax
  vostok::configs::binary_config_value *v68; // ecx
  const vostok::configs::binary_config_value *v69; // eax
  vostok::configs::binary_config_value *v70; // ecx
  vostok::configs::binary_config_value *v71; // eax
  const vostok::configs::binary_config_value *v72; // eax
  vostok::configs::binary_config_value *v73; // ecx
  vostok::configs::binary_config_value *v74; // eax
  vostok::configs::binary_config_value *v75; // eax
  vostok::configs::binary_config_value *v76; // eax
  const vostok::configs::binary_config_value *v77; // eax
  vostok::configs::binary_config_value *v78; // ecx
  const vostok::configs::binary_config_value *v79; // eax
  vostok::configs::binary_config_value *v80; // ecx
  vostok::configs::binary_config_value *v81; // eax
  const vostok::configs::binary_config_value *v82; // eax
  vostok::configs::binary_config_value *v83; // ecx
  vostok::configs::binary_config_value *v84; // eax
  vostok::configs::binary_config_value *v85; // eax
  vostok::configs::binary_config_value *v86; // eax
  const vostok::configs::binary_config_value *v87; // eax
  const vostok::configs::binary_config_value *v88; // eax
  vostok::configs::binary_config_value *v89; // ecx
  vostok::configs::binary_config_value *v90; // eax
  const vostok::configs::binary_config_value *v91; // eax
  vostok::configs::binary_config_value *v92; // ecx
  vostok::configs::binary_config_value *v93; // eax
  vostok::configs::binary_config_value *v94; // eax
  vostok::configs::binary_config_value *v95; // eax
  const vostok::configs::binary_config_value *v96; // eax
  const vostok::configs::binary_config_value *v97; // esi
  vostok::configs::binary_config_value *v98; // esi
  vostok::configs::binary_config_value *v99; // ecx
  const vostok::configs::binary_config_value *v100; // eax
  vostok::configs::binary_config_value *v101; // ecx
  vostok::configs::binary_config_value *v102; // eax
  vostok::configs::binary_config_value *v103; // eax
  const vostok::configs::binary_config_value *v104; // eax
  vostok::particle::particle_system_instance_impl *v105; // esi
  vostok::configs::binary_config_value *v106; // ecx
  vostok::configs::binary_config_value *v107; // ecx
  const vostok::configs::binary_config_value *v108; // eax
  vostok::configs::binary_config_value *v109; // ecx
  vostok::configs::binary_config_value *v110; // eax
  const vostok::configs::binary_config_value *v111; // eax
  vostok::configs::binary_config_value *v112; // ecx
  vostok::configs::binary_config_value *v113; // eax
  vostok::configs::binary_config_value *v114; // eax
  const char **v115; // eax
  int v116; // eax
  vostok::configs::binary_config_value *v117; // ecx
  const vostok::configs::binary_config_value *v118; // eax
  vostok::configs::binary_config_value *v119; // ecx
  vostok::configs::binary_config_value *v120; // eax
  const vostok::configs::binary_config_value *v121; // eax
  vostok::configs::binary_config_value *v122; // ecx
  vostok::configs::binary_config_value *v123; // eax
  vostok::configs::binary_config_value *v124; // eax
  const char **v125; // eax
  vostok::configs::binary_config_value *v126; // ecx
  const vostok::configs::binary_config_value *v127; // eax
  vostok::configs::binary_config_value *v128; // ecx
  vostok::configs::binary_config_value *v129; // eax
  const vostok::configs::binary_config_value *v130; // eax
  vostok::configs::binary_config_value *v131; // ecx
  vostok::configs::binary_config_value *v132; // eax
  vostok::configs::binary_config_value *v133; // eax
  const char **v134; // eax
  vostok::configs::binary_config_value *v135; // ecx
  const vostok::configs::binary_config_value *v136; // eax
  vostok::configs::binary_config_value *v137; // ecx
  vostok::configs::binary_config_value *v138; // eax
  const vostok::configs::binary_config_value *v139; // eax
  vostok::configs::binary_config_value *v140; // ecx
  vostok::configs::binary_config_value *v141; // eax
  vostok::configs::binary_config_value *v142; // eax
  vostok::configs::binary_config_value *v143; // eax
  const vostok::configs::binary_config_value *v144; // eax
  vostok::configs::binary_config_value *v145; // ecx
  const vostok::configs::binary_config_value *v146; // eax
  vostok::configs::binary_config_value *v147; // ecx
  vostok::configs::binary_config_value *v148; // eax
  vostok::configs::binary_config_value *v149; // eax
  const vostok::configs::binary_config_value *v150; // eax
  vostok::configs::binary_config_value *v151; // ecx
  const vostok::configs::binary_config_value *v152; // eax
  vostok::configs::binary_config_value *v153; // ecx
  vostok::configs::binary_config_value *v154; // eax
  vostok::configs::binary_config_value *v155; // eax
  const vostok::configs::binary_config_value *v156; // eax
  const vostok::configs::binary_config_value *v157; // eax
  vostok::configs::binary_config_value *v158; // ecx
  vostok::configs::binary_config_value *v159; // eax
  vostok::configs::binary_config_value *v160; // eax
  const vostok::configs::binary_config_value *v161; // eax
  const vostok::configs::binary_config_value *v162; // esi
  vostok::configs::binary_config_value *v163; // esi
  vostok::configs::binary_config_value *v164; // ecx
  const vostok::configs::binary_config_value *v165; // eax
  vostok::configs::binary_config_value *v166; // ecx
  vostok::configs::binary_config_value *v167; // eax
  vostok::configs::binary_config_value *v168; // eax
  const vostok::configs::binary_config_value *v169; // eax
  const vostok::configs::binary_config_value *v170; // esi
  vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *v171; // edi
  vostok::resources::query_result_for_cook *v172; // ecx
  vostok::resources::query_result_for_cook *v173; // ecx
  vostok::memory::doug_lea_allocator *v174; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v175; // [esp-Ch] [ebp-50h] BYREF
  const vostok::resources::memory_type *v176; // [esp-8h] [ebp-4Ch]
  unsigned int v177; // [esp-4h] [ebp-48h]
  const char *v178; // [esp+0h] [ebp-44h]
  const char *v179; // [esp+4h] [ebp-40h]
  unsigned int v180; // [esp+8h] [ebp-3Ch]
  vostok::resources::query_result_for_cook *m_parent_query; // [esp+10h] [ebp-34h]
  int v182; // [esp+14h] [ebp-30h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v183; // [esp+18h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v184; // [esp+1Ch] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v185; // [esp+20h] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v186; // [esp+24h] [ebp-20h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v187; // [esp+28h] [ebp-1Ch] BYREF
  unsigned int v188; // [esp+2Ch] [ebp-18h]
  vostok::variant<32> *v189; // [esp+30h] [ebp-14h]
  vostok::render::material_effects_instance *v190; // [esp+34h] [ebp-10h]
  int v191; // [esp+38h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v192; // [esp+3Ch] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v193; // [esp+40h] [ebp-4h] BYREF

  v6 = vostok::render::g_allocator;
  m_parent_query = data->m_parent_query;
  v7 = type_info::raw_name(&vostok::render::material_effects_instance `RTTI Type Descriptor');
  if ( vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x228u, v7, v178, v179, v180) )
  {
    vostok::render::material_effects_instance::material_effects_instance(v9, (unsigned int)num_vertex_inputs);
    v190 = v10;
  }
  else
  {
    v190 = 0;
  }
  m_object = (vostok::particle::particle_system_instance_impl *)cook_data->material.m_object;
  v193.m_object = 0;
  if ( m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v193);
    v193.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v12 = (char *)v193.m_object->m_lods[0].m_template.m_object;
  p_m_material_name = &v190->m_material_name;
  m_begin = v190->m_material_name.m_string.m_begin;
  if ( m_begin != v12 )
  {
    v190->m_material_name.m_string.m_end = m_begin;
    *m_begin = 0;
    vostok::buffer_string::operator+=(&p_m_material_name->m_string, v12);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v193);
  v188 = 0;
  if ( data->m_size )
  {
    v15 = exists_stages;
    v189 = exists_stages;
    v193.m_object = (vostok::particle::particle_system_instance_impl *)data->m_queries;
    v182 = exists_vertex_inputs - (bool *)exists_stages;
    while ( 1 )
    {
      num_vertex_inputs = 0;
      vostok::variant<32>::try_get<vostok::render::effect_compile_data *>(
        v15,
        (int)v193.m_object->m_lods[0].m_template.m_object,
        (vostok::render::effect_compile_data **)&num_vertex_inputs);
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::effect_compile_data>(
        vostok::render::g_allocator,
        (vostok::render::effect_compile_data **)&num_vertex_inputs,
        v178,
        v179,
        v180);
      if ( vostok::resources::query_result_for_user::is_successful(
             (vostok::resources::query_result_for_user *)v177,
             (int)v193.m_object) )
      {
        break;
      }
LABEL_90:
      v15 = (vostok::variant<32> *)++v188;
      v189 = (vostok::variant<32> *)((char *)v189 + 4);
      v193.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v193.m_object + 736);
      if ( v188 >= data->m_size )
        goto LABEL_91;
    }
    v16 = v189;
    v17 = *(_DWORD *)&v189->m_helper_storage[v182];
    material_effects_or_new = vostok::render::material_effects_instance::get_material_effects_or_new(v190, v17);
    material_effects_or_new->m_vertex_input_type = v17;
    v19 = *(_DWORD *)v16->m_helper_storage;
    exists_vertex_inputs = &material_effects_or_new->is_emissive;
    v191 = v19;
    if ( v19 == 1 )
    {
      v20 = (vostok::particle::particle_system_instance_impl *)cook_data->material.m_object;
      v192.m_object = 0;
      if ( v20 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v192);
        v192.m_object = v20;
        _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v187,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v192.m_object->m_lods[4].m_emitter_instance_list.m_first);
      num_vertex_inputs = vostok::configs::binary_config_value::operator[](
                            (vostok::configs::binary_config_value *)v187.m_object->m_lods[0].m_template.m_object,
                            "material");
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v187);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v192);
      if ( vostok::configs::binary_config_value::value_exists(v21, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v23 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v24, (int)v23, (unsigned int)"effect") )
        {
          v25 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v26 = vostok::configs::binary_config_value::operator[](v25, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v27, (int)v26, (unsigned int)"use_emissive") )
          {
            v28 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
            v29 = vostok::configs::binary_config_value::operator[](v28, "effect");
            v30 = vostok::configs::binary_config_value::operator[](v29, "use_emissive");
            v31 = vostok::configs::binary_config_value::operator[](v30, "value");
            v22 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            *exists_vertex_inputs = v31->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v22, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v33 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v34, (int)v33, (unsigned int)"is_cast_shadow") )
        {
          v35 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v36 = vostok::configs::binary_config_value::operator[](v35, "is_cast_shadow");
          v37 = vostok::configs::binary_config_value::operator[](v36, "value");
          v32 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
          exists_vertex_inputs[3] = v37->data.pointer != 0;
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v32, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v39 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v40, (int)v39, (unsigned int)"effect") )
        {
          v41 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v42 = vostok::configs::binary_config_value::operator[](v41, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v43, (int)v42, (unsigned int)"use_alpha_test") )
          {
            v44 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
            v45 = vostok::configs::binary_config_value::operator[](v44, "effect");
            v46 = vostok::configs::binary_config_value::operator[](v45, "use_alpha_test");
            v47 = vostok::configs::binary_config_value::operator[](v46, "value");
            v38 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            exists_vertex_inputs[4] = v47->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v38, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v49 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v50, (int)v49, (unsigned int)"effect") )
        {
          v51 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v52 = vostok::configs::binary_config_value::operator[](v51, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v53, (int)v52, (unsigned int)"wind_motion") )
          {
            v54 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
            v55 = vostok::configs::binary_config_value::operator[](v54, "effect");
            v56 = vostok::configs::binary_config_value::operator[](v55, "wind_motion");
            v57 = vostok::configs::binary_config_value::operator[](v56, "value");
            v48 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            exists_vertex_inputs[5] = v57->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v48, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v59 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v60, (int)v59, (unsigned int)"effect") )
        {
          v61 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v62 = vostok::configs::binary_config_value::operator[](v61, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v63, (int)v62, (unsigned int)"use_ttranslucency") )
          {
            v64 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
            v65 = vostok::configs::binary_config_value::operator[](v64, "effect");
            v66 = vostok::configs::binary_config_value::operator[](v65, "use_ttranslucency");
            v67 = vostok::configs::binary_config_value::operator[](v66, "value");
            v58 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            exists_vertex_inputs[8] = v67->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v58, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v69 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v70, (int)v69, (unsigned int)"effect") )
        {
          v71 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v72 = vostok::configs::binary_config_value::operator[](v71, "effect");
          if ( vostok::configs::binary_config_value::value_exists(
                 v73,
                 (int)v72,
                 (unsigned int)"use_subsurface_scattering") )
          {
            v74 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
            v75 = vostok::configs::binary_config_value::operator[](v74, "effect");
            v76 = vostok::configs::binary_config_value::operator[](v75, "use_subsurface_scattering");
            v77 = vostok::configs::binary_config_value::operator[](v76, "value");
            v68 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            exists_vertex_inputs[2] = v77->data.pointer != 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v68, (int)num_vertex_inputs, (unsigned int)"g_stage") )
      {
        v79 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
        if ( vostok::configs::binary_config_value::value_exists(v80, (int)v79, (unsigned int)"effect") )
        {
          v81 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
          v82 = vostok::configs::binary_config_value::operator[](v81, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v83, (int)v82, (unsigned int)"use_olta") )
          {
            v84 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
            v85 = vostok::configs::binary_config_value::operator[](v84, "effect");
            v86 = vostok::configs::binary_config_value::operator[](v85, "use_olta");
            v87 = vostok::configs::binary_config_value::operator[](v86, "value");
            v78 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            exists_vertex_inputs[11] = v87->data.pointer != 0;
          }
        }
      }
      if ( !vostok::configs::binary_config_value::value_exists(v78, (int)num_vertex_inputs, (unsigned int)"g_stage") )
        goto LABEL_87;
      v88 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
      if ( !vostok::configs::binary_config_value::value_exists(v89, (int)v88, (unsigned int)"effect") )
        goto LABEL_87;
      v90 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
      v91 = vostok::configs::binary_config_value::operator[](v90, "effect");
      if ( !vostok::configs::binary_config_value::value_exists(v92, (int)v91, (unsigned int)"two_sided") )
        goto LABEL_87;
      v93 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "g_stage");
      v94 = vostok::configs::binary_config_value::operator[](v93, "effect");
      v95 = vostok::configs::binary_config_value::operator[](v94, "two_sided");
      v96 = vostok::configs::binary_config_value::operator[](v95, "value");
      exists_vertex_inputs[13] = v96->data.pointer != 0;
    }
    if ( v191 == 17 )
    {
      v97 = (const vostok::configs::binary_config_value *)cook_data->material.m_object;
      num_vertex_inputs = 0;
      if ( v97 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs);
        num_vertex_inputs = v97;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v97[8].id_crc, 1u);
      }
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v186,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs[16].type);
      v98 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)v186.m_object->m_lods[0].m_template.m_object,
              "material");
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v186);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs);
      if ( !vostok::configs::binary_config_value::value_exists(v99, (int)v98, (unsigned int)"lighting") )
        goto LABEL_87;
      v100 = vostok::configs::binary_config_value::operator[](v98, "lighting");
      if ( !vostok::configs::binary_config_value::value_exists(v101, (int)v100, (unsigned int)"two_sided") )
        goto LABEL_87;
      v102 = vostok::configs::binary_config_value::operator[](v98, "lighting");
      v103 = vostok::configs::binary_config_value::operator[](v102, "two_sided");
      v104 = vostok::configs::binary_config_value::operator[](v103, "value");
      exists_vertex_inputs[13] = v104->data.pointer != 0;
    }
    if ( v191 == 16 )
    {
      v105 = (vostok::particle::particle_system_instance_impl *)cook_data->material.m_object;
      v192.m_object = 0;
      if ( v105 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v192);
        v192.m_object = v105;
        _InterlockedExchangeAdd(&v105->m_reference_count, 1u);
      }
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v185,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v192.m_object->m_lods[4].m_emitter_instance_list.m_first);
      num_vertex_inputs = vostok::configs::binary_config_value::operator[](
                            (vostok::configs::binary_config_value *)v185.m_object->m_lods[0].m_template.m_object,
                            "material");
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v185);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v192);
      if ( vostok::configs::binary_config_value::value_exists(v106, (int)num_vertex_inputs, (unsigned int)"forward") )
      {
        v108 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
        if ( vostok::configs::binary_config_value::value_exists(v109, (int)v108, (unsigned int)"effect") )
        {
          v110 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
          v111 = vostok::configs::binary_config_value::operator[](v110, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v112, (int)v111, (unsigned int)"effect_id") )
          {
            v113 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
            v114 = vostok::configs::binary_config_value::operator[](v113, "effect");
            v115 = (const char **)vostok::configs::binary_config_value::operator[](v114, "effect_id");
            v116 = vostok::strings::compare(*v115, (const char *)&stru_80B4E8);
            v107 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            exists_vertex_inputs[6] = v116 == 0;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v107, (int)num_vertex_inputs, (unsigned int)"forward") )
      {
        v118 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
        if ( vostok::configs::binary_config_value::value_exists(v119, (int)v118, (unsigned int)"effect") )
        {
          v120 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
          v121 = vostok::configs::binary_config_value::operator[](v120, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v122, (int)v121, (unsigned int)"effect_id") )
          {
            v123 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
            v124 = vostok::configs::binary_config_value::operator[](v123, "effect");
            v125 = (const char **)vostok::configs::binary_config_value::operator[](v124, "effect_id");
            if ( !vostok::strings::compare(*v125, (const char *)&stru_80B4F4) )
              exists_vertex_inputs[7] = 1;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v117, (int)num_vertex_inputs, (unsigned int)"forward") )
      {
        v127 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
        if ( vostok::configs::binary_config_value::value_exists(v128, (int)v127, (unsigned int)"effect") )
        {
          v129 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
          v130 = vostok::configs::binary_config_value::operator[](v129, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v131, (int)v130, (unsigned int)"effect_id") )
          {
            v132 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
            v133 = vostok::configs::binary_config_value::operator[](v132, "effect");
            v134 = (const char **)vostok::configs::binary_config_value::operator[](v133, "effect_id");
            if ( !vostok::strings::compare(*v134, (const char *)&stru_80B510) )
              exists_vertex_inputs[12] = 1;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v126, (int)num_vertex_inputs, (unsigned int)"forward") )
      {
        v136 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
        if ( vostok::configs::binary_config_value::value_exists(v137, (int)v136, (unsigned int)"effect") )
        {
          v138 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
          v139 = vostok::configs::binary_config_value::operator[](v138, "effect");
          if ( vostok::configs::binary_config_value::value_exists(v140, (int)v139, (unsigned int)&include_getter) )
          {
            v141 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
            v142 = vostok::configs::binary_config_value::operator[](v141, "effect");
            v143 = vostok::configs::binary_config_value::operator[](v142, (char *)&include_getter);
            v144 = vostok::configs::binary_config_value::operator[](v143, "value");
            v135 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
            *((_DWORD *)exists_vertex_inputs + 4) = v144->data.pointer;
          }
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v135, (int)num_vertex_inputs, (unsigned int)"forward") )
      {
        v146 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
        if ( vostok::configs::binary_config_value::value_exists(v147, (int)v146, (unsigned int)"force_pre_distortion") )
        {
          v148 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
          v149 = vostok::configs::binary_config_value::operator[](v148, "force_pre_distortion");
          v150 = vostok::configs::binary_config_value::operator[](v149, "value");
          v145 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
          exists_vertex_inputs[9] = v150->data.pointer != 0;
        }
      }
      if ( vostok::configs::binary_config_value::value_exists(v145, (int)num_vertex_inputs, (unsigned int)"forward") )
      {
        v152 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
        if ( vostok::configs::binary_config_value::value_exists(v153, (int)v152, (unsigned int)"draw_to_gbuffer") )
        {
          v154 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
          v155 = vostok::configs::binary_config_value::operator[](v154, "draw_to_gbuffer");
          v156 = vostok::configs::binary_config_value::operator[](v155, "value");
          v151 = (vostok::configs::binary_config_value *)exists_vertex_inputs;
          exists_vertex_inputs[10] = v156->data.pointer != 0;
        }
      }
      if ( !vostok::configs::binary_config_value::value_exists(v151, (int)num_vertex_inputs, (unsigned int)"forward") )
        goto LABEL_87;
      v157 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
      if ( !vostok::configs::binary_config_value::value_exists(v158, (int)v157, (unsigned int)"two_sided") )
        goto LABEL_87;
      v159 = vostok::configs::binary_config_value::operator[](num_vertex_inputs, "forward");
      v160 = vostok::configs::binary_config_value::operator[](v159, "two_sided");
      v161 = vostok::configs::binary_config_value::operator[](v160, "value");
      exists_vertex_inputs[13] = v161->data.pointer != 0;
    }
    if ( v191 == 3 )
    {
      v162 = (const vostok::configs::binary_config_value *)cook_data->material.m_object;
      num_vertex_inputs = 0;
      if ( v162 )
      {
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs);
        num_vertex_inputs = v162;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v162[8].id_crc, 1u);
      }
      vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
        &v184,
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs[16].type);
      v163 = vostok::configs::binary_config_value::operator[](
               (vostok::configs::binary_config_value *)v184.m_object->m_lods[0].m_template.m_object,
               "material");
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v184);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs);
      if ( vostok::configs::binary_config_value::value_exists(v164, (int)v163, (unsigned int)"distortion") )
      {
        v165 = vostok::configs::binary_config_value::operator[](v163, "distortion");
        if ( vostok::configs::binary_config_value::value_exists(v166, (int)v165, (unsigned int)"two_sided") )
        {
          v167 = vostok::configs::binary_config_value::operator[](v163, "distortion");
          v168 = vostok::configs::binary_config_value::operator[](v167, "two_sided");
          v169 = vostok::configs::binary_config_value::operator[](v168, "value");
          exists_vertex_inputs[13] = v169->data.pointer != 0;
        }
      }
    }
LABEL_87:
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v183,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v193.m_object->m_sub_fat.m_parent);
    v170 = (const vostok::configs::binary_config_value *)v183.m_object;
    num_vertex_inputs = 0;
    if ( v183.m_object )
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs);
      num_vertex_inputs = v170;
      _InterlockedExchangeAdd((volatile signed __int32 *)&v170[8].id_crc, 1u);
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&num_vertex_inputs,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&exists_vertex_inputs[4 * v191 + 40]);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&num_vertex_inputs);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v183);
    goto LABEL_90;
  }
LABEL_91:
  v177 = 552;
  v176 = &vostok::resources::nocache_memory;
  v175.m_object = (survarium::pure_game_effect_emitter_base *)v15;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
    &v175,
    (survarium::pure_game_effect_emitter_base *)v190);
  v171 = (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)m_parent_query;
  vostok::resources::query_result_for_cook::set_unmanaged_resource(
    v172,
    (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_parent_query,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v175.m_object,
    v176,
    v177);
  vostok::resources::query_result_for_cook::finish_query_impl(
    v173,
    v171,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
  if ( exists_stages )
    vostok::memory::doug_lea_allocator::free_impl(
      v174,
      (int)vostok::render::g_allocator,
      (char *)&exists_stages[-1].m_helper,
      v178,
      v179,
      v180);
  if ( cook_data->delete_in_cook )
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data>(
      vostok::render::g_allocator,
      &cook_data,
      v178,
      v179,
      v180);
}
