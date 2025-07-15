void __thiscall survarium::game_material_manager_cook::on_fx_loaded(
        survarium::game_material_manager_cook *this,
        vostok::resources::queries_result *data,
        survarium::vector<survarium::game_material_manager_cook::query_ext_data> *ext_data)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **M_start; // esi
  vostok::resources::query_result *m_queries; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *p_ext_data; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *p_x; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *v8; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *v9; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *v10; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > *v11; // ecx
  survarium::game_material_manager_cook *v12; // [esp-4h] [ebp-3Ch]
  const char *v13; // [esp+0h] [ebp-38h]
  const char *v14; // [esp+4h] [ebp-34h]
  unsigned int v15; // [esp+8h] [ebp-30h]
  survarium::game_material_manager_cook::query_ext_data *M_finish; // [esp+Ch] [ebp-2Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v17; // [esp+10h] [ebp-28h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v18; // [esp+14h] [ebp-24h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v19; // [esp+18h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> __x; // [esp+1Ch] [ebp-1Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v21; // [esp+20h] [ebp-18h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v22; // [esp+24h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v23; // [esp+28h] [ebp-10h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+2Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v25; // [esp+30h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v26; // [esp+34h] [ebp-4h] BYREF

  M_start = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)ext_data->_M_impl._M_start;
  M_finish = ext_data->_M_impl._M_finish;
  if ( ext_data->_M_impl._M_start != M_finish )
  {
    m_queries = data->m_queries;
    do
    {
      v5 = M_start[1];
      if ( v5 )
      {
        if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)1 )
        {
          vostok::resources::query_result_for_user::get_unmanaged_resource(m_queries, &v26);
          vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
            &v26,
            *M_start + 3);
          p_ext_data = &v26;
        }
        else if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)2 )
        {
          vostok::resources::query_result_for_user::get_unmanaged_resource(m_queries, &v25);
          vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
            &v25,
            *M_start + 4);
          p_ext_data = &v25;
        }
        else
        {
          if ( v5 != (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)3 )
          {
            if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)4 )
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(m_queries, &v23);
              vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
                &v23,
                *M_start + 6);
              p_x = &v23;
            }
            else if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)5 )
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(m_queries, &v22);
              vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
                &v22,
                *M_start + 7);
              p_x = &v22;
            }
            else if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)6 )
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(m_queries, &v21);
              vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
                &v21,
                *M_start + 8);
              p_x = &v21;
            }
            else if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)7 )
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(
                m_queries,
                (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&__x);
              stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *>>::push_back(
                (const stlp_std::__false_type *)&__x,
                v8,
                (stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *> > *)&(*M_start)[9]);
              p_x = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&__x;
            }
            else if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)8 )
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(
                m_queries,
                (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v19);
              stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *>>::push_back(
                (const stlp_std::__false_type *)&v19,
                v9,
                (stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *> > *)&(*M_start)[13]);
              p_x = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v19;
            }
            else if ( v5 == (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)9 )
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(
                m_queries,
                (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v18);
              stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *>>::push_back(
                (const stlp_std::__false_type *)&v18,
                v10,
                (stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *> > *)&(*M_start)[17]);
              p_x = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v18;
            }
            else
            {
              vostok::resources::query_result_for_user::get_unmanaged_resource(
                m_queries,
                (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v17);
              stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *>>::push_back(
                (const stlp_std::__false_type *)&v17,
                v11,
                (stlp_std::vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<void *> > *)&(*M_start)[21]);
              p_x = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v17;
            }
            vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_x);
            goto LABEL_26;
          }
          vostok::resources::query_result_for_user::get_unmanaged_resource(
            m_queries,
            (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v24);
          vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
            (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v24,
            *M_start + 5);
          p_ext_data = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v24;
        }
      }
      else
      {
        vostok::resources::query_result_for_user::get_unmanaged_resource(
          m_queries,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&ext_data);
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&ext_data,
          *M_start + 2);
        p_ext_data = (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&ext_data;
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_ext_data);
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data>(
        survarium::g_allocator,
        (vostok::render::material_effects_instance_cook_data **)M_start + 2,
        v13,
        v14,
        v15);
      this = v12;
LABEL_26:
      M_start += 3;
      ++m_queries;
    }
    while ( M_start != (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> **)M_finish );
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    (vostok::resources::query_result_for_cook *)this,
    (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)data->m_parent_query,
    result_out_of_memory,
    assert_on_fail_true,
    result_fail);
}
