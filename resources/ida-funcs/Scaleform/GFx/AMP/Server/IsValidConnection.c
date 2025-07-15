bool __thiscall Scaleform::GFx::AMP::Server::IsValidConnection(Scaleform::GFx::AMP::Server *this)
{
  return Scaleform::GFx::AMP::ThreadMgr::IsValidConnection((Scaleform::GFx::AMP::ThreadMgr *)this->Port);
}
