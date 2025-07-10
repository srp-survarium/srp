void __userpurge survarium::flash_renderer::present(
        survarium::flash_renderer *this@<ecx>,
        int a2@<esi>,
        survarium::flash_movie **movies,
        Scaleform::GFx::Resource *movies_count,
        survarium::flash_text_manager *text_manager)
{
  const vostok::math::float4x4 *v5; // xmm0_4
  unsigned int v6; // ebp
  survarium::flash_movie *v7; // edi
  int v8; // eax
  int v9; // ecx
  Scaleform::GFx::Movie *m_movie; // ecx
  Scaleform::Render::ContextImpl::RTHandle *v11; // edi
  Scaleform::Render::ContextImpl::RenderNotify *ContextNotify; // eax
  Scaleform::Render::TreeRoot *RenderEntry; // eax
  survarium::flash_text_manager *v14; // edi
  int v15; // ecx
  unsigned int v16; // eax
  Scaleform::GFx::DrawTextManager *text_manager_impl; // ecx
  Scaleform::GFx::Resource **DisplayHandle; // edi
  Scaleform::Render::ContextImpl::RenderNotify *v19; // eax
  Scaleform::Render::Renderer2D *v20; // edi
  Scaleform::Render::TreeRoot *v21; // eax
  Scaleform::Render::Renderer2D *v22; // [esp+4h] [ebp-38h]
  Scaleform::Render::Viewport vp; // [esp+8h] [ebp-34h] BYREF
  const vostok::math::float4x4 *v24; // [esp+34h] [ebp-8h]
  const vostok::math::float4x4 *v25; // [esp+38h] [ebp-4h]

  v5 = clear_value;
  v6 = 0;
  if ( movies_count )
  {
    do
    {
      v7 = movies[v6];
      v8 = *(_DWORD *)a2;
      if ( v7->m_output_width != *(_DWORD *)a2 || v7->m_output_height != *(_DWORD *)(a2 + 4) )
      {
        v9 = *(_DWORD *)(a2 + 4);
        v7->m_output_height = v9;
        vp.BufferHeight = v9;
        vp.Height = v9;
        m_movie = v7->m_movie;
        v7->m_output_width = v8;
        vp.BufferWidth = v8;
        vp.Width = v8;
        vp.Left = 0;
        vp.Top = 0;
        memset(&vp.ScissorLeft, 0, 20);
        v25 = v5;
        v24 = v5;
        m_movie->SetViewport(m_movie, (const Scaleform::GFx::Viewport *)&vp);
      }
      v11 = &v7->m_handle->Scaleform::Render::ContextImpl::RTHandle;
      Scaleform::Render::Renderer2D::BeginFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
      ContextNotify = (Scaleform::Render::ContextImpl::RenderNotify *)Scaleform::Render::Renderer2D::GetContextNotify(*(Scaleform::GFx::AS3::SoundObject **)(a2 + 12));
      if ( Scaleform::Render::ContextImpl::RTHandle::NextCapture(v11, ContextNotify) )
      {
        v22 = *(Scaleform::Render::Renderer2D **)(a2 + 12);
        RenderEntry = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(v11);
        Scaleform::Render::Renderer2D::Display(v22, RenderEntry);
      }
      Scaleform::Render::Renderer2D::EndFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
      v5 = clear_value;
      ++v6;
    }
    while ( v6 < (unsigned int)movies_count );
  }
  v14 = text_manager;
  if ( text_manager )
  {
    v15 = *(_DWORD *)a2;
    if ( text_manager->m_output_width != *(_DWORD *)a2 || text_manager->m_output_height != *(_DWORD *)(a2 + 4) )
    {
      v16 = *(_DWORD *)(a2 + 4);
      text_manager->m_output_height = v16;
      vp.BufferHeight = v16;
      vp.Height = v16;
      v14->m_output_width = v15;
      vp.BufferWidth = v15;
      vp.Width = v15;
      text_manager_impl = v14->text_manager_impl;
      vp.Left = 0;
      vp.Top = 0;
      memset(&vp.ScissorLeft, 0, 20);
      v25 = v5;
      v24 = v5;
      Scaleform::GFx::DrawTextManager::SetViewport(text_manager_impl, &vp);
      v14->need_capture = 1;
    }
    DisplayHandle = (Scaleform::GFx::Resource **)Scaleform::GFx::DrawTextManager::GetDisplayHandle(v14->text_manager_impl);
    if ( *DisplayHandle )
      Scaleform::RefCountImpl::AddRef(*DisplayHandle);
    movies_count = *DisplayHandle;
    Scaleform::Render::Renderer2D::BeginFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
    v19 = (Scaleform::Render::ContextImpl::RenderNotify *)Scaleform::Render::Renderer2D::GetContextNotify(*(Scaleform::GFx::AS3::SoundObject **)(a2 + 12));
    if ( Scaleform::Render::ContextImpl::RTHandle::NextCapture(
           (Scaleform::Render::ContextImpl::RTHandle *)&movies_count,
           v19) )
    {
      v20 = *(Scaleform::Render::Renderer2D **)(a2 + 12);
      v21 = (Scaleform::Render::TreeRoot *)Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry((Scaleform::Render::ContextImpl::RTHandle *)&movies_count);
      Scaleform::Render::Renderer2D::Display(v20, v21);
    }
    Scaleform::Render::Renderer2D::EndFrame(*(Scaleform::Render::Renderer2D **)(a2 + 12));
    Scaleform::Render::ContextImpl::RTHandle::~RTHandle((Scaleform::Render::ContextImpl::RTHandle *)&movies_count);
  }
}
