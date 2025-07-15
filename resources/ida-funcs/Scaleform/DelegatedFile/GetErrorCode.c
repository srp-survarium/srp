void __thiscall Scaleform::DelegatedFile::GetErrorCode(Scaleform::Render::TextureManager::ServiceCommand *this)
{
  this->pManager->ProcessQueues(this->pManager);
}
