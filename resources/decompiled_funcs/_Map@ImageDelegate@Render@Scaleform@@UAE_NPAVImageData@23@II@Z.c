int __thiscall Scaleform::Render::ImageDelegate::Map(
        Scaleform::Render::ImageDelegate *this,
        Scaleform::Render::ImageData *pdata,
        unsigned int levelIndex,
        unsigned int levelCount)
{
  return ((int (__thiscall *)(Scaleform::Render::Image *, Scaleform::Render::ImageData *, unsigned int, unsigned int))this->pImage.pObject->Map)(
           this->pImage.pObject,
           pdata,
           levelIndex,
           levelCount);
}
