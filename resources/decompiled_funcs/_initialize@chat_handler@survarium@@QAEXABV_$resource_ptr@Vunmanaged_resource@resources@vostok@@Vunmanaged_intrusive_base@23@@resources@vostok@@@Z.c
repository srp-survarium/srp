void __usercall survarium::chat_handler::initialize(
        survarium::chat_handler *this@<esi>,
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *ui@<eax>)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::unmanaged_resource *v3; // edi
  survarium::flash_movie_resource *v4; // eax
  survarium::flash_movie_resource *v5; // ecx
  survarium::flash_movie_resource *v6; // eax
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::GFx::Movie *v8; // ecx
  Scaleform::GFx::Movie *v9; // ecx
  survarium::flash_movie_resource *v10; // ecx
  survarium::flash_function_handler_impl *impl; // eax
  survarium::flash_movie_resource *v12; // edx
  survarium::flash_value func; // [esp+2Ch] [ebp-34h] BYREF
  survarium::flash_value proxy; // [esp+44h] [ebp-1Ch] BYREF

  m_object = ui->m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  v4 = 0;
  if ( v3 )
  {
    v4 = (survarium::flash_movie_resource *)v3;
    _InterlockedExchangeAdd(&v3->m_reference_count, 1u);
  }
  v5 = v4;
  v6 = this->m_chat_ui.m_object;
  this->m_chat_ui.m_object = v5;
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
  if ( v3 && !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  ((void (__stdcall *)(_DWORD))this->m_chat_ui.m_object->movie->m_movie->SetBackgroundAlpha)(0.0);
  m_movie = this->m_chat_ui.m_object->movie->m_movie;
  m_movie->SetViewAlignment(m_movie, Align_TopLeft);
  v8 = this->m_chat_ui.m_object->movie->m_movie;
  v8->SetViewScaleMode(v8, SM_NoScale);
  this->m_chat_ui.m_object->movie->m_priority = 30;
  v9 = this->m_chat_ui.m_object->movie->m_movie;
  v9->SetState(&v9->Scaleform::GFx::StateBag, State_ExternalInterface, this->survarium::flash_external_handler::impl);
  v10 = this->m_chat_ui.m_object;
  *(_DWORD *)proxy.body = 0;
  *(_DWORD *)&proxy.body[4] = 0;
  Scaleform::GFx::Movie::GetVariable(v10->movie->m_movie, (Scaleform::GFx::Value *)&proxy, "root.chat");
  impl = this->survarium::flash_function_handler::impl;
  v12 = this->m_chat_ui.m_object;
  *(_DWORD *)func.body = 0;
  *(_DWORD *)&func.body[4] = 0;
  Scaleform::GFx::Movie::CreateFunction(v12->movie->m_movie, (Scaleform::GFx::Value *)&func, impl, 0);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)proxy.body + 20))(
    *(_DWORD *)proxy.body,
    *(_DWORD *)&proxy.body[8],
    "send_function",
    &func,
    (proxy.body[4] & 0x8F) == 10);
  if ( (func.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)func.body + 8))(
      *(_DWORD *)func.body,
      &func,
      *(_DWORD *)&func.body[8]);
    *(_DWORD *)func.body = 0;
  }
  *(_DWORD *)&func.body[4] = 0;
  if ( (proxy.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)proxy.body + 8))(
      *(_DWORD *)proxy.body,
      &proxy,
      *(_DWORD *)&proxy.body[8]);
}
