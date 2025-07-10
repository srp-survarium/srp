void __thiscall survarium::scaleform_render_command_queue_impl::GetRenderInterfaces(
        survarium::scaleform_render_command_queue_impl *this,
        Scaleform::Render::Interfaces *p)
{
  p->pHAL = this->pHAL;
  p->pRenderer2D = this->pR2D;
  p->pTextureManager = this->pHALTextureMgr;
  p->RenderThreadID = this->pRenderThreadId;
}
