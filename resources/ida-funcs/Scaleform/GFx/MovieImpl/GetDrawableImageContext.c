Scaleform::Render::DrawableImageContext *__thiscall Scaleform::GFx::MovieImpl::GetDrawableImageContext(
        Scaleform::GFx::MovieImpl *this)
{
  Scaleform::Render::DrawableImageContext *result; // eax
  Scaleform::Render::DrawableImageContext *v3; // eax
  Scaleform::Render::DrawableImageContext *v4; // eax
  Scaleform::Render::DrawableImageContext *v5; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // [esp-Ch] [ebp-24h]
  Scaleform::Render::Interfaces i; // [esp+8h] [ebp-10h] BYREF

  result = this->DIContext.pObject;
  if ( !result )
  {
    v3 = (Scaleform::Render::DrawableImageContext *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      96,
                                                      0);
    if ( v3 )
    {
      pRTCommandQueue = this->pRTCommandQueue;
      memset(&i, 0, sizeof(i));
      Scaleform::Render::DrawableImageContext::DrawableImageContext(v3, &this->RenderContext, pRTCommandQueue, &i);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->DIContext.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->DIContext.pObject = v5;
    return v5;
  }
  return result;
}
