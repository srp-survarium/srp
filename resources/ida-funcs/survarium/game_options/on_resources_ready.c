void __thiscall survarium::game_options::on_resources_ready(
        survarium::game_options *this,
        vostok::resources::queries_result *data)
{
  vostok::configs::binary_config *v3; // ebx
  vostok::configs::binary_config *m_object; // edx
  vostok::configs::binary_config *v5; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_options_ui; // edi
  survarium::flash_movie_resource *v7; // ecx
  vostok::resources::unmanaged_resource *v8; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v10; // ecx
  vostok::configs::binary_config *v11; // ebx
  vostok::configs::binary_config *v12; // eax
  survarium::flash_movie_resource *v13; // edx
  vostok::resources::unmanaged_resource *v14; // ecx
  vostok::resources::unmanaged_intrusive_base *v15; // ecx
  Scaleform::GFx::Movie *v16; // ecx
  Scaleform::GFx::Movie *v17; // ecx
  Scaleform::GFx::Movie *v18; // ecx
  survarium::game_options *v19; // ecx
  survarium::game_options *v20; // ecx
  survarium::options_tab *v21; // ecx
  int *m_options; // ebx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v23; // [esp+1Ch] [ebp-Ch] BYREF
  vostok::resources::unmanaged_resource *resource; // [esp+20h] [ebp-8h]
  vostok::resources::unmanaged_intrusive_base *v25; // [esp+24h] [ebp-4h]

  v3 = 0;
  v23.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v23,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[0].m_unmanaged_resource);
  m_object = v23.m_object;
  if ( v23.m_object )
  {
    v3 = v23.m_object;
    _InterlockedExchangeAdd(&v23.m_object->m_reference_count, 1u);
  }
  v5 = 0;
  p_m_options_ui = &this->m_options_ui;
  if ( v3 )
  {
    v5 = v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
    m_object = v23.m_object;
  }
  v7 = (survarium::flash_movie_resource *)v5;
  v8 = p_m_options_ui->m_object;
  p_m_options_ui->m_object = v7;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd(&v8->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v8->vostok::resources::unmanaged_intrusive_base, v8);
    m_object = v23.m_object;
  }
  if ( v3 )
  {
    resource = (vostok::resources::unmanaged_resource *)&v3->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
      m_object = v23.m_object;
    }
  }
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &m_object->vostok::resources::unmanaged_intrusive_base,
      m_object);
  ((void (__stdcall *)(_DWORD))p_m_options_ui->m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  m_movie = p_m_options_ui->m_object->movie->m_movie;
  m_movie->SetViewAlignment(m_movie, Align_TopLeft);
  v10 = p_m_options_ui->m_object->movie->m_movie;
  v11 = 0;
  v10->SetViewScaleMode(v10, SM_NoScale);
  v23.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &v23,
    (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data->m_queries[1].m_unmanaged_resource);
  v12 = v23.m_object;
  if ( v23.m_object )
  {
    v11 = v23.m_object;
    _InterlockedExchangeAdd(&v23.m_object->m_reference_count, 1u);
  }
  v13 = 0;
  if ( v11 )
  {
    resource = v11;
    _InterlockedExchangeAdd(&v11->m_reference_count, 1u);
    v13 = (survarium::flash_movie_resource *)v11;
  }
  resource = this->m_cursor_ui.m_object;
  v14 = resource;
  this->m_cursor_ui.m_object = v13;
  if ( v14 )
  {
    v15 = &v14->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v15->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(v15, resource);
      v12 = v23.m_object;
    }
  }
  if ( v11 )
  {
    v25 = &v11->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&v11->m_reference_count, 0xFFFFFFFF) )
    {
      vostok::resources::unmanaged_intrusive_base::destroy(&v11->vostok::resources::unmanaged_intrusive_base, v11);
      v12 = v23.m_object;
    }
  }
  if ( v12 && !_InterlockedExchangeAdd(&v12->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v12->vostok::resources::unmanaged_intrusive_base, v12);
  ((void (__stdcall *)(_DWORD))this->m_cursor_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  v16 = this->m_cursor_ui.m_object->movie->m_movie;
  v16->SetViewAlignment(v16, Align_TopLeft);
  v17 = this->m_cursor_ui.m_object->movie->m_movie;
  v17->SetViewScaleMode(v17, SM_NoScale);
  v18 = p_m_options_ui->m_object->movie->m_movie;
  v18->SetState(&v18->Scaleform::GFx::StateBag, State_ExternalInterface, this->impl);
  survarium::game_options::fill_labels(v19, this);
  survarium::game_options::fill_settings_data(v20, this);
  m_options = (int *)this->m_options;
  resource = (vostok::resources::unmanaged_resource *)4;
  do
  {
    survarium::options_tab::initialize_data(v21, *m_options++, &this->m_options_ui);
    resource = (vostok::resources::unmanaged_resource *)((char *)resource - 1);
  }
  while ( resource );
  survarium::game_options::initialize_bindings((survarium::game_options *)v21, this);
}
