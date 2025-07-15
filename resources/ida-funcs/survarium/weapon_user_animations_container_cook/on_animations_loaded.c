void __thiscall survarium::weapon_user_animations_container_cook::on_animations_loaded(
        survarium::weapon_user_animations_container_cook *this,
        vostok::resources::queries_result *data,
        unsigned int first_view_death_animations_count,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *third_view_death_animations_count)
{
  vostok::resources::query_result_for_cook *m_result; // ecx
  char *v6; // eax
  vostok::resources::unmanaged_resource *v7; // ecx
  char *v8; // edi
  survarium::weapon_user_animations_container::animations_collection *v9; // esi
  char *v10; // esi
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // ecx
  _DWORD *v14; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v15; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v16; // eax
  vostok::resources::managed_resource *m_object; // edi
  vostok::resources::managed_resource *v18; // eax
  vostok::resources::managed_resource *v19; // edi
  vostok::resources::managed_resource *v20; // eax
  vostok::resources::managed_resource *v21; // edi
  vostok::resources::managed_resource *v22; // eax
  vostok::resources::managed_resource *v23; // edi
  vostok::resources::managed_resource *v24; // eax
  vostok::resources::managed_resource *v25; // edi
  vostok::resources::managed_resource *v26; // eax
  vostok::resources::managed_resource *v27; // edi
  vostok::resources::managed_resource *v28; // eax
  vostok::resources::managed_resource *v29; // edi
  vostok::resources::managed_resource *v30; // eax
  vostok::resources::managed_resource *v31; // edi
  vostok::resources::managed_resource *v32; // eax
  vostok::resources::managed_resource *v33; // edi
  vostok::resources::managed_resource *v34; // eax
  vostok::resources::managed_resource *v35; // edi
  vostok::resources::managed_resource *v36; // eax
  vostok::resources::managed_resource *v37; // edi
  vostok::resources::managed_resource *v38; // eax
  vostok::resources::managed_resource *v39; // edi
  vostok::resources::managed_resource *v40; // eax
  vostok::resources::managed_resource *v41; // edi
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v42; // eax
  vostok::resources::managed_resource *v43; // edi
  survarium::pure_game_effect_emitter_base *v44; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_parent_query; // ebx
  survarium::pure_game_effect_emitter_base *v46; // ecx
  vostok::resources::query_result_for_cook *v47; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v48[4]; // [esp-4h] [ebp-90h] BYREF
  vostok::resources::memory_usage_type v49; // [esp+Ch] [ebp-80h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v50; // [esp+14h] [ebp-78h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v51; // [esp+18h] [ebp-74h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v52; // [esp+1Ch] [ebp-70h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v53; // [esp+20h] [ebp-6Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v54; // [esp+24h] [ebp-68h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v55; // [esp+28h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v56; // [esp+2Ch] [ebp-60h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v57; // [esp+30h] [ebp-5Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v58; // [esp+34h] [ebp-58h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v59; // [esp+38h] [ebp-54h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v60; // [esp+3Ch] [ebp-50h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v61; // [esp+40h] [ebp-4Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v62; // [esp+44h] [ebp-48h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v63; // [esp+48h] [ebp-44h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v64; // [esp+4Ch] [ebp-40h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v65; // [esp+50h] [ebp-3Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v66; // [esp+54h] [ebp-38h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v67; // [esp+58h] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v68; // [esp+5Ch] [ebp-30h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v69; // [esp+60h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v70; // [esp+64h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v71; // [esp+68h] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v72; // [esp+6Ch] [ebp-20h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v73; // [esp+70h] [ebp-1Ch] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v74; // [esp+74h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v75; // [esp+78h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v76; // [esp+7Ch] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v77; // [esp+80h] [ebp-Ch] BYREF
  unsigned int v78[2]; // [esp+84h] [ebp-8h] BYREF
  int i; // [esp+98h] [ebp+Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v80; // [esp+98h] [ebp+Ch]
  int v81; // [esp+98h] [ebp+Ch]
  int v82; // [esp+98h] [ebp+Ch]
  int v83; // [esp+98h] [ebp+Ch]
  int v84; // [esp+98h] [ebp+Ch]
  int v85; // [esp+98h] [ebp+Ch]
  int v86; // [esp+98h] [ebp+Ch]
  int v87; // [esp+98h] [ebp+Ch]
  int v88; // [esp+98h] [ebp+Ch]
  int v89; // [esp+98h] [ebp+Ch]
  int v90; // [esp+98h] [ebp+Ch]
  int v91; // [esp+98h] [ebp+Ch]
  int v92; // [esp+98h] [ebp+Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v93; // [esp+98h] [ebp+Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v94; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v95; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v96; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v97; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v98; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v99; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v100; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v101; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v102; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v103; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v104; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v105; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v106; // [esp+9Ch] [ebp+10h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v107; // [esp+9Ch] [ebp+10h]

  m_result = (vostok::resources::query_result_for_cook *)data->m_result;
  if ( m_result == (vostok::resources::query_result_for_cook *)1 )
  {
    v6 = vostok::memory::doug_lea_allocator::malloc_impl(
           (vostok::memory::doug_lea_allocator *)1,
           (int)survarium::g_allocator,
           4 * ((_DWORD)third_view_death_animations_count + first_view_death_animations_count) + 2120,
           "weapon_user_animations_container",
           (const char *const)v48[1].m_object,
           (const char *const)v48[2].m_object,
           (const unsigned int)v48[3].m_object);
    v8 = v6;
    if ( v6 )
    {
      vostok::resources::unmanaged_resource::unmanaged_resource(v7, v6, fs_iterator_class);
      *(_DWORD *)v8 = &survarium::weapon_user_animations_container::`vftable';
      v9 = (survarium::weapon_user_animations_container::animations_collection *)(v8 + 264);
      for ( i = 1; i >= 0; --i )
        survarium::weapon_user_animations_container::animations_collection::animations_collection(v9++);
      v10 = v8;
    }
    else
    {
      v10 = 0;
    }
    v11 = 0;
    *((_DWORD *)v10 + 296) = v8 + 2120;
    for ( *((_DWORD *)v10 + 297) = first_view_death_animations_count; v11 < first_view_death_animations_count; ++v11 )
    {
      v12 = (_DWORD *)(*((_DWORD *)v10 + 296) + 4 * v11);
      if ( v12 )
        *v12 = 0;
    }
    v13 = 0;
    *((_DWORD *)v10 + 528) = *((_DWORD *)v10 + 296) + 4 * first_view_death_animations_count;
    *((_DWORD *)v10 + 529) = third_view_death_animations_count;
    if ( third_view_death_animations_count )
    {
      do
      {
        v14 = (_DWORD *)(*((_DWORD *)v10 + 528) + 4 * v13);
        if ( v14 )
          *v14 = 0;
        ++v13;
      }
      while ( v13 < (unsigned int)third_view_death_animations_count );
    }
    v15 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)*((_DWORD *)v10 + 296);
    v78[0] = 0;
    survarium::get_animations_from_request_results(first_view_death_animations_count, v15, data, v78);
    survarium::get_animations_from_request_results(
      (unsigned int)third_view_death_animations_count,
      *((vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *const *)v10
      + 528),
      data,
      v78);
    v94 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(736 * v78[0]);
    v80 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 264);
    v78[0] += 27;
    v64.m_object = (vostok::resources::managed_resource *)27;
    do
    {
      v16 = v94;
      v94 += 184;
      m_object = vostok::resources::query_result_for_user::get_managed_resource(
                   (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v16),
                   &v63)->m_object;
      v77.m_object = 0;
      if ( m_object )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v77);
        v77.m_object = m_object;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v77,
        v80);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v77);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v63);
      ++v80;
      --v64.m_object;
    }
    while ( v64.m_object );
    v18 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v95 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1192);
    v78[0] += 27;
    v81 = 27;
    while ( 1 )
    {
      v63.m_object = (vostok::resources::managed_resource *)((char *)v18 + 736);
      v19 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v18),
              &v62)->m_object;
      v76.m_object = 0;
      if ( v19 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v76);
        v76.m_object = v19;
        _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v76,
        v95);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v76);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v62);
      ++v95;
      if ( !--v81 )
        break;
      v18 = v63.m_object;
    }
    v20 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v96 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 372);
    v78[0] += 27;
    v82 = 27;
    while ( 1 )
    {
      v62.m_object = (vostok::resources::managed_resource *)((char *)v20 + 736);
      v21 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v20),
              &v61)->m_object;
      v75.m_object = 0;
      if ( v21 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v75);
        v75.m_object = v21;
        _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v75,
        v96);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v75);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v61);
      ++v96;
      if ( !--v82 )
        break;
      v20 = v62.m_object;
    }
    v22 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v97 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1300);
    v78[0] += 27;
    v83 = 27;
    while ( 1 )
    {
      v61.m_object = (vostok::resources::managed_resource *)((char *)v22 + 736);
      v23 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v22),
              &v60)->m_object;
      v74.m_object = 0;
      if ( v23 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v74);
        v74.m_object = v23;
        _InterlockedExchangeAdd(&v23->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v74,
        v97);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v74);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v60);
      ++v97;
      if ( !--v83 )
        break;
      v22 = v61.m_object;
    }
    v24 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v98 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 480);
    v78[0] += 27;
    v84 = 27;
    while ( 1 )
    {
      v60.m_object = (vostok::resources::managed_resource *)((char *)v24 + 736);
      v25 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v24),
              &v59)->m_object;
      v73.m_object = 0;
      if ( v25 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v73);
        v73.m_object = v25;
        _InterlockedExchangeAdd(&v25->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v73,
        v98);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v73);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v59);
      ++v98;
      if ( !--v84 )
        break;
      v24 = v60.m_object;
    }
    v26 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v99 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1408);
    v78[0] += 27;
    v85 = 27;
    while ( 1 )
    {
      v59.m_object = (vostok::resources::managed_resource *)((char *)v26 + 736);
      v27 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v26),
              &v58)->m_object;
      v72.m_object = 0;
      if ( v27 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v72);
        v72.m_object = v27;
        _InterlockedExchangeAdd(&v27->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v72,
        v99);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v72);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v58);
      ++v99;
      if ( !--v85 )
        break;
      v26 = v59.m_object;
    }
    v28 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v100 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 588);
    v78[0] += 27;
    v86 = 27;
    while ( 1 )
    {
      v58.m_object = (vostok::resources::managed_resource *)((char *)v28 + 736);
      v29 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v28),
              &v57)->m_object;
      v71.m_object = 0;
      if ( v29 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v71);
        v71.m_object = v29;
        _InterlockedExchangeAdd(&v29->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v71,
        v100);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v71);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v57);
      ++v100;
      if ( !--v86 )
        break;
      v28 = v58.m_object;
    }
    v30 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v101 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1516);
    v78[0] += 27;
    v87 = 27;
    while ( 1 )
    {
      v57.m_object = (vostok::resources::managed_resource *)((char *)v30 + 736);
      v31 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v30),
              &v56)->m_object;
      v70.m_object = 0;
      if ( v31 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v70);
        v70.m_object = v31;
        _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v70,
        v101);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v70);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v56);
      ++v101;
      if ( !--v87 )
        break;
      v30 = v57.m_object;
    }
    v32 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v102 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 696);
    v78[0] += 6;
    v88 = 6;
    while ( 1 )
    {
      v56.m_object = (vostok::resources::managed_resource *)((char *)v32 + 736);
      v33 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v32),
              &v55)->m_object;
      v69.m_object = 0;
      if ( v33 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v69);
        v69.m_object = v33;
        _InterlockedExchangeAdd(&v33->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v69,
        v102);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v69);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v55);
      ++v102;
      if ( !--v88 )
        break;
      v32 = v56.m_object;
    }
    v34 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v103 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1624);
    v78[0] += 6;
    v89 = 6;
    while ( 1 )
    {
      v55.m_object = (vostok::resources::managed_resource *)((char *)v34 + 736);
      v35 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v34),
              &v54)->m_object;
      v68.m_object = 0;
      if ( v35 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v68);
        v68.m_object = v35;
        _InterlockedExchangeAdd(&v35->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v68,
        v103);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v68);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v54);
      ++v103;
      if ( !--v89 )
        break;
      v34 = v55.m_object;
    }
    v36 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v104 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 720);
    v78[0] += 108;
    v90 = 108;
    while ( 1 )
    {
      v54.m_object = (vostok::resources::managed_resource *)((char *)v36 + 736);
      v37 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v36),
              &v53)->m_object;
      v67.m_object = 0;
      if ( v37 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v67);
        v67.m_object = v37;
        _InterlockedExchangeAdd(&v37->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v67,
        v104);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v67);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v53);
      ++v104;
      if ( !--v90 )
        break;
      v36 = v54.m_object;
    }
    v38 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v105 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1648);
    v78[0] += 108;
    v91 = 108;
    while ( 1 )
    {
      v53.m_object = (vostok::resources::managed_resource *)((char *)v38 + 736);
      v39 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v38),
              &v52)->m_object;
      v66.m_object = 0;
      if ( v39 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v66);
        v66.m_object = v39;
        _InterlockedExchangeAdd(&v39->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v66,
        v105);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v66);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v52);
      ++v105;
      if ( !--v91 )
        break;
      v38 = v53.m_object;
    }
    v40 = (vostok::resources::managed_resource *)(736 * v78[0]);
    v106 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 1152);
    v78[0] += 8;
    v92 = 8;
    while ( 1 )
    {
      v52.m_object = (vostok::resources::managed_resource *)((char *)v40 + 736);
      v41 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v40),
              &v51)->m_object;
      v65.m_object = 0;
      if ( v41 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v65);
        v65.m_object = v41;
        _InterlockedExchangeAdd(&v41->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v65,
        v106);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v65);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v51);
      ++v106;
      if ( !--v92 )
        break;
      v40 = v52.m_object;
    }
    v107 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(736 * v78[0]);
    v93 = (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(v10 + 2080);
    v65.m_object = (vostok::resources::managed_resource *)8;
    do
    {
      v42 = v107;
      v107 += 184;
      v43 = vostok::resources::query_result_for_user::get_managed_resource(
              (vostok::resources::query_result_for_user *)((char *)data->m_queries + (_DWORD)v42),
              &v50)->m_object;
      v64.m_object = 0;
      if ( v43 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v64);
        v64.m_object = v43;
        _InterlockedExchangeAdd(&v43->m_reference_count, 1u);
      }
      vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v64,
        v93);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v64);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v50);
      ++v93;
      --v65.m_object;
    }
    while ( v65.m_object );
    m_parent_query = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)data->m_parent_query;
    v48[0].m_object = v44;
    v49.type = &vostok::resources::nocache_memory;
    v49.size = 2120;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      v48,
      (survarium::pure_game_effect_emitter_base *)v10);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(&v49, v46, m_parent_query, v48[0]);
    vostok::resources::query_result_for_cook::finish_query_impl(
      v47,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_out_of_memory,
      assert_on_fail_true,
      result_fail);
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query_impl(
      m_result,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
