void __thiscall vostok::render::render_model_cook::on_materials_loaded(
        vostok::render::render_model_cook *this,
        vostok::resources::queries_result *data,
        vostok::render::cook_intermediate_data *cook_data)
{
  vostok::render::cook_intermediate_data *v3; // esi
  bool v4; // zf
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // edi
  int v6; // [esp+Ch] [ebp-14h]
  unsigned int v7; // [esp+10h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v8; // [esp+14h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v9; // [esp+18h] [ebp-8h]
  vostok::render::cook_intermediate_data *cook_dataa; // [esp+1Ch] [ebp-4h]

  v3 = cook_data;
  v4 = !cook_data->status_failed;
  cook_dataa = (vostok::render::cook_intermediate_data *)this;
  if ( v4 )
  {
    v7 = 0;
    if ( data->m_size )
    {
      p_m_unmanaged_resource = &data->m_queries[0].m_unmanaged_resource;
      v6 = 0;
      v9 = &data->m_queries[0].m_unmanaged_resource;
      do
      {
        if ( vostok::resources::query_result_for_user::is_successful(
               (vostok::resources::query_result_for_user *)this,
               (int)&p_m_unmanaged_resource[-55]) )
        {
          vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
            &v8,
            (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)p_m_unmanaged_resource);
          vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
            &v8,
            &cook_data->assets[v6].material);
          vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v8);
          v3 = cook_data;
        }
        ++v7;
        ++v6;
        p_m_unmanaged_resource = v9 + 184;
        v9 += 184;
      }
      while ( v7 < data->m_size );
    }
    v4 = !v3->render_model_data_ready;
    v3->material_data_ready = 1;
    if ( !v4 )
      vostok::render::render_model_cook::query_materail_effects(this, cook_dataa, v3);
  }
  else
  {
    vostok::render::render_model_cook::query_materail_effects(
      this,
      (vostok::render::cook_intermediate_data *)this,
      cook_data);
  }
}
