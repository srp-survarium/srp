void __userpurge vostok::physics::collision_shape_cook::on_collision_sources_loaded(
        vostok::physics::collision_shape_cook *this@<ecx>,
        float a2@<xmm10>,
        vostok::resources::queries_result *data,
        vostok::physics::collision_shape_cook::cook_data *cd)
{
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v5; // esi
  vostok::particle::particle_system_instance_impl *v6; // esi
  volatile int m_flags; // ecx
  const vostok::configs::binary_config_value *v8; // eax
  vostok::physics::collision_shape_cook *v9; // ecx
  survarium::pure_game_effect_emitter_base *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  vostok::configs::binary_config_value **m_lods; // esi
  const vostok::configs::binary_config_value *v13; // esi
  bool v14; // zf
  survarium::pure_game_effect_emitter_base *v15; // esi
  const vostok::configs::binary_config_value *v16; // eax
  vostok::configs::binary_config_value *v17; // ecx
  char *v18; // edi
  vostok::configs::binary_config_value *v19; // eax
  survarium::game_material_manager *v20; // ecx
  unsigned __int16 pointer; // di
  survarium::pure_game_effect_emitter_base *material; // eax
  unsigned int j; // eax
  vostok::resources::managed_resource *v24; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v25; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v26; // ecx
  vostok::resources::managed_resource *v27; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v28; // ecx
  vostok::memory::chunk_reader *v29; // ecx
  vostok::memory::chunk_reader *v30; // ecx
  vostok::memory::chunk_reader *v31; // ecx
  vostok::memory::chunk_reader *v32; // ecx
  vostok::memory::chunk_reader *v33; // ecx
  vostok::resources::managed_resource *v34; // esi
  const unsigned __int16 *v35; // ebx
  const unsigned __int8 *m_pointer; // esi
  vostok::memory::base_allocator *v37; // esi
  char *v38; // eax
  unsigned int v39; // ebx
  vostok::memory::base_allocator_vtbl *v40; // edx
  unsigned int v41; // edi
  unsigned int v42; // edi
  _WORD *v43; // edi
  int k; // ecx
  vostok::memory::reader *v45; // ecx
  char *v46; // edi
  vostok::configs::binary_config_value *v47; // ecx
  __int16 v48; // si
  const vostok::configs::binary_config_value *v49; // eax
  vostok::configs::binary_config_value *v50; // ecx
  vostok::configs::binary_config_value *v51; // eax
  vostok::memory::base_allocator *v52; // esi
  char *v53; // eax
  unsigned int v54; // edi
  survarium::pure_game_effect_emitter_base *v55; // ecx
  const survarium::game_material *v56; // eax
  const unsigned __int8 *v57; // esi
  __int16 v58; // si
  survarium::pure_game_effect_emitter_base *v59; // edi
  vostok::resources::managed_resource *managed_resource; // eax
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v61; // edi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v62; // eax
  btBvhTriangleMeshShape *v63; // edi
  vostok::physics::bt_collision_shape *v64; // eax
  vostok::resources::unmanaged_resource *v65; // ecx
  survarium::pure_game_effect_emitter_base *v66; // eax
  survarium::pure_game_effect_emitter_base *v67; // esi
  vostok::resources::pinned_ptr_const<unsigned char> *v68; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v69; // eax
  const btTransform *v70; // esi
  vostok::math::float4x4 *v71; // ecx
  vostok::math::float4x4 *v72; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v73; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v74; // ecx
  vostok::resources::query_result_for_cook *v75; // ecx
  vostok::resources::query_result_for_cook *parent_query; // edi
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v77; // [esp+24h] [ebp-24Ch] BYREF
  assert_on_fail_bool v78; // [esp+28h] [ebp-248h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v79; // [esp+2Ch] [ebp-244h] BYREF
  vostok::memory::chunk_reader::chunk_type v80; // [esp+30h] [ebp-240h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v81; // [esp+3Ch] [ebp-234h] BYREF
  unsigned int i; // [esp+40h] [ebp-230h]
  unsigned int v83; // [esp+44h] [ebp-22Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v84; // [esp+48h] [ebp-228h] BYREF
  survarium::pure_game_effect_emitter_base *object; // [esp+4Ch] [ebp-224h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v86; // [esp+50h] [ebp-220h] BYREF
  PHY_ScalarType btBvhTriangleMeshShape; // [esp+54h] [ebp-21Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v88; // [esp+58h] [ebp-218h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v89; // [esp+5Ch] [ebp-214h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v90; // [esp+60h] [ebp-210h] BYREF
  vostok::resources::query_result *v91; // [esp+64h] [ebp-20Ch]
  vostok::memory::reader v92; // [esp+68h] [ebp-208h] BYREF
  unsigned int v93; // [esp+74h] [ebp-1FCh]
  vostok::memory::chunk_reader v94; // [esp+78h] [ebp-1F8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+98h] [ebp-1D8h] BYREF
  unsigned __int8 *dataa; // [esp+9Ch] [ebp-1D4h]
  unsigned int size; // [esp+A0h] [ebp-1D0h]
  const unsigned __int8 *v98; // [esp+A4h] [ebp-1CCh] BYREF
  vostok::math::float3 *v99; // [esp+A8h] [ebp-1C8h]
  unsigned int v100; // [esp+ACh] [ebp-1C4h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v101; // [esp+B0h] [ebp-1C0h] BYREF
  unsigned __int8 *v102; // [esp+B4h] [ebp-1BCh]
  unsigned int v103; // [esp+B8h] [ebp-1B8h]
  const unsigned __int8 *v104; // [esp+BCh] [ebp-1B4h] BYREF
  unsigned int *v105; // [esp+C0h] [ebp-1B0h]
  unsigned int v106; // [esp+C4h] [ebp-1ACh]
  vostok::configs::binary_config_value v107; // [esp+C8h] [ebp-1A8h] BYREF
  vostok::math::float4x4 v108; // [esp+E0h] [ebp-190h] BYREF
  btTransform v109; // [esp+120h] [ebp-150h] BYREF
  _BYTE *v110; // [esp+160h] [ebp-110h]
  _BYTE *v111; // [esp+164h] [ebp-10Ch]
  char *v112; // [esp+168h] [ebp-108h]
  _BYTE v113[260]; // [esp+16Ch] [ebp-104h] BYREF
  char vars0; // [esp+270h] [ebp+0h] BYREF

  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v81,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = (vostok::particle::particle_system_instance_impl *)v81.m_object;
  v90.m_object = 0;
  if ( v81.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v90);
    v90.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v81);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v81,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[1].m_unmanaged_resource);
  v5 = (vostok::particle::particle_system_instance_impl *)v81.m_object;
  v84.m_object = 0;
  if ( v81.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v84);
    v84.m_object = v5;
    _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v81);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v81,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&data->m_queries[5].m_unmanaged_resource);
  v6 = (vostok::particle::particle_system_instance_impl *)v81.m_object;
  v89.m_object = 0;
  if ( v81.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v89);
    v89.m_object = v6;
    _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v81);
  object = 0;
  if ( v90.m_object )
  {
    m_flags = (volatile int)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      qmemcpy(&v94, v90.m_object->m_lods[0].m_template.m_object, 0x18u);
      v8 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)&v94, "primitives");
      vostok::physics::collision_shape_cook::create_primitives_shape(v9, a2, v8, cd);
      object = v10;
      v11 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)&v94, "primitives");
      m_flags = 24;
      v83 = 24 * v11->count / 24;
      if ( v84.m_object
        && (m_lods = (vostok::configs::binary_config_value **)v84.m_object->m_lods,
            vostok::configs::binary_config_value::value_exists(
              (vostok::configs::binary_config_value *)0x18,
              (int)v84.m_object->m_lods[0].m_template.m_object,
              (unsigned int)"game_material_settings")) )
      {
        v13 = vostok::configs::binary_config_value::operator[](*m_lods, "game_material_settings");
        v14 = !cd->fill_gmtl;
        qmemcpy((void *)&v107, v13, sizeof(v107));
        m_flags = 0;
        if ( !v14 )
        {
          v81.m_object = 0;
          for ( i = 0; i < v83; ++i )
          {
            v15 = object;
            btBvhTriangleMeshShape = *(unsigned __int16 *)(object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                                         + 2 * i);
            v16 = vostok::configs::binary_config_value::operator[](
                    (vostok::configs::binary_config_value *)&v94,
                    "mtl_list");
            v17 = (vostok::configs::binary_config_value *)(24 * (unsigned __int16)btBvhTriangleMeshShape);
            v18 = *(char **)((char *)&v17->data.pointer + (unsigned int)v16->data.pointer);
            if ( vostok::configs::binary_config_value::value_exists(v17, (int)&v107, (unsigned int)v18) )
            {
              v19 = vostok::configs::binary_config_value::operator[](&v107, v18);
              pointer = (unsigned __int16)vostok::configs::binary_config_value::operator[](v19, "game_material_id")->data.pointer;
              material = v81.m_object;
              if ( !v81.m_object || WORD2(v81.m_object->m_current_satisfaction_update_tick) != pointer )
              {
                material = (survarium::pure_game_effect_emitter_base *)survarium::game_material_manager::get_material(
                                                                         v20,
                                                                         (int)v89.m_object,
                                                                         pointer);
                v81.m_object = material;
              }
              m_flags = v15[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
              *(_WORD *)(m_flags + 2 * i) = pointer | (LOBYTE(material->m_next_in_increase_quality_queue) << 14);
            }
            else
            {
              m_flags = 0xFFFF;
              *(_WORD *)(v15[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                       + 2 * i) = -1;
            }
          }
        }
      }
      else
      {
        for ( j = 0; j < v83; ++j )
        {
          m_flags = object[1].vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
          *(_WORD *)(m_flags + 2 * j) = -1;
        }
      }
    }
  }
  v91 = &data->m_queries[2];
  if ( vostok::resources::query_result_for_user::is_successful(
         (vostok::resources::query_result_for_user *)m_flags,
         (int)&data->m_queries[2]) )
  {
    v79.m_object = v24;
    vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[2], &v79);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v25,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v107,
      v79);
    v79.m_object = (vostok::resources::managed_resource *)&data->m_queries[3];
    v88.m_object = (vostok::resources::managed_resource *)&data->m_queries[3];
    vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[3], &v79);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v26,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
      v79);
    v79.m_object = v27;
    vostok::resources::query_result_for_user::get_managed_resource(&data->m_queries[4], &v79);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v28,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&v101,
      v79);
    vostok::memory::chunk_reader::chunk_reader(
      &v94,
      (const unsigned __int8 *)HIDWORD(v107.data.max_storage),
      v29,
      (unsigned int)v107.id.pointer,
      v80);
    vostok::memory::chunk_reader::chunk_reader((vostok::memory::chunk_reader *)&v109, dataa, v30, size, v80);
    vostok::memory::chunk_reader::chunk_reader((vostok::memory::chunk_reader *)&v108, v102, v31, v103, v80);
    vostok::memory::chunk_reader::open_reader(v32, &v94, &v98, (vostok::memory::chunk_reader::chunk_type *)0x19, v80);
    vostok::memory::chunk_reader::open_reader(
      v33,
      (vostok::memory::chunk_reader *)&v109,
      &v104,
      (vostok::memory::chunk_reader::chunk_type *)0x1A,
      v80);
    v34 = (vostok::resources::managed_resource *)(v106 >> 2);
    v35 = 0;
    v86.m_object = (vostok::resources::managed_resource *)(v106 >> 2);
    btBvhTriangleMeshShape = v100 / 0xC;
    v93 = (v106 >> 2) / 3;
    if ( v84.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::memory::chunk_reader::open_reader(
        (vostok::memory::chunk_reader *)3,
        (vostok::memory::chunk_reader *)&v108,
        &v92.m_data,
        (vostok::memory::chunk_reader::chunk_type *)0x1B,
        v80);
      m_pointer = v92.m_pointer;
      v92.m_pointer += 2;
      LOWORD(i) = *(_WORD *)m_pointer;
      v37 = vostok::physics::g_allocator;
      v38 = type_info::raw_name(&vostok::resources::IAEXAAVqueries_result::`vostok::physics::collision_shape_cook::on_collision_sources_loaded'::`32'::remap `RTTI Type Descriptor');
      v39 = (unsigned __int16)i;
      v40 = v37->__vftable;
      v79.m_object = (vostok::resources::managed_resource *)174;
      v41 = 2 * (unsigned __int16)i;
      v83 = (unsigned int)v40->call_malloc(
                            v37,
                            v41,
                            v38,
                            "vostok::physics::collision_shape_cook::on_collision_sources_loaded",
                            ".\\collision_shape_cook.cpp",
                            174u);
      memset(v83, 0, v41);
      if ( (_WORD)i )
      {
        v42 = v83;
        memset((void *)v83, 0xFFu, 4 * (v39 >> 1));
        v43 = (_WORD *)(v42 + 4 * (v39 >> 1));
        for ( k = v39 & 1; k; --k )
          *v43++ = -1;
      }
      qmemcpy(&v94, v84.m_object->m_lods[0].m_template.m_object, 0x18u);
      if ( vostok::configs::binary_config_value::value_exists(0, (int)&v94, (unsigned int)"game_material_settings") )
      {
        qmemcpy(
          &v94,
          vostok::configs::binary_config_value::operator[](
            (vostok::configs::binary_config_value *)&v94,
            "game_material_settings"),
          0x18u);
        v45 = 0;
        if ( (_WORD)i )
        {
          v81.m_object = (survarium::pure_game_effect_emitter_base *)v83;
          i = v39;
          do
          {
            v46 = (char *)vostok::memory::reader::r_string(v45, &v92);
            v110 = v113;
            v111 = v113;
            v112 = &vars0;
            v113[0] = 0;
            if ( vostok::configs::binary_config_value::value_exists(v47, (int)&v94, (unsigned int)v46) )
            {
              v79.m_object = (vostok::resources::managed_resource *)"game_material_id";
              v48 = -1;
              v49 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)&v94, v46);
              if ( vostok::configs::binary_config_value::value_exists(v50, (int)v49, (unsigned int)v79.m_object) )
              {
                v51 = vostok::configs::binary_config_value::operator[](
                        (vostok::configs::binary_config_value *)&v94,
                        v46);
                v48 = (__int16)vostok::configs::binary_config_value::operator[](v51, "game_material_id")->data.pointer;
              }
              LOWORD(v81.m_object->__vftable) = v48;
            }
            v81.m_object = (survarium::pure_game_effect_emitter_base *)((char *)v81.m_object + 2);
            --i;
          }
          while ( i );
        }
      }
      v92 = *vostok::memory::chunk_reader::open_reader(
               (vostok::memory::chunk_reader *)v45,
               (vostok::memory::chunk_reader *)&v108,
               (const unsigned __int8 **)&v94,
               (vostok::memory::chunk_reader::chunk_type *)0x1C,
               v80);
      v52 = vostok::physics::g_allocator;
      v53 = type_info::raw_name(&unsigned short `RTTI Type Descriptor');
      v54 = v93;
      v35 = (const unsigned __int16 *)v52->call_malloc(
                                        v52,
                                        2 * v93,
                                        v53,
                                        "vostok::physics::collision_shape_cook::on_collision_sources_loaded",
                                        ".\\collision_shape_cook.cpp",
                                        203u);
      if ( cd->fill_gmtl )
      {
        v55 = 0;
        v56 = 0;
        v81.m_object = 0;
        if ( v54 )
        {
          do
          {
            v57 = v92.m_pointer;
            v92.m_pointer += 2;
            LOWORD(i) = *(_WORD *)v57;
            v58 = *(_WORD *)(v83 + 2 * (unsigned __int16)i);
            if ( !v56 || v56->m_id != v58 )
            {
              v56 = survarium::game_material_manager::get_material(
                      (survarium::game_material_manager *)v55,
                      (int)v89.m_object,
                      *(_WORD *)(v83 + 2 * (unsigned __int16)i));
              v55 = v81.m_object;
            }
            v35[(_DWORD)v55] = v58 | (v56->m_walker_behaviour << 14);
            v55 = (survarium::pure_game_effect_emitter_base *)((char *)v55 + 1);
            v81.m_object = v55;
          }
          while ( (unsigned int)v55 < v93 );
        }
      }
      if ( v83 )
        vostok::physics::g_allocator->call_free(
          vostok::physics::g_allocator,
          (void *)v83,
          "vostok::physics::collision_shape_cook::on_collision_sources_loaded",
          ".\\collision_shape_cook.cpp",
          221u);
      v34 = v86.m_object;
    }
    v59 = object;
    managed_resource = (vostok::resources::managed_resource *)vostok::resources::query_result_for_user::get_managed_resource(
                                                                (vostok::resources::query_result_for_user *)v88.m_object,
                                                                &v86);
    if ( v59 )
    {
      v79.m_object = managed_resource;
      v69 = vostok::resources::query_result_for_user::get_managed_resource(v91, &v88);
      btBvhTriangleMeshShape = (PHY_ScalarType)vostok::physics::create_btBvhTriangleMeshShape(
                                                 (unsigned int)v34,
                                                 &cd->scale_,
                                                 v99,
                                                 v105,
                                                 btBvhTriangleMeshShape,
                                                 v35,
                                                 v69,
                                                 (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)v79.m_object);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v88);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v86);
      v70 = (const btTransform *)v59[1].__vftable;
      v72 = vostok::math::float4x4::identity(v71, &v108);
      vostok::physics::from_vostok(v72, &v109.m_basis);
      btCompoundShape::addChildShape(
        (btCompoundShape *)v79.m_object,
        v70,
        &v109,
        (btCollisionShape *)btBvhTriangleMeshShape);
      v59[1].type = (unsigned int)v35;
    }
    else
    {
      v61 = (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)managed_resource;
      v62 = vostok::resources::query_result_for_user::get_managed_resource(v91, &v88);
      v63 = vostok::physics::create_btBvhTriangleMeshShape(
              (unsigned int)v34,
              &cd->scale_,
              v99,
              v105,
              btBvhTriangleMeshShape,
              v35,
              v62,
              v61);
      v64 = (vostok::physics::bt_collision_shape *)vostok::memory::new_helper<vostok::physics::bt_collision_shape>::call<vostok::memory::base_allocator>(
                                                     vostok::physics::g_allocator,
                                                     "vostok::physics::create_static_triangle_mesh_shape",
                                                     (const char *const)0x157);
      if ( v64 )
      {
        vostok::physics::bt_collision_shape::bt_collision_shape(v64, v63, v65);
        v67 = v66;
      }
      else
      {
        v67 = 0;
      }
      object = v67;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v88);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v86);
      v67[1].type = (unsigned int)v35;
    }
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v68);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v73);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v74);
  }
  if ( object )
  {
    v79.m_object = (vostok::resources::managed_resource *)280;
    v78 = (assert_on_fail_bool)&vostok::resources::nocache_memory;
    v77.m_object = (survarium::pure_game_effect_emitter_base *)v24;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v77,
      object);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      v75,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)cd->parent_query,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v77.m_object,
      (const vostok::resources::memory_type *)v78,
      (unsigned int)v79.m_object);
    parent_query = cd->parent_query;
    v79.m_object = 0;
    v78 = assert_on_fail_true;
    v77.m_object = (survarium::pure_game_effect_emitter_base *)3;
  }
  else
  {
    parent_query = cd->parent_query;
    v79.m_object = (vostok::resources::managed_resource *)11;
    v78 = assert_on_fail_true;
    v77.m_object = (survarium::pure_game_effect_emitter_base *)1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)v24,
    (const vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)parent_query,
    (vostok::resources::cook_base::result_enum)v77.m_object,
    v78,
    (vostok::resources::cook_base::result_enum)v79.m_object);
  vostok::physics::g_allocator->call_free(
    vostok::physics::g_allocator,
    cd,
    "vostok::physics::collision_shape_cook::on_collision_sources_loaded",
    ".\\collision_shape_cook.cpp",
    260u);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v89);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v84);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v90);
}
