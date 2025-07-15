Scaleform::GFx::AMP::Server *__thiscall Scaleform::GFx::AMP::Server::`vector deleting destructor'(
        Scaleform::GFx::AMP::Server *this,
        char a2)
{
  Scaleform::GFx::AMP::Server::~Server(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::GFx::AMP::Server *__thiscall Scaleform::GFx::AMP::Server::`vector deleting destructor'(char *this, char a2)
{
  return Scaleform::GFx::AMP::Server::`vector deleting destructor'((Scaleform::GFx::AMP::Server *)(this - 8), a2);
}
