void __thiscall Scaleform::Render::DrawableImageContext::OnNextCapture(
        Scaleform::Render::DrawableImageContext *this,
        Scaleform::Render::ContextImpl::RenderNotify *notify)
{
  Scaleform::Render::DICommandQueue *Capacity; // ecx
  unsigned int *p_Size; // edi
  int v5; // eax
  Scaleform::Render::DICommandQueue *pNext; // esi

  ((void (__thiscall *)(Scaleform::Render::Renderer2D **, Scaleform::Render::ContextImpl::RenderNotify *))this[-1].IDefaults.pRenderer2D->RefCount)(
    &this[-1].IDefaults.pRenderer2D,
    notify);
  Capacity = (Scaleform::Render::DICommandQueue *)this->TreeRootKillList.Data.Policy.Capacity;
  p_Size = &this->TreeRootKillList.Data.Size;
  while ( 1 )
  {
    v5 = p_Size ? (int)(p_Size - 2) : 0;
    if ( Capacity == (Scaleform::Render::DICommandQueue *)v5 )
      break;
    pNext = Capacity->pNext;
    Scaleform::Render::DICommandQueue::OnNextCapture(Capacity, notify);
    Capacity = pNext;
  }
}
