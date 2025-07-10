void __thiscall Scaleform::Render::TextureManager::UpdateImage(
        Scaleform::Render::TextureManager *this,
        Scaleform::Render::Image *pimage)
{
  Scaleform::Mutex *v3; // esi

  v3 = (Scaleform::Mutex *)&this->pRTCommandQueue[9];
  Scaleform::Mutex::DoLock(v3);
  Scaleform::Render::ImageUpdateQueue::Add((Scaleform::Render::ImageUpdateQueue *)&this->pTextureCache, pimage);
  Scaleform::Mutex::Unlock(v3);
}
