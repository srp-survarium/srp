void __thiscall vostok::render::material_effects_instance_cook::translate_query(
        vostok::render::material_effects_instance_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::variant<32> *m_user_data; // esi
  char *m_requery_path; // eax
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::material_effects_instance_cook,vostok::resources::queries_result &,vostok::render::material_effects_instance_cook_data *>,boost::_bi::list3<boost::_bi::value<vostok::render::material_effects_instance_cook *>,boost::arg<1>,boost::_bi::value<vostok::render::material_effects_instance_cook_data *> > > v6; // [esp-Ch] [ebp-4Ch]
  int v7; // [esp+0h] [ebp-40h]
  vostok::render::material_effects_instance_cook_data *cook_data; // [esp+10h] [ebp-30h] BYREF
  vostok::resources::request requests; // [esp+14h] [ebp-2Ch] BYREF
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+20h] [ebp-20h] BYREF

  m_user_data = parent->m_user_data;
  cook_data = 0;
  vostok::variant<32>::try_get<vostok::render::material_effects_instance_cook_data *>(
    (vostok::variant<32> *)this,
    (int)m_user_data,
    &cook_data);
  if ( cook_data->material.m_object )
  {
    vostok::render::material_effects_instance_cook::query_effects(
      (vostok::render::material_effects_instance_cook *)cook_data,
      this,
      parent,
      cook_data);
  }
  else
  {
    requests.id = (vostok::resources::class_id_enum)this;
    requests.path = (const char *)vostok::render::material_effects_instance_cook::on_material_ready;
    *(vostok::resources::request *)&v6.f_.f_ = requests;
    v6.l_.a3_.t_ = cook_data;
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      (boost::function<void __cdecl(vostok::resources::queries_result &)> *)cook_data,
      (int)&callback,
      (unsigned int)m_user_data,
      v6,
      v7);
    m_requery_path = parent->m_requery_path;
    if ( !m_requery_path )
      m_requery_path = parent->m_request_path;
    requests.path = m_requery_path;
    requests.id = material_class;
    cook_data = 0;
    vostok::resources::query_resources(
      &requests,
      1u,
      &callback,
      (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
      (const vostok::variant<32> **)&cook_data,
      parent,
      assert_on_fail_true);
    if ( callback.vtable && ((int)callback.vtable & 1) == 0 )
    {
      v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)callback.vtable & 0xFFFFFFFE);
      if ( v5 )
        v5(&callback.functor, &callback.functor, 2);
    }
  }
}
