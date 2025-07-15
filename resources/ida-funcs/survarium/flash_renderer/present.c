void __userpurge survarium::flash_renderer::present(
        survarium::flash_renderer *this@<ecx>,
        int a2@<edi>,
        survarium::flash_movie **movies,
        Scaleform::GFx::Resource *movies_count,
        survarium::flash_text_manager *text_manager)
{
  Scaleform::AmpServer *Instance; // eax
  unsigned int v6; // esi
  survarium::flash_movie *v7; // ebx
  Scaleform::Render::ContextImpl::RTHandle *v8; // ebx
  Scaleform::Render::ContextImpl::RenderNotify *ContextNotify; // eax
  Scaleform::Render::TreeRoot *RenderEntry; // eax
  survarium::flash_text_manager *v11; // esi
  Scaleform::GFx::Resource **DisplayHandle; // esi
  Scaleform::Render::Renderer2D *v13; // ecx
  Scaleform::Render::ContextImpl::RenderNotify *v14; // eax
  Scaleform::Render::Renderer2D *v15; // esi
  Scaleform::Render::TreeRoot *v16; // eax
  Scaleform::Render::Renderer2D *v17; // [esp+4h] [ebp-4h]

  Instance = Scaleform::AmpServer::GetInstance();
  Instance->AdvanceFrame(Instance);
  v6 = 0;
  if ( movies_count )
  {
    do
    {
      v7 = movies[v6];
      if ( v7->m_output_width != *(_DWORD *)a2 || v7->m_output_height != *(_DWORD *)(a2 + 4) )
        survarium::flash_movie::SetViewport(v7, *(_DWORD *)a2, *(_DWORD *)(a2 + 4));
      v8 = &v7->m_handle->Scaleform::Render::ContextImpl::RTHandle;
      Scaleform::Render::Renderer2D::BeginFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
      ContextNotify = (Scaleform::Render::ContextImpl::RenderNotify *)Scaleform::Render::Renderer2D::GetContextNotify(*(Scaleform::GFx::AS3::SoundObject **)(a2 + 12));
      if ( Scaleform::Render::ContextImpl::RTHandle::NextCapture(v8, ContextNotify) )
      {
        v17 = *(Scaleform::Render::Renderer2D **)(a2 + 12);
        RenderEntry = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(v8);
        Scaleform::Render::Renderer2D::Display(v17, RenderEntry);
      }
      Scaleform::Render::Renderer2D::EndFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
      ++v6;
    }
    while ( v6 < (unsigned int)movies_count );
  }
  v11 = text_manager;
  if ( text_manager )
  {
    if ( text_manager->m_output_width != *(_DWORD *)a2 || text_manager->m_output_height != *(_DWORD *)(a2 + 4) )
      survarium::flash_text_manager::set_viewport(text_manager, *(_DWORD *)a2, *(_DWORD *)(a2 + 4));
    DisplayHandle = (Scaleform::GFx::Resource **)Scaleform::GFx::DrawTextManager::GetDisplayHandle(v11->text_manager_impl);
    if ( *DisplayHandle )
      Scaleform::RefCountImpl::AddRef(*DisplayHandle);
    v13 = *(Scaleform::Render::Renderer2D **)(a2 + 12);
    movies_count = *DisplayHandle;
    Scaleform::Render::Renderer2D::BeginFrame(v13);
    v14 = (Scaleform::Render::ContextImpl::RenderNotify *)Scaleform::Render::Renderer2D::GetContextNotify(*(Scaleform::GFx::AS3::SoundObject **)(a2 + 12));
    if ( Scaleform::Render::ContextImpl::RTHandle::NextCapture(
           (Scaleform::Render::ContextImpl::RTHandle *)&movies_count,
           v14) )
    {
      v15 = *(Scaleform::Render::Renderer2D **)(a2 + 12);
      v16 = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry((Scaleform::Render::ContextImpl::RTHandle *)&movies_count);
      Scaleform::Render::Renderer2D::Display(v15, v16);
    }
    Scaleform::Render::Renderer2D::EndFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle((Scaleform::Render::ContextImpl::RTHandle *)&movies_count);
  }
}
