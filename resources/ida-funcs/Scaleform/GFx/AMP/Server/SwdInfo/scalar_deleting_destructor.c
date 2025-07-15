Scaleform::GFx::AMP::Server::SwdInfo *__thiscall Scaleform::GFx::AMP::Server::SwdInfo::`scalar deleting destructor'(
        Scaleform::GFx::AMP::Server::SwdInfo *this,
        char a2)
{
  Scaleform::GFx::AMP::Server::SwdInfo::~SwdInfo(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
