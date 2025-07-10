void __thiscall Scaleform::Render::ThreadCommandQueue::GetRenderInterfaces(
        Scaleform::Render::ThreadCommandQueue *this,
        Scaleform::Render::Interfaces *p)
{
  p->pTextureManager = 0;
  p->pHAL = 0;
  p->pRenderer2D = 0;
  p->RenderThreadID = 0;
}
