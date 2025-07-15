void __thiscall Scaleform::Render::DICommandContext::DICommandContext(
        Scaleform::Render::DICommandContext *this,
        Scaleform::Render::ThreadCommandQueue *rtQueue)
{
  Scaleform::Render::HAL *pHAL; // edx
  Scaleform::Render::Interfaces i; // [esp+4h] [ebp-10h] BYREF

  memset(&i, 0, sizeof(i));
  if ( rtQueue )
  {
    rtQueue->GetRenderInterfaces(rtQueue, &i);
    pHAL = i.pHAL;
    this->pR2D = i.pRenderer2D;
    this->pHAL = pHAL;
  }
}
