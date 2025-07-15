void __userpurge vostok::physics::collision_shape_cook::on_collision_sources_loaded(
        vostok::physics::collision_shape_cook *this@<ecx>,
        float a2@<xmm4>,
        vostok::resources::queries_result *data,
        vostok::physics::collision_shape_cook::cook_data *cd)
{
  vostok::resources::queries_result *v4; // edi
  vostok::configs::binary_config *m_object; // esi
  vostok::configs::binary_config *v6; // esi
  const vostok::configs::binary_config_value *v7; // eax
  unsigned int v8; // esi
  unsigned int i; // edi
  vostok::configs::binary_config_value *v10; // eax
  const void *pointer; // eax
  volatile int m_flags; // edx
  unsigned int v13; // edi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v14; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v15; // esi
  unsigned int v16; // edi
  unsigned __int16 v17; // cx
  vostok::memory::base_allocator_vtbl *v18; // edx
  unsigned int v19; // esi
  __int16 v20; // si
  vostok::resources::managed_resource *v21; // edi
  char v22; // cf
  unsigned int v23; // ecx
  _WORD *v24; // edi
  int j; // ecx
  vostok::resources::managed_resource *v26; // ecx
  vostok::resources::managed_resource *v27; // ecx
  float y; // eax
  float k; // esi
  vostok::configs::binary_config_value *v30; // eax
  vostok::configs::binary_config_value *v31; // eax
  const void *v32; // eax
  unsigned int v33; // eax
  const unsigned __int8 *v34; // eax
  int v35; // ecx
  void *(__thiscall *call_malloc)(vostok::memory::base_allocator *, unsigned int); // eax
  unsigned __int16 *v37; // eax
  unsigned int v38; // ecx
  float v39; // eax
  vostok::resources::unmanaged_resource *v40; // edi
  vostok::resources::managed_resource_vtbl *v41; // eax
  vostok::resources::managed_resource *v42; // eax
  vostok::physics::bt_collision_shape *v43; // esi
  vostok::resources::managed_resource_vtbl *v44; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v45; // eax
  long double v46; // st7
  unsigned int v47; // xmm0_4
  float v48; // xmm7_4
  float v49; // xmm6_4
  float v50; // xmm2_4
  char *v51; // xmm4_4
  float v52; // xmm0_4
  float v53; // xmm3_4
  float v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm3_4
  float v57; // xmm5_4
  float v58; // xmm4_4
  float v59; // xmm5_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  unsigned int v62; // xmm7_4
  float v63; // xmm1_4
  float v64; // xmm6_4
  btVector3 v65; // xmm0
  const unsigned __int8 *v66; // eax
  const unsigned __int8 *v67; // ecx
  const unsigned __int8 *v68; // eax
  const unsigned __int8 *v69; // eax
  const unsigned __int8 *v70; // ecx
  const unsigned __int8 *v71; // eax
  const unsigned __int8 *v72; // eax
  const unsigned __int8 *v73; // ecx
  const unsigned __int8 *v74; // eax
  vostok::resources::query_result_for_cook *v75; // ecx
  vostok::configs::binary_config *v76; // eax
  vostok::resources::unmanaged_intrusive_base *v77; // ecx
  vostok::configs::binary_config *v78; // eax
  vostok::resources::unmanaged_intrusive_base *v79; // ecx
  vostok::resources::unmanaged_resource *v80; // [esp+400Ch] [ebp-30Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> _X; // [esp+4014h] [ebp-304h] BYREF
  vostok::physics::collision_shape_cook *v82; // [esp+4018h] [ebp-300h]
  char *key; // [esp+402Ch] [ebp-2ECh] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v84; // [esp+4030h] [ebp-2E8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v85; // [esp+4034h] [ebp-2E4h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v86; // [esp+4038h] [ebp-2E0h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v87; // [esp+403Ch] [ebp-2DCh] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> indices_resource; // [esp+4040h] [ebp-2D8h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> ptr; // [esp+4044h] [ebp-2D4h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v90; // [esp+4048h] [ebp-2D0h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+404Ch] [ebp-2CCh] BYREF
  unsigned __int16 *v92; // [esp+4050h] [ebp-2C8h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v93; // [esp+4054h] [ebp-2C4h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> vertices_resource; // [esp+4058h] [ebp-2C0h] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v95; // [esp+405Ch] [ebp-2BCh] BYREF
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v96; // [esp+4060h] [ebp-2B8h] BYREF
  vostok::math::float3 axis; // [esp+4064h] [ebp-2B4h] BYREF
  vostok::resources::pinned_ptr_base<unsigned char const > v98; // [esp+4070h] [ebp-2A8h] BYREF
  vostok::resources::pinned_ptr_base<unsigned char const > v99; // [esp+407Ch] [ebp-29Ch] BYREF
  __m128i v100; // [esp+4088h] [ebp-290h] BYREF
  vostok::resources::pinned_ptr_base<unsigned char const > v101; // [esp+409Ch] [ebp-27Ch] BYREF
  vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader> v102; // [esp+40A8h] [ebp-270h] BYREF
  char v103; // [esp+40A9h] [ebp-26Fh] BYREF
  _BYTE v104[2]; // [esp+40AAh] [ebp-26Eh] BYREF
  const unsigned __int8 *v105; // [esp+40ACh] [ebp-26Ch]
  const unsigned __int8 *v106; // [esp+40B0h] [ebp-268h]
  unsigned int v107; // [esp+40B4h] [ebp-264h]
  int v108; // [esp+40B8h] [ebp-260h]
  int v109; // [esp+40BCh] [ebp-25Ch]
  int v110; // [esp+40C0h] [ebp-258h]
  int v111; // [esp+40C4h] [ebp-254h]
  unsigned int v112; // [esp+40C8h] [ebp-250h] BYREF
  int v113; // [esp+40CCh] [ebp-24Ch]
  const unsigned __int8 *m_data; // [esp+40D4h] [ebp-244h]
  vostok::math::float3 *vertices; // [esp+40D8h] [ebp-240h]
  unsigned int m_size; // [esp+40DCh] [ebp-23Ch]
  int v117; // [esp+40E0h] [ebp-238h]
  int v118; // [esp+40E4h] [ebp-234h]
  int v119; // [esp+40E8h] [ebp-230h]
  int v120; // [esp+40ECh] [ebp-22Ch]
  const unsigned __int8 *v121; // [esp+40F4h] [ebp-224h]
  unsigned int *indices; // [esp+40F8h] [ebp-220h]
  unsigned int v123; // [esp+40FCh] [ebp-21Ch]
  int v124; // [esp+4100h] [ebp-218h]
  int v125; // [esp+4104h] [ebp-214h]
  int v126; // [esp+4108h] [ebp-210h]
  int v127; // [esp+410Ch] [ebp-20Ch]
  unsigned int v128; // [esp+4110h] [ebp-208h] BYREF
  unsigned int chunk_id; // [esp+4114h] [ebp-204h] BYREF
  vostok::configs::binary_config_value v130; // [esp+4118h] [ebp-200h] BYREF
  vostok::configs::binary_config_value v131; // [esp+4130h] [ebp-1E8h] BYREF
  btTransform localTransform; // [esp+4148h] [ebp-1D0h] BYREF
  vostok::configs::binary_config_value v133; // [esp+4188h] [ebp-190h] BYREF
  vostok::configs::binary_config_value v134; // [esp+41A0h] [ebp-178h] BYREF
  vostok::math::quaternion v135; // [esp+41B8h] [ebp-160h] BYREF
  _BYTE *v136; // [esp+41C8h] [ebp-150h]
  _BYTE *v137; // [esp+41CCh] [ebp-14Ch]
  vostok::math::float4x4 *v138; // [esp+41D0h] [ebp-148h]
  _BYTE v139[260]; // [esp+41D4h] [ebp-144h] BYREF
  vostok::math::float4x4 v140; // [esp+42D8h] [ebp-40h] BYREF

  v4 = data;
  *(float *)&key = 0.0;
  *(float *)&v86.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v86,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v86.m_object;
  v96.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v96,
    v86.m_object);
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  *(float *)&v84.m_object = 0.0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v84,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v6 = v84.m_object;
  v95.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v95,
    v84.m_object);
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  ptr.m_object = 0;
  if ( v96.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v130 = *v96.m_object->m_root;
    v7 = vostok::configs::binary_config_value::operator[](&v130, "primitives");
    ptr.m_object = vostok::physics::collision_shape_cook::create_primitives_shape(v7, cd, a2, v82);
    v8 = 24 * vostok::configs::binary_config_value::operator[](&v130, "primitives")->count / 24;
    if ( v95.m_object
      && vostok::configs::binary_config_value::value_exists(v95.m_object->m_root, "game_material_settings") )
    {
      v134 = *vostok::configs::binary_config_value::operator[](v95.m_object->m_root, "game_material_settings");
      for ( i = 0; i < v8; ++i )
      {
        key = (char *)*(unsigned __int16 *)(ptr.m_object[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                          + 2 * i);
        key = *((char **)vostok::configs::binary_config_value::operator[](&v130, "mtl_list")->data.pointer
              + 6 * (unsigned __int16)key);
        if ( vostok::configs::binary_config_value::value_exists(&v134, key) )
        {
          v10 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](&v134, key);
          pointer = vostok::configs::binary_config_value::operator[](v10, "game_material_id")->data.pointer;
          m_flags = ptr.m_object[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
          v113 = 0;
          *(_WORD *)(m_flags + 2 * i) = (_WORD)pointer;
        }
        else
        {
          *(_WORD *)(ptr.m_object[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                   + 2 * i) = 0;
        }
      }
      v4 = data;
    }
    else
    {
      memset(
        ptr.m_object[1].vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
        0,
        2 * v8);
    }
  }
  if ( v4->m_queries[2].m_error_type == error_type_unset && v4->m_queries[2].m_create_resource_result != result_error )
  {
    object.m_object = 0;
    key = (char *)&v4->m_queries[2].m_managed_resource;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &object,
      &v4->m_queries[2].m_managed_resource);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      &object);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &v101,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)_X.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
    v90.m_object = 0;
    v93.m_object = (vostok::resources::managed_resource *)&v4->m_queries[3].m_managed_resource;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v90,
      &v4->m_queries[3].m_managed_resource);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      &v90);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &v99,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)_X.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v90);
    v87.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v87,
      &v4->m_queries[4].m_managed_resource);
    _X.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &_X,
      &v87);
    vostok::resources::pinned_ptr_base<unsigned char const>::pinned_ptr_base<unsigned char const>(
      &v98,
      (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)_X.m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v87);
    m_data = v101.m_data;
    vertices = (vostok::math::float3 *)v101.m_data;
    m_size = v101.m_size;
    v121 = v99.m_data;
    indices = (unsigned int *)v99.m_data;
    v105 = v98.m_data;
    v106 = v98.m_data;
    v123 = v99.m_size;
    v117 = 0;
    v119 = 0;
    v120 = 0;
    v118 = 0;
    v124 = 0;
    v126 = 0;
    v127 = 0;
    v125 = 0;
    v107 = v98.m_size;
    v108 = 0;
    v110 = 0;
    v111 = 0;
    v109 = 0;
    v13 = vostok::memory::chunk_reader::chunk_size(
            (vostok::memory::chunk_reader *)0x19,
            (const unsigned int)&chunk_id,
            (vostok::memory::chunk_reader::chunk_type *)v82);
    v14.m_object = (vostok::resources::managed_resource *)(vostok::memory::chunk_reader::chunk_size(
                                                             (vostok::memory::chunk_reader *)0x1A,
                                                             (const unsigned int)&v128,
                                                             (vostok::memory::chunk_reader::chunk_type *)v82) >> 2);
    v15.m_object = (vostok::configs::binary_config *)(v13 / 0xC);
    v16 = (unsigned int)v14.m_object / 3;
    v86.m_object = v15.m_object;
    v85.m_object = v14.m_object;
    v90.m_object = (vostok::resources::managed_resource *)((unsigned int)v14.m_object / 3);
    v92 = 0;
    if ( v95.m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      *(float *)&indices_resource.m_object = COERCE_FLOAT(
                                               vostok::memory::chunk_reader::chunk_size(
                                                 (vostok::memory::chunk_reader *)0x1B,
                                                 (const unsigned int)&v112,
                                                 (vostok::memory::chunk_reader::chunk_type *)v82));
      v17 = *(_WORD *)v106;
      LODWORD(axis.y) = v106 + 2;
      LOWORD(v92) = v17;
      v18 = vostok::physics::g_ph_allocator->__vftable;
      v19 = 2 * v17;
      v84.m_object = (vostok::configs::binary_config *)v17;
      object.m_object = (vostok::resources::managed_resource *)v18->call_malloc(vostok::physics::g_ph_allocator, v19);
      memset((int)object.m_object, 0, v19);
      v20 = (__int16)v92;
      if ( (_WORD)v92 )
      {
        v21 = object.m_object;
        v22 = (int)v84.m_object & 1;
        v23 = (unsigned int)v84.m_object >> 1;
        memset(object.m_object, 0xFFu, 4 * ((unsigned int)v84.m_object >> 1));
        v24 = &v21->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
            + v23;
        for ( j = v22; j; --j )
          *v24++ = -1;
        v16 = (unsigned int)v90.m_object;
      }
      v133 = *v95.m_object->m_root;
      if ( vostok::configs::binary_config_value::value_exists(&v133, "game_material_settings") )
      {
        v131 = *vostok::configs::binary_config_value::operator[](&v133, "game_material_settings");
        v26 = 0;
        if ( v20 )
        {
          v27 = (vostok::resources::managed_resource *)((char *)indices_resource.m_object + (unsigned int)v106);
          indices_resource.m_object = (vostok::resources::managed_resource *)((char *)indices_resource.m_object
                                                                            + (unsigned int)v106);
          v87.m_object = object.m_object;
          while ( 1 )
          {
            y = axis.y;
            for ( k = axis.y; (vostok::resources::managed_resource *)LODWORD(y) != v27; ++LODWORD(y) )
            {
              if ( !*(_BYTE *)LODWORD(y) )
                break;
            }
            LODWORD(axis.y) = LODWORD(y) + 1;
            v136 = v139;
            v137 = v139;
            v138 = &v140;
            v139[0] = 0;
            if ( vostok::configs::binary_config_value::value_exists(&v131, (char *)LODWORD(k)) )
            {
              _X.m_object = (vostok::resources::managed_resource *)"game_material_id";
              vertices_resource.m_object = (vostok::resources::managed_resource *)0xFFFF;
              v30 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                              &v131,
                                                              (char *)LODWORD(k));
              if ( vostok::configs::binary_config_value::value_exists(v30, (char *)_X.m_object) )
              {
                _X.m_object = (vostok::resources::managed_resource *)"game_material_id";
                v31 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                                &v131,
                                                                (char *)LODWORD(k));
                v32 = vostok::configs::binary_config_value::operator[](v31, (char *)_X.m_object)->data.pointer;
                v113 = 0;
              }
              else
              {
                LOWORD(v32) = vertices_resource.m_object;
              }
              v26 = v87.m_object;
              LOWORD(v87.m_object->__vftable) = (_WORD)v32;
            }
            v87.m_object = (vostok::resources::managed_resource *)((char *)v87.m_object + 2);
            --v84.m_object;
            if ( *(float *)&v84.m_object == 0.0 )
              break;
            v27 = indices_resource.m_object;
          }
        }
      }
      _X.m_object = (vostok::resources::managed_resource *)28;
      if ( v111 )
      {
        if ( v111 == 1 )
          v33 = vostok::memory::array_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
                  (vostok::memory::array_chunk_reader<vostok::memory::chunk_reader> *)v26,
                  (int)&v103,
                  (unsigned int)_X.m_object);
        else
          v33 = vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
                  (vostok::memory::associative_chunk_reader<vostok::memory::chunk_reader> *)v26,
                  (int)v104,
                  (unsigned int)_X.m_object);
        v16 = (unsigned int)v90.m_object;
      }
      else
      {
        v33 = vostok::memory::sequential_chunk_reader<vostok::memory::chunk_reader>::chunk_position(
                &v102,
                (unsigned int)_X.m_object);
      }
      v34 = &v105[v33];
      v35 = *((_DWORD *)v34 + 1) & 0x3FFFFFFF;
      v100.m128i_i32[0] = (int)(v34 + 8);
      v100.m128i_i32[1] = (int)(v34 + 8);
      LODWORD(axis.z) = v35;
      call_malloc = vostok::physics::g_ph_allocator->call_malloc;
      *(_QWORD *)&axis.x = v100.m128i_i64[0];
      v37 = (unsigned __int16 *)call_malloc(vostok::physics::g_ph_allocator, 2 * v16);
      v38 = 0;
      v92 = v37;
      if ( v16 )
      {
        v39 = axis.y;
        do
        {
          v92[v38++] = *((_WORD *)&object.m_object->__vftable + (unsigned __int16)*(_WORD *)LODWORD(v39));
          LODWORD(v39) += 2;
        }
        while ( v38 < v16 );
      }
      if ( object.m_object )
        vostok::physics::g_ph_allocator->call_free(vostok::physics::g_ph_allocator, object.m_object);
      v14.m_object = v85.m_object;
      v15.m_object = v86.m_object;
    }
    v40 = ptr.m_object;
    if ( ptr.m_object )
    {
      v44 = v93.m_object->__vftable;
      *(float *)&v85.m_object = 0.0;
      if ( *(float *)&v44 != 0.0 )
      {
        v85.m_object = (vostok::resources::managed_resource *)v44;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v44[7].is_increasing_quality, 1u);
      }
      v45.m_object = *(vostok::resources::managed_resource **)key;
      *(float *)&v93.m_object = 0.0;
      if ( *(float *)&v45.m_object != 0.0 )
      {
        v93.m_object = v45.m_object;
        _InterlockedExchangeAdd(&v45.m_object->m_reference_count, 1u);
      }
      v87.m_object = (vostok::resources::managed_resource *)vostok::physics::create_btBvhTriangleMeshShape(
                                                              (int)v15.m_object,
                                                              &cd->scale_,
                                                              vertices,
                                                              indices,
                                                              (unsigned int)v14.m_object,
                                                              v92,
                                                              &v93,
                                                              &v85);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v93);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v85);
      v90.m_object = (vostok::resources::managed_resource *)v40[1].__vftable;
      *(float *)&v85.m_object = COERCE_FLOAT(vostok::math::float4x4::identity(&v140));
      vostok::math::quaternion::quaternion(&v135, (const vostok::math::float4x4 *)v85.m_object);
      vostok::math::quaternion::get_axis_and_angle(&v135, &axis, (float *)&key);
      *(float *)&v86.m_object = -axis.z;
      *(float *)&v84.m_object = sqrtf(
                                  (float)((float)(axis.y * axis.y) + (float)((float)-axis.z * (float)-axis.z))
                                + (float)(axis.x * axis.x));
      *(float *)&key = *(float *)&key * 0.5;
      v46 = sinf(*(float *)&key);
      *(float *)&v84.m_object = v46 / *(float *)&v84.m_object;
      *(float *)&key = cosf(*(float *)&key);
      *(float *)&v47 = -*(float *)&v85.m_object->m_children_resources.m_last;
      v100.m128i_i32[0] = *(_DWORD *)&v85.m_object->m_children_resources.gapC;
      v48 = *(float *)&v86.m_object * *(float *)&v84.m_object;
      v49 = axis.y * *(float *)&v84.m_object;
      v50 = *(float *)&v84.m_object * axis.x;
      v100.m128i_i32[1] = (int)v85.m_object->m_children_resources.m_first;
      v100.m128i_i64[1] = v47;
      v51 = key;
      v52 = 2.0
          / (float)((float)((float)((float)(v50 * v50) + (float)(v49 * v49)) + (float)(v48 * v48))
                  + (float)(*(float *)&key * *(float *)&key));
      v53 = v52 * (float)(*(float *)&v84.m_object * axis.x);
      v54 = v52 * (float)(axis.y * *(float *)&v84.m_object);
      *(float *)&key = v53 * *(float *)&key;
      v55 = v52 * (float)(*(float *)&v86.m_object * *(float *)&v84.m_object);
      v56 = v53 * (float)(*(float *)&v84.m_object * axis.x);
      *(float *)&v84.m_object = v54 * *(float *)&v51;
      v57 = v55 * *(float *)&v51;
      v58 = v54 * v50;
      *(float *)&v85.m_object = v57;
      v59 = v55 * v50;
      *(float *)&v93.m_object = v54 * v49;
      v60 = v55 * v49;
      v61 = v55 * v48;
      *(float *)&v62 = *(float *)&clear_value - (float)((float)(v54 * v49) + v56);
      v63 = v60 + *(float *)&key;
      *(float *)&indices_resource.m_object = v60 - *(float *)&key;
      *(float *)&v86.m_object = v56;
      *(float *)&key = *(float *)&clear_value - (float)(v61 + v56);
      vertices_resource.m_object = (vostok::resources::managed_resource *)LODWORD(v63);
      v64 = *(float *)&clear_value - (float)(v61 + *(float *)&v93.m_object);
      localTransform.m_basis.m_el[1].mVec128.m128_f32[0] = v58 + *(float *)&v85.m_object;
      localTransform.m_basis.m_el[1].mVec128.m128_f32[1] = *(float *)&key;
      localTransform.m_basis.m_el[2].mVec128.m128_f32[0] = v59 - *(float *)&v84.m_object;
      v65.mVec128 = (__m128)_mm_load_si128(&v100);
      localTransform.m_basis.m_el[0].mVec128.m128_f32[0] = v64;
      localTransform.m_basis.m_el[0].mVec128.m128_f32[1] = v58 - *(float *)&v85.m_object;
      localTransform.m_basis.m_el[0].mVec128.m128_u64[1] = COERCE_UNSIGNED_INT(v59 + *(float *)&v84.m_object);
      localTransform.m_basis.m_el[1].mVec128.m128_u64[1] = (unsigned int)indices_resource.m_object;
      localTransform.m_basis.m_el[2].mVec128.m128_f32[1] = v63;
      localTransform.m_basis.m_el[2].mVec128.m128_u64[1] = v62;
      localTransform.m_origin = (btVector3)v65.mVec128;
      btCompoundShape::addChildShape((btCompoundShape *)v90.m_object, &localTransform, (btCollisionShape *)v87.m_object);
      ptr.m_object[1].type = (unsigned int)v92;
    }
    else
    {
      v41 = v93.m_object->__vftable;
      *(float *)&indices_resource.m_object = 0.0;
      if ( *(float *)&v41 != 0.0 )
      {
        indices_resource.m_object = (vostok::resources::managed_resource *)v41;
        _InterlockedExchangeAdd((volatile signed __int32 *)&v41[7].is_increasing_quality, 1u);
      }
      v42 = *(vostok::resources::managed_resource **)key;
      vertices_resource.m_object = 0;
      if ( v42 )
      {
        vertices_resource.m_object = v42;
        _InterlockedExchangeAdd(&v42->m_reference_count, 1u);
      }
      v43 = vostok::physics::create_static_triangle_mesh_shape(
              &vertices_resource,
              &indices_resource,
              vertices,
              indices,
              (unsigned int)v15.m_object,
              (unsigned int)v14.m_object,
              v92,
              &cd->scale_);
      ptr.m_object = v43;
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&vertices_resource);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&indices_resource);
      v43->m_tri_face_data = v92;
    }
    if ( v98.m_resource.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v66 = v98.m_data;
        v67 = v98.m_data - 8;
        _InterlockedExchangeAdd((volatile signed __int32 *)v98.m_data - 2, 0xFFFFFFFF);
        v68 = v66 - 36;
        if ( *(_DWORD *)v68 )
        {
          if ( !*(_DWORD *)v67 )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v68 + 40), 1u);
            *(_DWORD *)v68 = 0;
          }
        }
      }
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v98.m_resource);
    if ( v99.m_resource.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v69 = v99.m_data;
        v70 = v99.m_data - 8;
        _InterlockedExchangeAdd((volatile signed __int32 *)v99.m_data - 2, 0xFFFFFFFF);
        v71 = v69 - 36;
        if ( *(_DWORD *)v71 )
        {
          if ( !*(_DWORD *)v70 )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v71 + 40), 1u);
            *(_DWORD *)v71 = 0;
          }
        }
      }
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v99.m_resource);
    if ( v101.m_resource.m_object )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v72 = v101.m_data;
        v73 = v101.m_data - 8;
        _InterlockedExchangeAdd((volatile signed __int32 *)v101.m_data - 2, 0xFFFFFFFF);
        v74 = v72 - 36;
        if ( *(_DWORD *)v74 )
        {
          if ( !*(_DWORD *)v73 )
          {
            _InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)v74 + 40), 1u);
            *(_DWORD *)v74 = 0;
          }
        }
      }
    }
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v101.m_resource);
  }
  if ( ptr.m_object )
  {
    _X.m_object = (vostok::resources::managed_resource *)280;
    v80 = ptr.m_object;
    _InterlockedExchangeAdd(&ptr.m_object->m_reference_count, 1u);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      cd->parent_query,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v80,
      &vostok::resources::nocache_memory,
      (unsigned int)_X.m_object);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v75,
      result_success,
      assert_on_fail_true,
      error_type_unset);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      0,
      result_error,
      assert_on_fail_true,
      error_type_cook_failed);
  }
  vostok::physics::g_ph_allocator->call_free(vostok::physics::g_ph_allocator, cd);
  v76 = v95.m_object;
  if ( v95.m_object )
  {
    v77 = &v95.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v95.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v77, v76);
  }
  v78 = v96.m_object;
  if ( v96.m_object )
  {
    v79 = &v96.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v96.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v79, v78);
  }
}
