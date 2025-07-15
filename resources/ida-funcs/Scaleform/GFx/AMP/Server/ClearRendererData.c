void __thiscall Scaleform::GFx::AMP::Server::ClearRendererData(Scaleform::GFx::AMP::Server *this)
{
  Scaleform::Render::Renderer2D *CurrentRenderer; // ecx
  Scaleform::Render::HAL *HAL; // eax
  _DWORD v4[6]; // [esp+Ch] [ebp-18h] BYREF

  Scaleform::GFx::AMP::ViewStats::ClearAmpFunctionStats(this->RenderStats.pObject->DisplayTimings.pObject);
  CurrentRenderer = this->CurrentRenderer;
  memset(v4, 0, sizeof(v4));
  HAL = Scaleform::Render::Renderer2D::GetHAL(CurrentRenderer);
  HAL->GetStats(HAL, (Scaleform::Render::HAL::Stats *)v4, 1);
  InterlockedExchange((volatile LONG *)&this->FontThrashing, 0);
  InterlockedExchange((volatile LONG *)&this->FontFailures, 0);
}
