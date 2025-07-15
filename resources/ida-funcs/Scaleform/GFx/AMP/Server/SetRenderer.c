void __thiscall Scaleform::GFx::AMP::Server::SetRenderer(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::Render::Renderer2D *renderer)
{
  this->Loaders.Data.Size = (unsigned int)renderer;
}
