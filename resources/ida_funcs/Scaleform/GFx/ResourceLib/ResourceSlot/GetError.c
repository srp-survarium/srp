const char *__thiscall Scaleform::GFx::ResourceLib::ResourceSlot::GetError(
        Scaleform::GFx::ResourceLib::ResourceSlot *this)
{
  return (const char *)((this->ErrorMessage.HeapTypeBits & 0xFFFFFFFC) + 8);
}
