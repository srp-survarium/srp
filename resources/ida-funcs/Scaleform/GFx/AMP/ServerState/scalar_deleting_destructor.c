Scaleform::GFx::AMP::ServerState *__thiscall Scaleform::GFx::AMP::ServerState::`scalar deleting destructor'(
        Scaleform::GFx::AMP::ServerState *this,
        char a2)
{
  Scaleform::GFx::AMP::ServerState::~ServerState(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this);
  return this;
}
