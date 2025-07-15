bool __thiscall Scaleform::GFx::AMP::Server::IsProfiling(Scaleform::GFx::AMP::Server *this)
{
  return *(_DWORD *)&this->InitSocketLib != 0;
}
