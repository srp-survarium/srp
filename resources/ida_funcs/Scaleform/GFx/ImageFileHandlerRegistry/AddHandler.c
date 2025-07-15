void __thiscall Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(
        Scaleform::GFx::ImageFileHandlerRegistry *this,
        Scaleform::Render::ImageFileHandler *handler)
{
  Scaleform::Render::ImageFileHandlerRegistry::AddHandler(&this->Scaleform::Render::ImageFileHandlerRegistry, handler);
}
