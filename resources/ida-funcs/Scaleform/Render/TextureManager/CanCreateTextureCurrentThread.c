BOOL __thiscall Scaleform::Render::TextureManager::CanCreateTextureCurrentThread(
        Scaleform::Render::TextureManager *this)
{
  return !this->RenderThreadId || (void *)Scaleform::GetCurrentThreadId() == this->RenderThreadId;
}
