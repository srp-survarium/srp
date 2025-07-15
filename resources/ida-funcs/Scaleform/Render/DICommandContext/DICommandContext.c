void __thiscall Scaleform::Render::DICommandContext::DICommandContext(
        Scaleform::Render::DICommandContext *this,
        Scaleform::Render::ThreadCommandQueue *rtQueue)
{
  Scaleform::Render::HAL *v3; // edx
  int v4; // [esp+4h] [ebp-10h] BYREF
  Scaleform::Render::HAL *v5; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Renderer2D *v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  if ( rtQueue )
  {
    rtQueue->GetRenderInterfaces(rtQueue, (Scaleform::Render::Interfaces *)&v4);
    v3 = v5;
    this->pR2D = v6;
    this->pHAL = v3;
  }
}
