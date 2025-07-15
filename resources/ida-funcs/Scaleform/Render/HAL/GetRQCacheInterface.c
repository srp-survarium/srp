Scaleform::Render::RQCacheInterface *__thiscall Scaleform::Render::HAL::GetRQCacheInterface(
        Scaleform::Render::HAL *this)
{
  return &this->QueueProcessor.Caches;
}
